#include "log.h"
using namespace std;

Log::Log()
{
    SHOW_WHERE;
    fN = "defaultFile.txt";
}

Log::Log(Log &obj)
{
    SHOW_WHERE;
    fN = obj.fN;
}

void Log::operator=(Log &obj)
{
    fN = obj.fN;
}

/*
 * Passes the file name in this constructor for which file will be opening
 */
Log::Log(std::string fileName){
    SHOW_WHERE;
    fN = fileName;

}

// In the destructor the file handler is closed.
Log::~Log() {
    SHOW_WHERE;
    fh.close();
}

/*
 * Opens the data stream in append mode, adding on to any data that was in it before hand
 */
bool Log::openAppend()
{
    SHOW_WHERE;
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
    SHOW_WHERE;
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
    SHOW_WHERE;
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
    SHOW_WHERE;
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
    SHOW_WHERE;
    return fh.is_open();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference.  This allows chaining of multiple filehandler
// operations.

Log& Log::operator<<(std::string str) {
    SHOW_WHERE;
    try {
        fh << str;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(int integer) {
    SHOW_WHERE;
    try {
        fh << integer;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(char character) {
    SHOW_WHERE;
    try {
        fh << character;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(float floatingPoint) {
    SHOW_WHERE;
    try {
        fh << floatingPoint;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(double doublePoint) {
    SHOW_WHERE;
    try {
        fh << doublePoint;
    } catch(exception &e) {}
    return *this;
}
Log& Log::operator<<(wchar_t wideChar) {
    SHOW_WHERE;
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

