// Michael Kotzjan
// HFU, 06.05.2016

#include <iostream>

using namespace std;

class EmptyObjException
{
  public:
    const char * msg;
    EmptyObjException()
    {
      msg = "Objekt ist leer";
    }
};
