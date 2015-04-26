//------------------------------------------------------------------------------
// AddTile.cpp
//
// Group: Group 9, study assistant Philip Loibl
//
// Authors:
// Lorenz Leitner (1430211)
// Verena Niederwanger (1430778)
// Markus Pichler (1331070)
//------------------------------------------------------------------------------
//

#ifndef TILE_H
#define TILE_H

#include "Color.h"
#include <string>
#include <iostream>

//------------------------------------------------------------------------------
// Tile Class
// Class for tiles
//
class Tile
{

  public:
    //--------------------------------------------------------------------------
    // Type Enum
    // Enum for easier reading of tile types
    //
    enum Type
    {
      EMPTY_T = 0,
      TYPE_CROSS = 1,
      TYPE_CURVE_1 = 2,
      TYPE_CURVE_2 = 3
    };

  private:

    //--------------------------------------------------------------------------
    // Type of Tile
    //
    Type side_;

    //--------------------------------------------------------------------------
    // Color of the active Curve
    //
    Color topcolor_;

    //--------------------------------------------------------------------------
    // Color of the active Curve
    //
    Color of_activeplayer_;

    //--------------------------------------------------------------------------
    // int white Id to identify tile
    //
    int white_id_;

    //--------------------------------------------------------------------------
    // int red Id to identify tile
    //
    int red_id_;

    //--------------------------------------------------------------------------
    // Private assignment operator

    Tile& operator=(const Tile& original);

  public:
    //--------------------------------------------------------------------------
    // Constructor method
    //
    // @param side the type of tile
    // @param color the top color
    //
    Tile(Type side, Color orientation);

    //--------------------------------------------------------------------------
    // Copy constructor
    // copies a tile to a new tile
    //
    // @param the tile to be copied
    //
    Tile(const Tile &);

    //--------------------------------------------------------------------------
    // Constructor method
    //
    // @param Li the left color
    // @param Re the right color
    // @param Ob the top color
    // @param Un the bottom color
    //
    Tile(Color Li, Color Re, Color Ob, Color Un);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Tile() throw();

    //--------------------------------------------------------------------------
    // Setter Methods
    //

    //--------------------------------------------------------------------------
    // setColor method
    // Sets the color of a tile
    //
    // @param topcolor the color at the top of a tile
    //
    void setColor(Color topcolor);

    //--------------------------------------------------------------------------
    // setType method
    // Sets the type of a tile
    //
    // @param c the type, either '+', '/' or '\'
    //
    void setType(char c);

    //--------------------------------------------------------------------------
    // setPlayer method
    // Sets color of a player
    //
    // @param of_activeplayer the color of a player
    //
    void setPlayer(Color of_activeplayer);

    //--------------------------------------------------------------------------
    // setRedId method
    // Sets int(ID) of a tile
    //
    // @param red_id the int(red ID) of a tile
    //
    void setRedId(int red_id);

    //--------------------------------------------------------------------------
    // setWhiteId method
    // Sets int(ID) of a tile
    //
    // @param white_id the int(white ID) of a tile
    //
    void setWhiteId(int white_id);

    //--------------------------------------------------------------------------
    // Getter Methods
    //

    //--------------------------------------------------------------------------
    // getType method
    // Gets the type of a tile
    //
    // @return Type side_
    //
    Type getType();

    //--------------------------------------------------------------------------
    // getColor method
    // Gets the top color of a tile
    //
    // @return Color topcolor_
    //
    Color getColor();

    //--------------------------------------------------------------------------
    // getColorLeft method
    // Gets the left color of a tile
    //
    // @return Color topcolor_ if type is '/'
    // @return Color notTopColor() if type is '+' or '\'
    //
    Color getColorLeft();

    //--------------------------------------------------------------------------
    // getColorRight method
    // Gets the right color of a tile
    //
    // @return Color topcolor_ if type is '\'
    // @return Color notTopColor() if type is '+' or '/'
    //
    Color getColorRight();

    //--------------------------------------------------------------------------
    // getColorTop method
    // Gets the top color of a tile
    //
    // @return Color getColor()
    //
    Color getColorTop();

    //--------------------------------------------------------------------------
    // getColorBottom method
    // Gets the bottom color of a tile
    //
    // @return Color topcolor_ if type is '+'
    // @return Color notTopColor() if type is '/' or '\'
    //
    Color getColorButtom();

    //--------------------------------------------------------------------------
    // getRedId method
    // Gets the red id of a tile
    //
    // @return int red_id_
    //
    int getRedId();

    //--------------------------------------------------------------------------
    // getWhiteId method
    // Gets the white id of a tile
    //
    // @return int white_id_
    //
    int getWhiteId();

    //--------------------------------------------------------------------------
    // getId method
    // gets a color id of a tile
    //
    // @param std::string color "white" or "red"
    //
    // @return int id of the color(depend on input)
    //
    int getId(std::string color);


    int getPlayerColor();

    //--------------------------------------------------------------------------
    // Operator Methods
    //

    //--------------------------------------------------------------------------
    // operator== method
    // Used to compare two tiles on equality
    //
    // @param Tile the tile with which the other tile is to be compared
    //
    // @return bool true if tile matches
    //
    virtual bool operator==(const Tile&) const;

    //--------------------------------------------------------------------------
    // operator!= method
    // Used to compare two tiles on inequality
    //
    // @param Tile the tile with which the other tile is to be compared
    //
    // @return bool true if tile does not match
    //
    virtual bool operator!=(const Tile&) const;

    //--------------------------------------------------------------------------
    // notTopColor method
    // Returns the color which is not the top color
    //
    // @return Color COLOR_WHITE if top color is red
    // @return Color COLOR_RED if top color is white
    // @return Color EMPTY_C if top color is empty
    //
    Color notTopColor();

    //--------------------------------------------------------------------------
    // charToType method
    // returns the type for the char
    //
    // @return Type TYPE_CURVE_1 if '/'
    // @return Type TYPE_CROSS if '+'
    // @return Type TYPE_CURVE_2 if '\'
    // @return Type EMPTY_T for default
    //
    Type charToType(char c);



    //--------------------------------------------------------------------------
    // Get Output Methods
    //
    std::string getColorOut();
    std::string getTypeOut();
    std::string getPlayerColorOut();
};
#endif // TILE_H