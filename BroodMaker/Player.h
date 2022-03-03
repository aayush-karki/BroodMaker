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
			float a_boardPosX = 0.f, float a_boardPosY = 0.f,
			float a_tileWidth = 0.f, float a_tileLength = 0.f );
	// constructor when path is provided
	Player( std::list<st_path*>::iterator a_startPosIte,
			float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
			float a_boardPosX = 0.f, float a_boardPosY = 0.f,
			float a_tileWidth = 0.f, float a_tileLength = 0.f );
	void Draw( sf::RenderWindow& a_window );
	void SetRow( int a_newRow ); // setter function
	void SetCol( int a_newCol ); // setter function
	void UpdateRowNCol( int a_newRow, int a_newCol ); // updates row and col
	void SetPosition( float a_posX, float a_posY );
	void SetPosition( std::list<st_path*>::iterator a_playerCurrPathPos ); // setter function if st_path is passed
	std::list<st_path*>::iterator GetCurrPathPos() const; 
																		   // ===== private member functions =====
private:
	void InitializePlayer( int  a_playerStartRow = 0, int a_PlayerStartCol = 0,
						   float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
						   float a_boardPos = 0.f, float a_boardPosY = 0.f,
						   float a_tileWidth = 0.f, float a_tileLength = 0.f );

	// ===== private member varialbes =====
private:
	sf::RectangleShape m_playerBody; // player body

	// iterator that points to the current path node; stored for easy increment
	std::list<st_path*>::iterator m_playerCurrPathPos; 

	
	int m_currRow; // tile row where the player is
	int m_currCol; // tile col where the player is

	float m_boardPosX; // board's x-postion relative to the screen
	float m_boardPosY; // board's y-postion relative to the screen
	
	float m_tileSizeX; // tile size in x-axis
	float m_tileSizeY; // tile size in y-axis
};

// ================== definations  =================

/// 
/// @public
/// @brief  Default Constructor
/// 
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
/// 
inline Player::Player( int  a_playerStartRow, int a_PlayerStartCol,
					   float a_playerSizeX, float a_playerSizeY,
					   float a_boardPosX, float a_boardPosY,
					   float a_tileSizeX, float a_tileSizeY )
{
	InitializePlayer( a_playerStartRow, a_PlayerStartCol,
					  a_playerSizeX, a_playerSizeY,
					  a_boardPosX, a_boardPosY,
					  a_tileSizeX, a_tileSizeY );
}

/// 
/// @public
/// @brief  Constructor
/// 
/// This Constructor is called when a pointer to st_path is passed.
/// 
/// @param a_startPosIte a iterator that holds to st_path node which contains the start
///			row and column number inside it
/// @param a_playerSizeX size of the player in x-asix -> default 0.f
/// @param a_playerSizeY size of the player in y-asix -> default 0.f
/// @param a_boardPosX board's x-position on screen -> default 0.f
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
/// @param a_tileSizeX tile size in x-axis
/// @param a_tileSizeY tile size in y-axis
/// 
inline Player::Player( std::list<st_path*>::iterator a_startPosIte,
					   float a_playerSizeX, float a_playerSizeY,
					   float a_boardPosX, float a_boardPosY, 
					   float a_tileSizeX, float a_tileSizeY )
{
	m_playerCurrPathPos = a_startPosIte;

	int startRow = (*a_startPosIte )->stm_rowNum;
	int startCol = ( *a_startPosIte )->stm_colNum;

	InitializePlayer( startRow, startCol,
					  a_playerSizeX, a_playerSizeY,
					  a_boardPosX, a_boardPosY,
					  a_tileSizeX, a_tileSizeY);
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
/// @brief Sets  the col and row the player is in
/// 
/// @param a_newRow new row where the player is in
/// @param a_newCol new col where the player is in
/// 
inline void Player::UpdateRowNCol( int a_newRow, int a_newCol )
{
	SetRow( a_newRow );
	SetCol( a_newCol );
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

/// 
/// @public
/// @brief Getter function to get the iterator to 
///		list that points to currPath pos
/// 
/// @return iterator to 
///		list that points to currPath pos
inline std::list<st_path*>::iterator Player::GetCurrPathPos() const
{
	return m_playerCurrPathPos;
}