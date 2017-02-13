#include "worm.h"



Worm::Worm()
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' '; //Makes all cells blank
        }
    }
}

Worm::Worm(Worm &obj) {

    gameboard = obj.gameboard;

    headLocation = obj.headLocation;
    length = obj.length;
    bodyPieces = obj.bodyPieces;
    mode = obj.mode;
    score = obj.score;
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
    addFruit();
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
    }
}

bool Worm::addToBody()
{
    int lastR = 0;
    int lastC = 0;
    lastR = bodyPieces[length-1].rowPos;//The row of the tail
    lastC = bodyPieces[length-1].colPos;//the collumn of the tail


    //std::cout << "\n" << "lRow " << lastR << " lCol" << lastC << " " << sizeof(bodyPieces);;
    int rowPosition = lastR - dVector[0]; //New target location of tail peice
    int colPosition = lastC - dVector[1];
    if((rowPosition < ROWS && rowPosition >=0 ) && (colPosition < COLS && colPosition >= 0))
    {
        length += 1;

        if(gameboard[lastR - dVector[0]][lastC - dVector[1]] != ' ')
        {
            std::cout <<"The tail peice could not be added";
            return false;
        }else{
            bodyPieces.push_back(bodyPiece()); //Adds a empty spot the the back of worm vector
            bodyPieces[length-1].rowPos = rowPosition; // Sets the empty spot up
            bodyPieces[length-1].colPos = colPosition;
            add(bodyChar, bodyPieces[length-1].rowPos, bodyPieces[length-1].colPos);
            return true;
        }
    }
    return false;

}
/*
 * Makes the worm move in the direction given. Based on the distance it will move more that many peices
 * If there is a fruit in the way, the snake will eat it and grow by 1
 */
bool Worm::move(int dir, int distance)
{
    //Define the direction of the snake
    direction = dir;
    defineDirection();
    remove(headLocation[0], headLocation[1]);
    headLocation[0] += dVector[0];
    headLocation[1] += dVector[1];

    for(int x =0; x < distance; x++){
        if(add(headChar, headLocation[0], headLocation[1])) // Is true when the head can move
        {
            //Remove each peice from the gameboard, move each peice, add back to gameboard
            for(auto peice : bodyPieces)
            {
                remove(peice.rowPos, peice.colPos);
                peice.rowPos += dVector[0];
                peice.colPos += dVector[1];
                add(bodyChar, peice.rowPos, peice.colPos);
            }
            return true;
        }else{
            if(get(headLocation[0], headLocation[1]) == foodChar) //If where the head is going has a fruit
            {
                remove(headLocation[0], headLocation[1]); //Remove the fruit
                add(headChar, headLocation[0], headLocation[1]); //Add the head to the position

                //Remove each peice from the gameboard, move each peice, add back to gameboard
                for(auto peice : bodyPieces)
                {
                    remove(peice.rowPos, peice.colPos);
                    peice.rowPos += dVector[0];
                    peice.colPos += dVector[1];
                    add(bodyChar, peice.rowPos, peice.colPos);
                }
                //Add another peice to the body
                addToBody();
                return true;
            }else{
                //End the game
                alive = false;
                std::cout << "You have died you foool";
                std::cout << "Your length was " << length;
                return false;
            }
        }
    }
    return false;
}

/*
 * Puts  a fruit in a ranodm open spot
 */
void Worm::addFruit()
{
    bool generated = false;
    while(!generated)
    {
        int pRow = rand() % ROWS;
        int pCol = rand() % COLS;

        if(add(foodChar, pRow, pCol))
        {
            generated = true;
        }
    }
}

/*
 * Returns the char at given location
 */
char Worm::get(int r, int c)
{
    return gameboard[r][c];
}

/*
 * Adds the char in given location
 * If the space is occupied will return false
 */
bool Worm::add(char obj, int r, int c)
{
    if((r < ROWS && r >= 0 )&&(c < COLS && c >= 0))
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

/*
 * Removes the char in given space and replaces with ' '
 */
void Worm::remove(int r, int c)
{
    gameboard[r][c] = ' ';
}

/*
 * Takes the direction int, and converts it to a vector value for easier movements
 */
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
