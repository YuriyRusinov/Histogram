TEMPLATE = lib
TARGET = rand_test

CONFIG += qt

DESTDIR = ../bin

include (../qt_hist.conf)

INCLUDEPATH *= $$GSL_INC_DIR
DEPENDPATH *= $$GSL_INC_DIR

INCLUDEPATH *= $$QWT_INC_DIR
DEPENDPATH *= $$QWT_INC_DIR

INCLUDEPATH *= gui \
               gui/ui

DEPENDPATH *= gui \
              gui/ui

DEFINES += _HIST_DLL_
DEFINES += _FILE_OFFSET_BITS=64

include (gui/gui.pri)

HEADERS += \
           random.h \
           uniform_random.h \
           gaussian_random.h \
           exponential_random.h

SOURCES += \
           random.cpp \
           uniform_random.cpp \
           gaussian_random.cpp \
           exponential_random.cpp

headers.files += \
                 random.h \
                 uniform_random.h \
                 gaussian_random.h \
                 exponential_random.h \
                 src_config. h

LIBS += -L$$GSL_LIB_DIR -lgsl -lcblas -lm  -L$$QWT_LIB_DIR -lqwt6

headers.path = $$HIST_INCLUDE_DIR
