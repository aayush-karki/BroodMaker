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
	InializeDisplayCard();
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
{
	InializeDisplayCard();

}

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

	// updaing the displayed text in the ui element
	UpdateDisplayedText();

	return *this;
}

///
/// @public
/// @brief Initializes the display card
/// 
void Brood::Application::Components::DisplayCard::InializeDisplayCard()
{
	// ========= Font of the card =========

	// initializing front time
	m_TxtFrontTimePromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 120,35 },
																	{ 135,265 }, "Time" );
	m_TxtFrontTimeValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 60,35 },
																	{ 265,265 }, "", "TimeValue" );

	// initializing up
	m_TxtUpPromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 120,35 },
															 { 135,310 }, "Up:" );
	m_TxtUpValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 60,35 },
															 { 265,310 }, "", "UpValue" );

	// initializing down
	m_TxtDownPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 120,35 },
																{ 135,355 }, "Down:" );
	m_TxtDownValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 60,35 },
															   { 265,355 }, "", "downValue" );
	// initializing turn card
	m_BtnTurnCard = Brood::BroodUI::Button::DyCreateButton( { 190, 35 },
															{ 135, 400 }, "turn card" );

	// ========= back of the card =========

	// initializing back time
	m_TxtBackTimePromt = Brood::BroodUI::TextBox::DyCreateTextBox( { 85,35 },
																   { 115,220 }, "Time left" );
	m_TxtBackTimeValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 140,35 },
																   { 210,220 }, "", "TimeValue" );

	// initializing answer
	m_TxtQuestionPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 240,35 },
																	{ 115,265 }, "Question: " );
	m_TxtQuestionValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 240,35 },
																   { 115,310 }, "", "answer" );

	// initializing userAnswer
	m_TxtUserAnswerPrompt = Brood::BroodUI::TextBox::DyCreateTextBox( { 240,35 },
																	  { 115,355 }, "Answer:" );
	m_TxtUserAnswerValue = Brood::BroodUI::TextBox::DyCreateTextBox( { 240,35 },
																	 { 115,400 }, "", "enter your answer" );

	// initializing submit button
	m_BtnSubmit = Brood::BroodUI::Button::DyCreateButton( { 140, 35 },
														  { 165, 445 }, "Submit Answer" );

	// updating the displayed text in the box
	UpdateDisplayedText();

	// setting up the card 
	// 
	// getting the top left cordinate of the box that
	//		encloses all the displayCard component
	sf::Vector2f topLeftPos = GetNearestTopLeftCordinate();

	// getting the bottom right cordinate of the box that
	//		encloses all the displayCard component
	sf::Vector2f bottomRightPos = GetFurtherstBottomRightCordinate();

	SetBodySize( ( bottomRightPos.x - topLeftPos.x ) + 20.f, ( bottomRightPos.y - topLeftPos.y ) + 20.f );
	SetBodyPosition( topLeftPos - sf::Vector2f{ 10,10 } );
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );
}

