// Michael Kotzjan
// HFU, 16.05.2016

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Transform
{
  // Check if file exist
  static bool fileExist(const char* filename);

  // Remove multiple spaces
  // Needed flag: -L
  static void trim(istream& input, string& output, bool oneLine);

  // Add enumeration in front of each line
  // Needed flag: -Z
  static void enumerate(istream& input, string& output, bool oneLine);

  public:
  // Run transformation
  static void transform(int amount, char* parameter[]);
};

#endif
