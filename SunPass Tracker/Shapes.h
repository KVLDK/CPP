/*
shapes.h
Kara Vahldieck
10/15/16
Header file for Shapes class
version 1.0
*/


#ifndef _SHAPES_H
#define _SHAPES_H

class Box
{
public:

  Box (); //default constructor
  Box (float length_, float width_, float height_, bool verbose_); //parameterized constructor
  virtual ~Box (); //destructor

  float Volume() const;

private:

  Box (const Box&); //copy constructor
  Box& operator= (const Box& v); //assignment operator, 'v' for vehicle

  float length_, width_, height_;
  bool verbose_;
};

class Cylinder
{
public:

  Cylinder (); //default constructor
  Cylinder (float length_, float radius_, bool verbose_); //parameterized constructor
  virtual ~Cylinder (); //destructor

  float Volume() const;

private:

  Cylinder (const Cylinder&); //copy constructor
  Cylinder& operator= (const Cylinder& v); //assignment operator

  float length_, radius_;
  bool verbose_;
};

class Plane
{
public:

  Plane (); //default constructor
  Plane (float length_, float width_, bool verbose_); //parameterized constructor
  virtual ~Plane (); //destructor

  float Area () const;

private:

  Plane (const Plane&); //copy constructor
  Plane& operator= (const Plane& v); //assignment operator

  float length_, width_;
  bool verbose_;
};


#endif
