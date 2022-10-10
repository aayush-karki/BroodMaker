/*************************************************************************/
/// 
/// @file EditorWorkspace.h 
/// 
/// @brief  This file is a header file for InitialWorkSpace class.
/// 
/// It contains all of the declaration of the member 
///		funciton of InitialWorkSpace class.
/// 
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "WorkSpace.h"
#include "BoardEditor.h"
#include "GameEditor.h"
#include "TileEditor.h"
#include "PlayerEditor.h"
#include "DiceEditor.h"
#include "DeckEditor.h"
#include "CardEditor.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class EditorWorkspace;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of EditorWorkspace class =====================
// ======================================================================

///
/// @ingroup Application
/// @class BoardEditor  "EditorWorkspace.h"
/// @brief It is a container that bundels and control all the different 
///		editor workspace, namely Board Editor, Tile Editor, Path Editor, and
///		Deck Editor
/// 
/// Editor WorkSpace is where the user edit or tweek different setting to make
///		a game project
/// 
/// Derived from the WorkSpace class 
/// 
class Brood::Application::EditorWorkspace :
	public Brood::Application::WorkSpace
{
	// ================= public member variables =================  
public:
	// default constructor
	EditorWorkspace( Brood::Application::Components::GameDataManager* a_gameData );

	// default destructor
	virtual ~EditorWorkspace();

	// ===== virtual funcitons ====   

	/// initializes the component of a workspace
	void InitializeWorkSpace();

	/// all the logic for the workspace is here
	void Update();

	// updates all the display elment
	void UpdateAllDispayElement();

	/// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	/// Calls Debugger for all UI elements in this class
	void Debugger();

	// setter function for game data
	void SetGameDataManager( Brood::Application::Components::GameDataManager* a_gameDataManagerPtr );

	// ================= private member function ==================  
private:

	/// Initializes the edit mode tabs
	void InitializeEditModeTabs();

	/// checks if the ribbion tabs was pressed
	void UpdateEditModeTabs();

	// updates the edit Tab and selects the proper tab
	void UpdateActiveEditorIdx( unsigned a_idx );

	// ================= private member variables =================  
private:

	/// panel body
	sf::RectangleShape m_sidePanel;

	/// holds the index of current active editor workspace
	unsigned m_activeEditorIdx;
	
	/// Ui for edit modes tabs
	std::vector<Brood::BroodUI::Button*> m_editModesTabs;

	/// list of editor workspace
	std::vector<Brood::Application::WorkSpace*> m_editorWorkspaceList;
};

// ======================================================================
// ================= end of EditorWorkspace class =======================
// ======================================================================