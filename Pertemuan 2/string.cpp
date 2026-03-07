#include <iostream>      // for std::cout and other I/O
#include <string.h>      // for string handling functions (not strictly needed here)

using namespace std;     // avoid prefixing std:: everywhere

int main() {
  // initialize a std::string with a literal
  string str = "HelloWorld!";

  // print the length of the string to standard output
  cout << str.size() << endl;

  // indicate successful program termination
  return 0;
}