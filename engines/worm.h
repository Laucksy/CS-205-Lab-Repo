#ifndef WORM_H
#define WORM_H

#define ROWS 10
#define COLS 8
#define startLength 4
//#define headChar @
//#define bodyChar 0

#include "iostream"
#include "string"
#include "vector"

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
    bool move(int dir, int distance);
    void defineDirection();


    bool won();
    bool lost();


    //Varialbes
    char gameboard[ROWS][COLS];

    struct bodyPiece{
        int rowPos;
        int colPos;
    };

    bool alive = true;

    int length = 1;

    char headChar = '@';
    char bodyChar = '0';
    int headLocation[2];//row,col of head loaction
    std::vector<bodyPiece> bodyPieces;//[each body peice]

private:
        int direction;//N:0, E:1, S:2, W:3
        int dVector[2];//The direction vector, [row, col]
        void bodyMove();
        bool addToBody();
        void makeBody();


};



#endif // WORM_H
