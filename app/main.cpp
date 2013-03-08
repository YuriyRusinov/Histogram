#include <QApplication>
#include "histmainwindow.h"

int main (int argc, char *argv[])
{
    QApplication app (argc, argv);
    HistMainWindow * w = new HistMainWindow ();
    w->show ();

    int r = app.exec();
    delete w;
    return r;
}
