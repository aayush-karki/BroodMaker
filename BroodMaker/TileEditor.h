/*************************************************************************/
/// 
/// @file TileEditor.h 
/// 
/// @brief  This file is a header file for TileEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of TileEditor class.
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
		class TileEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of TileEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class TileEditor  "TileEditor.h"
/// @brief It alows the users to tweek the tile setting
///
/// It is a container that bundels elements that is present 
///		in TileEditor workspace
/// 
/// Derived form Workspace class
/// 
/// @todo allowd to enter number in the txt feild
/// 
class Brood::Application::TileEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	TileEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~TileEditor();
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

	// checks if the user interacted with the tile row
	// number panel Element
	void UpdateTileRowNumber();

	// checks if the user interacted with the tile column
	// number panel Element
	void UpdateTileColNumber();

	// checks if the user interacted with the tile type
	// panel Element
	void UpdateTileType();

	// checks if the user interacted with the NextPath row
	// number panel Element
	void UpdateNextPathRowNumber();

	// checks if the user interacted with the NextPath column
	// number panel Element
	void UpdateNextPathColNumber();

	// checks if the user interacted with the EndBridge row
	// number panel Element
	void UpdateEndBridgeRowNumber();

	// checks if the user interacted with the EndBridge column
	// number panel Element
	void UpdateEndBridgeColNumber();

	// checks if the user interacted with the correct number 
	// of card panel Element
	void UpdateCorrectCardNumber();

	// checks if the user interacted with the assign deck idx
	// panel Element
	void UpdateAssinedDeckIdx();

	// checks if the user interacted with the force dice roll
	// panel Element
	void UpdateForceDiceRoll();

	// checks if the user interacted with the load 
	// tile texture panel Element
	void UpdateTileFileTexture();

	// ================= private member variable ==================  
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	// ===========================================================
	// =========== member variables for general game setting =====
	// ===========================================================

	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	// ==== UI elements to change the current tile Row ====

	/// holds the text Board Row number prompt
	Brood::BroodUI::TextBox* m_txtTileCurrRowPromt;

	/// clicking it will decrease the board's row by 1
	Brood::BroodUI::Button* m_btnTileDecCurrRow;

	/// displays the board's Row number
	Brood::BroodUI::TextBox* m_txtTileCurrRow;

	/// clicking it will increase the board's row by 1
	Brood::BroodUI::Button* m_btnTileIncCurrRow;

	// ==== UI elements to change the current tile Col ====

	/// holds the text Board Col number prompt
	Brood::BroodUI::TextBox* m_txtTileCurrColPromt;

	/// clicking it will decrease the board's Col by 1
	Brood::BroodUI::Button* m_btnTileDecCurrCol;

	/// displays the board's Col number
	Brood::BroodUI::TextBox* m_txtTileCurrCol;

	/// clicking it will increase the board's Col by 1
	Brood::BroodUI::Button* m_btnTileIncCurrCol;

	// ==== UI elements to change the Tile type ====

	/// holds the text Tile type prompt
	Brood::BroodUI::TextBox* m_txtTileTypePromt;

	/// type of the tiles: start tile,
	/// end tile, bridge Start tile, balnk tile
	Brood::BroodUI::DropDownInput* m_ddiTileType;

	// ==== UI elements to change the NextPath tile Row ====

	/// holds the text Board Row number prompt
	Brood::BroodUI::TextBox* m_txtTileNextPathRowPromt;

	/// clicking it will decrease the board's row by 1
	Brood::BroodUI::Button* m_btnTileDecNextPathRow;

	/// displays the board's Row number
	Brood::BroodUI::TextBox* m_txtTileNextPathRow;

	/// clicking it will increase the board's row by 1
	Brood::BroodUI::Button* m_btnTileIncNextPathRow;

	// ==== UI elements to change the NextPath tile Col ====

	/// holds the text Board Col number prompt
	Brood::BroodUI::TextBox* m_txtTileNextPathColPromt;

	/// clicking it will decrease the board's Col by 1
	Brood::BroodUI::Button* m_btnTileDecNextPathCol;

	/// displays the board's Col number
	Brood::BroodUI::TextBox* m_txtTileNextPathCol;

	/// clicking it will increase the board's Col by 1
	Brood::BroodUI::Button* m_btnTileIncNextPathCol;

	// ==== UI elements to change the EndBridge tile Row ====

	/// holds the text Board Row number prompt
	Brood::BroodUI::TextBox* m_txtTileEndBridgeRowPromt;

	/// clicking it will decrease the board's row by 1
	Brood::BroodUI::Button* m_btnTileDecEndBridgeRow;

	/// displays the board's Row number
	Brood::BroodUI::TextBox* m_txtTileEndBridgeRow;

	/// clicking it will increase the board's row by 1
	Brood::BroodUI::Button* m_btnTileIncEndBridgeRow;

	// ==== UI elements to change the EndBridge tile Col ====

	/// holds the text Board Col number prompt
	Brood::BroodUI::TextBox* m_txtTileEndBridgeColPromt;

	/// clicking it will decrease the board's Col by 1
	Brood::BroodUI::Button* m_btnTileDecEndBridgeCol;

	/// displays the board's Col number
	Brood::BroodUI::TextBox* m_txtTileEndBridgeCol;

	/// clicking it will increase the board's Col by 1
	Brood::BroodUI::Button* m_btnTileIncEndBridgeCol;

	// ==== UI elements to change the tile's NumCorrectCard ====

	/// holds the text tile's NumCorrectCard  prompt
	Brood::BroodUI::TextBox* m_txtTileNumCorrectCardPromt;

	/// clicking it will decrease the tile's NumCorrectCard by 1
	Brood::BroodUI::Button* m_btnTileDecNumCorrectCard;

	/// displays the tile's NumCorrectCard number
	Brood::BroodUI::TextBox* m_txtTileNumCorrectCard;

	/// clicking it will increase the tile's NumCorrectCard by 1
	Brood::BroodUI::Button* m_btnTileIncNumCorrectCard;

	// ==== UI elements to change the AssignDeckNum tile ====

	/// holds the text tile's assigned DeckIdx prompt
	Brood::BroodUI::TextBox* m_txtTileAssignedDeckIdxPromt;

	/// clicking it will decrease the tile's DeckIdx by 1
	Brood::BroodUI::Button* m_btnTileDecAssignedDeckIdx;

	/// displays the tile's DeckIdx  
	Brood::BroodUI::TextBox* m_txtTileAssignedDeckIdx;

	/// clicking it will increase the tile's DeckIdx by 1
	Brood::BroodUI::Button* m_btnTileIncAssignedDeckIdx;

	// ==== UI elements to change tile force dice Roll rule ====

	/// holds the text Force dice prompt
	Brood::BroodUI::TextBox* m_txtTileForceDiceRollPromt;

	/// holds yes or no
	Brood::BroodUI::DropDownInput* m_ddiTileForceDiceRoll;

	// ==== UI elements to enter a Tile filename texture  ====

	/// holds the Tile texture filename prompt
	Brood::BroodUI::TextBox* m_txtTileBgFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtTileBgFileInput;

	/// clicking it will load the Tile file
	Brood::BroodUI::Button* m_btnTileBgOpenFile;


};

// ======================================================================
// ================= end of TileEditor class ============================
// ======================================================================
