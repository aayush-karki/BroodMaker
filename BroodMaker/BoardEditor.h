/*************************************************************************/
/// 
/// @file BoardEditor.h 
/// 
/// @brief  This file is a header file for BoardEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of BoardEditor class.
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
		class BoardEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of BoardEditor class =========================
// ======================================================================

/// 
/// @ingroup Application
/// @class BoardEditor  "BoardEditor.h"
/// @brief It alows the users to tweek the general game setting 
///		and game rules.
///
/// It is a container that bundels elements that is present 
///		in BoardEditor workspace
/// 
/// It contatins the folloing panel element: 
///		board X-postion, board Y-position, boardX-size,
///		board Y-Size, board row, board column
/// 
/// Derived form Workspace class
/// 
class Brood::Application::BoardEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	BoardEditor( Brood::Application::Components::GameDataManager* a_gameData,
				 sf::RectangleShape* a_panelPtr );

	// default destructor
	~BoardEditor();
	// ===== virtual funcitons ====

	// initializes the component of a workspace
	void InitializeWorkSpace();

	// all the logic for the workspace is here
	void Update();

	// updates all the display elment
	void UpdateAllDispayElement();

	// renders to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();

	// ===========================================================
	// =========== update for General Board setting ==============
	// ===========================================================

	// checks if the user interacted with the x size 
	// panel Element
	void UpdateBoardXSizePanelElement();

	// checks if the user interacted with the y size 
	// panel Element
	void UpdateBoardYSizePanelElement();

	// checks if the user interacted with the x position
	// panel Element
	void UpdateBoardXPosPanelElement();

	// checks if the user interacted with the y position
	// panel Element
	void UpdateBoardYPosPanelElement();

	// checks if the user interacted with the row 
	// panel Element
	void UpdateBoardRowPanelElement();

	// checks if the user interacted with the column
	// panel Element
	void UpdateBoardColPanelElement();

	// ================= private data member ======================  
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;
// ===========================================================
	// =========== member variables for General board setting ====
	// ===========================================================

	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	// ==== UI elements to change the board's x size ====

	/// holds the text Board X size prompt
	Brood::BroodUI::TextBox* m_txtBoardSizePromtX;

	/// clicking it will decrease the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeDecX;

	/// displays the board's x size 
	Brood::BroodUI::TextBox* m_txtBoardSizeX;

	/// clicking it will increase the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeIncX;

	// ==== UI elements to change the board's y size ====

	/// holds the text Board y size prompt
	Brood::BroodUI::TextBox* m_txtBoardSizePromtY;

	/// clicking it will decrease the board y size by 5
	Brood::BroodUI::Button* m_btnBoardSizeDecY;

	/// displays the board's y size 
	Brood::BroodUI::TextBox* m_txtBoardSizeY;

	/// clicking it will increase the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeIncY;

	// ==== UI elements to change the board's x position ====

	/// holds the text Board X position prompt
	Brood::BroodUI::TextBox* m_txtBoardPosPromtX;

	/// clicking it will decrease the board x position by 5
	Brood::BroodUI::Button* m_btnBoardPosDecX;

	/// displays the board's x position 
	Brood::BroodUI::TextBox* m_txtBoardPosX;

	/// clicking it will increase the board x position by 5
	Brood::BroodUI::Button* m_btnBoardPosIncX;

	// ==== UI elements to change the board's y position ====

	/// holds the text Board y position prompt
	Brood::BroodUI::TextBox* m_txtBoardPosPromtY;

	/// clicking it will decrease the board y position by 5
	Brood::BroodUI::Button* m_btnBoardPosDecY;

	/// displays the board's y position 
	Brood::BroodUI::TextBox* m_txtBoardPosY;

	/// clicking it will increase the board y position by 5
	Brood::BroodUI::Button* m_btnBoardPosIncY;

	// ==== UI elements to change the board's Row ====

	/// holds the text Board Row number prompt
	Brood::BroodUI::TextBox* m_txtBoardRowPromt;

	/// clicking it will decrease the board's row by 1
	Brood::BroodUI::Button* m_btnBoardDecRow;

	/// displays the board's Row number
	Brood::BroodUI::TextBox* m_txtBoardRow;

	/// clicking it will increase the board's row by 1
	Brood::BroodUI::Button* m_btnBoardIncRow;

	// ==== UI elements to change the board's Column ====

	/// holds the text Board Column number prompt
	Brood::BroodUI::TextBox* m_txtBoardColPromt;

	/// clicking it will decrease the board's Column by 1
	Brood::BroodUI::Button* m_btnBoardDecCol;

	/// displays the board's Column number
	Brood::BroodUI::TextBox* m_txtBoardCol;

	/// clicking it will increase the board's Column by 1
	Brood::BroodUI::Button* m_btnBoardIncCol;
};

// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================