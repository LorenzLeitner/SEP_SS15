//------------------------------------------------------------------------------
// Filename: Karte.h
// Description: ...
// Authors: Lorenz Leitner
// Tutor: Philipp Loibl
// Group: 11574
// Created: 15.04.2015
// Last change: 15.04.2015
//------------------------------------------------------------------------------

#ifndef KARTE_H_INCLUDED
#define KARTE_H_INCLUDED

#include <string>
#include <iostream>
#include <map>
#include "Position.h"
#include "Tile.h"
#include "Command.h"

struct customKeyComparator : std::binary_function<Position*, Position*, bool>
{
  bool operator() (Position *lhs, Position *rhs) const
  {
    return *lhs < *rhs;  // This calls the operator < in your class
  }
};

//struct customKeyComparator
//{
//  bool operator()(const Position a, const Position b) const
//  {
//    int i = a.getX();
//    /*int i = a.getXConst();
//    if ((a.getX() < b.getX()) && (a.getY() == b.getY()))
//    {
//      return true;
//    }
//    if (a.getX() > b.getX() && a.getY() < b.getY())
//    {
//      return true;
//    }
//    else
//    {
//      return false;
//    }*/
//  }
//};

class Karte
{
public:

  Karte();
  //~Addtile();
  
};

#endif //KARTE_H_INCLUDED

