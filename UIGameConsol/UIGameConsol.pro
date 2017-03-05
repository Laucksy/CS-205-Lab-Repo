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
    ../reference/playergamehistory.cpp

LIBS    += -lncurses \
            -lform

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
    ../reference/playergamehistory.h
