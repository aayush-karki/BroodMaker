/*************************************************************************/
/*************************************************************************/
/// 
/// @file GameDataManager.h 
/// 
/// @brief  This file is a header file for GameDataManager class.
/// 
/// It contains all of the declaration of the member 
///		funciton of GameDataManager class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "CardInfo.h"
#include "Button.h"
#include "TextBox.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class DisplayCard;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DisplayCard class =========================
// ======================================================================

///
/// @ingroup Components
/// @class PlayerManager  "DisplayCard.h"
/// m_minPlayer
/// @brief A PlayerManager Class manages all player realted things
/// 
class Brood::Application::Components::DisplayCard:
	public Brood::BroodUI::Button
{
	// ===================== public member function ===================
public:
	// default constructor
	DisplayCard();

	// default destructor
	~DisplayCard();

	// copy constructor
	DisplayCard( const DisplayCard& a_other );

	// assignment operator
	DisplayCard& operator=( const DisplayCard& a_other );

	// Initializes the ui elements
	void InializeDisplayCard();

	// ========= Getter funciton ==============

	// getter function to get the front bg filename
	std::string GetFrontBgFileName();

	// getter function to get the back bg filename
	std::string GetBackBgFileName();

	// displays time user have to complete the question
	Brood::BroodUI::TextBox* GetFrontTimePromptPtr();
	Brood::BroodUI::TextBox* GetFrontTimeValuePtr();

	// displays number of steps that user goes forward
	Brood::BroodUI::TextBox* GetUpPromptPtr();
	Brood::BroodUI::TextBox* GetUpValuePtr();

	// displays number of steps that user goes backward
	Brood::BroodUI::TextBox* GetDownPromptPtr();
	Brood::BroodUI::TextBox* GetDownValuePtr();

	// button to turn the card of the card
	Brood::BroodUI::Button* GetTurnCardPtr();

	// ========= back of the card =========
	// displays time user have to complete the question
	Brood::BroodUI::TextBox* GetBackTimePromptPtr();
	Brood::BroodUI::TextBox* GetBackTimeValuePtr();

	// displays the question that user has to answer
	Brood::BroodUI::TextBox* GetQuestionPromptPtr();
	Brood::BroodUI::TextBox* GetQuestionValuePtr();

	// displays the textbox for user to enter theiranswer
	Brood::BroodUI::TextBox* GetAnswerPromptPtr();
	Brood::BroodUI::TextBox* GetAnswerValuePtr();

	// button to show back of the card
	Brood::BroodUI::Button* GetSubmitPtr();


	// ========= Setter funciton ==============

	// setter function to set the front bg filename
	void SetFrontBgFileName( std::string a_frontBgFilename );

	// setter function to set the back bg filename
	void SetBackBgFileName( std::string a_backBgFilename );

	// setter funciton to set the card info that will be 
	// used to display
	void SetCardInfoToDisplay( Brood::Application::Components::CardInfo* a_cardInfoToDisplay );

	// toggles the background; if current bg is front
	// then toggles it to back
	void ToggleBackground();

	// updates the displayed text
	void UpdateDisplayedText();

	// draw funciton
	void Draw( sf::RenderWindow& a_window );

	void Debugger(); // adds the element ID to the text


	// ===================== private member variables ===================
private:

	bool m_isCurrFront;

	// holds the filename for front image
	std::string m_frontBgFileName;

	// holds the filename for back image
	std::string m_backBgFileName;

	// pointer contains the info to display
	Brood::Application::Components::CardInfo* m_cardInfoToDisplay;
	
	// ========= Font of the card =========

	// displays time user have to complete the question
	Brood::BroodUI::TextBox* m_TxtFrontTimePromt;
	Brood::BroodUI::TextBox* m_TxtFrontTimeValue;
	
	// displays number of steps that user goes forward
	Brood::BroodUI::TextBox* m_TxtUpPromt;
	Brood::BroodUI::TextBox* m_TxtUpValue;
	
	// displays number of steps that user goes backward
	Brood::BroodUI::TextBox* m_TxtDownPrompt;
	Brood::BroodUI::TextBox* m_TxtDownValue;

	// button to turn the card of the card
	Brood::BroodUI::Button* m_BtnTurnCard;
	
	// ========= back of the card =========
	// displays time user have to complete the question
	Brood::BroodUI::TextBox* m_TxtBackTimePromt;
	Brood::BroodUI::TextBox* m_TxtBackTimeValue;

	// displays the question that user has to answer
	Brood::BroodUI::TextBox* m_TxtQuestionPrompt;
	Brood::BroodUI::TextBox* m_TxtQuestionValue;
	
	// displays the textbox for user to enter theiranswer
	Brood::BroodUI::TextBox* m_TxtUserAnswerPrompt;
	Brood::BroodUI::TextBox* m_TxtUserAnswerValue;

	// button to show back of the card
	Brood::BroodUI::Button* m_BtnSubmit;
};

// ======================================================================
// ================= end of DisplayCard class ===========================
// ======================================================================