/*
vehicles.h
Kara Vahldieck
10/15/16
Header file for Vehicles class
version 1.0
*/


#ifndef _VEHICLES_H
#define _VEHICLES_H

#include <shapes.h>

enum VehicleType {badSn, vehicle, car, truck, van, tanker, flatbed};

class Vehicle
{
public:

  Vehicle (); //default constructor
  Vehicle (const char* serialNumber_, unsigned int passengerCapacity_, bool verbose_);
  //parameterized constructor
  virtual ~Vehicle (); //destructor

  const char* SerialNumber () const;
  unsigned int PassengerCapacity () const;
  virtual float LoadCapacity () const;
  virtual const char* ShortName () const;
  virtual float Toll () const;

  static VehicleType SnDecode (const char* sn);

protected:

  bool verbose_;

private:

  Vehicle (const Vehicle&); //copy constructor
  Vehicle& operator= (const Vehicle& v); //assignment operator

  char* serialNumber_;
  unsigned int passengerCapacity_;
};

class Car: public Vehicle //inherits from class Vehicle
{
public:

  Car (); //default constructor
  Car (const char* serialNumber_, unsigned int passengerCapacity_, bool verbose_);
  // parameterized constructor
  virtual ~Car (); //destructor

  virtual const char* ShortName () const;

private:

  Car (const Car&); //copy constructor
  Car& operator= (const Car& v); //assignment operator

};

class Truck: public Vehicle
{
public:

  Truck (); //default constructor
  Truck (const char* serialNumber_, unsigned int passengerCapacity_, const char* DOTLicense_, bool verbose_); //parameterized constructor
  virtual ~Truck (); //destructor

  virtual const char* ShortName () const;
  virtual float Toll () const;
  const char* DOTLicense () const;

private:

  Truck (const Truck&); //copy constructor
  Truck& operator= (const Truck& v); //assignment operator

  char* DOTLicense_;
};

class Van: public Truck, public Box //multiple inheritance
{
public:

  Van (); //default constructor
  Van (const char* serialNumber_, unsigned int passengerCapacity_, const char* DOTLicense_, float length_, float width_, float height_, bool verbose_);
  //parameterized constructor
  virtual ~Van (); //destructor

  virtual float LoadCapacity () const;
  virtual const char* ShortName () const;

private:

  Van (const Van& v); //copy constructor
  Van& operator= (const Van& v); //assignment operator
};

class Tanker: public Truck, public Cylinder
{
public:

  Tanker (); //default constructor
  Tanker (const char* serialNumber_, unsigned int passengerCapacity_, const char* DOTLicense_, float length_, float radius__, bool verbose_);
  //parameterized constructor
  virtual ~Tanker (); //destructor

  virtual float LoadCapacity () const;
  virtual const char* ShortName () const;

private:

  Tanker (const Tanker& v); //copy constructor
  Tanker& operator= (const Tanker& v); //assignment operator
};

class Flatbed: public Truck, public Plane
{
public:

  Flatbed (); //default constructor
  Flatbed (const char* serialNumber_, unsigned int passengerCapacity_, const char* DOTLicense_, float length_, float width_, bool verbose_);
  //parameterized constructor
  virtual ~Flatbed (); //destructor

  virtual float LoadCapacity () const;
  virtual const char* ShortName () const;

private:

  Flatbed (const Flatbed& v); //copy constructor
  Flatbed& operator= (const Flatbed& v); //assignment operator
};


#endif

