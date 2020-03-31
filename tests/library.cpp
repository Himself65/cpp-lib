#include <gtest/gtest.h>
#include <vector>
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

TEST(vector_test_case, base_test) {
  std::vector<int> my_vector;
  my_vector.push_back(1);
  my_vector.push_back(2);
  my_vector.push_back(3);
  EXPECT_EQ(my_vector.size(), 3);
}