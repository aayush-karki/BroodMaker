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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "Button.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class DropDownMenu;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DropDownMenu class ========================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class DropDownMenu  "DropDownMenu.h"
/// @brief A UI elemnt that represent a drop down menu. 
/// 
/// A class derived from Button class. 
///		It contains a list of menus inside a single element.
///		The list of items are left aligned and below the menu title.
///		the size of the items is depended on the longest item name.
///		
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
/// //app loop
/// while( !exit )
/// {
///		// event loop
///		
///		// logic 
/// 
///		// checking if the logics of the element is to be executed or not
///		myDropDown.DoElement();
///		
///		// checking its item if the dropdown menu was selcted
///		if( myDropDown.IsSelected() )
///		{
///			auto itemList = myDropDown.GetItemList();
///			// draw its items
///			// positining the itemes
///			if( !itemList.empty() )
///			{
///				// checking if the logics of the items is to be executed or not
///				for( int i = 0; i < itemList.size(); ++i )
///				{
///					if (itemList.at( i )->DoElement() ) 
///					{
///						// roll a dice
///					}
///				}
///			}
///		}
/// 
///		// rendering
///		myDropDown.Draw( window );
/// }
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
	std::vector<Brood::BroodUI::Button*>& GetItemList();

	// setter function
	void SetText( std::string a_text = "") ; // sets text of the title menu
	void SetBodySize( sf::Vector2f a_eachItemSize ) override; // sets body size
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override; // sets body size
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override; // sets body position
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override; // sets body position
	void SetFont( sf::Font* a_font ); // sets font for the menus
	void SetFontSize( int a_fontSize = 12 ); // sets fonts size

	void AddItemToMenu( std::string a_menuName, sf::Color a_color = sf::Color::White ); // adds item to menu

	// overrided funciton 
	//virtual bool DoElement() override;
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function ===============
private:
	void SetItemPos( int a_itemIndex ); // helper function position menu item at given index correctly
	void SetItemSize( int a_itemIndex ); // helper function size the menu item at given index correctly
	void SetEachItemSize(); // helper function size all the menu item correctly
	void SetEachItemPos(); // helper function position all the menu item correctly

	// ============ private member variables ===============
private:
	sf::Font* m_font; ///> pointer to the font

	std::vector<Brood::BroodUI::Button*> m_items; ///> stores the list of menus
	size_t m_maxItemLength; ///> holds the length of the longest menu item
};

// ======================================================================
// ================= end of DropDownMenu class ==========================
// ======================================================================