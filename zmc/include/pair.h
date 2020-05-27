#ifndef ZMCPAIR_H_
#define ZMCPAIR_H_

#include <initializer_list>

template <typename T1, typename T2>
class pair
{
public:
  T1 first;
  T2 second;
  pair(T1 first, T2 second);
  pair();
  bool operator==(pair<T1, T2> &src);
  bool operator!=(pair<T1, T2> &src);
  void swap(pair<T1, T2> &src);
  friend pair<T1, T2> make_pair(T1 first, T2 second);
};

#include "../define/pair.cpp"

#endif