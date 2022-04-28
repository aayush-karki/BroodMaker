/*************************************************************************/
/// 
/// @file WorkSpace.h 
/// 
/// @brief  This file is a header file for WorkSpace class.
/// 
/// It contains all of the declaration of the member 
///		funciton of WorkSpace class.
/// 
/// 
/************************************************************************/
#pragma once

// =============================== defining namespace =======================
namespace Brood
{
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class WorkSpace;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup Application
/// @class WorkSpace  "WorkSpace.h"
/// @brief a abstract base class that is parent to all the different 
///		workspace.
/// 
class Brood::Application::WorkSpace
{
	// ================= public member function =================  
public:
	// default constructor
	WorkSpace();
	// default destructor
	virtual ~WorkSpace();

	virtual void InitializeWorkSpace() = 0; // initializes the component of a workspace
	virtual void Update() = 0; // all the logic for the workspace is here
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw to the screen

/// @TODO: initialize the menu bar here 
/// @TODO: set the editor or game workspace varialbe here
};

