#ifndef ROBOTS_H
#define ROBOTS_H
#define ROWS 5
#define COLS 3
#define PSYM '@' //Player's symbol
#define RSYM '+' //Robots' symbol
#define TSYM '*' //Trash piles' symbol
#define LSYM 'L' //Symbol shown when player is eaten
                 //(makes lose() easy to implement)
#include "iostream"
#include "string"

class Robots
{
    public:
        //Constructors
        Robots();
        Robots(Robots &obj);
        ~Robots();
        void operator=(Robots &obj);

        //Methods
        //Gets and Sets
        bool add(char obj, int r, int c);
        char get(int r, int c);
        int getScore();

        //Gameflow
        void init_board(int numBots);
        bool turn(char input);

        //Meta information
        void clear();
        bool won();
        bool lost();

        //Variables
        int playerRow;
        int playerCol;
        int mode; // 0 - action prompt every turn,
                  // 1 - wait as long as possible without prompting,
                  // 2 - wait until die

    private:
        //Methods
        //Movements
        bool single_move(char nextBoard[ROWS][COLS],
                           char type, int r, int c, int direction);
        bool move(char nextBoard[ROWS][COLS], int direction, int distance);
        void teleport();
        //void quit();
        //bool draw();

        //Variables
        char gameboard[ROWS][COLS];
        int score;
};

#endif // ROBOTS_H
