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
#pragma once
#include "stdafx.h"
#include "Player.h"
#include "PathManager.h"
#include "Struct_path.h"
#include "Struct_CtorParam.h"

///
/// @class PlayerManager  "PlayerManager.h"
/// 
/// @brief A PlayerManager Class manages all player realted things
/// 
class PlayerManager
{
	// ===================== private member function ===================
public:
	
	// default constructor
	PlayerManager( St_BoardParam* a_BoardParm = nullptr, 
				   PathManager* a_PathManagerIte = nullptr ); 
	~PlayerManager(); // destructor

	void AddNewPlayer( float a_playerSizeX = 0.f, float a_playerSizeY = 0.f,
					   int a_playerStartRow = 0, int a_playerStartCol = 0);
	Player* GetNextPlayer(); // returns next player in the list
	const std::vector<Player*>::iterator GetAllPlayerBegin();
	const std::vector<Player*>::iterator GetAllPlayerEnd();
	void Draw( sf::RenderWindow& a_window );

	// ===================== private member variables ===================
private:
	
	// contains all the player currently playing the game
	std::vector<Player*> m_allPlayers; 
	int m_currPlayerIdx; // index of current playing player

	PathManager* m_PathManagerIte; // pointer to path manager
	St_BoardParam* m_BoardParmIte; // pointer to initial board parameters
	
};

/// @public
/// @brief Default Constructor
/// 
/// it sets m_currPlayerIndx to -1
/// 
inline PlayerManager::PlayerManager( St_BoardParam* a_BoardParm, PathManager* a_PathManagerIte ):
	m_PathManagerIte (a_PathManagerIte), m_BoardParmIte (a_BoardParm)

{
	m_currPlayerIdx = -1;
}

/// 
/// @public
/// 
/// @brief Getter function; for begin of player list
/// @return a iterator that points to the begining of the player list
/// 
inline const std::vector<Player*>::iterator PlayerManager::GetAllPlayerBegin()
{
	return m_allPlayers.begin();
}

/// 
/// @public
/// 
/// @brief Getter function; for end of path list
/// @return a iterator that points to the end of the path list
/// 
inline const std::vector<Player*>::iterator PlayerManager::GetAllPlayerEnd()
{
	return m_allPlayers.end();
}