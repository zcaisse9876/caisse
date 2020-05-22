#ifndef ZMCVECTOR_H_
#define ZMCVECTOR_H_

#include <initializer_list>
#include <stdexcept>

template <typename T>
class vector // Contiguous Memory Managed Data Array Container
{
private:
  const int allocationInc = 10; // Determines frequency of array scaling, buffer of empty blocks of memory. increase for better performance, decrease for better memory management.
  T *elem;                      // Pointer to item T.
  int allocated;                // Number of currently allocated blocks on free store for element T.
  int sz;                       // Number of element T currently stored in array.

  void allocate(); // Allocate more space on free store.

  void deallocate(); // reduce current amount of space allocated on free store.

public:
  vector(); // Default constructor, base 10 memory blocks reserved.

  vector(std::initializer_list<T> l); //  Initilizer list support.

  vector(const vector<T> &src); //Copy Constructor.

  vector(vector<T> &&src); // Move constructor.

  ~vector(); // Destructor, destroy pointer to array of T on free store.

  vector<T> &operator=(const vector<T> &src); //Copy Assignment Operator.

  vector<T> &operator=(vector<T> &&src); // Move assignment operator.

  bool operator==(const vector<T> &src); // Equality operator, element-wise comparison.

  void push_back(T x); // Inserts element T at end of vector, scales up if more memory is needed.

  T pop_back(); // Removes last element T in vector, scales down reserved memory.

  T &operator[](int i); // Subscript operator for access by index.

  int size(); // Returns the # of items held in the vector.

  int alloc(); // Returns the current # of contiguous blocks of memory allocated to hold type T.

  T *begin(); // Returns pointer to first element of array.

  T *end(); // Returns pointer to one passed the last element of the array.
};

#include "../define/vector.cpp"

#endif