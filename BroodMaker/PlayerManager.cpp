/*************************************************************************/
/// 
/// @file PlayerManager.cpp 
/// 
/// @brief  This file is a source file for PlayerManager class.
/// 
/// It contains all of the defination of the member 
///		funciton of PlayerManager class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "PlayerManager.h"

// ======================================================================
// ================= start of PlayerManager class =======================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///  
Brood::Application::Components::PlayerManager::PlayerManager()
{}

/// 
/// @public
/// @brief Default destructor
/// 
Brood::Application::Components::PlayerManager::~PlayerManager()
{
	// destroying the players
	std::vector<Brood::Application::Components::Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		delete( *currPlayer );
	}
}

/// 
/// @public
/// @brief  Copy constructor
/// 
/// @param a_otherPlayerManager reference to the the other playermanager object that
///		is being copied from 
///
Brood::Application::Components::PlayerManager::PlayerManager( const Brood::Application::Components::PlayerManager& a_otherPlayerManager )
{
	this->m_allPlayers = a_otherPlayerManager.m_allPlayers;
	this->m_maxPlayer = a_otherPlayerManager.m_maxPlayer;
	this->m_minPlayer = a_otherPlayerManager.m_minPlayer;
	this->m_currActivePlayerIdx = a_otherPlayerManager.m_currActivePlayerIdx;
}

/// 
/// @public
/// @brief  assignment operator
/// 
/// @param a_otherPlayerManager reference to the the other playermanager object that
///		is being copied from 
///
Brood::Application::Components::PlayerManager& Brood::Application::Components::PlayerManager::operator=( const Brood::Application::Components::PlayerManager& a_otherPlayerManager )
{
	// checking for self assignment
	if( this == &a_otherPlayerManager )
	{
		return *this;
	}

	this->m_allPlayers = a_otherPlayerManager.m_allPlayers;
	this->m_maxPlayer = a_otherPlayerManager.m_maxPlayer;
	this->m_minPlayer = a_otherPlayerManager.m_minPlayer;
	this->m_currActivePlayerIdx = a_otherPlayerManager.m_currActivePlayerIdx;

	return *this;
}

///
/// @brief Initializes the player manager
/// 
/// @param a_pathPtr  a iterator that holds to 
///		Brood::Application::Components::st_path node which 
///		contains the start row and column number inside it
/// 
void Brood::Application::Components::PlayerManager::InitializePlayerManager( Brood::Application::Components::Path* a_pathPtr )
{
	m_startPathPtr = a_pathPtr;
	SetMaxPlayer( 1 );
	SetMinPlayer( 1 );
	SetCurrActivePlayerIdx( 0 );
}

/// 
/// @brief  initializes the player manager with the passed data
/// 
/// @param a_deckData reference of the player manager data
/// @param a_playerCurrPath path that the new player starts on
/// 
void Brood::Application::Components::PlayerManager::InitializePlayerManager( Brood::Application::Data::ST_PlayerManagerData& a_playerManagerData,
																			 Brood::Application::Components::Path* a_playerCurrPath )
{
	m_startPathPtr = a_playerCurrPath;
	SetMaxPlayer( a_playerManagerData.stm_maxPlayer );
	SetMinPlayer( a_playerManagerData.stm_minPlayer );
	m_currActivePlayerIdx = a_playerManagerData.stm_currPlayerIdx;
}


/// 
/// @public
/// @brief creates and returns player data struct
/// 
/// @return player data struct with the dice data in it
/// 
Brood::Application::Data::ST_PlayerManagerData Brood::Application::Components::PlayerManager::GetDataToSave()
{
	Brood::Application::Data::ST_PlayerManagerData playerManagerData;

	playerManagerData.stm_maxPlayer = m_maxPlayer;
	playerManagerData.stm_minPlayer = m_minPlayer;
	playerManagerData.stm_currPlayerIdx = m_currActivePlayerIdx;

	return playerManagerData;
}

/// 
/// @public
/// @brief loads the PlayerManager data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::PlayerManager::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// saving the PlayerManager data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );

	// saving the players
	std::vector<Brood::Application::Components::Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		( *currPlayer )->SaveDataToFile( a_fileAccessPtr );
	}
}

/// 
/// @public
/// @brief loads the PlayerManager and its path data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::PlayerManager::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr,
																	  Brood::Application::Components::Board* a_gameBoard )
{
	// loading the PlayerManager data
	Brood::Application::Data::ST_PlayerManagerData playerManagerData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	playerManagerData.PopulateFromString( dataFromFile );

	// todo hardcored values
	InitializePlayerManager( playerManagerData, a_gameBoard->GetBoardPathList().at( 0 ).at( 0 ) );

	// loading the players
	std::vector<Brood::Application::Components::Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		( *currPlayer )->LoadDataFromFile( a_fileAccessPtr, a_gameBoard );
	}
}

/// 
/// @public
/// @brief Getter function to get the maximum number of player
/// 
/// @return maximum number of player
///
const unsigned Brood::Application::Components::PlayerManager::GetMaxPlayer() const
{
	return m_maxPlayer;
}

/// 
/// @public
/// @brief Getter function to get the minimum number of player
/// 
/// @return minimum number of player
///
const unsigned Brood::Application::Components::PlayerManager::GetMinPlayer() const
{
	return m_minPlayer;
}

/// 
/// @public
/// @brief Getter function to get the current Player index
/// 
/// @return maximum number of player
///
const unsigned Brood::Application::Components::PlayerManager::GetCurrActivePlayerIdx()const
{
	return m_currActivePlayerIdx;
}

