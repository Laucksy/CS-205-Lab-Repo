#include "configuration.h"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "vector"
#include "map"
#include "macros.h"
using namespace std;

/* Default constructor
 */
Configuration::Configuration() {
    SHOW_WHERE;
    filePath = ""; //Default filepath
    fileName = "config.txt"; //Hardcoded filename (option 1)
    read(); //Loads file data into map
}

/* Copy constructor
 */
Configuration::Configuration(Configuration &obj) {
    SHOW_WHERE;
    configMap = obj.configMap;
    filePath = obj.filePath;
    fileName = obj.fileName;
    read(); //Loads file data into map
}

/* Copy assignment
 */
void Configuration::operator=(Configuration &obj) {
    configMap = obj.configMap;
    filePath = obj.filePath;
    fileName = obj.fileName;
    read(); //Loads file data into map
}

/* Constructor if the user wants to pass a file name
 * param: string fn, the name of the file
 */
Configuration::Configuration(string fn) {
    SHOW_WHERE;
    filePath = "";
    fileName = fn;
    read(); //Loads file data into map
}

/* Constructor if the user wants to pass a file name
 * param: string fn, the name of the file
 */
Configuration::Configuration(string fp, string fn) {
    SHOW_WHERE;
    filePath = fp;
    fileName = fn;
    read(); //Loads file data into map
}

/* Default destructor
 */
Configuration::~Configuration() {
    SHOW_WHERE;
    write(); //Writes map data to file
}

/* Returns the value in the map for a given key
 * param: string key, the key to search for in the map
 * return: the value for the given key
 */
string Configuration::getConfig(string key) {
    SHOW_WHERE;
    if(configMap.find(key) != configMap.end())
        return configMap.find(key)->second;
    else
        return ""; //Returns empty string if key isn't found
}

/* Sets the value for a key, overwriting a value if the key already exists.
 * param: key to add
 * param: value to add
 */
void Configuration::setConfig(string key, string value) {
    SHOW_WHERE;
    configMap[key] = value;
}

/* Gets the file path
 * return: file path
 */
string Configuration::getFilePath() {
    SHOW_WHERE;
    return filePath;
}

/* Gets the file name
 * return: file name
 */
string Configuration::getFileName() {
    SHOW_WHERE;
    return fileName;
}

/* Sets the file path
 * param: file path
 */
void Configuration::setFilePath(string fp) {
    SHOW_WHERE;
    filePath = fp;
}

/* Sets the file name
 * param: file name
 */
void Configuration::setFileName(string fn) {
    SHOW_WHERE;
    fileName = fn;
}

/* Reads the file and puts the data into a map
 */
void Configuration::read() {
    SHOW_WHERE;
    try {
        string line;
        ifstream file(filePath + fileName); //Open the file
        if(file.is_open()) {
            configMap.clear(); //Empty the map
            while(getline(file,line)) { //Loops through each line of the file
                stringstream ss(line);
                string item;
                vector<string> tokens;
                while(getline(ss, item, delim)) {
                    tokens.push_back(item); //Separates line into key and value
                }
                cout << tokens.size() << "," << tokens[0] << "," << tokens[1] << "\n";
                configMap[tokens[0]] = tokens[1]; //Add key/value pair to map
            }
            file.close();
        }
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}

/* Write from the map to the file
 */
void Configuration::write() {
    SHOW_WHERE;
    try {
        ofstream file;
        file.open(filePath + fileName, ios::out); //Open the file
        for(map<string,string>::iterator iter=configMap.begin(); iter!=configMap.end(); ++iter) //Iterate through all map elements
            file << iter->first << delim << iter->second << '\n'; //Write key/value to file separated by delimeter
        file.close();
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}
