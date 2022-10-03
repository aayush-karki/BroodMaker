/*************************************************************************/
/// 
/// @file Player.cpp 
/// 
/// @brief  This file is a source file for Player class.
/// 
/// It contains all of the defination of the member 
///		funciton of Player class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Player.h"

// ======================================================================
// ================= start of Player class ==============================
// ======================================================================

/// 
/// @public
/// @brief  Default Constructor
///
/// @param a_pathIte a iterator that holds to Brood::Application::Components::st_path node which 
///		contains the start row and column number inside it
/// @param a_positionOffsetX position offset of the path relative 
///		to tile's x position
/// @param a_positionOffsetY position offset of the path relative 
///		to tile's Y position
/// 
Brood::Application::Components::Player::Player( Brood::Application::Components::Path* a_pathPtr,
												unsigned a_positionOffsetX,
												unsigned a_positionOffsetY ) :
	m_playerCurrPathPtr( a_pathPtr ), m_positionOffsetX( a_positionOffsetX ),
	m_positionOffsetY( a_positionOffsetY ), m_spriteBody( &m_playerBody )
{
	// initializing the player body
	this->m_playerBody.setFillColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );

	if( a_pathPtr == nullptr )
	{
		this->m_playerBody.setSize( { 10.f, 10.f } );
		this->m_playerBody.setPosition( { 200, 200 } );
	}
	else
	{
		sf::Vector2f tileSize = m_playerCurrPathPtr->GetTilePtr()->GetBodySize();

		this->m_playerBody.setSize( { ( tileSize.x * 50 ) / 100, ( tileSize.y * 50 ) / 100 } );
		UpdatePosition();
	}
}

/// 
/// @public
/// @brief  Default Desturctor
///
Brood::Application::Components::Player::~Player()
{}


/// 
/// @public
/// @brief  Copy constructor
/// 
/// @param a_otherPlayer reference to the the other player object that
///		is being copied from 
///
Brood::Application::Components::Player::Player( const Player& a_otherPlayer ) :
	Player()
{
	this->m_playerBody = a_otherPlayer.m_playerBody;
	this->m_positionOffsetX = a_otherPlayer.m_positionOffsetX;
	this->m_positionOffsetY = a_otherPlayer.m_positionOffsetY;
	this->m_playerCurrPathPtr = a_otherPlayer.m_playerCurrPathPtr;
	this->m_spriteBody = a_otherPlayer.m_spriteBody;
}

/// 
/// @public
/// @brief  assignment operator
/// 
/// @param a_otherPlayer reference to the the other player object that
///		is being copied from 
///
Brood::Application::Components::Player& Brood::Application::Components::Player::operator=( const Player& a_otherPlayer )
{
	// chekecking for self assignment 
		// checking for self assignment
	if( this == &a_otherPlayer )
	{
		return *this;
	}

	this->m_playerBody = a_otherPlayer.m_playerBody;
	this->m_positionOffsetX = a_otherPlayer.m_positionOffsetX;
	this->m_positionOffsetY = a_otherPlayer.m_positionOffsetY;
	this->m_playerCurrPathPtr = a_otherPlayer.m_playerCurrPathPtr;
	this->m_spriteBody = a_otherPlayer.m_spriteBody;

	return *this;
}

/// 
/// @public
/// @brief Funciton to update the pointer to the path. 
/// 
/// It also updates the position of the player body. If there
///		are already player in the tile space it offsets the player
///		position by 3 px to the left and down
///			
/// @param a_playerNewPathPtr pointer to the new path
/// 
void Brood::Application::Components::Player::UpdatePathptr( Brood::Application::Components::Path* a_playerNewPathPtr )
{
	// checking for self assignment
	if( m_playerCurrPathPtr == a_playerNewPathPtr )
	{
		return;
	}

	// if the current path is not null then removing itself from the path
	else if( m_playerCurrPathPtr != nullptr )
	{
		// deleting it self form the previous tile list
		m_playerCurrPathPtr->DeletePlayerFromList( this );
	}

	// saving the path pointer
	m_playerCurrPathPtr = a_playerNewPathPtr;

	// checking if the passed path is not null ptr then update the path's position
	if( a_playerNewPathPtr != nullptr )
	{
		// updating the position
		UpdatePosition();

		// adding the player to the path's player list
		a_playerNewPathPtr->AddPlayerToList( this );

		// if more than one player exists in the list offset this player position

		unsigned tilePlayerCount = a_playerNewPathPtr->GetPlayerListPtr().size();

		if( tilePlayerCount != 1 )
		{
			sf::Vector2f tilePos = m_playerCurrPathPtr->GetTilePtr()->GetBodyPosition();
			float playerPosX = tilePos.x + m_positionOffsetX + tilePlayerCount * 3;
			float playerPosY = tilePos.y + m_positionOffsetY + tilePlayerCount * 3;
			this->m_playerBody.setPosition( { playerPosX , playerPosY } );
		}
	}
}

