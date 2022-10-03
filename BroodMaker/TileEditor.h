/*************************************************************************/
/// 
/// @file TileEditor.h 
/// 
/// @brief  This file is a header file for TileEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of TileEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "MenuBar.h" // includes all the other uiElements
#include "WorkSpace.h"
#include "Board.h"
#include "DeckManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class TileEditor;
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
/// @class TileEditor  "TileEditor.h"
/// @brief It alows the users to tweek the tile setting
///
/// It is a container that bundels elements that is present 
///		in TileEditor workspace
/// 
/// Derived form Workspace class
/// 
/// @todo allowd to enter number in the txt feild
/// 
class Brood::Application::TileEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	TileEditor( Brood::Application::Components::Board* a_boardPtr,
				Brood::Application::Components::DeckManager* a_deckManagerPtr,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~TileEditor();
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
