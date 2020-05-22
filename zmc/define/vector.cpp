template <typename T>
void vector<T>::allocate() // Allocate more space on free store.
{
  this->allocated += this->allocationInc;
  T *temp = new T[this->allocated];
  for (int i = 0; i < this->sz; ++i)
    temp[i] = this->elem[i];
  delete[] this->elem;
  this->elem = temp;
}

template <typename T>
void vector<T>::deallocate() // reduce current amount of space allocated on free store.
{
  this->allocated -= this->allocationInc;
  T *temp = new T[this->allocated];
  for (int i = 0; i < this->sz; ++i)
    temp[i] = this->elem[i];
  delete[] this->elem;
  this->elem = temp;
}

template <typename T>
vector<T>::vector() : elem{new T[allocationInc]}, allocated{allocationInc}, sz{0} // Default constructor, base 10 memory blocks reserved.
{
}

template <typename T>
vector<T>::vector(std::initializer_list<T> l) : elem{new T[l.size()]}, allocated{static_cast<int>(l.size())}, sz{static_cast<int>(l.size())} //  Initilizer list support.
{
  auto it = l.begin();
  for (int i = 0; i < l.size(); ++i)
    this->elem[i] = *(it++);
}

template <typename T>
vector<T>::vector(const vector<T> &src) : elem{new T[src.allocated]}, allocated{src.allocated}, sz{src.sz} //Copy Constructor.
{
  for (int i = 0; i < src.sz; ++i)
    this->elem[i] = src.elem[i];
}

template <typename T>
vector<T>::vector(vector<T> &&src) : elem(src.elem), allocated{src.allocated}, sz{src.sz} // Move constructor.
{
  src.elem = nullptr;
}

template <typename T>
vector<T>::~vector() // Destructor, destroy pointer to array of T on free store.
{
  if (this->elem)
  {
    delete[] this->elem;
    this->elem = nullptr;
  }
}

template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &src) //Copy Assignment Operator.
{
  if (&src == this)
    return *this;

  if (this->elem)
    delete[] this->elem;

  this->elem = new T[src.allocated];
  this->sz = src.sz;
  this->allocated = src.allocated;
  for (int i = 0; i < src.sz; ++i)
    this->elem[i] = src.elem[i];

  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&src) // Move assignment operator.
{
  if (&src == this)
    return *this;

  if (this->elem)
    delete[] this->elem;

  this->elem = src.elem;
  this->sz = src.sz;
  this->allocated = src.allocated;
  src.elem = nullptr;

  return *this;
}

template <typename T>
bool vector<T>::operator==(const vector<T> &src) // Equality operator, element-wise comparison.
{
  if (src.sz != this->sz)
    return false;

  for (int i = 0; i < src.sz; ++i)
  {
    if (this->elem[i] != src.elem[i])
      return false;
  }

  return true;
}

template <typename T>
void vector<T>::push_back(T x) // Inserts element T at end of vector, scales up if more memory is needed.
{
  if (this->sz == this->allocated)
    this->allocate();
  this->elem[this->sz] = x;
  this->sz++;
}

template <typename T>
T vector<T>::pop_back() // Removes last element T in vector, scales down reserved memory.
{
  if (this->sz == 0)
    return 0;

  if (this->sz <= this->allocated - (this->allocationInc * 2))
    this->deallocate();

  this->sz--;
  return this->elem[this->sz];
}

template <typename T>
T &vector<T>::operator[](int i) // Subscript operator for access by index.
{
  if (i >= this->sz || i < 0)
    throw std::out_of_range("Index out of Range!");
  return this->elem[i];
}

template <typename T>
int vector<T>::size() // Returns the # of items held in the vector.
{
  return this->sz;
}

template <typename T>
int vector<T>::alloc() // Returns the current # of contiguous blocks of memory allocated to hold type T.
{
  return this->allocated;
}

template <typename T>
T *vector<T>::begin() // Returns pointer to first element of array.
{
  return this->sz ? &this->elem[0] : nullptr;
}

template <typename T>
T *vector<T>::end() // Returns pointer to one passed the last element of the array.
{
  return this->sz ? &this->elem[0] + this->sz : nullptr;
}