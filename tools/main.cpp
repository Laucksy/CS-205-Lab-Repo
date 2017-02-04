#include "configuration.h"
#include "iostream"
#include "log.h"
using namespace std;

int main(int argc, char *argv[])
{
    Configuration config;
    //config.setConfig("name", "erik laucks");
    //config.setConfig("age", "17");
    //config.setConfig("archetype", "nerd");
    config.write();
    cout << "\n";
    config.read();

    return 0;
}