/// 
/// @brief  initializes the displayCard with the passed data
/// 
/// @param a_displayCardData reference of the card info data
/// 
void Brood::Application::Components::DisplayCard::InitializeDisplayCard( Brood::Application::Data::ST_DisplayCardData& a_displayCardData )
{
	// this never runs but
	// just to be sure
	if( m_TxtFrontTimePromt == nullptr )
	{
		InializeDisplayCard();
	}

	// setting up body
	SetBodySize( { a_displayCardData.stm_displayCardSizeX, a_displayCardData.stm_displayCardSizeY });
	SetBodyPosition({ a_displayCardData.stm_displayCardPositionX, a_displayCardData.stm_displayCardPositionY });
	
	if( !a_displayCardData.stm_displayCardFrontTextureFilename.empty())
	{
		SetFrontBgFileName( a_displayCardData.stm_displayCardFrontTextureFilename );
	}

	if( !a_displayCardData.stm_displayCardBackTextureFilename.empty() )
	{
		SetBackBgFileName( a_displayCardData.stm_displayCardBackTextureFilename );
	}

	// displays time user have to complete the answer
	m_TxtFrontTimePromt->SetBodySize( { a_displayCardData.stm_frontTimePromptSizeX, a_displayCardData.stm_frontTimePromptSizeY } );
	m_TxtFrontTimePromt->SetBodyPosition({ a_displayCardData.stm_frontTimePromptPositionX, a_displayCardData.stm_frontTimePromptPositonY});

	m_TxtFrontTimeValue->SetBodySize( { a_displayCardData.stm_frontTimeValueSizeX, a_displayCardData.stm_frontTimeValueSizeY } );
	m_TxtFrontTimeValue->SetBodyPosition( { a_displayCardData.stm_frontTimeValuePositionX, a_displayCardData.stm_frontTimeValuePositonY } );

	// displays number of steps that user goes forward
	m_TxtUpPromt->SetBodySize( { a_displayCardData.stm_upPromptSizeX, a_displayCardData.stm_upPromptSizeY } );
	m_TxtUpPromt->SetBodyPosition( { a_displayCardData.stm_upPromptPositionX, a_displayCardData.stm_upPromptPositonY } );

	m_TxtUpValue->SetBodySize( { a_displayCardData.stm_upValueSizeX, a_displayCardData.stm_upValueSizeY } );
	m_TxtUpValue->SetBodyPosition( { a_displayCardData.stm_upValuePositionX, a_displayCardData.stm_upValuePositonY } );

	// displays number of steps that user goes backward
	m_TxtDownPrompt->SetBodySize( { a_displayCardData.stm_downPromptSizeX, a_displayCardData.stm_downPromptSizeY } );
	m_TxtDownPrompt->SetBodyPosition( { a_displayCardData.stm_downPromptPositionX, a_displayCardData.stm_downPromptPositonY } );

	m_TxtDownValue->SetBodySize( { a_displayCardData.stm_downValueSizeX, a_displayCardData.stm_downValueSizeY } );
	m_TxtDownValue->SetBodyPosition( { a_displayCardData.stm_downValuePositionX, a_displayCardData.stm_downValuePositonY } );


	// button to turn the card of the card
	m_BtnTurnCard->SetBodySize( { a_displayCardData.stm_turnCardPromptSizeX, a_displayCardData.stm_turnCardPromptSizeY } );
	m_BtnTurnCard->SetBodyPosition( { a_displayCardData.stm_turnCardPromptPositionX, a_displayCardData.stm_turnCardPromptPositonY } );

	// ========= back of the card =========
	// displays time user have to complete the answer
	m_TxtBackTimePromt->SetBodySize( { a_displayCardData.stm_backTimePromptSizeX, a_displayCardData.stm_backTimePromptSizeY } );
	m_TxtBackTimePromt->SetBodyPosition( { a_displayCardData.stm_backTimePromptPositionX, a_displayCardData.stm_backTimePromptPositonY } );

	m_TxtBackTimeValue->SetBodySize( { a_displayCardData.stm_backTimeValueSizeX, a_displayCardData.stm_backTimeValueSizeY } );
	m_TxtBackTimeValue->SetBodyPosition( { a_displayCardData.stm_backTimeValuePositionX, a_displayCardData.stm_backTimeValuePositonY } );

	// displays the answer that user has to answer
	m_TxtQuestionPrompt->SetBodySize( { a_displayCardData.stm_answerPromptSizeX, a_displayCardData.stm_answerPromptSizeY } );
	m_TxtQuestionPrompt->SetBodyPosition( { a_displayCardData.stm_answerPromptPositionX, a_displayCardData.stm_answerPromptPositonY } );

	m_TxtQuestionValue->SetBodySize( { a_displayCardData.stm_answerValueSizeX, a_displayCardData.stm_answerValueSizeY } );
	m_TxtQuestionValue->SetBodyPosition( { a_displayCardData.stm_answerValuePositionX, a_displayCardData.stm_answerValuePositonY } );

	// displays the textbox for user to enter theiranswer
	m_TxtUserAnswerPrompt->SetBodySize( { a_displayCardData.stm_answerPromptSizeX, a_displayCardData.stm_answerPromptSizeY } );
	m_TxtUserAnswerPrompt->SetBodyPosition( { a_displayCardData.stm_answerPromptPositionX, a_displayCardData.stm_answerPromptPositonY } );

	m_TxtUserAnswerValue->SetBodySize( { a_displayCardData.stm_answerValueSizeX, a_displayCardData.stm_answerValueSizeY } );
	m_TxtUserAnswerValue->SetBodyPosition( { a_displayCardData.stm_answerValuePositionX, a_displayCardData.stm_answerValuePositonY } );

	// button to show back of the card
	m_BtnSubmit->SetBodySize( { a_displayCardData.stm_submitButtonValueSizeX, a_displayCardData.stm_submitButtonValueSizeY } );
	m_BtnSubmit->SetBodyPosition( { a_displayCardData.stm_submitButtonValuePositionX, a_displayCardData.stm_submitButtonValuePositonY } );
}

