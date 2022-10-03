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

/// allocating space and initializing the m_enterPressed
bool Brood::BroodUI::TextBox::m_enterPressed = false;

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
								  Brood::BroodUI::ENUM_UIType a_enumType ) :
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
/// @brief Copy constructor
/// 
/// @param a_otherTextBox reference to the uiElement which is used to 
///		copy the data form 
/// 
Brood::BroodUI::TextBox::TextBox( const Brood::BroodUI::TextBox& a_otherTextBox ) :
	UIElement( a_otherTextBox ), m_isEditable( a_otherTextBox.m_isEditable ),
	m_hasLimit( a_otherTextBox.m_hasLimit ), m_limit( a_otherTextBox.m_limit )
{
	this->m_ossText.str( a_otherTextBox.m_ossText.str() );
}

/// 
/// @brief assignment operator
/// 
/// @param a_otherTextBox reference to the text box which is used to 
///		copy the data form 
/// 
/// @return pointer to this element
///
Brood::BroodUI::TextBox& Brood::BroodUI::TextBox::operator=( const Brood::BroodUI::TextBox& a_otherTextBox )
{
	// chekcing for self assignment
	if( this == &a_otherTextBox )
	{
		return *this;
	}

	// calling the assignment operator of the UIElement
	Brood::BroodUI::UIElement::operator=( a_otherTextBox );

	this->m_isEditable = a_otherTextBox.m_isEditable;
	this->m_hasLimit = a_otherTextBox.m_hasLimit;
	this->m_limit = a_otherTextBox.m_limit;
	this->m_enterPressed = a_otherTextBox.m_enterPressed;
	this->m_ossText.str( a_otherTextBox.m_ossText.str() );

	return *this;
}

/// 
/// @public
/// @static
/// @overlaoded
/// @brief helper function to dynamically create a textbox element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the textbox element
/// @param a_pos  postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; default 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///  
Brood::BroodUI::TextBox* Brood::BroodUI::TextBox::DyCreateTextBox( sf::Vector2f a_size, sf::Vector2f a_pos, std::string a_text, bool a_isEditable, std::string a_placeholderText, sf::Color a_color )
{
	Brood::BroodUI::TextBox* textBoxElement = new Brood::BroodUI::TextBox;
	textBoxElement->SetBodySize( a_size );
	textBoxElement->SetBodyPosition( a_pos );
	textBoxElement->SetFont( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_font );
	textBoxElement->SetFontSize( 18 );
	textBoxElement->SetBodyColor( a_color );
	textBoxElement->SetText( a_text );
	textBoxElement->SetEditable( a_isEditable );
	textBoxElement->SetPlaceHolderText( a_placeholderText );

	return textBoxElement;
}


/// 
/// @public
/// @static
/// @overlaoded
/// @brief helper function to dynamically create a textbox element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the textbox element
/// @param a_sizeY width of the textbox element
/// @param a_posX x-postion of the textbox element
/// @param a_posY y-postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; 
///		default Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///

Brood::BroodUI::TextBox* Brood::BroodUI::TextBox::DyCreateTextBox( float a_sizeX, float a_sizeY, float a_posX, float a_posY, std::string a_text, bool a_isEditable, std::string a_placeholderText, sf::Color a_color )
{
	return Brood::BroodUI::TextBox::DyCreateTextBox( { a_sizeX, a_sizeY }, { a_posX, a_posY },
														   a_text, a_isEditable, a_placeholderText, a_color );
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
/// @brief getter funciton to get if the element is curretly selected or not
/// 
/// @return true if it is currently selected; else false
/// 
const bool Brood::BroodUI::TextBox::IsSelected() const
{
	return m_isSelected;
}

/// 
/// @public
/// @brief getter funciton to get value stored in of enter button
/// 
/// @return value stored in of enter button
/// 
const bool Brood::BroodUI::TextBox::IsEnterPressed() const
{
	return m_enterPressed;
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
	else
	{
		SetText( m_ossText.str() ); // we need to use Text as it also sets m_drawText
		m_text.setString( m_ossText.str() + "_" ); // we do not want _ to save as input
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
/// @brief setter function to set enterPressed to false
/// 
void Brood::BroodUI::TextBox::SetEnterPressedFalse()
{
	m_enterPressed = false;
}

/// 
/// @public
/// @brief setter function to set enterPressed to false
/// 
void Brood::BroodUI::TextBox::SetPlaceHolderText( std::string a_placeHolderText )
{
	m_placeHolderText = a_placeHolderText;
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
				std::cout << m_ossText.str().length() << std::endl;
				if( m_ossText.str().length() >= m_limit && charTyped == DELETE_KEY )
				{
					DeleteLastChar();
				}
				else if( m_ossText.str().length() < m_limit )
				{
					InputLogic( charTyped );
				}
				std::cout << m_ossText.str().length() << std::endl << std::endl;
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

	// chekcing if this element is currActive and is not hot when 
	// left mouse button is not pressed
	if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() &&
		Brood::MouseHandler::IsLeftButtonPressed() &&
		GetElementIdPtr() != Brood::BroodUI::ElementSelection::GetHotElementIdPtr() )
	{
		// then this element should not be currActive
		Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( &m_elementId );
		Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );
	}

	// checking if the current active element is this element
	// if yes set the isSelected property to true 
	SetSelected( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() );

	return doElement;
}

///
/// @public
/// @virtual
/// @brief Draws the body to the render window
/// 
/// @param a_window reference to the render window
/// 
void Brood::BroodUI::TextBox::Draw( sf::RenderWindow& a_window )
{
	// drawing the textbox
	Brood::BroodUI::UIElement::Draw( a_window );

	// draw place holder text if the textbox is editable 
	// and textbox has no text 
	if( m_isEditable && m_textContent.empty() && !m_placeHolderText.empty() )
	{
		// saving it to restore the font color
		sf::Color currentFontColor = m_text.getFillColor();
		
		sf::Color placeHolderFontColor = currentFontColor;
		placeHolderFontColor.a = placeHolderFontColor.a / 2;
		SetFontColor( placeHolderFontColor );

		SetText(m_placeHolderText);
		a_window.draw( m_text );

		// restoring it back to how it used to be
		SetText( "" );
		SetFontColor( currentFontColor );
	}
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
	else if( charTyped == ENTER_KEY )
	{
		m_enterPressed = true;

		// then this element should not be currActive
		Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( &m_elementId );
		Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );
	}
	else if( charTyped == ESCAPE_KEY )
	{
		// then this element should not be currActive
		Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( &m_elementId );
		Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );

	}

	SetText( m_ossText.str() ); // we need to use Text as it also sets m_drawText
	m_text.setString( m_ossText.str() + "_" ); // we do not want _ to save as input
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

	SetText( m_ossText.str() );
}

// ======================================================================
// ================= end of TextBox class ===============================
// ======================================================================