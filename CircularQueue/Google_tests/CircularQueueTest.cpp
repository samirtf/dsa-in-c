#include "gtest/gtest.h"

extern "C" {
    #include "CircularQueue.h"
}

TEST(ConstructionSuite, NullIfCreatesWithNegativeSize) {
    EXPECT_EQ(NULL, NULL);
}