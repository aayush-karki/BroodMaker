/*************************************************************************/
/// 
/// @file DeckEditor.cpp 
/// 
/// @brief  This file is a source file for DeckEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of DeckEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "DeckEditor.h"

// ======================================================================
// ================= start of DeckEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::DeckEditor::DeckEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::DeckEditor::~DeckEditor()
{
	// all the dynamically created panel elements are 
	// destructed in the base class
}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It inializes the board,
///		setting section Dropdown Input.
//
void Brood::Application::DeckEditor::InitializeWorkSpace()
{


}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::DeckEditor::Update()
{

}

/// 
/// @public
/// @virtual
/// @brief updates the display element
/// 

///
void Brood::Application::DeckEditor::UpdateAllDispayElement()
{}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
/// 
/// @param a_window reference to the render window
///
void Brood::Application::DeckEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing game component
	m_gameData->Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::DeckEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}

// ======================================================================
// ================= end of DeckEditor class ============================
// ======================================================================
