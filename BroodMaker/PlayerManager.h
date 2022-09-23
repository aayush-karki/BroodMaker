/*************************************************************************/
/// 
/// @file PlayerManager.h 
/// 
/// @brief  This file is a header file for PlayerManager class.
/// 
/// It contains all of the declaration of the member 
///		funciton of PlayerManager class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of PlayerManager class
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "stdafx.h"
#include "Player.h"
#include "PathManager.h"
#include "Path.h"
#include "Struct_CtorParam.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class PlayerManager;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of PlayerManager class =======================
// ======================================================================

///
/// @ingroup Components
/// @class PlayerManager  "PlayerManager.h"
/// m_minPlayer
/// @brief A PlayerManager Class manages all player realted things
/// 
class Brood::Application::Components::PlayerManager
{
	// ===================== private member function ===================
public:

	// default constructor
	PlayerManager();

	// destructor
	~PlayerManager();

	// copy constructor
	PlayerManager( const Brood::Application::Components::PlayerManager& a_otherPlayerManager );

	// assignment operator
	PlayerManager& operator=( const Brood::Application::Components::PlayerManager& a_otherPlayerManager );

	// =========== getter function ===========

	// getter funciton to get the maximum player 
	unsigned GetMaxPlayer();

	// getter funciton to get the minimum player 
	unsigned GetMinPlayer();

	unsigned GetCurrActivePlayerIdx();

	// getter funciton to get the Iterator to the start of allplayer vector
	std::vector<Brood::Application::Components::Player*>::iterator GetAllPlayerBegin();

	// getter funciton to get the Iterator to the end of allplayer vector
	std::vector<Brood::Application::Components::Player*>::iterator GetAllPlayerEnd();

	// =========== setter functions ==========

	// setter funciton to set the maximum player 
	void SetMaxPlayer( unsigned a_maxPlayer );

	// setter funciton to set the minimum player 
	void SetMinPlayer( unsigned a_minPlayer );

	// setter function to set the curr Active Player
	void SetCurrActivePlayerIdx( unsigned a_currActivePlayerIdx );

	// sets the path for the current active player
	void SetPathForPlayerAtCurrIdx(Brood::Application::Components::Path* a_pathPtr);

	// Get the current active player
	Brood::Application::Components::Player* GetPlayerAtCurrIdx();

	// Increases the currentPlayer index by 1 andreturns the player 
	//	at that index
	//	if currentPlayer index points to the last player, then it loops
	// back to the first element
	Brood::Application::Components::Player* GetNextPlayer(); // returns next player in the list

	// replaces the a new player at passed index with a copy of passed index
	void ReplacaePlayerAt( unsigned a_index,
						   Brood::Application::Components::Player* a_playerPtr = nullptr );

	void Draw( sf::RenderWindow& a_window );

	// ===================== private member variables ===================
private:

	// contains all the player currently playing the game
	std::vector<Brood::Application::Components::Player*> m_allPlayers;

	// index of current playing player
	int m_currActivePlayerIdx;

	// maximum number of player
	unsigned m_maxPlayer;

	// minimum number of player
	unsigned m_minPlayer;
};

// ======================================================================
// ================= end of PlayerManager class =========================
// ======================================================================