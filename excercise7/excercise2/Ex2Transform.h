// Michael Kotzjan
// HFU, 16.05.2016

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Transform
{
  // Check if file exist
  static bool fileExist(const char* filename);

  // Remove multiple spaces
  // Needed flag: -L
  static void trim(istream* input, string& output, bool oneLine);

  // Add enumeration in front of each line
  // Needed flag: -Z
  static void enumerate(istream* input, string& output, bool oneLine);

  // Transform a bitstring to unsigned integer
  static unsigned int toInt(const string& bs);

  // Split a string on whitespace and store the result in a vector
  static void split(string* input, vector<string>& result);

  // Transform 32 bit strings to integers
  // Needed flag: -I
  static void bitToInt(istream* input, string& output, bool oneLine);

  // Transform 64 bit strings to doubles
  // Needed flag: -D
  static void bitToDouble(istream* input, string& output, bool oneLine);

  // Transform 8 bit (1 byte) string to hex
  // Needed flag: -H
  static void bitToHex(istream* input, string& output, bool oneLine);

  public:
  // Run transformation
  static void transform(int amount, char* parameter[]);
};

#endif