/// 
/// @public
/// @brief Setter funciton to set the x-size 
/// 
/// The offset is relative to the tile the player is currently on.
///		It also updates the players position
/// 
/// @param a_sizeX player's x size 
/// 
void Brood::Application::Components::Player::SetPlayerSizeX( float a_sizeX )
{
	m_playerBody.setSize( { a_sizeX, m_playerBody.getSize().y } );
}

/// 
/// @public
/// @brief Setter funciton to set the x-size 
/// 
/// The offset is relative to the tile the player is currently on.
///		It also updates the players position
/// 
/// @param a_sizeX player's x size 
/// 
void Brood::Application::Components::Player::SetPlayerSizeY( float a_sizeY )
{
	m_playerBody.setSize( { m_playerBody.getSize().x, a_sizeY } );
}

/// 
/// @public
/// @brief Setter funciton to set the x-offset for player positon 
/// 
/// The offset is relative to the tile the player is currently on.
///		It also updates the players position
/// 
/// @param a_positionOffsetX position offset of the path relative 
///		to tile's x position
void Brood::Application::Components::Player::SetPositionOffsetX( int a_positionOffsetX )
{
	m_positionOffsetX = a_positionOffsetX;

	UpdatePosition();
}

/// 
/// @public
/// @brief Setter funciton to set the y-offset for player positon 
/// 
/// The offset is relative to the tile the player is currently on.
///		It also updates the players position
/// 
/// @param a_positionOffsetY position offset of the path relative 
///		to tile's Y position
void Brood::Application::Components::Player::SetPositionOffsetY( int a_positionOffsetY )
{
	m_positionOffsetY = a_positionOffsetY;

	UpdatePosition();
}

/// 
/// @public
/// @brief Getter function to get the pointer to the tile
///		that the player is currently on
/// 
/// @return pointer to the tile that the player is currently on
/// 
const Brood::Application::Components::Path* Brood::Application::Components::Player::GetCurrPathPtr() const
{
	return m_playerCurrPathPtr;
}


/// 
/// @public
/// @brief Getter function to get a reference to player body
/// 
///			
/// @return  a reference to player body
/// 
sf::RectangleShape& Brood::Application::Components::Player::GetPlayerBody()
{
	return m_playerBody;
}

/// 
/// @public
/// @brief Getter function to get a reference to the player sprite body
/// 
///			
/// @return  a reference to player body
/// 
Brood::SpriteHandler& Brood::Application::Components::Player::GetPlayerSpriteBody()
{
	return m_spriteBody;
}

/// 
/// @public
/// @brief Getter function to get the x-offset
///
///		
/// @return a reference to player body
///
int Brood::Application::Components::Player::GetPositionOffsetX()
{
	return m_positionOffsetX;
}

/// 
/// @public
/// @brief Getter function to get the y-offset
/// 
///		
/// @return a reference to player body
///
int Brood::Application::Components::Player::GetPositionOffsetY()
{
	return m_positionOffsetY;
}

/// 
/// @public
/// @brief Draw funciton draws tiles to the screen.
///			
/// @param a_window reference to the render window
/// 
void Brood::Application::Components::Player::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_playerBody );
}

/// 
/// @private
/// @brief updates the player position with respect to tile
///			
void Brood::Application::Components::Player::UpdatePosition()
{
	sf::Vector2f tilePos = m_playerCurrPathPtr->GetTilePtr()->GetBodyPosition();

	float playerPosX = tilePos.x + m_positionOffsetX;
	float playerPosY = tilePos.y + m_positionOffsetY;

	this->m_playerBody.setPosition( { playerPosX , playerPosY } );
}

// ======================================================================
// ================= end of Player class ================================
// ======================================================================