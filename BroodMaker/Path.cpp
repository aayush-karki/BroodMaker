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
/// @param a_tileType type of the tile; default blank
/// 
Brood::Application::Components::Path::Path( Brood::Application::Components::Tiles* a_tilePtr,
											Brood::Application::Components::Deck* a_deckPtr,
											Brood::Application::Components::ENUM_TileType a_tileType ) :
	m_tilePtr( a_tilePtr == nullptr ? new Brood::Application::Components::Tiles() : a_tilePtr ),
	m_tileType( a_tileType ), m_nextPathPtr( this ), m_previousPathPtr( this ),
	m_bridgeEndPathPtr( this ), m_deckPtr( a_deckPtr ), m_deckIdx( 0 ), m_numCardDraw(1),
	m_drawLine( false ), m_nextPathLine( sf::PrimitiveType::Lines, 2 ),
	m_bridgePathLine( sf::PrimitiveType::Lines, 2 )
{
	// assign the next path line vertex a black color
	m_nextPathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White;
	m_nextPathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// assign the bridge line vertex a black color
	m_bridgePathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_Black;
	m_bridgePathLine[ 1 ].color = m_bridgePathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// updating the path lines
	UpdatePathLines();
}

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
/// @param a_otherPath reference to the the path 
///			object that is being copied from 
/// 
Brood::Application::Components::Path::Path( const Path& a_otherPath ) :
	m_tileType( a_otherPath.m_tileType ),
	m_nextPathPtr( a_otherPath.m_nextPathPtr ),
	m_previousPathPtr( a_otherPath.m_previousPathPtr ),
	m_bridgeEndPathPtr( a_otherPath.m_bridgeEndPathPtr ),
	m_deckPtr( a_otherPath.m_deckPtr ), m_deckIdx( a_otherPath.m_deckIdx ),
	m_numCardDraw( a_otherPath.m_numCardDraw ),	m_drawLine( a_otherPath.m_drawLine ),
	m_nextPathLine( a_otherPath.m_nextPathLine ),m_bridgePathLine( a_otherPath.m_bridgePathLine )
{
	delete m_tilePtr;
	this->m_tilePtr = new  Brood::Application::Components::Tiles();

	// assign the next path line vertex a black color
	m_nextPathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White;
	m_nextPathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// assign the bridge line vertex a black color
	m_bridgePathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_Black;
	m_bridgePathLine[ 1 ].color = m_bridgePathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// updating the path lines
	UpdatePathLines();
}

///
/// @public 
/// @brief assignmnet operator
/// 
/// @param a_otherPath reference to the the path 
///			structue that is being copied from 
/// 
Brood::Application::Components::Path& Brood::Application::Components::Path::operator=( const Path& a_otherPath )
{
	// checking for self assignment
	if( this == &a_otherPath )
	{
		return *this;
	}
	delete m_tilePtr;
	this->m_tilePtr = new  Brood::Application::Components::Tiles();
	this->m_tileType = a_otherPath.m_tileType;
	this->m_nextPathPtr = a_otherPath.m_nextPathPtr;
	this->m_previousPathPtr = a_otherPath.m_previousPathPtr;
	this->m_bridgeEndPathPtr = a_otherPath.m_bridgeEndPathPtr;
	this->m_deckPtr = a_otherPath.m_deckPtr;
	this->m_deckIdx = a_otherPath.m_deckIdx;
	this->m_numCardDraw = a_otherPath.m_numCardDraw;
	this->m_drawLine = a_otherPath.m_drawLine;
	this->m_nextPathLine = a_otherPath.m_nextPathLine;
	this->m_bridgePathLine = a_otherPath.m_bridgePathLine;

	// assign the next path line vertex a black color
	m_nextPathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White;
	m_nextPathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// assign the bridge line vertex a black color
	m_bridgePathLine[ 0 ].color = Brood::Application::StaticVariables::ST_ColorVariables::stm_Black;
	m_bridgePathLine[ 1 ].color = m_bridgePathLine[ 1 ].color = m_nextPathLine[ 0 ].color;

	// updating the path lines
	UpdatePathLines();

	return *this;
}

