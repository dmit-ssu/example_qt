TEMPLATE = app
TARGET = unittest
SOURCES += main.cpp myclass.cpp
HEADERS += myclass.h

QT      += testlib
QT      -= gui

CONFIG  += console
CONFIG  -= app_bundle

DEFINES += SRCDIR=\\\"$$PWD/\\\"
