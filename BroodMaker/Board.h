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
#include "GlobalVariables.h"
#include "Path.h"

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
	Board( unsigned  a_numRows = 1, unsigned a_numCols = 1,
		   float a_boardSizeX = 50.f, float a_boardSizeY = 50.f,
		   float a_boardPosX = 50.f, float a_boardPosY = 50.f );

	//Destructor
	~Board();
	/// @todo add copy constuctor and copy assignment

	void Draw( sf::RenderWindow& a_window );

	// initialize the board
	void InitializeBoard( unsigned  a_numRows = 0, unsigned a_numCols = 0,
						  float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
						  float a_boardPosX = 0.f, float a_boardPosY = 0.f );

	// ===== setter funcitons ==== 

	// setter function to set the nubmer of rows in the board
	void SetNumRow( unsigned a_numRows, Brood::Application::Components::Deck* a_deckPtr );

	// setter function to set the nubmer of coulumns in the board
	void SetNumCol( unsigned a_numCols, Brood::Application::Components::Deck* a_deckPtr );

	// setter function to set the board size
	void SetBoardSize( sf::Vector2f a_boardSize );

	// setter function to set the board size
	void SetBoardSize( float a_boardSizeX, float a_boardSizeY );

	// setter function to set the board position
	void SetBoardPos( sf::Vector2f a_boardPos );

	// setter function to set the board position
	void SetBoardPos( float a_boardPosX, float a_boardPosY );

	// getter function to get the currentActiveTile
	void SetCurrentActiveTilePtr( Brood::Application::Components::Path* a_newActivePathPtr );

	// ===== getter funcitons ==== 

	// getter function to get the nubmer of rows in the board
	const unsigned GetNumRow() const;

	// getter function to get the nubmer of coulumns in the board
	const unsigned GetNumCol() const;

	// getter function to get the board size
	const sf::Vector2f GetBoardSize() const;

	// getter function to get the board position
	const sf::Vector2f GetBoardPos() const;

	// getter function to get the board path list
	const std::vector<std::vector<Brood::Application::Components::Path*>>& GetBoardPathList() const;

	// getter function to get the currentActive path
	Brood::Application::Components::Path* GetCurrentActivePath();

	// toggles the draw line for all the paths 
	void ToggleDrawLine();

	void Debugger(); // debugger

	//Brood::Dice& GetDice(); 
	//void Update();
	//void PlayerRollAndMove( );
	//void AddPlayer( float a_playerSizeX = 0.f, float a_playerSizeY = 0.f, int a_playerStartRow = 0, int a_playerStartCol = 0 );


	// ========== private member functions ===============
private:

	// increases the number of row and populates it
	void IncreaseNumRow( unsigned a_numRows, Brood::Application::Components::Deck* a_deckPtr );

	// decrease the number of row
	void DecreaseNumRow( unsigned a_numRows );

	// increases the number of col and populates it
	void IncreaseNumCol( unsigned a_numCols, Brood::Application::Components::Deck* a_deckPtr );

	// decrease the number of col
	void DecreaseNumCol( unsigned a_numCols );

	// updates the tile in board by using the member variables
	void UpdateBoardPath( unsigned a_rowBegin, unsigned a_rowEnd,
						   unsigned a_colBegin, unsigned a_colEnd,
						   bool a_createNew = false,
						  Brood::Application::Components::Deck* a_deckPtr = nullptr);

	// ========== private member varibles ===============
private:

	/// main board
	sf::RectangleShape m_boardBody;

	/// number of cell rows in the board
	unsigned m_numRows;

	/// number of cell columns in the board
	unsigned m_numCols;

	/// contains the board Path whic in turn contains tile
	std::vector<std::vector<Brood::Application::Components::Path*>> m_boardPaths;

	/// holds the pointer ot the current active path
	///		used by the tile editor
	Brood::Application::Components::Path* m_currActivePathPtr;
};

// ======================================================================
// ================= end of Brood class =================================
// ======================================================================

