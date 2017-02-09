#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "map"
#include "string"
#include "baseclass.h"
using namespace std;


class Configuration : public BaseClass
{
public:
    Configuration();
    Configuration(Configuration &obj);
    void operator=(Configuration &obj);
    Configuration(string fn);
    Configuration(string fp, string fn);
    ~Configuration(); // destructor
    string getConfig(string key);
    void setConfig(string key, string value);
    string getFilePath();
    string getFileName();
    void setFilePath(string fp);
    void setFileName(string fn);
    void read();
    void write();

private:
    map<string,string> configMap;
    char delim = '|';
    string filePath;
    string fileName;
};

#endif // CONFIGURATION_H
