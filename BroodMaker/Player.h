/*************************************************************************/
/// 
/// @file Player.h 
/// 
/// @brief  This file is a header file for Player class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Player class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Player class
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "stdafx.h"

#include "Path.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class Player;
		class Path;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Player class ==============================
// ======================================================================

///
/// @ingroup Components
/// @class Player  "Player.h"
/// 
/// @brief A Player Class
/// 
/// @todo make it so that if two or more player are in the same tile 
///		then offset the player so that they are visually.
///		One way to do this could be to add a vector of playerPtr
///		 to tile where if a player get to the tile player will push
///		itself back to this list and will save ther player index to itself.
///		and once a player moves on it will call a function to update itself
///		leaving the tile thus updating other player position in the tile list
/// 
class Brood::Application::Components::Player
{
	// ================== public member fuction =======================
public:
	// Default Constructor when path is provided
	Player( Brood::Application::Components::Path* a_pathPtr = nullptr, unsigned a_positionOffsetX = 0,
			unsigned a_positionOffsetY = 0 );

	// default destructor
	~Player();

	// copy constructor
	Player(const Player& a_otherPlayer);

	// assignment operator
	Player& operator=( const Player& a_otherPlayer );

	// function to update the path iterator
	void UpdatePathptr( Brood::Application::Components::Path* a_playerNewPathPtr );

	// setter funciton to set the player's x-offset
	void SetPositionOffsetX( float a_positionOffsetX );

	// setter funciton to set the player's y-offset
	void SetPositionOffsetY( float a_positionOffsetY );

	// getter funciton to get the pointer to the tile
	const Brood::Application::Components::Path* GetCurrPathPtr() const;

	// getter funciton to get a reference to the player body
	const sf::RectangleShape& GetPlayerBody() const;

	// draw to screen
	void Draw( sf::RenderWindow& a_window );

	// ===== private member function =====
private:
	// updates the player position with respect to tile 
	void UpdatePosition();

	// ===== private member variable =====
private:
	
	// player body
	sf::RectangleShape m_playerBody; 

	// holds the x-offset relative to the tile's x position
	unsigned m_positionOffsetX;

	// holds the x-offset relative to the tile's y position
	unsigned m_positionOffsetY;

	// pointer that points to the current path node;
	// it hoolds all tile that the player is on
	Brood::Application::Components::Path* m_playerCurrPathPtr;
};

// ======================================================================
// ================= end of Player class ================================
// ======================================================================