#ifndef LOG_H
#define LOG_H
<<<<<<< HEAD



// The header file for the minimal Log class.
#include <fstream>
#include <string>
#include <iostream>
#include "macros.h"
=======
>>>>>>> 99b6df66286747c648f14c18d9620ce7ae415657
#include "baseclass.h"
#include "macros.h"
#include "fstream"
#include "string"

class Log : public BaseClass
{
public:

    Log();  // default constructor
    Log(Log &obj);
    void operator=(Log &obj);
    Log(std::string fileName); // string passing constructor
    ~Log(); // destructor

    std::string getFileName();

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
