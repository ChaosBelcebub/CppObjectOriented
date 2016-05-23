// Michael Kotzjan
// HFU, 16.05.2016

#include "./Ex2Transform.h"
#include <iostream>

using namespace std;

// ____________________________________________________________________________
void Transform::transform(int amount, char* parameter[])
{
  istream* inputStream;
  ifstream *input;
  string result;
  string output;
  bool consoleInput = false;
  if(amount < 2 || amount > 4)
  {
    throw "Not the right amount of parameter\n(Usage: ./Ex2Main <Flag> <Optional: Input> <Optional: Output>)";
  }

  string p = parameter[1];
  if(!(p == "-L" || p == "-Z"))
  {
    throw "Parameter does not exist.";
  }

  if(amount >= 3)
  {
    if(!fileExist(parameter[2]))
    {
      throw "Input file does not exist";
    } else {
      input = new ifstream(parameter[2]);
      inputStream = input;
      consoleInput = false;
    }
    
    if(amount != 3)
    {
      output = parameter[3];
    } else {
      output = parameter[2];
    }
  } else {
    inputStream = &cin;
    consoleInput = true;
    cout << "Enter text:" << endl;
  }

  // Run operation
  if(p == "-L")
  {
    trim(*inputStream, result, consoleInput);
  } else if(p == "-Z") {
    enumerate(*inputStream, result, consoleInput);
  }

  // Print or save result in file
  if(consoleInput)
  {
    cout << "Result:" << endl;
    cout << result;
  } else {
    
    ofstream os(output);
    if(os.is_open())
    {
      os << result;
      os.close();
    } else {
      throw "Can't open output file.";
    }
  }
}

// ____________________________________________________________________________
bool Transform::fileExist(const char* filename)
{
  ifstream file(filename, ifstream::in);
  return file.is_open();
}

// ____________________________________________________________________________
void Transform::trim(istream& input, string& output, bool oneLine)
{
  bool isWhitespace;
  stringstream ss;
  string line;

  while (getline(input >> ws, line))
  {
    isWhitespace = false;
    for(unsigned int i = 0; i < line.length(); ++i)
    {
      if(!isWhitespace && line[i] == ' ')
      {
        ss << line[i];
        isWhitespace = true;
      } else if(isWhitespace && line[i] == ' ') {
        continue;
      } else {
        ss << line[i];
        isWhitespace = false;
      }
    }
    ss << endl;
    if(oneLine) break;
  }
  output = ss.str();
}

// ____________________________________________________________________________
void Transform::enumerate(istream& input, string& output, bool oneLine)
{
  stringstream tmp;
  stringstream ss;
  string line;
  int count = 0;
  int number = 1;
  while (getline(input, line))
  {
    tmp << line << endl;
    ++count;
  }

  // Get length of integer
  int size = 0;
  do {
    count /= 10;
    ++size;
  } while(count);

  while (getline(tmp, line))
  {
    ss << setw(size) << left << number << "| " << line << endl;
    ++number;
    if(oneLine) break;
  }
  output = ss.str();
}
