#include <variant.hpp>

#include <gtest/gtest.h>

namespace exp = std::experimental;

TEST(Access_HoldsAlternative, Typical) {
  exp::variant<int, std::string> v(42);
  EXPECT_TRUE(exp::holds_alternative<0>(v));
  EXPECT_FALSE(exp::holds_alternative<1>(v));
  EXPECT_TRUE(exp::holds_alternative<int>(v));
  EXPECT_FALSE(exp::holds_alternative<std::string>(v));
}
