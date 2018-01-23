/*
shapes.cpp
Kara V
10/15/16
Implementation file for Shapes class
version 1.0
*/


#include <shapes.h>
#include <cmath>
#include <iostream>

Box::Box (): length_(0), width_(0), height_(0), verbose_(0)
{}

Box::Box (float length, float width, float height, bool verbose): length_(length), width_(width), height_(height), verbose_(verbose)
{ if (verbose_ == 1)
    std::cout << "Box()\n";
}

Box::~Box ()
{ if (verbose_ == 1)
    std::cout << "~Box()\n";
}

float Box::Volume () const
{ float volume;
  volume = length_ * width_ * height_;
  return volume;
}

Cylinder::Cylinder (): length_(0), radius_(0), verbose_(0)
{}

Cylinder::Cylinder (float length, float radius, bool verbose): length_(length), radius_(radius), verbose_(verbose)
{ if (verbose_ == 1)
    std::cout << "Cylinder()\n";
}

Cylinder::~Cylinder ()
{ if (verbose_ == 1)
    std::cout << "~Cylinder()\n";
}

float Cylinder::Volume () const
{ float volume;
  volume = (M_PI) * (radius_ * radius_) * length_;
  return volume;
}

Plane::Plane (): length_(0), width_(0), verbose_(0)
{}

Plane::Plane (float length, float width, bool verbose): length_(length), width_(width), verbose_(verbose)
{ if (verbose_ == 1)
    std::cout << "Plane()\n";
}

Plane::~Plane ()
{ if (verbose_ == 1)
    std::cout << "~Plane()\n";
}

float Plane::Area () const
{ float area;
  area = length_ * width_;
  return area;
}

