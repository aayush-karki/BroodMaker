/*************************************************************************/
/// 
/// @file Player.cpp 
/// 
/// @brief  This file is a source file for Player class.
/// 
/// It contains all of the defination of the member 
///		funciton of Player class.
///
/************************************************************************/

#include "Player.h"

/// 
/// @public
/// @brief initializes the 
/// 
/// @param a_playerStartRow represents on which row number 
///			the player starts -> default 0
/// @param a_PlayerStartCol represents on which column number 
///			the player starts-> default 0
/// @param a_playerSizeX size of the player in x-asix -> default 0.f
/// @param a_playerSizeY size of the player in y-asix -> default 0.f
/// @param a_boardPosX board's x-position on screen -> default 0.f
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
/// @param a_tileSizeX tile size in x-axis
/// @param a_tileSizeY tile size in y-axis
void Player::InitializePlayer( int a_playerStartRow, int a_PlayerStartCol, 
							   float a_playerSizeX, float a_playerSizeY, 
							   float a_boardPosX, float a_boardPosY,
							   float a_tileSizeX, float a_tileSizeY)
{
	// setting the boardPos 
	this->m_boardPosX = a_boardPosX;
	this->m_boardPosY = a_boardPosY;

	// setting the tile width and length
	this->m_tileSizeX = a_tileSizeX;
	this->m_tileSizeY = a_tileSizeY;

	this->m_playerBody.setSize( sf::Vector2f( a_playerSizeX, a_playerSizeY ) );
	this->m_playerBody.setFillColor( sf::Color::White );

	// setting theposition 
	float xPos = m_currCol * m_tileSizeY + m_boardPosX;
	float yPos = m_currRow * m_tileSizeX + m_boardPosY;

	SetPosition( xPos, yPos ); // calling member funcition
}

/// 
/// @brief setter function if st_path is passed
/// @param a_playerCurrPathPos  iterator that points to the current path node
/// 
void Player::SetPosition( std::list<st_path*>::iterator a_playerCurrPathPos )
{
	m_playerCurrPathPos = a_playerCurrPathPos;
	// updating row and col
	m_currRow = ( *a_playerCurrPathPos )->stm_rowNum;
	m_currCol = ( *a_playerCurrPathPos )->stm_colNum;

	// calculating the position
	float xPos = m_currCol * m_tileSizeY + m_boardPosX;
	float yPos = m_currRow * m_tileSizeX + m_boardPosY;

	SetPosition( xPos, yPos ); // calling member funcition
}

