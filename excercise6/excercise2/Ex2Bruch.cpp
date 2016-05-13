// Michael Kotzjan
// HFU, 09.05.2016

#include "./Ex2Bruch.h"

// ____________________________________________________________________________
Bruch::Bruch()
{
  n = d = 1;
}
// ____________________________________________________________________________
Bruch::Bruch(int a, int b)
{
  n = a;
  d = b;
}

// ____________________________________________________________________________
Bruch Bruch::operator+(const Bruch& b) const
{
  int x = n * b.d;
  int y = b.n * d;
  int z = d * b.d;

  return Bruch(x+y, z);
}

// ____________________________________________________________________________
Bruch Bruch::operator/(const Bruch& b) const
{
  return Bruch(n*b.d, d*b.n);
}

// ____________________________________________________________________________
ostream& operator<<(ostream& out, const Bruch& b)
{
  out << b.n << "/" << b.d;
  return out;
}

// ____________________________________________________________________________
bool operator==(const Bruch& b1, const Bruch& b2)
{
  return b1.n == b2.n && b1.d == b2.d;
}
