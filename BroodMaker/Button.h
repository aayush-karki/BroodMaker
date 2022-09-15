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
#include "MouseHandler.h"
#include "UtilityFunctions.h"
#include "SpriteHandler.h"
#include "UIElement.h"

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
/// myButton.SetBodyColor( sf::Color::Red );
/// 
/// myButton.SetFont( font );
/// 
/// // if you want to set a text
/// myButton.SetText( "-----" );
/// 
/// // if you want to set a texture
/// myButton.GetSpriteBody().SetSpriteLength( 50 );
/// myButton.GetSpriteBody().SetSpriteHeight( 50 );
/// // loading the texture
/// myButton.GetSpriteBody().SetTextureFromFilePath( fileName );
/// myButton.GetSpriteBody().SetSpriteFromTexture( 0 );
/// 
/// //app loop
/// while( !exit )
/// {
///		// event loop
///		
///		// logic 
///		if (myButton.DoElement()) {
///			std::cout << "myButton Pressed" << std::endl;
///		}
///		
///		// render
///		myButton.Draw( window );
/// }
/// 
/// @endcode
///
class Brood::BroodUI::Button : public Brood::BroodUI::UIElement
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
	
	virtual bool DoElement() override; // checks to see if the logic for the element is to be excecuted or not 
	
	virtual void Debugger(); // adds the element ID to the text

	// ============ private member variables =============== 
private:
	Brood::SpriteHandler m_bodySprite; ///> object to set texture
};

// ======================================================================
// ================= end of button class ================================
// ======================================================================