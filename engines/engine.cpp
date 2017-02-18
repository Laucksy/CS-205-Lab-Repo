#include "engine.h"

Engine::Engine() {
    rows = 4;
    cols = 4;
    // allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++)
        gameboard[i] = new char[cols];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            gameboard[i][j] = '_';
}

Engine::Engine(int r, int c) {
    rows = r;
    cols = c;
    // allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++)
        gameboard[i] = new char[cols];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            gameboard[i][j] = '_';
}

Engine::~Engine() {
    delete[] gameboard;
}

int Engine::getRows() {
    return rows;
}

int Engine::getCols() {
    return cols;
}

/* Retrieves item at given cell
 * @param r - row to retrieve from
 * @param c - column to retrieve from
 * @return - char at given location
 */
char Engine::get(int r, int c) {
    if(r >= rows || c >= cols || r < 0 || c < 0) {return 'x';}
    if(gameboard == NULL || gameboard[r] == NULL) {return 'x';}
    return gameboard[r][c];
}

/* Adds object to board if space isn't already taken
 * @param obj - item to add to board
 * @param r - row to add to
 * @param c - column to add to
 * @return - true if successfully added, false if space already taken
 */
bool Engine::add(char obj, int r, int c) {
    if(r >= rows || c >= cols || r < 0 || c < 0) {return false;}
    if(gameboard == NULL || gameboard[r] == NULL) {return false;}
    if(gameboard[r][c] == ' ') {
        gameboard[r][c] = obj;
        return true;
    }
    return false;
}

/* Removes the char in given space and replaces with ' '
 * @param r - row to remove from
 * @param c - column to remove from
 */
void Engine::remove(int r, int c) {
    if(r >= rows || c >= cols || r < 0 || c < 0) {return;}
    if(gameboard == NULL || gameboard[r] == NULL) {return;}
    gameboard[r][c] = ' ';
}



