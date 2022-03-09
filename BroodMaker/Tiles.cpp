/*************************************************************************/
/// 
/// @file Tiles.cpp 
/// 
/// @brief  This file is a source file for Tiles class.
/// 
/// It contains the definaiton of the member 
///		funcitons of Tiles class.
/// 
/************************************************************************/
#include "stdafx.h"
#include "Tiles.h"

/// 
/// @private
/// @brief sets up a tile
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
void Tiles::InitializeTile( int a_tileRowNum, int a_tileColNum, float a_tileSizeX,
							float a_tileSizeY, float a_boardPosX, float a_boardPosY )
{
	// setting up the column and row number
	this->m_tileRowNum = a_tileRowNum;
	this->m_tileColNum = a_tileColNum;

	// setting up the body
	this->m_TileBody.setSize( sf::Vector2f( a_tileSizeX, a_tileSizeY ) );
	this->m_TileBody.setPosition( a_boardPosX + a_tileColNum * a_tileSizeX,
								  a_boardPosY + a_tileRowNum * a_tileSizeY );
	/// @todo currently tiles are of random color
	this->m_TileBody.setFillColor( sf::Color( std::rand() % 256, std::rand() % 256, std::rand() % 256 ) );

}
