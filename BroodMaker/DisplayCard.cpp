/*************************************************************************/
/// 
/// @file DisplayCard.cpp
/// 
/// @brief  This file is a source file for DisplayCard class.
/// 
/// It contains all of the defination of the member 
///		funciton of DisplayCard class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "DisplayCard.h"


// ======================================================================
// ================= start of DisplayCard class =========================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///	
Brood::Application::Components::DisplayCard::DisplayCard() :
	Brood::BroodUI::Button( nullptr ),
	m_frontBgFileName( "" ), m_backBgFileName( "" ),
	m_cardInfoToDisplay( nullptr ), m_isCurrFront( true )
{
	SetBodySize( 400, 200 );
	SetBodyPosition( 10, 200 );
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	// ========= Font of the card =========

	// initializing front time
	m_TxtFrontTimePromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																	{ 110,210 }, "Time" );
	m_TxtFrontTimeValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																	{ 110,260 }, "", "TimeValue" );

	// initializing up
	m_TxtUpPromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 50,40 },
															 { 210,310 }, "Up:" );
	m_TxtUpValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 50,40 },
															 { 210,360 }, "", "UpValue" );

	// initializing down
	m_TxtDownPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 50,40 },
																{ 260,310 }, "Down:" );
	m_TxtDownValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 50,40 },
															   { 260,360 }, "", "downValue" );
	m_BtnTurnCard = Brood::BroodUI::Button::DyCreateButton( { 50, 200 },
															{ 10, 3600 }, "turn card" );;

	// ========= back of the card =========

	// initializing back time
	m_TxtBackTimePromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																   { 110,210 }, "Time left" );
	m_TxtBackTimeValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																   { 110,260 }, "", "TimeValue" );

	// initializing question
	m_TxtQuestionPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																	{ 110,210 }, "Question: " );
	m_TxtQuestionValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																   { 110,260 }, "", "question" );

	// initializing userAnswer
	m_TxtUserAnswerPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 100,40 },
																	  { 110,310 }, "Answer:" );
	m_TxtUserAnswerValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 200,40 },
																	 { 220,310 }, "", "enter your answer" );

	// initializing submit button
	m_BtnSubmit = Brood::BroodUI::Button::DyCreateButton( { 200,40 },
														  { 110,360 }, "Submit Answer" );
}

/// 
/// @public
/// @brief default destrctor
///
Brood::Application::Components::DisplayCard::~DisplayCard()
{}

///
/// @brief Copy constructor
/// 
/// @param a_other reference to the other display card which is used to 
///		copy the data form 
/// 
Brood::Application::Components::DisplayCard::DisplayCard( const DisplayCard& a_other ) :
	Brood::BroodUI::Button( a_other ), m_frontBgFileName( a_other.m_frontBgFileName ),
	m_backBgFileName( a_other.m_backBgFileName ), m_cardInfoToDisplay( a_other.m_cardInfoToDisplay ),
	m_isCurrFront( a_other.m_isCurrFront )
{}

/// 
/// @brief assignment operator
/// 
/// @param a_other reference to the other display card which is used to 
///		copy the data form 
/// 
/// @return pointer to this display card
///
Brood::Application::Components::DisplayCard& Brood::Application::Components::DisplayCard::operator=( const Brood::Application::Components::DisplayCard& a_other )
{
	// chekcing for self assignment
	if( this == &a_other )
	{
		return *this;
	}

	// calling the assignment operator
	Brood::BroodUI::Button::operator=( a_other );
	this->m_frontBgFileName = a_other.m_frontBgFileName;
	this->m_backBgFileName = a_other.m_backBgFileName;
	this->m_cardInfoToDisplay = a_other.m_cardInfoToDisplay;
	this->m_isCurrFront = a_other.m_isCurrFront;

	return *this;
}


/// 
/// @public
/// @brief Getter function to get a front background filename
/// 
/// @return  front background filename
/// 
std::string Brood::Application::Components::DisplayCard::GetFrontBgFileName()
{
	return m_frontBgFileName;
}

