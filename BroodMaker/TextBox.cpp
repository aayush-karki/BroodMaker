/*************************************************************************/
/// 
/// @file TextBox.h 
/// 
/// @brief  This file is a source file for TextBox class.
/// 
/// It contains all of the defination of the member 
///		funciton of TextBox class.
///
/************************************************************************/

#include "stdafx.h"
#include "TextBox.h"

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the textBox object
/// 
/// It alse sets the default value of isEditable, isSelected, 
///		and hasLimit to false.
/// It sets the limit to -1.
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// 
Brood::BroodUI::TextBox::TextBox( Brood::BroodUI::UIElement* a_parentPtr, int a_index ) :
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_textBox,
							   a_parentPtr, a_index ),
	m_isEditable( false ), m_isSelected( false ), m_hasLimit( false ),
	m_limit( -1 )
{}

Brood::BroodUI::TextBox::~TextBox()
{}

/// 
/// @public
/// @brief getter funciton to get the typed text
/// 
/// @return text that user typed
/// 
std::string Brood::BroodUI::TextBox::TextBox::GetText()
{
	return m_ossText.str();
}

/// 
/// @public
/// @brief Setter function to set the TextBox's Size
/// 
/// @param a_size size of the element
/// 
void Brood::BroodUI::TextBox::SetBodySize( sf::Vector2f a_size )
{
	Brood::BroodUI::UIElement::SetBodySize( a_size );
}

/// 
/// @public
/// @overload
/// @brief Setter function to set the TextBox's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
/// 
void Brood::BroodUI::TextBox::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::TextBox::SetBodySize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the textbox's Position.
/// 
/// @param a_pos position of the element 
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
///  
void Brood::BroodUI::TextBox::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( a_pos, a_relativeToParent );
	SetTextPosition();
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the textbox's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
void Brood::BroodUI::TextBox::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::TextBox::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief setter funciton to set the font size
/// 
void Brood::BroodUI::TextBox::SetFont( sf::Font& a_font )
{
	m_text.setFont( a_font );
}

/// 
/// @public
/// @brief setter funciton to set the Font color
/// 
/// param a_color font color -> default sf::Color::White
/// 
void Brood::BroodUI::TextBox::SetFontColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// 
/// @public
/// @brief setter funciton to set the Font Color
/// 
/// @param a_charSize -> size of indivisual character in the text -> deafult 12
/// 
void Brood::BroodUI::TextBox::SetFontSize( int a_charSize )
{
	m_text.setCharacterSize( a_charSize );
}

/// 
/// @brief setter funciton to set the text that is displayed in the button
/// 
/// @warning It assumes that the font for the text is already set
/// 
/// @param a_text text to show on the buttom -> default empty string
/// 
void Brood::BroodUI::TextBox::SetText( std::string a_text )
{
	m_text.setString( a_text );

	// clearing the stringstream and copying the data
	m_ossText.str( "" );
	m_ossText << a_text;

	Brood::BroodUI::TextBox::SetTextPosition();
}

/// 
/// @public
/// @brief setter funciton to set the limit
/// 
/// @note setting the limit to zero will have 1  char limit
/// 
/// @param a_hasLimit true if the text box has a limit attached to it
/// @param a_limit max number of character allowed
/// 
void Brood::BroodUI::TextBox::SetLimit( bool a_hasLimit, int a_limit )
{
	if( a_hasLimit && a_limit > 0 )
	{
		m_hasLimit = a_hasLimit;
		m_limit = a_limit;
	}
	else if( a_limit <= 0 )
	{
		std::cerr << "limit cannot be less than 1" << std::endl;
	}
}

/// 
/// @public
/// @brief setter function
/// 
/// @param a_selected true if current text box is selected or not
/// 
void Brood::BroodUI::TextBox::SetSelected( bool a_selected )
{
	m_isSelected = a_selected;
	if( !a_selected )
	{
		std::string tempStr = m_ossText.str();
		std::string newStr = "";

		// copying the string except the last char
		for( unsigned i = 0; i < tempStr.length(); ++i )
		{
			newStr += tempStr[ i ];
		}
		m_text.setString( newStr );
	}
}

/// 
/// @public
/// @brief setter function
/// 
/// @param a_isEditable true if text box is editable
/// 
void Brood::BroodUI::TextBox::SetEditable( bool a_isEditable )
{
	m_isEditable = a_isEditable;
}

/// 
/// @public
/// @brief Called when a character is typed 
/// 
/// @param a_input a copy of sf::Event::TextEntered
/// 
void Brood::BroodUI::TextBox::TypeOn( sf::Event a_input )
{
	if( m_isSelected )
	{
		// we only process ascii codes
		unsigned charTyped = a_input.text.unicode;
		if( charTyped > 0 && charTyped < 128 )
		{
			if( m_hasLimit )
			{
				if( m_ossText.str().length() <= m_limit )
				{
					InputLogic( charTyped );
				}
				else if( m_ossText.str().length() > m_limit && charTyped == DELETE_KEY )
				{
					DeleteLastChar();
				}
			}
			else
			{
				InputLogic( charTyped );
			}

			// setting the text position
			SetTextPosition();
		}
	}
}

/// 
/// @public
/// @brief Draw function 
/// 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::TextBox::Draw( sf::RenderWindow& a_window )
{
	if( m_isEditable || m_text.getString() != "" )
	{
		Brood::BroodUI::UIElement::Draw( a_window );
		a_window.draw( m_text );
	}
}

/// 
/// @private
/// @brief setter funciton to set the position of the text.
/// 
/// Sets the position of the text such that it is always centered
/// 
void Brood::BroodUI::TextBox::SetTextPosition()
{
	// getting m_text's center
	float textCenterX = m_text.getLocalBounds().width / ( float )2;
	float textCenterY = m_text.getCharacterSize() / float(1.5);

	// getting te postion of the text; origin is at the top left of the text

	float xPosText = ( GetBodyPosition().x + GetBodySize().x / 2 ) - textCenterX;
	float yPosText = ( GetBodyPosition().y + GetBodySize().y / 2 ) - textCenterY;

	m_text.setPosition( xPosText, yPosText );
	std::cout << m_text.getPosition().x << m_text.getPosition().y << std::endl;;
}

/// 
/// @private
/// @brief logic of what happens when different keys are pressed
///
/// @param charTyped ascii number that represent the char
/// 
void Brood::BroodUI::TextBox::InputLogic( int charTyped )
{
	if( charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY )
	{
		// appending the typed char to the text if it is not the special char
		m_ossText << static_cast< char >( charTyped );
		std::cout << charTyped << ": " << m_ossText.str() << std::endl;
	}
	else if( charTyped == DELETE_KEY )
	{
		// checking that there is something in the stringstream
		if( m_ossText.str().length() > 0 )
		{
			DeleteLastChar();
		}
	}
	m_text.setString( m_ossText.str() + "_" );
}

/// 
/// @private
/// @brief delete the last char form the user enterd string
/// 
void Brood::BroodUI::TextBox::DeleteLastChar()
{
	std::string tempStr = m_ossText.str();
	std::string newStr = "";

	// copying the string except the last char
	for( unsigned i = 0; i < tempStr.length() - 1; ++i )
	{
		newStr += tempStr[ i ];
	}

	// clearing the stringstream and copying the data
	m_ossText.str( "" );
	m_ossText << newStr;

	m_text.setString( m_ossText.str() );
}