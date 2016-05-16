// Michael Kotzjan
// HFU, 16.05.2016

#include "./Ex2Transform.h"
#include <iostream>
using namespace std;

// ____________________________________________________________________________
void Transform::transform(int amount, char* parameter[])
{
  if(amount < 3 || amount > 5)
  {
    throw "Not the right amount of parameter (Usage: ./Main <Flag> <Input> <Optional: Output>)";
  }

  switch (*parameter[1]) {
    case 'L':
      
      break;
    default:
      throw "Parameter does not exist.";
      break;
  }
}
