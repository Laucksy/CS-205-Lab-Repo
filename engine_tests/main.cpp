#include "iostream"
#include "gtest/gtest.h"
#include "../engines/engine.h"
#include "../engines/robots.h"
#include "../engines/worm.h"

class RobotsTest : public ::testing::Test {
protected:
    Robots robot;
    RobotsTest() {
        robot = *(new Robots(5,3));
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
        worm = *(new Worm(10,20));
    }

    virtual ~WormTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }
};

//Tests the add and get methods
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

//Tests the init_board method
TEST_F(RobotsTest, TESTINITBOARD) {
    //void init_board();
    robot.init_board(5);
    ASSERT_EQ(robot.get(robot.playerRow,robot.playerCol), PSYM);
    int bots = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(robot.get(i,j) == RSYM) {
                bots++;
            }
        }
    }
    ASSERT_GT(bots, 0) << "No bots added to world";
}

//Tests the turn method with an input of .
TEST_F(RobotsTest, TESTTURNPERIOD) {
    //void turn();

    robot.init_board(5);
    robot.mode = 1;
    char first[robot.getRows()][robot.getCols()];
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.turn('.');
    int diffs = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    ASSERT_GT(diffs, 0) << "Nothing changed between turns";
}

//Tests the turn method with an input of >
TEST_F(RobotsTest, TESTTURNGT) {
    robot.init_board(1);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    char first[robot.getRows()][robot.getCols()];
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.turn('>');
    int diffs = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    if(diffs == 0) {
        robot.turn('t');
        robot.turn('>');
        for(int i = 0; i < robot.getRows(); i++) {
            for(int j = 0; j < robot.getCols(); j++) {
                if(first[i][j] != robot.get(i,j)) {
                    diffs++;
                }
            }
        }
        ASSERT_GT(diffs, 0) << "Nothing changed between turns";
    } else {
        ASSERT_EQ(firstRow, robot.playerRow);
        ASSERT_EQ(firstCol, robot.playerCol);
        ASSERT_GT(diffs, 0) << "Nothing changed between turns";
    }
    //ASSERT_EQ(robot.mode, 1);
}

//Tests the turn method with an input of w
TEST_F(RobotsTest, TESTTURNW) {
    //Command w
    robot.init_board(5);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    char first[robot.getRows()][robot.getCols()];
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            first[i][j] = robot.get(i,j);
        }
    }
    robot.turn('w');
    int diffs = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(first[i][j] != robot.get(i,j)) {
                diffs++;
            }
        }
    }
    //ASSERT_EQ(robot.mode, 2);
    ASSERT_EQ(firstRow, robot.playerRow);
    ASSERT_EQ(firstCol, robot.playerCol);
    ASSERT_GT(diffs, 0) << "Nothing changed between turns";
}

