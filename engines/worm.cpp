#include "worm.h"



Worm::Worm()
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' '; //Makes all cells blank
        }
    }
}

Worm::~Worm()
{

}



void Worm::init()
{
    direction = 1;
    headLocation[0] = ROWS/2;//Maakes the y location of the body
    headLocation[1] = COLS/2;//makes the x location of the boyd
    //std::cout << dVector[0] << " DVECTORS  " << dVector[1] << "\n" ;
    add(headChar, headLocation[0], headLocation[1]);
    makeBody();
}

void Worm::makeBody()
{

    defineDirection();
    //add the first body peice first

    if(gameboard[headLocation[0] - dVector[0]][headLocation[1] - dVector[1]] != ' ')
    {
        std::cout <<"Couldnt add the first segment of the body";
    }else{
        bodyPieces.push_back(bodyPiece());
        bodyPieces[0].rowPos = headLocation[0] - dVector[0];
        bodyPieces[0].colPos = headLocation[1] - dVector[1];

        //add(bodyChar, bodyPieces[0].rowPos, bodyPieces[0].colPos);
        for(int x =1; x< startLength; x++)
        {
            addToBody();
        }

        for(int x = 0; x <length; x++)
        {
            add(bodyChar, bodyPieces[x].rowPos, bodyPieces[x].colPos);
        }
    }
}

bool Worm::addToBody()
{
    int lastR = 0;
    int lastC = 0;
    lastR = bodyPieces[length-1].rowPos;//The row of the tail
    lastC = bodyPieces[length-1].colPos;//the collumn of the tail


    std::cout << "\n" << "lRow " << lastR << " lCol" << lastC << " " << sizeof(bodyPieces);;
    int rowPosition = lastR - dVector[0];
    int colPosition = lastC - dVector[1];
    if((rowPosition <ROWS && rowPosition >=0 )&&(colPosition < COLS && colPosition >= 0))
    {
        length += 1;

        if(gameboard[lastR - dVector[0]][lastC - dVector[1]] != ' ')
        {
            std::cout <<"The tail peice could not be added";
            return false;
        }else{
            bodyPieces.push_back(bodyPiece());
            bodyPieces[length-1].rowPos = rowPosition;
            bodyPieces[length-1].colPos = colPosition;
            //delete[] tempArray;
            return true;
        }
    }
    return false;

}

bool Worm::add(char obj, int r, int c)
{
    if((r <ROWS && r >=0 )&&(c < COLS && c >= 0))
    {
        if(gameboard[r][c] != ' ')
        {
            std::cout << "There was already a peice here";
            return false;
        }else{
            gameboard[r][c] = obj;
            return true;
        }
    }
    std::cout <<"This index is out of bounds";
    return false;
}

bool Worm::move(int dir, int distance)
{
    direction = dir;
    defineDirection();
    remove(headLocation[0], headLocation[1]);
    headLocation[0] += dVector[0];
    headLocation[1] += dVector[1];

    for(int x =0; x < distance; x++){
        if(add(headChar, headLocation[0], headLocation[1]))
        {
            for(auto peice : bodyPieces)
            {
                remove(peice.rowPos, peice.colPos);
                peice.rowPos += dVector[0];
                peice.colPos += dVector[1];
                add(bodyChar, peice.rowPos, peice.colPos);
            }
            return true;
        }else{
            alive = false;
            std::cout << "You have died you foool";
            return false;
        }
    }
}

char Worm::get(int r, int c)
{
    return gameboard[r][c];
}

void Worm::remove(int r, int c)
{
    gameboard[r][c] = ' ';
}

void Worm::defineDirection()
{
    if(direction == 0)
    {
        dVector[0] = -1;
        dVector[1] = 0;
    }else if(direction == 1)
    {
        dVector[0] = 0;
        dVector[1] = 1;
    }else if(direction == 2)
    {
        dVector[0] = 1;
        dVector[1] = 0;
    }else if(direction == 3)
    {
        dVector[0] = 0;
        dVector[1] = -1;
    }

}
