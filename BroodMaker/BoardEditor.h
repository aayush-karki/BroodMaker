/*************************************************************************/
/// 
/// @file BoardEditor.h 
/// 
/// @brief  This file is a header file for BoardEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of BoardEditor class.
/// 
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "MenuBar.h" // includes all the other uiElements
#include "WorkSpace.h"
#include "Board.h"
#include "Dice.h"
#include "PlayerManager.h"

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
/// Derived form Workspace class
/// 
/// @todo allowd to enter number in the txt feild
/// 
class Brood::Application::BoardEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	BoardEditor( Brood::Application::Components::Board* a_boardPtr );

	// default destructor
	~BoardEditor();
	// ===== virtual funcitons ====

	// initializes the component of a workspace
	void InitializeWorkSpace();

	// all the logic for the workspace is here
	void Update();

	// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();

	// ================= private member function ==================  

	// Initializes the General Board Setting panel elements
	void InitailizeGeneralBoardSettingPanel();

	// Initializes the setting Section dropdown input
	void InitailizeSettingSelectionDDI();

	// ========= Update Funcitons ==============

	// checks if the user interacted with setting Selection
	//  and updates accordingly
	void UpdateSettingSelectionDDI();

	// checks if the user interacted with the x position panel Element
	void UpdateBoardXPosPanelElement();

	// checks if the user interacted with the y position panel Element
	void UpdateBoardYPosPanelElement();

	// checks if the user interacted with the x size panel Element
	void UpdateBoardXSizePanelElement();

	// checks if the user interacted with the y size panel Element
	void UpdateBoardYSizePanelElement();

	// checks if the user interacted with the row panel Element
	void UpdateBoardRowPanelElement();

	// checks if the user interacted with the column panel Element
	void UpdateBoardColPanelElement();

	// checks if the user interacted with the movement type panel Element
	void UpdateMovementTypePanelElement();

	// checks if the user interacted with the incorrect penalty panel Element
	void UpdateIncorrectPenaltyPanelElement();

	// ================= private data member ======================  
private:

	///> holds which setting is currently active
	unsigned m_selectedSettingIdx;


	///> holds the panel body
	sf::RectangleShape m_panel;

	///> holds which catagory of setting the displayed
	///>	user can choose between: General Board Setting, 
	///>	Player setting, and Dice setting
	Brood::BroodUI::DropDownInput* m_ddiSettingSelection;

	///> board for the game
	Brood::Application::Components::Board* m_boardPtr;

	///> dice list for the game
	std::vector<Brood::Application::Components::Dice*> m_diceList;

	Brood::Application::Components::PlayerManager m_playerManager;

	// ==== UI elements to change the board's x position ====

	///> holds the text Board X position
	Brood::BroodUI::TextBox* m_txtBoardPosPromtX;

	///> clicking it will decrease the board x position by 5
	Brood::BroodUI::Button* m_btnBoardPosDecX;

	/// ///> displays the board's x position 
	Brood::BroodUI::TextBox* m_txtBoardPosX;

	///> clicking it will increase the board x position by 5
	Brood::BroodUI::Button* m_btnBoardPosIncX;

	// ==== UI elements to change the board's y position ====

	///> holds the text Board y position
	Brood::BroodUI::TextBox* m_txtBoardPosPromtY;

	///> clicking it will decrease the board y position by 5
	Brood::BroodUI::Button* m_btnBoardPosDecY;

	/// ///> displays the board's y position 
	Brood::BroodUI::TextBox* m_txtBoardPosY;

	///> clicking it will increase the board y position by 5
	Brood::BroodUI::Button* m_btnBoardPosIncY;

	// ==== UI elements to change the board's x size ====

	///> holds the text Board X size
	Brood::BroodUI::TextBox* m_txtBoardSizePromtX;

	///> clicking it will decrease the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeDecX;

	/// ///> displays the board's x size 
	Brood::BroodUI::TextBox* m_txtBoardSizeX;

	///> clicking it will increase the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeIncX;

	// ==== UI elements to change the board's y size ====

	///> holds the text Board y size
	Brood::BroodUI::TextBox* m_txtBoardSizePromtY;

	///> clicking it will decrease the board y size by 5
	Brood::BroodUI::Button* m_btnBoardSizeDecY;

	/// ///> displays the board's y size 
	Brood::BroodUI::TextBox* m_txtBoardSizeY;

	///> clicking it will increase the board x size by 5
	Brood::BroodUI::Button* m_btnBoardSizeIncY;

	// ==== UI elements to change the board's Row ====

	///> holds the text Board Row number
	Brood::BroodUI::TextBox* m_txtBoardRowPromt;

	///> clicking it will decrease the board's row by 1
	Brood::BroodUI::Button* m_btnBoardDecRow;

	/// ///> displays the board's Row number
	Brood::BroodUI::TextBox* m_txtBoardRow;

	///> clicking it will increase the board's row by 1
	Brood::BroodUI::Button* m_btnBoardIncRow;

	// ==== UI elements to change the board's Column ====

	///> holds the text Board Column number
	Brood::BroodUI::TextBox* m_txtBoardColPromt;

	///> clicking it will decrease the board's Column by 1
	Brood::BroodUI::Button* m_btnBoardDecCol;

	/// ///> displays the board's Column number
	Brood::BroodUI::TextBox* m_txtBoardCol;

	///> clicking it will increase the board's Column by 1
	Brood::BroodUI::Button* m_btnBoardIncCol;

	// ==== UI elements to change the board movement rule ====

	///> holds the text Movement type
	Brood::BroodUI::TextBox* m_txtMovementTypePromt;

	///> holds how the player can move: dice, 
	///>	start with dice and then card, and 
	///>	card no dice
	Brood::BroodUI::DropDownInput* m_ddiMovementType;

	// ==== UI elements to change the board Penalty rule ====

	///> holds the text Movement type
	Brood::BroodUI::TextBox* m_txtIncorectPenaltyPromt;

	///> holds yes or no
	Brood::BroodUI::DropDownInput* m_ddiIncorectPenalty;

	// ==== UI elements to change the minimum player ====

	///> holds the text Required minimum player
	Brood::BroodUI::TextBox* m_txtPlayerMinNumPrompt;

	///> clicking it will decrease the minium required player number by 1
	Brood::BroodUI::Button* m_btnPlayerDecMinNum;

	/// ///> displays the Current minium required player number
	Brood::BroodUI::TextBox* m_txtPlayerMinNuml;

	///> clicking it will increase the minium required player number by 1
	Brood::BroodUI::Button* m_btnPlayerIncMinNum;
};

// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================
