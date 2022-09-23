/*************************************************************************/
/// 
/// @file PathManager.h 
/// 
/// @brief  This file is a header file for PathManager class.
/// 
/// It contains all of the declaration of the member 
///		funciton of PathManager class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of PathManager class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

#include "Path.h"
#include "PlayerManager.h"

///
/// @class PathManager  "PathManager.h"
/// 
/// @brief A PathManager Class that manages the linear flow of how a player
/// moves. 
/// 
/// It converts the 2d board into a 1d line that makes it easer to compute 
/// the path that a player would follow
/// 
/// 
class PathManager
{
	// ===================== public member funciton ===================
public:
	PathManager( unsigned a_numRows = 0, unsigned a_numCols = 0 ); // default constructor
	~PathManager(); // destructor
	const std::list<Brood::Application::Components::Path*>::iterator GetPathBegin(); // returns the begin of list 
	const std::list<Brood::Application::Components::Path*>::iterator GetPathEnd(); // returns the end of list 

	//bool DeletePlayerFromList( Brood::Application::Components::Player* a_playerPtr );
	// ===================== private member variables ===================
private:
	std::list<Brood::Application::Components::Path*> m_paths; // contains the path of the game

	//std::vector<Brood::Application::Components::Player*> m_playerPtrList;
};

/// 
/// @public
/// 
/// @brief Getter function; for begin of path list
/// @return a iterator that points to the begining of the path list
/// 
inline const std::list<Brood::Application::Components::Path*>::iterator PathManager::GetPathBegin()
{
	return m_paths.begin();
}

/// 
/// @public
/// 
/// @brief Getter function; for end of path list
/// @return a iterator that points to the end of the path list
/// 
inline const std::list<Brood::Application::Components::Path*>::iterator PathManager::GetPathEnd()
{
	return m_paths.end();
}