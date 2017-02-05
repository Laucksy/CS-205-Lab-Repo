#include "configuration.h"
#include "iostream"
#include "log.h"
using namespace std;

int main(int argc, char *argv[])
{
    /*Configuration Code*/
    Configuration config;
    //config.setConfig("name", "erik laucks");
    //config.setConfig("age", "17");
    //config.setConfig("archetype", "nerd");
    config.write();
    cout << "\n";
    config.read();


    //Log Code

    Log logger("testFile.txt");
    logger.openTruncate();
    logger << 679;
    string hemp = "Werds";
    logger << hemp;
    logger << "CheeseQ's" << true << "bull";
    logger << 'a';
    logger << true;
    logger << 56.2234790354;
    logger.close();
    logger.flush();

    return 0;
}
