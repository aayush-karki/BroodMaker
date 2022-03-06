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
#include "TextBox.h"

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
	Card( sf::Font& a_font, float a_cardSizeX = 0.f, float a_cardSizeY = 0.f,
		  std::string a_question = "", std::string a_corrAnswer = "",
		  float a_time = 0.0f,
		  unsigned a_correctNumSteps = 0, unsigned a_incorrectNumSteps = 0); 
	void Draw( sf::RenderWindow& a_window );
public:
	struct St_QAnspair
	{
		sf::Text stm_question;
		sf::String stm_corrAnswer;
	};

	// ============== private memeber function =================
private:
	void TextMemberVarSetter( sf::Font& a_font, sf::Text& a_textVarName, 
							  std::string a_textStr, float a_offsetPercent );

	// ============== private memeber variables =================
private:
	sf::RectangleShape m_cardBody;

	// in card
	sf::Text m_time;
	sf::Text m_correctNumSteps;
	sf::Text m_incorrectNumSteps;

	// back of the card
	St_QAnspair m_queAns;
	sf::Text m_userAns;

	//TextBox m_userAns;

	bool m_displayBack;

};


// ================== definations  =================
