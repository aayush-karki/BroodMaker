#include "SFML/Graphics.hpp"
#include <filesystem>

#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox
{
	// ============ public member function =============== 
public:
	// default constructor
	TextBox( int a_size = 15, sf::Color a_color = sf::Color::White, bool a_selected = false);

	void SetFont( sf::Font& a_font ); // setter funciton to set the font size
	void SetPosition( sf::Vector2f a_pos ); // setter funciton to set the position of the text
	void SetLimit( bool a_hasLimit = false, unsigned a_limit = 0 ); // setter funciton to set the limit member variable 
	void setSelected( bool a_selected ); // setter funciton to set the selected member variable 
	std::string GetText(); // getter function to get the text
	void Draw( sf::RenderWindow& a_window ); // draw to renderwindow
	void TypeOn( sf::Event a_input ); // called every time user enters a char

		// ============ private member function =============== 
private:
	void InputLogic( int charTyped ); // all of the logic; called on every key press
	void DeleteLastChar(); // delete last char

	// ============ private member variables ===============
private:
	sf::Text m_textBox;
	std::ostringstream m_text;
	bool m_isSelected = false;
	bool m_hasLimit = false;
	int m_limit = -1;

};

/// 
/// @brief setter funciton to set the limit
/// 
/// @note setting the limit to zero will have 1  char limit
/// 
/// @param a_hasLimit true if the text box has a limit attached to it
/// @param a_limit max number of character allowed
/// 
inline void TextBox::SetLimit( bool a_hasLimit, unsigned a_limit)
{
	m_hasLimit = a_hasLimit;
	m_limit = a_limit;

	if( a_limit != 0 )
	{
		m_limit;
	}
}

/// @brief Draw function 
/// @param a_window reference to render window
inline void TextBox::Draw( sf::RenderWindow& a_window ) 
{
	a_window.draw( m_textBox );
}

/// @brief getter funciton to get the typed text
/// @return text that user typed
inline std::string TextBox::GetText() 
{
	return m_text.str();
}

/// @brief setter funciton to set the position
inline void TextBox::SetPosition( sf::Vector2f a_pos )
{
	m_textBox.setPosition( a_pos );
}

/// @brief setter funciton to set the font size
inline void TextBox::SetFont( sf::Font& a_font ) 
{
	m_textBox.setFont( a_font );
}