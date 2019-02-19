TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    exception.cpp \
    object.cpp

HEADERS += \
    smartpointer.h \
    exception.h \
    object.h \
    list.h \
    seqlist.h \
    staticlist.h \
    dynamiclist.h \
    array.h \
    staticarray.h \
    dynamicarray.h \
    linklist.h

RESOURCES += \
    dslib.qrc

QMAKE_CXXFLAGS += -Wno-unused-parameter

QMAKE_CXXFLAGS += -Wno-unused-variable

