#include "configuration.h"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "vector"
#include "map"
using namespace std;

/*
A map template should be used to store the information. Details about maps can be found in chapter 21.6 of the C++ book.
The Configuration class should be performing exception handling for the file manipulation and other features of the class.
There should be one method for set and get each.
The organization of the file is up to you, but the most reasonable structure is each line is a key-value pair
    separated by some special character that is not used in the key or value.
There must be methods for reloading and storing the object state from and to the file.
There should be methods to set/change a file path and a file name.
Overloaded operators can be used in the implementation, for setting and reading key-values, but keep it simple for now.
Methods for loading (when first loading the stored configuration) and reloading (an existing stored configuration)
    into the class should clear out any existing map data. Note, this code should be separate
    from the methods to store path/file names for flexibility.
*/

map<string,string> configMap;
string fileName = "config.txt";

Configuration::Configuration() {
    read();
}

Configuration::~Configuration() {
    write();
}

string Configuration::getConfig(string key) {
    if(configMap.find(key) != configMap.end())
        return configMap.find(key)->second;
    else
        return "";
}

void Configuration::setConfig(string key, string value) {
    configMap[key] = value;
}

void Configuration::setFileName(string fn) {
    fileName = fn;
}

void Configuration::read() {
    try {
        string line;
        ifstream file(fileName);
        if(file.is_open()) {
            configMap.clear();
            while(getline(file,line)) {
                stringstream ss(line);
                string item;
                vector<string> tokens;
                while(getline(ss, item, '|')) {
                    tokens.push_back(item);
                }
                cout << tokens.size() << "," << tokens[0] << "," << tokens[1] << "\n";
                configMap[tokens[0]] = tokens[1];
            }
            file.close();
        }
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}

void Configuration::write() {
    try {
        ofstream file;
        file.open(fileName, ios::out);
        for(map<string,string>::iterator iter=configMap.begin(); iter!=configMap.end(); ++iter)
            file << iter->first << "|" << iter->second << '\n';
        file.close();
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}
