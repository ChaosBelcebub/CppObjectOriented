// Michael Kotzjan
// HFU, 27.04.2016

#include <iostream>

using namespace std;

class Beobachter
{
  public:
    virtual void aktualisieren() = 0;
};

class KonkreterBeobachter : public Beobachter
{
  public:
    void aktualisieren()
    {
      
    }
};

class Subjekt
{
  public:
    virtual void registrieren(KonkreterBeobachter b) = 0;
    virtual void entfernen(KonkreterBeobachter b) = 0;
    virtual void benachrichtigen(KonkreterBeobachter b) = 0;
    virtual int zustandGeben() = 0;
};

class KonkretesSubjekt
{
  
};

int main()
{

}
