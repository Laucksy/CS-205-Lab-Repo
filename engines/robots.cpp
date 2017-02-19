#include "robots.h"
using namespace std;

/* Default constructor
 */
Robots::Robots() : Engine::Engine() {
    srand(time(NULL));
    playerRow = -1;
    playerCol = -1;
    mode = 0;
    score = 0;
    initBots = 0;
    botNum = 0;
}

Robots::Robots(int r, int c) : Engine::Engine(r, c) {
    srand(time(NULL));
    playerRow = -1;
    playerCol = -1;
    mode = 0;
    score = 0;
    initBots = rows * cols / 50;
    botNum = 0;
}

/* Copy constructor
 * @param obj - Item to copy
 */
Robots::Robots(Robots &obj) {
    srand(time(NULL));
    rows = obj.rows;
    cols = obj.cols;
    // allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++)
        gameboard[i] = new char[cols];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            gameboard[i][j] = ' ';
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = obj.gameboard[i][j];
                }
            }
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
    score = obj.score;
    initBots = obj.initBots;
    botNum = obj.botNum;
}

/* Default destructor
 */
Robots::~Robots() {

}

/* Assignment operator
 * @param obj - object to copy
 */
void Robots::operator=(Robots &obj) {
    srand(time(NULL));
    rows = obj.rows;
    cols = obj.cols;
    // allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++)
        gameboard[i] = new char[cols];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            gameboard[i][j] = ' ';
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = obj.gameboard[i][j];
                }
            }
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
    score = obj.score;
    initBots = obj.initBots;
    botNum = obj.botNum;
}

/* Returns score for the player
 * @return int - player score
 */
int Robots::get_score() {
    return score;
}

/* Returns initial bots
 * @return int - initial bots
 */
int Robots::get_init_bots() {
    return initBots;
}

/* Initializes the board and adds bots
 * @param numBots - how many bots to add to board
 */
void Robots::init_board(int numBots) {
    botNum = numBots;
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = ' '; //Makes all cells blank
                }
            }
        }
    }
    mode = 0;
    playerRow = rand() % rows;
    playerCol = rand() % cols;
    add(PSYM,playerRow,playerCol); //Puts player in random space
    for(int i = 0; i < numBots; i++) {
        bool placed = false;
        while(!placed) {
            int row = rand() % rows;
            int col = rand() % cols;
            placed = add(RSYM,row,col); //Randomly places bots in open spaces
        }
    }
}

/* Makes all of the bots move and then the player
 * @param input - the command to run, blank if it's in an > or w command
 * @return boolean on whether the full turn went through or not.
 */
