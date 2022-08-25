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
	m_isEditable( false ), m_hasLimit( false ), m_limit( -1 )
{}

///
/// @public
/// @brief default destructor
/// 
Brood::BroodUI::TextBox::~TextBox()
{}

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
/// @brief setter function to set the text that is displayed in the button
/// 
/// @warning It assumes that the font for the text is already set
/// 
/// @param a_text text to show on the buttom -> default empty string
/// 
void Brood::BroodUI::TextBox::SetText( std::string a_text )
{
	Brood::BroodUI::UIElement::SetText( a_text );

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
	SetSelected( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() );

	return doElement;
}

/// 
/// @private
/// @brief logic of what happens when different keys are pressed
///
/// @reparam charTyped ascii number that represent the char
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
	
	SetText (m_ossText.str() + "_" );
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