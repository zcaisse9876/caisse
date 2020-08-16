/**
* Class Definitions
* zmc::forward_list<T>
*/

template <typename T>
forward_list<T>::forward_list() : head{nullptr}, tail{nullptr}, _size{0} {}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> vals) : head{nullptr}, tail{nullptr}, _size{0}
{
  if (!vals.size()) return;
  this->head = new forward_list<T>::ListNode(*vals.begin());
  this->tail = head;
  this->_size = vals.size();
  for (auto it = vals.begin() + 1; it != vals.end(); ++it)
  {
    this->tail->next = new forward_list<T>::ListNode(*it);
    this->tail = this->tail->next;
  }
}

template <typename T>
forward_list<T>::forward_list(const forward_list<T> &src): _size{src.size()}, tail{nullptr}, head{nullptr}
{
  for (const auto& n: src)
    this->push_back(n);
}

template <typename T>
forward_list<T>::forward_list(forward_list<T>&& src): _size{src.size()}
{
  this->head = src.head;
  this->tail = src.tail;
  src.head = nullptr;
  src.tail = nullptr;
  src._size = 0;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(const forward_list<T> &src)
{
  if (&src == this) return *this;
  if (this->head) delete this->head;
  this->head = nullptr;
  this->tail = nullptr;
  this->_size = src.size();
  for (const auto& n: src)
    this->push_back(n);

  return *this;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(forward_list<T> &&src)
{
  if (&src == this) return *this;
  if (this->head) delete this->head;
  this->_size = src.size();
  this->head = src.head;
  this->tail = src.tail;
  src.head = nullptr;
  src.tail = nullptr;
  src._size = 0;
  return *this;
}

template <typename T>
forward_list<T>::~forward_list()
{
  if (this->head)
    delete this->head;

  this->head = nullptr;
  this->tail = nullptr;
}

template <typename T>
void forward_list<T>::push_back(T val)
{
  if (!this->_size) return push_front(val);
  this->tail->next = new forward_list<T>::ListNode(val);
  this->tail = this->tail->next;
  this->_size += 1;
}

template <typename T>
void forward_list<T>::push_front(T val)
{
  auto nH = new forward_list<T>::ListNode(val);
  nH->next = this->head;
  this->head = nH;
  if (!this->_size++) this->tail = this->head;
}

template <typename T>
void forward_list<T>::pop_front()
{
  if (!this->_size) return;
  this->_size -= 1;
  auto nextHead = this->head->next;
  this->head->next = nullptr;
  delete this->head;
  this->head = nextHead;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin()
{
  return (this->_size ? this->head : nullptr);
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end()
{
  return (nullptr);
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::begin() const
{
  return (this->_size ? this->head : nullptr);
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::end() const
{
  return (nullptr);
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cbegin() const
{
  return (this->_size ? this->head : nullptr);
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cend() const
{
  return (nullptr);
}

template <typename T>
void forward_list<T>::swap(forward_list<T>& src)
{
  int tSize = src.size();
  forward_list<T>::ListNode* tHead = src.head;
  forward_list<T>::ListNode* tTail = src.tail;
  src._size = this->size();
  src.head = this->head;
  src.tail = this->tail;
  this->head = tHead;
  this->tail = tTail;
  this->_size = tSize;
  tHead = nullptr;
  tTail = nullptr;
}

template <typename T>
int forward_list<T>::size() const
{
  return this->_size;
}

template <typename T>
bool forward_list<T>::empty()
{
  return !this->_size;
}

template <typename T>
T& forward_list<T>::front()
{
  return this->head->value;
}

template <typename T>
void forward_list<T>::clear()
{
  if (!this->head) return;
  delete this->head;
  this->head = nullptr;
  this->tail = nullptr;
  this->_size = 0;
}

/**
* Nested Class Definitions
* zmc::forward_list<T>::base_iterator<PointerType>
*/

template <typename T>
template <bool flag, typename PointerType>
forward_list<T>::base_iterator<flag, PointerType>::base_iterator(PointerType e) : el(e) {}

template <typename T>
template <bool flag, typename PointerType>
typename std::conditional<flag, const T&, T&>::type forward_list<T>::base_iterator<flag, PointerType>::operator*() const
{
  return this->el->value;
}

template <typename T>
template <bool flag, typename PointerType>
typename forward_list<T>::template base_iterator<flag, PointerType> forward_list<T>::base_iterator<flag, PointerType>::operator++(int)
{
  forward_list<T>::base_iterator<flag, PointerType> orig(this->el);
  this->el = this->el->next;
  return orig;
}

template <typename T>
template <bool flag, typename PointerType>
typename forward_list<T>::template base_iterator<flag, PointerType> forward_list<T>::base_iterator<flag, PointerType>::operator++()
{
  this->el = this->el->next;
  return *this;
}

template <typename T>
template <bool flag, typename PointerType>
bool forward_list<T>::base_iterator<flag, PointerType>::operator==(const forward_list<T>::base_iterator<flag, PointerType> &b)
{
  return this->el == b.el;
}

template <typename T>
template <bool flag, typename PointerType>
bool forward_list<T>::base_iterator<flag, PointerType>::operator!=(const forward_list<T>::base_iterator<flag, PointerType> &b)
{
  return !(*this == b);
}

/**
* Nested Class Definitions
* zmc::forward_list<T>::ListNode
*/

template <typename T>
forward_list<T>::ListNode::ListNode(T v) : value{v}, next{nullptr} {}

template <typename T>
forward_list<T>::ListNode::~ListNode()
{
  std::cout << "Deleted: " << this->value << std::endl;
  if (this->next)
    delete this->next;
}