#include "log.h"
#include <iostream>
using namespace std;
string fN = "";
// In the default constructor the file handler is opened.
Log::Log() {
    fh.open("exampleLogFile.txt", std::ofstream::out | std::ofstream::app );
}

/*
 * Passes the file name in this constructor for which file will be opening
 */
Log::Log(std::string fileName){
    fN = fileName;
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
    if(fh.is_open())
    {
        return false;
    }else {
        fh.open(fN, std::ofstream::out | std::ofstream::app);
        return fh.is_open();
    }
}
/*
 * Opens the data stream in truncate mode, removing any data that was in it before hand
 */
bool Log::openTruncate()
{
    if(fh.is_open())
    {
        return false;
    }else {
        fh.open(fN, std::ofstream::out | std::ofstream::trunc);
        return fh.is_open();
    }
}

/*
 * Closes the data stream
 */
bool Log::close()
{
    fh.close();
    return true;
}
/*
 * Flushes the data stream
 */
bool Log::flush()
{
    fh.flush();
    return true;
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

    fh << str;
    return *this;
}
Log& Log::operator<<(int integer) {
    fh << integer;
    return *this;
}
Log& Log::operator<<(char character) {
    fh << character;
    return *this;
}
Log& Log::operator<<(float floatingPoint) {
    fh << floatingPoint;
    return *this;
}
Log& Log::operator<<(double doublePoint) {
    fh << doublePoint;
    return *this;
}
Log& Log::operator<<(wchar_t wideChar) {
    fh << wideChar;
    return *this;
}/*
Log& Log::operator<<(bool boolean) {
    if(boolean)
        fh << "True";
    else
        fh << "False";
    return *this;
}*/

