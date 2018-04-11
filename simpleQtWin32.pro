QT += core
QT -= gui

CONFIG += c++11

TARGET = simpleQtWin32
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    CodeConvert.cpp

HEADERS += \
    CodeConvert.h
