#include "Button.h"
#include <iostream>

/// @brief Default Constructor
/// @param a_text text to show inside the button 
/// @param a_size size of the button
/// @param a_charSize size of each character of text
/// @param a_bgColor initaial bg color
/// @param a_textColor text color
Button::Button( std::string a_text, sf::Vector2f a_size, int a_charSize,
		sf::Color a_bgColor, sf::Color a_textColor )
{
	m_text.setString( a_text );
	m_text.setFillColor( a_textColor );
	m_text.setCharacterSize( a_charSize );


	m_button.setSize( a_size );
	m_button.setFillColor( a_bgColor );

}

/// 
/// @brief setter funciton to set the position
/// 
/// sets the button and then centers the text
/// 
void Button::SetPosition( sf::Vector2f a_pos )
{
	m_button.setPosition( a_pos );

	// getting the start pos of the text such that it is always centered
	std::cout << m_text.getString().toAnsiString() << "----m_text.getLoc()width : " << m_text.getLocalBounds().height << std::endl;
	float xPosText = ( a_pos.x + m_button.getLocalBounds().width / 2 ) - ( m_text.getLocalBounds().width / 2 );
	float yPosText = ( a_pos.y + m_button.getLocalBounds().height / 2 ) - ( m_text.getLocalBounds().height  );

	m_text.setPosition( xPosText, yPosText );

}

bool Button::IsMouseOverBtn( sf::RenderWindow& a_window )
{
	int mousePosX = sf::Mouse::getPosition( a_window ).x;
	int mousePosY = sf::Mouse::getPosition( a_window ).y;

	// getting the upper left x and y pos of button
	float btnUpperPosX = m_button.getPosition().x;
	float btnUpperPosY = m_button.getPosition().y;

	// getting the lower right x and y pos of button
	float btnLowerPosX = btnUpperPosX + m_button.getLocalBounds().width;
	float btnLowerPosY = btnUpperPosY + m_button.getLocalBounds().height;

	if( mousePosX > btnUpperPosX && mousePosX < btnLowerPosX &&
		mousePosY > btnUpperPosY && mousePosY < btnLowerPosY )
	{
		return true;
	}
	return false;
}