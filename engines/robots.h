#ifndef ROBOTS_H
#define ROBOTS_H
#define ROWS 5
#define COLS 3

class Robots
{
    public:
        Robots();

        //Methods
        char add(char obj, int r, int c);
        char get(int r, int c);

        void turn();
        void action(char input);
        void move(int direction, int distance);
        void do_nothing();
        void teleport();
        void wait();
        void quit();
        void redraw();

        bool won();
        bool lost();

        //Variables
        char gameboard[ROWS][COLS];
        int robotRow;
        int robotCol;
};

#endif // ROBOTS_H
