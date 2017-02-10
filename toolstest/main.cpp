#include <iostream>
#include "gtest/gtest.h"
#include "../tools/configuration.h"
#include "../tools/log.h"

class ConfigTest : public ::testing::Test {
    protected:
        ConfigTest() {
          // You can do set-up work for each test here.
        }

        virtual ~ConfigTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

class LogTest : public ::testing::Test {
    protected:
        LogTest() {
          // You can do set-up work for each test here.
        }

        virtual ~LogTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }
};

TEST(ConfigTest, TESTSIMPLE) {
    Configuration s1;
    Configuration s2("config.txt");
    ASSERT_EQ(s1.getFileName(), s2.getFileName()) << s1.getFileName() << " and " << s2.getFileName() << " should match!";
}

TEST(ConfigTest, TESTMAP) {
    Configuration s1("testconfig.txt");
    s1.setConfig("test", "value1");
    ASSERT_EQ(s1.getConfig("test"), "value1") << "These should match!"; //Tests new key
    s1.setConfig("test", "value2");
    ASSERT_EQ(s1.getConfig("test"), "value2") << "These should match!"; //Tests overwriting current key
}

TEST(ConfigTest, TESTREADWRITE) {
    Configuration s1("testconfig.txt");
    s1.setConfig("test", "value1new");
    s1.write();
    s1 = *(new Configuration("testconfig.txt"));
    ASSERT_EQ(s1.getConfig("test"), "value1new") << "These should match!"; //Tests reading/writing from file
}

TEST(LogTest, TESTSIMPLE) {
    Log s1;
    Log s2("defaultFile.txt");
    ASSERT_EQ(s1.getFileName(), s2.getFileName()) << s1.getFileName() << " and " << s2.getFileName() << " should match!";
}

TEST(LogTest, TESTOPENTRUNCATE) {
    Log s1("testlog.txt");
    ASSERT_FALSE(s1.isOpen()) << "File stream shouldn't be open";
    s1.openTruncate();
    ASSERT_TRUE(s1.isOpen()) << "File stream should be open";
    s1.close();
    s1.flush();
    ASSERT_FALSE(s1.isOpen()) << "File stream shouldn't be open";
}

TEST(LogTest, TESTOPENAPPEND) {
    Log s1("testlog.txt");
    ASSERT_FALSE(s1.isOpen()) << "File stream shouldn't be open";
    s1.openAppend();
    ASSERT_TRUE(s1.isOpen()) << "File stream should be open";
    s1.close();
    s1.flush();
    ASSERT_FALSE(s1.isOpen()) << "File stream shouldn't be open";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
