/**
* Class Definitions
* zmc::forward_list<T>
*/

template <typename T>
forward_list<T>::forward_list() : tail{nullptr} {}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> src) : tail{nullptr}
{
  if (!src.size()) return;
  for (const auto& n: src)
    this->push_back(n);
}

template <typename T>
forward_list<T>::forward_list(const forward_list<T> &src) : tail{nullptr}
{
  if (src.empty()) return;
  for (const auto& n: src)
    this->push_back(n);
}

template <typename T>
forward_list<T>::forward_list(forward_list<T>&& src)
{
  this->head = src.head;
  this->tail = src.tail;
  src.head = nullptr;
  src.tail = nullptr;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(const forward_list<T> &src)
{
  if (&src == this) return *this;
  if (this->head) delete this->head;
  this->head = new forward_list<T>::ListNode();
  this->tail = nullptr;
  for (const auto& n: src)
    this->push_back(n);

  return *this;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(forward_list<T> &&src)
{
  if (&src == this) return *this;
  if (this->head) delete this->head;
  this->head = src.head;
  this->tail = src.tail;
  src.head = nullptr;
  src.tail = nullptr;
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
  if (this->empty()) return push_front(val);
  this->tail->next = new forward_list<T>::ListNode(val);
  this->tail = this->tail->next;
}

template <typename T>
void forward_list<T>::push_front(T val)
{
  this->head->next = new forward_list<T>::ListNode(val, this->head->next);
  if (!this->head->next->next) this->tail = this->head->next;
}

template <typename T>
void forward_list<T>::pop_front()
{
  if (this->empty()) return;
  auto toDelete = this->head->next;
  this->head->next = toDelete->next;
  toDelete->next = nullptr;
  delete toDelete;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin()
{
  return {this->head->next};
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end()
{
  return {nullptr};
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::before_begin()
{
  return {this->head};
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::before_end()
{
  return {this->tail};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::begin() const
{
  return {this->head->next};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::end() const
{
  return {nullptr};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cbegin() const
{
  return {this->head->next};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cend() const
{
  return {nullptr};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cbefore_begin() const
{
  return {this->head};
}

template <typename T>
typename forward_list<T>::const_iterator forward_list<T>::cbefore_end() const
{
  return {this->tail};
}

template <typename T>
void forward_list<T>::swap(forward_list<T>& src)
{
  forward_list<T>::ListNode* tHead = src.head;
  forward_list<T>::ListNode* tTail = src.tail;
  src.head = this->head;
  src.tail = this->tail;
  this->head = tHead;
  this->tail = tTail;
  tHead = nullptr;
  tTail = nullptr;
}

template <typename T>
bool forward_list<T>::empty()
{
  return this->head->next ? false : true;
}

template <typename T>
T& forward_list<T>::front()
{
  return this->head->next->value;
}

template <typename T>
void forward_list<T>::clear()
{
  if (this->empty()) return;
  delete this->head->next;
  this->head->next = nullptr;
  this->tail = nullptr;
}

template <typename T>
void forward_list<T>::splice_after(forward_list<T>::iterator toWhere, forward_list<T> &fromWhat)
{
  auto tempNode = toWhere.el->next;
  auto FWTail = fromWhat.head;
  while (FWTail->next) ++FWTail;
  toWhere.el->next = fromWhat.head->next;
  FWTail->next = tempNode;
  tempNode = nullptr;
  fromWhat.head->next = nullptr;
  fromWhat.tail = nullptr;
}

template <typename T>
void forward_list<T>::splice_after(forward_list<T>::iterator toWhere, forward_list<T> &fromWhat, forward_list<T>::iterator fromStart, forward_list<T>::iterator fromEnd)
{
  auto sectionBegin = fromStart.el->next;
  auto sectionEnd = fromStart.el;
  while(sectionEnd->next) { // O(n) must find node preceding fromEnd
    if (sectionEnd->next == fromEnd.el) break; // Reached node before target end node, success
    if (sectionEnd->next == toWhere.el) return; // Found location to splice nodes into within the splice from range, failure
    if (!sectionEnd->next) return; // Reached tail without finding end node, do nothing
    sectionEnd = sectionEnd->next;
  }

  fromStart.el->next = fromEnd.el; // Patch out section found above
  sectionEnd->next = toWhere.el->next; // end of section points to next location in target list;
  toWhere.el->next = sectionBegin; // locationin target list points to beginning of section;
  sectionBegin = nullptr;
  sectionEnd = nullptr;
}

template <typename T>
void forward_list<T>::splice_after(forward_list<T>::iterator toWhere, forward_list<T> &fromWhat, forward_list<T>::iterator location)
{
  auto tempNode = location.el->next; // Get node following node to be moved
  location.el->next = tempNode->next; // Patch out the node from the original list
  tempNode->next = toWhere.el->next; // Point node to place after location to be moved
  toWhere.el->next = tempNode; // Point location to be moved to node that got moved
  tempNode = nullptr;
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
forward_list<T>::ListNode::ListNode() : next{nullptr} {}

template <typename T>
forward_list<T>::ListNode::ListNode(T v, forward_list<T>::ListNode* n) : value{v}, next{n} {} 

template <typename T>
forward_list<T>::ListNode::~ListNode()
{
  std::cout << "Deleted: " << this->value << std::endl;
  if (this->next)
    delete this->next;
}