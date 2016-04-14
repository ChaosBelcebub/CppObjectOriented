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
  Feldklasse fk(5);
  for(int i = 0; i < 6; ++i)
  {
    fk.setElement(i, i);
  }
  for(int i = 4; i >= -1; --i)
  {
    cout << fk.getElement(i) << endl;
  }

  Feldklasse fk2 = fk;
  for(int i = 0; i < 5; ++i)
  {
    cout << fk2.getElement(i) << endl;
  }
}
