/*************************************************************************/
/// 
/// @file Card.h 
/// 
/// @brief  This file is a header file for Card class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Card class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Card class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

///
/// @class Card  "Card.h"
/// 
/// @brief A Card Class
/// 
class Card
{
	// ============== public memeber function =================
public:
	Card( float a_cardSizeX = 0.f, float a_cardSizeY = 0.f ); // default constructor

	// ============== private memeber variables =================
private:
	sf::RectangleShape m_cardBody;
	//float m_cardBody

	// front of the card
	float m_time;
	unsigned m_correctNumSteps;
	unsigned m_incorrectNumSteps;

	// back of the card
	std::string m_question;
	float m_answer;

};


// ================== definations  =================
