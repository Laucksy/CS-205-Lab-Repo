#ifndef ENGINE_H
#define ENGINE_H
#include "stddef.h"

class Engine
{
public:
    Engine();
    Engine(int r, int c);
    ~Engine();

    int getRows();
    int getCols();
    bool add(char obj, int r, int c);
    char get(int r, int c);
    void remove(int r, int c);

    int rows;
    int cols;

    // declaration
    char ** gameboard;
protected:


};

#endif // ENGINE_H
