// Michael Kotzjan
// HFU 21.03.2015

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// Struct of a point
struct Punkt
{
  long int x;
  long int y;
};

// Rectangular
// Defined by two points, left down and right up
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
  double area = (r->ro.x - r->lu.x) * (r->ro.y - r->lu.y);
  return area >= 0 ? area : area*-1;
}

// Checks if a point is inside a rectangular
double innerhalb(const Rechteck &r, const Punkt &p)
{
  return p.x >= r.lu.x && p.x <= r.ro.x && p.y >= r.lu.y && p.y <= r.ro.y;
}

// Checks if a rectangular lap over an other
bool ueberlapp(const Rechteck *r1, const Rechteck *r2)
{
  if(r1->lu.x > r2->ro.x || r1->ro.x < r2->lu.x)
    return false;
  if(r1->lu.y > r2->ro.y || r1->ro.y < r2->lu.y)
    return false;
  return true;
}

// Dynamic creation of a point
Punkt* neuerPunkt()
{
  // Get the values
  long int x, y;
  cout << "X-Wert eingeben: ";
  cin >> x;
  cout << "Y-Wert eingeben: ";
  cin >> y;
  
  // Create new Point with values
  Punkt* punkt = new Punkt();
  punkt->x = x;
  punkt->y = y;
  return punkt;
}

// Dynamic array
Punkt** neuesPunktFeld(int dim)
{
  // Create an array of given dimension
  Punkt** p = new Punkt*[dim];
  // Fill array with new points
  for (int i = 0; i < dim; ++i) {
    p[i] = neuerPunkt();
  }
  return p;
}

// Delete array
void clearPunktFeld(Punkt** p, int dim)
{
  // Delete all points of the array
  for(int i=0; i < dim; ++i) {
    delete p[i];
  }
  // Delete array
  delete[] p;
}

// Max distance between points of my array
double maxAbstand(Punkt** field, Punkt* p1, Punkt* p2, int dim)
{
  double result = 0.0;
  double temp;
  // Iterate over all possible different pairs of points
  for(int i=0; i < dim; ++i)
  {
    for(int j=0; j < dim; ++j)
    {
      if(i != j)
      {
        // Calculate distance
        temp = abstand(*field[i], *field[j]);
        if(temp > result)
        {
          result = temp;
          *p1 = *field[i];
          *p2 = *field[j];
        }
      }
    }
  }
  return result;
}

double minWeg(Punkt** field, Punkt** weg, int dim)
{
  double result = -1;
  // Sort field
  sort(field, field+dim);
  // Calculate path for all permutations
  do
  {
    double tmp = 0;
    for(int i=1; i<dim; ++i)
    {
      tmp += abstand(*field[i], *field[i-1]);
    }
    // For the first iteration just store the path.
    // Else check if path is shorter
    if(result < 0 || (result >= 0 && tmp < result))
    {
      result = tmp;
      for(int i=0; i<dim; ++i)
      {
        *weg[i] = *field[i];
      }
    }
  } while(next_permutation(field, field+dim));
}

