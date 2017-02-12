#include "robots.h"

/* Default constructor
 */
Robots::Robots() {
    playerRow = -1;
    playerCol = -1;
    mode = 0;
    score = 0;
}

/* Copy constructor
 * @param obj - Item to copy
 */
Robots::Robots(Robots &obj) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = obj.gameboard[i][j];
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
    score = obj.score;
}

/* Default destructor
 */
Robots::~Robots() {

}

/* Assignment operator
 * @param obj - object to copy
 */
void Robots::operator=(Robots &obj) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = obj.gameboard[i][j];
        }
    }
    playerRow = obj.playerRow;
    playerCol = obj.playerCol;
    mode = obj.mode;
    score = obj.score;
}

/* Adds object to board if space isn't already taken
 * @param obj - item to add to board
 * @param r - row to add to
 * @param c - column to add to
 * @return - true if successfully added, false if space already taken
 */
bool Robots::add(char obj, int r, int c) {
    if(r >= ROWS || c >= COLS) {return false;}
    if(gameboard[r][c] == ' ') {
        gameboard[r][c] = obj;
        return true;
    }
    return false;
}

/* Retrieves item at given cell
 * @param r - row to retrieve from
 * @param c - column to retrieve from
 * @return - char at given location
 */
char Robots::get(int r, int c) {
    if(r >= ROWS || c >= COLS) {return 'x';}
    return gameboard[r][c];
}

/* Returns score for the player
 * @return int - player score
 */
int Robots::getScore() {
    return score;
}

/* Initializes the board and adds bots
 * @param numBots - how many bots to add to board
 */
void Robots::init_board(int numBots) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' '; //Makes all cells blank
        }
    }
    mode = 0;
    playerRow = rand() % ROWS;
    playerCol = rand() % COLS;
    add(PSYM,playerRow,playerCol); //Puts player in random space
    for(int i = 0; i < numBots; i++) {
        bool placed = false;
        while(!placed) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            placed = add(RSYM,row,col); //Randomly places bots in open spaces
        }
    }
}

/* Makes all of the bots move and then the player
 * @param input - the command to run, blank if it's in an > or w command
 * @return boolean on whether the full turn went through or not.
 */
bool Robots::turn(char input) {
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
    char nextBoard[ROWS][COLS]; //Makes second board to transfer new moves to
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            nextBoard[i][j] = ' '; //Makes new board empty
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(get(i,j) == RSYM) { //Moves all robots first
                if(i - playerRow > 0 && j == playerCol) {
                    single_move(nextBoard,RSYM,i,j,1); //Moves up
                } else if(i - playerRow > 0 && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,2); //Moves up right
                } else if(i == playerRow && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,3); //Moves right
                } else if(i - playerRow < 0 && j - playerCol < 0) {
                    single_move(nextBoard,RSYM,i,j,4); //Moves down right
                } else if(i - playerRow < 0 && j == playerCol) {
                    single_move(nextBoard,RSYM,i,j,5); //Moves down
                } else if(i - playerRow < 0 && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,6); //Moves down left
                } else if(i == playerRow && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,7); //Moves left
                } else if(i - playerRow > 0 && j - playerCol > 0) {
                    single_move(nextBoard,RSYM,i,j,8); //Moves up left
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

    if(mode == 0) { //For clarification, AFAP is As Far As Possible
        if(input == 'h') {move(nextBoard,7,1);} //Moves up
        if(input == 'H') {move(nextBoard,7,2);} //Moves up AFAP
        if(input == 'l') {move(nextBoard,3,1);} //Moves up right
        if(input == 'L') {move(nextBoard,3,2);} //Moves up right AFAP
        if(input == 'k') {move(nextBoard,1,1);} //Moves right
        if(input == 'K') {move(nextBoard,1,2);} //Moves right AFAP
        if(input == 'j') {move(nextBoard,5,1);} //Moves down right
        if(input == 'J') {move(nextBoard,5,2);} //Moves down right AFAP
        if(input == 'y') {move(nextBoard,8,1);} //Moves down
        if(input == 'Y') {move(nextBoard,8,2);} //Moves down AFAP
        if(input == 'u') {move(nextBoard,2,1);} //Moves down left
        if(input == 'U') {move(nextBoard,2,2);} //Moves down left AFAP
        if(input == 'b') {move(nextBoard,6,1);} //Moves left
        if(input == 'B') {move(nextBoard,6,2);} //Moves left AFAP
        if(input == 'n') {move(nextBoard,4,1);} //Moves up left
        if(input == 'N') {move(nextBoard,4,2);} //Moves up left AFAP
    } else if(mode == 1) { //Handles if they're in > mode
        if(nextBoard[playerRow][playerCol] != ' ') {
            mode = 0;
            return false; //This means the player would die, so don't let it
        }
        nextBoard[playerRow][playerCol] = PSYM;
    } else {
        if(nextBoard[playerRow][playerCol] != ' ') {
            nextBoard[playerRow][playerCol] = LSYM; //Kill player
            mode = 0;
        } else {
            nextBoard[playerRow][playerCol] = PSYM;
        }
        if(input == '.' || input == ' ') {
            mode = 0; //Go back to normal mode
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = nextBoard[i][j]; //Copy new board to old one
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
bool Robots::single_move(char nextBoard[ROWS][COLS], char type,
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
    if((r + rShift) >= ROWS || (r + rShift) < 0 ||
            (c + cShift) >= COLS || (c + cShift) < 0) {
        return false; //Can't move to invalid space
    } else if(type == RSYM) { //Moving a robot
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
        if(nextBoard[r+rShift][c+cShift] != ' ') {
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
bool Robots::move(char nextBoard[ROWS][COLS], int direction, int distance) {
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
    int newRow = rand() % ROWS;
    int newCol = rand() % COLS;
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
    }
}

//void Robots::quit() {}

/*bool Robots::draw() {
    return false;
}*/

/* Clears gameboard
 */
void Robots::clear() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' ';
        }
    }
    mode = 0;
}

/* Checks if the game is won
 * @return boolean whether or not they won
 */
bool Robots::won() {
    int bots = 0;
    int heaps = 0;
    int losses = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
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
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(get(i,j) == LSYM) {
                found = true;
            }
        }
    }
    return found;
}
