TEMPLATE = app
TARGET = unittest
SOURCES += main.cpp

QT      += testlib
QT      -= gui

CONFIG  += console
CONFIG  -= app_bundle

DEFINES += SRCDIR=\\\"$$PWD/\\\"
