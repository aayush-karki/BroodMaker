/*************************************************************************/
/// 
/// @file TextBox.h 
/// 
/// @brief This file is a header file for TextBox class whicih is
///		in BroodUI namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of TextBox class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "UIElement.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class TextBox;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of TextBox class =============================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class TextBox  "TextBox.h"
/// @brief a uielemnt that represent the text in the UI
/// 
/// @details A class derived from UI elements class.
///		It can be set as mutable or immutable text.
/// @warning The following code needs to be present in the event switch 
///		for the textbox to be editable:
///		@code
///		
///		case sf::Event::TextEntered:
///		{
///			if( Brood::BroodUI::ElementSelection::GetCurrActiveElement() == nullptr )
///			{
///				break;
///			}
///		
///			// checking if the current active element is a editable textbox
///			int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID();
///			Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
///			if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_textBox )
///			{
///				// checking if it is editable or not
///				Brood::BroodUI::TextBox* currActiveTextBox = ( Brood::BroodUI::TextBox* )currActiveElement;
///				if( currActiveTextBox->IsEditable() )
///				{
///					// if yes then sent the textEntered event to the element
///					currActiveTextBox->TypeOn( events );
///				}
///			}
///			break;
///		}
///		
///		@endcode
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
/// // creating a textbox object
/// myTextBox.SetBodySize( 100, 50 );
/// myTextBox.SetBodyPosition( 160, 350 );
/// myTextBox.SetBodyColor( sf::Color::White );
/// myTextBox.SetFont( font );
/// myTextBox.SetFontSize( 25 );
/// myTextBox.SetFontColor( sf::Color::Black );
/// myTextBox.SetText( "hello is this god" );
/// myTextBox.SetEditable( true );
/// myTextBox.SetLimit( true, 4 );
/// 
/// //app loop
/// while( !exit )
/// {
/// 	// events
/// 	while( window.pollEvent( events ) )
/// 	{
/// 		switch( events.type )
///			{
///				// other events
///				// == in the even polling loop ==
///				case sf::Event::TextEntered:
///				{
///					if( Brood::BroodUI::ElementSelection::GetCurrActiveElement() == nullptr )
///					{
///						break;
///					}
///				
///					// checking if the current active element is a editable textbox
///					int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID();
///					Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
///					if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_textBox )
///					{
///						// checking if it is editable or not
///						Brood::BroodUI::TextBox* currActiveTextBox = ( Brood::BroodUI::TextBox* )currActiveElement;
///						if( currActiveTextBox->IsEditable() )
///						{
///							// if yes then sent the textEntered event to the element
///							currActiveTextBox->TypeOn( events );
///						}
///					}
///					break;
///				}
///			}
///		}
///
///		// logics
///		myTextBox.DoElement();
///		
///		// render
///		myTextBox.Draw( window );
/// }
/// 
/// @endcode
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
	TextBox( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
			 Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_textBox);
	// default destructor
	virtual ~TextBox();

	// getter funcitons
	std::string GetText() const; 
	unsigned int GetFontSize() const;
	const bool IsEditable() const;
	const bool IsSelected() const;

	// setter fucnitons
	virtual  void SetBodySize( sf::Vector2f  a_size ) override; // sets body size
	virtual void SetBodySize( float a_sizeX, float a_sizeY ) override; // sets body size
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override; // sets body position
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override; // sets body position

	void SetFont( sf::Font& a_font ); // sets font
	void SetFontColor( sf::Color a_color = sf::Color::White ); // sets font color
	void SetFontSize( int a_fontSize = 12 ); // sets font size
	void SetText( std::string a_text = ""); // sets text
	void SetLimit( bool a_hasLimit = false, int a_limit = 0 ); // to set the limit to number of character 
	void SetSelected( bool a_selected ); // sets the state of the element.
	void SetEditable( bool a_isEditable ); // sets if the textbox is editable or not

	void TypeOn( sf::Event a_input ); // called every time user enters a char

	virtual bool DoElement() override; // checks to see if the logic for the element is to be excecuted or not 
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function =============== 
private:
	void SetTextPosition(); // to set the position of the text
	void InputLogic( int charTyped ); // all of the logic; called on every key press
	void DeleteLastChar(); // delete last char

	// ============ private member variables ===============
private:
	sf::Text m_text; ///> text content
	std::ostringstream m_ossText; ///> text buffer
	bool m_isEditable; ///> is true if the element's text is editable
	bool m_isSelected; ///> is true if the element is selected
	bool m_hasLimit; ///> is true if the element has number of character limit
	int m_limit; ///> max number of character
	unsigned m_fontSize; ///> font size
};

// ======================================================================
// ================= end of TextBox class ===============================
// ======================================================================