/*
fstack.cpp
Kara V
11/17/16
version 1.0

Contains test client code to test stack.t
*/


#include <stack.t>
#include <iostream>
#include <iomanip>
#include <cstdlib>

//stack template parameters depend on varType being used
//uncomment the type the user would like to use

 //stacks of type char
typedef char VarType;
const size_t cap = 100;
const char fill = '*';
//*/

/* //stacks of type int
typedef int VarType;
const size_t cap = 100;
const int fill = 0;
//*/

/* //stacks of type fsu::String
#include <xstring.h>
typedef fsu::String VarType;
const size_t cap = 100;
const fsu::String fill = "*";
#include <xstring.cpp>
//*/


void DisplayMenu();

template < typename T, size_t N>
fsu::Stack<T,N> CopyTest(fsu::Stack<T,N>);

template < typename T, size_t N>
void AssignTest(const fsu::Stack<T,N>&, fsu::Stack<T,N>&);

int main()
{
  std::cout << "Welcome to the Stack test program\n\n";

  fsu::Stack<VarType, cap> s(fill); //instantiate obj
  VarType t; //value to push onto stack

  DisplayMenu();

  char selection;

do
{
  std::cout << "Enter your selection ('Q' to quit):";
  std::cin >> selection;

  switch(selection)
  {
    case '+':
    case '1':
      if (s.Capacity() != s.Size())
      {
        std::cin >> t;
        s.Push(t);
        break;
      }

      else
        std::cout << "Stack is full\n";

      break;

    case '-':
    case '2':
      if (s.Empty() == false)
      {
        s.Pop();
        break;
      }

      else
        std::cout << "Stack is empty\n";

   break;

    case 'C':
    case 'c':
      s.Clear();
      break;

    case 'T':
    case 't':
      std::cout << "Top of stack:  " <<  s.Top() << "\n";
      break;

    case 'E':
    case 'e':
      if (s.Empty() == false)
        std::cout << "Stack is not empty\n";

      else
        std::cout << "Stack is empty\n";

      break;

    case 'S':
    case 's':
      std::cout << "Size of stack:  " << s.Size() << '\n';
      break;

    case 'K':
    case 'k':
      std::cout << "Capacity of stack:  " << s.Capacity() << '\n';
      break;

    case '=':
    {
      std::cout << "Copy Test:\n";
      fsu::Stack<VarType,cap> s2 = CopyTest(s);
      std::cout << "Copied object         size:  " << s2.Size()
               << "\n                      contents:  ";
      s2.Display(std::cout);
      std::cout << "\n";

      fsu::Stack<VarType,cap> s3(fill);
      std::cout << "\nAssign Test:\n";
      AssignTest(s2, s3);
      std::cout << "Original object       size:  " << s2.Size()
               << "\n                      contents:  ";
      s2.Display(std::cout);
      std::cout << "\nAssignee object       size:  " << s3.Size()
               << "\n                      contents:  ";
      s3.Display(std::cout);
      break;
     }

    case 'D':
    case 'd':
      std::cout << "Stack:  ";
      s.Display(std::cout);
      std::cout << "\n";
      break;

  case 'U':
    case 'u':
      s.Dump(std::cout);
      break;

    case 'M':
    case 'm':
      DisplayMenu();
      break;

    case 'Q':
    case 'q':
      selection = 'Q';
      break;

    default:
      std::cout << "Incorrect entry\n";


  }
 } while (selection != 'Q');
}

void DisplayMenu()
{
  std::cout << "Push(Tval)  .............  + or 1\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Top()  ..................  T\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Capacity()  .............  K\n"
            << "Copies  .................  =\n"
            << "Display stack  ..........  D\n"
            << "Dump()  .................  U\n"
            << "Display this menu  ......  M\n";
}

template < typename T, size_t N>
fsu::Stack<T,N> CopyTest(fsu::Stack<T,N> s)
{
  fsu::Stack<T,N> s2(s); //calls copy constructor
  return s2;
}

template < typename T, size_t N>
void AssignTest(const fsu::Stack<T,N>& s2, fsu::Stack<T,N>& s3)
{ s3 = s2; } //calls assignment operator

