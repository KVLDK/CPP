/*
queue.t
Kara Vahldieck
11/28/16
version 1.0

Contains definitions and implementations for queue ADT
*/



#ifndef _QUEUE_T
#define _QUEUE_T

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
namespace fsu
{

//class definition

template < typename T >
class Queue
{
public:

  Queue(); //default constructor
  ~Queue(); //destructor
  Queue(const Queue&); //copy constructor
  Queue& operator=(const Queue&); //assignment operator


  void Push(const T& t);
  T Pop();
  T& Front();
  const T& Front() const;
  size_t Size() const;
  bool Empty() const;
  void Clear();
  void Display(std::ostream& os, char ofc = '\0') const;

  void Append(const Queue& q);
  void Release();
  void Dump(std::ostream& os, char ofc = '\0') const;
  size_t Capacity() const;

private:

  class Link
  {
    Link (const T& t) : element_(t), nextLink_(nullptr) {}
    T element_;
    Link * nextLink_;
    friend class Queue<T>;
  };

  Link * firstLink_;
  Link * lastLink_;

};

template < typename T >
std::ostream& operator<<(std::ostream& os, const Queue<T>& q)
{
  q.Display(os, '\0');
  return os;
}

//class function template definitions

template < typename T >
Queue<T>::Queue(): firstLink_(nullptr), lastLink_(nullptr)
{}

template < typename T >
Queue<T>::~Queue()
{ Release(); }

template < typename T >
Queue<T>::Queue(const Queue& q): firstLink_(nullptr), lastLink_(nullptr)
{
  if (q.Empty())
  {
    std::cout << "Cannot copy, queue is empty\n";
    return;
  }
  
    Append(q);
}

template < typename T >
Queue<T>& Queue<T>::operator=(const Queue& q)
{
  if (this != &q)
  {
    if (q.Empty())
    {
      std::cout << "Cannot assign, queue is empty\n";
      exit(EXIT_FAILURE);
    }

    Append(q);
  }
  return *this;
}

template < typename T >
void Queue<T>::Push(const T& t)
{
  Queue<T>::Link * newLink = new Link (t);

  if (Empty())
    firstLink_ = lastLink_ = newLink; //creates a new queue

 else
  {
    lastLink_ -> nextLink_ = newLink; //point new link to location of last link position
    lastLink_ = newLink; //new link is the new last link (at the end of the queue)
  }
}

template < typename T >
T Queue<T>::Pop()
{
  if (Empty())
  {
    std::cout << "Error: Queue is empty.\n";
    exit(EXIT_FAILURE);
  }

  else
  {
    Queue<T>::Link * newLink = firstLink_;

    if (firstLink_ == lastLink_)
      firstLink_ = lastLink_ = 0; //if only 1 element in the queue

    else
      firstLink_ = firstLink_ -> nextLink_; //first link ptr now points to next element

    T value = newLink -> element_; //value to return is element newLink points to
    delete newLink;
    return value;

  }
}

template < typename T >
T& Queue<T>::Front()
{
  if (Empty())
  {
    std::cout << "Error: Queue is empty.\n";
    exit(EXIT_FAILURE);
  }

  else
  {
    return firstLink_ -> element_;
  }
}

template < typename T >
const T& Queue<T>::Front() const
{
  if (Empty())
  {
    std::cout << "Error: Queue is empty.\n";
    exit(EXIT_FAILURE);
  }

  else
  {
    return firstLink_ -> element_;
  }
}

template < typename T >
size_t Queue<T>::Size() const
{
  size_t size = 0;

  if (Empty())
    return size;

  Queue<T>::Link * tempLink = firstLink_; //temp link to iterate thru queue

  while (tempLink != 0)
  {
    tempLink = tempLink -> nextLink_; //move to next link until hit 0
    ++size;
  }
  delete tempLink;
  return size;
}

template < typename T >
bool Queue<T>::Empty() const
{
  if (firstLink_ == 0)
    return true;

  return false;
}

template < typename T >
void Queue<T>::Clear()
{ Release(); }

template < typename T >
void Queue<T>::Display(std::ostream&os, char ofc) const
{
  if (Empty())
  {
    std::cout << "Queue is empty, nothing to display";
    return;
  }

  Queue<T>::Link * tempLink = firstLink_;

  if (ofc != '\0')
  {
    while (tempLink != 0)
    {
      os << ofc << tempLink -> element_;
      tempLink = tempLink -> nextLink_;
    }
    delete tempLink;
    return;
  }

 if (ofc == '\0')
  {
    while (tempLink != 0)
    {
      os << tempLink -> element_;
      tempLink = tempLink -> nextLink_;
    }
    return;
  }
}

template < typename T >
void Queue<T>::Append(const Queue& q)
{
  Queue<T>::Link * tempPtr = q.firstLink_; //to hold values in q's queue
  T value = tempPtr -> element_; //1st value in q's queue
  Queue<T>::Link * newLink = new Link(value); //new obj's 1st link created
  lastLink_ = firstLink_ = newLink; //new queue has only 1 item now
  tempPtr = tempPtr -> nextLink_; //now points to q's next link

  while (tempPtr != 0) //0 indicates end of q's queue
  {
    T value = tempPtr -> element_; //next value in q's queue
    Queue<T>::Link * newLink = new Link(value); //new link in new obj
    lastLink_ -> nextLink_ = newLink;
    lastLink_ = newLink; //newLink is new next and last link in new queue
    tempPtr = tempPtr -> nextLink_; //now points to q's next link
  }
}

template < typename T >
void Queue<T>::Release()
{
  if (!Empty())
  {
    Queue<T>::Link * currentLink = firstLink_;
    Queue<T>::Link * tempLink;

    while (currentLink != 0)
    {
      tempLink = currentLink;
      currentLink = currentLink -> nextLink_;
      delete tempLink;
    }
  }
  firstLink_ = lastLink_ = 0;
}

template < typename T >
void Queue<T>::Dump(std::ostream& os, char ofc) const
{ Display(os, ofc); }

template < typename T >
size_t Queue<T>::Capacity() const
{ return Size(); }

}
#endif
