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
#pragma once
#include "MenuBar.h" // includes all the other uiElements
#include "WorkSpace.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class InitialWorkSpace;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup Application
/// @class BoardEditor  "InitialWorkSpace.h"
/// @brief It is a container that bundels elements that is present in
///		InitialWorkSpace workspace
/// 
/// Initial WorkSpace where the user can chose weather to load a game file and 
///		go into game mode or alternatively to go into editor mode and work on 
///		previous game edits or start a new game project
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

	// ================= private member variables =================  
private:
	// main uielement which shows the list of stored game files and editor files
	Brood::BroodUI::Button* m_gameOrEditor; 
	Brood::BroodUI::Button* m_toggleGameInfoLeft;
	Brood::BroodUI::Button* m_toggleGameInfoRight;

	/// @TODO create this as a verticalmenus and delete them from
	/// all the function
	bool m_showImportDialogBox;
	Brood::BroodUI::Button* m_importGame;
	Brood::BroodUI::Button* m_loadPreviousEdits;
	Brood::BroodUI::Button* m_createNewEdit;
	Brood::BroodUI::Button* m_cancle;

	bool m_showEnterFilenameDialogBox;
	Brood::BroodUI::TextBox* m_fileName;
	Brood::BroodUI::TextBox* m_enterFileNameFeild;
	Brood::BroodUI::Button* m_openFile;
	Brood::BroodUI::Button* m_cancleSmall;
	
	// store the list of file path that corresponds to the game or editor file
	std::vector<std::string> m_gameInfoFilePathList;

	// list of texture to show in the gamOrEditor button 
	std::vector<sf::Texture> m_gameListTexture; 

	int m_currGameInfoIdx; // index of the file that is loaded by the main button
	sf::Font m_font;
};

