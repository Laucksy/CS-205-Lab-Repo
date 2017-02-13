#include "worm.h"



Worm::Worm()
{
}

Worm::Worm(int r, int c) : Engine::Engine(r, c)
{
}

Worm::Worm(Worm &obj) {
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = obj.gameboard[i][j];
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        headLocation[i] = obj.headLocation[i];
    }

    length = obj.length;
    bodyPieces = obj.bodyPieces;
}

Worm::~Worm()
{

}

void Worm::operator=(Worm &obj) {
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = obj.gameboard[i][j];
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        headLocation[i] = obj.headLocation[i];
    }

    length = obj.length;
    bodyPieces = obj.bodyPieces;
}

void Worm::init()
{
    direction = 1;
    headLocation[0] = rows/2;//Maakes the y location of the body
    headLocation[1] = cols/2;//makes the x location of the boyd
    //std::cout << dVector[0] << " DVECTORS  " << dVector[1] << "\n" ;
    add(headChar, headLocation[0], headLocation[1]);
    makeBody();
    addFruit();
}

void Worm::makeBody()
{
    defineDirection();
    //add the first body peice first

    if(gameboard[headLocation[0] - dVector[0]] != NULL &&
       gameboard[headLocation[0] - dVector[0]][headLocation[1] - dVector[1]]
            != ' ')
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


    //std::cout << "\n" << "lRow " << lastR << " lCol" << lastC
        //<< " " << sizeof(bodyPieces);;
    int rowPosition = lastR - dVector[0]; //New target location of tail peice
    int colPosition = lastC - dVector[1];
    if((rowPosition < rows && rowPosition >=0 ) &&
            (colPosition < cols && colPosition >= 0))
    {
        length += 1;

        if(gameboard[lastR - dVector[0]] != NULL &&
                gameboard[lastR - dVector[0]][lastC - dVector[1]] != ' ')
        {
            std::cout <<"The tail peice could not be added";
            return false;
        }else{
            bodyPieces.push_back(bodyPiece()); //Adds a empty spot to
                                                //the back of worm vector
            bodyPieces[length-1].rowPos = rowPosition; //Sets empty spot up
            bodyPieces[length-1].colPos = colPosition;
            add(bodyChar, bodyPieces[length-1].rowPos,
                    bodyPieces[length-1].colPos);
            return true;
        }
    }
    return false;

}
/*
 * Makes the worm move in the direction given. Based on the distance it
 * will move more that many peices
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
        if(add(headChar, headLocation[0], headLocation[1])) // Is true when
                                                          //the head can move
        {
            //Remove each peice from the gameboard, move each peice, add
                //back to gameboard
            for(auto peice : bodyPieces)
            {
                remove(peice.rowPos, peice.colPos);
                peice.rowPos += dVector[0];
                peice.colPos += dVector[1];
                add(bodyChar, peice.rowPos, peice.colPos);
            }
            return true;
        }else{
            if(get(headLocation[0], headLocation[1]) == foodChar)
                //If where the head is going has a fruit
            {
                remove(headLocation[0], headLocation[1]); //Remove the fruit
                add(headChar, headLocation[0], headLocation[1]);
                    //Add the head to the position

                //Remove each peice from the gameboard, move each peice,
                    //add back to gameboard
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
        int pRow = rand() % rows;
        int pCol = rand() % cols;

        if(add(foodChar, pRow, pCol))
        {
            generated = true;
        }
    }
}

/*
 * Takes the direction int, and converts it to a vector value for
 * easier movements
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
