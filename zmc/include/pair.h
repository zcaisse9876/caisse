#ifndef ZMCPAIR_H_
#define ZMCPAIR_H_

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
  template<typename T3, typename T4>
  friend pair<T3, T4> make_pair(T3 first, T4 second);
};

#include "../define/pair.cpp"

#endif