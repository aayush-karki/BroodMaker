/*************************************************************************/
/// 
/// @file DropDownMenu.h 
/// 
/// @brief  This file is a header file for DropDownMenu class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DropDownMenu class.
///
/************************************************************************/

#pragma once
#include "Button.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class DropDownMenu;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class DropDownMenu  "DropDownMenu.h"
/// @brief A UI elemnt that represent a drop down menu. 
/// 
///	
/// @details A class derived from Button class. 
///		It contains a list of menus inside a single item
/// 
/// ### Example Case
/// @code {.cpp}
/// 
/// // creating a dropdown object
/// Brood::BroodUI::DropDownMenu myDropDown; 
/// 
/// // setting size and position
/// myDropDown.SetBodySize( 20, 50 );
/// myDropDown.SetBodyPosition( 265, 0 );
/// 
/// // setting the font which is required to display the text
/// myDropDown.SetFont( &font );
/// 
/// // setting the font size. It should be less than the body height by 2 units.
/// // @see Textbox::SetFontSize() for more information
/// myDropDown.SetFontSize( 20 );
/// 
/// // setting the menu title to "a"
/// myDropDown.SetText( "a" );
/// 
/// // setting body color
/// myDropDown.SetBodyColor( sf::Color::Green );
/// 
/// // adding 2 items to the menu
/// myDropDown.AddItemToMenu( "1st item" );
/// myDropDown.AddItemToMenu( "2st item" );
/// 
/// // ============ in the main loop ===============
/// 
/// // checking if the logics of the element is to be executed or not
/// myDropDown.DoElement();
/// 
/// // checking if the my DropDown was selected
/// if( myDropDown.GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
/// {
/// 	myDropDown.SetSelected( true );
/// }
/// else
/// {
/// 	myDropDown.SetSelected( false );
/// }
/// 
/// // checking its item if the dropdown menu was selcted
/// if( myDropDown.IsSelected() )
/// {
/// 	auto itemList = myDropDown.GetItemList();
/// 	// draw its items
/// 	// positining the itemes
/// 	if( !itemList.empty() )
/// 	{
/// 		for( int i = 0; i < itemList.size(); ++i )
/// 		{
/// 			itemList.at( i )->DoElement();
/// 		}
/// 	}
/// }
/// 
/// // drawing the element
/// myDropDown.Draw( window );
/// 
/// @endcode
/// 
class Brood::BroodUI::DropDownMenu: public Brood::BroodUI::Button
{
	// ============ public member function =============== 
public:
	// default constructor
	DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr = nullptr);
	// default destructor
	virtual ~DropDownMenu();

	// getter funciton
	std::vector<Brood::BroodUI::TextBox*>& GetItemList();

	// setter function
	void SetText( std::string a_text = "") ;
	void SetBodySize( sf::Vector2f a_eachItemSize ) override;
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override;
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;
	void SetFont( sf::Font* a_font );

	void AddItemToMenu( std::string a_menuName, sf::Color a_color = sf::Color::White );

	// overrided funciton 
	//virtual bool DoElement() override;
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function ===============
private:
	void SetItemPos( int a_itemIndex );
	void SetItemSize( int a_itemIndex );
	void SetEachItemSize( );

	// ============ private member variables ===============
private:
	sf::Font* m_font; // pointer to the font

	std::vector<Brood::BroodUI::TextBox*> m_items; // stores the list of menus
	size_t m_maxItemLength; // holds the length of the longest menu item
};