//Tests the turn method with an input of up
TEST_F(RobotsTest, TESTTURNUP) {
    //Moving up
    do {
        robot.init_board(0);
    } while(robot.playerRow != 4 || robot.playerCol != 2);
    robot.turn('k');
    ASSERT_EQ(robot.get(3,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('K');
    ASSERT_EQ(robot.get(0,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of up right
TEST_F(RobotsTest, TESTTURNUPRIGHT) {
    //Moving up and right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.turn('u');
    ASSERT_EQ(robot.get(1,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('b');
    robot.turn('U');
    ASSERT_EQ(robot.get(0,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of right
TEST_F(RobotsTest, TESTTURNRIGHT) {
    //Moving right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.turn('l');
    ASSERT_EQ(robot.get(2,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('h');
    robot.turn('L');
    ASSERT_EQ(robot.get(2,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of down right
TEST_F(RobotsTest, TESTTURNDOWNRIGHT) {
    //Moving down and right
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 0);
    robot.turn('n');
    ASSERT_EQ(robot.get(3,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('y');
    robot.turn('N');
    ASSERT_EQ(robot.get(4,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of down
TEST_F(RobotsTest, TESTTURNDOWN) {
    //Moving down
    do {
        robot.init_board(0);
    } while(robot.playerRow != 0 || robot.playerCol != 2);
    robot.turn('j');
    ASSERT_EQ(robot.get(1,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('J');
    ASSERT_EQ(robot.get(4,2), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of down left
TEST_F(RobotsTest, TESTTURNDOWNLEFT) {
    //Moving down and left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.turn('b');
    ASSERT_EQ(robot.get(3,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('u');
    robot.turn('B');
    ASSERT_EQ(robot.get(4,0), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of left
TEST_F(RobotsTest, TESTTURNLEFT) {
    //Moving left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.turn('h');
    ASSERT_EQ(robot.get(2,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('l');
    robot.turn('H');
    ASSERT_EQ(robot.get(2,0), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the turn method with an input of up left
TEST_F(RobotsTest, TESTTURNUPLEFT) {
    //Moving up and left
    do {
        robot.init_board(0);
    } while(robot.playerRow != 2 || robot.playerCol != 2);
    robot.turn('y');
    ASSERT_EQ(robot.get(1,1), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
    robot.turn('n');
    robot.turn('Y');
    ASSERT_EQ(robot.get(0,0), PSYM) << "Player position: "
                                    << robot.playerRow << ", "
                                    << robot.playerCol;
}

//Tests the teleport method
TEST_F(RobotsTest, TESTTURNTELEPORT) {
    robot.init_board(5);
    int firstRow = robot.playerRow;
    int firstCol = robot.playerCol;
    robot.turn('t');
    ASSERT_TRUE(firstRow != robot.playerRow || firstCol != robot.playerCol);

    robot.init_board(14);
    firstRow = robot.playerRow;
    firstCol = robot.playerCol;
    robot.turn('t');
    ASSERT_TRUE(firstRow != robot.playerRow || firstCol != robot.playerCol);
}

//Tests the ability of the robots to collide with themselves,
//heaps, and players
TEST_F(RobotsTest, TESTCOLLISIONS) {
    robot.init_board(14);
    robot.turn('.');
    int heaps = 0;
    int losses = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(robot.get(i,j) == TSYM) {
                heaps++;
            } if (robot.get(i,j) == LSYM) {
                losses++;
            }
        }
    }
    ASSERT_GT(heaps, 0) << "No heaps added to world";
    ASSERT_EQ(losses, 1) << "User collision not detected";
}

//Tests the clear method
TEST_F(RobotsTest, TESTCLEAR) {
    robot.init_board(5);
    robot.clear();
    int bots = 0;
    for(int i = 0; i < robot.getRows(); i++) {
        for(int j = 0; j < robot.getCols(); j++) {
            if(robot.get(i,j) == RSYM) {
                bots++;
            }
        }
    }
    ASSERT_EQ(bots, 0) << "Bots still in world";
}

//Tests the won method
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

//Tests the lost method
TEST_F(RobotsTest, TESTLOST) {
    //bool lost();
    ASSERT_FALSE(robot.lost());
    do {
        robot.init_board(0);
    } while(robot.playerRow != 0 || robot.playerCol != 0);
    ASSERT_TRUE(robot.add(RSYM,1,0));
    robot.turn('.');
    ASSERT_TRUE(robot.lost()) << robot.get(0,0) << ", " << robot.get(1,0);
}



TEST_F(WormTest, TESTSIMPLE) {
}

TEST_F(WormTest, ADDTEST)
{
    ASSERT_TRUE(worm.add('a',5,5)) << "Gameboard info " << worm.getRows() << "," << worm.getCols();
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
    EXPECT_EQ('0', worm.get(5,2));
    EXPECT_EQ('0', worm.get(5,1));
    EXPECT_EQ('0', worm.get(5,0));
}

TEST_F(WormTest, MOVEWORMTEST)
{
    worm.init();
    EXPECT_TRUE(worm.move(1, 1));
    EXPECT_EQ('@', worm.get(5,5));
    EXPECT_EQ('0', worm.get(5,3));
    EXPECT_EQ('0', worm.get(5,2));
    EXPECT_EQ('0', worm.get(5,1));
    EXPECT_EQ(' ', worm.get(5,0));
}

TEST_F(WormTest, SELFHITTEST)
{
    worm.init();
    EXPECT_TRUE(worm.move(1,1));
    EXPECT_TRUE(worm.move(0,1));
    EXPECT_TRUE(worm.move(3,1));
    EXPECT_FALSE(worm.move(4,1));
    EXPECT_FALSE(worm.alive);
}

TEST_F(WormTest, GETFOODTEST)
{
    worm.init();
    worm.addFruit();


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