// Tests
int main(int argc, char *argv[])
{
  // Test 1
  // Print a Point
  cout << endl << "-- Test 1: Print a point --" << endl;
  cout << "Expected:" << endl;
  cout << "Punkt: 0, 0" << endl;
  cout << "Punkt: -2, -5" << endl;
  cout << "Punkt: 5, 42" << endl << endl;
  cout << "Result:" << endl;

  Punkt p1 = {0, 0};
  Punkt p2 = {-2, -5};
  Punkt p3 = {5, 42};

  printPunkt(p1);
  printPunkt(p2);
  printPunkt(p3);

  // Test 2
  // Distance
  cout << endl << "-- Test 2: Distance --" << endl;
  cout << "Expected:" << endl;
  cout << "0" << endl;
  cout << "0" << endl;
  cout << "2" << endl;
  cout << "4" << endl;
  cout << "7.07107" << endl << endl;
  cout << "Result:" << endl;

  Punkt p4 = {2, 0};
  Punkt p5 = {0, -4};
  Punkt p6 = {5, 5};

  cout << abstand(p1, p1) << endl;
  cout << abstand(p3, p3) << endl;
  cout << abstand(p1, p4) << endl;
  cout << abstand(p5, p1) << endl;
  cout << abstand(p6, p1) << endl;

  // Test 3
  // Same points?
  cout << endl << "-- Test 3: Are points the same? --" << endl;
  cout << "Expected:" << endl;
  cout << "True" << endl;
  cout << "True" << endl;
  cout << "False" << endl;
  cout << "False" << endl;
  cout << "False" << endl << endl;
  cout << "Result:" << endl;
  Punkt p7 = {5, 42};

  cout << (gleich(p1, p1) ? "True" : "False") << endl;
  cout << (gleich(p3, p7) ? "True" : "False") << endl;
  cout << (gleich(p1, p2) ? "True" : "False") << endl;
  cout << (gleich(p5, p6) ? "True" : "False") << endl;
  cout << (gleich(p2, p7) ? "True" : "False") << endl;

  // Test 4
  // Area
  cout << endl << "-- Test 4: Area --" << endl;
  cout << "Expected:" << endl;
  cout << "0" << endl;
  cout << "10" << endl;
  cout << "25" << endl;
  cout << "25" << endl << endl;
  cout << "Result:" << endl;

  Rechteck r1 = {p1, p1};
  Rechteck r2 = {p2, p1};
  Rechteck r3 = {p1, p6};
  Rechteck r4 = {p6, p1};

  cout << flaeche(&r1) << endl;
  cout << flaeche(&r2) << endl;
  cout << flaeche(&r3) << endl;
  cout << flaeche(&r4) << endl;

  // Test 5
  // Check if point is inside rectangular
  cout << endl << "-- Test 5: Point inside rectangular? --" << endl;
  cout << "Expected:" << endl;
  cout << "True" << endl;
  cout << "True" << endl;
  cout << "False" << endl;
  cout << "False" << endl;
  cout << "False" << endl;
  cout << "False" << endl << endl;
  cout << "Result:" << endl;

  cout << (innerhalb(r1, p1) ? "True" : "False") << endl;
  cout << (innerhalb(r3, p4) ? "True" : "False") << endl;
  cout << (innerhalb(r1, p2) ? "True" : "False") << endl;
  cout << (innerhalb(r3, p2) ? "True" : "False") << endl;
  cout << (innerhalb(r3, p3) ? "True" : "False") << endl;
  cout << (innerhalb(r3, p5) ? "True" : "False") << endl;

  // Test 6
  // Check if two rectangular lap over another
  cout << endl << "-- Test 6: Rectangular lap over? --" << endl;
  cout << "Expected:" << endl;
  cout << "True" << endl;
  cout << "True" << endl;
  cout << "True" << endl;
  cout << "False" << endl;
  cout << "False" << endl << endl;
  cout << "Result:" << endl;
  
  Rechteck r5 = {p6, p3};
  Rechteck r6 = {p2, p6};
  cout << (ueberlapp(&r1, &r1) ? "True" : "False") << endl;
  cout << (ueberlapp(&r6, &r2) ? "True" : "False") << endl;
  cout << (ueberlapp(&r2, &r6) ? "True" : "False") << endl;
  cout << (ueberlapp(&r5, &r1) ? "True" : "False") << endl;
  cout << (ueberlapp(&r1, &r5) ? "True" : "False") << endl;

  // Test 7
  // Dynamic creation of a new point
  cout << endl << "-- Test 7: Dynamic creation of a point --" << endl;
  cout << "Expected:" << endl;
  cout << "Enter values for 3 points." << endl;
  cout << "The printed output should be correct." << endl;

  Punkt* p8 = neuerPunkt();
  Punkt* p9 = neuerPunkt();
  Punkt* p10 = neuerPunkt();

  cout << endl << "Result:" << endl;

  printPunkt(*p8);
  printPunkt(*p9);
  printPunkt(*p10);

  delete p8;
  delete p9;
  delete p10;

  // Test 8
  // Dynamic creation of a point field
  cout << endl << "-- Test 8: Dynamic creation point field --" << endl;
  cout << "Expected:" << endl;
  cout << "Enter values for 3 points." << endl;
  cout << "The printed output should be correct." << endl;

  Punkt** pf1 = neuesPunktFeld(3);

  cout << endl << "Result:" << endl;

  for(int i = 0; i < 3; ++i)
  {
    printPunkt(*pf1[i]);
  }

  clearPunktFeld(pf1, 3);

  // Test 9
  // Max distance of points of an array
  cout << endl << "-- Test 9: Max distance of point array --" << endl;
  cout << "Expected:" << endl;
  cout << "Enter values for 3 points." << endl;
  cout << "The output should be the max distance and the two points." << endl;

  Punkt** pf3 = neuesPunktFeld(3);
  Punkt* p11 = new Punkt();
  Punkt* p12 = new Punkt();

  cout << endl << "Result:" << endl;

  cout << "Distance: " << maxAbstand(pf3, p11, p12, 3) << endl;
  printPunkt(*p11);
  printPunkt(*p12);

  clearPunktFeld(pf3, 3);
  delete p11;
  delete p12;

  // Test 10
  // Shortest path with all points used
  cout << endl << "-- Test 10: Shortest path --" << endl;
  cout << "Expected:" << endl;
  cout << "Enter values for 3 points." << endl;
  cout << "The output should be the shortest path and distance." << endl;

  Punkt** pf4 = neuesPunktFeld(3);
  Punkt** result = new Punkt*[3];
  for(int i=0; i<3; ++i)
  {
    result[i] = new Punkt();
  }

  cout << endl << "Result:" << endl;

  cout << "Distance: " << minWeg(pf4, result, 3) << endl;
  for(int i=0; i<3; ++i)
  {
    printPunkt(*result[i]);
  }

  clearPunktFeld(pf4, 3);
  clearPunktFeld(result, 3);

  return 0;
}
