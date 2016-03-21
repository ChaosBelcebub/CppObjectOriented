// Michael Kotzjan
// HFU 21.03.2016

#ifndef EXCERCISE2_EXCERCISE2KARTEIKARTE_H
#define EXCERCISE2_EXCERCISE2KARTEIKARTE_H 

#include <string>

using namespace std;

class Excercise2Karteikarte
{
  string Buchtitel;
  string Autor;
  int Anzahl;

  public:
  // Getter
  string getBuchtitel();
  string getAutor();
  int getAnzahl();

  // Setter
  void setBuchtitel(string bt);
  void setAutor(string a);
  void setAnzahl(int a);
};

#endif
