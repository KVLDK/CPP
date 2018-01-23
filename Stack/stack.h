/*
stack.t
Kara Vahldieck
11/17/18
version 1.0

Contains definitions and implementations for stack ADT
*/


#ifndef _STACK_T
#define _STACK_T

#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace fsu
{

//class definition

template < typename T, size_t N = 100 >
class Stack
{
public:

  Stack(); //default constructor
  Stack(T fill); //1 parameter constructor
  ~Stack(); //destructor
  Stack(const Stack&); //copy constructor
  Stack& operator=(const Stack&); //assignment operator

  void Push(const T& t);
  T Pop();
  T& Top();
  const T& Top() const;
  size_t Size() const;
  size_t Capacity() const;
  bool Empty() const;
  void Clear();
  void Display(std::ostream& os, char ofc = '\0') const;
  void Dump(std::ostream& os);

private:

  const size_t capacity_;
  T data_[N];
  size_t size_;
};

template < typename T, size_t N >
std::ostream& operator<< (std::ostream& os, const Stack<T,N>& s)
{
  s.Display(os, '\0');
  return os;
}

//class function template definitions

template < typename T, size_t N >
Stack<T,N>::Stack(): capacity_(N), data_(), size_(0)
{}

template < typename T, size_t N >
Stack<T,N>::Stack(T fill): capacity_(N), data_(), size_(0)
{
  for (size_t i = 0; i < N; ++i)
   data_[i] = fill;
}

template < typename T, size_t N >
Stack<T,N>::~Stack()
{} //empty destructor (no responsibilities)

template < typename T, size_t N >
Stack<T,N>::Stack(const Stack& s): capacity_(s.capacity_), data_(), size_(s.size_)
{
  for (size_t i = 0; i < N; ++i)
   data_[i] = s.data_[i];
}

template < typename T, size_t N >
Stack<T,N>& Stack<T,N>::operator=(const Stack& s)
{
  if (this != &s)
  {
    size_ = s.size_;

    for (size_t i = 0; i < N; ++i)
    { data_[i] = s.data_[i]; }
  }
  return *this;
}

template < typename T, size_t N >
void Stack<T,N>::Push(const T& t)
{
  if (size_ != N)
  {
    data_[size_] = t;
    ++size_;
  }

  else
    std::cout << "Error: stack is full \n";
}

template < typename T, size_t N >
T Stack<T,N>::Pop()
{
  T pop;

  if (size_ != 0)
  {
    pop = data_[size_ - 1];
    --size_;
    data_[size_] = T();
    return pop;
  }

  else
  {
    std::cout << "Error: stack is empty \n";
    exit(EXIT_FAILURE);
  }
}

template < typename T, size_t N >
T& Stack<T,N>::Top()
{
  if (size_ != 0)
   return data_[size_ - 1];

  else
  {
    std::cout << "Error: stack is empty \n";
    exit(EXIT_FAILURE);
  }
}

template < typename T, size_t N >
const T& Stack<T,N>::Top() const
{
  if (size_ != 0)
   return data_[size_ - 1];

  else
  {
    std::cout << "Error: stack is empty \n";
    exit(EXIT_FAILURE);
  }
}

template < typename T, size_t N >
size_t Stack<T,N>::Size() const
{
  return size_;
}

template < typename T, size_t N >
size_t Stack<T,N>::Capacity() const
{
  return capacity_;
}

template < typename T, size_t N >
bool Stack<T,N>::Empty() const
{
  if (size_ == 0)
  { return true; }

    return false;
}

template < typename T, size_t N >
void Stack<T,N>::Clear()
{
  for (size_t i = 0; i <= (size_ - 1); ++i)
    data_[i] = T();

  size_ = 0;
}

template < typename T, size_t N >
void Stack<T,N>::Display(std::ostream& os, char ofc) const
{

  if (size_ == 0)
  {
    std::cout << "Stack is empty, nothing to display";
    return;
  }

  if (ofc != '\0')
  {
    for (size_t i = 0; i <= (size_ - 1); ++i)
      os << ofc <<  data_[i];

    return;
     //only display elements that are set, not 'fill' elements
  }

  if (ofc == '\0')
  {
    for (size_t i = 0; i <= (size_ - 1); ++i)
      os << data_[i];

    return;
  }
}

template < typename T, size_t N >
void Stack<T,N>::Dump (std::ostream& os)
{
  std::cout << "\nStack Dump():\n";
  std::cout << "Capacity: " << capacity_ << "\n";
  std::cout << "Size:     " << size_ << "\n";
  std::cout << "Array:    [";

  for (size_t i = 0; i < (capacity_ - 1); ++i)
    std::cout << data_[i] << ",";

  std::cout << "]\n";
  std::cout << "Stack:    [";
  Display (std::cout, ',');
  std::cout << "]\n\n";
}


} //end namespace fsu


#endif
