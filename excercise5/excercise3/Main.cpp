// Michael Kotzjan
// HFU, 27.04.2016

#include <iostream>

using namespace std;

class Beobachter
{
  public:
    virtual void aktualisieren() = 0;
};

class Subjekt
{
  public:
    virtual void registrieren(Beobachter b) = 0;
    virtual void entfernen(Beobachter b) = 0;
    virtual void benachrichtigen(Beobachter b) = 0;
    virtual int zustandGeben() = 0;
};

class KonkretesSubjekt
{
  
};

class KonkreterBeobachter
{

};

int main()
{

}
