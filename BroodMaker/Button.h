/*************************************************************************/
/// 
/// @file Button.h 
/// 
/// @brief  This file is a header file for Button class 
///		which is in Button namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of Button class.
///
/************************************************************************/

#pragma once
#include "UIElement.h"
#include "TextBox.h"
#include "MouseHandler.h"
#include "UtilityFunctions.h"

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
/// A class derived from TextBox class.
/// 
/// ### Example Case
/// @code {.cpp}
/// 
/// // creating a textbox object
/// Brood::BroodUI::Button myButton;
/// myButton.SetBodySize( 100, 50 );
/// myButton.SetBodyPosition( 55, 0 );
/// myButton.SetFont( font );
/// myButton.SetBodyColor( sf::Color::Red );
/// myButton.SetText( "-----" );
/// 
/// 
/// // ============ in the main loop ===============
/// 
/// myButton.DoElement();
/// 
/// // drawing the element
/// myButton.Draw( window );
/// 
/// @endcode
///
class Brood::BroodUI::Button : public Brood::BroodUI::TextBox
{
	// ============ public member function =============== 
public:

	// default constructor
	Button( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
			Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_button);
	// default destructor
	virtual ~Button(); 

	// setter function
	void SetSpriteLength( float a_spriteLength );
	void SetSpriteHeight( float a_spriteHwight );

	bool SetTextureFromFilePath( std::string a_texturePath );
	bool SetTextureFromSavedFilePath();
	
	// overrided funciton 
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton


	// ================ private member function ==============
private:

	void SetSpriteFromTexture( unsigned a_num ); // setter

	// ============ private member variables =============== 
private:
	bool m_drawText; // is true if text is set

	std::string m_texturePath;
	sf::Texture m_texture; // reference to the a the texture opened from the path
	float m_spriteLength; 
	float m_spriteHeight;
};
