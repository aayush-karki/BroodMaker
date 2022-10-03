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
/// @brief Copy constructor
/// 
/// @param a_otherElement reference to the uiElement which is used to 
///		copy the data form 
/// 
Brood::BroodUI::Button::Button( const Brood::BroodUI::Button& a_otherElement ) :
	UIElement( a_otherElement ), m_bodySprite( a_otherElement.m_bodySprite )
{}

/// 
/// @brief assignment operator
/// 
/// @param a_otherButton reference to the button which is used to 
///		copy the data form 
/// 
/// @return pointer to this element
///
Brood::BroodUI::Button& Brood::BroodUI::Button::operator=( const Brood::BroodUI::Button& a_otherButton )
{
	// chekcing for self assignment
	if( this == &a_otherButton )
	{
		return *this;
	}

	// calling the assignment operator of the UIElement
	Brood::BroodUI::UIElement::operator=(a_otherButton);

	this->m_bodySprite = a_otherButton.m_bodySprite;

	return *this;
}


/// 
/// @public
/// @static
/// @overlaoded
/// @brief helper function to dynamically create a button element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the button element
/// @param a_pos  postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default
///		 Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
/// 
Brood::BroodUI::Button* Brood::BroodUI::Button::DyCreateButton( sf::Vector2f a_size, sf::Vector2f a_pos, std::string a_text, sf::Color a_color )
{
	Brood::BroodUI::Button* buttonElement = new Brood::BroodUI::Button;
	buttonElement->SetBodySize( a_size );
	buttonElement->SetBodyPosition( a_pos );
	buttonElement->SetFont( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_font );
	buttonElement->SetFontSize( 18 );
	buttonElement->SetBodyColor( a_color );
	buttonElement->SetText( a_text );

	return buttonElement;
}

/// 
/// @public
/// @static
/// @overlaoded
/// @brief helper function to dynamically create a button element 
///		initializes it, and adds it to m_unNameList
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the button element
/// @param a_sizeY width of the button element
/// @param a_posX x-postion of the button element
/// @param a_posY y-postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
///
Brood::BroodUI::Button* Brood::BroodUI::Button::DyCreateButton( float a_sizeX, float a_sizeY, float a_posX, float a_posY, std::string a_text, sf::Color a_color )
{
	return Brood::BroodUI::Button::DyCreateButton( { a_sizeX, a_sizeY }, { a_posX, a_posY },
												   a_text, a_color );
}


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
/// @brief setter function to set the state of the element i.e. if it is 
///		seleected or not
/// 
/// @note this is used to display the active overlay or not
/// 
/// @param a_selected true if current button is selected or not
/// 
void Brood::BroodUI::Button::SetSelected( bool a_selected )
{
	m_isSelected = a_selected;

	SetDrawOverlay();

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
/// @brief changes the text/texture of the element to its the element ID when debug is on
///		and changes it back to the text/texture it had before debugging when debug is off.
/// 
void Brood::BroodUI::Button::Debugger()
{
	m_bodySprite.Debugger();

	Brood::BroodUI::UIElement::Debugger();

}

// ======================================================================
// ================= end of button class ================================
// ======================================================================