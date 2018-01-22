/*
Kara V
Product Header File
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>

class Product
{
public:
    Product();  //default constructor
    Product (const char*, unsigned, float);  //3-argument constructor
    ~Product();  //destructor
    Product(const Product&); //copy constructor
    Product &operator=(const Product&); //assignment operator

    //set values of private data
    void SetName (const char*);
    void SetBarCode (uint32_t);
    void SetCost (float);

    //get values of private data
    const char* GetName() const;
    unsigned GetBarCode() const;
    float GetCost() const;

private:
    char* name_;
    uint32_t code_;
    float cost_;
};

//output stream operator to print Product object values to screen
std::ostream& operator << (std::ostream&, const Product& p);


#endif
