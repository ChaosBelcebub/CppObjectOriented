// Michael Kotzjan
// HFU 31.03.2016

#include <iostream>
#include <string>

using namespace std;

class Karteikarte
{
  // Private
  string Buchtitel;
  string Autor;
  int Anzahl;

  public:
  // Getter
  string getBuchtitel()
  {
    return Buchtitel;
  }

  string getAutor()
  {
    return Autor;
  }

  int getAnzahl()
  {
    return Anzahl;
  }

  // Setter
  void setBuchtitel(string bt)
  {
    Buchtitel = bt;
  }

  void setAutor(string a)
  {
    Autor = a;
  }

  void setAnzahl(int a)
  {
    Anzahl = a;
  }

  // Print the informations
  // Used getters to demonstrate functionality
  void show()
  {
    cout << "Titel: " << getBuchtitel() << endl;
    cout << "Autor: " << getAutor() << endl;
    cout << "Anzahl: " << getAnzahl() << endl;
  }
};

int main(int argc, char* argv[])
{
  Karteikarte k1;
  Karteikarte k2;

  k1.setBuchtitel("Titel1");
  k1.setAutor("Autor1");
  k1.setAnzahl(3);

  k2.setBuchtitel("Titel2");
  k2.setAutor("Autor2");
  k2.setAnzahl(42);

  cout << "Karteikarte 1:" << endl;
  k1.show();

  cout << "Karteikarte 2:" << endl;
  k2.show();
}
