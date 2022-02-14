/*************************************************************************/
/// 
/// @file Board.h 
/// 
/// @brief  This file is a header file for Board class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Board class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Board class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

#include "Tiles.h"
#include "Player.h"

///
/// @class Board  "Board.h"
/// @brief A container Class that holds the component that make the 
///		Board.  
/// 
/// The uses is mainly interacting with this class to access the funcitons
/// 
/// @note that board orgin is set in the upper left corner;
///		 which will be consistent through out the applicaiton
/// 
class Board
{
public:
	/// 
	/// @brief Constructor for a board object
	/// 
	/// @param a_numCols number of cell cols
	/// @param a_numRows number of cell rows
	/// 
	Board( int a_numRows = 0, int a_numCols = 0,
		   float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
		   float a_boardPosX = 0.f, float a_boardPosY = 0.f )
	{
		InitializeBoard( a_numRows, a_numCols, a_boardSizeX, a_boardSizeY,
						a_boardPosX, a_boardPosY );
	}
	/// 
	/// @brief Destructor
	~Board();

	void Draw( sf::RenderWindow& a_window );

private:
	// ===== private member functions =====
	void InitializeBoard( int  a_numRows = 0, int a_numCols = 0,
						 float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
						 float a_boardPosX = 0.f, float a_boardPosY = 0.f );

private:
	// private member varibles

	sf::RectangleShape m_boardBody;  // main board
	int m_numRows; // number of cell rows in the board
	int m_numCols; // number of cell columns in the board

	std::vector<std::vector<Tiles*>> m_boardTiles; // contains the board tiles
	std::vector<Player*> m_llPlayers; // contains all the player playing the game
};

