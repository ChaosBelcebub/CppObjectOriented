// Michael Kotzjan
// HFU, 18.04.2016

#include <iostream>

using namespace std;

class Vektor3d
{
  float x, y, z;

  public:
  Vektor3d(float a = 0, float b = 0, float c = 0) :
    x(a), y(b), z(c)
  {

  }

  // + operator
  friend Vektor3d operator+(const Vektor3d v1, const Vektor3d v2);

  // - operator
  friend Vektor3d operator-(const Vektor3d v1, const Vektor3d v2);

  // * operator for float
  friend Vektor3d operator*(const Vektor3d v, float f);

  // * operator for two vectors
  friend float operator*(const Vektor3d v1, const Vektor3d v2);

  // == operator
  friend bool operator==(const Vektor3d& v1, const Vektor3d& v2);

  // ++ präfix
  Vektor3d operator++()
  {
    x++;
    y++;
    z++;
    return *this;
  }

  // ++ postfix
  Vektor3d operator++(int d)
  {
    Vektor3d tmp = *this;
    x++;
    y++;
    z++;
    return tmp;
  }

  // << operator
  friend ostream& operator<<(ostream& out, Vektor3d v);

  // --präfix
  Vektor3d operator--()
  {
    x--;
    y--;
    z--;
    return *this;
  }

  // --postfix
  Vektor3d operator--(int d)
  {
    Vektor3d tmp = *this;
    x--;
    y--;
    z--;
    return tmp;
  }
};