///  
/// @public
/// 
/// @brief Getter function to get the start row of player 
/// 
/// @return start row for the players
/// 
const Brood::Application::Components::Path* Brood::Application::Components::PlayerManager::GetPlayerStartPath() const
{
	return m_startPathPtr;
}

///  
/// @public
/// 
/// @brief Getter function; for begin of player list
/// @return a iterator that points to the begining of the player list
/// 
std::vector<Brood::Application::Components::Player*>::iterator Brood::Application::Components::PlayerManager::GetAllPlayerBegin()
{
	return m_allPlayers.begin();
}

/// 
/// @public
/// 
/// @brief Getter function; for end of path list
/// @return a iterator that points to the end of the path list
/// 
std::vector<Brood::Application::Components::Player*>::iterator Brood::Application::Components::PlayerManager::GetAllPlayerEnd()
{
	return m_allPlayers.end();
}

/// 
/// @public
/// 
/// @brief Setter function to set the maximum number of player
/// 
/// @param a_maxPlayer  maximum number of player
/// 
void Brood::Application::Components::PlayerManager::SetMaxPlayer( unsigned a_maxPlayer )
{

	m_allPlayers.resize( a_maxPlayer, new Player( m_startPathPtr ) );

	unsigned prelastIdx = m_allPlayers.size();

	// dynamically removing the extra deck
	if( a_maxPlayer < m_allPlayers.size() )
	{
		for( int idx = a_maxPlayer - 1; idx < m_allPlayers.size(); ++idx )
		{
			delete m_allPlayers.at( idx );
		}
		m_allPlayers.resize( a_maxPlayer );
	}
	else
	{
		for( int idx = m_allPlayers.size(); idx < a_maxPlayer; ++idx )
		{
			m_allPlayers.push_back( new Brood::Application::Components::Player() );
		}
	}

	m_maxPlayer = a_maxPlayer;

}

/// 
/// @public
/// 
/// @brief Setter function to set the minimum number of player
/// 
/// @param a_minPlayer minimum number of player
/// 
void Brood::Application::Components::PlayerManager::SetMinPlayer( unsigned a_minPlayer )
{
	m_minPlayer = a_minPlayer;
}

/// 
/// @public
/// 
/// @brief Setter function to set the current player Index
/// 
/// @param a_currActivePlayerIdx minimum number of player
/// 
void Brood::Application::Components::PlayerManager::SetCurrActivePlayerIdx( unsigned a_currActivePlayerIdx )
{
	m_currActivePlayerIdx = a_currActivePlayerIdx;
}

///  
/// @public
/// 
/// @brief Setter function to set the start path for new additional player
/// 
/// @param a_startPathPtr pointer to the start path for the player
/// 
void Brood::Application::Components::PlayerManager::SetPlayerStartPath( Brood::Application::Components::Path* a_startPathPtr )
{
	m_startPathPtr = a_startPathPtr;
}


/// 
/// @public
/// 
/// @brief Setter function to set the path for current active player
/// 
/// @param a_pathPtr pointer to the path the current active player is currently on
/// 
void Brood::Application::Components::PlayerManager::SetPathForPlayerAtCurrIdx( Brood::Application::Components::Path* a_pathPtr )
{
	if( m_currActivePlayerIdx == -1 )
	{
		return;
	}

	m_allPlayers.at( m_currActivePlayerIdx )->UpdatePathptr( a_pathPtr );
}

/// 
/// @public
/// @brief Getter function to get the current active player from the list
/// 
/// @return currentActive player who is supposed to be players if list is
///		 not empty ; nullptr if the list is empty
Brood::Application::Components::Player* Brood::Application::Components::PlayerManager::GetPlayerAtCurrIdx()
{
	// no player in the list
	if( m_currActivePlayerIdx == -1 )
	{
		return nullptr;
	}

	return m_allPlayers.at( m_currActivePlayerIdx );
}


/// 
/// @public
/// @brief Getter function to get next player in the list
/// 
/// @return next player who is supposed to be players if list is
///		 not empty ; nullptr if the list is empty
Brood::Application::Components::Player* Brood::Application::Components::PlayerManager::GetNextPlayer()
{
	// no player in the list
	if( m_currActivePlayerIdx == -1 )
	{
		return nullptr;
	}

	++m_currActivePlayerIdx;
	if( m_currActivePlayerIdx == m_allPlayers.size() )
	{
		// looping to the first player
		m_currActivePlayerIdx = 0;
	}

	return m_allPlayers.at( m_currActivePlayerIdx );
}

/// 
/// @public
/// @brief replaces the a new player at passed index
///		 with a copy of passed index
/// 
/// @note if the passed index does not exist then it does nothing
///		to increase the index, increase the maximum number of player 
///		by 
/// 
/// @param a_index index at which he player is to be replaced
/// @param a_playerPtr Pointer to the player whose data is used 
///		to make a copy
///  
void Brood::Application::Components::PlayerManager::ReplacaePlayerAt( unsigned a_index,
																	  Brood::Application::Components::Player* a_playerPtr )
{
	// checking if the index exist
	if( a_index >= m_allPlayers.size() )
	{
		// do nothing
		return;
	}

	// else replace the player at passed index
	( m_allPlayers.at( a_index ) ) = new Player( *( a_playerPtr ) );
}

///
/// @brief Draws the player to the screen
/// 
/// @param a_window reference to the render screen
/// 
void Brood::Application::Components::PlayerManager::Draw( sf::RenderWindow& a_window )
{
	std::vector<Brood::Application::Components::Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		( *currPlayer )->Draw( a_window );
	}
}

// ======================================================================
// ================= end of PlayerManager class =========================
// ======================================================================