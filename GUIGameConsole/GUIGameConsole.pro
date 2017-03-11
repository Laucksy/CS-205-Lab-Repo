#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T12:26:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIGameConsole
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


SOURCES += main.cpp\
        mainwindow.cpp \
    guinewplayer.cpp \
    guiselectplayer.cpp \
    guitopthree.cpp \
    guistatistics.cpp

HEADERS  += mainwindow.h \
    guinewplayer.h \
    guiselectplayer.h \
    guitopthree.h \
    guistatistics.h

FORMS    += mainwindow.ui \
    guinewplayer.ui \
    guiselectplayer.ui \
    guitopthree.ui \
    guistatistics.ui
FORMS    += ../GUIRobot/guirobot.ui
FORMS    += ../GUIWorm/guiworm.ui

LIBS += -l sqlite3

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp

HEADERS += ../engines/worm.h
SOURCES += ../engines/worm.cpp

HEADERS += ../GUIRobot/guirobot.h
SOURCES += ../GUIRobot/guirobot.cpp

HEADERS += ../GUIWorm/guiworm.h
SOURCES += ../GUIWorm/guiworm.cpp

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
