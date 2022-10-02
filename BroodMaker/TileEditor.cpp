/*************************************************************************/
/// 
/// @file TileEditor.cpp 
/// 
/// @brief  This file is a source file for TileEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of TileEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "TileEditor.h"

// ======================================================================
// ================= start of BoardEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
Brood::Application::TileEditor::TileEditor( Brood::Application::Components::Board* a_boardPtr,
											sf::RectangleShape* a_panelPtr ):
m_boardPtr(a_boardPtr), m_panelBodyPtr(a_panelPtr)
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::TileEditor::~TileEditor()
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
void Brood::Application::TileEditor::InitializeWorkSpace()
{


}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::TileEditor::Update()
{
	
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
/// 
/// @param a_window reference to the render window
///
void Brood::Application::TileEditor::Draw( sf::RenderWindow& a_window )
{
	
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::TileEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}


// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================