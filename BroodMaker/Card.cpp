/*************************************************************************/
/// 
/// @file Card.cpp 
/// 
/// @brief  This file is a source file for Card class.
/// 
/// It contains all of the defination of the member 
///		funciton of Card class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "Card.h"

/// 
/// @public
/// @brief Default Constructor
/// 
/// @param a_font reference to sf::Font that sf::Text uses
/// @param a_cardSizeX Size of the card in x-axis -> default 0.f
/// @param a_cardSizeY Size of the card in y-axis -> default 0.f
/// @param a_question question to ask -> default ""
/// @param a_corrAnswer correct answer to the question -> default ""
/// @param a_time time to answer the question -> defualt 0
/// @param a_correctNumSteps number of steps that the player moves forward
///			 if player answers correctly -> default 0
/// @param a_incorrectNumSteps number of steps that the player moves backward
///			if player answers incorrectly -> default 0
/// 
Card::Card( sf::Font& a_font, 
			float a_cardSizeX, float a_cardSizeY, 
			std::string a_question, std::string a_corrAnswer,
			float a_time, 
			unsigned a_correctNumSteps, unsigned a_incorrectNumSteps )
{
	m_displayBack = false;

	// setting up board
	this->m_cardBody.setSize( sf::Vector2f( a_cardSizeX, a_cardSizeY ) );
	this->m_cardBody.setPosition( 200, 100);
	this->m_cardBody.setFillColor( sf::Color::Green );

	// setting up St_QAnsPair
	TextMemberVarSetter( a_font, m_queAns.stm_question, a_question, .2f );
	m_queAns.stm_corrAnswer = a_corrAnswer;
	
	// setting up ohter the texts
	TextMemberVarSetter( a_font, m_time, std::to_string( a_time ), 0.3f );
	TextMemberVarSetter( a_font, m_correctNumSteps, "go up: " + std::to_string(a_correctNumSteps) + " number of steps", 0.6f);
	TextMemberVarSetter( a_font, m_incorrectNumSteps, "go up: " + std::to_string( a_incorrectNumSteps ) + " number of steps", 0.8f );
	TextMemberVarSetter( a_font, m_userAns, "" , 0.4f );
}
void Card::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_cardBody );
	if( m_displayBack )
	{
		a_window.draw( m_queAns.stm_question );
		/// @todo add a text box where uses can enter their answer
	}
	a_window.draw( m_time );
	a_window.draw( m_correctNumSteps );
	a_window.draw( m_incorrectNumSteps);
}

/// 
/// @private
/// @brief helperfunction to set the sf::text datatype
/// @param a_font reference to the font that is going to be used
/// @param a_textVarName refernce to the member variable
/// @param a_textStr string that the text  will have
/// @param a_offsetPercent where the text is going to be relative to card
void Card::TextMemberVarSetter( sf::Font& a_font, sf::Text& a_textVarName, 
								std::string a_textStr, float a_offsetPercent )
{

	sf::Vector2f cardPos = m_cardBody.getPosition();
	sf::Vector2f offSet( cardPos.x * a_offsetPercent, cardPos.y * a_offsetPercent );

	// setting up the texts
	a_textVarName.setFont( a_font );
	a_textVarName.setString( a_textStr );
	a_textVarName.setFillColor( sf::Color::White );
	a_textVarName.setPosition( cardPos + offSet );
}
