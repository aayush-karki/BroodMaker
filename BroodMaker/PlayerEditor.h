/*************************************************************************/
/// 
/// @file PlayerEditor.h 
/// 
/// @brief  This file is a header file for PlayerEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of PlayerEditor class.
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
		class PlayerEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of PlayerEditor class ========================
// ======================================================================

/// 
/// @ingroup Application
/// @class PlayerEditor  "PlayerEditor.h"
/// @brief It alows the users to tweek the player setting
///
/// It is a container that bundels elements that is present 
///		in PlayerEditor workspace
/// 
/// It allows to tweek the following settings: 
///		Player start row, Player start column,
///		Current player index, Draw current 
///		player, Current player X-Size, current player Y-size, 
///		Current player X-offset, Current player Y-offset, and
///		Current player texture file name
/// 
/// Derived form Workspace class
/// 
class Brood::Application::PlayerEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	PlayerEditor( Brood::Application::Components::GameDataManager* a_gameData,
				  sf::RectangleShape* a_panelPtr );

	// default destructor
	~PlayerEditor();
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

	// ===========================================================
	// =========== update for Player setting =====================
	// ===========================================================

	// checks if the user interacted with the start row
	// number panel Element
	void UpdateStartRowNumber();

	// checks if the user interacted with the start column
	// number panel Element
	void UpdateStartColNumber();

	// checks if the user interacted with the current
	// selceted player index panel Element
	void UpdateCurrSelectedPlayerIdx();

	// checks if the user interacted with the player 
	// x size panel Element
	void UpdateCurrPlayerSizeX();

	// checks if the user interacted with the player 
	// y Offset panel Element
	void UpdateCurrPlayerSizeY();

	// checks if the user interacted with the player 
	// x size panel Element
	void UpdateCurrPlayerOffsetX();

	// checks if the user interacted with the player 
	// y Offset panel Element
	void UpdateCurrPlayerOffsetY();

	// checks if the user interacted with the load 
	// player texture panel Element
	void UpdateCurrPlayerFileTexture();

	// ================= private member variable ==================  
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// board for the game
	Brood::Application::Components::Board* m_boardPtr;

	/// pointer to the player manager
	Brood::Application::Components::PlayerManager* m_playerManagerPtr;


	// ===========================================================
	// =========== member variables for player setting ===========
	// ===========================================================

	// ==== UI elements to change the start row for player ====

	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	/// holds the text start row prompt
	Brood::BroodUI::TextBox* m_txtPlayerStartRowPrompt;

	/// clicking it will decrease the start row of player number by 1
	Brood::BroodUI::Button* m_btnPlayerDecStartRowNum;

	/// displays the Current start row number of the player
	Brood::BroodUI::TextBox* m_txtPlayerStartRowNum;

	/// clicking it will increase the  start row of the player number by 1
	Brood::BroodUI::Button* m_btnPlayerIncStartRowNum;

	// ==== UI elements to change the start column for player ====

	/// holds the text start column prompt
	Brood::BroodUI::TextBox* m_txtPlayerStartColPrompt;

	/// clicking it will decrease the start column of player number by 1
	Brood::BroodUI::Button* m_btnPlayerDecStartColNum;

	/// displays the Current start column number of the player
	Brood::BroodUI::TextBox* m_txtPlayerStartColNum;

	/// clicking it will increase the  start column of the player number by 1
	Brood::BroodUI::Button* m_btnPlayerIncStartColNum;

	// ============ UI elements to change current selected player Index ============

	/// holds the text selected Index prompt
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxPrompt;

	/// clicking it will decrease the current selected player Index number by 1
	Brood::BroodUI::Button* m_btnPlayerDecCurrIdx;

	/// displays the current selected player Index
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdx;

	/// clicking it will increase the current selected player Indexr number by 1
	Brood::BroodUI::Button* m_btnPlayerIncCurrIdx;

	// ==== UI elements toggle draw player at current index ====

	/// holds the text Current Player Index prompt
	Brood::BroodUI::TextBox* m_txtDrawPlayerAtCurrIdxPromt;

	/// holds if the player at current index is to be draw
	/// or not
	Brood::BroodUI::DropDownInput* m_ddiDrawPlayerAtCurrIdx;

	// ==== UI elements to change x-size of current selected player Index ====

	/// holds the text Player X-Size
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxSizeXPrompt;

	/// clicking it will decrease the current selected player x-size number by 5
	Brood::BroodUI::Button* m_btnPlayerDecCurrIdxSizeX;

	/// displays the current selected player x-size
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxSizeX;

	/// clicking it will increase the current selected player x-size number by 5
	Brood::BroodUI::Button* m_btnPlayerIncCurrIdxSizeX;

	// ==== UI elements to change y-size of current selected y-size Index ====

	/// holds the text Player y-Size
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxSizeYPrompt;

	/// clicking it will decrease the current selected player y-size number by 5
	Brood::BroodUI::Button* m_btnPlayerDecCurrIdxSizeY;

	/// displays the current selected player y-size
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxSizeY;

	/// clicking it will increase the current selected player y-size number by 5
	Brood::BroodUI::Button* m_btnPlayerIncCurrIdxSizeY;

	// ==== UI elements to change x-offset of current selected player Index ====

	/// holds the text Player X-Offset
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxOffsetXPrompt;

	/// clicking it will decrease the current selected player X-Offset number by 5
	Brood::BroodUI::Button* m_btnPlayerDecCurrIdxOffsetX;

	/// displays the current selected player X-Offset
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxOffsetX;

	/// clicking it will increase the current selected player X-Offset number by 5
	Brood::BroodUI::Button* m_btnPlayerIncCurrIdxOffsetX;

	// ==== UI elements to change y-offset of current selected player Index ====

	/// holds the text Player y-Offset prompt
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxOffsetYPrompt;

	/// clicking it will decrease the current selected player y-Offset number by 5
	Brood::BroodUI::Button* m_btnPlayerDecCurrIdxOffsetY;

	/// displays the current selected player y-Offset
	Brood::BroodUI::TextBox* m_txtPlayerCurrIdxOffsetY;

	/// clicking it will increase the current selected player y-Offset number by 5
	Brood::BroodUI::Button* m_btnPlayerIncCurrIdxOffsetY;

	// ==== UI elements to enter a filename texture  ====

	/// holds the Player texture filename prompt
	Brood::BroodUI::TextBox* m_txtplayerFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtPlayerFileInput;

	/// clicking it will load the player file
	Brood::BroodUI::Button* m_btnPlayerOpenFile;

};

// ======================================================================
// ================= end of PlayerEditor class ==========================
// ======================================================================