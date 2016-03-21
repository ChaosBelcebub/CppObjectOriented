// Michael Kotzjan
// HFU 21.03.2016

#include "./Excercise2Karteikarte.h"

// ____________________________________________________________________________
string Excercise2Karteikarte::getBuchtitel()
{
  return Buchtitel;
}

// ____________________________________________________________________________
string Excercise2Karteikarte::getAutor()
{
  return Autor;
}

// ____________________________________________________________________________
int Excercise2Karteikarte::getAnzahl()
{
  return Anzahl;
}

// ____________________________________________________________________________
void Excercise2Karteikarte::setBuchtitel(string bt)
{
  Buchtitel = bt;
}

// ____________________________________________________________________________
void Excercise2Karteikarte::setAutor(string a)
{
  Autor = a;
}

// ____________________________________________________________________________
void Excercise2Karteikarte::setAnzahl(int a)
{
  Anzahl = a;
}
