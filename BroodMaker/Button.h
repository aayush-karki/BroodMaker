/*************************************************************************/
/// 
/// @file Button.h 
/// 
/// @brief  This file is a header file for Button class 
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of Button class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "TextBox.h"
#include "MouseHandler.h"
#include "UtilityFunctions.h"
#include "SpriteHandler.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class Button;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of button class ==============================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class Button  "Button.h"
/// @brief a uielemnt to work as a Button.
/// 
/// A class derived from TextBox class.
/// 
/// ### Example Case
/// @code {.cpp}
/// 
/// // window object
/// sf::RenderWindow window( sf::VideoMode( 500, 500 ), "BroodMaker" );
///
/// // event object 
/// sf::Event events;
/// 
/// // creating a Button object
/// Brood::BroodUI::Button myButton;
/// myButton.SetBodySize( 100, 50 );
/// myButton.SetBodyPosition( 55, 0 );
/// myButton.SetFont( font );
/// myButton.SetBodyColor( sf::Color::Red );
/// myButton.SetText( "-----" );
/// 
/// //app loop
/// while( !exit )
/// {
///		// event loop
///		
///		// logic 
///		myButton.DoElement();
///		
///		// render
///		myButton.Draw( window );
/// }
/// 
/// @endcode
///
class Brood::BroodUI::Button : public Brood::BroodUI::TextBox
{
	/// @todo see if it is better to make button derived from button or from text box

	// ============ public member function =============== 
public:

	// default constructor
	Button( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
			Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_button);
	// default destructor
	virtual ~Button(); 

	// Getter funciton 
	Brood::SpriteHandler& GetSpriteBody(); // gets the sprite body
	
	// overrided funciton 
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member variables =============== 
private:
	bool m_drawText; ///> is true if text is set and hence draw to screen

	Brood::SpriteHandler m_bodySprite; ///> object to set texture
};

// ======================================================================
// ================= end of button class ================================
// ======================================================================