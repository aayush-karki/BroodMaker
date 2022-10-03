/*************************************************************************/
/// 
/// @file WorkSpace.cpp 
/// 
/// @brief  This file is a source file for WorkSpace class
/// 
/// It also contains all of the declaration of the WorkSpace class's
///		member function.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Path.h"

// ======================================================================
// ================= start of path class ================================
// ======================================================================

/// 
/// @public
/// @brief default constructor
/// 
/// @param a_tilePtr pointer to a tile
/// 
Brood::Application::Components::Path::Path( Brood::Application::Components::Tiles* a_tilePtr )
	: m_tilePtr( a_tilePtr == nullptr ? new Brood::Application::Components::Tiles() : a_tilePtr )
{}

/// 
/// @public
/// @brief destuctor
/// 
Brood::Application::Components::Path::~Path()
{
	delete m_tilePtr;
}

///
/// @public 
/// @brief copy constructor
/// 
/// @param otherPath reference to the the path 
///			object that is being copied from 
/// 
Brood::Application::Components::Path::Path( const Path& otherPath )
{
	delete m_tilePtr;
	this->m_tilePtr = new  Brood::Application::Components::Tiles();
}

///
/// @public 
/// @brief assignmnet operator
/// 
/// @param otherPath reference to the the path 
///			structue that is being copied from 
/// 
Brood::Application::Components::Path& Brood::Application::Components::Path::operator=( const Path& otherPath )
{
	// checking for self assignment
	if( this == &otherPath )
	{
		return *this;
	}

	this->m_tilePtr = otherPath.m_tilePtr;

	return *this;
}

/// 
/// @public
/// @brief Getter funciton to get the pointer to the tile
/// 
/// @return pointer to the tile
///
Brood::Application::Components::Tiles* Brood::Application::Components::Path::GetTilePtr()
{
	return m_tilePtr;
}

/// 
/// @public
/// @brief Getter funciton to get the pointer to the tile
/// 
/// @return pointer to the tile
/// 
const Brood::Application::Components::Tiles* Brood::Application::Components::Path::GetTilePtr() const
{
	return m_tilePtr;
}

/// 
/// @public
/// @brief Getter funciton to get the pointer to the deck
/// 
/// @return pointer to the deck
///
const Brood::Application::Components::Deck* Brood::Application::Components::Path::GetDeckPtr() const
{
	return m_deckPtr;
}


/// 
/// @public
/// @brief Getter funciton to get a referebce to the player list
/// 
/// @return const reference to the player list
///
const std::vector<Brood::Application::Components::Player*>& Brood::Application::Components::Path::GetPlayerListPtr() const
{
	return m_playerPtrList;
}

/// 
/// @public
/// @brief Setter funciton to set the pointer to the tile
/// 
/// @param a_tilePtr pointer to the tile
/// 
void Brood::Application::Components::Path::SetTilePtr( Brood::Application::Components::Tiles* a_tilePtr )
{
	m_tilePtr = a_tilePtr;
}

bool Brood::Application::Components::Path::SetDeckPtr( Brood::Application::Components::Deck* a_deckPtr )
{
	if( a_deckPtr == m_deckPtr )
	{
		return false;
	}

	Brood::Application::Components::Deck* tempDeckPtr = m_deckPtr;

	// the deck ptr is null
	m_deckPtr = a_deckPtr;

	// removing the path form the deck's list
	//m_deckPtr->
}

/// 
/// @public
/// @brief adds the player from to the player list
/// 
/// @param a_playerPtr pointer to the player which is to be added
///		from the list
/// 
/// @return true if the addition was successfull
/// 
bool Brood::Application::Components::Path::AddPlayerToList( Brood::Application::Components::Player* a_playerPtr )
{
	// checking if the passed player exist in the list
	std::vector<Brood::Application::Components::Player*>::iterator currIte = m_playerPtrList.begin();
	while( currIte != m_playerPtrList.end() )
	{
		if( *currIte == a_playerPtr )
		{
			break;
		}

		++currIte;
	}

	if( currIte != m_playerPtrList.end() )
	{
		// player already exist in the list
		return false;
	}

	// adding the player from the list
	m_playerPtrList.push_back(a_playerPtr);

	return true;
}

/// 
/// @public
/// @brief deletes the player from its list and set's the player
///		tile pointer to nullptr
/// 
/// @param a_playerPtr pointer to the player which is to be deleted
///		from the list
/// 
/// @return true if the deletion was successfull
/// 
bool Brood::Application::Components::Path::DeletePlayerFromList( Brood::Application::Components::Player* a_playerPtr )
{
	// checking if the passed player exist in the list
	std::vector<Brood::Application::Components::Player*>::iterator currIte = m_playerPtrList.begin();

	while( currIte != m_playerPtrList.end() )
	{
		if( *currIte == a_playerPtr )
		{
			break;
		}

		++currIte;
	}

	if( currIte == m_playerPtrList.end() )
	{
		// player does not exist in the list
		return false;
	}

	// player exist in the list.

	// removing the player from the list
	*currIte = nullptr;
	m_playerPtrList.erase( currIte );


	return true;
}

/// 
/// @public
/// @brief Draw funciton draws the tile to the screen
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::Components::Path::Draw( sf::RenderWindow& a_window )
{
	m_tilePtr->Draw( a_window );
}

/// 
/// @public
/// @brief overloading the == operator
/// 
/// @param thisPath reference to st_path structure which is on left side of the == operator
/// @param otherPath reference to st_path structure which is on right side of the == operator
/// @return 
bool operator==( const Brood::Application::Components::Path& thisPath,
				 const Brood::Application::Components::Path& otherPath )
{
	return ( &thisPath == &otherPath );
}

// ======================================================================
// ================= end of Path class ==================================
// ======================================================================