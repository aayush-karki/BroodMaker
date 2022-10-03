/*************************************************************************/
/// 
/// @file CardEditor.h 
/// 
/// @brief  This file is a header file for CardEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of CardEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "MenuBar.h" // includes all the other uiElements
#include "WorkSpace.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class CardEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of TileEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class CardEditor  "CardEditor.h"
/// @brief It alows the users to tweek the card setting
///
/// It is a container that bundels elements that is present 
///		in CardEditor workspace
/// 
/// Derived form Workspace class
/// 
class Brood::Application::CardEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	CardEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~CardEditor();
	// ===== virtual funcitons ====

	// initializes the component of a workspace
	void InitializeWorkSpace();

	// all the logic for the workspace is here
	void Update();

	// updates all the display elment
	void UpdateAllDispayElement();

	// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();

	// ================= private member function ================== 	
private:

	// ================= private member variable ==================  
private:

	/// pointer to the game data
	Brood::Application::Components::GameDataManager* m_gameData;

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// board for the game
	Brood::Application::Components::Board* m_boardPtr;

	/// pointer to the deck manager
	Brood::Application::Components::DeckManager* m_deckManagerPtr;
};

// ======================================================================
// ================= end of TileEditor class ============================
// ======================================================================
