/*************************************************************************/
/// 
/// @file Struct_path.h 
/// 
/// @brief  This file is a header file for st_path structure.
/// 
/// It contains all of the declaration of the member 
///		funciton of st_path structure
/// It contains all of the inline funcitons defination of 
///		the member funciton of st_path structure
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "Tiles.h"
#include "Player.h"
#include "Deck.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class Path;
		class Player;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of path class ================================
// ======================================================================

/// 
/// @ingroup Components
/// @class Path
/// @brief Path is a node used for linkedlist.
/// 
/// This is used as a node for the path linked list. A linked list
///		 for the path is necessary to conver the 2d board into
///		a liner path.
/// 
/// It stores a pointer to a tile
/// 
///
class Brood::Application::Components::Path
{
	// =============== public member function ===================
public:
	//default constructor
	Path( Brood::Application::Components::Tiles* a_tilePtr = nullptr );

	// destructor
	~Path();

	// copy constructor
	Path( const Path& a_otherPath );

	// assignment operator
	Path& operator=( const Path& a_otherPath );

	// Getter funciton to get the pointer to the tile
	Brood::Application::Components::Tiles* GetTilePtr();

	// Getter funciton to get the pointer to the tile
	const Brood::Application::Components::Tiles* GetTilePtr() const;

	// getter function to get the deck pointer
	const Brood::Application::Components::Deck* GetDeckPtr() const;

	// getter function to get the player list pointer
	const std::vector<Brood::Application::Components::Player*>& GetPlayerListPtr() const;

	// setter funciton to set the pointer to the tile
	void SetTilePtr( Brood::Application::Components::Tiles* a_tilePtr );

	// setter funciton to set the pointer to the deck
	bool SetDeckPtr( Brood::Application::Components::Deck* a_deckPtr );

	// add player to its list
	bool AddPlayerToList( Brood::Application::Components::Player* a_playerPtr );

	// deletes the player from its player list
	bool DeletePlayerFromList( Brood::Application::Components::Player* a_playerPtr );

	// draws the tile
	void Draw( sf::RenderWindow& a_window );

	// =============== public member variable ===================
private:
	// 
	Brood::Application::Components::Tiles* m_tilePtr;

	// list of player who are assigned to this path
	std::vector<Brood::Application::Components::Player*> m_playerPtrList;

	// deck that is assigned to this path
	Brood::Application::Components::Deck* m_deckPtr;
};

// ======================================================================
// ================= end of path Class ==================================
// ======================================================================

// relation operators
// overloading == operator
bool operator==( const Brood::Application::Components::Path& thisPath,
				 const Brood::Application::Components::Path& otherPath );
