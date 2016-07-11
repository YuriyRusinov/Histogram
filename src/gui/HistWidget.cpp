#include <QGridLayout>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_interval.h>
#if QWT_VERSION >= 0x060100
#include <qwt_samples.h>
#endif
#include <qwt_plot_histogram.h>
#include "HistWidget.h"

HistWidget :: HistWidget (double xmin, double xmax, double ymin, double ymax, QWidget * parent, Qt::WindowFlags flags)
    : QWidget (parent, flags),
    plot (new QwtPlot),
    w_hist (0)
{
    QGridLayout * gLay = new QGridLayout (this);

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->enableYMin(true);
#if QWT_VERSION >= 0x060100
    grid->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0 , Qt::DotLine));
#else
    grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
#endif
    grid->attach(plot);
    plot->setAxisScale(QwtPlot::xBottom, xmin, xmax);
    plot->setAxisScale(QwtPlot::yLeft, ymin, ymax);

    gLay->addWidget (plot, 0, 0, 1, 1);
}

HistWidget :: ~HistWidget (void)
{
    delete plot;
    if (w_hist)
        gsl_histogram_free (w_hist);
}

void HistWidget :: setHistogram (const gsl_histogram * hist)
{
    if (hist == w_hist)
        return;

    if (w_hist)
        gsl_histogram_free (w_hist);

    w_hist = gsl_histogram_clone (hist);
    size_t nH = w_hist->n;
    double *r = w_hist->range;
    qDebug () << __PRETTY_FUNCTION__ << nH;
    QwtPlotHistogram * pH = new QwtPlotHistogram();
    QVector<QwtIntervalSample> samples;
    for (size_t i=0; i<nH; i++)
    {
    //    qDebug () << __PRETTY_FUNCTION__ << r[i];
        double bin = gsl_histogram_get (hist, i);
        QwtIntervalSample s (bin, r[i], r[i+1]);
        samples.append (s);
    }
    pH->setSamples (samples);
    pH->attach (plot);
    plot->replot ();
}
