TEMPLATE = app

INCLUDEPATH *= ../src \
               ../src/gui \
               ../src/gui/ui

DEPENDPATH *= ../src \
              ../src/gui \
              ../src/gui/ui

include (../qt_hist.conf)
TARGET = qt_histogram_app

DESTDIR = ../bin
LIBS *= -L$$DESTDIR -lrand_test

include(app.pri)

target.path = $$HIST_EXEC_DIR
INSTALLS += target
