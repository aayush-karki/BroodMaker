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

#include "Card.h"

/// 
/// @public
/// @brief Default Constructor
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
Card::Card( float a_cardSizeX, float a_cardSizeY,
			std::string a_question, std::string a_corrAnswer,
			float a_time, 
			unsigned a_correctNumSteps, unsigned a_incorrectNumSteps)
{
	m_userAns = "";
	m_displayBack = false;

	// setting up board
	this->m_cardBody.setSize( sf::Vector2f( a_cardSizeX, a_cardSizeY ) );
	this->m_cardBody.setPosition( 200, 100);
	this->m_cardBody.setFillColor( sf::Color::Green );

	// setting up St_QAnsPair
	m_queAns.stm_corrAnswer =  a_corrAnswer;
	m_queAns.stm_question = a_question;

	// setting up the texts
	m_time.setString("asedfghjk");
	m_time.setFillColor( sf::Color::White );
	m_time.setCharacterSize( 200 );
	sf::Vector2f cardPos = m_cardBody.getPosition();
	sf::Vector2f offSet( cardPos.x * 0.1, cardPos.y * 0.1 );
	m_time.setPosition( cardPos + offSet );
	
	// setting up other member variables
	m_correctNumSteps = a_correctNumSteps;
	m_incorrectNumSteps = a_incorrectNumSteps;
}

void Card::Draw( sf::RenderWindow& a_window )
{
	//a_window.draw( m_cardBody );
	a_window.draw( m_time );

	
}
