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
/// @public
/// @brief Default Constructor
///	
/// Initializes the button object
/// 
/// @note by default it sets the text that is displayed on the button to empty string
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// 
Brood::BroodUI::Button::Button( Brood::BroodUI::UIElement* a_parentPtr, int a_index ) :
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_button,
							   a_parentPtr, a_index ), m_drawText( false )
{
	// adding the button as parent of the textbox
	m_text.GetElementIdPtr()->SetParent( GetElementIdPtr(), 0 );
	// adding the textBox as child of the button
	int textIndex = GetElementIdPtr()->AddChild( m_text.GetElementIdPtr());
	m_text.GetElementIdPtr()->SetParent( GetElementIdPtr(), textIndex );

	m_text.SetEditable( false );
}

Brood::BroodUI::Button::~Button()
{}


/// 
/// @public
/// @brief getter funciton 
///
/// @return pointer to the textBox
/// 
Brood::BroodUI::TextBox* Brood::BroodUI::Button::GetTextBoxPtr()
{
	return &m_text;
}

/// 
/// @public
/// @brief Setter function to set the button's Size
/// 
/// @param a_size size of the element
/// 
void Brood::BroodUI::Button::SetBodySize( sf::Vector2f a_size )
{
	Brood::BroodUI::UIElement::SetBodySize( a_size );
	m_text.SetBodySize( a_size );
}

/// 
/// @public
/// @overload
/// @brief Setter function to set the button's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
/// 
void Brood::BroodUI::Button::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::Button::SetBodySize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the Button's Position.
/// 
/// @param a_pos position of the element 
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
///  
void Brood::BroodUI::Button::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( a_pos, a_relativeToParent );
	m_text.SetBodyPosition( a_pos, a_relativeToParent );
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the Button's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
void Brood::BroodUI::Button::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::Button::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Draw function 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::Button::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( Brood::BroodUI::UIElement::m_body );
	m_text.Draw( a_window );

	// draw the over lay only if the overlay is turned on
	if( m_drawOverlay )
	{
		a_window.draw( Brood::BroodUI::UIElement::m_bodyOverLay );
	}
}
