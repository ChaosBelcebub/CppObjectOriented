// Michael Kotzjan
// HFU, 09.05.2016

#include <iostream>

using namespace std;

class Bruch
{
  public:
  int n;
  int d;

  Bruch(int a = 0)
  {
    n = 1;
    d = a;
  }

  Bruch(int a, int b)
  {
    n = a;
    d = b;
  }

  friend double operator+(const Bruch& b1, const Bruch& b2)
  {
    int x = b1.n * b2.d;
    int y = b2.n * b1.d;
    int z = b1.d * b2.d;

    return (x + y)/ z;
  }

  friend double operator/(const Bruch& b1, const Bruch& b2)
  {
    return (b1.n * b2.d)/(b1.d * b2.n);
  }

  friend ostream& operator<<(ostream& out, Bruch b)
  {
    out << b.n << "/" << b.d;
    return out;
  }
};
