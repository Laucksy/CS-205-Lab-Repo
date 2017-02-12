#include "worm.h"



Worm::Worm()
{

}

Worm::~Worm()
{

}

void Worm::init()
{
    direction = 1;
    headLocation[0] = ROWS/2;//Maakes the y location of the body
    headLocation[1] = COLS/2;//makes the x location of the boyd

    add(headChar, headLocation[0], headLocation[1]);
    makeBody();
}

void Worm::makeBody()
{
    defineDirection();
    //add the first body peice first

    if(gameboard[headLocation[0] - dVector[0]][headLocation[1] - dVector[1]] != NULL)
    {
        std::cout <<"Couldnt add the first segment of the body";
    }else{
        bodyPieces[0][headLocation[0] - dVector[0], headLocation[1] - dVector[1]];
        add(bodyChar, bodyPieces[0][0], bodyPieces[0][1]);
        for(int x =1; x< startLength; x++)
        {
            addToBody();
        }
    }
}

bool Worm::addToBody()
{
    int lastR = 0;
    int lastC = 0;
    lastR = bodyPieces[length-1][0];//The row of the tail
    lastC = bodyPieces[length-1][1];//the collumn of the tail
    length ++;
    int tempArray[length][2];

    if(gameboard[lastC - dVector[0]][lastR - dVector[1]] != NULL)
    {
        std::cout <<"The tail peice could not be added";
        return false;
    }else{
        //Copies the old array to a new larger one
        for(int x = 0; x <length-1; x++)
        {
            tempArray[x][0] = bodyPieces[x][0];
            tempArray[x][1] = bodyPieces[x][1];
        }
        //add a new array piece
        tempArray[length-1][lastR - dVector[0], lastC - dVector[1]];
        //Make old array the new array
        delete[] bodyPieces;
        int bodyPieces[length][2];
        for(int x = 0; x <length; x++)
        {
            bodyPieces[x][0] = tempArray[x][0];
            bodyPieces[x][1] = tempArray[x][1];
        }
        delete[] tempArray;


        add(bodyChar, bodyPieces[length-1][0],bodyPieces[length-1][1]);
    }

}

bool Worm::add(char obj, int r, int c)
{
    if(gameboard[r][c] != NULL)
    {
        std::cout << "There was already a peice here";
        return false;
    }else{
        gameboard[r][c] = obj;
        return true;
    }
}

char Worm::get(int r, int c)
{
    return gameboard[r][c];
}

void Worm::remove(int r, int c)
{
    gameboard[r][c] = NULL;
}

void Worm::defineDirection()
{
    if(direction = 0)
    {
        dVector[0] = -1;
        dVector[1] = 0;
    }else if(direction = 1)
    {
        dVector[0] = 0;
        dVector[1] = 1;
    }else if(direction = 2)
    {
        dVector[0] = 1;
        dVector[1] = 0;
    }else if(direction = 3)
    {
        dVector[0] = 0;
        dVector[1] = -1;
    }
}
