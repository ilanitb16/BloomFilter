#include <gtest/gtest.h>
#include <../src/Main.cpp>

TEST(create_array, BasicTest) {
    EXPECT_EQ(createArray("8"), 8);
    EXPECT_EQ(createArray("a"), 0);
    EXPECT_EQ(createArray("100 542 54"), 100);
    EXPECT_EQ(createArray("100 542 54 a"), 0);
}

TEST(check_black_list, BasicTest) {
    BitsArray arr = BitsArray(8);

    EXPECT_EQ(arr.addUrlToArray("www.example.com0"), true);
    EXPECT_EQ(arr.isBlackListed("www.example.com0"), true);
    EXPECT_EQ(arr.isBlackListed("www.example.com1"), false);
}
