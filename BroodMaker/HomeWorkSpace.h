/*************************************************************************/
/// 
/// @file HomeWorkSpace.h 
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
#include "EditorWorkspace.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class HomeWorkSpace;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of InitialWorkSpace class ====================
// ======================================================================

/// 
/// @ingroup Application
/// @class HomeWorkSpace  "HomeWorkSpace.h"
/// @brief It is the underlying entry to the application. It is the true
///		entry point for the application.
/// 
///	It creates ribbion tabs which is accessable from anywhere in the 
///		applicaiton.
/// 
/// It comprises of 3 workspace, namely Initial WorkSpace, Editor workspace, 
///		and game workspace.
/// 
/// Initial WorkSpace is the homeworkspace. that is to say that the 
///		it controls wheter to switch to Editor workspace, or game workspace, ot
///		to itself. It is where the user can chose weather to load a game file 
///		and go into game mode to play previously made games or alternatively 
///		to go into editor mode and work on previous game edits or start a new 
///		game project.
/// 
/// Editor workspace is where user can make new games and export the created game
///		to play in the game workspace.
/// 
/// Game workspace is where the user can play the created game.
/// 
/// Derived from the WorkSpace class 
/// 
class Brood::Application::HomeWorkSpace :
	public Brood::Application::WorkSpace
{
	// ================= public member variables =================  
public:
	// default constructor
	HomeWorkSpace();

	// default destructor
	~HomeWorkSpace();

	// override functions
	virtual void InitializeWorkSpace() override;

	// all the logic for the workspace is here
	virtual void Update();

	// updates all the display elment
	void UpdateAllDispayElement();

	// draw to the screen
	virtual void Draw( sf::RenderWindow& a_window );


	// debugger
	virtual void Debugger();

	// ================= private member function =================  
private:
	///> Initialize the Ribbion Tabs
	void InitializeRibbionTabs();

	///> checks if the ribbion tabs was pressed
	void UpdateRibbionTabs();

	///> executes the menu item at the passed indexs
	void ExecuteMenuItem( unsigned a_iIdx, unsigned a_jIdx );

	/// executes the logic for dialog box
	void UpdateHomeWorkspace();

	// ================= private member variables =================  
private:

	///> Ui for ribbon tabs
	Brood::BroodUI::MenuBar m_ribbionTabs;

	// main uielement which shows the list of stored game files and
	// editor files

	sf::RectangleShape m_gameOrEditorForeground;

	///> main card that is in the middle of the screen that 
	///		shows the current game/edit list
	Brood::BroodUI::Button* m_gameOrEditorBtn;

	///> button to toggle left through the games/edits list
	Brood::BroodUI::Button* m_toggleGameInfoLeftBtn;

	///> button to toggle right through the games/edits list
	Brood::BroodUI::Button* m_toggleGameInfoRightBtn;

	///> index of the file that is loaded by the main button
	int m_currGameInfoIdx;

	///> true to show the import dialog box
	bool m_showImportDialogBox;

	///> button to import games
	Brood::BroodUI::Button* m_importGameBtn;

	///> button to load previous edits
	Brood::BroodUI::Button* m_loadPreviousEditsBtn;

	///> button to create new edit
	Brood::BroodUI::Button* m_createNewEditBtn;

	///> button to close the dialog box
	Brood::BroodUI::Button* m_cancleBtn;

	///> true to show the filename dialog box
	bool m_showEnterFilenameDialogBox;

	///> stores the filename prompt
	Brood::BroodUI::TextBox* m_fileNameTxt;

	///> place to enter the filename
	Brood::BroodUI::TextBox* m_enterFileNameFeildTxt;

	///> button to open the entered file name
	Brood::BroodUI::Button* m_openFileBtn;

	///> store the list of file path that corresponds to the game or editor file
	std::vector<std::string> m_gameInfoFilePathList;

	///> list of texture to show in the gamOrEditor button 
	std::vector<sf::Texture> m_gameListTexture;

	///> list of workspace that the application uses.
	///>	It holds 2 workspace, namely, editorWorSpace, and game workspace.
	std::vector<Brood::Application::WorkSpace*> m_workSpacesList;

	/// holds which workspace the applicaiton is currently on,
	///		0 means editor workspace, 1 means game workspace
	unsigned m_currWorkSpaceIdx;

	/// holds wheter current active workspace is initial workspace or
	///		game/edit workspace
	bool m_isHomeWorkspace;
};

// ======================================================================
// ================= end of InitialWorkSpace class ======================
// ======================================================================
