#include <iostream>
#include "gtest/gtest.h"
#include "../engines/robots.h"
#include "../engines/worm.h"

class RobotsTest : public ::testing::Test {
    protected:
        Robots robot;
        RobotsTest() {
          // You can do set-up work for each test here.
        }

        virtual ~RobotsTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

class WormTest : public ::testing::Test {
    protected:
        Worm worm;
        WormTest() {
          // You can do set-up work for each test here.
        }

        virtual ~WormTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

/*
TEST_F(RobotsTest, TESTADDGET) {
    //void add(char obj, int r, int c);
    //char get(int r, int c);
    robot.init_board(0);
    ASSERT_TRUE(robot.add(RSYM,1,1));
    ASSERT_FALSE(robot.add(TSYM,1,1));
    ASSERT_EQ(robot.get(1,1), RSYM) << "Didn't add to legit spot";
    ASSERT_FALSE(robot.add(RSYM,10,10));
    ASSERT_EQ(robot.get(10,10), 'x') << "Added to unavailable spot";
}

TEST_F(RobotsTest, TESTINITBOARD) {
    //void init_board();
    robot.init_board(5);
    ASSERT_EQ(robot.get(robot.playerRow,robot.playerCol), PSYM) << "Player didn't show up";
    int bots = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(robot.get(i,j) == RSYM) {
                bots++;
            }
        }
    }
    ASSERT_GT(bots, 0) << "No bots added to world";
}

TEST_F(RobotsTest, TESTTURN) {
    //void turn();
    robot.init_board(5);
    robot.mode = 1;
    char first[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.turn('.');
    int diffs = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    ASSERT_GT(diffs, 0) << "Nothing changed between turns";



    robot.init_board(5);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    //first[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.turn('>');
    diffs = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    ASSERT_EQ(robot.mode, 1);
    ASSERT_EQ(firstRow, robot.playerRow);
    ASSERT_EQ(firstCol, robot.playerCol);
    ASSERT_GT(diffs, 0) << "Nothing changed between turns";

    //Command w
   robot.init_board(5);
   firstRow = robot.playerRow;
   firstCol = robot.playerCol;
   //first[ROWS][COLS];
   for(int i = 0; i < ROWS; i++) {
       for(int j = 0; j < COLS; j++) {
           first[i][j] = robot.get(i,j);
       }
   }
   robot.turn('w');
   diffs = 0;
   for(int i = 0; i < ROWS; i++) {
       for(int j = 0; j < COLS; j++) {
           if(first[i][j] != robot.get(i,j)) {
               diffs++;
           }
       }
   }
   ASSERT_EQ(robot.mode, 2);
   ASSERT_EQ(firstRow, robot.playerRow);
   ASSERT_EQ(firstCol, robot.playerCol);
   ASSERT_GT(diffs, 0) << "Nothing changed between turns";


   //Moving up
   do {
       robot.init_board(0);
   } while(robot.playerRow != 4 || robot.playerCol != 2);
   robot.turn('k');
   ASSERT_EQ(robot.get(3,2), PSYM);
   robot.turn('K');
   ASSERT_EQ(robot.get(0,2), PSYM);

   //Moving up and right
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 0);
   robot.turn('u');
   ASSERT_EQ(robot.get(1,1), PSYM);
   robot.turn('b');
   robot.turn('U');
   ASSERT_EQ(robot.get(0,0), PSYM);

   //Moving right
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 0);
   robot.turn('l');
   ASSERT_EQ(robot.get(2,1), PSYM);
   robot.turn('h');
   robot.turn('L');
   ASSERT_EQ(robot.get(2,2), PSYM);

   //Moving down and right
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 0);
   robot.turn('n');
   ASSERT_EQ(robot.get(3,1), PSYM);
   robot.turn('y');
   robot.turn('N');
   ASSERT_EQ(robot.get(4,2), PSYM);

   //Moving down
   do {
       robot.init_board(0);
   } while(robot.playerRow != 0 || robot.playerCol != 2);
   robot.turn('j');
   ASSERT_EQ(robot.get(1,2), PSYM);
   robot.turn('J');
   ASSERT_EQ(robot.get(4,2), PSYM);

   //Moving down and left
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 2);
   robot.turn('b');
   ASSERT_EQ(robot.get(3,1), PSYM);
   robot.turn('u');
   robot.turn('B');
   ASSERT_EQ(robot.get(4,0), PSYM);

   //Moving left
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 2);
   robot.turn('h');
   ASSERT_EQ(robot.get(2,1), PSYM);
   robot.turn('l');
   robot.turn('H');
   ASSERT_EQ(robot.get(2,0), PSYM);

   //Moving up and left
   do {
       robot.init_board(0);
   } while(robot.playerRow != 2 || robot.playerCol != 2);
   robot.turn('y');
   ASSERT_EQ(robot.get(1,1), PSYM);
   robot.turn('n');
   robot.turn('Y');
   ASSERT_EQ(robot.get(0,0), PSYM);



   robot.init_board(5);
   firstRow = robot.playerRow;
   firstCol = robot.playerCol;
   robot.turn('t');
   ASSERT_NE(firstRow, robot.playerRow);
   ASSERT_NE(firstCol, robot.playerCol);

   robot.init_board(14);
   firstRow = robot.playerRow;
   firstCol = robot.playerCol;
   robot.turn('t');
   ASSERT_EQ(firstRow, robot.playerRow);
   ASSERT_EQ(firstCol, robot.playerCol);
}
*/

/*TEST_F(RobotsTest, TESTSINGLEMOVE) {
    //void robot_move(int r, int c, int direction);
    do {
        robot.init_board(0);
    } while(robot.playerRow != 0 || robot.playerCol != 0 || robot.get(1,0) != ' ');
    ASSERT_TRUE(robot.add(RSYM,2,0));
    robot.single_move(2,0,1);
    ASSERT_EQ(robot.get(1,0), RSYM) << "Robot didn't move right";
}*/

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

/*TEST_F(RobotsTest, TESTACTION) {
    //bool action(char input);
    //Command >
    robot.init_board(5);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    char first[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.action('>');
    int diffs = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    ASSERT_EQ(robot.mode, 1);
    ASSERT_EQ(firstRow, robot.playerRow);
    ASSERT_EQ(firstCol, robot.playerCol);
    ASSERT_GT(diffs, 0) << "Nothing changed between turns";
    //Command w
   robot.init_board(5);
   firstRow = robot.playerRow;
   firstCol = robot.playerCol;
   //first[ROWS][COLS];
   for(int i = 0; i < ROWS; i++) {
       for(int j = 0; j < COLS; j++) {
           first[i][j] = robot.get(i,j);
       }
   }
   robot.action('w');
   diffs = 0;
   for(int i = 0; i < ROWS; i++) {
       for(int j = 0; j < COLS; j++) {
           if(first[i][j] != robot.get(i,j)) {
               diffs++;
           }
       }
   }
   ASSERT_EQ(robot.mode, 2);
   ASSERT_EQ(firstRow, robot.playerRow);
   ASSERT_EQ(firstCol, robot.playerCol);
   ASSERT_GT(diffs, 0) << "Nothing changed between turns";
}*/

/*TEST_F(RobotsTest, TESTMOVE) {
    //bool move(int direction, int distance);
    //Moving up
    do {
        robot.init_board(0);
    } while(robot.playerRow != 4 || robot.playerCol != 2);
    robot.move(1,1);
    ASSERT_EQ(robot.get(3,2), PSYM);
    robot.move(1,2);
    ASSERT_EQ(robot.get(0,2), PSYM);

    //Moving up and right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.move(2,1);
    ASSERT_EQ(robot.get(1,1), PSYM);
    robot.move(6,1);
    robot.move(2,2);
    ASSERT_EQ(robot.get(0,0), PSYM);

    //Moving right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.move(3,1);
    ASSERT_EQ(robot.get(2,1), PSYM);
    robot.move(7,1);
    robot.move(3,2);
    ASSERT_EQ(robot.get(2,2), PSYM);

    //Moving down and right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.move(4,1);
    ASSERT_EQ(robot.get(3,1), PSYM);
    robot.move(7,1);
    robot.move(4,2);
    ASSERT_EQ(robot.get(4,2), PSYM);

    //Moving down
    do {
        robot.init_board(0);
    } while(robot.playerRow != 0 || robot.playerCol != 2);
    robot.move(5,1);
    ASSERT_EQ(robot.get(1,2), PSYM);
    robot.move(5,2);
    ASSERT_EQ(robot.get(4,2), PSYM);

    //Moving down and left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.move(6,1);
    ASSERT_EQ(robot.get(3,1), PSYM);
    robot.move(2,1);
    robot.move(6,2);
    ASSERT_EQ(robot.get(4,0), PSYM);

    //Moving left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.move(7,1);
    ASSERT_EQ(robot.get(2,1), PSYM);
    robot.move(3,1);
    robot.move(7,2);
    ASSERT_EQ(robot.get(2,0), PSYM);

    //Moving up and left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.move(8,1);
    ASSERT_EQ(robot.get(1,1), PSYM);
    robot.move(4,1);
    robot.move(8,2);
    ASSERT_EQ(robot.get(0,0), PSYM);
}*/

/*TEST_F(RobotsTest, TESTTELEPORT) {
    //void teleport();
    robot.init_board(5);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    robot.teleport();
    ASSERT_NE(firstRow, robot.playerRow);
    ASSERT_NE(firstCol, robot.playerCol);

    robot.init_board(14);
    firstRow = robot.playerRow;
    firstCol = robot.playerCol;
    robot.teleport();
    ASSERT_EQ(firstRow, robot.playerRow);
    ASSERT_EQ(firstCol, robot.playerCol);
}*/

/*TEST_F(RobotsTest, TESTDRAW) {
    //bool draw();
    ASSERT_FALSE(robot.draw());
}*/


/*
TEST_F(RobotsTest, TESTWON) {
    //bool won();
    robot.init_board(0);
    ASSERT_FALSE(robot.won());
    if(robot.get(0,0) != PSYM) {
        ASSERT_TRUE(robot.add(TSYM,0,0));
    } else {
        ASSERT_TRUE(robot.add(TSYM,1,1));
    }
    ASSERT_TRUE(robot.won());
    robot.init_board(5);
    ASSERT_FALSE(robot.won());
}

TEST_F(RobotsTest, TESTLOST) {
    //bool lost();
    ASSERT_FALSE(robot.lost());
    do {
        robot.init_board(5);
    } while(robot.playerRow != 0 || robot.playerCol != 0);
    ASSERT_TRUE(robot.add(RSYM,1,0));
    robot.turn('.');
    ASSERT_TRUE(robot.lost());
}


*/


TEST_F(WormTest, TESTSIMPLE) {
}

TEST_F(WormTest, ADDTEST)
{
    ASSERT_TRUE(worm.add('a',5,5));
    ASSERT_TRUE(worm.add('b', 6,7));
    ASSERT_FALSE(worm.add('d',5,5));
}

TEST_F(WormTest, GETTEST)
{
    ASSERT_TRUE(worm.add('k',5,5));
    ASSERT_EQ('k', worm.get(5,5));
}

TEST_F(WormTest, ADDWORMTEST)
{
    worm.init();
    EXPECT_EQ('@', worm.get(5,4));
    EXPECT_EQ('0', worm.get(5,3));
    EXPECT_EQ('0', worm.get(6,4));
    EXPECT_EQ('0', worm.get(4,4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
