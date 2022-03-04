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
#include "Dice.h"
#include "PathManager.h"
#include "PlayerManager.h"

#include "Struct_path.h"
#include "Struct_CtorParam.h"

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
	// ================== public member fuction =======================
public: 

	// default constroctor
	Board( int a_numRows = 0, int a_numCols = 0,
		   float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
		   float a_boardPosX = 0.f, float a_boardPosY = 0.f );
	Board( St_BoardParam* a_StBoardInializer, St_DiceParam* a_StDiceInializer );
	~Board(); //Destructor
	/// @todo add copy constuctor and copy assignment
	void Draw( sf::RenderWindow& a_window );
	Dice& GetDice(); // getter funciton 
	void PlayerRollAndMove( );
	void AddPlayer( float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
					int a_playerStartRow = 0, int a_playerStartCol = 0 );
	

	// ===== private member functions =====
private:
	void InitializeBoard( int  a_numRows = 0, int a_numCols = 0,
						 float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
						 float a_boardPosX = 0.f, float a_boardPosY = 0.f );
	
	// ========== private member varibles ===============
private:

	sf::RectangleShape m_boardBody;  // main board

	int m_numRows; // number of cell rows in the board
	int m_numCols; // number of cell columns in the board
	
	float m_boardPosX; // board's x-postion relative to the screen
	float m_boardPosY; // board's y-postion relative to the screen
	
	
	std::vector<std::vector<Tiles*>> m_boardTiles; // contains the board tiles

	PathManager m_pathsList; // contains the path of the game
	PlayerManager m_playerManger; // contains all the player in the game

	Dice m_dice; // dice obj
};


// ================== definations  =================

/// 
/// @public
/// @brief default Constructor
/// 
/// Inializes the board
/// 
/// @param a_numRows number of tile rows in a board -> default 0
/// @param a_numCols number of tile columns in a board-> default 0
/// @param a_boardSizeX  board's width -> default 0.f
/// @param a_boardSizeY board's length -> default 0.f
/// @param a_boardPosX board's x-position on screen; 
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
///  
inline Board::Board( int a_numRows, int a_numCols,
					 float a_boardSizeX, float a_boardSizeY,
					 float a_boardPosX, float a_boardPosY ):
	m_pathsList(a_numRows, a_numCols), m_playerManger(nullptr, &m_pathsList )
{
	InitializeBoard( a_numRows, a_numCols, 
					 a_boardSizeX, a_boardSizeY,
					 a_boardPosX, a_boardPosY );
}

/// 
/// @public
/// @brief Constructor
/// @param a_StBoardInializer pointer to structure that contains parameter that board 
///		constructor needs
/// @param a_StDiceInializer pointer to structure that contains parameter that board 
///		constructor needs
/// 
inline Board::Board( St_BoardParam* a_StBoardInializer, St_DiceParam* a_StDiceInializer ) : 
	m_pathsList( a_StBoardInializer->stm_numRows, a_StBoardInializer->stm_numCols ),
	m_dice( a_StDiceInializer ), m_playerManger(a_StBoardInializer, &m_pathsList)
{
	InitializeBoard( a_StBoardInializer->stm_numRows, a_StBoardInializer->stm_numCols,
					 a_StBoardInializer->stm_boardSizeX, a_StBoardInializer->stm_boardSizeY,
					 a_StBoardInializer->stm_boardPosX, a_StBoardInializer->stm_boardPosY );
}

/// 
/// @public
/// @brief Getter function 
/// @return a const reference to the dice member variable
inline Dice& Board::GetDice()
{
	return m_dice;
}

/// 
/// @public
/// @brief incapsulate the player Manager addNewPlayer
/// 
inline void Board::AddPlayer( float a_playerSizeX, float a_playerSizeY,
							  int a_playerStartRow, int a_playerStartCol )
{
	m_playerManger.AddNewPlayer( a_playerSizeX, a_playerSizeY,
								 a_playerStartRow, a_playerStartCol );
}
