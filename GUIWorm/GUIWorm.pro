#-------------------------------------------------
#
# Project created by QtCreator 2017-02-20T11:49:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIWorm
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -l sqlite3

SOURCES += main.cpp\
        guiworm.cpp \
    ../engines/engine.cpp \
    ../engines/worm.cpp

HEADERS  += guiworm.h \
    ../engines/engine.h \
    ../engines/worm.h

FORMS    += guiworm.ui

HEADERS += ../reference/player.h
SOURCES += ../reference/player.cpp

HEADERS += ../reference/playergamehistory.h
SOURCES += ../reference/playergamehistory.cpp

HEADERS += ../reference/game.h
SOURCES += ../reference/game.cpp

HEADERS += ../reference/gamehistory.h
SOURCES += ../reference/gamehistory.cpp

HEADERS += ../reference/dbtool.h
SOURCES += ../reference/dbtool.cpp

HEADERS += ../reference/dbtable.h
SOURCES += ../reference/dbtable.cpp

HEADERS += ../reference/dbtablegame.h
SOURCES += ../reference/dbtablegame.cpp

HEADERS += ../reference/dbtableplayer.h
SOURCES += ../reference/dbtableplayer.cpp
