TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    playergamehistory.cpp \
    game.cpp \
    gamehistory.cpp \
    dbtool.cpp \
    dbtable.cpp \
    dbtablegame.cpp \
    dbtableplayer.cpp

HEADERS += \
    player.h \
    playergamehistory.h \
    game.h \
    gamehistory.h \
    dbtool.h \
    dbtable.h \
    dbtablegame.h \
    dbtableplayer.h

LIBS += -l sqlite3
