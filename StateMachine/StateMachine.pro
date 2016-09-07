TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    StateContext.cpp \
    StateIdle.cpp \
    StateKeyword.cpp \
    StateFaceDetect.cpp

HEADERS += \
    StateContext.h \
    State.h \
    StateIdle.h \
    StateKeyword.h \
    StateFaceDetect.h \
    Event.h

