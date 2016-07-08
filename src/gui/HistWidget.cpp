#include <QGridLayout>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_interval.h>
#include "HistWidget.h"

HistWidget :: HistWidget (double xmin, double xmax, double ymin, double ymax, QWidget * parent, Qt::WindowFlags flags)
    : QWidget (parent, flags),
    plot (new QwtPlot)
{
    QGridLayout * gLay = new QGridLayout (this);

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(plot);
    plot->setAxisScale(QwtPlot::xBottom, xmin, xmax);
    plot->setAxisScale(QwtPlot::yLeft, ymin, ymax);

    gLay->addWidget (plot, 0, 0, 1, 1);
}

HistWidget :: ~HistWidget (void)
{
    delete plot;
}
