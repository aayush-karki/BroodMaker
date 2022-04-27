/*************************************************************************/
/// 
/// @file TextBox.h 
/// 
/// @brief  This file is a header file for TextBox class.
/// 
/// It contains all of the declaration of the member 
///		funciton of TextBox class.
///
/************************************************************************/
#pragma once

#include "UIElement.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class TextBox;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class TextBox  "TextBox.h"
/// @brief a uielemnt that represent the text in the UI
/// 
/// It can be set as mutable or immutable text.
/// 
/// A class derived from UI elements class.
/// 
class Brood::BroodUI::TextBox : public Brood::BroodUI::UIElement
{
	// ============== private defines ================= 
private:
	// defines for better code readibility
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

// ============ public member function =============== 
public:
	// default constructor
	TextBox( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1,
			 Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_textBox);
	// default destructor
	virtual ~TextBox();

	std::string GetText(); // getter function to get the text

	// setter fucnitons
	virtual  void SetBodySize( sf::Vector2f  a_size ) override;
	virtual void SetBodySize( float a_sizeX, float a_sizeY ) override;
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;

	void SetFont( sf::Font& a_font );
	void SetFontColor( sf::Color a_color = sf::Color::White );
	void SetFontSize( int a_charSize = 12 );
	void SetText( std::string a_text = ""); // sets text
	void SetLimit( bool a_hasLimit = false, int a_limit = 0 ); // to set the limit to number of character 
	void SetSelected( bool a_selected ); // sets active
	void SetEditable( bool a_isEditable ); // sets active


	void TypeOn( sf::Event a_input ); // called every time user enters a char

	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function =============== 
private:
	void SetTextPosition(); // to set the position of the text
	void InputLogic( int charTyped ); // all of the logic; called on every key press
	void DeleteLastChar(); // delete last char

	// ============ private member variables ===============
private:
	sf::Text m_text;
	std::ostringstream m_ossText;
	bool m_isEditable;
	bool m_isSelected;
	bool m_hasLimit;
	int m_limit;
};
