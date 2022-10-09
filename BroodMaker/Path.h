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
/// @brief Path is a wraper for tile class
/// 
/// It stores a pointer to a tile and other information necessary
/// 
///
class Brood::Application::Components::Path
{
	// =============== public member function ===================
public:
	//default constructor
	Path( Brood::Application::Components::Tiles* a_tilePtr = nullptr,
		  Brood::Application::Components::Deck* a_deckPtr = nullptr,
		  Brood::Application::Components::ENUM_TileType a_tileType = Brood::Application::Components::ENUM_TileType::TILE_blank );

	// destructor
	~Path();

	// copy constructor
	Path( const Path& a_otherPath );

	// assignment operator
	Path& operator=( const Path& a_otherPath );

	// initialize the path
	void InitializePath( Brood::Application::Data::ST_PathPrefabData& a_pathData,
						 Brood::Application::Components::Path* a_nextPathPtr,
						 Brood::Application::Components::Path* a_bridgeEndPathPtr,
						 Brood::Application::Components::Deck* a_deckPtr );

	// returns the path data to save 
	Brood::Application::Data::ST_PathPrefabData GetDataToSave();

	// ======= getter funciton ===========

	// getter funciton to get the tile type of the tile
	Brood::Application::Components::ENUM_TileType GetTileType();

	// Getter funciton to get the pointer to the tile
	Brood::Application::Components::Tiles* GetTilePtr();

	// Getter funciton to get the pointer to the tile
	const Brood::Application::Components::Tiles* GetTilePtr() const;

	// getter funciton to get the pointer to the next path 
	Brood::Application::Components::Path* GetNextPathPtr();

	// getter funciton to get the pointer to the previous path 
	Brood::Application::Components::Path* GetPreviouPathPtr();

	// getter funciton to get the pointer to the bridge end path 
	Brood::Application::Components::Path* GetBridgeEndPathPtr();

	// getter function to get the player list pointer
	const std::vector<Brood::Application::Components::Player*>& GetPlayerListPtr() const;

	// getter function to get the deck pointer
	const Brood::Application::Components::Deck* GetDeckPtr() const;

	// getter funciton to get the index of the assingned deck
	unsigned GetDeckIdx();

	// Getter funciton to get the number of card to be drawn
	unsigned GetNumCardDraw();

	// getter funciton to get force dice roll
	bool GetForceDiceRoll();

	// gets the center point of the tile
	sf::Vector2f GetTileCenter();

	// gets the draw line var
	bool GetDrawLine();

	// ======= setter funciton ===========

	// Setter funciton to Set the tile type of the tile
	void SetTileType( Brood::Application::Components::ENUM_TileType a_tileType );

	// setter funciton to set the pointer to the tile
	void SetTilePtr( Brood::Application::Components::Tiles* a_tilePtr );

	// Setter funciton to Set the pointer to the next path 
	void SetNextPathPtr( Brood::Application::Components::Path* a_nextPathPtr );

	// Setter funciton to Set the pointer to the previous path 
	void SetPreviouPathPtr( Brood::Application::Components::Path* a_previousPathPtr );

	// Setter funciton to Set the pointer to the bridge end path 
	void SetBridgeEndPathPtr( Brood::Application::Components::Path* a_bridgeEndPathPtr );

	// setter funciton to set the pointer to the deck
	void SetDeckPtr( Brood::Application::Components::Deck* a_deckPtr );

	// Setter funciton to Set the index of the assingned deck
	void SetDeckIdx( unsigned a_deckIdx );

	// Setter funciton to Set the number of card to be drawn
	void SetNumCardDraw( unsigned a_numCardDraw );

	// Setter funciton to Set force dice roll
	void SetForceDiceRoll( bool a_diceRoll );

	// toggles the the draw line var
	void ToggleDrawLine();

	// add player to its list
	bool AddPlayerToList( Brood::Application::Components::Player* a_playerPtr );

	// deletes the player from its player list
	bool DeletePlayerFromList( Brood::Application::Components::Player* a_playerPtr );

	// updates path line
	void UpdatePathLines();

	// draws the tile
	void Draw( sf::RenderWindow& a_window );

	// draws the tile
	void DrawPath( sf::RenderWindow& a_window );

	// =============== public member variable ===================
private:

	/// holds the type of the tile this path holds
	Brood::Application::Components::ENUM_TileType m_tileType;

	/// holds a tile inside of it 
	Brood::Application::Components::Tiles* m_tilePtr;

	/// holds a pointer to the next path 
	/// next path can only be one step away form the tile
	Brood::Application::Components::Path* m_nextPathPtr;

	/// holds a pointer to the previous path 
	Brood::Application::Components::Path* m_previousPathPtr;

	/// holds a pointer to the bridge end path 
	Brood::Application::Components::Path* m_bridgeEndPathPtr;

	/// list of player who are assigned to this path
	std::vector<Brood::Application::Components::Player*> m_playerPtrList;

	/// deck that is assigned to this path
	Brood::Application::Components::Deck* m_deckPtr;

	/// index of the assingned deck
	unsigned m_deckIdx;

	/// number of card that the player are forced to draw
	unsigned m_numCardDraw;

	/// forces dice roll
	bool m_forceDiceRoll;

	/// line is drawn for tile editor
	bool m_drawLine;

	/// line to the next path;
	/// this is always going to be an array of two vertex
	/// and the vertext at index 0 is midPoint of the tile
	/// and the vertext at index 1 is midPoint of the nextTile
	sf::VertexArray m_nextPathLine;

	/// line to the bridge path
	/// this is always going to be an array of two vertex
	/// and the vertext at index 0 is midPoint of the tile
	/// and the vertext at index 1 is midPoint of the nextTile
	sf::VertexArray m_bridgePathLine;
};

// ======================================================================
// ================= end of path Class ==================================
// ======================================================================

// relation operators
// overloading == operator
bool operator==( const Brood::Application::Components::Path& thisPath,
				 const Brood::Application::Components::Path& otherPath );
