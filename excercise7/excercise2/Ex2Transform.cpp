// Michael Kotzjan
// HFU, 16.05.2016

#include "./Ex2Transform.h"
#include <iostream>

using namespace std;

// Definition of variables
string Transform::input = "";
string Transform::output = "";

// ____________________________________________________________________________
void Transform::transform(int amount, char* parameter[])
{
  if(amount < 3 || amount > 5)
  {
    throw "Not the right amount of parameter\n(Usage: ./Ex2Main <Flag> <Input> <Optional: Output>)";
  }

  if(!fileExist(parameter[2]))
  {
    throw "Input file does not exist";
  }
  input = output = parameter[2];

  if(amount != 3)
  {
    output = parameter[3];
  }

  // Check if input file exist
  string p = parameter[1];
  if(p == "-L")
  {
    trim();
  } else {
    throw "Parameter does not exist.";
  }
}

// ____________________________________________________________________________
bool Transform::fileExist(const char* filename)
{
  ifstream file(filename, ifstream::in);
  return file.is_open();
}

// ____________________________________________________________________________
void Transform::trim()
{
// using std::ws <-------
  string line;
  stringstream result;
  ifstream input(Transform::input);
  if(input.is_open())
  {
    while (getline(input >> ws, line))
    {
      result << line << endl;
    }
    input.close();
  } else {
    throw "Can't open input file.";
  }

  ofstream output(Transform::output);
  if(output.is_open())
  {
    output << result.str();
    output.close();
  } else {
    throw "Can't open output file.";
  }
}
