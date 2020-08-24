#ifndef ZMCSTRING_H_
#define ZMCSTRING_H_

class string {                                                          // string implementation
private:
  char *elem;                                                           // Pointer to item T.
  int allocated;                                                        // Number of currently allocated blocks on free store for element T.
  int sz;                                                               // Number of element T currently stored in array.
  const char term = '\0';                                               // Null terminating character. Is this necessary in this implementation? Don't think so, may remove in future. Initial thoughts point to interfering with algorithms

public:
  string();                                                             // Default constructor
  string(const char* str);                                              // Construstor from const char *
  string(const char* a, const char* b);                                 // Iterator Constructor
  string(string& src);                                                  // Copy constructor
  string(string&& src);                                                 // Move constructor
  ~string();                                                            // Default destructor
  string operator=(string& src);                                        // Copy assignment operator
  string operator=(string&& src);                                       // Move assignment operator
  string operator+(const char* str);                                    // Overloaded addition for C string
  string operator+(const string& str);                                  // Overloaded addition for string
  void operator+=(const char* str);                                     // in-place addition with C-style string
  void operator+=(const string& str);                                   // in-place addition with string
  char &operator[](const int i);                                        // Subscript operator for element access
  bool operator<(const string& src);                                    // LT operator
  bool operator>=(const string& src);                                   // GTEQ operator
  bool operator>(const string& src);                                    // GT operator
  bool operator<=(const string& src);                                   // LTEQ operator
  bool operator==(const string& src);                                   // EQ operator
  bool operator!=(const string& src);                                   // NEQ operator
  int length();                                                         // length of string
  int alloc();                                                          // Returns size allocated, for testing
  char* begin();                                                        // pointer to beginning of array
  char* end();                                                          // pointer to one passed end of array
  void replace(int i, int len, const string &text);
  string substr(int begin, int end);
  friend std::ostream &operator<<(std::ostream &os, const string &src); // Declaring overriden << operator as friend for private access
};

#include "../define/string.cpp"

#endif