// Michael Kotzjan
// HFU, 10.05.2016

#include <gtest/gtest.h>
#include <string>
#include "./Ex1Vielleicht.h"

// ____________________________________________________________________________
TEST(Ex1VielleichtTest, IntegerTest)
{
  Vielleicht<int> v1;
  Vielleicht<double> v2;
  Vielleicht<string> v3;

  ASSERT_EQ(0, 0);
}
