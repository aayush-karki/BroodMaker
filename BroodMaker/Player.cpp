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
	m_positionOffsetY( a_positionOffsetY )
{
	// initializing the player body
	this->m_playerBody.setFillColor( sf::Color::White );

	if( a_pathPtr == nullptr )
	{
		this->m_playerBody.setSize( { 10.f, 10.f } );
		this->m_playerBody.setPosition( { 200, 200 } );
	}
	else
	{
		sf::Vector2f tileSize = m_playerCurrPathPtr->GetTile()->GetBodySize();

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
Brood::Application::Components::Player::Player( const Player& a_otherPlayer )
{
	this->m_playerBody = a_otherPlayer.m_playerBody;
	this->m_positionOffsetX = a_otherPlayer.m_positionOffsetX;
	this->m_positionOffsetY = a_otherPlayer.m_positionOffsetY;
	this->m_playerCurrPathPtr = a_otherPlayer.m_playerCurrPathPtr;
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
	this->m_playerBody = a_otherPlayer.m_playerBody;
	this->m_positionOffsetX = a_otherPlayer.m_positionOffsetX;
	this->m_positionOffsetY = a_otherPlayer.m_positionOffsetY;
	this->m_playerCurrPathPtr = a_otherPlayer.m_playerCurrPathPtr;

	return *this;
}

/// 
/// @public
/// @brief Funciton to update the pointer to the path. 
/// 
/// It also updates the position of the player body
///			
/// @param a_playerNewPathPtr pointer to the new path
/// 
void Brood::Application::Components::Player::UpdatePathptr( Brood::Application::Components::Path* a_playerNewPathPtr )
{
	if( m_playerCurrPathPtr != nullptr )
	{
		// deleting it self form the previous tile list
		m_playerCurrPathPtr->DeletePlayerFromList( this );
	}

	// saving the path pointer
	m_playerCurrPathPtr = a_playerNewPathPtr;

	// checking if the passed path is not null ptr then update the path's position
	if( a_playerNewPathPtr != nullptr )
	if( a_playerNewPathPtr != nullptr )
	{
		// updating the position
		UpdatePosition();
	}
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
void Brood::Application::Components::Player::SetPositionOffsetX( float a_positionOffsetX )
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
void Brood::Application::Components::Player::SetPositionOffsetY( float a_positionOffsetY )
{
	m_positionOffsetY = a_positionOffsetY;

	UpdatePosition();
}

/// 
/// @public
/// @brief Getter function to get the pointer to the tile
///		that the player is currently on
/// 
/// It also updates the position of the player body
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
/// It also updates the position of the player body
///			
/// @return  a reference to player body
/// 
const sf::RectangleShape& Brood::Application::Components::Player::GetPlayerBody() const
{
	return m_playerBody;
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
	sf::Vector2f tilePos = m_playerCurrPathPtr->GetTile()->GetBodyPosition();

	float playerPosX = ( tilePos.x * m_positionOffsetX ) / 100;
	float playerPosY = ( tilePos.y * m_positionOffsetY ) / 100;

	this->m_playerBody.setPosition( { playerPosX , playerPosY } );
}

// ======================================================================
// ================= end of Player class ================================
// ======================================================================