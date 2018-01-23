/*
fqueue.cpp
Kara Vahldieck
11/28/16
version 1.0

Contains test client code to test queue.t
*/


#include <queue.t>
#include <iostream>
#include <iomanip>
#include <cstdlib>

//queue template parameters depend on varType being used

/*//queues of type char
typedef char VarType;
//*/

 //queues of type int
typedef int VarType;
//*/

/* //queues of type fsu::String
#include <xstring.h>
typedef fsu::String VarType;
#include <xstring.cpp>
//*/


void DisplayMenu();

template < typename T >
fsu::Queue<T> CopyTest(fsu::Queue<T>);

template < typename T >
void AssignTest(const fsu::Queue<T>&, fsu::Queue<T>&);

int main()
{
  std::cout << "Welcome to the Queue test program\n\n";

  fsu::Queue<VarType> q; //instantiate obj
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
         std::cin >> t;
         q.Push(t);
         break;

     case '-':
     case '2':
       if (q.Empty() == false)
       {
         q.Pop();
         break;
       }

       else
         std::cout << "Queue is empty\n";

       break;

     case 'C':
     case 'c':
       q.Clear();
       break;

     case 'R':
     case 'r':
       q.Release();
       break;

 case 'F':
     case 'f':
       std::cout << "Front of queue:  " <<  q.Front() << "\n";
       break;

     case 'E':
     case 'e':
       if (q.Empty() == false)
         std::cout << "Queue is not empty\n";

       else
         std::cout << "Queue is empty\n";

       break;

     case 'S':
     case 's':
       std::cout << "Size of queue:  " << q.Size() << '\n';
       break;

     case '=':
       {
         std::cout << "Copy Test:\n";
         fsu::Queue<VarType> q2 = CopyTest(q);
         std::cout << "Copied object         size:  " << q2.Size()
                   << "\n                      contents:  ";
         q2.Display(std::cout);

 fsu::Queue<VarType> q3;
         std::cout << "\nAssign Test:\n";
         AssignTest(q2, q3);
         std::cout << "Original object       size:  " << q2.Size()
                   << "\n                      contents:  ";
         q2.Display(std::cout);
         std::cout << "\nAssignee object       size:  " << q3.Size()
                   << "\n                      contents:  ";
         q3.Display(std::cout);
         std::cout << "\n";
         break;
       }

     case 'D':
     case 'd':
       std::cout << "Queue:  ";
       q.Display(std::cout);
       std::cout << "\n";
       std::cout << "Dump of queue:  ";
       q.Dump(std::cout);
       std::cout << "\n";
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
 }while (selection != 'Q');
}

void DisplayMenu()
{
  std::cout << "Push(Tval)  .............  + or 1\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Release()  ..............  R\n"
            << "Front()  ................  F\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copies  .................  =\n"
            << "Display queue  ..........  D\n"
            << "Display this menu  ......  M\n";
}

template < typename T >
fsu::Queue<T> CopyTest(fsu::Queue<T> q)
{
  fsu::Queue<T> q2(q); //calls copy constructor
  return q2;
}

template < typename T >
void AssignTest(const fsu::Queue<T>& q2, fsu::Queue<T>& q3)
{ q3 = q2; } //calls assignment operator


