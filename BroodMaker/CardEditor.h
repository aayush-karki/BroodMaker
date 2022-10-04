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

	// ================= private member variable ==================  
private:

	/// pointer to the game data
	Brood::Application::Components::GameDataManager* m_gameData;

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// board for the game
	Brood::Application::Components::Board* m_boardPtr;

	/// pointer to the deck manager
	Brood::Application::Components::DeckManager* m_deckManagerPtr;

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

	/// clicking it will increase the CardSubmit Position y number by 5
	Brood::BroodUI::Button* m_btnCardSubmitIncPosY;

	// ===========================================================
	// =========== member variables for card info setting ========
	// ===========================================================
};

// ======================================================================
// ================= end of TileEditor class ============================
// ======================================================================
