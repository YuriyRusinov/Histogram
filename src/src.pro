TEMPLATE = lib
TARGET = rand_test

CONFIG += qt

DESTDIR = ../bin

include (../qt_hist.conf)

INCLUDEPATH *= $$GSL_INC_DIR
DEPENDPATH *= $$GSL_INC_DIR

DEFINES += _HIST_DLL_
DEFINES += _FILE_OFFSET_BITS=64

include (gui/gui.pri)

HEADERS += random.h

SOURCES += \
           random.cpp

headers.files += \
                 random.h \
                 src_config. h

LIBS += -L$$GSL_LIB_DIR -lgsl -lm  -L$$QWT_LIB_DIR -lqwt6

headers.path = $$HIST_INCLUDE_DIR
