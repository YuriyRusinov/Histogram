#ifndef _HISTMAINWINDOW_H
#define _HISTMAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class hist_main_window;
};

class RandomHistObject;
class QMdiArea;

class HistMainWindow : public QMainWindow
{
public:
    HistMainWindow (QWidget * parent=0, Qt::WindowFlags flags=0);
    ~HistMainWindow (void);

private slots:
    void slotSetParams (void);
    void slotCalc (void);

private:
    //
    // Functions
    //
    void init (void);
private:
    //
    // Variables
    //
    Ui::hist_main_window * UI;
    QMdiArea * m_mdiArea;
    RandomHistObject * randH;

private:
    Q_OBJECT
};

#endif
