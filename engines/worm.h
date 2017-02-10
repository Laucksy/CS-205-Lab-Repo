#ifndef WORM_H
#define WORM_H

#define ROWS 5
#define COLS 3



class Worm
{
public:
    Worm();

    //Methods
    bool add(char obj, int r, int c);
    char get(int r, int c);
    void action(char input);
    void move(int direction, int distance);
    void bodyMove();

    bool won();
    bool lost();


    //Varialbes
    char gameboard[ROWS][COLS];

    bool alive = true;

    int length = 7;
    char headChar = '@';
    char bodyChar = '0';

    int headLocation[2];//row,col of head loaction
    int bodyPiece[2];
    int bodyChain[7];




};

#endif // WORM_H
