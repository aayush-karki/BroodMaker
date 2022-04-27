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
/// @todo: make this a derived from textBox
/// 
/// A class derived from UI elements class.
/// 
class Brood::BroodUI::Button : public Brood::BroodUI::UIElement
{
	// ============ public member function =============== 
public:

	// default constructor
	Button( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1,
			Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_button);
	virtual ~Button(); // destructor
	//getter function
	Brood::BroodUI::TextBox* GetTextBoxPtr();

	// setter funcitons
	virtual  void SetBodySize( sf::Vector2f  a_size ) override;
	virtual void SetBodySize( float a_sizeX, float a_sizeY ) override;
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;

	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member variables =============== 
private:
	bool m_drawText; // is true if text is set
	Brood::BroodUI::TextBox m_text;
};
