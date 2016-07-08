#include <QMdiArea>
#include <QMdiSubWindow>
#include <QtDebug>

#include <RandomHistObj.h>
#include "histmainwindow.h"
#include "ui_hist_main_window.h"

HistMainWindow :: HistMainWindow (QWidget * parent, Qt::WindowFlags flags)
    : QMainWindow (parent, flags),
    UI (new Ui::hist_main_window),
    m_mdiArea (new QMdiArea)
{
    UI->setupUi (this);
    init ();

    randH = RandomHistObject :: getRandomHistObject();
    connect (randH, SIGNAL (viewResults (QWidget *)), this, SLOT (slotView (QWidget *)) );
    connect (UI->actRandomProcess, SIGNAL (triggered()), this, SLOT (slotSetRandomParams()) );
    connect (UI->actHistogram, SIGNAL (triggered()), this, SLOT (slotSetHistParams()) );
    connect (UI->act_Calculate, SIGNAL (triggered()), this, SLOT (slotCalc()) );
    connect (UI->act_Quit, SIGNAL (triggered()), this, SLOT (close()) );
}

HistMainWindow :: ~HistMainWindow (void)
{
    delete UI;
}

void HistMainWindow :: slotSetRandomParams (void)
{
    qDebug () << __PRETTY_FUNCTION__;
    randH->GUIRandomProc ();
}

void HistMainWindow :: slotCalc (void)
{
    qDebug () << __PRETTY_FUNCTION__;
    randH->calcHist ();
    randH->GUIViewHist ();
}

void HistMainWindow :: init (void)
{
    setCentralWidget (m_mdiArea);
}

void HistMainWindow :: slotSetHistParams (void)
{
    qDebug () << __PRETTY_FUNCTION__;
    randH->GUIHistogramParams ();
}

void HistMainWindow :: slotView (QWidget * w)
{
    QMdiSubWindow * subw = m_mdiArea->addSubWindow (w);
    subw->setAttribute (Qt::WA_DeleteOnClose);
    w->adjustSize ();
    w->show ();
}
