// Michael Kotzjan
// HFU, 16.05.2016

#include <iostream>
#include "./Ex2Transform.h"

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    Transform::transform(argc, argv);
  } catch(const char* e) {
    cout << e << endl;
  }
  return 0;
}
