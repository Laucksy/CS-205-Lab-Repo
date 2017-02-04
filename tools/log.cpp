#include "log.h"
using namespace std;
string fileName = "";
// In the default constructor the file handler is opened.
Log::Log() {

    fh.open("exampleLogFile.txt", std::ofstream::out | std::ofstream::app );
}

Log::Log(std::string fileName){
    fh.open(fileName, std::ofstream::out | std::ofstream::app);
}

// In the destructor the file handler is closed.
Log::~Log() {
    fh.close();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator<<(std::string str) {

    fh << str;
    fh << fileName;
    return *this;
}

