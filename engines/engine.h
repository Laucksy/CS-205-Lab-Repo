#ifndef ENGINE_H
#define ENGINE_H


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
protected:
    int rows = 4;
    int cols = 4;

    // declaration
    char ** gameboard;

};

#endif // ENGINE_H
