/*************************************************************************/
/// 
/// @file Button.cpp
/// 
/// @brief  This file is a source file for Button class.
/// 
/// It contains all of the defination of the member 
///		funciton of Button class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Button.h"

// ======================================================================
// ================= start of button class ==============================
// ======================================================================

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
/// 
Brood::BroodUI::Button::Button( Brood::BroodUI::UIElement* a_parentPtr,
								Brood::BroodUI::ENUM_UIType a_enumType ) :
	Brood::BroodUI::TextBox( a_parentPtr, a_enumType ),
	m_drawText( false ), m_bodySprite( &m_body )
{
	SetEditable( false );
}

/// 
/// @public
/// @brief default destrctor
///
Brood::BroodUI::Button::~Button()
{}

///
/// @public
/// @brief Getter function to get the sprite body
/// 
/// Sprite body allows to manupulate the sprite/texture
/// 
/// @return reference to the spritebody object
Brood::SpriteHandler& Brood::BroodUI::Button::GetSpriteBody()
{
	return m_bodySprite;
}

/// 
/// @public
/// @brief Draw function 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::Button::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::TextBox::Draw( a_window );
}

// ======================================================================
// ================= end of button class ================================
// ======================================================================