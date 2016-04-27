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
    virtual void aktualisieren(int i) = 0;
};

class KonkreterBeobachter : public Beobachter
{
    string name;

  public:
    KonkreterBeobachter(string s)
    {
      name = s;
    }

    void aktualisieren(int i)
    {
      cout << "Beobachter " << name << " aktualisiert: " << i << endl;
    }
};

class Subjekt
{
  public:
    virtual void registrieren(KonkreterBeobachter* b) = 0;
    virtual void entfernen(KonkreterBeobachter* b) = 0;
    virtual void benachrichtigen() = 0;
    virtual void zustandGeben(int i) = 0;
};

class KonkretesSubjekt : public Subjekt
{
    vector<KonkreterBeobachter*> beobachter;
    int zustand;

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

    void zustandGeben(int i)
    {
      zustand = i;
      benachrichtigen();
    }
};

int main()
{
  KonkretesSubjekt subjekt1;
  KonkretesSubjekt subjekt2;

  KonkreterBeobachter beobachter1("1");
  KonkreterBeobachter beobachter2("2");
  KonkreterBeobachter beobachter3("3");
  KonkreterBeobachter beobachter4("4");

  subjekt1.registrieren(&beobachter1);
  subjekt1.registrieren(&beobachter2);
  subjekt2.registrieren(&beobachter3);
  subjekt2.registrieren(&beobachter4);

  subjekt1.zustandGeben(42);
  subjekt2.zustandGeben(-12);

  subjekt1.entfernen(&beobachter1);
  subjekt2.entfernen(&beobachter4);

  subjekt1.zustandGeben(2);
  subjekt2.zustandGeben(7);
}
