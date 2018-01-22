/*
  Kara V
  Driver to test fucntionality of Product.cpp and Header.h
*/

#include <iostream>
#include "Header.h"


int main()
{

    //sample data for 3-argument constructor
    const char* name = "Apple";
    uint32_t code = 0000001126;
    float cost = 3.00;


    Product p1; //default constructor called
    Product p2(name, code, cost); //3-argument constructor called

    std::cout << "Objects after declaration: \n\n" << "p1 = " << p1 << "\np2 = " << p2 << "\n\n";

    //more sample data
    const char* setname = "Grapefruit";
    uint32_t setcode = 0000001012;
    float setcost = 2.00;

    //test Set functions
    p1.SetName(setname);
    p1.SetBarCode(setcode);
    p1.SetCost(setcost);

    std::cout << "p1 after set: \n\n" << "p1 = " << p1 << "\n\n";
    
    Product p3(p2);  //calls copy constructor

    std::cout << "p3 after call to copy constructor with p2 data: \n\n" << "p3 = " << p3 << "\n\n";

    //output tests Get Functions
    std::cout << "Get name of all products: \n\n" << "p1 = " << p1.GetName() << "\np2 = " << p2.GetName() << "\np3 = " << p3.GetName() << "\n\n";
    std::cout << "Get barcode of all products: \n\n" << "p1 = " << std::hex << std::setfill('0') << std::setw(8) << p1.GetBarCode() << "\np2 = " << std::hex << std::setfill('0') << std::setw(8) << p2.GetBarCode() << "\np3 = " << std::hex << std::setfill('0') << std::setw(8) << p3.GetBarCode() << "\n\n";
    std::cout << "Get cost of all products: \n\n" << "p1 = " << "$"<< p1.GetCost() << "\np2 = " << "$"<< p2.GetCost() << "\np3 = " << "$"<< p3.GetCost() << "\n\n";


    std::cout << "Assigning p2 to p1....\n\n";
    p1 = p2; //calls assignment operator
    std::cout << "p1 and p2 call to assignment operator: \n\n" << "p1 = " << p1 << "\np2 = " << p2 << "\n\n";

    //create array of Product objects with defaut constructor
    const int size = 5;
    Product pArray[size] = {};

    //more sample data
    const char* nametwo = "Banana";
    uint32_t codetwo = 0000000724;
    float costtwo = 5.00;

    std::cout << "Array contents after declaration: \n\n";

    //output array with default values
    for (int i=0; i<5; ++i)
    { std::cout << "p[" << i << "] = " << pArray[i] << " \n"; }

    //set array values changed to those provided in sample data, then output
    std::cout << "\nArray contents after Set: \n\n";
    for (int i=0; i<5; ++i)
    {   pArray[i].SetName(nametwo);
        pArray[i].SetBarCode(codetwo);
        pArray[i].SetCost(costtwo);
        std::cout << "p[" << i << "] = " << pArray[i] << " \n"; }

    std::cout << "\n";



    //keep window open until user ends program

    std::cout << "Press ENTER to continue";
	std::cin.ignore();
	std::cin.get();


} //end main