/// 
/// @public
/// @brief creates and returns displayCard data struct
/// 
/// @return displayCard data struct with the displayCard data in it
/// 
Brood::Application::Data::ST_DisplayCardData Brood::Application::Components::DisplayCard::GetDataToSave()
{
	Brood::Application::Data::ST_DisplayCardData displayCardData;

	// saving up body
	displayCardData.stm_displayCardSizeX = GetBodySize().x;	
	displayCardData.stm_displayCardSizeY  = GetBodySize().y;
	displayCardData.stm_displayCardPositionX = GetBodyPosition().x;
	displayCardData.stm_displayCardPositionY = GetBodyPosition().y;

	// saving file texture
	displayCardData.stm_displayCardFrontTextureFilename = m_frontBgFileName;
	displayCardData.stm_displayCardBackTextureFilename = m_backBgFileName;

	// displays time user have to complete the answer
	
	displayCardData.stm_frontTimePromptSizeX = m_TxtFrontTimePromt->GetBodySize().x;
	displayCardData.stm_frontTimePromptSizeY = m_TxtFrontTimePromt->GetBodySize().y;
	
	displayCardData.stm_frontTimePromptPositionX = m_TxtFrontTimePromt->GetBodyPosition().x;
	displayCardData.stm_frontTimePromptPositonY = m_TxtFrontTimePromt->GetBodyPosition().y;

	displayCardData.stm_frontTimeValueSizeX = m_TxtFrontTimeValue->GetBodySize().x;
	displayCardData.stm_frontTimeValueSizeY = m_TxtFrontTimeValue->GetBodySize().y;

	displayCardData.stm_frontTimeValuePositionX = m_TxtFrontTimeValue->GetBodyPosition().x;
	displayCardData.stm_frontTimeValuePositonY = m_TxtFrontTimeValue->GetBodyPosition().y;

	// displays number of steps that user goes forward

	displayCardData.stm_upPromptSizeX = m_TxtUpPromt->GetBodySize().x;
	displayCardData.stm_upPromptSizeY = m_TxtUpPromt->GetBodySize().y;

	displayCardData.stm_upPromptPositionX = m_TxtUpPromt->GetBodyPosition().x;
	displayCardData.stm_upPromptPositonY = m_TxtUpPromt->GetBodyPosition().y;

	displayCardData.stm_upValueSizeX = m_TxtUpValue->GetBodySize().x;
	displayCardData.stm_upValueSizeY = m_TxtUpValue->GetBodySize().y;

	displayCardData.stm_upValuePositionX = m_TxtUpValue->GetBodyPosition().x;
	displayCardData.stm_upValuePositonY = m_TxtUpValue->GetBodyPosition().y;

	// displays number of steps that user goes backward

	displayCardData.stm_downPromptSizeX = m_TxtDownValue->GetBodySize().x;
	displayCardData.stm_downPromptSizeY = m_TxtDownValue->GetBodySize().y;

	displayCardData.stm_downPromptPositionX = m_TxtDownValue->GetBodyPosition().x;
	displayCardData.stm_downPromptPositonY = m_TxtDownValue->GetBodyPosition().y;

	displayCardData.stm_downValueSizeX = m_TxtDownValue->GetBodySize().x;
	displayCardData.stm_downValueSizeY = m_TxtDownValue->GetBodySize().y;

	displayCardData.stm_downValuePositionX = m_TxtDownValue->GetBodyPosition().x;
	displayCardData.stm_downValuePositonY = m_TxtDownValue->GetBodyPosition().y;

	// button to turn the card of the card

	displayCardData.stm_turnCardPromptSizeX = m_BtnTurnCard->GetBodySize().x;
	displayCardData.stm_turnCardPromptSizeY = m_BtnTurnCard->GetBodySize().y;

	displayCardData.stm_turnCardPromptPositionX = m_BtnTurnCard->GetBodyPosition().x;
	displayCardData.stm_turnCardPromptPositonY = m_BtnTurnCard->GetBodyPosition().y;

	// ========= back of the card =========
	 
	// displays time user have to complete the answer

	displayCardData.stm_backTimePromptSizeX = m_TxtBackTimePromt->GetBodySize().x;
	displayCardData.stm_backTimePromptSizeY = m_TxtBackTimePromt->GetBodySize().y;

	displayCardData.stm_backTimePromptPositionX = m_TxtBackTimePromt->GetBodyPosition().x;
	displayCardData.stm_backTimePromptPositonY = m_TxtBackTimePromt->GetBodyPosition().y;

	displayCardData.stm_backTimeValueSizeX = m_TxtBackTimeValue->GetBodySize().x;
	displayCardData.stm_backTimeValueSizeY = m_TxtBackTimeValue->GetBodySize().y;

	displayCardData.stm_backTimeValuePositionX = m_TxtBackTimeValue->GetBodyPosition().x;
	displayCardData.stm_backTimeValuePositonY = m_TxtBackTimeValue->GetBodyPosition().y;

	// displays the answer that user has to answer

	displayCardData.stm_answerPromptSizeX = m_TxtQuestionValue->GetBodySize().x;
	displayCardData.stm_answerPromptSizeY = m_TxtQuestionValue->GetBodySize().y;

	displayCardData.stm_answerPromptPositionX = m_TxtQuestionValue->GetBodyPosition().x;
	displayCardData.stm_answerPromptPositonY = m_TxtQuestionValue->GetBodyPosition().y;

	displayCardData.stm_answerValueSizeX = m_TxtQuestionValue->GetBodySize().x;
	displayCardData.stm_answerValueSizeY = m_TxtQuestionValue->GetBodySize().y;

	displayCardData.stm_answerValuePositionX = m_TxtQuestionValue->GetBodyPosition().x;
	displayCardData.stm_answerValuePositonY = m_TxtQuestionValue->GetBodyPosition().y;

	// displays the textbox for user to enter theiranswer

	displayCardData.stm_answerPromptSizeX = m_TxtUserAnswerValue->GetBodySize().x;
	displayCardData.stm_answerPromptSizeY = m_TxtUserAnswerValue->GetBodySize().y;

	displayCardData.stm_answerPromptPositionX = m_TxtUserAnswerValue->GetBodyPosition().x;
	displayCardData.stm_answerPromptPositonY = m_TxtUserAnswerValue->GetBodyPosition().y;

	displayCardData.stm_answerValueSizeX = m_TxtUserAnswerValue->GetBodySize().x;
	displayCardData.stm_answerValueSizeY = m_TxtUserAnswerValue->GetBodySize().y;

	displayCardData.stm_answerValuePositionX = m_TxtUserAnswerValue->GetBodyPosition().x;
	displayCardData.stm_answerValuePositonY = m_TxtUserAnswerValue->GetBodyPosition().y;

	// button to show back of the card
	displayCardData.stm_submitButtonValueSizeX = m_BtnSubmit->GetBodySize().x;
	displayCardData.stm_submitButtonValueSizeY = m_BtnSubmit->GetBodySize().y;

	displayCardData.stm_submitButtonValuePositionX = m_BtnSubmit->GetBodyPosition().x;
	displayCardData.stm_submitButtonValuePositonY = m_BtnSubmit->GetBodyPosition().y;

	return displayCardData;
}

