/*************************************************************************/
/// 
/// @file InitialWorkSpace.h 
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

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class InitialWorkSpace;
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
/// @class InitialWorkSpace  "InitialWorkSpace.h"
/// @brief It is a container that bundels elements that is present in
///		InitialWorkSpace workspace
/// 
/// Initial WorkSpace is where the user can chose weather to load a game file 
///		and go into game mode to play previously made games or alternatively 
///		to go into editor mode and work on previous game edits or start a new 
///		game project.
/// 
/// Derived from the WorkSpace class 
/// 
class Brood::Application::InitialWorkSpace : public Brood::Application::WorkSpace
{
	// ================= public member variables =================  
public:
	// default constructor
	InitialWorkSpace();
	// default destructor
	~InitialWorkSpace();

	// override functions
	virtual void InitializeWorkSpace() override;
	virtual void Update(); // all the logic for the workspace is here
	virtual void Draw( sf::RenderWindow& a_window ); // draw to the screen
	virtual void Debugger(); // debugger

	// ================= private member variables =================  
private:
	// main uielement which shows the list of stored game files and editor files
	Brood::BroodUI::Button* m_gameOrEditor;  ///> main card that is in the middle of the screen that shows the current game/edit list
	Brood::BroodUI::Button* m_toggleGameInfoLeft; ///> button to toggle left through the games/edits list
	Brood::BroodUI::Button* m_toggleGameInfoRight; ///> button to toggle right through the games/edits list

	/// @TODO make this into vertical menus once it is created

	int m_currGameInfoIdx; // index of the file that is loaded by the main button

	bool m_showImportDialogBox; ///> true to show the import dialog box
	Brood::BroodUI::Button* m_importGame; ///> button to import games
	Brood::BroodUI::Button* m_loadPreviousEdits;  ///> button to load previous edits
	Brood::BroodUI::Button* m_createNewEdit; ///> button to create new edit
	Brood::BroodUI::Button* m_cancle; ///> button to close the dialog box

	bool m_showEnterFilenameDialogBox; ///> true to show the filename dialog box
	Brood::BroodUI::TextBox* m_fileName; ///> stores the filename prompt
	Brood::BroodUI::TextBox* m_enterFileNameFeild;  ///> place to enter the filename
	Brood::BroodUI::Button* m_openFile; ///> button to open the entered file name

	// store the list of file path that corresponds to the game or editor file
	std::vector<std::string> m_gameInfoFilePathList;

	// list of texture to show in the gamOrEditor button 
	std::vector<sf::Texture> m_gameListTexture; 
};

// ======================================================================
// ================= end of InitialWorkSpace class ======================
// ======================================================================
