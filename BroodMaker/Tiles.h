/*************************************************************************/
/// 
/// @file Tiles.h 
/// 
/// @brief  This file is a header file for Tiles class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Tiles class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Tiles class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

///
/// @class Tiles  "Tiles.h"
/// 
/// @brief Class to make a tiles that make a board.  
/// 
/// Board Tiles are the basic building block of the board.
///		This class  provides the functionality to alter and customize 
///		the tiles. Thus give the ability to coustomizing the whole board
/// 
/// @todo: see if you want to make board a part of a tile or a board
/// 
class Tiles
{
	// =============== public member functions =================
public:
	
	// default constructor
	Tiles( int  a_tileRowNum = 0, int a_tileColNum = 0,
		   float a_tileSizeX = 0.f, float a_tileSizeY = 0.f,
		   float a_boardPosX = 0.f, float a_boardPosY = 0.f );
	
	/// @todo add destructor, copy constructor and assignment
	
	void Draw( sf::RenderWindow& a_window );
	const sf::Vector2f GetPos() const;

	// ===== private member functions =====
private:
	void InitializeTile( int  a_tileRowNum = 0, int a_tileColNum = 0,
						 float a_tileSizeX = 0.f, float a_tileSizeY = 0.f,
						 float a_boardPosX = 0.f, float a_boardPosY = 0.f );

	// ===== private member variables =====
private:

	sf::RectangleShape m_TileBody; // body
	int m_tileRowNum;      // row position in a board
	int m_tileColNum;      // column position in a board
};

// ==================== definations =========================

/// 
/// @public
/// @brief Default Constructor
/// 
/// @param a_tileRowNum represents row number of the board -> default 0
/// @param a_tileColNum represents column of the board  -> default 0
/// @param a_tileSizeX size of each tile in x-asix -> default 0.f
/// @param a_tileSizeY size of each tile in y-asix -> default 0.f
/// @param a_boardPosX board's x-position on screen -> default 0.f
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
/// 
inline Tiles::Tiles( int  a_tileRowNum, int a_tileColNum,
	   float a_tileSizeX, float a_tileSizeY ,
	   float a_boardPosX, float a_boardPosY)
{
	InitializeTile( a_tileRowNum, a_tileColNum,
					a_tileSizeX, a_tileSizeY,
					a_boardPosX, a_boardPosY );
}


/// 
/// @public
/// @brief 
/// @return 
inline const sf::Vector2f Tiles::GetPos() const
{
	return sf::Vector2f( m_tileColNum, m_tileRowNum ); 
}
