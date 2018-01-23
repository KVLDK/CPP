/*
vehicles.cpp
Kara Vahldieck
10/15/16
Implementation file for Vehicles class
version 1.0
*/


#include <vehicles.h>
#include <shapes.h>
#include <iostream>
#include <cstring>


Vehicle::Vehicle (): serialNumber_(NULL), passengerCapacity_(0), verbose_(0)
{ const char* holder = "nullptr"; //holds value to copy into serialNumber_

  serialNumber_ = new char[8];
  serialNumber_[8] = '\0';
  strcpy(serialNumber_, holder);
}

Vehicle::Vehicle (const char* serialNumber, unsigned int passengerCapacity, bool verbose): serialNumber_(NULL), passengerCapacity_(passengerCapacity), verbose_(verbose)
{ if (serialNumber_ != NULL)
  { delete[] serialNumber_;}

  size_t size = strlen(serialNumber);
  serialNumber_ = new char[1+size];
  serialNumber_[size] = '\0';
  strcpy(serialNumber_, serialNumber);

  if (verbose_ == 1)
    std::cout << "Vehicle()\n";
}

Vehicle::~Vehicle ()
{ if (Vehicle::verbose_ == 1)
    std::cout << "~Vehicle()\n";

  if (serialNumber_ != NULL)
    delete[] serialNumber_;
}

const char* Vehicle::SerialNumber () const
{ return serialNumber_;}

unsigned int Vehicle::PassengerCapacity () const
{ return passengerCapacity_;}

float Vehicle::LoadCapacity () const
{ return 0; }

const char* Vehicle::ShortName () const
{
  return "UNK";
}

float Vehicle::Toll () const
{ return 2.00; } //default toll value for cars, truck toll function will be overloaded

VehicleType Vehicle::SnDecode (const char* sn)
{
  switch (sn[0])
  {
    case '0':
      return badSn;
    case '1':
      return vehicle;
    case '2':
      return car;
    case '3':
      return truck;
    case '4':
      return van;
    case '5':
      return tanker;
    case '6':
      return flatbed;
    default:
      return badSn;
  }
}

Car::Car (): Vehicle() //call base class default constructor
{}

Car::Car (const char* serialNumber, unsigned int passengerCapacity, bool verbose): Vehicle (serialNumber, passengerCapacity, verbose)
{ if (Vehicle::verbose_ == 1)
    std::cout << "Car()\n";
}
// call base class parameterized constructor with supplied arguments

Car::~Car ()
{ if (Vehicle::verbose_ == 1)
    std::cout << "~Car()\n";
}

const char* Car::ShortName () const
{
  return "CAR";
}

Truck::Truck (): Vehicle (), DOTLicense_(NULL)
{ const char* holder = "nullptr"; //holds value to copy into DOTLicense_

  DOTLicense_ = new char[8];
  DOTLicense_[8] = '\0';
  strcpy(DOTLicense_, holder);
}

Truck::Truck (const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, bool verbose): Vehicle (serialNumber, passengerCapacity, verbose), DOTLicense_(NULL)
{{ if (DOTLicense_ != NULL)
    { delete[] DOTLicense_;}

    size_t size = strlen(DOTLicense);
    DOTLicense_ = new char[1+size];
    DOTLicense_[size] = '\0';
    strcpy(DOTLicense_, DOTLicense);}

  if (Vehicle::verbose_ == 1)
      std::cout << "Truck()\n";
}

Truck::~Truck ()
{ if (Vehicle::verbose_ == 1)
    std::cout << "~Truck()\n";

  if (DOTLicense_ != NULL)
    delete[] DOTLicense_;
}

const char* Truck::ShortName () const
{
  return "TRK";
}

float Truck::Toll () const
{ return 10.00; }

const char* Truck::DOTLicense () const
{ return DOTLicense_;}

Van::Van (): Truck (), Box ()
{}

Van::Van (const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float width, float height, bool verbose): Truck (serialNumber, passengerCapacity, DOTLicense, verbose), Box (length, width, height\
, verbose)
{ if (Vehicle::verbose_ == 1)
    std::cout << "Van()\n";
}

Van::~Van ()
{ if (Vehicle::verbose_ == 1)
    std::cout << "~Van()\n";
}

float Van::LoadCapacity () const
{ float capacity = Box::Volume();
  return capacity;
}

const char* Van::ShortName () const
{
  return "VAN";
}

Tanker::Tanker (): Truck (), Cylinder ()
{}

Tanker::Tanker (const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float radius, bool verbose): Truck(serialNumber, passengerCapacity, DOTLicense, verbose), Cylinder (length, radius, verbose)
{ if (Vehicle::verbose_ == 1)
    std::cout << "Tanker()\n";
}

Tanker::~Tanker ()
{ if (Vehicle::verbose_ == 1)
    std::cout << "~Tanker()\n";
}

float Tanker::LoadCapacity () const
{ float capacity = Cylinder::Volume();
  return capacity;
}

const char* Tanker::ShortName () const
{
  return "TNK";
}

Flatbed::Flatbed (): Truck (), Plane ()
{}

Flatbed::Flatbed (const char* serialNumber, unsigned int passengerCapacity, const char* DOTLicense, float length, float width, bool verbose): Truck (serialNumber, passengerCapacity, DOTLicense, verbose), Plane (length, width, verbose)
{ if (Vehicle::verbose_ == 1)
    std::cout << "Flatbed()\n";
}

Flatbed::~Flatbed ()
{ if (Vehicle::verbose_ == 1)
    std::cout<< "~Flatbed()\n";
}

float Flatbed::LoadCapacity () const
{ float capacity = Plane::Area();
  return capacity;
}

const char* Flatbed::ShortName () const
{
  return "FLT";
}