bool Robots::turn(char input) {
    int oldScore = score;
    int oldPRow = playerRow;
    int oldPCol = playerCol;
    if(input == 'q') { //Quits on command
        std::cout << "Exiting";
        exit(0);
    }
    if(input == 't') { //Runs teleport
        teleport();
        return true;
    }
    if(input == '>') { //Sets up waiting
        mode = 1;
    }
    if(input == 'w' || input == '.' || input == ' ') {
        mode = 2; //Sets up wait until die
    }

    char** nextBoard = new char*[rows]; //Makes second board to transfer
                                                //new moves to
    for(int i = 0; i < rows; i++)
        nextBoard[i] = new char[cols];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(gameboard[i][j] == TSYM)
                nextBoard[i][j] = TSYM; //Adds trash piles to board
            else
                nextBoard[i][j] = ' '; //Makes new board empty
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

    if(mode == 0) { //For clarification, P means it went as far as possible
        bool moved = false;
        if(input == 'h') {moved = move(nextBoard,7,1);} //Moves up
        if(input == 'H') {moved = move(nextBoard,7,2);} //Moves up P
        if(input == 'l') {moved = move(nextBoard,3,1);} //Moves up right
        if(input == 'L') {moved = move(nextBoard,3,2);} //Moves up right P
        if(input == 'k') {moved = move(nextBoard,1,1);} //Moves right
        if(input == 'K') {moved = move(nextBoard,1,2);} //Moves right P
        if(input == 'j') {moved = move(nextBoard,5,1);} //Moves down right
        if(input == 'J') {moved = move(nextBoard,5,2);} //Moves down right P
        if(input == 'y') {moved = move(nextBoard,8,1);} //Moves down
        if(input == 'Y') {moved = move(nextBoard,8,2);} //Moves down P
        if(input == 'u') {moved = move(nextBoard,2,1);} //Moves down left
        if(input == 'U') {moved = move(nextBoard,2,2);} //Moves down left P
        if(input == 'b') {moved = move(nextBoard,6,1);} //Moves left
        if(input == 'B') {moved = move(nextBoard,6,2);} //Moves left P
        if(input == 'n') {moved = move(nextBoard,4,1);} //Moves up left
        if(input == 'N') {moved = move(nextBoard,4,2);} //Moves up left P
        if(!moved) {
            score = oldScore;
            playerRow = oldPRow;
            playerCol = oldPCol;
            delete[] nextBoard;
            return false;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(get(i,j) == RSYM) { //Moves all robots first
                bool moved = false;
                if(i - playerRow > 0 && j == playerCol) {
                    moved = single_move(nextBoard,RSYM,i,j,1); //Up
                } else if(i - playerRow > 0 && j - playerCol < 0) {
                    moved = single_move(nextBoard,RSYM,i,j,2); //Up right
                } else if(i == playerRow && j - playerCol < 0) {
                    moved = single_move(nextBoard,RSYM,i,j,3); //Right
                } else if(i - playerRow < 0 && j - playerCol < 0) {
                    moved = single_move(nextBoard,RSYM,i,j,4); //Down right
                } else if(i - playerRow < 0 && j == playerCol) {
                    moved = single_move(nextBoard,RSYM,i,j,5); //Down
                } else if(i - playerRow < 0 && j - playerCol > 0) {
                    moved = single_move(nextBoard,RSYM,i,j,6); //Down left
                } else if(i == playerRow && j - playerCol > 0) {
                    moved = single_move(nextBoard,RSYM,i,j,7); //Left
                } else if(i - playerRow > 0 && j - playerCol > 0) {
                    moved = single_move(nextBoard,RSYM,i,j,8); //Up left
                }
                if(!moved) {
                    score = oldScore;
                    playerRow = oldPRow;
                    playerCol = oldPCol;
                    delete[] nextBoard;
                    return false;
                }
            }
        }
    }

    if(mode == 1) { //Handles if they're in > mode
        if(nextBoard[playerRow][playerCol] != ' ') {
            mode = 0;
            score = oldScore;
            playerRow = oldPRow;
            playerCol = oldPCol;
            delete[] nextBoard;
            return false; //This means the player would die, so don't let it
        }
        nextBoard[playerRow][playerCol] = PSYM;
    }
    else if (mode == 2){
        if(nextBoard[playerRow][playerCol] != ' ') {
            nextBoard[playerRow][playerCol] = LSYM; //Kill player
            mode = 0;
        } else {
            nextBoard[playerRow][playerCol] = PSYM;
            if(won()) {
                score += (score - oldScore) * .1;
                mode = 0;
            }
        }
        if(input == '.' || input == ' ') {
            mode = 0; //Go back to normal mode
        }
    }

    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = nextBoard[i][j]; //Copy new board
                                                            //to old one
                }
            }
        }
    }
    if(mode == 1) { //Call again on > mode
        turn('>');
    } else if (mode == 2) { //Call again on w mode
        turn('w');
    }
    return true;
}

/* Executes a single space move on a given object
 * @param nextBoard - the temp gameboard
 * @param type - the object type to move
 * @param r - the row the object is at
 * @param c - the column the object is at
 * @param direction - the numerical direction to move
 * @return boolean whether the move was successfull or not
 */
bool Robots::single_move(char** nextBoard, char type,
                         int r, int c, int direction) {
    int rShift = 0; //Vertical shift from the current cell
    int cShift = 0; //Horizontal shift from the current cell
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
    if((r + rShift) >= rows || (r + rShift) < 0 ||
            (c + cShift) >= cols || (c + cShift) < 0) {
        return false; //Can't move to invalid space
    } else if(type == RSYM) { //Moving a robot
        if(nextBoard[r+rShift][c+cShift] == PSYM) {
            return false; //Can't move here or player dies
        }
        if(nextBoard[r+rShift][c+cShift] == RSYM) {
            nextBoard[r+rShift][c+cShift] = TSYM;
            score += 20; //Robot collides with robot
        } else if(nextBoard[r+rShift][c+cShift] == TSYM) {
            nextBoard[r+rShift][c+cShift] = TSYM;
            score += 10; //Robot collides with trash heap
        } else {
            nextBoard[r+rShift][c+cShift] = RSYM;
            nextBoard[r][c] = ' '; //Robot moves to open space
        }
        return true;
    } else if(type == PSYM) { //Moving a player
        if(nextBoard[r+rShift][c+cShift] != ' '
                || gameboard[r+rShift][c+cShift] != ' ') {
            return false; //Can't move here or player dies
        } else {
            nextBoard[r+rShift][c+cShift] = PSYM; //Move player here
            nextBoard[r][c] = ' '; //Clear old location
            playerRow = r+rShift; //Update location variables
            playerCol = c+cShift; //Update location variables
            return true;
        }
    } else {
        return false;
    }
}

