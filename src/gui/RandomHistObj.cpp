#include <math.h>
#include <gsl/gsl_rng.h>

#include <QMap>
#include <QStringList>
#include <QMessageBox>
#include <QtDebug>

#include "HistWidget.h"
#include "random.h"
#include "gaussian_random.h"
#include "uniform_random.h"
#include "exponential_random.h"
#include "randomparametersform.h"
#include "histogramparametersform.h"
#include "RandomHistObj.h"

_HIST_EXPORT_ RandomHistObject * RandomHistObject :: self = 0;

RandomHistObject :: RandomHistObject (QObject * parent)
    : QObject (parent),
    rGenerator (0),
    hist (0)
{
    if (self)
        qFatal("There should be only one RandomHist object");
    self = this;
}

RandomHistObject :: ~RandomHistObject (void)
{
    self = 0;
    if (rGenerator)
        delete rGenerator;
    if (hist)
        gsl_histogram_free (hist);
    rGenerator = 0;
    hist = 0;
}

RandomHistObject * RandomHistObject :: getRandomHistObject (QObject * parent)
{
    if (!self)
        self = new RandomHistObject (parent);

    return self;
}

void RandomHistObject :: GUIRandomProc (QWidget * parent, Qt::WindowFlags flags)
{
    RandomParametersForm * rpForm = new RandomParametersForm (parent, flags);
    QMap<int, QString> distrs;
    QStringList dLaws;
    dLaws << tr ("Uniform distribution")
          << tr ("Gaussian distribution")
          << tr ("Exponential distribution");
    for (int i=0; i<3; i++)
        distrs.insert ((DistrFuncs )i, dLaws[i]);
    rpForm->setDistributions (distrs);
    if (rGenerator)
    {
        delete rGenerator;
        rGenerator = 0;
    }
    gsl_rng_env_setup();
    unsigned long s = gsl_rng_default_seed;
    if (rpForm->exec() == QDialog::Accepted)
    {
         DistrFuncs funDisp = (DistrFuncs )rpForm->getFunDistr ();
         double mathExp = rpForm->getMathExp();
         double stand = sqrt (rpForm->getDisp());
         qDebug () << __PRETTY_FUNCTION__ << mathExp << stand;
         int numb = rpForm->getNumber();
         switch (funDisp)
         {
             case Uniform: rGenerator = new UniformRandomNumberGen (mathExp, stand, s); break;
             case Gaussian: default: rGenerator = new GaussianRandomNumberGen (mathExp, stand, s); break;
             case Exponential: rGenerator = new ExponentialRandomNumberGen (mathExp, s); break;
         }
         resNumb.clear ();
         resNumb.resize (numb);
         for (int i=0; i<numb; i++)
         {
             double x = rGenerator->gen ();
             resNumb[i] = x;
         }
    }
    rpForm->setParent (0);
    delete rpForm;
}

void RandomHistObject :: GUIHistogramParams (QWidget * parent, Qt::WindowFlags flags)
{
    
    HistogramParametersForm * hpForm = new HistogramParametersForm (parent, flags);
    double xmin;
    double xmax;
    int n;
    bool isLogScale;

    if (hpForm->exec() == QDialog::Accepted)
    {
        xmin = hpForm->getXMin ();
        xmax = hpForm->getXMax ();
        n = hpForm->getNumb ();
        isLogScale = hpForm->is_logscale ();
    }
    if (hist)
    {
        gsl_histogram_free (hist);
        hist = 0;
    }
    hist = gsl_histogram_alloc (n);
    if (isLogScale)
    {
        double *range = new double [n];
        double q = xmax/xmin/n;
        range [0] = xmin;
        for (int i=1; i<n; i++)
            range [i] = range[i-1]*q;
        gsl_histogram_set_ranges (hist, range, n);
        delete [] range;
    }
    else
        gsl_histogram_set_ranges_uniform (hist, xmin, xmax);
}

void RandomHistObject :: calcHist (void)
{
    qDebug () << __PRETTY_FUNCTION__;
    if (resNumb.isEmpty())
    {
        int res = QMessageBox::question (0, tr ("Histogram"), tr("Random numbers were not set. Do you want to setup ?"), QMessageBox::Yes | QMessageBox::No);
        if (res == QMessageBox::Yes)
            this->GUIRandomProc ();
        else
            return;
    }
    if (!hist)
    {
        int res = QMessageBox::question (0, tr ("Histogram"), tr("Histogram parameters were not set. Do you want to setup ?"), QMessageBox::Yes | QMessageBox::No);
        if (res == QMessageBox::Yes)
            this->GUIHistogramParams ();
        else
            return;
    }
    int nr = resNumb.size ();
    //size_t nH = gsl_histogram_bins (hist);
    gsl_histogram_reset (hist);
    for (int i=0; i<nr; i++)
        gsl_histogram_increment (hist, resNumb[i]);
    gsl_histogram_fprintf (stdout, hist, "%g", "%g");
}

void RandomHistObject :: GUIViewHist (QWidget * parent, Qt::WindowFlags flags)
{
    if (!hist)
        return;
    double xmin = gsl_histogram_min (hist);
    double xmax = gsl_histogram_max (hist);
    double ymin = 0.0;
    double ymax = gsl_histogram_max_val (hist);
    HistWidget * hw = new HistWidget (xmin, xmax, ymin, ymax, parent, flags);
    hw->setHistogram (hist);
    emit viewResults (hw);
}
