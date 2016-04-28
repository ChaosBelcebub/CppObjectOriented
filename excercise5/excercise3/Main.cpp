// Michael Kotzjan
// HFU, 27.04.2016
//
// Used sources:
// http://www.codeproject.com/Articles/328365/Understanding-and-Implementing-Observer-Pattern

#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Beobachter
{
  public:
    virtual void aktualisieren(double i) = 0;
};

class KonkreterBeobachter : public Beobachter
{
    string name;

  public:
    KonkreterBeobachter(string s)
    {
      name = s;
    }

    void aktualisieren(double d)
    {
      cout << "Beobachter " << name << " aktualisiert: " << d << endl;
    }
};

class Subjekt
{
  public:
    virtual void registrieren(KonkreterBeobachter* b) = 0;
    virtual void entfernen(KonkreterBeobachter* b) = 0;
    virtual void benachrichtigen() = 0;
    virtual void zustandGeben(double d) = 0;
};

class KonkretesSubjekt : public Subjekt
{
    vector<KonkreterBeobachter*> beobachter;
    double zustand;

  public:
    void registrieren(KonkreterBeobachter* b)
    {
      beobachter.push_back(b);
    }

    void entfernen(KonkreterBeobachter* b)
    {
      beobachter.erase(std::remove(beobachter.begin(), beobachter.end(), b), beobachter.end());
    }

    void benachrichtigen()
    {
      for (auto& b : beobachter)
      {
        b->aktualisieren(zustand);
      }
    }

    void zustandGeben(double d)
    {
      zustand = d;
      benachrichtigen();
    }
};

int main()
{
  double wert1 = 52.3;
  double wert2 = 28.7;

  KonkretesSubjekt aktie1;
  KonkretesSubjekt aktie2;

  KonkreterBeobachter beobachter1("Markus");
  KonkreterBeobachter beobachter2("Peter");
  KonkreterBeobachter beobachter3("Dominik");
  KonkreterBeobachter beobachter4("Paula");

  aktie1.registrieren(&beobachter1);
  aktie1.registrieren(&beobachter2);
  aktie2.registrieren(&beobachter3);
  aktie2.registrieren(&beobachter4);

  cout << endl << "### Test 1 ###" << endl;
  cout << "Increase values:" << endl;
  for (int i = 0; i < 3; ++i)
  {
    wert1 += 5.7;
    wert2 += 8.4;
    aktie1.zustandGeben(wert1);
    aktie2.zustandGeben(wert2);
  }

  cout << endl << "### Test 2 ###" << endl;
  cout << "Unregister 2 observers and increase values:" << endl;
  aktie1.entfernen(&beobachter2);
  aktie2.entfernen(&beobachter3);
  for (int i = 0; i < 3; ++i)
  {
    wert1 += 6.8;
    wert2 += 12.2;
    aktie1.zustandGeben(wert1);
    aktie2.zustandGeben(wert2);
  }

  cout << endl << "### Test 3 ###" << endl;
  cout << "Decrease values:" << endl;
}
