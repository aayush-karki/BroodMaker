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
class Board
{
public:
	/// 
	/// @brief Constructor for a board object
	/// 
	/// @param a_numCols number of cell cols
	/// @param a_numRows number of cell rows
	/// 
	Board(int a_numCols = 0, int a_numRows = 0) {}


private:
	// private member varibles

	sf::RectangleShape m_boardBody;  // main board
	int m_numCols; // number of cell columns in the board
	int m_numRows; // number of cell rows in the board

	std::vector<std::vector<Tiles>> BoardTiles; // contains the board tiles
	std::vector<Player> AllPlayers; // contains all the player playing the game
};

