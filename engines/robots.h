#ifndef ROBOTS_H
#define ROBOTS_H
#define ROWS 5
#define COLS 3

class Robots
{
    public:
        Robots();
        Robots(Robots &obj);
        ~Robots();
        void operator=(Robots &obj);

        //Methods
        void add(char obj, int r, int c);
        char get(int r, int c);

        void init_board();
        void turn();
        void robot_move(int r, int c, int direction);
        bool action(char input);
        bool move(int direction, int distance);
        void teleport();
        void quit();
        void draw();

        bool won();
        bool lost();

        //Variables
        char gameboard[ROWS][COLS];
        int playerRow;
        int playerCol;
        int mode; // 0 - action prompt every turn, 1 - wait as long as possible without prompting, 2 - wait until die
};

#endif // ROBOTS_H
