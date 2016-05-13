// Michael Kotzjan
// HFU, 13.05.2016

#include <gtest/gtest.h>
#include <string>
#include "./Ex2Add.cpp"
#include "./Ex2Bruch.h"

using namespace std;

TEST(addInt, addOne)
{
  ASSERT_EQ(add(1), 1);
  ASSERT_EQ(add(-1), -1);
  ASSERT_EQ(add(42), 42);
  ASSERT_EQ(add(0), 0);
}

TEST(addInt, addTwo)
{
  ASSERT_EQ(add(0, 0), 0);
  ASSERT_EQ(add(1, 1), 2);
  ASSERT_EQ(add(-1, 2), 1);
  ASSERT_EQ(add(5, -3), 2);
  ASSERT_EQ(add(-5, -5), -10);
}

TEST(addInt, addThree)
{
  ASSERT_EQ(add(0, 0, 0), 0);
  ASSERT_EQ(add(1, 1, 1), 3);
  ASSERT_EQ(add(-3, 2, -2), -3);
  ASSERT_EQ(add(25, -5, 22), 42);
  ASSERT_EQ(add(-8, -5, -2), -15);
}

TEST(addString, addOne)
{
  ASSERT_EQ(add(string()), "");
  ASSERT_EQ(add(string("Hallo")), "Hallo");
  ASSERT_EQ(add(string("Test")), "Test");
}

TEST(addString, addTwo)
{
  ASSERT_EQ(add(string(), string()), "");
  ASSERT_EQ(add(string(), string("Hallo")), "Hallo");
  ASSERT_EQ(add(string("Hallo"), string("Welt")), "HalloWelt");
}

TEST(addString, addThree)
{
  ASSERT_EQ(add(string(), string(), string()), "");
  ASSERT_EQ(add(string(), string("Hallo"), string()), "Hallo");
  ASSERT_EQ(add(string("1"), string("2"), string("3")), "123");
}

TEST(addBruch, addOne)
{
  ASSERT_EQ(add(Bruch(1,1)), Bruch(1,1));
  ASSERT_EQ(add(Bruch(0,0)), Bruch(0,0));
  ASSERT_EQ(add(Bruch(-1,2)), Bruch(-1,2));
  ASSERT_EQ(add(Bruch(-5,-10)), Bruch(-5,-10));
}

TEST(addBruch, addTwo)
{
  ASSERT_EQ(add(Bruch(1,1), Bruch(1,1)), Bruch(2,1));
  ASSERT_EQ(add(Bruch(-1,1), Bruch(1,1)), Bruch(0,1));
  ASSERT_EQ(add(Bruch(2,3), Bruch(4,3)), Bruch(18,9));
  ASSERT_EQ(add(Bruch(5,3), Bruch(1,2)), Bruch(13,6));
}

TEST(addBruch, addThree)
{
  ASSERT_EQ(add(Bruch(0,0), Bruch(0,0), Bruch(0,0)), Bruch(0,0));
  ASSERT_EQ(add(Bruch(1,1), Bruch(1,1), Bruch(1,1)), Bruch(3,1));
  ASSERT_EQ(add(Bruch(1,2), Bruch(1,2), Bruch(-1, 1)), Bruch(0,4));
  ASSERT_EQ(add(Bruch(2,3), Bruch(4,3), Bruch(1,3)), Bruch(63,27));
}
