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
///			if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() == nullptr )
///			{
///				break;
///			}
///		
///			// checking if the current active element is a editable textbox
///			int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr()->GetElementID();
///			Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::MapIdToElement::GetElementPtrFromMap( currActiveElementId );
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
///					if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() == nullptr )
///					{
///						break;
///					}
///				
///					// checking if the current active element is a editable textbox
///					int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr()->GetElementID();
///					Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::MapIdToElement::GetElementPtrFromMap( currActiveElementId );
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
/// @todo add a way to add place holder text
/// @todo add view to the textbox feild that gets scrolled 
///		when the type text go of window
/// @todo adda actual cursor instead of _
/// @todo add a way to retrive the text when pressed enter
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

	// copy constructor
	TextBox( const TextBox& a_otherTextBox );

	// assignment operator
	Brood::BroodUI::TextBox& operator=( const TextBox& a_otherTextBox );

	// ====== getter funcitons ======

	// checks to see if the text box is editable or not 
	const bool IsEditable() const;

	// check to see if the text box is selected or not
	const bool IsSelected() const;

	// ====== setter funcitons ======

	// sets text
	void SetText( std::string a_text = "" ) override; 
	
	// sets the limit to number of character 
	void SetLimit( bool a_hasLimit = false, int a_limit = 0 ); 
	
	// sets the state of the element.
	void SetSelected( bool a_selected ); 
	
	// sets if the textbox is editable or not
	void SetEditable( bool a_isEditable ); 

	// called every time user enters a char
	void TypeOn( sf::Event a_input );

	// checks to see if the logic for the element is to 
	// be excecuted or not 
	virtual bool DoElement() override; 

	// ============ private member function =============== 
private:

	// all of the logic; called on every key press
	void InputLogic( int charTyped ); 

	// delete last char
	void DeleteLastChar(); 

	// ============ private member variables ===============
private:
	
	/// text buffer
	std::ostringstream m_ossText; 
	
	/// is true if the element's text is editable
	bool m_isEditable; 
	
	/// is true if the element has number of character limit
	bool m_hasLimit; 
	
	/// max number of character
	int m_limit; 
};

// ======================================================================
// ================= end of TextBox class ===============================
// ======================================================================