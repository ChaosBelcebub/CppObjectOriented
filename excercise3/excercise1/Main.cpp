// Michael Kotzjan
// HFU 11.04.2015

#include <iostream>
#include <stdlib.h>

using namespace std;

class dyna
{
  int *p;
  public:
  dyna(int i);
  ~dyna() { delete p; }
  int get() { return *p; }
};

dyna::dyna(int i)
{
  p = new int;
  *p = i;
}

// gib negativen Wert
// zurueck
int neg(dyna &ob)
{
  return -ob.get();
}

int main()
{
  dyna o(-10);
  cout << o.get() << "\n";
  cout << neg(o) << "\n";
  dyna o2(20);
  cout << o2.get() << "\n";
  cout << neg(o2) << "\n";
  cout << o.get() << "\n";
  cout << neg(o) << "\n";

  return 0;
}
