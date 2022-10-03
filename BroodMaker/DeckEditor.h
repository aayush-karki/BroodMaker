/*************************************************************************/
/// 
/// @file DeckEditor.h 
/// 
/// @brief  This file is a header file for DeckEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DeckEditor class.
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
		class DeckEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DeckEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class TileEditor  "DeckEditor.h"
/// @brief It alows the users to tweek the deck setting
///
/// It is a container that bundels elements that is present 
///		in DeckEditor workspace
/// 
/// Derived form Workspace class
/// 
class Brood::Application::DeckEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	DeckEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~DeckEditor();
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
// ================= end of DeckEditor class ============================
// ======================================================================