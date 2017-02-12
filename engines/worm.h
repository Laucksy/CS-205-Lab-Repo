#ifndef WORM_H
#define WORM_H

#define ROWS 10
#define COLS 8
#define startLength 4
//#define headChar @
#define bodyChar 0

#include "iostream"
#include "string"

class Worm
{
public:
    Worm();
    Worm(Worm &obj);
    ~Worm();
    void operator=(Worm &obj);
    void init();

    //Methods
    bool add(char obj, int r, int c);
    void remove(int r, int c);
    char get(int r, int c);
    bool move(int direction, int distance);
    void defineDirection();


    bool won();
    bool lost();


    //Varialbes
    char gameboard[ROWS][COLS];

    bool alive = true;

    int length = 1;

    char headChar = '@';
    int headLocation[2];//row,col of head loaction
    int bodyPieces[1][2];//[each body peice][Row,Col of body]

private:
        int direction;//N:0, E:1, S:2, W:3
        int dVector[2];//The direction vector
        void bodyMove();
        bool addToBody();
        void makeBody();


};

#endif // WORM_H
