#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "string"
using namespace std;


class Configuration
{
public:
    Configuration();
    ~Configuration(); // destructor
    string getConfig(string key);
    void setConfig(string key, string value);
    void setFileName(string fn);
    void read();
    void write();
};

#endif // CONFIGURATION_H
