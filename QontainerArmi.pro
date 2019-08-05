#-------------------------------------------------
#
# Project created by QtCreator 2018-12-20T12:58:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QontainerArmi
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        GUI/widget.cpp \
        GERARCHIA/arma.cpp \
        GERARCHIA/armaapolvere.cpp \
        GERARCHIA/armapneumatica.cpp \
        GERARCHIA/armabianca.cpp \
        GERARCHIA/esplosivo.cpp \
        GERARCHIA/armadafuoco.cpp \
        GUI/inserimento.cpp \
        GUI/comboboxtipoarma.cpp \
        GUI/dettagli.cpp \
        GUI/ricerca.cpp \
    GUI/layoutricercaelimina.cpp \
    GUI/elimina.cpp \
    GUI/imageutility.cpp \
    modello.cpp \
    nofilefoundexception.cpp

HEADERS += \
        GUI/widget.h \
        GERARCHIA/arma.h \
        GERARCHIA/armaapolvere.h \
        GERARCHIA/armapneumatica.h \
        GERARCHIA/armabianca.h \
        GERARCHIA/esplosivo.h \
        GERARCHIA/armadafuoco.h \
        GERARCHIA/list.h \
        GUI/inserimento.h \
        GUI/comboboxtipoarma.h \
        GUI/dettagli.h \
        GUI/ricerca.h \
    GUI/layoutricercaelimina.h \
    GUI/elimina.h \
    GUI/imageutility.h \
    modello.h \
    nofilefoundexception.h
RESOURCES += \
    resources.qrc
DISTFILES += \
    Immagini/choosefile.png \
    Immagini/icon.png \
    Immagini/noData.png \
    Immagini/deleteIcon.png \
    Immagini/searchIcon.png \
    Immagini/info.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
