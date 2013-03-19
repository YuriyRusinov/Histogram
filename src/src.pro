TEMPLATE = lib
TARGET = rand_test

CONFIG += qt

DESTDIR = ../bin

include (../qt_hist.conf)

DEFINES += _HIST_DLL_
DEFINES += _FILE_OFFSET_BITS=64

HEADERS += HistWidget.h

SOURCES += HistWidget.cpp

headers.files += \
                 HistWidget.h \
                 src_config. h

headers.path = $$HIST_INCLUDE_DIR
