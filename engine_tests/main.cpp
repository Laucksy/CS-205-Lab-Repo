#include <iostream>
#include "gtest/gtest.h"
#include "../engines/robots.h"
#include "../engines/worm.h"

class RobotsTest : public ::testing::Test {
    protected:
        RobotsTest() {
          // You can do set-up work for each test here.
        }

        virtual ~RobotsTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

class WormTest : public ::testing::Test {
    protected:
        WormTest() {
          // You can do set-up work for each test here.
        }

        virtual ~WormTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

TEST_F(RobotsTest, TESTADD) {
    //void add(char obj, int r, int c);
}

TEST_F(RobotsTest, TESTGET) {
    //char get(int r, int c);
}

TEST_F(RobotsTest, TESTINITBOARD) {
    //void init_board();
}

TEST_F(RobotsTest, TESTTURN) {
    //void turn();
}

TEST_F(RobotsTest, TESTROBOTMOVE) {
    //void robot_move(int r, int c, int direction);
}

TEST_F(RobotsTest, TESTACTION) {
    //bool action(char input);
}

TEST_F(RobotsTest, TESTMOVE) {
    //bool move(int direction, int distance);
}

TEST_F(RobotsTest, TESTTELEPORT) {
    //void teleport();
}

TEST_F(RobotsTest, TESTQUIT) {
    //void quit();
}

TEST_F(RobotsTest, TESTDRAW) {
    //void draw();
}

TEST_F(RobotsTest, TESTWON) {
    //bool won();
}

TEST_F(RobotsTest, TESTLOST) {
    //bool lost();
}





TEST_F(WormTest, TESTSIMPLE) {
}

TEST_F(WormTest, ADDTEST)
{
    Worm game1();
    ASSERT_TRUE(game1.add('a',5,5));
    ASSERT_TRUE(game1.add('b', 6,7));
    ASSERT_FALSE(game1.add('d',5,5));
}

TEST_F(WormTest, GETTEST)
{
    Worm game1();
    ASSERT_TRUE(game1.add('k',5,5));
    ASSERT_EQ('k', game1.get(5,5));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
