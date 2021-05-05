QT -= gui

TEMPLATE = lib
CONFIG += plugin

CONFIG += c++11

DESTDIR = ../Plugins

SOURCES += \
    piconfig.cpp

HEADERS += \
    piconfig.h \
    piconfiginterface.h

DISTFILES += PiConfig.json
