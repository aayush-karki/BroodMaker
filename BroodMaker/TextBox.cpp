/*************************************************************************/
/// 
/// @file TextBox.cpp
/// 
/// @brief  This file is a source file for TextBox class.
/// 
/// It contains all of the defination of the member 
///		funciton of TextBox class.
///
/************************************************************************/

/// @TODO fix the limit bug

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "TextBox.h"

// ======================================================================
// ================= start of TextBox class =============================
// ======================================================================

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
/// 
Brood::BroodUI::TextBox::TextBox( Brood::BroodUI::UIElement* a_parentPtr,
								  Brood::BroodUI::ENUM_UIType a_enumType) :
	Brood::BroodUI::UIElement( a_enumType, a_parentPtr ),
	m_isEditable( false ), m_isSelected( false ), m_hasLimit( false ),
	m_limit( -1 ), m_fontSize( 0 )
{}

///
/// @public
/// @brief default destructor
/// 
Brood::BroodUI::TextBox::~TextBox()
{}

/// 
/// @public
/// @brief getter funciton to get the user typed text that is stored in the element
/// 
/// @return all the user typed text that is stored in the element
/// 
std::string Brood::BroodUI::TextBox::GetText() const
{
	return m_ossText.str();
}

/// 
/// @public
/// @brief getter funciton to get the font size
/// 
/// @return size of the font
/// 
unsigned int Brood::BroodUI::TextBox::GetFontSize() const
{
	return m_text.getCharacterSize();
}

/// 
/// @public
/// @brief getter funciton to get its editibility
/// 
/// @return true if the textbox is editable; else false
/// 
const bool Brood::BroodUI::TextBox::IsEditable() const
{
	return m_isEditable;
}

/// 
/// @public
/// @overload
/// @brief getter funciton to get if the element is curretly selected or not
/// 
/// @return true if it is currently selected; else false
/// 
const bool Brood::BroodUI::TextBox::IsSelected( ) const
{
	return m_isSelected;
}

/// 
/// @public
/// @brief Setter function to set the TextBox's Size
/// 
/// @warning The menu height should always be greater than font size by 2 px.
/// @param a_size size of the element
/// 
void Brood::BroodUI::TextBox::SetBodySize( sf::Vector2f a_size )
{
	//checking if the new height for the body is greater than the charsize by 2
	if( a_size.y >= m_fontSize + 2 )
	{
		// setting the bar body size
		Brood::BroodUI::UIElement::SetBodySize( a_size );
	}
	else if( a_size.y < m_fontSize )
	{
		std::cerr << "body height cannot be smaller than font Size cannot" << std::endl;
		return;
	}
	else
	{
		std::cerr << "body height needs to be 2 pixel bigger than font size" << std::endl;
		return;
	}
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
/// @brief setter function to set the font size
/// 
void Brood::BroodUI::TextBox::SetFont( sf::Font& a_font )
{
	m_text.setFont( a_font );
}

/// 
/// @public
/// @brief setter function to set the Font color
/// 
/// param a_color font color -> default sf::Color::White
/// 
void Brood::BroodUI::TextBox::SetFontColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// 
/// @public
/// @brief setter function to set the Font size
/// 
/// @note If the font size is more than body height by
/// 
/// @param a_charSize -> size of indivisual character in the SetEditabletext -> deafult 12
/// 
void Brood::BroodUI::TextBox::SetFontSize( int a_fontSize )
{
	float bodyHeight = GetBodySize().y;

	// checking menu bar height
	if( bodyHeight <= 2 )
	{
		std::cerr << "The body height is less than or equal to 2." << std::endl
			<< "Set the body height to more than 2 before setting the font size" << std::endl;
		return;
	}
	// checking if fontsize is greater than menu height - 2
	else if( a_fontSize > bodyHeight - 2 )
	{
		std::cerr << "Font size is more than the body height - 2." << std::endl
			<< "Setting the font size to current body height - 2" << std::endl
			<< "Setting the font size to " << bodyHeight - 2 << std::endl;
		m_fontSize = ( unsigned ) bodyHeight - 2;
	}
	else
	{
		m_fontSize = (unsigned) a_fontSize;
	}

	m_text.setCharacterSize( m_fontSize );
}

/// 
/// @brief setter function to set the text that is displayed in the button
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
	if( a_limit <= 0 )
	{
		std::cerr << "limit cannot be less than 1" << std::endl;
		return;
	}
	else if( a_hasLimit && a_limit > 0 )
	{
		m_hasLimit = a_hasLimit;
		m_limit = a_limit;
	}
}

/// 
/// @public
/// @brief setter function to set the state of the element i.e. if it is 
///		seleected or not
/// 
/// @param a_selected true if current text box is selected or not
/// 
void Brood::BroodUI::TextBox::SetSelected( bool a_selected )
{
	// if the element is not editable then do nothing
	if( m_elementType == Brood::BroodUI::ENUM_UIType::UI_textBox && !m_isEditable )
	{
		return;
	}

	// setting the state
	m_isSelected = a_selected;

	// if not selected then remove the text cursor i.e. "_"
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
/// @brief setter function to set if the element is edutable or not
/// 
/// @param a_isEditable true if text box is editable
/// 
void Brood::BroodUI::TextBox::SetEditable( bool a_isEditable )
{
	m_isEditable = a_isEditable;
}

/// 
/// @public
/// @brief Called when a character is typed a
/// 
/// @param a_input a copy of sf::Event::TextEntered
/// 
void Brood::BroodUI::TextBox::TypeOn( sf::Event a_input )
{
	if( m_isEditable && m_isSelected )
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
/// @brief checks if the logics of the element is to be executed or not
/// 
/// In the process updates the element selector --that is current active and hot 
///		element. It also set the overlay
/// 
/// @return true if the element's funciton is to be executed
/// 
bool Brood::BroodUI::TextBox::DoElement()
{
	bool doElement = Brood::BroodUI::UIElement::DoElement();

	// checking if the current active element is this element
	// if yes set the isSelected property to true 
	SetSelected( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() );

	return doElement;
}

/// 
/// @public
/// @brief Draw function 
/// 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::TextBox::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::UIElement::Draw( a_window );

	// draw the text only when the text is present
	if( m_text.getString() != "" )
	{
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

// ======================================================================
// ================= end of TextBox class ===============================
// ======================================================================