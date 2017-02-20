#include "worm.h"

Worm::Worm()
{
}

Worm::Worm(int r, int c) : Engine::Engine(r, c)
{
    for(int i = 0; i <rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            gameboard[i][j] = ' ';
        }
    }
    //std::cout << "Complete Pasta";
}

Worm::Worm(Worm &obj) : Engine::Engine(obj.rows, obj.cols)
{
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
    //delete[] gameboard;
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

        add(bodyChar, bodyPieces[0].rowPos, bodyPieces[0].colPos);
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
    lastR = bodyPieces[bodyPieces.size()-1].rowPos;//The row of the tail
    lastC = bodyPieces[bodyPieces.size()-1].colPos;//the collumn of the tail

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
            bodyPieces[bodyPieces.size()-1].rowPos = rowPosition; //Sets empty spot up
            bodyPieces[bodyPieces.size()-1].colPos = colPosition;
            add(bodyChar, bodyPieces[bodyPieces.size()-1].rowPos,
                    bodyPieces[bodyPieces.size()-1].colPos);
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
    bool worked = false;
    for(int x =0; x < distance; x++){
        //Define the direction of the snake
        direction = dir;
        defineDirection();
        remove(headLocation[0], headLocation[1]);
        headLocation[0] += dVector[0];
        headLocation[1] += dVector[1];


        if(add(headChar, headLocation[0], headLocation[1])) // Is true when
            //the head can move
        {
            //Remove each peice from the gameboard, move each peice, add
            //back to gameboard
            remove(bodyPieces[0].rowPos, bodyPieces[0].colPos);
            bodyPieces[0].rowPos = headLocation[0] - dVector[0];
            bodyPieces[0].colPos = headLocation[1] - dVector[1];
            //add(bodyChar, bodyPieces[0].rowPos, bodyPieces[0].colPos);

            for(int i = bodyPieces.size()-1; i >0; i--)
            {
                remove(bodyPieces[i].rowPos, bodyPieces[i].colPos);
                bodyPieces[i].rowPos = bodyPieces[i-1].rowPos;
                bodyPieces[i].colPos = bodyPieces[i-1].colPos;
            }
            for(int i = bodyPieces.size()-1; i >= 0; i--)
            {
                add(bodyChar, bodyPieces[i].rowPos, bodyPieces[i].colPos);
            }
            worked =  true;
        }else{
            if(get(headLocation[0], headLocation[1]) == foodChar)
                //If where the head is going has a fruit
            {
                remove(headLocation[0], headLocation[1]); //Remove the fruit
                add(headChar, headLocation[0], headLocation[1]);
                //Add the head to the position

                remove(bodyPieces[0].rowPos, bodyPieces[0].colPos);
                bodyPieces[0].rowPos = headLocation[0] - dVector[0];
                bodyPieces[0].colPos = headLocation[1] - dVector[1];
                //Remove each peice from the gameboard, move each peice,
                //add back to gameboard
                for(int i = bodyPieces.size()-1; i >0; i--)
                {
                    remove(bodyPieces[i].rowPos, bodyPieces[i].colPos);
                    bodyPieces[i].rowPos = bodyPieces[i-1].rowPos;
                    bodyPieces[i].colPos = bodyPieces[i-1].colPos;
                }
                for(auto pieces : bodyPieces)
                {
                    add(bodyChar, pieces.rowPos, pieces.colPos);
                }
                //Add another peice to the body
                addToBody();
                addFruit();
                worked =  true;
            }else{
                //End the game
                alive = false;
                worked =  false;
                return false;
            }
        }
    }
    return worked;
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
