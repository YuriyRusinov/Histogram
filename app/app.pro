TEMPLATE = app

include (../qt_hist.conf)
TARGET = qt_histogram_app

DESTDIR = ../bin

include(app.pri)

target.path = $$HIST_EXEC_DIR
INSTALLS += target
