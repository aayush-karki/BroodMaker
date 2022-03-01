/*************************************************************************/
/// 
/// @file Player.h 
/// 
/// @brief  This file is a header file for Player class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Player class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Player class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

#include "Struct_path.h"

///
/// @class Player  "Player.h"
/// 
/// @brief A Player Class
/// 
class Player
{
	// ================== public member fuction =======================
public:
	// Default Constructor
	Player( int  a_playerStartRow = 0, int a_PlayerStartCol = 0,
			float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
			float a_boardPosX = 0.f, float a_boardPosY = 0.f );
	// constructor when start is in path
	Player( st_path *a_startPos,
			float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
			float a_boardPosX = 0.f, float a_boardPosY = 0.f );
	void Draw( sf::RenderWindow& a_window );
	void SetRow( int a_newRow ); // setter function
	void SetCol( int a_newCol ); // setter function
	void SetPosition( float a_posX, float a_posY ); // setter function

	// ===== private member functions =====
private:
	void InitializePlayer( int  a_playerStartRow = 0, int a_PlayerStartCol = 0,
						   float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
						   float a_boardPosX = 0.f, float a_boardPosY = 0.f );

	// ===== private member varialbes =====
private:
	sf::RectangleShape m_playerBody; // player body
	int m_currRow; // tile row where the player is
	int m_currCol; // tile col where the player is

	//std::list<st_path*>::iterator m_playerTile ;
};

// ================== definations  =================

/// 
/// @public
/// @brief Default Constructor
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
inline Player::Player( int a_playerStartRow, int a_PlayerStartCol,
					   float a_playerSizeX, float a_playerSizeY, 
					   float a_boardPosX, float a_boardPosY )
{
	InitializePlayer( a_playerStartRow, a_PlayerStartCol,
					  a_playerSizeX, a_playerSizeY,
					  a_boardPosX, a_boardPosY );
}

/// 
/// @public
/// @brief  Constructor
/// 
/// This Construc is called when a pointer to st_path is passed.
/// 
/// @param a_startPos a pointer to st_path node which contains the start
///			row and column number inside it
/// @param a_playerSizeX size of the player in x-asix -> default 0.f
/// @param a_playerSizeY size of the player in y-asix -> default 0.f
/// @param a_boardPosX board's x-position on screen -> default 0.f
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
/// 
inline Player::Player( st_path *a_startPos, float a_playerSizeX, float a_playerSizeY, float a_boardPosX, float a_boardPosY )
{
	int startRow = a_startPos->stm_rowNum;
	int startCol = a_startPos->stm_colNum;

	InitializePlayer( startRow, startCol,
					  a_playerSizeX, a_playerSizeY,
					  a_boardPosX, a_boardPosY );
}

/// 
/// @public
/// @brief Draw funciton draws tiles to the screen.
///			
/// @param a_window reference to the render window
/// 
inline void Player::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_playerBody );
}

/// 
/// @public
/// @brief Setter funciton to set the row the player is in
/// 
/// @param a_newRow new row where the player is in
/// 
inline void Player::SetRow( int a_newRow )
{
	this->m_currRow = a_newRow;
}

/// 
/// @public
/// @brief Setter funciton to set the col the player is in
/// 
/// @param a_newCol new col where the player is in
/// 
inline void Player::SetCol( int a_newCol )
{
	this->m_currCol = a_newCol;
}

/// 
/// @public
/// @brief Setter funciton to set the player positon 
/// 
/// @param a_posX position in x-asix
/// @param a_posY position in y-asix
inline void Player::SetPosition( float a_posX, float a_posY )
{
	m_playerBody.setPosition( a_posX, a_posY );
}
