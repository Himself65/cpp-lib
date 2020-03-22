#include <gtest/gtest.h>
#include <iostream>
#include "library.h"

TEST(sample_test_case, sample_test) {
  EXPECT_EQ(1, 1);
}

TEST(sample_test_case, hellp_test) {
  EXPECT_EQ(hello(), "hello");
}

TEST(sprintf_test_case, base_test) {
  EXPECT_EQ(SPrintF("foo"), "foo");
}