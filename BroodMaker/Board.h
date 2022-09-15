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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once

#include "Tiles.h"
//#include "Player.h"
//#include "Dice.h"
//#include "PathManager.h"
//#include "PlayerManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class Board;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Board class ===============================
// ======================================================================

/// 
/// @ingroup Components
/// @class Board  "Board.h"
/// @brief A container Class to create a board
/// 
/// @note that board orgin is set in the upper left corner;
///		 which will be consistent through out the applicaiton
/// 
class Brood::Application::Components::Board
{
	// ================== public member fuction =======================
public:

	// default constructor
	Board();

	//Destructor
	~Board();
	/// @todo add copy constuctor and copy assignment

	void Draw( sf::RenderWindow& a_window );

	void InitializeBoard( unsigned  a_numRows = 0, unsigned a_numCols = 0,
						  float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
						  float a_boardPosX = 0.f, float a_boardPosY = 0.f );

	// setter funcitons
	void SetNumRow( unsigned a_numRows );
	void SetNumCol( unsigned a_numCols );
	void SetBoardSize( sf::Vector2f a_boardSize );
	void SetBoardSize( float a_boardSizeX, float a_boardSizeY );
	void SetBoardPos( sf::Vector2f a_boardPos );
	void SetBoardPos( float a_boardPosX, float a_boardPosY );
	void Debugger(); // debugger

	//Brood::Dice& GetDice(); // getter funciton 
	//void Update();
	//void PlayerRollAndMove( );
	//void AddPlayer( float a_playerSizeX = 0.f, float a_playerSizeY = 0.f, int a_playerStartRow = 0, int a_playerStartCol = 0 );


	// ========== private member functions ===============
private:

	// increases the number of row and populates it
	void IncreaseNumRow( unsigned a_numRows );

	// decrease the number of row
	void DecreaseNumRow( unsigned a_numRows );

	// increases the number of col and populates it
	void IncreaseNumCol( unsigned a_numCols );

	// decrease the number of col
	void DecreaseNumCol( unsigned a_numCols );

	// updates the tile in board by using the member variables
	void UpdateBoardTiles( unsigned a_rowBegin, unsigned a_rowEnd,
						   unsigned a_colBegin, unsigned a_colEnd,
						   bool a_createNew = false );

	// ========== private member varibles ===============
private:

	///> main board
	sf::RectangleShape m_boardBody;

	///> number of cell rows in the board
	unsigned m_numRows;

	///> number of cell columns in the board
	unsigned m_numCols;

	///> contains the board tiles
	std::vector<std::vector<Tiles*>> m_boardTiles;

	//PathManager m_pathsList; // contains the path of the game
	//PlayerManager m_playerManger; // contains all the player in the game

	//Brood::Dice m_dice; // dice obj
};