/* Handles the moves to be made on the player
 * @param nextBoard - the temp gameboard
 * @param direction - the numerical direction to move
 * @param distance - the distance to move
 */
bool Robots::move(char** nextBoard, int direction, int distance) {
    if(distance == 1) {
        return single_move(nextBoard,PSYM,playerRow,playerCol,direction);
    } else {
        while(single_move(nextBoard,PSYM,playerRow,playerCol,direction)) {}
        return true;
    }
}

/* Teleports the player to a random location
 */
void Robots::teleport() {
    int newRow = rand() % rows;
    int newCol = rand() % cols;
    if(gameboard != NULL && gameboard[newRow] != NULL &&
            gameboard[newRow][newCol] != '\0' && gameboard[playerRow]
            != NULL && gameboard[playerRow][playerCol] != '\0') {
        if(gameboard[newRow][newCol] != ' ') { //Player dies
            gameboard[newRow][newCol] = LSYM;
            gameboard[playerRow][playerCol] = ' ';
            playerRow = newRow;
            playerCol = newCol;
        } else { //Player successfully moves
            gameboard[newRow][newCol] = PSYM;
            gameboard[playerRow][playerCol] = ' ';
            playerRow = newRow;
            playerCol = newCol;
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(get(i,j) == RSYM) { //Moves all robots
                        if(i - playerRow > 0 && j == playerCol) {
                            single_move(gameboard,RSYM,i,j,1); //Up
                        } else if(i - playerRow > 0 && j - playerCol < 0) {
                            single_move(gameboard,RSYM,i,j,2); //Up right
                        } else if(i == playerRow && j - playerCol < 0) {
                            single_move(gameboard,RSYM,i,j,3); //Right
                        } else if(i - playerRow < 0 && j - playerCol < 0) {
                            single_move(gameboard,RSYM,i,j,4); //Down right
                        } else if(i - playerRow < 0 && j == playerCol) {
                            single_move(gameboard,RSYM,i,j,5); //Down
                        } else if(i - playerRow < 0 && j - playerCol > 0) {
                            single_move(gameboard,RSYM,i,j,6); //Down left
                        } else if(i == playerRow && j - playerCol > 0) {
                            single_move(gameboard,RSYM,i,j,7); //Left
                        } else if(i - playerRow > 0 && j - playerCol > 0) {
                            single_move(gameboard,RSYM,i,j,8); //Up left
                        }
                    }
                }
            }
        }
    }
}

/* Clears gameboard
 */
void Robots::clear() {
    if(gameboard != NULL) {
        for(int i = 0; i < rows; i++) {
            if(gameboard[i] != NULL) {
                for(int j = 0; j < cols; j++) {
                    gameboard[i][j] = ' ';
                }
            }
        }
    }
    mode = 0;
}

/* Resets board for next level
 */
void Robots::level() {
    init_board(botNum + (botNum/10));
}

/* Checks if the game is won
 * @return boolean whether or not they won
 */
bool Robots::won() {
    int bots = 0;
    int heaps = 0;
    int losses = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(get(i,j) == RSYM) {
                bots++; //Counts bots
            } else if(get(i,j) == TSYM) {
                heaps++; //Counts trash heaps
            } else if(get(i,j) == LSYM) {
                losses++; //Counts loss symbols
            }
        }
    }
    return bots == 0 && heaps > 0 && losses == 0;
}

/* Checks if the game is lost
 * @return boolean whether or not they lost
 */
bool Robots::lost() {
    bool found = false;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(get(i,j) == LSYM) {
                found = true;
            }
        }
    }
    return found;
}
