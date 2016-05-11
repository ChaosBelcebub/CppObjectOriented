// Michael Kotzjan
// HFU, 09.05.2016

#include <iostream>

using namespace std;

class Bruch
{
  public:
  int n;
  int d;

  Bruch();
  Bruch(int a, int b);

  Bruch operator+(const Bruch& b) const;
  Bruch operator/(const Bruch& b) const;
  friend ostream& operator<<(ostream& out, const Bruch& b);
  friend bool operator==(const Bruch& b1, const Bruch& b2);
};
