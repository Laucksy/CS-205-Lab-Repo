TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

# if you are having compiler complaints about pthread, uncomment the following
LIBS += -pthread

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest          \
                ../gtest/googletest/include/gtest/gtest.h

HEADERS += ../tools/baseclass.h
SOURCES += ../tools/baseclass.cpp

HEADERS += ../tools/configuration.h
SOURCES += ../tools/configuration.cpp

HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp
