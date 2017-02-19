#ifndef ROBOTS_H
#define ROBOTS_H
#define PSYM '@' //Player's symbol
#define RSYM '+' //Robots' symbol
#define TSYM '*' //Trash piles' symbol
#define LSYM 'L' //Symbol shown when player is eaten
                 //(makes lose() easy to implement)
#include "engine.h"
#include "iostream"
#include "string"

class Robots : public Engine
{
    public:
        //Constructors
        Robots();
        Robots(int r, int c);
        Robots(Robots &obj);
        ~Robots();
        void operator=(Robots &obj);

        //Methods
        //Gets and Sets
        int get_score();
        int get_init_bots();

        //Gameflow
        void init_board(int numBots);
        bool turn(char input);

        //Meta information
        void clear();
        void level();
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
        bool single_move(char** nextBoard,
                           char type, int r, int c, int direction);
        bool move(char** nextBoard, int direction, int distance);
        void teleport();

        //Variables
        int score;
        int initBots;
        int botNum;
};

#endif // ROBOTS_H
