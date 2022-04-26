/*************************************************************************/
/// 
/// @file Button.h 
/// 
/// @brief  This file is a source file for Button class.
/// 
/// It contains all of the defination of the member 
///		funciton of Button class.
///
/************************************************************************/

#include "stdafx.h"
#include "Button.h"

/// 
/// @brief setter funciton to set the text that is displayed in the button
/// 
/// @note if the text is empty, it only sets the color and charSize. It also sets the 
///		drawText to false. 
/// 
/// @warning It assumes that the font for the text is already set
/// 
/// @param a_text text to show on the buttom -> default empty string
/// @param a_color text color -> default sf::color::white
/// @param a_charSize -> size of indivisual character in the text -> deafult 12
/// 
void Brood::BroodUI::Button::SetText( std::string a_text, sf::Color a_color, unsigned a_charSize )
{

	m_text.setFillColor( a_color );
	m_text.setCharacterSize( a_charSize );

	// if the text is empty there is no point in displaying the text
	if( !a_text.empty() )
	{
		m_text.setString( a_text );
		Brood::BroodUI::Button::SetTextPosition();
		m_drawText = true;
	}
	else
	{
		m_drawText = false;
	}

}

/// 
/// @private
/// @brief setter funciton to set the position of the text.
/// 
/// Sets the position of the text such that it is always centered
/// 
void Brood::BroodUI::Button::SetTextPosition()
{
	// getting m_text's center
	float textCenterX = m_text.getLocalBounds().width / 2;
	float textCenterY = m_text.getLocalBounds().height / 2;

	// getting te postion of the text; origin is at the top left of the text

	float xPosText = ( GetBodyPosition().x + GetBodySize().x / 2 ) - textCenterX;
	float yPosText = ( GetBodyPosition().y + GetBodySize().y / 2 ) - textCenterY;

	m_text.setPosition( xPosText, yPosText );
	std::cout << m_text.getPosition().x << m_text.getPosition().y << std::endl;;
}
