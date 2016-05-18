// Michael Kotzjan
// HFU, 16.05.2016

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Transform
{
  // File names
  static string input;
  static string output;

  // Check if file exist
  static bool fileExist(const char* filename);

  // Remove multiple spaces
  // Needed flag: -L
  static void trim();

  public:
  // Run transformation
  static void transform(int amount, char* parameter[]);
};

#endif
