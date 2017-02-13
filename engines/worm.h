#ifndef WORM_H
#define WORM_H

#define ROWSW 10
#define COLSW 8
#define startLength 4
//#define headChar @
//#define bodyChar 0

#include "iostream"
#include "string"
#include "vector"
#include "random"

class Worm
{
public:
    Worm();//Deafult constructor
    Worm(Worm &obj);//Copy Constructor
    ~Worm();//Dispose Constructor
    void operator=(Worm &obj);


    //Methods
    void init();                      //Initiate game
    bool move(int dir, int distance); //Makes the worm move in the
                                        //direction given a distance

    //These should be private, but are used by test methods
    void addFruit();        //Generates a fruit at a random spot
    char get(int r, int c);           //returns the char in the gameboard
     bool add(char obj, int r, int c); //Adds a char to specified position
                                        //in the gameboard

    //Varialbes
    char gameboard[ROWSW][COLSW]; //Char array that contains all the peices
    bool alive = true;      //Tells if the snake is alive or dead
    int length = 1;         //The length of the snake, equivilant to score



private:
    //Methods
    //   gamebord Methods

    void remove(int r, int c); //removes the char in the gameboard
                                //and replaces it with ' '


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

    int headLocation[2];//row,col of head loaction
    int direction;//N:0, E:1, S:2, W:3
    int dVector[2];//The direction vector, [row, col]

};



#endif // WORM_H
