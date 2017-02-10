#ifndef LOG_H
#define LOG_H



// The header file for the minimal Log class.
#include <fstream>
#include <string>
#include <iostream>
#include "macros.h"
#include "baseclass.h"

class Log : public BaseClass
{
public:

    Log();  // default constructor
    Log(Log &obj);
    void operator=(Log &obj);
    Log(std::string fileName); // string passing constructor
    ~Log(); // destructor

    // overloaded handler operator
    Log& operator<<(const std::string str);
    Log& operator<<(const int integer);
    Log& operator<<(const char character) ;
    Log& operator<<(const float floatingPoint) ;
    Log& operator<<(const double doublePoint) ;
    Log& operator<<(const wchar_t wideChar) ;

    bool openTruncate();
    bool openAppend();

    bool close();
    bool flush();
    bool isOpen();

private:

    // The file handler.
    std::ofstream fh;

    std::string fN;
};


#endif // LOG_H
