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
class Tiles
{
public:
	/// 
	/// @brief Constructor
	/// 
	Tiles(int  a_tileRowNum = 0, int a_tileColNum = 0, 
		   float a_tileSizeX = 0.f, float a_tileSizeY = 0.f,
		   float a_boardPosX = 0.f, float a_boardPosY = 0.f ) 
	{
		InitializeTile( a_tileRowNum, a_tileColNum,
						a_tileSizeX, a_tileSizeY,
						a_boardPosX, a_boardPosY );
	}

	void Draw( sf::RenderWindow& a_window );

	const sf::Vector2f GetPos() const { return sf::Vector2f( m_tileColNum, m_tileRowNum ); }

private:
	// ===== private member functions =====
	void InitializeTile( int  a_tileRowNum = 0, int a_tileColNum = 0,
						 float a_tileSizeX = 0.f, float a_tileSizeY = 0.f,
						 float a_boardPosX = 0.f, float a_boardPosY = 0.f );

private:
	// ===== private member variables =====

	sf::RectangleShape m_TileBody;
	int m_tileRowNum;      // row position in a board
	int m_tileColNum;      // column position in a board
};