/// 
/// @public
/// @brief loads the DisplayCard data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::DisplayCard::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// saving the dice data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );
}

/// 
/// @public
/// @brief loads the DisplayCard and its path data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::DisplayCard::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// loading the DisplayCard data
	Brood::Application::Data::ST_DisplayCardData displayCardData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	displayCardData.PopulateFromString( dataFromFile );
	InitializeDisplayCard( displayCardData );
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
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetFrontTimePromptPtr()
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
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetUpPromptPtr()
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
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetBackTimePromptPtr()
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
/// @brief Getter function to get the pointer to the answer prompt ui element
/// 
/// @return pointer to the answer prompt ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetQuestionPromptPtr()
{
	return m_TxtQuestionPrompt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the answer value ui element
/// 
/// @return pointer to the answer value ui element
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
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetAnswerPromptPtr()
{
	return m_TxtUserAnswerPrompt;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the user answer value ui element
/// 
/// @return pointer to the user answer value ui element
///
Brood::BroodUI::TextBox* Brood::Application::Components::DisplayCard::GetAnswerValuePtr()
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
/// @brief gets the bottom right cordinate of the box that
///		encloses all the child component
/// 
/// @return gets the bottom right cordinate of the box that
///		encloses all the child component
///
sf::Vector2f Brood::Application::Components::DisplayCard::GetFurtherstBottomRightCordinate()
{
	// stores the largest Upper position found
	sf::Vector2f largestUpperPos = { std::numeric_limits<float>::min(), std::numeric_limits<float>::min() };

	// for m_TxtFrontTimePromt
	UpdateLargestUpperPos( largestUpperPos, m_TxtFrontTimePromt );

	// for m_TxtFrontTimeValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtFrontTimeValue );

	// for m_TxtUpPromt
	UpdateLargestUpperPos( largestUpperPos, m_TxtUpPromt );

	// for m_TxtUpValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtUpValue );

	// for m_TxtDownPrompt
	UpdateLargestUpperPos( largestUpperPos, m_TxtDownPrompt );

	// for m_TxtDownValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtDownValue );

	// for m_BtnTurnCard
	UpdateLargestUpperPos( largestUpperPos, m_BtnTurnCard );

	// for m_TxtBackTimePromt
	UpdateLargestUpperPos( largestUpperPos, m_TxtBackTimePromt );

	// for m_TxtBackTimeValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtBackTimeValue );

	// for m_TxtQuestionPrompt
	UpdateLargestUpperPos( largestUpperPos, m_TxtQuestionPrompt );

	// for m_TxtBackTimeValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtBackTimeValue );

	// for m_TxtUserAnswerPrompt
	UpdateLargestUpperPos( largestUpperPos, m_TxtUserAnswerPrompt );

	// for m_TxtUserAnswerValue
	UpdateLargestUpperPos( largestUpperPos, m_TxtUserAnswerValue );

	// for m_BtnSubmit
	UpdateLargestUpperPos( largestUpperPos, m_BtnSubmit );

	return largestUpperPos;
}

/// 
/// @public
/// @brief gets top left cordinate of the box that
///		encloses all the child component
/// 
/// @return gets top left cordinate of the box that
///		encloses all the child component
///
sf::Vector2f Brood::Application::Components::DisplayCard::GetNearestTopLeftCordinate()
{
	// stores the largest Upper position found
	sf::Vector2f smallestLowerPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };

	// for m_TxtFrontTimePromt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtFrontTimePromt );

	// for m_TxtFrontTimeValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtFrontTimeValue );

	// for m_TxtUpPromt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtUpPromt );

	// for m_TxtUpValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtUpValue );

	// for m_TxtDownPrompt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtDownPrompt );

	// for m_TxtDownValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtDownValue );

	// for m_BtnTurnCard
	UpdateSmallestLowerPos( smallestLowerPos, m_BtnTurnCard );

	// for m_TxtBackTimePromt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtBackTimePromt );

	// for m_TxtBackTimeValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtBackTimeValue );

	// for m_TxtQuestionPrompt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtQuestionPrompt );

	// for m_TxtBackTimeValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtBackTimeValue );

	// for m_TxtUserAnswerPrompt
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtUserAnswerPrompt );

	// for m_TxtUserAnswerValue
	UpdateSmallestLowerPos( smallestLowerPos, m_TxtUserAnswerValue );

	// for m_BtnSubmit
	UpdateSmallestLowerPos( smallestLowerPos, m_BtnSubmit );

	return smallestLowerPos;
}

