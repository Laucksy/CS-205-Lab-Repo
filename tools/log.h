#ifndef LOG_H
#define LOG_H



// The header file for the minimal Log class.
#include <fstream>
#include <string>

class Log
{
public:

    Log();  // default constructor
    ~Log(); // destructor

    // overloaded handler operator
    Log& operator<<(const std::string str);

private:

    // The file handler.
    std::ofstream fh;
};


#endif // LOG_H
