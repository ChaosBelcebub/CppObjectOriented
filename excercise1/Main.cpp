// Michael Kotzjan
// HFU 14.03.2015

#include <iostream>
#include <math.h>

using namespace std;

struct Punkt
{
  long int x;
  long int y;
};

// Rectangular
struct Rechteck
{
  Punkt lu;
  Punkt ro;
};

// Prints a punkt
void printPunkt(Punkt p)
{
  cout << "Punkt: " << p.x << ", " << p.y << endl;
}

// Calculates the euklidean distance
double abstand(Punkt p1, Punkt p2)
{
  return sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
}

// Are the points the same?
bool gleich(const Punkt &p1, const Punkt &p2)
{
  return p1.x == p2.x && p1.y == p2.y;
}

// Returns the area
double flaeche(const Rechteck* r)
{
  return (r->ro.x - r->lu.x) * (r->ro.y - r->lu.y);
}

// Checks if a point is inside a rectangular
double innerhalb(const Rechteck &r, const Punkt &p)
{
  return p.x >= r.lu.x && p.x <= r.ro.x && p.y >= r.lu.y && p.y <= r.ro.y;
}

// Checks if a rectangular lap over an other
bool ueberlapp(const Rechteck *r1, const Rechteck *r2)
{
  if (r1->ro.x < r2->lu.x || r2->lu.x > r1->ro.x)
    return false;
  if (r1->ro.y < r2->lu.y || r2->lu.y > r1->ro.y)
    return false;
  return true;
}

// Dynamic creation of a point
Punkt* neuerPunkt()
{
  long int x, y;
  cout << "X-Wert eingeben: ";
  cin >> x;
  cout << "Y-Wert eingeben: ";
  cin >> y;
  
  Punkt* punkt = new Punkt();
  punkt->x = x;
  punkt->y = y;
  return punkt;
}

// Dynamic array
Punkt** neuesPunktFeld(int dim)
{
  Punkt** p = new Punkt*[dim];
  for (int i = 0; i < dim; ++i) {
    p[i] = neuerPunkt();
  }
  return p;
}

// Delete array
void clearPunktFeld(Punkt** p, int size)
{
  for (int i = 0; i < size; ++i) {
    delete p[i];
  }
  delete[] p;
}

int main(int argc, char *argv[])
{
  Punkt p;
  p.x = 10;
  p.y = 10;

  Punkt p1;
  p1.x = 2;
  p1.y = 2;

  Rechteck r;
  r.lu.x = 1;
  r.lu.y = 1;
  r.ro.x = 3;
  r.ro.y = 2;

  Rechteck r2;
  r2.lu.x = 1;
  r2.lu.y = 1;
  r2.ro.x = 2;
  r2.ro.y = 3;

  Rechteck r3;
  r3.lu.x = 0;
  r3.lu.y = 3;
  r3.ro.x = 1;
  r3.ro.y = 4;

  // Tests
  printPunkt(p);
  cout << "Abstand: " << abstand(p, p1) << endl;
  if (gleich(p, p)) cout << "Punkte p und p sind gleich." << endl;
  if (!gleich(p, p1)) cout << "Punkte p und p1 nicht gleich." << endl;
  cout << "Fläche: " << flaeche(&r) << endl;
  cout << "Fläche: " << flaeche(&r2) << endl;
  if (!innerhalb(r, p)) cout << "p nicht in r." << endl;
  if (innerhalb(r, p1)) cout << "p in r." << endl;
  if (ueberlapp(&r, &r2)) cout << "r überlappt mit r2" << endl;
  if (!ueberlapp(&r, &r3)) cout << "r überlappt r2 nicht" << endl;
  Punkt* np = neuerPunkt();
  printPunkt(*np);

  int size = 2;
  Punkt** a = neuesPunktFeld(size);
  clearPunktFeld(a, size);
}
