#include <iostream>
#include "worm.h"

using namespace std;

int main(int argc, char *argv[])
{
    Worm worm(20,20);
    worm.init();

    cout << "Hello World!" << endl;
    return 0;
}
