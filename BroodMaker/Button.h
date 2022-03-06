#pragma once
#include <SFML/Graphics.hpp>

class Button
{
	// ============ public member function =============== 
public:
	Button() {};
	Button( std::string a_text, sf::Vector2f a_size, int a_charSize,
			sf::Color a_bgColor, sf::Color a_textColor );

	void SetFont( sf::Font& a_font ); // setter funciton to set the font size
	void SetTextColor( sf::Color a_color ); // setter funciton to set the text color
	void SetBtnBackColor( sf::Color a_color ); // setter funciton to set the bg color of button
	void SetPosition( sf::Vector2f a_pos ); // setter funciton to set the position of the text

	void Draw( sf::RenderWindow& a_window ); // draw to renderwindow

	bool IsMouseOverBtn( sf::RenderWindow& a_window ); // detect if the mouse is over the button or not

	// ============ private member variables =============== 
private:
	sf::RectangleShape m_button;
	sf::Text m_text;
};

/// @brief setter funciton to set the font size
inline void Button::SetFont( sf::Font& a_font )
{
	m_text.setFont( a_font );
}

/// @brief setter funciton to set the text color
/// @param a_color font color
inline void Button::SetTextColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// @brief setter funciton to set the bg color of button
/// @param a_color font color
inline void Button::SetBtnBackColor( sf::Color a_color )
{
	m_button.setFillColor( a_color );
}

/// @brief Draw function 
/// @param a_window reference to render window
inline void Button::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_button );
	a_window.draw( m_text );
}

