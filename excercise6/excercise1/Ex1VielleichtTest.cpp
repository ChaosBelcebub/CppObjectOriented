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
  ASSERT_EQ(result.text(), "");
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

// ____________________________________________________________________________
TEST(CharPointer, testDerWert)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1;
  Vielleicht<char*> v2(cp1);
  Vielleicht<char*> v3(cp2);

  try
  {
    v1.derWert();
    FAIL();
  } catch(EmptyObjException e) {
  }

  char* result1 = v2.derWert();
  char* result2 = v3.derWert();
  
  for(int i = 0; i < 10; ++i)
  {
    ASSERT_EQ(result1[i], cp1[i]);
  }
  for(int i = 0; i < 10; ++i)
  {
    ASSERT_EQ(result2[i], cp2[i]);
  }
}

// ____________________________________________________________________________
TEST(CharPointer, testLeer)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1;
  Vielleicht<char*> v2(cp1);
  Vielleicht<char*> v3(cp2);

  ASSERT_TRUE(v1.leer());
  ASSERT_FALSE(v2.leer());
  ASSERT_FALSE(v3.leer());
}

// ____________________________________________________________________________
TEST(CharPointer, testText)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1;
  Vielleicht<char*> v2(cp1);
  Vielleicht<char*> v3(cp2);

  ASSERT_EQ(v1.text(), "leer");
  ASSERT_EQ(v2.text(), "Hallo Welt");
  ASSERT_EQ(v3.text(), "Hallo");
}

// ____________________________________________________________________________
TEST(CharPointer, testAddition)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1;
  Vielleicht<char*> v2(cp1);
  Vielleicht<char*> v3(cp2);

  Vielleicht<char*> result = v1 + v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 + v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "Hallo WeltHallo");
}

// ____________________________________________________________________________
TEST(CharPointer, testDivision)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1;
  Vielleicht<char*> v2(cp1);
  Vielleicht<char*> v3(cp2);

  Vielleicht<char*> result = v1 / v2;
  ASSERT_TRUE(result.leer());
  ASSERT_EQ(result.text(), "leer");

  result = v2 / v3;
  ASSERT_FALSE(result.leer());
  ASSERT_EQ(result.text(), "");
}

// ____________________________________________________________________________
TEST(CharPointer, testCopy)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  cp1[10] = 0;
  cp2[5] = 0;
  Vielleicht<char*> v1(cp1);
  Vielleicht<char*> v2 = v1;
  v1.m_wert = cp2;
  ASSERT_EQ(v1.text(), "Hallo");
  ASSERT_EQ(v2.text(), "Hallo Welt");
}

// ____________________________________________________________________________
TEST(CharPointer, testAssign)
{
  char * cp1 = new char[11];
  char * cp2 = new char[6];
  char * cp3 = new char[5];
  strcpy(cp1, "Hallo Welt");
  strcpy(cp2, "Hallo");
  strcpy(cp3, "Test");
  cp1[10] = 0;
  cp2[5] = 0;
  cp3[4] = 0;
  Vielleicht<char*> v1(cp1);
  Vielleicht<char*> v2(cp2);
  Vielleicht<char*> v3;
  v2 = v1;
  v3 = v1;
  v1.m_wert = cp3;
  ASSERT_EQ(v1.text(), "Test");
  ASSERT_EQ(v2.text(), "Hallo Welt");
  ASSERT_EQ(v3.text(), "Hallo Welt");
  ASSERT_FALSE(v3.leer());
}
