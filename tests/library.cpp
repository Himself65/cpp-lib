#include <gtest/gtest.h>
#include <memory>
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

TEST(shared_ptr_test_case, base_test) {
  using std::string, std::shared_ptr, std::make_shared;
  auto *s1 = new string("foo");
  auto p1 = shared_ptr<string>(s1, [&](string *p) {
    EXPECT_TRUE(*p == string("called"));
    delete p;
    s1 = nullptr;
  });
  auto p2 = make_shared<string>("goo");

  *p1 = "called";
  p1 = p2;
  EXPECT_EQ(s1, nullptr);
}