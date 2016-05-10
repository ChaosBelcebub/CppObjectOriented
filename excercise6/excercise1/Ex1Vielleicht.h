// Michael Kotzjan
// HFU, 10.05.2016

#ifndef EX1VIELLEICHT_H_
#define EX1VIELLEICHT_H_

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include "./Ex1Bruch.cpp"
#include "./Ex1EmptyObjException.cpp"

using namespace std;

template<typename T> class Vielleicht
{
  T m_wert;
  bool m_leer;
  
  public:
  // Constructor
  Vielleicht(T wert);
  Vielleicht();

  // Returns true if object is empty
  bool leer() const;

  // Returns the value
  const T& derWert() const;

  // Returns the value as string
  string text() const;

  // + operator
  Vielleicht<T> operator+(const Vielleicht<T>& v);

  // / operator
  Vielleicht<T> operator/(const Vielleicht<T>& v);
};

#endif // EX1VIELLEICHT_H_
