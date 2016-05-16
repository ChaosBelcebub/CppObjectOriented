// Michael Kotzjan
// HFU, 16.05.2016

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>

using namespace std;

class Transform
{
  // Flag and file names
  static string flag;
  static string source;
  static string output;

  // Remove multiple spaces
  // Needed flag: -L
  static void trim();

  public:
  // Run transformation
  static void transform(int amount, char* parameter[]);
};

#endif
