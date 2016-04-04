// Michael Kotzjan
// HFU, 01.04.2016

#include <iostream>

using namespace std;

class TestObjekt
{
  static int anz;
  int count;
  
  public:
  TestObjekt()
  {
    ++anz;
    count = anz;
    cout << "Konstrutor (" << count << ")" << endl;
  }

  TestObjekt(TestObjekt& t)
  {
    ++ anz;
    count = anz;
    cout << "Kopierkonstruktor (" << t.getCount() << " -> " << count << ")" << endl;
  }

  ~TestObjekt()
  {
    cout << "Destruktor (" << count << ")" << endl;
  }

  int getCount()
  {
    return count;
  }
};
int TestObjekt::anz = 0;

// Tests
// Global variable
TestObjekt t1;

// Global function
void testFunk(TestObjekt to)
{
}

void testFunk2(TestObjekt& to)
{
}

TestObjekt testFunk()
{
  TestObjekt t;
  return t;
}

int main(int argc, char *argv[])
{
  // Local
  cout << "b)" << endl;
  TestObjekt t2;
  cout << endl;

  cout << "c)" << endl;
  testFunk(t1);
  testFunk(t2);
  cout << endl;

  cout << "d)" << endl;
  testFunk2(t1);
  cout << endl;

  cout << "e)" << endl;
  TestObjekt t3 = testFunk();
  testFunk();
  cout << endl;
}
