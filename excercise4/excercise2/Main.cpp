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

  // ###############
  // New:
  // Operator =
  // ###############
  const Feldklasse& operator=(const Feldklasse& fk)
  {
    if (dim != fk.dim)
    {
      delete feld;
      dim = fk.dim;
      feld = new double[dim];
    }
    for (int i = 0; i < dim; ++i)
    {
      feld[i] = fk.feld[i];
    }
    return fk;
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
  // Test
  cout << "Teste Implementierung von Zuweisungsoperator:" << endl;
  Feldklasse fk(5);
  for (int i = 0; i < 5; ++i)
  {
    fk.setElement(i * 1.5, i);
  }
  cout << "Ausgabe des Testfeldes:" << endl;
  for (int i = 0; i < 5; ++i)
  {
    cout << i << ": " << fk.getElement(i) << endl;
  }
  cout << "Zuweisung an 3 Felder, größer, kleiner und gleich." << endl;
  Feldklasse fk1(5);
  Feldklasse fk2(2);
  Feldklasse fk3(8);
  fk1 = fk;
  fk2 = fk;
  fk3 = fk;
  cout << "Veränderung des Testfeldes." << endl;
  for (int i = 0; i < 5; ++i)
  {
    fk.setElement(0.0, i);
  }
  cout << "Ausgabe der Felder:" << endl;
  cout << "Testfeld:" << endl;
  for (int i = 0; i < 5; ++i)
  {
    cout << i << ": " << fk.getElement(i) << endl;
  }
  cout << "Feld gleicher Größe:" << endl;
  for (int i = 0; i < 5; ++i)
  {
    cout << i << ": " << fk1.getElement(i) << endl;
  }
  cout << "Kleineres Feld:" << endl;
  for (int i = 0; i < 5; ++i)
  {
    cout << i << ": " << fk2.getElement(i) << endl;
  }
  cout << "Größeres Feld:" << endl;
  for (int i = 0; i < 5; ++i)
  {
    cout << i << ": " << fk3.getElement(i) << endl;
  }
}
