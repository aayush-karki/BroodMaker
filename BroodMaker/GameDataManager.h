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
#include "DisplayCard.h"

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
/// @class GameDataManager  "GameDataManager.h"
/// @brief A GameDataManager Class manages the game data.
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

	// =========== setter functions ==========

	/// setter funciton to set the game title for the game
	void SetGameTitle( std::string a_gameTitle);

	// =========== getter functions ==========

	/// Getter funciton to get a saved game title of the game
	std::string GetGameTitle();

	/// Getter funciton to get a pointer to board of the game
	Brood::Application::Components::Board* GetBoardPtr();

	/// Getter funciton to get a pointer to dice of the game
	Brood::Application::Components::Dice* GetDicePtr();

	/// Getter funciton to get a pointer to player mangaer of the game
	Brood::Application::Components::PlayerManager* GetPlayerManagerPtr();

	/// Getter funciton to get a pointer to Deck mangaer of the game
	Brood::Application::Components::DeckManager* GetDeckManagerPtr();

	/// Getter funciton to get a pointer to display card of the game
	Brood::Application::Components::DisplayCard* GetDisplayCardPtr();

	// ===================== private member variables ===================
private:

	std::string m_gameTitle;

	/// board for the game
	Brood::Application::Components::Board m_board;

	/// dice for the game
	Brood::Application::Components::Dice m_dice;

	/// player mangaer for the game
	Brood::Application::Components::PlayerManager m_playerManager;

	/// Deck mangaer for the game
	Brood::Application::Components::DeckManager m_deckManager;

	// cardinfo
	Brood::Application::Components::DisplayCard m_displayCard;
};

// ======================================================================
// ================= end of GameDataManager class =======================
// ======================================================================