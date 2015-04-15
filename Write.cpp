//------------------------------------------------------------------------------
// Filename: Write.cpp
// Description: Used for writing binary file
//              First only as write command
//              Later as automatic write if -g flag is set
// Authors: Lorenz Leitner
// Tutor: Philipp Loibl
// Group: 11574
// Created: 14.04.2015
// Last change: 14.04.2015
//------------------------------------------------------------------------------

#include "Write.h"

#define AP_OFFSET     4
#define AP_WHITE      1
#define AP_RED        2
#define NO_FIGURE     0
#define SIDE_CROSS    1
#define SIDE_CURVE_1  2
#define SIDE_CURVE_2  3
#define TOP_WHITE     1
#define TOP_RED       2

Write::Write() : Command("Write")
{
}

int Write::execute(Game& board, std::vector<std::string>& params)
{
  return 0;
}

//------------------------------------------------------------------------------
void Write::createNewFile(std::string user_input, std::map<Position*, Tile*> &karte,
  int &tile_counter)
{
  std::string file_name;
  try
  {
    // Takes parameter after write as file_name
    file_name = user_input.substr(6);
    long pos;

    class FileHeader
    {
    public:
      char *signature;    // char[4] // TRAX
      char active_player; // char // white (1) or red (2)
      signed char minX;   // s8
      signed char minY;   // s8
      signed char maxX;   // s8
      signed char maxY;   // s8
    };

    class BoardTiles
    {
    public:
      char side;      // no figure (0), cross (1), Kurve1 "/" (2), Kurve2 "\" (3)
      char top_color; // no figure (0), white end (1), red end (2) // offset 1
    };

    FileHeader file_header;
    // Find max and min coordinates
    for (auto& x : karte)
    {
      file_header.minX = x.first->getX();
      file_header.minY = x.first->getY();
      break;
    }
    std::map<Position*, Tile*>::reverse_iterator rit;
    for (rit = karte.rbegin(); rit != karte.rend(); ++rit)
    {
      file_header.maxX = rit->first->getX();
      file_header.maxY = rit->first->getY();
      break;
    }
    // Other way
    /*file_header.minX = karte.begin()->first->getX();
    file_header.minY = karte.begin()->first->getY();
    
    file_header.maxX = karte.end()->first->getX();
    file_header.maxY = karte.end()->first->getY();*/

    // Write values into header
    file_header.signature = "TRAX";
    file_header.active_player = AP_RED;
  
    // Open file for writing
    // file_name is either argv[2] or command after write, i.e. user_input
    std::ofstream file(file_name,
      std::ios::out | std::ios::trunc | std::ios::binary);
    // Check if file is open, prints error if not, stops writing
    if (!file.is_open())
    {
      throw WriteException();
    }

    // Write header into file
    file << file_header.signature;
    file << file_header.active_player;
    file << file_header.minX;
    file << file_header.minY;
    file << file_header.maxX;
    file << file_header.maxY;

    //--------------------------------------------------------------------------//
    // Write each line of the board from (minX,minY) to (maxX,maxY)
    // from left to right
    // Write tiles into file
    BoardTiles board_tiles;

    // TODO Write

    for (auto& x : karte)
    {
      // Write type and color
      // Ideally 0 for both if position has no tile
      board_tiles.side = x.second->getType();
      board_tiles.top_color = x.second->getColor();

      file << board_tiles.side;
      file << board_tiles.top_color;

      // Save position
      pos = file.tellp();
      // Toggle active player
      switch (file_header.active_player)
      {
      case AP_WHITE:
        file_header.active_player = AP_RED;
        break;
      case AP_RED:
        file_header.active_player = AP_WHITE;
        break;
      }
      // Go to active player offset and write
      file.seekp(AP_OFFSET);
      file << file_header.active_player;
      // Go back to where we left off
      file.seekp(pos);
    }
    file.close();
  }
  catch (WriteException& e1)
  {
    std::cout << e1.what() << file_name << std::endl;
  }
  catch (...)
  {
    std::cout << "Error: Wrong parameter count!" << std::endl;
  }
}

//------------------------------------------------------------------------------
//void Write::togglePlayerWrite(FileHeader file_header)
//{
//  switch (file_header.active_player)
//}