/*************************************************************************/
/// 
/// @file DiceEditor.h 
/// 
/// @brief  This file is a header file for DiceEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DiceEditor class.
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
		class DiceEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DiceEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class DiceEditor  "DiceEditor.h"
/// @brief It alows the users to tweek the dice setting
///
/// It is a container that bundels elements that is present 
///		in DiceEditor workspace
/// 
/// It has the folloing panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works
/// 
/// Derived form Workspace class
/// 
class Brood::Application::DiceEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	DiceEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~DiceEditor();
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

	// ================= private member function ================== 	
private:
	// ===========================================================
	// =========== update for Dice setting =======================
	// ===========================================================

	// checks if the user interacted with the Dice 
	// side number panel Element
	void UpdateDiceSideNum();

	// checks if the user interacted with the Dice 
	// x size panel Element
	void UpdateDiceSizeX();

	// checks if the user interacted with the Dice 
	// y Pos panel Element
	void UpdateDiceSizeY();

	// checks if the user interacted with the Dice 
	// x size panel Element
	void UpdateDicePosX();

	// checks if the user interacted with the Dice 
	// y Pos panel Element
	void UpdateDicePosY();

	// checks if the user interacted with the load 
	// Dice texture panel Element
	void UpdateDiceFileTexture();

	// checks if the user interacted with the 
	// roll dice button
	void UpdateRollDice();
	// ================= private member variable ==================  
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// board for the game
	Brood::Application::Components::Board* m_boardPtr;

	/// pointer to the deck manager
	Brood::Application::Components::Dice* m_dicePtr;

	// ===========================================================
	// =========== member variables for dice setting =============
	// ===========================================================
	
	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	// ==== UI elements to change dice sides ====

	/// holds the text Dice side
	Brood::BroodUI::TextBox* m_txtDiceSidePrompt;

	/// clicking it will decrease the Diceside number by 1
	Brood::BroodUI::Button* m_btnDiceDecSide;

	/// displays the  Dice Side
	Brood::BroodUI::TextBox* m_txtDiceSide;

	/// clicking it will increase the Dice Side number by 1
	Brood::BroodUI::Button* m_btnDiceIncSide;

	// ==== UI elements to change x-size of dice ====

	/// holds the text Dice X-Size
	Brood::BroodUI::TextBox* m_txtDiceSizeXPrompt;

	/// clicking it will decrease the  Dice x-size number by 5
	Brood::BroodUI::Button* m_btnDiceDecSizeX;

	/// displays the  Dice x-size
	Brood::BroodUI::TextBox* m_txtDiceSizeX;

	/// clicking it will increase the  Dice x-size number by 5
	Brood::BroodUI::Button* m_btnDiceIncSizeX;

	// ==== UI elements to change y-size of  y-size Index ====

	/// holds the text Dice y-Size
	Brood::BroodUI::TextBox* m_txtDiceSizeYPrompt;

	/// clicking it will decrease the  Dice y-size number by 5
	Brood::BroodUI::Button* m_btnDiceDecSizeY;

	/// displays the  Dice y-size
	Brood::BroodUI::TextBox* m_txtDiceSizeY;

	/// clicking it will increase the  Dice y-size number by 5
	Brood::BroodUI::Button* m_btnDiceIncSizeY;

	// ==== UI elements to change x-Pos of  Dice Index ====

	/// holds the text Dice X-Pos
	Brood::BroodUI::TextBox* m_txtDicePosXPrompt;

	/// clicking it will decrease the  Dice X-Pos number by 5
	Brood::BroodUI::Button* m_btnDiceDecPosX;

	/// displays the  Dice X-Pos
	Brood::BroodUI::TextBox* m_txtDicePosX;

	/// clicking it will increase the  Dice X-Pos number by 5
	Brood::BroodUI::Button* m_btnDiceIncPosX;

	// ==== UI elements to change y-Pos of  Dice Index ====

	/// holds the text Dice y-Pos prompt
	Brood::BroodUI::TextBox* m_txtDicePosYPrompt;

	/// clicking it will decrease the  Dice y-Pos number by 5
	Brood::BroodUI::Button* m_btnDiceDecPosY;

	/// displays the  Dice y-Pos
	Brood::BroodUI::TextBox* m_txtDicePosY;

	/// clicking it will increase the  Dice y-Pos number by 5
	Brood::BroodUI::Button* m_btnDiceIncPosY;

	// ==== UI elements to enter a filename texture  ====

	/// holds the Dice texture filename prompt
	Brood::BroodUI::TextBox* m_txtDiceFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtDiceFileInput;

	/// clicking it will load the Dice file
	Brood::BroodUI::Button* m_btnDiceOpenFile;

	// ==== UI elements to change Dice sprite ====

	/// Rolls the dice

	/// clicking it will decrease the  Dice y-Pos number by 5
	Brood::BroodUI::Button* m_btnRollDice;


};

// ======================================================================
// ================= end of DiceEditor class ============================
// ======================================================================
