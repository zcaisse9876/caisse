template <typename T>
forward_list<T>::forward_list() : head{nullptr}, tail{nullptr}, _size{0} {}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> vals) : head{nullptr}, tail{nullptr}, _size{0}
{
  if (!vals.size()) return;
  head = new forward_list<T>::ListNode(*vals.begin());
  tail = head;
  _size = vals.size();
  for (auto it = vals.begin() + 1; it != vals.end(); ++it)
  {
    tail->next = new forward_list<T>::ListNode(*it);
    tail = tail->next;
  }
}

template <typename T>
forward_list<T>::~forward_list()
{
  if (head)
    delete head;

  head = nullptr;
  tail = nullptr;
}

template <typename T>
void forward_list<T>::push_back(T val)
{
  if (!_size) return push_front(val);
  tail->next = new forward_list<T>::ListNode(val);
  tail = tail->next;
  _size += 1;
}

template <typename T>
void forward_list<T>::push_front(T val)
{
  auto nH = new forward_list<T>::ListNode(val);
  nH->next = head;
  head = nH;
  if (!_size++) tail = head;
}

template <typename T>
void forward_list<T>::pop_front()
{
  if (!_size) return;
  _size -= 1;
  auto nextHead = head->next;
  head->next = nullptr;
  delete head;
  head = nextHead;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin()
{
  return (_size ? head : nullptr);
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end()
{
  return (nullptr);
}

template <typename T>
int forward_list<T>::size()
{
  return _size;
}

template <typename T>
bool forward_list<T>::empty()
{
  return !_size;
}