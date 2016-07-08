#ifndef _HistWidget_H
#define _HistWidget_H

#include <QWidget>

#include "src_config.h" 

class QwtPlot;

class _HIST_EXPORT_ HistWidget : public QWidget
{
public:
    HistWidget (double xmin, double xmax, double ymin, double ymax, QWidget * parent=0, Qt::WindowFlags flags=0);
    virtual ~HistWidget (void);

private:
    QwtPlot *plot;
private:
    Q_OBJECT

};

#endif
