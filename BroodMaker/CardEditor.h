/*************************************************************************/
/// 
/// @file CardEditor.h 
/// 
/// @brief  This file is a header file for CardEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of CardEditor class.
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
		class CardEditor;
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
/// @class CardEditor  "CardEditor.h"
/// @brief It alows the users to tweek the card setting
///
/// It is a container that bundels elements that is present 
///		in CardEditor workspace
/// 
/// Derived form Workspace class
/// 
class Brood::Application::CardEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	CardEditor( Brood::Application::Components::GameDataManager* a_gameData,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~CardEditor();
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

	// initializes the setting DDM
	void InitailizeSettingSelectionDDI();

	// updates the setting DDM
	void UpdateSettingSelectionDDI();

	// initializes the card display panel element
	void InializeCardDisplayPanel();

	// Update the card display panel element
	void UpdateCardDisplayPanel();

	// Draw the card display panel element
	void DrawCardDisplayPanel( sf::RenderWindow& a_window );

	// initializes the card display front component panel element
	void InializeCardDisplayFcompPanel();

	// Update the card display front component panel element
	void UpdateCardDisplayFcompPanel();

	// Draw the card display front component panel element
	void DrawCardDisplayFcompPanel( sf::RenderWindow& a_window );

	// initializes the card display back component panel element
	void InializeCardDisplayBcompPanel();

	// Update the card display back component panel element
	void UpdateCardDisplayBcompPanel();

	// Draw the card display back component panel element
	void DrawCardDisplayBcompPanel( sf::RenderWindow& a_window );

	// initializes the card info panel element
	void InializeCardInfoPanel();

	// Update the card info panel element
	void UpdateCardInfoPanel();

	// Draw the card info panel element
	void DrawCardInfoPanel( sf::RenderWindow& a_window );

	
	// ===========================================================
	// =========== update functions for card display setting ======
	// ===========================================================


	// checks if the user interacted with the load 
	// Card texture panel Element
	void UpdateCardFrontFileTexture();

	// checks if the user interacted with the load 
	// Card texture panel Element
	void UpdateCardBackFileTexture();

	// checks if the user interacted with the 
	// current selceted deck index panel
	void UpdateCurrSelectedDeckIdx();

	// checks if the user interacted with the 
	// current selceted Card index panel
	void UpdateCurrSelectedCardIdx();

	// checks if the user interacted with the 
	// time panel
	void UpdateCurrCardInfoTime();

	// checks if the user interacted with the 
	// Up panel
	void UpdateCurrCardInfoUp();

	// checks if the user interacted with the 
	// Down panel
	void UpdateCurrCardInfoDown();

	// checks if the user interacted with the
	// enter curr card question panel element
	void UpdateCurrCardQuestionInput();

	// checks if the user interacted with the
	// enter curr card answer panel element
	void UpdateCurrCardAnswerInput();

	// checks if the user interacted with the
	// turn card panel element
	void UpdateTurnCard();

	// ================= private member variable ==================  
private:

	/// pointer to the game data
	Brood::Application::Components::GameDataManager* m_gameData;

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	// holds which setting it is displaying
	unsigned m_selectedSettingIdx;

	/// holds which catagory of setting the displayed
	///	user can choose between: Display card Setting, 
	/// Display card front componet Setting,
	/// Display card back componet Setting
	///	Existing info Card Setting
	Brood::BroodUI::DropDownInput* m_ddiSettingSelection;

	// ===========================================================
	// =========== member variables for card display setting =====
	// ===========================================================

	// ==== UI elements to change CardFrontTimePrompt size x ====

	/// holds the text Card size x
	Brood::BroodUI::TextBox* m_txtCardSizeXPrompt;

	/// clicking it will decrease the Card size x number by 1
	Brood::BroodUI::Button* m_btnCardDecSizeX;

	/// displays the current Card size X
	Brood::BroodUI::TextBox* m_txtCardSizeX;

	/// clicking it will increase the Card size x number by 1
	Brood::BroodUI::Button* m_btnCardIncSizeX;

	// ==== UI elements to change Card size y ====

	/// holds the text Card size y
	Brood::BroodUI::TextBox* m_txtCardSizeYPrompt;

	/// clicking it will decrease the Card size y number by 1
	Brood::BroodUI::Button* m_btnCardDecSizeY;

	/// displays the current Card size y
	Brood::BroodUI::TextBox* m_txtCardSizeY;

	/// clicking it will increase the Card size y number by 1
	Brood::BroodUI::Button* m_btnCardIncSizeY;

	// ==== UI elements to change Card position x ====

	/// holds the text Card position x
	Brood::BroodUI::TextBox* m_txtCardPosXPrompt;

	/// clicking it will decrease the Card Position x number by 5
	Brood::BroodUI::Button* m_btnCardDecPosX;

	/// displays the current Card Position X
	Brood::BroodUI::TextBox* m_txtCardPosX;

	/// clicking it will increase the Card Position x number by 5
	Brood::BroodUI::Button* m_btnCardIncPosX;

	// ==== UI elements to change Card Position y ====

	/// holds the text Card Position y
	Brood::BroodUI::TextBox* m_txtCardPosYPrompt;

	/// clicking it will decrease the Card Position y number by 5
	Brood::BroodUI::Button* m_btnCardDecPosY;

	/// displays the current Card Position y
	Brood::BroodUI::TextBox* m_txtCardPosY;

	/// clicking it will increase the Card Position y number by 5
	Brood::BroodUI::Button* m_btnCardIncPosY;

	// ==== UI elements to enter a CardFrontBg filename texture  ====

	/// holds the CardFront texture filename prompt
	Brood::BroodUI::TextBox* m_txtCardFrontBgFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtCardFrontBgFileInput;

	/// clicking it will load the CardFront file
	Brood::BroodUI::Button* m_btnCardFrontBgOpenFile;

	// ==== UI elements to enter a CardBrontBg filename textur  ====

	/// holds the CardBack texture filename prompt
	Brood::BroodUI::TextBox* m_txtCardBackBgFileNamePrompt;

	/// holds the file name user enters
	Brood::BroodUI::TextBox* m_txtCardBackBgFileInput;

	/// clicking it will load the CardBack file
	Brood::BroodUI::Button* m_btnCardBackBgOpenFile;

	// ===========================================================
	// =========== member variables for front of the card ========
	// ===========================================================

	// ==== UI elements to change CardFrontTimePrompt position x ====

	/// holds the text CardFrontTimePrompt position x
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptPosXPrompt;

	/// clicking it will decrease the CardFrontTimePrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptDecPosX;

	/// displays the current CardFrontTimePrompt Position X
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptPosX;

	/// clicking it will increase the CardFrontTimePrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptIncPosX;

	// ==== UI elements to change CardFrontTimePrompt Position y ====

	/// holds the text CardFrontTimePrompt Position y
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptPosYPrompt;

	/// clicking it will decrease the CardFrontTimePrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptDecPosY;

	/// displays the current CardFrontTimePrompt Position y
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptPosY;

	/// clicking it will increase the CardFrontTimePrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptIncPosY;

	// ==== UI elements to change CardFrontTimeValue position x ====

	/// holds the text CardFrontTimeValue position x
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValuePosXPrompt;

	/// clicking it will decrease the CardFrontTimeValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueDecPosX;

	/// displays the current CardFrontTimeValue Position X
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValuePosX;

	/// clicking it will increase the CardFrontTimeValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueIncPosX;

	// ==== UI elements to change CardFrontTimeValue Position y ====

	/// holds the text CardFrontTimeValue Position y
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValuePosYPrompt;

	/// clicking it will decrease the CardFrontTimeValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueDecPosY;

	/// displays the current CardFrontTimeValue Position y
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValuePosY;

	/// clicking it will increase the CardFrontTimeValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueIncPosY;

	// ==== UI elements to change CardUpPrompt position x ====

	/// holds the text CardUpPrompt position x
	Brood::BroodUI::TextBox* m_txtCardUpPromptPosXPrompt;

	/// clicking it will decrease the CardUpPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptDecPosX;

	/// displays the current CardUpPrompt Position X
	Brood::BroodUI::TextBox* m_txtCardUpPromptPosX;

	/// clicking it will increase the CardUpPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptIncPosX;

	// ==== UI elements to change CardUpPrompt Position y ====

	/// holds the text CardUpPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardUpPromptPosYPrompt;

	/// clicking it will decrease the CardUpPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptDecPosY;

	/// displays the current CardUpPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardUpPromptPosY;

	/// clicking it will increase the CardUpPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptIncPosY;

	// ==== UI elements to change CardUpValue position x ====

	/// holds the text CardUpValue position x
	Brood::BroodUI::TextBox* m_txtCardUpValuePosXPrompt;

	/// clicking it will decrease the CardUpValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardUpValueDecPosX;

	/// displays the current CardUpValue Position X
	Brood::BroodUI::TextBox* m_txtCardUpValuePosX;

	/// clicking it will increase the CardUpValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardUpValueIncPosX;

	// ==== UI elements to change CardUpValue Position y ====

	/// holds the text CardUpValue Position y
	Brood::BroodUI::TextBox* m_txtCardUpValuePosYPrompt;

	/// clicking it will decrease the CardUpValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardUpValueDecPosY;

	/// displays the current CardUpValue Position y
	Brood::BroodUI::TextBox* m_txtCardUpValuePosY;

	/// clicking it will increase the CardUpValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardUpValueIncPosY;

	// ==== UI elements to change CardDownPrompt position x ====

	/// holds the text CardDownPrompt position x
	Brood::BroodUI::TextBox* m_txtCardDownPromptPosXPrompt;

	/// clicking it will decrease the CardDownPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptDecPosX;

	/// displays the current CardDownPrompt Position X
	Brood::BroodUI::TextBox* m_txtCardDownPromptPosX;

	/// clicking it will increase the CardDownPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptIncPosX;

	// ==== UI elements to change CardDownPrompt Position y ====

	/// holds the text CardDownPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardDownPromptPosYPrompt;

	/// clicking it will decrease the CardDownPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptDecPosY;

	/// displays the current CardDownPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardDownPromptPosY;

	/// clicking it will increase the CardDownPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptIncPosY;

	// ==== UI elements to change CardDownValue position x ====

	/// holds the text CardDownValue position x
	Brood::BroodUI::TextBox* m_txtCardDownValuePosXPrompt;

	/// clicking it will decrease the CardDownValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardDownValueDecPosX;

	/// displays the current CardDownValue Position X
	Brood::BroodUI::TextBox* m_txtCardDownValuePosX;

	/// clicking it will increase the CardDownValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardDownValueIncPosX;

	// ==== UI elements to change CardDownValue Position y ====

	/// holds the text CardDownValue Position y
	Brood::BroodUI::TextBox* m_txtCardDownValuePosYPrompt;

	/// clicking it will decrease the CardDownValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardDownValueDecPosY;

	/// displays the current CardDownValue Position y
	Brood::BroodUI::TextBox* m_txtCardDownValuePosY;

	/// clicking it will increase the CardDownValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardDownValueIncPosY;

	// ==== UI elements to change CardTurnCard position x ====

	/// holds the text CardTurnCard position x
	Brood::BroodUI::TextBox* m_txtCardTurnCardPosXPrompt;

	/// clicking it will decrease the CardTurnCard Position x number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardDecPosX;

	/// displays the current CardTurnCard Position X
	Brood::BroodUI::TextBox* m_txtCardTurnCardPosX;

	/// clicking it will increase the CardTurnCard Position x number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardIncPosX;

	// ==== UI elements to change CardTurnCard Position y ====

	/// holds the text CardTurnCard Position y
	Brood::BroodUI::TextBox* m_txtCardTurnCardPosYPrompt;

	/// clicking it will decrease the CardTurnCard Position y number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardDecPosY;

	/// displays the current CardTurnCard Position y
	Brood::BroodUI::TextBox* m_txtCardTurnCardPosY;

	/// clicking it will increase the CardTurnCard Position y number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardIncPosY;

	// ==== UI elements to change CardFrontTimePrompt size x ====

	/// holds the text CardFrontTimePrompt size x
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptSizeXPrompt;

	/// clicking it will decrease the CardFrontTimePrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptDecSizeX;

	/// displays the current CardFrontTimePrompt size X
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptSizeX;

	/// clicking it will increase the CardFrontTimePrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptIncSizeX;

	// ==== UI elements to change CardFrontTimePrompt size y ====

	/// holds the text CardFrontTimePrompt size y
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptSizeYPrompt;

	/// clicking it will decrease the CardFrontTimePrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptDecSizeY;

	/// displays the current CardFrontTimePrompt size y
	Brood::BroodUI::TextBox* m_txtCardFrontTimePromptSizeY;

	/// clicking it will increase the CardFrontTimePrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimePromptIncSizeY;

	// ==== UI elements to change CardFrontTimeValue size x ====

	/// holds the text CardFrontTimeValue size x
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValueSizeXPrompt;

	/// clicking it will decrease the CardFrontTimeValue size x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueDecSizeX;

	/// displays the current CardFrontTimeValue size X
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValueSizeX;

	/// clicking it will increase the CardFrontTimeValue size x number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueIncSizeX;

	// ==== UI elements to change CardFrontTimeValue size y ====

	/// holds the text CardFrontTimeValue size y
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValueSizeYPrompt;

	/// clicking it will decrease the CardFrontTimeValue size y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueDecSizeY;

	/// displays the current CardFrontTimeValue size y
	Brood::BroodUI::TextBox* m_txtCardFrontTimeValueSizeY;

	/// clicking it will increase the CardFrontTimeValue size y number by 5
	Brood::BroodUI::Button* m_btnCardFrontTimeValueIncSizeY;

	// ==== UI elements to change CardUpPrompt size x ====

	/// holds the text CardUpPrompt size x
	Brood::BroodUI::TextBox* m_txtCardUpPromptSizeXPrompt;

	/// clicking it will decrease the CardUpPrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptDecSizeX;

	/// displays the current CardUpPrompt size X
	Brood::BroodUI::TextBox* m_txtCardUpPromptSizeX;

	/// clicking it will increase the CardUpPrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptIncSizeX;

	// ==== UI elements to change CardUpPrompt size y ====

	/// holds the text CardUpPrompt size y
	Brood::BroodUI::TextBox* m_txtCardUpPromptSizeYPrompt;

	/// clicking it will decrease the CardUpPrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptDecSizeY;

	/// displays the current CardUpPrompt size y
	Brood::BroodUI::TextBox* m_txtCardUpPromptSizeY;

	/// clicking it will increase the CardUpPrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardUpPromptIncSizeY;

	// ==== UI elements to change CardUpValue size x ====

	/// holds the text CardUpValue size x
	Brood::BroodUI::TextBox* m_txtCardUpValueSizeXPrompt;

	/// clicking it will decrease the CardUpValue size x number by 5
	Brood::BroodUI::Button* m_btnCardUpValueDecSizeX;

	/// displays the current CardUpValue size X
	Brood::BroodUI::TextBox* m_txtCardUpValueSizeX;

	/// clicking it will increase the CardUpValue size x number by 5
	Brood::BroodUI::Button* m_btnCardUpValueIncSizeX;

	// ==== UI elements to change CardUpValue size y ====

	/// holds the text CardUpValue size y
	Brood::BroodUI::TextBox* m_txtCardUpValueSizeYPrompt;

	/// clicking it will decrease the CardUpValue size y number by 5
	Brood::BroodUI::Button* m_btnCardUpValueDecSizeY;

	/// displays the current CardUpValue size y
	Brood::BroodUI::TextBox* m_txtCardUpValueSizeY;

	/// clicking it will increase the CardUpValue size y number by 5
	Brood::BroodUI::Button* m_btnCardUpValueIncSizeY;

	// ==== UI elements to change CardDownPrompt size x ====

	/// holds the text CardDownPrompt size x
	Brood::BroodUI::TextBox* m_txtCardDownPromptSizeXPrompt;

	/// clicking it will decrease the CardDownPrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptDecSizeX;

	/// displays the current CardDownPrompt size X
	Brood::BroodUI::TextBox* m_txtCardDownPromptSizeX;

	/// clicking it will increase the CardDownPrompt size x number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptIncSizeX;

	// ==== UI elements to change CardDownPrompt size y ====

	/// holds the text CardDownPrompt size y
	Brood::BroodUI::TextBox* m_txtCardDownPromptSizeYPrompt;

	/// clicking it will decrease the CardDownPrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptDecSizeY;

	/// displays the current CardDownPrompt size y
	Brood::BroodUI::TextBox* m_txtCardDownPromptSizeY;

	/// clicking it will increase the CardDownPrompt size y number by 5
	Brood::BroodUI::Button* m_btnCardDownPromptIncSizeY;

	// ==== UI elements to change CardDownValue size x ====

	/// holds the text CardDownValue size x
	Brood::BroodUI::TextBox* m_txtCardDownValueSizeXPrompt;

	/// clicking it will decrease the CardDownValue size x number by 5
	Brood::BroodUI::Button* m_btnCardDownValueDecSizeX;

	/// displays the current CardDownValue size X
	Brood::BroodUI::TextBox* m_txtCardDownValueSizeX;

	/// clicking it will increase the CardDownValue size x number by 5
	Brood::BroodUI::Button* m_btnCardDownValueIncSizeX;

	// ==== UI elements to change CardDownValue size y ====

	/// holds the text CardDownValue size y
	Brood::BroodUI::TextBox* m_txtCardDownValueSizeYPrompt;

	/// clicking it will decrease the CardDownValue size y number by 5
	Brood::BroodUI::Button* m_btnCardDownValueDecSizeY;

	/// displays the current CardDownValue size y
	Brood::BroodUI::TextBox* m_txtCardDownValueSizeY;

	/// clicking it will increase the CardDownValue size y number by 5
	Brood::BroodUI::Button* m_btnCardDownValueIncSizeY;

	// ==== UI elements to change CardTurnCard size x ====

	/// holds the text CardTurnCard size x
	Brood::BroodUI::TextBox* m_txtCardTurnCardSizeXPrompt;

	/// clicking it will decrease the CardTurnCard size x number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardDecSizeX;

	/// displays the current CardTurnCard size X
	Brood::BroodUI::TextBox* m_txtCardTurnCardSizeX;

	/// clicking it will increase the CardTurnCard size x number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardIncSizeX;

	// ==== UI elements to change CardTurnCard size y ====

	/// holds the text CardTurnCard size y
	Brood::BroodUI::TextBox* m_txtCardTurnCardSizeYPrompt;

	/// clicking it will decrease the CardTurnCard size y number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardDecSizeY;

	/// displays the current CardTurnCard size y
	Brood::BroodUI::TextBox* m_txtCardTurnCardSizeY;

	/// clicking it will increase the CardTurnCard size y number by 5
	Brood::BroodUI::Button* m_btnCardTurnCardIncSizeY;

	// ===========================================================
	// =========== member variables for back of the card =========
	// ===========================================================

	// ==== UI elements to change CardBackTimePrompt position x ====

	/// holds the text CardBackTimePrompt position x
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptPosXPrompt;

	/// clicking it will decrease the CardBackTimePrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptDecPosX;

	/// displays the current CardBackTimePrompt Position X
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptPosX;

	/// clicking it will increase the CardBackTimePrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptIncPosX;

	// ==== UI elements to change CardBackTimePrompt Position y ====

	/// holds the text CardBackTimePrompt Position y
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptPosYPrompt;

	/// clicking it will decrease the CardBackTimePrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptDecPosY;

	/// displays the current CardBackTimePrompt Position y
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptPosY;

	/// clicking it will increase the CardBackTimePrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptIncPosY;

	// ==== UI elements to change CardBackTimeValue position x ====

	/// holds the text CardBackTimeValue position x
	Brood::BroodUI::TextBox* m_txtCardBackTimeValuePosXPrompt;

	/// clicking it will decrease the CardBackTimeValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueDecPosX;

	/// displays the current CardBackTimeValue Position X
	Brood::BroodUI::TextBox* m_txtCardBackTimeValuePosX;

	/// clicking it will increase the CardBackTimeValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueIncPosX;

	// ==== UI elements to change CardBackTimeValue Position y ====

	/// holds the text CardBackTimeValue Position y
	Brood::BroodUI::TextBox* m_txtCardBackTimeValuePosYPrompt;

	/// clicking it will decrease the CardBackTimeValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueDecPosY;

	/// displays the current CardBackTimeValue Position y
	Brood::BroodUI::TextBox* m_txtCardBackTimeValuePosY;

	/// clicking it will increase the CardBackTimeValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueIncPosY;

	// ==== UI elements to change CardQuestionPrompt position x ====

	/// holds the text CardQuestionPrompt position x
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptPosXPrompt;

	/// clicking it will decrease the CardQuestionPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptDecPosX;

	/// displays the current CardQuestionPrompt Position X
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptPosX;

	/// clicking it will increase the CardQuestionPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptIncPosX;

	// ==== UI elements to change CardQuestionPrompt Position y ====

	/// holds the text CardQuestionPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptPosYPrompt;

	/// clicking it will decrease the CardQuestionPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptDecPosY;

	/// displays the current CardQuestionPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptPosY;

	/// clicking it will increase the CardQuestionPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptIncPosY;

	// ==== UI elements to change CardQuestionValue position x ====

	/// holds the text CardQuestionValue position x
	Brood::BroodUI::TextBox* m_txtCardQuestionValuePosXPrompt;

	/// clicking it will decrease the CardQuestionValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueDecPosX;

	/// displays the current CardQuestionValue Position X
	Brood::BroodUI::TextBox* m_txtCardQuestionValuePosX;

	/// clicking it will increase the CardQuestionValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueIncPosX;

	// ==== UI elements to change CardQuestionValue Position y ====

	/// holds the text CardQuestionValue Position y
	Brood::BroodUI::TextBox* m_txtCardQuestionValuePosYPrompt;

	/// clicking it will decrease the CardQuestionValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueDecPosY;

	/// displays the current CardQuestionValue Position y
	Brood::BroodUI::TextBox* m_txtCardQuestionValuePosY;

	/// clicking it will increase the CardQuestionValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueIncPosY;

	// ==== UI elements to change CardAnswerPrompt position x ====

	/// holds the text CardAnswerPrompt position x
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptPosXPrompt;

	/// clicking it will decrease the CardAnswerPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptDecPosX;

	/// displays the current CardAnswerPrompt Position X
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptPosX;

	/// clicking it will increase the CardAnswerPrompt Position x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptIncPosX;

	// ==== UI elements to change CardAnswerPrompt Position y ====

	/// holds the text CardAnswerPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptPosYPrompt;

	/// clicking it will decrease the CardAnswerPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptDecPosY;

	/// displays the current CardAnswerPrompt Position y
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptPosY;

	/// clicking it will increase the CardAnswerPrompt Position y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptIncPosY;

	// ==== UI elements to change CardAnswerValue position x ====

	/// holds the text CardAnswerValue position x
	Brood::BroodUI::TextBox* m_txtCardAnswerValuePosXPrompt;

	/// clicking it will decrease the CardAnswerValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueDecPosX;

	/// displays the current CardAnswerValue Position X
	Brood::BroodUI::TextBox* m_txtCardAnswerValuePosX;

	/// clicking it will increase the CardAnswerValue Position x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueIncPosX;

	// ==== UI elements to change CardAnswerValue Position y ====

	/// holds the text CardAnswerValue Position y
	Brood::BroodUI::TextBox* m_txtCardAnswerValuePosYPrompt;

	/// clicking it will decrease the CardAnswerValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueDecPosY;

	/// displays the current CardAnswerValue Position y
	Brood::BroodUI::TextBox* m_txtCardAnswerValuePosY;

	/// clicking it will increase the CardAnswerValue Position y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueIncPosY;

	// ==== UI elements to change CardSubmit position x ====

	/// holds the text CardSubmit position x
	Brood::BroodUI::TextBox* m_txtCardSubmitPosXPrompt;

	/// clicking it will decrease the CardSubmit Position x number by 5
	Brood::BroodUI::Button* m_btnCardSubmitDecPosX;

	/// displays the current CardSubmit Position X
	Brood::BroodUI::TextBox* m_txtCardSubmitPosX;

	/// clicking it will increase the CardSubmit Position x number by 5
	Brood::BroodUI::Button* m_btnCardSubmitIncPosX;

	// ==== UI elements to change CardSubmit Position y ====

	/// holds the text CardSubmit Position y
	Brood::BroodUI::TextBox* m_txtCardSubmitPosYPrompt;

	/// clicking it will decrease the CardSubmit Position y number by 5
	Brood::BroodUI::Button* m_btnCardSubmitDecPosY;

	/// displays the current CardSubmit Position y
	Brood::BroodUI::TextBox* m_txtCardSubmitPosY;

	/// clicking it will increase the CardSubmit Size y number by 5
	Brood::BroodUI::Button* m_btnCardSubmitIncPosY;

	// ==== UI elements to change CardBackTimePrompt position x ====

	/// holds the text CardBackTimePrompt position x
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptSizeXPrompt;

	/// clicking it will decrease the CardBackTimePrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptDecSizeX;

	/// displays the current CardBackTimePrompt Size X
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptSizeX;

	/// clicking it will increase the CardBackTimePrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptIncSizeX;

	// ==== UI elements to change CardBackTimePrompt Size y ====

	/// holds the text CardBackTimePrompt Size y
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptSizeYPrompt;

	/// clicking it will decrease the CardBackTimePrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptDecSizeY;

	/// displays the current CardBackTimePrompt Size y
	Brood::BroodUI::TextBox* m_txtCardBackTimePromptSizeY;

	/// clicking it will increase the CardBackTimePrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimePromptIncSizeY;

	// ==== UI elements to change CardBackTimeValue position x ====

	/// holds the text CardBackTimeValue position x
	Brood::BroodUI::TextBox* m_txtCardBackTimeValueSizeXPrompt;

	/// clicking it will decrease the CardBackTimeValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueDecSizeX;

	/// displays the current CardBackTimeValue Size X
	Brood::BroodUI::TextBox* m_txtCardBackTimeValueSizeX;

	/// clicking it will increase the CardBackTimeValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueIncSizeX;

	// ==== UI elements to change CardBackTimeValue Size y ====

	/// holds the text CardBackTimeValue Size y
	Brood::BroodUI::TextBox* m_txtCardBackTimeValueSizeYPrompt;

	/// clicking it will decrease the CardBackTimeValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueDecSizeY;

	/// displays the current CardBackTimeValue Size y
	Brood::BroodUI::TextBox* m_txtCardBackTimeValueSizeY;

	/// clicking it will increase the CardBackTimeValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardBackTimeValueIncSizeY;

	// ==== UI elements to change CardQuestionPrompt position x ====

	/// holds the text CardQuestionPrompt position x
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptSizeXPrompt;

	/// clicking it will decrease the CardQuestionPrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptDecSizeX;

	/// displays the current CardQuestionPrompt Size X
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptSizeX;

	/// clicking it will increase the CardQuestionPrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptIncSizeX;

	// ==== UI elements to change CardQuestionPrompt Size y ====

	/// holds the text CardQuestionPrompt Size y
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptSizeYPrompt;

	/// clicking it will decrease the CardQuestionPrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptDecSizeY;

	/// displays the current CardQuestionPrompt Size y
	Brood::BroodUI::TextBox* m_txtCardQuestionPromptSizeY;

	/// clicking it will increase the CardQuestionPrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionPromptIncSizeY;

	// ==== UI elements to change CardQuestionValue position x ====

	/// holds the text CardQuestionValue position x
	Brood::BroodUI::TextBox* m_txtCardQuestionValueSizeXPrompt;

	/// clicking it will decrease the CardQuestionValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueDecSizeX;

	/// displays the current CardQuestionValue Size X
	Brood::BroodUI::TextBox* m_txtCardQuestionValueSizeX;

	/// clicking it will increase the CardQuestionValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueIncSizeX;

	// ==== UI elements to change CardQuestionValue Size y ====

	/// holds the text CardQuestionValue Size y
	Brood::BroodUI::TextBox* m_txtCardQuestionValueSizeYPrompt;

	/// clicking it will decrease the CardQuestionValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueDecSizeY;

	/// displays the current CardQuestionValue Size y
	Brood::BroodUI::TextBox* m_txtCardQuestionValueSizeY;

	/// clicking it will increase the CardQuestionValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardQuestionValueIncSizeY;

	// ==== UI elements to change CardAnswerPrompt position x ====

	/// holds the text CardAnswerPrompt position x
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptSizeXPrompt;

	/// clicking it will decrease the CardAnswerPrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptDecSizeX;

	/// displays the current CardAnswerPrompt Size X
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptSizeX;

	/// clicking it will increase the CardAnswerPrompt Size x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptIncSizeX;

	// ==== UI elements to change CardAnswerPrompt Size y ====

	/// holds the text CardAnswerPrompt Size y
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptSizeYPrompt;

	/// clicking it will decrease the CardAnswerPrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptDecSizeY;

	/// displays the current CardAnswerPrompt Size y
	Brood::BroodUI::TextBox* m_txtCardAnswerPromptSizeY;

	/// clicking it will increase the CardAnswerPrompt Size y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerPromptIncSizeY;

	// ==== UI elements to change CardAnswerValue position x ====

	/// holds the text CardAnswerValue position x
	Brood::BroodUI::TextBox* m_txtCardAnswerValueSizeXPrompt;

	/// clicking it will decrease the CardAnswerValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueDecSizeX;

	/// displays the current CardAnswerValue Size X
	Brood::BroodUI::TextBox* m_txtCardAnswerValueSizeX;

	/// clicking it will increase the CardAnswerValue Size x number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueIncSizeX;

	// ==== UI elements to change CardAnswerValue Size y ====

	/// holds the text CardAnswerValue Size y
	Brood::BroodUI::TextBox* m_txtCardAnswerValueSizeYPrompt;

	/// clicking it will decrease the CardAnswerValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueDecSizeY;

	/// displays the current CardAnswerValue Size y
	Brood::BroodUI::TextBox* m_txtCardAnswerValueSizeY;

	/// clicking it will increase the CardAnswerValue Size y number by 5
	Brood::BroodUI::Button* m_btnCardAnswerValueIncSizeY;

	// ==== UI elements to change CardSubmit position x ====

	/// holds the text CardSubmit position x
	Brood::BroodUI::TextBox* m_txtCardSubmitSizeXPrompt;

	/// clicking it will decrease the CardSubmit Size x number by 5
	Brood::BroodUI::Button* m_btnCardSubmitDecSizeX;

	/// displays the current CardSubmit Size X
	Brood::BroodUI::TextBox* m_txtCardSubmitSizeX;

	/// clicking it will increase the CardSubmit Size x number by 5
	Brood::BroodUI::Button* m_btnCardSubmitIncSizeX;

	// ==== UI elements to change CardSubmit Size y ====

	/// holds the text CardSubmit Size y
	Brood::BroodUI::TextBox* m_txtCardSubmitSizeYPrompt;

	/// clicking it will decrease the CardSubmit Size y number by 5
	Brood::BroodUI::Button* m_btnCardSubmitDecSizeY;

	/// displays the current CardSubmit Size y
	Brood::BroodUI::TextBox* m_txtCardSubmitSizeY;

	/// clicking it will increase the CardSubmit Size y number by 5
	Brood::BroodUI::Button* m_btnCardSubmitIncSizeY;

	// ===========================================================
	// =========== member variables for card info setting ========
	// ===========================================================

	// ==== UI elements to change current Deck number ====

	/// holds the text Curr Deck Num
	Brood::BroodUI::TextBox* m_txtDeckNumPrompt;

	/// clicking it will decrease the Curr Deck Num number by 1
	Brood::BroodUI::Button* m_btnDecDeckNum;

	/// displays the current CardSubmit Size y
	Brood::BroodUI::TextBox* m_txtDeckNum;

	/// clicking it will increase the Curr Deck Num number by 1
	Brood::BroodUI::Button* m_btnIncDeckNum;

	// ==== UI elements to change current Card number ====

	/// holds the text Curr card Num
	Brood::BroodUI::TextBox* m_txtCurrCardNumPrompt;

	/// clicking it will decrease the Curr card number by 1
	Brood::BroodUI::Button* m_btnDecCurrCardNum;

	/// displays the current CardSubmit Size y
	Brood::BroodUI::TextBox* m_txtCurrCardNum;

	/// clicking it will increase the Curr card Num number by 1
	Brood::BroodUI::Button* m_btnIncCurrCardNum;

	// ==== UI elements to change current Card Time ====

	/// holds the text Curr card time
	Brood::BroodUI::TextBox* m_txtCurrCardTimePrompt;

	/// clicking it will decrease the Curr card time number by 1
	Brood::BroodUI::Button* m_btnDecCurrCardTime;

	/// displays the current Curr card time
	Brood::BroodUI::TextBox* m_txtCurrCardTime;

	/// clicking it will increase the Curr card Time number by 1
	Brood::BroodUI::Button* m_btnIncCurrCardTime;

	// ==== UI elements to change current Card Up ====

	/// holds the text Curr card up
	Brood::BroodUI::TextBox* m_txtCurrCardUpPrompt;

	/// clicking it will decrease the Curr card up number by 1
	Brood::BroodUI::Button* m_btnDecCurrCardUp;

	/// displays the current Curr card up
	Brood::BroodUI::TextBox* m_txtCurrCardUp;

	/// clicking it will increase the Curr card up number by 1
	Brood::BroodUI::Button* m_btnIncCurrCardUp;

	// ==== UI elements to change current Card Down ====

	/// holds the text Curr card down
	Brood::BroodUI::TextBox* m_txtCurrCardDownPrompt;

	/// clicking it will decrease the Curr card down number by 1
	Brood::BroodUI::Button* m_btnDecCurrCardDown;

	/// displays the current Curr card down
	Brood::BroodUI::TextBox* m_txtCurrCardDown;

	/// clicking it will increase the Curr card down number by 1
	Brood::BroodUI::Button* m_btnIncCurrCardDown;

	// ==== UI elements to enter a curr Card Question  ====

	/// holds the curr Card Question prompt
	Brood::BroodUI::TextBox* m_txtCurrCardQuestionPrompt;

	/// holds the question user enters
	Brood::BroodUI::TextBox* m_txtCurrCardQuestionInput;

	// ==== UI elements to enter a curr Card Answer  ====

	/// holds the curr Card Answer prompt
	Brood::BroodUI::TextBox* m_txtCurrCardAnswerPrompt;

	/// holds the question user enters
	Brood::BroodUI::TextBox* m_txtCurrCardAnswerInput;

	// ==== UI elements to turn the card  ====

	Brood::BroodUI::Button* m_btnTurnCardAround;
};

// ======================================================================
// ================= end of TileEditor class ============================
// ======================================================================


/// TODO see if you can generalize the update function for pos 