#include "log.h"
#include <iostream>
#include "macros.h"
using namespace std;
string fN = "";

// In the default constructor the file handler is opened.
//Log::Log() {
//    fh.open("exampleLogFile.txt", std::ofstream::out | std::ofstream::app );
//}

/*
 * Passes the file name in this constructor for which file will be opening
 */
Log::Log(std::string fileName){
    fN = fileName;
    SHOW_WHERE;
    try {
        fh.open(fN, std::ofstream::out | std::ofstream::app );
    } catch(exception &e) {}
}

// In the destructor the file handler is closed.
Log::~Log() {
    fh.close();
}

/*
 * Opens the data stream in append mode, adding on to any data that was in it before hand
 */
bool Log::openAppend()
{
    if(fh.is_open()) {
        return false;
    } else {
        try {
            fh.open(fN, std::ofstream::out | std::ofstream::app);
        } catch(exception &e) {}
        return fh.is_open();
    }
}
/*
 * Opens the data stream in truncate mode, removing any data that was in it before hand
 */
bool Log::openTruncate()
{
    if(fh.is_open()) {
        return false;
    } else {
        try {
            fh.open(fN, std::ofstream::out | std::ofstream::trunc);
        } catch(exception &e) {}
        return fh.is_open();
    }
}

/*
 * Closes the data stream
 */
bool Log::close()
{
    try {
        fh.close();
        return true;
    } catch(exception &e) {}
    return false;
}
/*
 * Flushes the data stream
 */
bool Log::flush()
{
    try {
        fh.flush();
        return true;
    } catch(exception &e) {}
    return false;
}

/*
 * Returns if the data out stream is currently open
 */
bool Log::isOpen()
{
    return fh.is_open();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference.  This allows chaining of multiple filehandler
// operations.

Log& Log::operator<<(std::string str) {
    try {
        fh << str;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(int integer) {
    try {
        fh << integer;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(char character) {
    try {
        fh << character;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(float floatingPoint) {
    try {
        fh << floatingPoint;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(double doublePoint) {
    try {
        fh << doublePoint;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(wchar_t wideChar) {
    try {
        fh << wideChar;
    } catch(exception &e) {}
    return *this;
}

/*
Log& Log::operator<<(bool boolean) {
    if(boolean)
        fh << "True";
    else
        fh << "False";
    return *this;
}*/

