#ifndef _HistWidget_H
#define _HistWidget_H

#include <QWidget>

#include "src_config.h" 

class _HIST_EXPORT_ HistWidget : public QWidget
{
public:
    HistWidget (QWidget * parent=0, Qt::WindowFlags flags=0);
    virtual ~HistWidget (void);

private:
    Q_OBJECT

};

#endif
