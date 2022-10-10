/*************************************************************************/
/// 
/// @file DeckEditor.h 
/// 
/// @brief  This file is a header file for DeckEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DeckEditor class.
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
		class DeckEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DeckEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class TileEditor  "DeckEditor.h"
/// @brief It alows the users to tweek the deck setting
///
/// It is a container that bundels elements that is present 
///		in DeckEditor workspace
/// 
/// Derived form Workspace class
/// 
class Brood::Application::DeckEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	DeckEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~DeckEditor();
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

	// checks if the user interacted current deck index
	// panel Element
	void UpdateCurrSelectedDeckIdx();

	// checks if the user interacted with the Deck 
	// x size panel Element
	void UpdateDeckSizeX();

	// checks if the user interacted with the Deck 
	// y Pos panel Element
	void UpdateDeckSizeY();

	// checks if the user interacted with the Deck 
	// x size panel Element
	void UpdateDeckPosX();

	// checks if the user interacted with the Deck 
	// y Pos panel Element
	void UpdateDeckPosY();

	// checks if the user interacted with the load 
	// deck texture panel Element
	void UpdateDeckFileTexture();

	// checks if the user interacted with the load 
	// card init file panel Element
	void UpdateCardInitFile();

	// checks if the user interacted with the number 
	// of card panel Element
	void UpdateCardNumber();

	// ================= private member variable ==================  
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	// ===========================================================
	// =========== member variables for deck setting =============
	// ===========================================================

	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	// ==== UI elements to change deck current index ====

	/// holds the text deck current index
	Brood::BroodUI::TextBox* m_txtDeckCurrIdxPrompt;

	/// clicking it will decrease the deck current index number by 1
	Brood::BroodUI::Button* m_btnDeckDecCurrIdx;

	/// displays the current deck current index
	Brood::BroodUI::TextBox* m_txtDeckCurrIdx;

	/// clicking it will increase the deck current index number by 1
	Brood::BroodUI::Button* m_btnDeckIncCurrIdx;

	// ==== UI elements to change deck size x ====

	/// holds the text deck size x
	Brood::BroodUI::TextBox* m_txtDeckSizeXPrompt;

	/// clicking it will decrease the deck size x number by 1
	Brood::BroodUI::Button* m_btnDeckDecSizeX;

	/// displays the current deck size X
	Brood::BroodUI::TextBox* m_txtDeckSizeX ;

	/// clicking it will increase the deck size x number by 1
	Brood::BroodUI::Button* m_btnDeckIncSizeX;

	// ==== UI elements to change deck size y ====

	/// holds the text deck size y
	Brood::BroodUI::TextBox* m_txtDeckSizeYPrompt;

	/// clicking it will decrease the deck size y number by 1
	Brood::BroodUI::Button* m_btnDeckDecSizeY;

	/// displays the current deck size y
	Brood::BroodUI::TextBox* m_txtDeckSizeY;

	/// clicking it will increase the deck size y number by 1
	Brood::BroodUI::Button* m_btnDeckIncSizeY;

	// ==== UI elements to change deck position x ====

	/// holds the text deck position x
	Brood::BroodUI::TextBox* m_txtDeckPosXPrompt;

	/// clicking it will decrease the deck Position x number by 5
	Brood::BroodUI::Button* m_btnDeckDecPosX;

	/// displays the current deck Position X
	Brood::BroodUI::TextBox* m_txtDeckPosX;

	/// clicking it will increase the deck Position x number by 5
	Brood::BroodUI::Button* m_btnDeckIncPosX;

	// ==== UI elements to change deck Position y ====

	/// holds the text deck Position y
	Brood::BroodUI::TextBox* m_txtDeckPosYPrompt;

	/// clicking it will decrease the deck Position y number by 5
	Brood::BroodUI::Button* m_btnDeckDecPosY;

	/// displays the current deck Position y
	Brood::BroodUI::TextBox* m_txtDeckPosY;

	/// clicking it will increase the deck Position y number by 5
	Brood::BroodUI::Button* m_btnDeckIncPosY;

	// ==== UI elements to enter a deck filename texture  ====

	/// holds the Deck texture filename prompt
	Brood::BroodUI::TextBox* m_txtDeckBgFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtDeckBgFileInput;

	/// clicking it will load the Deck file
	Brood::BroodUI::Button* m_btnDeckBgOpenFile;

	// ==== UI elements to enter a filename for card init  ====

	/// holds the CardInit texture filename prompt
	Brood::BroodUI::TextBox* m_txtCardInitFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtCardInitFileInput;

	/// clicking it will load the CardInit file
	Brood::BroodUI::Button* m_btnCardInitOpenFile;

	// ==== UI elements to change number of cards in the deck ====

	/// holds the text number of cards
	Brood::BroodUI::TextBox* m_txtCardNumPrompt;

	/// clicking it will decrease the number of cards by 1
	Brood::BroodUI::Button* m_btnDecCardNum;

	/// displays the current number of cards in the deck
	Brood::BroodUI::TextBox* m_txtCardNum;

	/// clicking it will increase the number of cards by 1
	Brood::BroodUI::Button* m_btnIncCardNum;
};

// ======================================================================
// ================= end of DeckEditor class ============================
// ======================================================================