/// 
/// @public
/// @brief Setter function to set a front background filename
/// 
/// @param a_frontBgFilename front background filename
///
/// @return true if texture was successfully set
/// 
bool Brood::Application::Components::DisplayCard::SetFrontBgFileName( std::string a_frontBgFilename )
{
	if( GetSpriteBody().SetTextureFromFilePath( a_frontBgFilename ) )
	{
		m_frontBgFileName = a_frontBgFilename;
		return true;
	}
	return false;
}

/// 
/// @public
/// @brief Setter function to set a back background filename
/// 
/// @param a_backBgFilename back background filename
/// 
/// @return true if texture was successfully set
/// 
bool Brood::Application::Components::DisplayCard::SetBackBgFileName( std::string a_backBgFilename )
{
	if( GetSpriteBody().SetTextureFromFilePath( a_backBgFilename ) )
	{
		m_backBgFileName = a_backBgFilename;
		return true;
	}
	return false;
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
void Brood::Application::Components::DisplayCard::ToggleCardFace()
{
	if( m_isCurrFront )
	{
		SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );
		m_bodySprite.SetTextureFromFilePath( m_backBgFileName );
	}
	else
	{
		SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );
		m_bodySprite.SetTextureFromFilePath( m_frontBgFileName );
	}

	m_isCurrFront = !m_isCurrFront;
}

