/*
tracker.cpp
Kara V
10/19/16
Implementation file for tracker program
version 1.0
*/

#include <vehicles.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>


//global constants
const unsigned int C1=6, C2=7, C3=10, C4=10, c5=2, c6=2;

int main (int argc, char* argv[]) //parameters are received from the command line
{
  unsigned int maxDOTLength = 0;
  unsigned int maxSNLength = 0;
  const int vMax = 100;
  const int snMax = 50; //
  const int DOTMax = 50;


  Vehicle*  vArray[vMax]; //array to hold segment objects

  std::cout<< "\n\nSunPass Tracker started...\n\n";

  std::ifstream ifs; //declare an istream object to read input

  if (argc > 1)
 {
   ifs.open(argv[1]); //if a filename is presented in the c-line, open it
    if (ifs.fail())
    {
      std::cout << " ** cannot open command file " << argv[1] << '\n';
      exit (EXIT_FAILURE);
    }
 } //print message and exit if unable to open file

 int segSize;
 char sn[snMax];
 unsigned int pc;
 char DOTL[DOTMax];
 float d1, d2, d3;
 VehicleType v;

 do
 {
   int badSnTotal = 0, vehicleTotal = 0, carTotal = 0, truckTotal = 0, vanTotal =0, tankerTotal = 0, flatbedTotal = 0;
   float totalTonnage = 0.00, totalToll = 0.00;

   std::cin >> segSize; //extract the segSize from the stream
   if (segSize == 0 || segSize >100 )
     break;

   for (size_t i = 0; i < segSize; ++i)
   {
     std::cin >> sn; //extract the sn from the stream
     v = Vehicle::SnDecode(sn);
     switch (v)
   {
     case badSn:
       std::cin >> pc; //extract pc from the stream
       ++badSnTotal;
       vArray[i] = new Vehicle(sn, pc, 0); //create object and insert into array
       totalToll += (vArray[i])->Toll();
       break;

     case vehicle:
       std::cin >> pc; //extract pc from the stream
       ++vehicleTotal;
       vArray[i] = new Vehicle(sn, pc, 0); //create object and insert into array
       totalToll += (vArray[i])->Toll();
       break;

     case car:
       std::cin >> pc; //extract pc from the stream
       ++carTotal;
       vArray[i] = new Car(sn, pc, 0); //create object and insert into array
       totalToll += (vArray[i])->Toll();
       break;

    case truck:
       std::cin >> pc >> DOTL;
       ++truckTotal;
       vArray[i] = new Truck (sn, pc, DOTL, 0);
       totalToll += (vArray[i])->Toll();
       break;

     case van:
       std::cin >> pc >> DOTL >> d1 >> d2 >> d3;
       ++vanTotal;
       vArray[i] = new Van (sn, pc, DOTL, d1, d2, d3, 0);
       totalToll += (vArray[i])->Toll();
       totalTonnage += vArray[i] -> LoadCapacity();
       //array obj 'van' accesses its LoadCapacity function thru ptr notation
       break;

     case tanker:
       std::cin >> pc >> DOTL >> d1 >> d2;
       ++tankerTotal;
       vArray[i] = new Tanker (sn, pc, DOTL, d1, d2, 0);
       totalToll += (vArray[i])->Toll();
       totalTonnage += vArray[i] -> LoadCapacity();
       //array obj 'tanker' accesses its LoadCapacity function thru ptr notation
       break;

  case flatbed:
       std::cin >> pc >> DOTL >> d1 >> d2;
       ++flatbedTotal;
       vArray[i] = new Flatbed (sn, pc, DOTL, d1, d2, 0);
       totalToll += (vArray[i])->Toll();
       totalTonnage += vArray[i] -> LoadCapacity();
       //array obj 'flatbed' accesses its LoadCapacity function thru ptr notation
       break;

     default:
       std::cerr << "**ERROR: bad serial number passed to decision logic\n";
       break;
  }
 }

   for (size_t i = 0; i < segSize; ++i)
   {
     int temp  = strlen(vArray[i]->SerialNumber());
     if (maxSNLength < temp)
       maxSNLength = temp;
   }

   for (size_t i = 0; i < segSize; ++i)
   {
     if (truck <= Vehicle::SnDecode((vArray[i])->SerialNumber()))
     {
       int temp = strlen(dynamic_cast<Truck*>(vArray[i])->DOTLicense());
       if (maxDOTLength < temp)
         maxDOTLength = temp;
     }
   }
 if (maxDOTLength < 11)
     maxDOTLength = 11;

   if (maxSNLength < 13)
     maxSNLength = 13;

   const unsigned int C5 = maxDOTLength + c5;
   const unsigned int C6 = maxSNLength + c6;


   std::cout << "Segment Summary\n===============\n\n";
   std::cout << "  Cars:     " << carTotal;
   std::cout << "\n  Trucks:   " << truckTotal;
   std::cout << "\n  Vans:     " << vanTotal;
   std::cout << "\n  Tankers:  " << tankerTotal;
   std::cout << "\n  Flatbeds: " << flatbedTotal;
   std::cout << "\n  Unknowns: " << vehicleTotal;
   std::cout << "\n  BadSns:   " << badSnTotal;
   std::cout << "\n  Tonnage:  " << totalTonnage;
   std::cout << "\n  Tolls:    $" << std::fixed << std::setprecision(2) << totalToll;

   std::cout << "\n\nSegment Details\n===============\n\n";
   std::cout << std::setw(C1) << "Type" << std::setw(C2) << "Toll" << std::setw(C3) << "Pass Cap" << std::   setw(C4) << "Load Cap" << std::setw(C5) << "DOT License" << std::setw(C6) << "Serial Number";
   std::cout << '\n';
   std::cout << std::setw(C1) << "----" << std::setw(C2) << "----" << std::setw(C3) << "--------" << std::   setw(C4) << "--------" << std::setw(C5)    << "-----------" << std::setw(C6) << "-------------";
     std::cout << '\n';

 for (size_t i = 0; i < segSize; ++i)
 {
   std::cout << std::setw(C1) << (vArray[i])->ShortName() << std::setw(C2) << std::setprecision(2) << (vArray[i])->Toll() << std::setw(C3) << (vArray[i])->PassengerCapacity() << std::setw(C4) << (vArray[i])->LoadCapacity();
    if (truck <= Vehicle::SnDecode((vArray[i])->SerialNumber()))
     {
       std::cout << std::setw(C5)<< dynamic_cast<Truck*>((vArray[i]))->DOTLicense();}
     //if obj is of type truck or inherited from type truck, must downcase the
     //ptr to use the DOTLicense function
     else
       std::cout << std::setw(C5) << "(NA)";


   std::cout << std::setw(C6) << (vArray[i])->SerialNumber() << "\n";
 }
 maxDOTLength = 0;
 maxSNLength = 0;
 std::cout << "\n";
 } while (segSize != 0);

std::cout << "\n\nThank you for using SunPass Tracker.\n\n";
}


