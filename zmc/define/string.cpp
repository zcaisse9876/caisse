string::string() : elem{new char[1]}, allocated{1}, sz{0}
{
  elem[0] = term;
} // Default constructor

string::string(const char *str)
{
  const int length = strlen(str);
  this->elem = new char[length + 1]; // Length + 1 to accomodate null terminator
  this->allocated = length + 1;      // Record allocated size
  this->sz = length;                 // Length of string
  strcpy(this->elem, str);           // Copy source string into destination
} // Construstor from const char *

string::string(const char *a, const char *b)
{

} // Iterator Constructor

string::string(string &src)
{
  int length = strlen(src.elem);
  this->elem = new char[length + 1];
  this->allocated = length + 1;
  this->sz = length;
  strcpy(this->elem, src.elem);
} // Copy constructor

string::string(string &&src)
{
  this->elem = src.elem;
  src.elem = nullptr;
  this->allocated = src.sz + 1;
  this->sz = src.sz;
} // Move constructor

string::~string()
{
  if (this->elem)
    delete[] this->elem;

  this->elem = nullptr;
} // Default destructor

string string::operator=(string &src)
{
  if (&src == this)
    return *this;

  if (this->elem)
    delete[] this->elem;

  int length = strlen(src.elem);
  this->elem = new char[length + 1];
  this->allocated = length + 1;
  this->sz = length;
  strcpy(this->elem, src.elem);
  return *this;
} // Copy assignment operator

string string::operator=(string &&src)
{
  if (&src == this)
    return *this;

  if (this->elem)
    delete[] this->elem;

  this->elem = src.elem;
  src.elem = nullptr;
  this->allocated = src.sz + 1;
  this->sz = src.sz;
  return *this;
} // Move assignment operator

string string::operator+(const char *str)
{
  const int nlen = strlen(str) + this->sz;
  int i = 0;
  char *concat = new char[nlen + 1];
  const char *p1 = &this->elem[0], *p2 = &str[0];
  while (*p1 || *p2)
  {
    if (*p1) 
      concat[i++] = *(p1++);
    else
      concat[i++] = *(p2++);
  }
  concat[nlen] = term;
  return string(concat);
} // Overloaded addition for C string

string string::operator+(const string &str)
{
  return *this + str.elem;
} // Overloaded addition for string

void string::operator+=(const char *str)
{
  const int nlen = strlen(str) + this->sz;
  int i = 0;
  char *concat = new char[nlen + 1];
  const char *p1 = &this->elem[0], *p2 = &str[0];
  while (*p1 || *p2)
  {
    if (*p1)
      concat[i++] = *(p1++);
    else
      concat[i++] = *(p2++);
  }
  concat[nlen] = term;

  if (this->elem)
    delete[] this->elem;

  this->elem = concat;
  this->sz = nlen;
  this->allocated = nlen + 1;
}

void string::operator+=(const string &str)
{
  this->operator+=(str.elem);
}

std::ostream &operator<<(std::ostream &os, const string &src)
{
  for (int i = 0; i < src.sz; ++i)
    os << src.elem[i];
  return os;
} // Overloaded Ostream for standard out

char &string::operator[](const int i)
{
  if (i < 0 || i > sz - 1)
    throw std::out_of_range("Index accessor out of range!");

  return elem[i];
} // Subscript operator for element access

bool string::operator<(const string &src)
{
  return strcmp(this->elem, src.elem) < 0;
}

bool string::operator>=(const string &src)
{
  int i = strcmp(this->elem, src.elem);
  return i == 0 || i > 0;
}

bool string::operator>(const string &src)
{
  return strcmp(this->elem, src.elem) > 0;
}

bool string::operator<=(const string &src)
{
  const int i = strcmp(this->elem, src.elem);
  return i == 0 || i < 0;
}

bool string::operator==(const string &src)
{
  return strcmp(this->elem, src.elem) == 0;
}

bool string::operator!=(const string &src)
{
  return strcmp(this->elem, src.elem) != 0;
}

int string::length()
{
  return this->sz;
} // length of string

int string::alloc()
{
  return this->allocated;
}

char *string::begin()
{
  return this->sz ? &this->elem[0] : nullptr;
} // pointer to beginning of array

char *string::end()
{
  return this->sz ? &this->elem[0] + this->sz : nullptr;
} // pointer to one passed end of array