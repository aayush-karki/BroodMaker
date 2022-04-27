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
class Brood::BroodUI::Button : public Brood::BroodUI::TextBox
{
	// ============ public member function =============== 
public:

	// default constructor
	Button( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1,
			Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_button);
	// default destructor
	virtual ~Button(); 

	// setter function
	void SetSpriteLength( float a_spriteLength );
	void SetSpriteHeight( float a_spriteHwight );


	bool SetTextureFromFilePath( std::string a_texturePath );
	bool SetTextureFromSavedFilePath();
	
	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element

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