/// 
/// @public
/// @brief Getter funciton to get tile type of the tile
/// 
/// @return tile type of the tile
///
Brood::Application::Components::ENUM_TileType Brood::Application::Components::Path::GetTileType()
{
	return m_tileType;
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
/// @brief Getter funciton to get the pointer to the next path 
/// 
/// @return pointer to the next path 
///
Brood::Application::Components::Path* Brood::Application::Components::Path::GetNextPathPtr()
{
	return m_nextPathPtr;
}

/// 
/// @public
/// @brief Getter funciton to get the pointer to the previous path 
/// 
/// @return pointer to the previous path 
///
Brood::Application::Components::Path* Brood::Application::Components::Path::GetPreviouPathPtr()
{
	return m_previousPathPtr;
}

/// 
/// @public
/// @brief Getter funciton to get the pointer to the bridge end path 
/// 
/// @return pointer to bridge end path 
///
Brood::Application::Components::Path* Brood::Application::Components::Path::GetBridgeEndPathPtr()
{
	return m_bridgeEndPathPtr;
}

/// 
/// @public
/// @brief Getter funciton to get a reference to the player list
/// 
/// @return const reference to the player list
///
const std::vector<Brood::Application::Components::Player*>& Brood::Application::Components::Path::GetPlayerListPtr() const
{
	return m_playerPtrList;
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
/// @brief Getter funciton to get the index of the assingned deck
/// 
/// @return the index of the assingned deck
///
unsigned Brood::Application::Components::Path::GetDeckIdx()
{
	return m_deckIdx;
}

/// 
/// @public
/// @brief Getter funciton to get the number of card to be drawn
/// 
/// @return  get the number of card to be drawn
///
unsigned Brood::Application::Components::Path::GetNumCardDraw( )
{
	return m_numCardDraw;
}

/// 
/// @public
/// @brief getter funciton to get force dice roll
/// 
/// @return force dice roll boolean
///
bool Brood::Application::Components::Path::GetForceDiceRoll()
{
	return m_forceDiceRoll;
}

/// 
/// @public
/// @brief Getter funciton to get the mid position of the tile in the
///		screen space
/// 
/// @return mid position of the tile in the screen space
///
sf::Vector2f Brood::Application::Components::Path::GetTileCenter()
{
	sf::Vector2f halfbodySize = m_tilePtr->GetBodySize();
	halfbodySize.x /= 2;
	halfbodySize.y /= 2;

	return sf::Vector2f( m_tilePtr->GetBodyPosition() + halfbodySize );
}

/// 
/// @public
/// @brief Getter funciton to get the draw line
/// 
/// @return draw line
///
bool Brood::Application::Components::Path::GetDrawLine()
{
	return m_drawLine;
}

/// 
/// @public
/// @brief Setter funciton to Set tile type of the tile
/// 
/// @param a_tileType tile type of the tile
///
void Brood::Application::Components::Path::SetTileType( Brood::Application::Components::ENUM_TileType a_tileType )
{
	m_tileType = a_tileType;

	switch( m_tileType )
	{
		// mew tile type is blank then remove itself from its previous and next
		case Brood::Application::Components::ENUM_TileType::TILE_blank:
		{
			m_previousPathPtr->SetNextPathPtr( m_previousPathPtr );
			m_nextPathPtr->SetNextPathPtr( m_nextPathPtr );
			SetNextPathPtr( this );
			SetPreviouPathPtr( this );
			SetBridgeEndPathPtr( this );
			break;
		}
		// mew tile type is start then remove its previous
		case Brood::Application::Components::ENUM_TileType::TILE_start:
		{
			m_previousPathPtr->SetNextPathPtr( m_previousPathPtr );
			SetPreviouPathPtr( this );
			SetBridgeEndPathPtr( this );
			break;
		}
		// mew tile type is end then remove its next
		case Brood::Application::Components::ENUM_TileType::TILE_end:
		{
			m_nextPathPtr->SetNextPathPtr( this );
			SetNextPathPtr( this );
			SetBridgeEndPathPtr( this );
			break;
		}
		default:
		{
			break;
		}
	}
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

	// updating the path lines
	UpdatePathLines();
}

/// 
/// @public
/// @brief Setter funciton to set the pointer the next path 
/// 
/// @param a_nextPathPtr pointer to the next path 
///
void Brood::Application::Components::Path::SetNextPathPtr( Brood::Application::Components::Path* a_nextPathPtr )
{
	m_nextPathPtr = a_nextPathPtr;

	// updating the path lines
	UpdatePathLines();

}

/// 
/// @public
/// @brief Setter funciton to set the pointer the previous path 
/// 
/// @param a_previousPathPtr pointer to the previous path 
///
void Brood::Application::Components::Path::SetPreviouPathPtr( Brood::Application::Components::Path* a_previousPathPtr )
{
	m_previousPathPtr = a_previousPathPtr;
}

/// 
/// @public
/// @brief Setter funciton to set the pointer the bridge end path 
/// 
/// @param a_bridgeEndPathPtr pointer to the  bridge end path 
///
void Brood::Application::Components::Path::SetBridgeEndPathPtr( Brood::Application::Components::Path* a_bridgeEndPathPtr )
{
	m_bridgeEndPathPtr = a_bridgeEndPathPtr;

	// updating the path lines
	UpdatePathLines();
}

/// 
/// @public
/// @brief Setter funciton to set the assigned deck pointer
/// 
/// @param a_deckPtr pointer to the assigned deck pointer
///
void Brood::Application::Components::Path::SetDeckPtr( Brood::Application::Components::Deck* a_deckPtr )
{
	if( a_deckPtr == m_deckPtr )
	{
		return;
	}

	Brood::Application::Components::Deck* tempDeckPtr = m_deckPtr;

	// the deck ptr is null
	m_deckPtr = a_deckPtr;

	// removing the path form the deck's list
	//m_deckPtr->
}

/// 
/// @public
/// @brief Setter funciton to set the assigned deck index
/// 
/// @param a_deckPtr index of the assigned deck 
/// 
void Brood::Application::Components::Path::SetDeckIdx( unsigned a_deckIdx )
{
	m_deckIdx = a_deckIdx;
}

/// 
/// @public
/// @brief Setter funciton  to Set the number of card to be drawn
/// 
/// @param a_deckPtr index of the assigned deck 
/// 
void Brood::Application::Components::Path::SetNumCardDraw( unsigned a_numCardDraw )
{ 
	m_numCardDraw = a_numCardDraw;
}

/// 
/// @public
/// @brief Setter funciton  to  Set force dice roll
/// 
/// @param a_diceRoll true if it is too force dice roll
/// 
void Brood::Application::Components::Path::SetForceDiceRoll( bool a_diceRoll )
{
	m_forceDiceRoll = a_diceRoll;
}

/// 
/// @public
/// @brief Function to toggle the drawLine variable
/// 
void Brood::Application::Components::Path::ToggleDrawLine()
{
	m_drawLine = !m_drawLine;
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
	m_playerPtrList.push_back( a_playerPtr );

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
/// @brief Updates path lines based on nextpath, and bridgeEnd path
/// 
void Brood::Application::Components::Path::UpdatePathLines()
{
// updating next Path Line
	m_nextPathLine[ 0 ] = GetTileCenter();
	m_nextPathLine[ 1 ] = m_nextPathPtr->GetTileCenter();

	m_bridgePathLine[ 0 ] = GetTileCenter();
	m_bridgePathLine[ 1 ] = m_bridgeEndPathPtr->GetTileCenter();
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
/// @brief Draw funciton draws the path line to the screen
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::Components::Path::DrawPath( sf::RenderWindow& a_window )
{
	// chekcing if the m_drawLine is true
	if( m_drawLine )
	{
		a_window.draw( m_nextPathLine );
		a_window.draw( m_bridgePathLine );
	}
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