// Michael Kotzjan
// HFU, 16.05.2016

#include <iostream>
#include <fstream>
#include "./Ex2Transform.h"

using namespace std;

int main(int argc, char* argv[])
{
  cout << argc << endl;
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  cout << endl;

  try
  {
    Transform::transform(argc, argv);
  } catch(const char* e) {
    cout << e << endl;
  } catch(...) {
    cout << "ERROR" << endl;
  }

  ifstream ifs("test2.txt", ifstream::in);
  if (ifs.is_open())
    cout << "OPEN" << endl;
  else
    cout << "FAIL" << endl;
  char c = ifs.get();
  while (ifs.good())
  {
    cout << c;
    c = ifs.get();
  }
  ifs.close();

  return 0;
}
