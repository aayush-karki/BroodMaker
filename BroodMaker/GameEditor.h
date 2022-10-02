/*************************************************************************/
/// 
/// @file GameEditor.h 
/// 
/// @brief  This file is a header file for GameEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of GameEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "WorkSpace.h"
#include "Board.h"
#include "Dice.h"
#include "PlayerManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class GameEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of GameEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class BoardEditor  "GameEditor.h"
/// @brief It alows the users to tweek the general game setting 
///		and game rules.
///
/// It is a container that bundels elements that is present 
///		in GameEditor workspace
/// 
/// Derived form Workspace class
/// 
/// @todo allowd to enter number in the txt feild
/// 
class Brood::Application::GameEditor
{
	// ================= public member function ===================  
public:
	// default constructor
	GameEditor( Brood::Application::Components::Board* a_boardPtr,
				 Brood::Application::Components::PlayerManager* a_playerManagerPtr,
				 sf::RectangleShape* a_panelPtr );

	// default destructor
	~GameEditor();
	// ===== virtual funcitons ====

	// initializes the component of a workspace
	void InitializeWorkSpace();

	// all the logic for the workspace is here
	void Update();

	// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();


	// ================= private member function ================== 
private:

	// ================= private member variable ================== 
private:
};

