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
	Brood::BroodUI::UIElement( a_enumType, a_parentPtr ), m_bodySprite( &m_body )
{}

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
/// @brief checks if the logics of the element is to be executed or not
/// 
/// It checks the mouse position and button state to determine if to execute the 
///		elements logic or not. It does this by manupulating the element selection class.
///		It also set the overlay
/// 
/// @return true if the element's funciton is to be executed; else false
///
bool Brood::BroodUI::Button::DoElement()
{
	bool doElement = Brood::BroodUI::UIElement::DoElement();

	/// @delete me
	if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() == GetElementIdPtr() )
	{
		std::cout << GetElementIdPtr()->GetElementID() << std::endl;
	}

	// for button it should not be currActiveELmenet 
	if( doElement )
	{
		Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );
		Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( GetElementIdPtr() );
		this->m_drawOverlay = false;
	}

	return doElement;
}

/// 
/// @public
/// @brief changes the text of the element to its the element ID
/// 
void Brood::BroodUI::Button::Debugger()
{
	m_bodySprite.RemoveTexture();

	Brood::BroodUI::UIElement::Debugger();

}

// ======================================================================
// ================= end of button class ================================
// ======================================================================