#ifndef FORWORDZMCLIST_H_
#define FORWORDZMCLIST_H_

#include <initializer_list>
#include <iostream>

template <typename T>
class forward_list
{
private:
  struct ListNode
  {
    T value;
    ListNode *next;
    ListNode(T v) : value{v}, next{nullptr} {}
    virtual ~ListNode() { std::cout << "Deleted: " << this->value << std::endl; if (next) delete next; }
  };

  forward_list<T>::ListNode *head;
  forward_list<T>::ListNode *tail;
  int _size;

public:
  class iterator
  {
  private:
    forward_list<T>::ListNode* el;
  
  public:
    iterator(forward_list<T>::ListNode* e): el(e) {}

    T& operator*()
    {
      if (this->el)
        return this->el->value;
      else
        throw std::out_of_range("Index out of Range!");
    }

    forward_list<T>::iterator operator++(int)
    {

      if (!this->el)
        throw std::out_of_range("Index out of Range!");

      forward_list<T>::iterator orig(this->el);
      this->el = el->next;
      return orig;
    }

    forward_list<T>::iterator operator++()
    {
      if (!this->el)
        throw std::out_of_range("Index out of Range!");

      this->el = el->next;
      return *this;
    }

    bool operator==(const forward_list<T>::iterator& b)
    {
      return this->el == b.el;
    }

    bool operator!=(const forward_list<T>::iterator& b)
    {
      return !(*this == b);
    }
  };

  forward_list();
  forward_list(std::initializer_list<T> vals);
  ~forward_list();
  void push_front(T val);
  void push_back(T val);
  void pop_front();
  int size();
  bool empty();
  forward_list<T>::iterator begin();
  forward_list<T>::iterator end();
};

#include "../define/forward_list.cpp"

#endif