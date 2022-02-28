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
///  
void Player::InitializePlayer( int a_playerStartRow, int a_PlayerStartCol, 
							   float a_playerSizeX, float a_playerSizeY, 
							   float a_boardPosX, float a_boardPosY )
{
	this->m_playerBody.setSize( sf::Vector2f( a_playerSizeX, a_playerSizeY ) );
	this->m_playerBody.setPosition( a_boardPosX, a_boardPosY );
	this->m_playerBody.setFillColor( sf::Color::White );

	//m_playerTile = nullptr;
}
