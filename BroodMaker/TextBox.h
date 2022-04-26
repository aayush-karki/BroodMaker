/*************************************************************************/
/// 
/// @file TextBox.h 
/// 
/// @brief  This file is a header file for TextBox class.
/// 
/// It contains all of the declaration of the member 
///		funciton of TextBox class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of TextBox class
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
	TextBox( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 );
	//TextBox( int a_size = 15, sf::Color a_color = sf::Color::White, bool a_selected = false);

	// setter fucnitons 
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;
	void SetFont( sf::Font& a_font );
	void SetFontColor( sf::Color a_color = sf::Color::White );
	void SetFontSize( int a_charSize = 12 );
	void SetText( std::string a_text = ""); // sets text
	void SetLimit( bool a_hasLimit = false, int a_limit = 0 ); // to set the limit to number of character 
	void SetSelected( bool a_selected ); // sets active
	void SetEditable( bool a_isEditable ); // sets active


	std::string GetText(); // getter function to get the text
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

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the textBox object
/// 
/// It alse sets the default value of isEditable, isSelected, 
///		and hasLimit to false.
/// It sets the limit to -1.
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// 
inline Brood::BroodUI::TextBox::TextBox( Brood::BroodUI::UIElement* a_parentPtr, int a_index ) :
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_textBox,
							   a_parentPtr, a_index ), 
	m_isEditable( false ), m_isSelected( false ), m_hasLimit( false ), 
	m_limit( -1 )
{}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the textbox's Position.
/// 
/// @param a_pos position of the element 
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
///  
inline void Brood::BroodUI::TextBox::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( a_pos, a_relativeToParent );
	SetTextPosition();
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the textbox's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
inline void Brood::BroodUI::TextBox::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::TextBox::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Draw function 
/// @param a_window reference to render window
/// 
inline void Brood::BroodUI::TextBox::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::UIElement::Draw( a_window );
	a_window.draw( m_text );
}

/// 
/// @public
/// @brief getter funciton to get the typed text
/// 
/// @return text that user typed
/// 
inline std::string Brood::BroodUI::TextBox::TextBox::GetText()
{
	return m_ossText.str();
}

/// 
/// @public
/// @brief setter funciton to set the font size
/// 
inline void Brood::BroodUI::TextBox::SetFont( sf::Font& a_font )
{
	m_text.setFont( a_font );
}

/// 
/// @public
/// @brief setter funciton to set the Font color
/// 
/// param a_color font color -> default sf::Color::White
/// 
inline void Brood::BroodUI::TextBox::SetFontColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// 
/// @public
/// @brief setter funciton to set the Font Color
/// 
/// @param a_charSize -> size of indivisual character in the text -> deafult 12
/// 
inline void Brood::BroodUI::TextBox::SetFontSize( int a_charSize )
{
	m_text.setCharacterSize( a_charSize );
}

/// 
/// @public
/// @brief setter function
/// 
/// @param a_isEditable true if text box is editable
/// 
inline void Brood::BroodUI::TextBox::SetEditable( bool a_isEditable )
{
	m_isEditable = a_isEditable;
}
