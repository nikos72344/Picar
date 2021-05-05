QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PiCalcCore/add_funcs.cpp \
    PiCalcCore/core.cpp \
    PiCalcCore/errors_list.cpp \
    main.cpp \
    picalc.cpp \
    picanvas.cpp \
    picorner.cpp \
    piobject.cpp

HEADERS += \
    PiCalcCore/add_funcs.h \
    PiCalcCore/core.h \
    PiCalcCore/errors_list.h \
    picalc.h \
    picanvas.h \
    picorner.h \
    piobject.h

FORMS += \
    picanvas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
