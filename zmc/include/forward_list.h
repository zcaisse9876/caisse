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
    ListNode(T v);
    ~ListNode();
  }; // struct forward_list<T>::ListNode

  forward_list<T>::ListNode *head;
  forward_list<T>::ListNode *tail;
  int _size;

public:
  template <bool flag, typename PointerType>
  class base_iterator
  {
  private:
    PointerType el;

  public:
    base_iterator(PointerType e);
    typename std::conditional<flag, const T &, T &>::type operator*() const;
    forward_list<T>::base_iterator<flag, PointerType> operator++(int);
    forward_list<T>::base_iterator<flag, PointerType> operator++();
    bool operator==(const forward_list<T>::base_iterator<flag, PointerType> &b);
    bool operator!=(const forward_list<T>::base_iterator<flag, PointerType> &b);
  }; // class forward_list<T>::base_iterator<PointerType>

  typedef forward_list<T>::base_iterator<false, forward_list<T>::ListNode*> iterator;
  typedef forward_list<T>::base_iterator<true, const forward_list<T>::ListNode*> const_iterator;
 
  /**
  * Constructors and Operators
  */
  forward_list();
  explicit forward_list(std::initializer_list<T> vals);
  forward_list(const forward_list<T>& src); // Copy Constructor
  forward_list(forward_list<T>&& src); // Move Constructor
  forward_list<T>& operator=(const forward_list<T>& src); // Copy Assignment Operator
  forward_list<T>& operator=(forward_list<T>&& src); // Move Assignment Operator
  ~forward_list();


  /**
  * Modifiers
  */
  void push_front(T val);
  void push_back(T val);
  void pop_front();
  void clear();
  void swap(forward_list<T>& src);
  // void emplace_front();
  // void emplace_after();
  // void erase_after();
  // void insert_after();
  // void assign(int n, int val);
  // void assign(forward_list<T>::iterator& fromStart, forward_list<T>::iterator& fromEnd);
  // void assign(std::initializer_list<T> vals);

  /**
  * Operations
  */  
  // void splice_after(forward_list<T>::iterator& toWhere, forward_list<T>& fromWhat);
  // void splice_after(forward_list<T>::iterator& toWhere, forward_list<T>& fromWhat, forward_list<T>::iterator fromStart, forward_list<T>::iterator fromEnd = fromWhat.end());
  // void remove(T&);
  // void remove_if();
  // void unique();
  // void merge();
  // void sort();
  // void reverse();


  /**
  * Element Access
  */  
  T& front();

  /**
  * Capacity
  */
  bool empty();
  int size() const;

  /**
  * Iterators
  */
  forward_list<T>::iterator begin();
  forward_list<T>::iterator end();
  // forward_list<T>::iterator before_begin();
  // forward_list<T>::iterator before_end();
  forward_list<T>::const_iterator begin() const;
  forward_list<T>::const_iterator end() const;
  forward_list<T>::const_iterator cbegin() const;
  forward_list<T>::const_iterator cend() const;
  // forward_list<T>::const_iterator cbefore_begin() const;
  // forward_list<T>::const_iterator cbefore_end() const;
};

#include "../define/forward_list.cpp"

#endif