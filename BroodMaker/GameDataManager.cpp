/*************************************************************************/
/// 
/// @file GameDataManager.cpp 
/// 
/// @brief  This file is a source file for GameDataManager class
/// 
/// It also contains all of the declaration of the GameDataManager
///		class's member function.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "GameDataManager.h"

// ======================================================================
// ================= start of GameDataManager class =====================
// ======================================================================

/// 
/// @brief default constructor
/// 
Brood::Application::Components::GameDataManager::GameDataManager():
	m_board(), m_dice(), m_playerManager(),	m_deckManager()
{}

/// 
/// @brief  default destructor
///
Brood::Application::Components::GameDataManager::~GameDataManager()
{}


/// 
/// @brief Initializes the member variables
/// 
void Brood::Application::Components::GameDataManager::InitializeGameDataManger()
{
	// initializing  the board
	m_board.InitializeBoard( 1, 1, 500, 500, 50, 200 );

	// initializing  the playerManager
	m_playerManager.InitializePlayerManger( m_board.GetBoardPathList().at( 0 ).at( 0 ) );
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::Components::GameDataManager::Draw( sf::RenderWindow& a_window )
{
	m_board.Draw(a_window);
	m_deckManager.Draw( a_window );
	m_dice.Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::Components::GameDataManager::Debugger()
{
	m_board.Debugger();
	m_dice.Debugger();
	m_deckManager.Debugger();
}

/// 
/// @brief Getter funciton to get a pointer to board
///		 of the game 
/// 
/// @return pointer pointer to the board
///
Brood::Application::Components::Board* Brood::Application::Components::GameDataManager::GetBoardPtr()
{
	return &m_board;
}

/// 
/// @brief Getter funciton to get a pointer to dice 
///		 of the game 
/// 
/// @return pointer pointer to the dice
///
Brood::Application::Components::Dice* Brood::Application::Components::GameDataManager::GetDicePtr()
{
	return &m_dice;
}

/// 
/// @brief Getter funciton to get a pointer to player mangaer
///		 of the game 
/// 
/// @return pointer pointer to the player mangaer
/// 
Brood::Application::Components::PlayerManager* Brood::Application::Components::GameDataManager::GetPlayerManagerPtr()
{
	return &m_playerManager;
}

/// 
/// @brief Getter funciton to get a pointer to deck mangaer
///		 of the game 
/// 
/// @return pointer pointer to the deck mangaer
///
Brood::Application::Components::DeckManager* Brood::Application::Components::GameDataManager::GetDeckManagerPtr()
{
	return &m_deckManager;
}

// ======================================================================
// ================= end of GameDataManager class =======================
// ======================================================================
