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

#include "Struct_path.h"

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
	std::list<st_path*>::iterator GetPathBegin(); // returns the begin of list 
	std::list<st_path*>::iterator GetPathEnd(); // returns the end of list 

private:
	std::list<st_path*> m_paths; // contains the path of the game


};

/// 
/// @public
/// 
/// @brief Getter function; for begin of path list
/// @return a iterator that points to the begining of the path list
/// 
inline std::list<st_path*>::iterator PathManager::GetPathBegin()
{
	return m_paths.begin();
}

/// 
/// @public
/// 
/// @brief Getter function; for end of path list
/// @return a iterator that points to the end of the path list
/// 
inline std::list<st_path*>::iterator PathManager::GetPathEnd()
{
	return m_paths.end();
}