// friend operator+
Vektor3d operator+(const Vektor3d v1, const Vektor3d v2)
{
  Vektor3d tmp(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
  return tmp;
}

// friend operator-
Vektor3d operator-(const Vektor3d v1, const Vektor3d v2)
{
  Vektor3d tmp(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
  return tmp;
}

// friend operator*
Vektor3d operator*(const Vektor3d v1, const float f)
{
  Vektor3d tmp(v1.x * f, v1.y * f, v1.z * f);
  return tmp;
}

// friend operator*
float operator*(const Vektor3d v1, const Vektor3d v2)
{
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

// friend operator==
bool operator==(const Vektor3d& v1, const Vektor3d& v2)
{
  return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

// friend operator<<
ostream& operator<<(ostream& out, Vektor3d v)
{
  out << '(' << v.x << " | " << v.y << " | " << v.z << ')';
  return out;
}

int main()
{
  cout << endl << "### Testcase 1 ###" << endl;
  cout << "-- Constructor" << endl;
  cout << "- Vektor3d v1();" << endl;
  cout << "- Vektor3d v2(1, 2, 3);" << endl;
  cout << "- Vektor3d v3(-3, -2, 1);" << endl;
  cout << "-- Print out the result:" << endl;
  Vektor3d v1;
  Vektor3d v2(1, 2, 3);
  Vektor3d v3(-3, -2, -1);
  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;
  cout << "v3: " << v3 << endl;

  cout << endl << "### Testcase 2 ###" << endl;
  cout << "-- Operator +" << endl;
  cout << "- Expected results:" << endl;
  cout << "v1 + v1 = (0 | 0 | 0)" << endl;
  cout << "v1 + v2 = (1 | 2 | 3)" << endl;
  cout << "v1 + v3 = (-3 | -2 | -1)" << endl;
  cout << "v2 + v3 = (-2 | 0 | 2)" << endl;
  cout << "- Print out the result:" << endl;
  cout << "v1 + v1 = " << v1 + v1 << endl;
  cout << "v1 + v2 = " << v1 + v2 << endl;
  cout << "v1 + v3 = " << v1 + v3 << endl;
  cout << "v2 + v3 = " << v2 + v3 << endl;

  cout << endl << "### Testcase 3 ###" << endl;
  cout << "-- Operator -" << endl;
  cout << "- Expected results:" << endl;
  cout << "v1 - v1 = (0 | 0 | 0)" << endl;
  cout << "v1 - v2 = (-1 | -2 | -3)" << endl;
  cout << "v2 - v1 = (1 | 2 | 3)" << endl;
  cout << "v2 - v3 = (4 | 4 | 4)" << endl;
  cout << "v3 - v2 = (-4 | -4 | -4)" << endl;
  cout << "- Print out the result:" << endl;
  cout << "v1 - v1 = " << v1 - v1 << endl;
  cout << "v1 - v2 = " << v1 - v2 << endl;
  cout << "v2 - v1 = " << v2 - v1 << endl;
  cout << "v2 - v3 = " << v2 - v3 << endl;
  cout << "v3 - v2 = " << v3 - v2 << endl;

  cout << endl << "### Testcase 4 ###" << endl;
  cout << "-- Operator *" << endl;
  cout << "- Expected results:" << endl;
  cout << "v1 * 2 = (0 | 0 | 0)" << endl;
  cout << "v2 * 0 = (0 | 0 | 0)" << endl;
  cout << "v2 * -1 = (-1 | -2 | -3)" << endl;
  cout << "v3 * 2 = (-6 | -4 | -2)" << endl;
  cout << "v1 * v2 = 0" << endl;
  cout << "v2 * v2 = 14" << endl;
  cout << "v3 * v2 = -10" << endl;
  cout << "- Print out the result:" << endl;
  cout << "v1 * 2 = " << v1 * 2 << endl;
  cout << "v2 * 0 = " << v2 * 0 << endl;
  cout << "v2 * -1 = " << v2 * -1 << endl;
  cout << "v3 * 2 = " << v3 * 2 << endl;
  cout << "v1 * v2 = " << v1 * v2 << endl;
  cout << "v2 * v2 = " << v2 * v2 << endl;
  cout << "v3 * v2 = " << v3 * v2 << endl;

  cout << endl << "### Testcase 5 ###" << endl;
  cout << "-- Operator ==" << endl;
  cout << "- Expected result:" << endl;
  cout << "v1 == v1: true" << endl;
  cout << "v1 == v2: false" << endl;
  cout << "v2 == v3: false" << endl;
  cout << "Vektor3d v4(-3, -2, -1);" << endl;
  cout << "v3 == v4: true" << endl;
  cout << "- Print out the result:" << endl;
  cout << "v1 == v1: " << (v1 == v1?"true":"false") << endl;
  cout << "v1 == v2: " << (v1 == v2?"true":"false") << endl;
  cout << "v2 == v3: " << (v2 == v3?"true":"false") << endl;
  Vektor3d v4(-3, -2, -1);
  cout << "v3 == v4: " << (v3 == v4?"true":"false") << endl;

  cout << endl << "### Testcase 6 ###" << endl;
  cout << "-- Operator ++" << endl;
  cout << "- Expected results:" << endl;
  cout << "++v1: (1 | 1 | 1)" << endl;
  cout << "++v1: (2 | 2 | 2)" << endl;
  cout << "++v2: (2 | 3 | 4)" << endl;
  cout << "++v3: (-2 | -1 | 0)" << endl;
  cout << "v1++: (2 | 2 | 2)" << endl;
  cout << "v2++: (2 | 3 | 4)" << endl;
  cout << "v3++: (-2 | -1 | 0)" << endl;
  cout << "v1: (3 | 3 | 3)" << endl;
  cout << "v2: (3 | 4 | 5)" << endl;
  cout << "v3: (-1 | 0 | 1)" << endl;
  cout << "- Print out the results:" << endl;
  cout << "++v1: " << ++v1 << endl;
  cout << "++v1: " << ++v1 << endl;
  cout << "++v2: " << ++v2 << endl;
  cout << "++v3: " << ++v3 << endl;
  cout << "v1++: " << v1++ << endl;
  cout << "v2++: " << v2++ << endl;
  cout << "v3++: " << v3++ << endl;
  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;
  cout << "v3: " << v3 << endl;

  cout << endl << "### Testcase 7 ###" << endl;
  cout << "-- Operator --" << endl;
  cout << "- Expected result:" << endl;
  cout << "--v1: (2 | 2 | 2)" << endl;
  cout << "--v1: (1 | 1 | 1)" << endl;
  cout << "--v2: (2 | 3 | 4)" << endl;
  cout << "--v3: (-2 | -1 | 0)" << endl;
  cout << "v1--: (1 | 1 | 1)" << endl;
  cout << "v2--: (2 | 3 | 4)" << endl;
  cout << "v3--: (-2 | -1 | 0)" << endl;
  cout << "v1: (0 | 0 | 0)" << endl;
  cout << "v2: (1 | 2 | 3)" << endl;
  cout << "v3: (-3 | -2 | -1)" << endl;
  cout << "- Print out the result:" << endl;
  cout << "--v1: " << --v1 << endl;
  cout << "--v1: " << --v1 << endl;
  cout << "--v2: " << --v2 << endl;
  cout << "--v3: " << --v3 << endl;
  cout << "v1--: " << v1-- << endl;
  cout << "v2--: " << v2-- << endl;
  cout << "v3--: " << v3-- << endl;
  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;
  cout << "v3: " << v3 << endl;

  cout << endl << "### Finished ###" << endl << endl;
}
