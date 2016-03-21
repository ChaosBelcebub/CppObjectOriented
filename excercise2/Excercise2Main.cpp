// Michael Kotzjan
// HFU 21.03.2015

#include "./Excercise2Karteikarte.h"

using namespace std;

int main(int argc, char* argv[])
{
  Excercise2Karteikarte k1;
  Excercise2Karteikarte k2;
  string s1 = "Titel1";
  string s2 = "Titel2";
  string s3 = "Author1";
  string s4 = "Author2";

  k1.setBuchtitel(s1);
  k1.setAutor(s3);
  k1.setAnzahl(3);

  k2.setBuchtitel(s2);
  k2.setAutor(s4);
  k1.setAnzahl(42);
}
