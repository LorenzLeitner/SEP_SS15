//------------------------------------------------------------------------------
// Tile.cpp
//
// Group: Group 9, study assistant Philip Loibl
//
// Authors: Markus Pichler 1331070
//
//------------------------------------------------------------------------------
//

#include "Tile.h"

//------------------------------------------------------------------------------
Tile::Tile(Type side, Color topcolor)
{
  side_ = side;
  topcolor_ = topcolor;
}

Tile::Tile(Color Li, Color Re, Color Ob, Color Un)
{
  if(Ob == Un || Li == Re)
  {
    side_ = TYPE_CROSS;
    if(Ob == EMPTY_C)
    {
      Ob = Un;
    }
    else if(Un == EMPTY_C)
    {
      Un = Ob;
    }
    else if(Li == EMPTY_C)
    {
      Li = Re;
    }
    else if(Re == EMPTY_C)
    {
      Re = Li;
    }
    topcolor_ = Ob;
  }
  if(Ob == Li || Re == Un)
  {
    side_ = TYPE_CURVE_1;
    if(Ob == EMPTY_C)
    {
      Ob = Li;
    }
    else if(Un == EMPTY_C)
    {
      Un = Re;
    }
    else if(Li == EMPTY_C)
    {
      Li = Ob;
    }
    else if(Re == EMPTY_C)
    {
      Re = Un;
    }
    topcolor_ = Ob;
  }
  if(Ob == Re || Li == Un)
  {
    side_ = TYPE_CURVE_2;
    if(Ob == EMPTY_C)
    {
      Ob = Re;
    }
    else if(Un == EMPTY_C)
    {
      Un = Li;
    }
    else if(Li == EMPTY_C)
    {
      Li = Un;
    }
    else if(Re == EMPTY_C)
    {
      Re = Ob;
    }
    topcolor_ = Ob;
  }
}

//------------------------------------------------------------------------------
Tile::Tile(const Tile & src)
{
  side_ = src.side_;
  topcolor_ = src.topcolor_;
}

//------------------------------------------------------------------------------
Tile::~Tile() throw()
{
}

//------------------------------------------------------------------------------
void Tile::setColor(Color topcolor)
{
  topcolor_ = topcolor;
}

//------------------------------------------------------------------------------
Color Tile::getColor()
{
  return topcolor_;
}

//------------------------------------------------------------------------------
Tile::Type Tile::getType()
{
  return side_;
}

//------------------------------------------------------------------------------
void Tile::setType(char c)
{
  switch (c)
  {
    case '/':
      side_ = TYPE_CURVE_1;
      break;
    case '+':
      side_ = TYPE_CROSS;
      break;
    case '\\':
      side_ = TYPE_CURVE_2;
      break;
  }
}

//---------------------for Test cases----------
std::string Tile::getColorOut()
{
  switch (topcolor_)
  {
    case COLOR_WHITE:
      return "W";
      break;
    case COLOR_RED:
      return "R";
      break;
    case EMPTY_C:
      return "0";
      break;
  }
  return "fail";
}

std::string Tile::getTypeOut()
{
  switch (side_)
  {
    case TYPE_CROSS:
      return "+";
      break;
    case TYPE_CURVE_1:
      return "/";
      break;
    case TYPE_CURVE_2:
      return "\\";
      break;
    case EMPTY_T:
      return "0";
      break;
  }
    return "fail";
}
//-----------------------------------

//------------------------------------------------------------------------------
bool Tile::operator==(const Tile &src) const
{
  return (side_ == src.side_ && topcolor_ == src.topcolor_);
}

//------------------------------------------------------------------------------
bool Tile::operator!=(const Tile &src) const
{
  return !(*this == src);
}

//------------------------------------------------------------------------------
Color Tile::notTopColor()
{
  if(topcolor_ == COLOR_RED)
  {
    return COLOR_WHITE;
  }
  if(topcolor_ == COLOR_WHITE)
  {
    return COLOR_RED;
  }
  else
  {
    return EMPTY_C;
  }
}

//------------------------------------------------------------------------------
Color Tile::getColorLeft()
{
  switch (side_)
  {
    case TYPE_CROSS:  // +
      return notTopColor();
      break;
    case TYPE_CURVE_1:  // "/"
      return topcolor_;
      break;
    case TYPE_CURVE_2:  // "\"
      return notTopColor();
      break;
    default:
      return EMPTY_C;
  }
}

//------------------------------------------------------------------------------
Color Tile::getColorRight()
{
  switch (side_)
  {
    case TYPE_CROSS:  // +
      return notTopColor();
      break;
    case TYPE_CURVE_1:  // "/"
      return notTopColor();
      break;
    case TYPE_CURVE_2:  // "\"
      return topcolor_;
      break;
    default:
      return EMPTY_C;
  }
}

//------------------------------------------------------------------------------
Color Tile::getColorTop()
{
  return getColor();
}

//------------------------------------------------------------------------------
Color Tile::getColorButtom()
{
  switch (side_)
  {
    case TYPE_CROSS:  // +
      return topcolor_;
      break;
    case TYPE_CURVE_1:  // "/"
      return notTopColor();
      break;
    case TYPE_CURVE_2:  // "\"
      return notTopColor();
      break;
    default:
      return EMPTY_C;
  }
}

//------------------------------------------------------------------------------
Tile::Type Tile::charToType(char c)
{
  switch (c)
  {
    case '/':
      return TYPE_CURVE_1;
    case '+':
      return TYPE_CROSS;
    case '\\':
      return TYPE_CURVE_2;
    default:
      return EMPTY_T;
  }
}