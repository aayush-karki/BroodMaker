/*************************************************************************/
/// 
/// @file GameDataManager.h 
/// 
/// @brief  This file is a header file for GameDataManager class.
/// 
/// It contains all of the declaration of the member 
///		funciton of GameDataManager class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "Board.h"
#include "Dice.h"
#include "DeckManager.h"
#include "PlayerManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class GameDataManager;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of GameDataManager class =====================
// ======================================================================

///
/// @ingroup Components
/// @class PlayerManager  "PlayerManager.h"
/// m_minPlayer
/// @brief A PlayerManager Class manages all player realted things
/// 
class Brood::Application::Components::GameDataManager
{
	// ===================== public member function ===================
public:

	// default constructor
	GameDataManager();

	// default destructor
	~GameDataManager();

	// initializes the gameData
	void InitializeGameDataManger();

	/// Draws all the component to the screen
	void Draw( sf::RenderWindow& a_window );

	/// debugger
	void Debugger();


	// =========== getter functions ==========

	/// Getter funciton to get a pointer to board of the game
	Brood::Application::Components::Board* GetBoardPtr();

	/// Getter funciton to get a pointer to dice of the game
	Brood::Application::Components::Dice* GetDicePtr();

	/// Getter funciton to get a pointer to player mangaer of the game
	Brood::Application::Components::PlayerManager* GetPlayerManagerPtr();

	/// Getter funciton to get a pointer to Deck mangaer of the game
	Brood::Application::Components::DeckManager* GetDeckManagerPtr();

	// ===================== private member variables ===================
private:

	/// board for the game
	Brood::Application::Components::Board m_board;

	/// dice for the game
	Brood::Application::Components::Dice m_dice;

	/// player mangaer for the game
	Brood::Application::Components::PlayerManager m_playerManager;

	/// Deck mangaer for the game
	Brood::Application::Components::DeckManager m_deckManager;


};

// ======================================================================
// ================= end of GameDataManager class =======================
// ======================================================================