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
    cout << "Konstrutor Testobjekt " << count << endl;
  }

  TestObjekt(TestObjekt& t)
  {
    ++ anz;
    count = anz;
    cout << "Kopierkonstruktor TestObjekt " << count << endl;
  }

  ~TestObjekt()
  {
    cout << "Destruktor " << count << endl;
  }
};
int TestObjekt::anz = 0;



int main(int argc, char *argv[])
{
  TestObjekt t1;
  TestObjekt t2;
  TestObjekt t3 = t1;
  TestObjekt t4 = t2;
}
