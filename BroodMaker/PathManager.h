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

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "stdafx.h"

#include "Path.h"
#include "PlayerManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class PathManager;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of PathManager class =========================
// ======================================================================

///
/// @class Dice  "Deck.h"
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
	// default constructor
	PathManager( unsigned a_numRows = 0, unsigned a_numCols = 0 ); 
	
	// default destructor
	~PathManager();
	
	// returns the begin of list 
	const std::list<Brood::Application::Components::Path*>::iterator GetPathBegin(); 
	
	// returns the end of list 
	const std::list<Brood::Application::Components::Path*>::iterator GetPathEnd(); 

	// ===================== private member variables ===================
private:
	
	/// contains the path of the game
	std::list<Brood::Application::Components::Path*> m_paths; 
};

// ======================================================================
// ================= end of PathManager class ===========================
// ======================================================================