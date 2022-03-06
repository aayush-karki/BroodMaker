#include "TextBox.h"

/// 
/// @public
/// @brief  Constructor
/// 
/// @param a_size Size of the character in pixel
/// @param a_color color of the character
/// @param a_selected if the current is selected or not
/// 
TextBox::TextBox( int a_size, sf::Color a_color, bool a_selected)
{
	m_textBox.setCharacterSize( a_size );
	m_textBox.setFillColor( a_color );

	m_isSelected = a_selected;
	if( m_isSelected )
	{
		m_textBox.setString( "_" );
	}
	else
	{
		m_textBox.setString( "" );
	}

	SetLimit();
}

/// 
/// @brief setter function
/// @param a_selected true if current text box is selected or not
/// 
void TextBox::setSelected( bool a_selected )
{
	m_isSelected = a_selected;
	if( !a_selected )
	{
		std::string tempStr = m_text.str();
		std::string newStr = "";

		// copying the string except the last char
		for( unsigned i = 0; i < tempStr.length(); ++i )
		{
			newStr += tempStr[ i ];
		}
		m_textBox.setString( newStr );
	}
}

/// 
/// @brief Called when a character is typed 
/// @param a_input a copy of sf::Event::TextEntered
/// 
void TextBox::TypeOn( sf::Event a_input )
{
	if( m_isSelected )
	{
		// we only process ascii codes
		unsigned charTyped = a_input.text.unicode;
		if( charTyped > 0 && charTyped < 128 )
		{
			if( m_hasLimit )
			{
				if( m_text.str().length() <= m_limit )
				{
					InputLogic( charTyped );
				}
				else if( m_text.str().length() > m_limit && charTyped == DELETE_KEY )
				{
					DeleteLastChar();
				}
			}
			else
			{
				InputLogic( charTyped );
			}
		}
	}
}

/// 
/// @private
/// @brief logic of what happens when different keys are pressed
/// @param charTyped ascii number that represent the char
/// 
void TextBox::InputLogic( int charTyped )
{
	if( charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY )
	{
		// appending the typed char to the text if it is not the special char
		m_text << static_cast< char >( charTyped );
		std::cout << charTyped << ": " << m_text.str() << std::endl;
	}
	else if( charTyped == DELETE_KEY )
	{
		// checking that there is something in the stringstream
		if( m_text.str().length() > 0 )
		{
			DeleteLastChar();
		}
	}
	m_textBox.setString( m_text.str() + "_" );

}

/// 
/// @private
/// @brief delete the last char form the user enterd string
/// 
void TextBox::DeleteLastChar()
{
	std::string tempStr = m_text.str();
	std::string newStr = "";

	// copying the string except the last char
	for( unsigned i = 0; i < tempStr.length() - 1; ++i )
	{
		newStr += tempStr[ i ];
	}

	// clearing the stringstream and copying the data
	m_text.str( "" );
	m_text << newStr;

	m_textBox.setString( m_text.str() );

}