/*************************************************************************/
/// 
/// @file Button.h 
/// 
/// @brief  This file is a header file for Button class 
///		which is in Button namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of Button class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Button class
///
/************************************************************************/

#pragma once

#include "UIElement.h"
#include "MouseHandler.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class Button;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class Button  "Button.h"
/// @brief a uielemnt to work as a Button.
/// 
/// A class derived from UI elements class.
/// 
class Brood::BroodUI::Button : public Brood::BroodUI::UIElement
{
	// ============ public member function =============== 
public:

	// default constructor
	Button( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 );

	// setter functions
	void SetFont( sf::Font& a_font ); // sets the font
	void SetTextColor( sf::Color a_color ); // set the text color
	void SetText( std::string a_text = "",
				  sf::Color a_color = sf::Color::White,
				  unsigned a_charSize = 12 ); // sets text

	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member funciton =============== 
private:
	void SetTextPosition(); // set the position of the text relatice to the element body

	// ============ private member variables =============== 
private:
	bool m_drawText; // is true if text is set
	sf::Text m_text; // text to show on the Brood::BroodUI::Button
};

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
inline Brood::BroodUI::Button::Button( Brood::BroodUI::UIElement* a_parentPtr, int a_index ) :
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_button,
							   a_parentPtr, a_index ), m_drawText( false )
{}

/// 
/// @public
/// @brief setter funciton to set the font size
/// 
inline void Brood::BroodUI::Button::SetFont( sf::Font& a_font )
{
	m_text.setFont( a_font );
}

/// 
/// @public
/// @brief setter funciton to set the text color
/// param a_color font color
/// 
inline void Brood::BroodUI::Button::SetTextColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// 
/// @public
/// @brief Draw function 
/// @param a_window reference to render window
/// 
inline void Brood::BroodUI::Button::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::UIElement::Draw( a_window );
	
	if( m_drawText )
	{
		a_window.draw( m_text );
	}
}

