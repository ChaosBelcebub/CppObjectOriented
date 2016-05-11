// Michael Kotzjan
// HFU, 10.05.2016

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "./Ex1EmptyObjException.h"
#include "./Ex1Vielleicht.h"

// ____________________________________________________________________________
TEST(Int, testDerWert)
{
  Vielleicht<int> v1;
  Vielleicht<int> v2(42);
  Vielleicht<int> v3(-5);

  try
  {
    v1.derWert();
    FAIL();
  } catch(EmptyObjException e) {
  }

  ASSERT_EQ(v2.derWert(), 42);
  ASSERT_EQ(v3.derWert(), -5);
}

// ____________________________________________________________________________
TEST(Int, testLeer)
{
  Vielleicht<int> v1;
  Vielleicht<int> v2(42);
  Vielleicht<int> v3(-5);

  ASSERT_TRUE(v1.leer());
  ASSERT_FALSE(v2.leer());
  ASSERT_FALSE(v3.leer());
}

// ____________________________________________________________________________
TEST(Int, testText)
{
  Vielleicht<int> v1;
  Vielleicht<int> v2(42);
  Vielleicht<int> v3(-5);

  ASSERT_EQ(v1.text(), "leer");
  ASSERT_EQ(v2.text(), "42");
  ASSERT_EQ(v3.text(), "-5");
}

// ____________________________________________________________________________
TEST(Int, testAddition)
{
  Vielleicht<int> v1;
  Vielleicht<int> v2(42);
  Vielleicht<int> v3(-5);

  Vielleicht<int> result = v1 + v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 + v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "37");
}

// ____________________________________________________________________________
TEST(Int, testDivision)
{
  Vielleicht<int> v1;
  Vielleicht<int> v2(42);
  Vielleicht<int> v3(-5);

  Vielleicht<int> result = v1 / v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 / v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "-8");
}

// ____________________________________________________________________________
TEST(Double, testDerWert)
{
  Vielleicht<double> v1;
  Vielleicht<double> v2(4.2);
  Vielleicht<double> v3(-5.3);

  try
  {
    v1.derWert();
    FAIL();
  } catch(EmptyObjException e) {
  }

  ASSERT_EQ(v2.derWert(), 4.2);
  ASSERT_EQ(v3.derWert(), -5.3);
}

// ____________________________________________________________________________
TEST(Double, testLeer)
{
  Vielleicht<double> v1;
  Vielleicht<double> v2(4.2);
  Vielleicht<double> v3(-5.3);

  ASSERT_TRUE(v1.leer());
  ASSERT_FALSE(v2.leer());
  ASSERT_FALSE(v3.leer());
}

// ____________________________________________________________________________
TEST(Double, testText)
{
  Vielleicht<double> v1;
  Vielleicht<double> v2(4.2);
  Vielleicht<double> v3(-5.3);

  ASSERT_EQ(v1.text(), "leer");
  ASSERT_EQ(v2.text(), "4.2");
  ASSERT_EQ(v3.text(), "-5.3");
}

// ____________________________________________________________________________
TEST(Double, testAddition)
{
  Vielleicht<double> v1;
  Vielleicht<double> v2(4.2);
  Vielleicht<double> v3(-5.3);

  Vielleicht<double> result = v1 + v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 + v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "-1.1");
}

// ____________________________________________________________________________
TEST(Double, testDivision)
{
  Vielleicht<double> v1;
  Vielleicht<double> v2(4.2);
  Vielleicht<double> v3(-5.3);

  Vielleicht<double> result = v1 / v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 / v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "-0.792453");
}

// ____________________________________________________________________________
TEST(String, testDerWert)
{
  Vielleicht<string> v1;
  Vielleicht<string> v2("Hallo Welt");
  Vielleicht<string> v3("Hallo");

  try
  {
    v1.derWert();
    FAIL();
  } catch(EmptyObjException e) {
  }

  ASSERT_EQ(v2.derWert(), "Hallo Welt");
  ASSERT_EQ(v3.derWert(), "Hallo");
}

// ____________________________________________________________________________
TEST(String, testLeer)
{
  Vielleicht<string> v1;
  Vielleicht<string> v2("Hallo Welt");
  Vielleicht<string> v3("Hallo");

  ASSERT_TRUE(v1.leer());
  ASSERT_FALSE(v2.leer());
  ASSERT_FALSE(v3.leer());
}

// ____________________________________________________________________________
TEST(String, testText)
{
  Vielleicht<string> v1;
  Vielleicht<string> v2("Hallo Welt");
  Vielleicht<string> v3("Hallo");

  ASSERT_EQ(v1.text(), "leer");
  ASSERT_EQ(v2.text(), "Hallo Welt");
  ASSERT_EQ(v3.text(), "Hallo");
}

// ____________________________________________________________________________
TEST(String, testAddition)
{
  Vielleicht<string> v1;
  Vielleicht<string> v2("Hallo Welt");
  Vielleicht<string> v3("Hallo");

  Vielleicht<string> result = v1 + v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 + v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "Hallo WeltHallo");
}

// ____________________________________________________________________________
TEST(String, testDivision)
{
  Vielleicht<string> v1;
  Vielleicht<string> v2("Hallo Welt");
  Vielleicht<string> v3("Hallo");

  Vielleicht<string> result = v1 / v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 / v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "Hallol");
}

// ____________________________________________________________________________
TEST(Bruch, testDerWert)
{
  Vielleicht<Bruch> v1;
  Vielleicht<Bruch> v2(Bruch(1, 2));
  Vielleicht<Bruch> v3(Bruch(1, 4));

  try
  {
    v1.derWert();
    FAIL();
  } catch(EmptyObjException e) {
  }

  ASSERT_EQ(v2.derWert(), Bruch(1, 2));
  ASSERT_EQ(v3.derWert(), Bruch(1, 4));
}

// ____________________________________________________________________________
TEST(Bruch, testLeer)
{
  Vielleicht<Bruch> v1;
  Vielleicht<Bruch> v2(Bruch(1, 2));
  Vielleicht<Bruch> v3(Bruch(1, 4));

  ASSERT_TRUE(v1.leer());
  ASSERT_FALSE(v2.leer());
  ASSERT_FALSE(v3.leer());
}

// ____________________________________________________________________________
TEST(Bruch, testText)
{
  Vielleicht<Bruch> v1;
  Vielleicht<Bruch> v2(Bruch(1, 2));
  Vielleicht<Bruch> v3(Bruch(1, 4));

  ASSERT_EQ(v1.text(), "leer");
  ASSERT_EQ(v2.text(), "1/2");
  ASSERT_EQ(v3.text(), "1/4");
}

// ____________________________________________________________________________
TEST(Bruch, testAddition)
{
  Vielleicht<Bruch> v1;
  Vielleicht<Bruch> v2(Bruch(1, 2));
  Vielleicht<Bruch> v3(Bruch(1, 4));

  Vielleicht<Bruch> result = v1 + v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 + v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "6/8");
}

// ____________________________________________________________________________
TEST(Bruch, testDivision)
{
  Vielleicht<Bruch> v1;
  Vielleicht<Bruch> v2(Bruch(1, 2));
  Vielleicht<Bruch> v3(Bruch(1, 4));

  Vielleicht<Bruch> result = v1 / v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 / v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "4/2");
}
