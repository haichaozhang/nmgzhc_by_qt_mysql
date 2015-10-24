#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T23:27:53
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheSQD_system
TEMPLATE = app


SOURCES += main.cpp\
        thesqdregister.cpp \
    connectiondatabases.cpp \
    thesqdmonitoring.cpp \
    databasesconfiguration.cpp \
    theworkermanage.cpp \
    thesqdusermanage.cpp \
    theserialporttest.cpp \
    theequipmentmangage.cpp \
    theworkshopmangage.cpp \
    theworkersearch.cpp \
    theequipmentsearch.cpp

HEADERS  += thesqdregister.h \
    connectiondatabases.h \
    thesqdmonitoring.h \
    databasesconfiguration.h \
    theworkermanage.h \
    thesqdusermanage.h \
    theserialporttest.h \
    theequipmentmangage.h \
    theworkshopmangage.h \
    theworkersearch.h \
    theequipmentsearch.h

FORMS    += thesqdregister.ui \
    thesqdmonitoring.ui \
    databasesconfiguration.ui \
    theworkermanage.ui \
    thesqdusermanage.ui \
    theserialporttest.ui \
    theequipmentmangage.ui \
    theworkshopmangage.ui \
    theworkersearch.ui \
    theequipmentsearch.ui

INCLUDEPATH+= C:\Qt\Qt5.4.0\5.4\mingw491_32\include\Qwt

LIBS+=-LC:\Qt\Qt5.4.0\5.4\mingw491_32\lib -lqwtd
LIBS+=-LC:\Qt\Qt5.4.0\5.4\mingw491_32\lib -lqwt
CONFIG += c++11


