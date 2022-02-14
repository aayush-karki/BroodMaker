/*************************************************************************/
/// 
/// @file Tiles.cpp 
/// 
/// @brief  This file is a source file for Tiles class.
/// 
/// It contains the defininaiton of the member 
///		funciton of Tiles class.
/// 
/************************************************************************/
#include "Tiles.h"

void Tiles::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_TileBody );
}

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
	this->m_TileBody.setFillColor( sf::Color::Green );

}
