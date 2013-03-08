TEMPLATE = lib
TARGET = rand_test

CONFIG += qt

DESTDIR = ../bin

include (../qt_hist.conf)

DEFINES += _FFTMATR_DLL_
DEFINES += _FILE_OFFSET_BITS=64

#INCLUDEPATH *= gui \
#               misc

#DEPENDSPATH *= gui \
#               misc

headers.files += \
                 fft_c.h \
                 matrix.h \
                 calcim.h

headers.path = $$HIST_INCLUDE_DIR
