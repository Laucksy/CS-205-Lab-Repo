#ifndef WORM_H
#define WORM_H

#define startLength 4
//#define headChar @
//#define bodyChar 0

#include "engine.h"
#include "iostream"
#include "string"
#include "vector"
#include "random"

class Worm : public Engine
{
public:
    Worm();//Deafult constructor
    Worm(int r, int c);
    Worm(Worm &obj);//Copy Constructor
    ~Worm();//Dispose Constructor
    void operator=(Worm &obj);


    //Methods
    void init();                      //Initiate game
    bool move(int dir, int distance); //Makes the worm move in the
                                        //direction given a distance

    //These should be private, but are used by test methods
    void addFruit();        //Generates a fruit at a random spot

    //Varialbes
    bool alive = true;      //Tells if the snake is alive or dead
    int length = 1;         //The length of the snake, equivilant to score
int headLocation[2];//row,col of head loaction
int dVector[2];//The direction vector, [row, col]


private:
    //Methods
    //   worm Methods
    void defineDirection(); //Turns one digit direction value
                                //into a row and col number

    bool addToBody();       //Adds a peice to the end of the worm
    void makeBody();        //Generates the body for beggining

    //Variables

    //Custom struct that contains a row and col number
    struct bodyPiece{
        int rowPos;
        int colPos;
    };
    std::vector<bodyPiece> bodyPieces;//A vector to keep all the worms peices

    char headChar = '@';//Chracted used for the worm head
    char bodyChar = '0';//character used for worm body
    char foodChar = '*';//characted for the fruit


    int direction;//N:0, E:1, S:2, W:3


};



#endif // WORM_H