/// 
/// @public
/// @brief sets m_currFront
/// 
/// @param a_currFront If current bg is using front then toggles it to use back
/// 
void Brood::Application::Components::DisplayCard::SetCardFront( bool a_currFront )
{
	m_isCurrFront = a_currFront;

	if( m_isCurrFront )
	{
		SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );
		m_bodySprite.SetTextureFromFilePath( m_backBgFileName );
	}
	else
	{
		SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );
		m_bodySprite.SetTextureFromFilePath( m_frontBgFileName );
	}
}

/// 
/// @public
/// @brief updates the displayed text from the saved cardInfo
/// 
void Brood::Application::Components::DisplayCard::UpdateDisplayedText()
{
	if( m_cardInfoToDisplay == nullptr )
	{
		return;
	}

	m_TxtFrontTimeValue->SetText( std::to_string( m_cardInfoToDisplay->GetTime() ) );
	m_TxtUpValue->SetText( std::to_string( m_cardInfoToDisplay->GetCorrectNumSteps() ) );
	m_TxtDownValue->SetText( std::to_string( m_cardInfoToDisplay->GetIncorrectNumSteps() ) );
	m_TxtBackTimeValue->SetText( std::to_string( m_cardInfoToDisplay->GetTime() ) );
	m_TxtQuestionValue->SetText( m_cardInfoToDisplay->GetQuestion() );
	m_TxtQuestionValue->SetText( m_cardInfoToDisplay->GetCorrectAnswer() );
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
	Brood::BroodUI::Button::Draw( a_window );

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

		// drawing answer
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

	// debugging answer
	m_TxtQuestionPrompt->Debugger();
	m_TxtQuestionValue->Debugger();

	// debugging user answer
	m_TxtUserAnswerPrompt->Debugger();
	m_TxtUserAnswerValue->Debugger();

	// debugging submit button
	m_BtnSubmit->Debugger();
}

/// 
/// @private
/// @brief Getter function to get the bottom right coridinate  of the
///		passed component 
/// 
/// @param a_comp component whose bottom right coridinate is to be found
///
/// @return the bottom right coridinate  of the passed component
///
sf::Vector2f Brood::Application::Components::DisplayCard::GetCompUpperPos( Brood::BroodUI::UIElement* a_comp )
{
	return  ( a_comp->GetBodyPosition() + a_comp->GetBodySize() );
}

/// 
/// @private
/// @brief updates the passed largest upper pos by comparaing it with the 
///		upper position of the passed component
/// 
/// @param a_largestUpperPos largest upper pos passed by reference
/// @param a_comp component whose upperPos is to be compared to
/// 
void Brood::Application::Components::DisplayCard::UpdateLargestUpperPos( sf::Vector2f& a_largestUpperPos,
																		 Brood::BroodUI::UIElement* a_comp )
{
	sf::Vector2f currComponentUpperPos = GetCompUpperPos( a_comp );

	a_largestUpperPos.x = std::max( a_largestUpperPos.x, currComponentUpperPos.x );
	a_largestUpperPos.y = std::max( a_largestUpperPos.y, currComponentUpperPos.y );
}

/// 
/// @private
/// @brief updates the passed smallest lower pos by comparaing it with the 
///		lower position of the passed component
/// 
/// @param a_smallestLowerPos smallest lower pos passed by reference
/// @param a_comp component whose lowerPos is to be compared to
/// 
void Brood::Application::Components::DisplayCard::UpdateSmallestLowerPos( sf::Vector2f& a_smallestLowerPos,
																		  Brood::BroodUI::UIElement* a_comp )
{
	sf::Vector2f currComponentUpperPos = ( sf::Vector2f )a_comp->GetBodyPosition();

	a_smallestLowerPos.x = std::min( a_smallestLowerPos.x, currComponentUpperPos.x );
	a_smallestLowerPos.y = std::min( a_smallestLowerPos.y, currComponentUpperPos.y );
}



// ======================================================================
// ================= end of DisplayCard class ===========================
// ======================================================================