/// 
/// @public
/// @brief Getter function to get a back background filename
/// 
/// @return back background filename
/// 
std::string Brood::Application::Components::DisplayCard::GetBackBgFileName()
{
	return m_backBgFileName;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the frontTime prompt ui element
/// 
/// @return pointer to the frontTime prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetFrontTimePromtPtr()
{
	return m_TxtFrontTimePromt;
}


/// 
/// @public
/// @brief Getter function to get the pointer to the frontTime value ui element
/// 
/// @return pointer to the frontTime value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetFrontTimeValuePtr()
{
	return m_TxtFrontTimeValue;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the up prompt ui element
/// 
/// @return pointer to the up prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetUpPromtPtr()
{
	return m_TxtUpPromt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the up value ui element
/// 
/// @return pointer to the up value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetUpValuePtr()
{
	return m_TxtUpValue;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the down prompt ui element
/// 
/// @return pointer to the down prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetDownPromptPtr()
{
	return m_TxtDownPrompt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the down value ui element
/// 
/// @return pointer to the down value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetDownValuePtr()
{
	return m_TxtDownValue;
}


/// 
/// @public
/// @brief Getter function to get the pointer to the turn card ui element
/// 
/// @return pointer to the turn card ui element
///
Brood::BroodUI::Button* Brood::Application::Components::DisplayCard::GetTurnCardPtr()
{
	return m_BtnTurnCard;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the back time prompt ui element
/// 
/// @return pointer to the back time prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetBackTimePromtPtr()
{
	return m_TxtBackTimePromt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the back time value ui element
/// 
/// @return pointer to the back time value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetBackTimeValuePtr()
{
	return m_TxtBackTimeValue;
}


/// 
/// @public
/// @brief Getter function to get the pointer to the question prompt ui element
/// 
/// @return pointer to the question prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetQuestionPromptPtr()
{
	return m_TxtQuestionPrompt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the question value ui element
/// 
/// @return pointer to the question value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetQuestionValuePtr()
{
	return m_TxtQuestionValue;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the user answer prompt ui element
/// 
/// @return pointer to the user answer prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetUserAnswerPromptPtr()
{
	return m_TxtUserAnswerPrompt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the user answer value ui element
/// 
/// @return pointer to the user answer value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetUserAnswerValuePtr()
{
	return m_TxtUserAnswerValue;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the submit ui element
/// 
/// @return pointer to the submit ui element
///
Brood::BroodUI::Button* Brood::Application::Components::DisplayCard::GetSubmitPtr()
{
	return m_BtnSubmit;
}

/// 
/// @public
/// @brief Setter function to set a front background filename
/// 
/// @param a_frontBgFilename front background filename
///
void Brood::Application::Components::DisplayCard::SetFrontBgFileName( std::string a_frontBgFilename )
{
	m_frontBgFileName = a_frontBgFilename;
}

/// 
/// @public
/// @brief Setter function to set a back background filename
/// 
/// @param a_backBgFilename back background filename
/// 
void Brood::Application::Components::DisplayCard::SetBackBgFileName( std::string a_backBgFilename )
{
	m_backBgFileName = a_backBgFilename;
}

/// 
/// @public
/// @brief setter funciton to set the card info that will be 
///		used to display
/// 
/// @param a_cardInfoToDisplay pointer to the cardInfo object
/// 
void Brood::Application::Components::DisplayCard::SetCardInfoToDisplay( Brood::Application::Components::CardInfo* a_cardInfoToDisplay )
{
	m_cardInfoToDisplay = a_cardInfoToDisplay;

	UpdateDisplayedText();
}

/// 
/// @public
/// @brief toggles the background
/// 
///  If current bg is using front then toggles it to use back
/// 
void Brood::Application::Components::DisplayCard::ToggleBackground()
{
	if( m_isCurrFront )
	{
		m_bodySprite.SetTextureFromFilePath( m_backBgFileName );

	}
	else
	{
		m_bodySprite.SetTextureFromFilePath( m_frontBgFileName );
	}

	m_isCurrFront = !m_isCurrFront;
}

/// 
/// @public
/// @brief updates the displayed text from the saved cardInfo
/// 
void Brood::Application::Components::DisplayCard::UpdateDisplayedText()
{
	m_TxtFrontTimeValue->SetText( std::to_string( m_cardInfoToDisplay->GetTime() ) );
	m_TxtUpValue->SetText( std::to_string( m_cardInfoToDisplay->GetCorrectNumSteps() ) );
	m_TxtDownValue->SetText( std::to_string( m_cardInfoToDisplay->GetIncorrectNumSteps() ) );
	m_TxtBackTimeValue->SetText( std::to_string( m_cardInfoToDisplay->GetTime() ) );
	m_TxtQuestionValue->SetText( m_cardInfoToDisplay->GetQuestion() );
}

///
/// @public
/// @virtual
/// @brief Draws the body to the render window
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::Components::DisplayCard::Draw( sf::RenderWindow& a_window )
{
	if( m_isCurrFront )
	{

		// drawing front time
		m_TxtFrontTimePromt->Draw( a_window );
		m_TxtFrontTimeValue->Draw( a_window );

		// drawing up
		m_TxtUpPromt->Draw( a_window );
		m_TxtUpValue->Draw( a_window );

		// drawing down
		m_TxtDownPrompt->Draw( a_window );
		m_TxtDownValue->Draw( a_window );

		// drawing turnCard
		m_BtnTurnCard->Draw( a_window );
	}
	else
	{
		// drawing back time
		m_TxtBackTimePromt->Draw( a_window );
		m_TxtBackTimeValue->Draw( a_window );

		// drawing question
		m_TxtQuestionPrompt->Draw( a_window );
		m_TxtQuestionValue->Draw( a_window );

		// drawing user answer
		m_TxtUserAnswerPrompt->Draw( a_window );
		m_TxtUserAnswerValue->Draw( a_window );

		// drawing submit button
		m_BtnSubmit->Draw( a_window );
	}
}

///
/// @public
/// @virtual
/// @brief debugger
/// 
void Brood::Application::Components::DisplayCard::Debugger()
{
	// debugging front time
	m_TxtFrontTimePromt->Debugger();
	m_TxtFrontTimeValue->Debugger();

	// debugging up
	m_TxtUpPromt->Debugger();
	m_TxtUpValue->Debugger();

	// debugging down
	m_TxtDownPrompt->Debugger();
	m_TxtDownValue->Debugger();

	// debugging turnCard
	m_BtnTurnCard->Debugger();

	// debugging back time
	m_TxtBackTimePromt->Debugger();
	m_TxtBackTimeValue->Debugger();

	// debugging question
	m_TxtQuestionPrompt->Debugger();
	m_TxtQuestionValue->Debugger();

	// debugging user answer
	m_TxtUserAnswerPrompt->Debugger();
	m_TxtUserAnswerValue->Debugger();

	// debugging submit button
	m_BtnSubmit->Debugger();
}


// ======================================================================
// ================= end of DisplayCard class ===========================
// ======================================================================