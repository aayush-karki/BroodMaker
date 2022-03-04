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
#include "Struct_CtorParam.h"

///
/// @class Card  "Card.h"
/// 
/// @brief A Card Class
/// 
class Card
{
	// ============== public memeber function =================
public:
	// default constructor
	Card( float a_cardSizeX = 0.f, float a_cardSizeY = 0.f,
		  std::string a_question = "", std::string a_corrAnswer = "",
		  float a_time = 0.0f,
		  unsigned a_correctNumSteps = 0, unsigned a_incorrectNumSteps = 0); 
	void Draw( sf::RenderWindow& a_window );
public:
	struct St_QAnspair
	{
		sf::String stm_question = "";
		sf::String stm_corrAnswer = "";
	};

	// ============== private memeber variables =================
private:
	sf::RectangleShape m_cardBody;

	// in card
	sf::Text m_time;
	sf::Text text;
	sf::String m_correctNumSteps;
	sf::String m_incorrectNumSteps;

	// back of the card
	St_QAnspair m_queAns;
	sf::String m_userAns;

	bool m_displayBack;

};


// ================== definations  =================
