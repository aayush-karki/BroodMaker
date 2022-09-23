/*************************************************************************/
/// 
/// @file Tiles.h 
/// 
/// @brief  This file is a header file for Tiles class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Tiles class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Tiles class
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "Button.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	///
	/// @ingroup Application
	/// @addtogroup Components
	/// 
	namespace Components
	{
		class Tiles;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Tiles class ===============================
// ======================================================================

/// 
/// @ingroup Components
/// @class Tiles  "Tiles.h"
/// 
/// @brief building block of a borad.
/// 
/// Tiles are the basic building block of the board.
///		This class  provides the functionality to alter and customize 
///		each tiles. Thus give the ability to coustomizing the whole board.
/// 
/// Derived from Button Class
/// 
/// Setting up a tile is similar to seting up a button. But as the tile
///		is used as a building bock for a board it has tile row and 
///		tile nubmer. For more informantion @see Brood::BroodUI::Button class.
///  
class Brood::Application::Components::Tiles : public Brood::BroodUI::Button
{
	// =============== public member functions =================
public:
	
	// default constructor and destructors
	Tiles();
	~Tiles();

	// copy constructor
	Tiles( const Tiles& a_otherTile);
	
	/// @todo add copy constructor and assignment

	// getter function
	const sf::Vector2u GetRowAndCol() const; 
	const unsigned GetRow() const;
	const unsigned GetCol() const;

	// setter funciton 
	void SetRowAndCol(sf::Vector2u a_rowCol );
	void SetRow(unsigned a_row);
	void SetCol( unsigned a_col ); 
	
	// Populates the member variable and sets the position and size of the
	// tile
	void UpdateTile( unsigned  a_tileRowNum = 0, unsigned a_tileColNum = 0,
						 float a_tileSizeX = 0.f, float a_tileSizeY = 0.f,
						 float a_boardPosX = 0.f, float a_boardPosY = 0.f );

	// ===== private member variables =====
private:
	// row position in a board
	unsigned m_tileRowNum;      
	
	// column position in a board
	unsigned m_tileColNum;      
};

// ======================================================================
// ================= end of Tiles class =================================
// ======================================================================