TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    newplayer.cpp \
    selectplayer.cpp \
    topplayers.cpp \
    topgames.cpp \
    calculatestats.cpp \
    mainmenu.cpp \
    screen.cpp \
    screens.cpp \
    ../reference/game.cpp \
    ../reference/gamehistory.cpp \
    ../reference/player.cpp \
    ../reference/playergamehistory.cpp \
    ../reference/dbtool.cpp \
    ../reference/dbtable.cpp \
    ../reference/dbtablegame.cpp \
    ../reference/dbtableplayer.cpp


LIBS    += -lncurses \
            -lform \
             -l sqlite3

HEADERS += \
    newplayer.h \
    selectplayer.h \
    topplayers.h \
    topgames.h \
    calculatestats.h \
    mainmenu.h \
    screen.h \
    screens.h \
    ../reference/game.h \
    ../reference/gamehistory.h \
    ../reference/player.h \
    ../reference/playergamehistory.h \
    ../reference/dbtool.h \
    ../reference/dbtable.h \
    ../reference/dbtablegame.h \
    ../reference/dbtableplayer.h
