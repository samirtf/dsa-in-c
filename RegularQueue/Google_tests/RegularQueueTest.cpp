#include "gtest/gtest.h"

extern "C" {
    #include "RegularQueue.h"
}

TEST(AbsoluteDateTestSuite, TestaSeRetornaUm){
    EXPECT_EQ(1, one());
}

TEST(AbsoluteDateTestSuite, TestaSeRetornaDois){
    EXPECT_EQ(123, 12);
}

TEST(AbsoluteDateTestSuite, TestaSeRetornaTres){
    EXPECT_FALSE(0);
}

TEST(AbsoluteDateTestSuite, TestaSeRetornaQuatro){
    EXPECT_FALSE(1 == 1);
}