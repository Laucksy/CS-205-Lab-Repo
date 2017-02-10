TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# if you are having compiler complaints about pthread, uncomment the following
LIBS += -pthread

SOURCES += main.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest          \
                ../gtest/googletest/include/gtest/gtest.h

HEADERS += ../tools/robots.h
SOURCES += ../tools/robots.cpp

HEADERS += ../tools/worm.h
SOURCES += ../tools/worm.cpp
