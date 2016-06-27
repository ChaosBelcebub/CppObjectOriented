// Michael Kotzjan
// HFU, 15.ß5.2016

#include <math.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class InvalidLog : public invalid_argument
{
  public:
    InvalidLog(const string& what) : invalid_argument(what)
    {
    }
};

class Index0bis5Error : public out_of_range
{
  public:
    Index0bis5Error() : out_of_range("Index außerhalb.")
  {
  }
};

void werfeAusnahme(int nr)
{
  switch (nr)
  {
    case 0:
      throw invalid_argument("0 ist nicht definiert");
      break;
    case 1:
      throw range_error("1 ist nicht im Range");
      break;
    case 2:
      throw bad_exception();
      break;
    default:
      cout << nr << " ist kein gültiger Wert." << endl;
  }
}

double myLog(double d)
{
  if (d > 0)
  {
    return log(d);
  } else if(d <= 0) {
    throw InvalidLog("log() ist für diesen Wert nicht definiert.");
  }
  return 0;
}

void index0bis5(int i)
{
  if(i < 0 || i > 5)
  {
    throw Index0bis5Error();
  }
}

int main()
{
  cout << endl << "a)" << endl << endl;
  for(int i = 0; i < 4; ++i)
  {
    try
    {
      werfeAusnahme(i);
    } catch(invalid_argument e) {
      cout << "invalid_argument:" << endl;
      cout << e.what() << endl;
    } catch(range_error e) {
      cout << "range_error:" << endl;
      cout << e.what() << endl;
    } catch(bad_exception e) {
      cout << "bad_exception:" << endl;
      cout << e.what() << endl;
    } catch(...) {
      cout << "Fehler! Andere Exception wurde geworfen!" << endl;
    }
  }

  cout << endl << "b)" << endl << endl;
  //
  // int result = 2/0;
  // Es wird eine Gleitkomma-Ausnahme geworfen, die ich nicht
  // Abfangen konnte. Das Programm wurde beendet.
  
  cout << endl << "c)" << endl << endl;
  // Es wird kein Fehler geworfen, dabei sollte laut der Doku
  // bei negativen werten ein domain error geworfen werden, und bei
  // 0 ein pole error.
  for(int i = -1; i < 4; ++i)
  {
    cout << "log(" << i << ") = ";
    try
    {
      cout << myLog(i) << endl;
    } catch(InvalidLog e) {
      cout << e.what() << endl;
    }
  }

  cout << endl << "d)" << endl << endl;

  for(int i = -1; i <= 6; ++i)
  {
    cout << "Index " << i << ": ";
    try
    {
      index0bis5(i);
      cout << "Klappt!" << endl;
    } catch (Index0bis5Error e) {
      cout << e.what() << endl;
    }
  }

  cout << endl << "e)" << endl << endl;
  try {
    vector<int> myvector;
    myvector.resize(myvector.max_size()+1);
  } catch (length_error& le) {
    cout << le.what() << endl;
  }
}
