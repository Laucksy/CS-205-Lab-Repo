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

TEST_F(RobotsTest, TESTSIMPLE) {
}

TEST_F(WormTest, TESTSIMPLE) {
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
