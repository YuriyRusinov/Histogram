#include <QMdiArea>
#include <QtDebug>

#include "histmainwindow.h"
#include "ui_hist_main_window.h"

HistMainWindow :: HistMainWindow (QWidget * parent, Qt::WindowFlags flags)
    : QMainWindow (parent, flags),
    UI (new Ui::hist_main_window),
    m_mdiArea (new QMdiArea)
{
    UI->setupUi (this);
    init ();

    connect (UI->actSet_histogram_parameters, SIGNAL (triggered()), this, SLOT (slotSetParams()) );
    connect (UI->act_Calculate, SIGNAL (triggered()), this, SLOT (slotCalc()) );
    connect (UI->act_Quit, SIGNAL (triggered()), this, SLOT (close()) );
}

HistMainWindow :: ~HistMainWindow (void)
{
    delete UI;
}

void HistMainWindow :: slotSetParams (void)
{
    qDebug () << __PRETTY_FUNCTION__;
}

void HistMainWindow :: slotCalc (void)
{
    qDebug () << __PRETTY_FUNCTION__;
}

void HistMainWindow :: init (void)
{
    setCentralWidget (m_mdiArea);
}
