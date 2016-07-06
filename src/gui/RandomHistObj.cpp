#include <math.h>
#include <gsl/gsl_rng.h>

#include <QMap>
#include <QStringList>
#include <QtDebug>

#include "random.h"
#include "gaussian_random.h"
#include "uniform_random.h"
#include "exponential_random.h"
#include "randomparametersform.h"
#include "RandomHistObj.h"

_HIST_EXPORT_ RandomHistObject * RandomHistObject :: self = 0;

RandomHistObject :: RandomHistObject (QObject * parent)
    : QObject (parent),
    rGenerator (0)
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
    double mathExp = rpForm->getMathExp();
    double stand = sqrt (rpForm->getDisp());
    if (rpForm->exec() == QDialog::Accepted)
    {
         DistrFuncs funDisp = (DistrFuncs )rpForm->getFunDistr ();
         switch (funDisp)
         {
             case Uniform: rGenerator = new UniformRandomNumberGen (mathExp, stand, s); break;
             case Gaussian: default: rGenerator = new GaussianRandomNumberGen (mathExp, stand, s); break;
             case Exponential: rGenerator = new ExponentialRandomNumberGen (mathExp, s); break;
         }
         int numb = rpForm->getNumber();
         resNumb.clear ();
         resNumb.resize (numb);
         for (int i=0; i<numb; i++)
         {
             double x = rGenerator->gen ();
             resNumb[i] = x;
         }
         qDebug () << __PRETTY_FUNCTION__ << resNumb;
    }
}
