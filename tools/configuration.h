#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "string"
#include "baseclass.h"
using namespace std;


class Configuration : public BaseClass
{
public:
    Configuration();
    Configuration(string fp, string fn);
    ~Configuration(); // destructor
    string getConfig(string key);
    void setConfig(string key, string value);
    void setFilePath(string fp);
    void setFileName(string fn);
    void read();
    void write();
};

#endif // CONFIGURATION_H
