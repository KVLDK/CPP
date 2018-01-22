/*
Kara V
Product Class function definitions
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"
#include <cstdint>




Product::Product(): name_(NULL), code_(0x00000000), cost_(0.0)  //initialize to default values
{ 
  name_= new char [2];
  name_[0] = '#';
  name_[1] = '\0';
}

Product::Product(const char* name, uint32_t code, float cost): name_(NULL), code_(code), cost_(cost) //initialize with given values
{
  if(name_ != NULL) //ensures name_ not already initialized
    delete[] name_;

  size_t size = strlen(name);  // variable to hold size of name variable passed in
  name_ = new char[1+size];  //ensure enough room copy array and add null character to last index
  name_[size]='\0';  //null character at last index
  strcpy(name_, name);
}

Product::~Product()
{
  if(name_ != NULL)
    delete[] name_;
}

//copy constructor (creates brand new object)
Product::Product (const Product& p):name_(NULL), code_(p.code_), cost_(p.cost_)
{
    size_t size = strlen(p.name_);
    name_ = new char[1+size];
    name_[size] = '\0';
    strcpy(name_, p.name_);
}

//assignment operator
Product& Product::operator= (const Product& p)
{
    if(this != &p) //check values aren't already equal
    {
    size_t size = strlen(p.name_);
    name_ = new char[1+size];
    name_[size] = '\0';
    strcpy(name_, p.name_);
    
    code_=p.code_;
    cost_=p.cost_;
    }

return *this;
}

void Product::SetName (const char* name)
{
    if(name_!=NULL)  //check if name_ is initialized or NULL
        delete[] name_;

    size_t size = strlen(name);
    name_ = new char[1+size];
    name_[size] = '\0';
    strcpy(name_, name); 
}

void Product::SetBarCode (uint32_t code)
{
    code_=code;
}

void Product::SetCost (float cost)
{
    cost_=cost;
}

const char* Product::GetName() const
{
    return name_;
}

uint32_t Product::GetBarCode() const
{
    return code_;
}

float Product::GetCost() const
{
    return cost_;
}



//overloaded output stream operator provided by Professor Chris Lacher (FSU)
std::ostream& operator << (std::ostream& os, const Product& p)
{
std::ios_base::fmtflags flags=os.flags();
os.setf(std::ios::fixed | std::ios::showpoint);
os.precision(2);
os << p.GetName() << '\t' << std::uppercase << std::setfill('0') << std::setw(8) << p.GetBarCode() << std::setfill(' ') << '\t'  << "$" << p.GetCost();
os.setf(flags);
return os;
}








































