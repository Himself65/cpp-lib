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

TEST(class_foo_test_case, base_test) {
  using std::move;
  Foo a = Foo(1);
  Foo &&b = move(a);
  EXPECT_EQ(a.number, b.number);
  a.number = 2;
  EXPECT_EQ(a.number, b.number);
}

TEST(class_foo_test_case, base_test_1) {
  using std::move;
  Foo a = Foo(1);
  // pass
  const Foo &&b = Foo(1);
  // fail
  //  const Foo&& c = a;
  auto fn = [](Foo &&foo) {
    return foo.number++, foo;
  };
  auto d = fn(move(a));
  EXPECT_EQ(a.number, 2);
  EXPECT_EQ(d.number, 2);
  auto e = fn(Foo(1));
  EXPECT_EQ(d.number, 2);
}


#define FOO(a, b, ...)                                                        \
  do {                                                                        \
    if (a > b) a = b;                                                         \
    else b = a;                                                               \
  } while (0);

TEST(macro_test, base_test) {
  auto fn = []() {
    auto a = 1;
    auto b = 2;
    FOO(a, b, a = 3);
    EXPECT_EQ(a, 1);
    EXPECT_EQ(b, 1);
  };
  fn();
}

#undef FOO

#define OP(name, operator) int name (int a, int b) { return a operator b; }

OP(add, +)

OP(sub, -)

OP(mul, *)

OP(division, /)

#undef OP
#define PRE func['+'] = add; func['-'] = sub; func['*'] = mul; func['/'] = division;
TEST(test_macro, func_test) {
  int (*func[256])(int, int);
  PRE;
  EXPECT_EQ(func['+'](1, 2), 3);
  EXPECT_EQ(func['-'](1, 2), -1);
  EXPECT_EQ(func['/'](6, 2), 3);
  EXPECT_EQ(func['*'](6, 2), 12);
}

int foo() {
  static int i = 0;
  return i += 1;
}

TEST(test_static, test) {
  EXPECT_EQ(foo(), 1);
  EXPECT_EQ(foo(), 2);
}

TEST(test_static, test_static_foo) {
  EXPECT_EQ(get_library_foo(), 2);
}

TEST(test_plus, test) {
  int a = 0, b = 0;
  ++a = b++;
  EXPECT_EQ(a, 0);
  EXPECT_EQ(b, 1);
}

TEST(run_for_each, test) {
  char strs[2][256] = {
      "123",
      "234"
  };
  for (auto str : strs) {
    int pos = 0;
    while (str[pos] != '\0') {
      std::cout << str[pos++];
    }
    std::cout << std::endl;
  }
}