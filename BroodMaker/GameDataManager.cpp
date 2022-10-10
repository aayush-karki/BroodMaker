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
/// @public
/// @brief default constructor
/// 
Brood::Application::Components::GameDataManager::GameDataManager() :
	m_board(), m_dice(), m_playerManager(), m_deckManager(),
	m_gameTitle("NewGameEdit"), m_displayCard()
{}

/// 
/// @public
/// @brief  default destructor
///
Brood::Application::Components::GameDataManager::~GameDataManager()
{}


/// 
/// @public
/// @brief Initializes the member variables
/// 
void Brood::Application::Components::GameDataManager::InitializeGameDataManger()
{
	// initializing  the board
	m_board.InitializeBoard( 1, 1, 500, 500, 50, 200 );

	m_board.GetCurrentActivePath()->SetDeckPtr( m_deckManager.GetCurrActiveDeck());

	// initializing  the playerManager
	m_playerManager.InitializePlayerManager( m_board.GetBoardPathList().at( 0 ).at( 0 ) );

	m_displayCard.SetCardInfoToDisplay( m_deckManager.GetCurrActiveDeck()->GetCurrActiveCardPtr() );
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
	m_board.Draw( a_window );
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
	m_displayCard.Debugger();
}

/// 
/// @brief  initializes the game data manager with the passed data
/// 
/// @param a_gameDataManager reference of the game data
void Brood::Application::Components::GameDataManager::InitializeGameDataManager( Brood::Application::Data::ST_GameData& a_gameDataManager )
{
	m_gameTitle = a_gameDataManager.stm_gameTitle;
}

Brood::Application::Data::ST_GameData Brood::Application::Components::GameDataManager::GetDataToSave()
{
	Brood::Application::Data::ST_GameData gameDataManager;

	gameDataManager.stm_gameTitle = m_gameTitle;

	return gameDataManager;
}

/// 
/// @public
/// @brief saves the game data manager data to passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::GameDataManager::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// saving the game data manager data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );
}

/// 
/// @public
/// @brief loads the game data manager data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::GameDataManager::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// loading the game data manager data
	Brood::Application::Data::ST_GameData gameData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	gameData.PopulateFromString( dataFromFile );
	InitializeGameDataManager( gameData );
}

/// 
/// @public
/// @brief setter funciton to set the game title 
///		for the game
/// 
/// @param a_gameTitle game title
///
void Brood::Application::Components::GameDataManager::SetGameTitle( std::string a_gameTitle )
{
	m_gameTitle = a_gameTitle;
}

/// 
/// @public
/// @brief Getter funciton to get a saved game title
///		 of the game 
/// 
/// @return game title
///
std::string Brood::Application::Components::GameDataManager::GetGameTitle()
{
	return m_gameTitle;
}

/// 
/// @public
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
/// @public
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
/// @public
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
/// @public
/// @brief Getter funciton to get a pointer to deck mangaer
///		 of the game 
/// 
/// @return pointer pointer to the deck mangaer
///
Brood::Application::Components::DeckManager* Brood::Application::Components::GameDataManager::GetDeckManagerPtr()
{
	return &m_deckManager;
}

/// 
/// @public
/// @brief Getter funciton to get a pointer to
///		display card of the game
/// 
/// @return pointer pointer to the deck mangaer
///
Brood::Application::Components::DisplayCard* Brood::Application::Components::GameDataManager::GetDisplayCardPtr()
{
	return &m_displayCard;
}

// ======================================================================
// ================= end of GameDataManager class =======================
// ======================================================================
