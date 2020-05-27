template <typename T1, typename T2>
pair<T1, T2>::pair(T1 first, T2 second) : first{first}, second{second}
{
}

template <typename T1, typename T2>
pair<T1, T2>::pair()
{
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator==(pair<T1, T2> &src)
{
  return this->first == src.first && this->second == src.second;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator!=(pair<T1, T2> &src)
{
  return !(this->first == src.first && this->second == src.second);
}

template <typename T1, typename T2>
void pair<T1, T2>::swap(pair<T1, T2> &src) 
{
  T1 a = std::move(src.first);
  T2 b = std::move(src.second);
  src.first = std::move(this->first);
  src.second = std::move(this->second);
  this->first = std::move(a);
  this->second = std::move(b);
}

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 first, T2 second) {
  return {first, second};
}
