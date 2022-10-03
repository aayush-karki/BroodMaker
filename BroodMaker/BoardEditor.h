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
	BoardEditor( Brood::Application::Components::Board* a_boardPtr,
				 Brood::Application::Components::Dice* a_dicePtr,
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

	// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();

	// ================= private member function ==================  

	// Initializes the setting Section dropdown input
	void InitailizeSettingSelectionDDI();

	// Initializes the General Board Setting panel elements
	void InitailizeGeneralBoardSettingPanel();

	// Updates the General Board Setting panel elements
	void UpdateGeneralBoardSettingPanel();

	// Draws the General Board Setting panel elements
	void DrawGeneralBoardSettingPanel( sf::RenderWindow& a_window );

	// Initializes the Player Setting panel elements
	void InitailizePlayerSettingPanel();

	// Updates the Player Setting panel elements
	void UpdatePlayerSettingPanel();

	// Draws the General Board Setting panel elements
	void DrawPlayerSettingPanel( sf::RenderWindow& a_window );

	// Initializes the Dice Setting panel elements
	void InitailizeDiceSettingPanel();

	// Updates the Dice Setting panel elements
	void UpdateDiceSettingPanel();

	// Draws the Dice Setting panel elements
	void DrawDiceSettingPanel( sf::RenderWindow& a_window );

	// changes the displayed data on the panel 
	// of player current activeindex
	void ChangeDisplayedPlayerData();

	// ========= helper Update Funcitons ==============

	// ===========================================================
	// =========== update for General Board setting ==============
	// ===========================================================

	// checks if the user interacted with setting Selection
	//  and updates accordingly
	void UpdateSettingSelectionDDI();

	// checks if the user interacted with the x position
	// panel Element
	void UpdateBoardXPosPanelElement();

	// checks if the user interacted with the y position
	// panel Element
	void UpdateBoardYPosPanelElement();

	// checks if the user interacted with the x size 
	// panel Element
	void UpdateBoardXSizePanelElement();

	// checks if the user interacted with the y size 
	// panel Element
	void UpdateBoardYSizePanelElement();

	// checks if the user interacted with the row 
	// panel Element
	void UpdateBoardRowPanelElement();

	// checks if the user interacted with the column
	// panel Element
	void UpdateBoardColPanelElement();

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

	// checks if the user interacted with the toggle
	// draw player at current index
	void UpdateToggleDrawPlayerAtCurrIdx();

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


	// ================= private data member ======================  
private:

	/// @todo now start tile row and column
	/// @todo now add a current active player selector that
	///		 ranges from 0 to max player num
// changing it updates the player feilds like size, offset


	/// holds which setting is currently active
	unsigned m_selectedSettingIdx;

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// holds which catagory of setting the displayed
	///	user can choose between: General Board Setting, 
	///	Player setting, and Dice setting
	Brood::BroodUI::DropDownInput* m_ddiSettingSelection;

	/// board for the game
	Brood::Application::Components::Board* m_boardPtr;

	/// dice for the game
	Brood::Application::Components::Dice* m_dicePtr;

	Brood::Application::Components::PlayerManager m_playerManager;

	bool m_drawCurretntActivePlayer;

	// ===========================================================
	// =========== member variables for General board setting ====
	// ===========================================================

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

	// ===========================================================
	// =========== member variables for player setting ===========
	// ===========================================================

	// ==== UI elements to change the start row for player ====

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

	// ===========================================================
	// =========== member variables for dice setting =============
	// ===========================================================

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
// ================= end of BoardEditor class ===========================
// ======================================================================