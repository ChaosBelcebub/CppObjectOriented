// Michael Kotzjan
// HFU, 11.04.2016

#include <iostream>

using namespace std;

class Feldklasse
{
  int dim;
  double* feld;

  public:
  Feldklasse(int i)
  {
    dim = i;
    feld = new double[dim];
    for (int i = 0; i < dim; ++i)
    {
      feld[i] = 0.0;
    }
  }

  // Kopierkonstruktor
  Feldklasse(const Feldklasse &fk)
  {
    dim = fk.dim;
    feld = new double[dim];
    for (int i = 0; i < dim; ++i)
    {
      feld[i] = fk.feld[i];
    }
  }

  ~Feldklasse()
  {
    delete feld;
  }

  double getElement(int i)
  {
    if (i < 0 || i >= dim)
    {
      cout << "Index out of range." << endl;
      return 0;
    } else {
      return feld[i];
    }
  }

  void setElement(double elem, int i)
  {
    if (i < 0 || i >= dim)
    {
      cout << "Index out of range." << endl;
    } else {
      feld[i] = elem;
    }
  }
};

int main()
{
  // Erzeugen eines Objektes
  Feldklasse fk(5);
  
  cout << "Test 1" << endl;
  // Befüllen mit Indexprüfung
  for(int i = 0; i < 6; ++i)
  {
    fk.setElement(i, i);
  }

  cout << "Test 2" << endl;
  // Ausgeben mit Indexprüfung
  for(int i = 4; i >= -1; --i)
  {
    cout << fk.getElement(i) << endl;
  }

  cout << "Test 3" << endl;
  // Aufruf Kopierkonstruktor
  Feldklasse fk2 = fk;

  // Verändern von fk und Ausgabe von fk2
  for(int i = 0; i < 5; ++i)
  {
    fk.setElement(0.0, i);
    cout << fk2.getElement(i) << endl;
  }
}
