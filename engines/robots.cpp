#include "robots.h"

Robots::Robots() {
    playerRow = -1;
    playerCol = -1;
    mode = 0;
}

Robots::Robots(Robots &obj) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = obj.gameboard[i][j];
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
}

Robots::~Robots() {

}

void Robots::operator=(Robots &obj) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = obj.gameboard[i][j];
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
}

bool Robots::add(char obj, int r, int c) {
    if(r >= ROWS || c >= COLS) {return false;}
    if(gameboard[r][c] == ' ') {
        gameboard[r][c] = obj;
        return true;
    }
    return false;
}

char Robots::get(int r, int c) {
    if(r >= ROWS || c >= COLS) {return 'x';}
    return gameboard[r][c];
}

void Robots::init_board(int numBots) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' ';
        }
    }
    mode = 0;
    playerRow = rand() % ROWS;
    playerCol = rand() % COLS;
    add(playerRow,playerCol,PSYM);
    for(int i = 0; i < numBots; i++) {
        bool placed = false;
        while(!placed) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            placed = add(RSYM,row,col);
        }
    }
}

/* Makes all of the bots move and then the player
 * param: char input - the command to run, blank if it's in an > or w command
 * return: boolean on whether the full turn went through or not.
 */
bool Robots::turn(char input) {
    if(input == 'L') {
        return false;
    }
    if(input == 'q') {
        exit(0);
    }
    if(input == 't') {
        teleport();
        return true;
    }
    if(input == '>') {
        mode = 1;
    }
    if(input == 'w' || input == '.' || input == ' ') {
        mode = 2;
    }
    char nextBoard[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            nextBoard[i][j] = ' ';
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(get(i,j) == RSYM) {
                if(i - playerRow > 0 && j == playerCol) {
                    single_move(nextBoard,RSYM,i,j,1);
                } else if(i - playerRow > 0 && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,2);
                } else if(i == playerRow && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,3);
                } else if(i - playerRow < 0 && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,4);
                } else if(i - playerRow < 0 && j == playerCol) {
                    single_move(nextBoard,RSYM,i,j,5);
                } else if(i - playerRow < 0 && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,6);
                } else if(i == playerRow && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,7);
                } else if(i - playerRow > 0 && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,8);
                }
            }
        }
    }

    /*
      The commands are:
         h       move one square left
         l       move one square right
         k       move one square up
         j       move one square down
         y       move one square up and left
         u       move one square up and right
         b       move one square down and left
         n       move one square down and right
         .       (also space) do nothing for one turn
         HJKLBNYU
                 run as far as possible in the given direction
         >       do nothing for as long as possible
         t       teleport to a random location
         w       wait until you die or they all do
         q       quit
         ^L      redraw the screen
    */

    if(mode == 0) {
        if(input == 'h') {move(nextBoard,7,1);}
        if(input == 'H') {move(nextBoard,7,2);}
        if(input == 'l') {move(nextBoard,3,1);}
        if(input == 'L') {move(nextBoard,3,2);}
        if(input == 'k') {move(nextBoard,1,1);}
        if(input == 'K') {move(nextBoard,1,2);}
        if(input == 'j') {move(nextBoard,5,1);}
        if(input == 'J') {move(nextBoard,5,2);}
        if(input == 'y') {move(nextBoard,8,1);}
        if(input == 'Y') {move(nextBoard,8,2);}
        if(input == 'u') {move(nextBoard,2,1);}
        if(input == 'U') {move(nextBoard,2,2);}
        if(input == 'b') {move(nextBoard,6,1);}
        if(input == 'B') {move(nextBoard,6,2);}
        if(input == 'n') {move(nextBoard,4,1);}
        if(input == 'N') {move(nextBoard,4,2);}
    } else if(mode == 1) {
        if(nextBoard[playerRow][playerCol] != ' ') {
            mode = 0;
            return false;
        }
        nextBoard[playerRow][playerCol] = PSYM;
    } else {
        if(nextBoard[playerRow][playerCol] != ' ') {
            nextBoard[playerRow][playerCol] = LSYM;
        }
        nextBoard[playerRow][playerCol] = PSYM;
        if(input == '.' || input == ' ') {
            mode = 0;
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = nextBoard[i][j];
        }
    }
    return true;
}

bool Robots::single_move(char nextBoard[ROWS][COLS], char type, int r, int c, int direction) {
    int rShift = 0;
    int cShift = 0;
    if(direction == 1) {
        rShift = -1;
        cShift = 0;
    } else if(direction == 2) {
        rShift = -1;
        cShift = 1;
    } else if(direction == 3) {
        rShift = 0;
        cShift = 1;
    } else if(direction == 4) {
        rShift = 1;
        cShift = 1;
    } else if(direction == 5) {
        rShift = 1;
        cShift = 0;
    } else if(direction == 6) {
        rShift = 1;
        cShift = -1;
    } else if(direction == 7) {
        rShift = 0;
        cShift = -1;
    } else if(direction == 8) {
        rShift = -1;
        cShift = -1;
    }
    if(type == RSYM) {
        if(nextBoard[r+rShift][c+cShift] == RSYM) {
            nextBoard[r+rShift][c+cShift] = TSYM;
        } else {
            nextBoard[r+rShift][c+cShift] = RSYM;
            nextBoard[r][c] = ' ';
        }
        return true;
    } else if(type == PSYM) {
        if(nextBoard[r+rShift][c+cShift] != ' ') {
            return false;
        } else {
            nextBoard[r+rShift][c+cShift] = PSYM;
            nextBoard[r][c] = ' ';
            playerRow = r+rShift;
            playerCol = c+cShift;
            return true;
        }
    } else {
        return false;
    }
}

bool Robots::move(char nextBoard[ROWS][COLS], int direction, int distance) {
    if(distance == 1) {
        return single_move(nextBoard,PSYM,playerRow,playerCol,direction);
    } else {
        while(single_move(nextBoard,PSYM,playerRow,playerCol,direction)) {}
        return true;
    }
}

void Robots::teleport() {
    int newRow = rand() % ROWS;
    int newCol = rand() % COLS;
    if(gameboard[newRow][newCol] != ' ') {
        gameboard[newRow][newCol] = LSYM;
    } else {
        gameboard[newRow][newCol] = PSYM;
        gameboard[playerRow][playerCol] = ' ';
        playerRow = newRow;
        playerCol = newCol;
    }
}

//void Robots::quit() {}

bool Robots::draw() {
    return false;
}

bool Robots::won() {
    int bots = 0;
    int heaps = 0;
    int losses = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(get(i,j) == RSYM) {
                bots++;
            } else if(get(i,j) == TSYM) {
                heaps++;
            } else if(get(i,j) == LSYM) {
                losses++;
            }
        }
    }
    return bots == 0 && heaps > 0 && losses == 0;
}

bool Robots::lost() {
    bool found = false;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(get(i,j) == LSYM) {
                found = true;
            }
        }
    }
    return found;
}
