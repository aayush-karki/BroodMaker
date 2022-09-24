
/*************************************************************************/
/// 
/// @file MenuBar.h 
/// 
/// @brief  This file is a header file for MenuBar class.
/// 
/// It contains all of the declaration of the member 
///		funciton of MenuBar class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "DropDownMenu.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class MenuBar;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of MenuBar class =============================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class MenuBar  "MenuBar.h"
/// @brief A class that represents a menu bar.
/// 
/// It is a class derived from UIElement class. It acts a a container 
/// that bundels DropDownmeus horizontoally.
/// 
/// ### Example Case
/// @code
/// 
/// // window object
/// sf::RenderWindow window( sf::VideoMode( 500, 500 ), "BroodMaker" );
///
/// // event object 
/// sf::Event events;
/// 
/// // creating a MenuBar object
/// Brood::BroodUI::MenuBar myMenu;
/// 
/// // setting size and position
/// myMenu.SetBodySize( WINDOW_WIDTH, 30 );
/// myMenu.SetBodyPosition( 0, 0 );
/// 
/// // setting the font which is required to display the text
/// myMenu.SetFont( &font );
/// 
/// // setting the font size. It should be less than the body height by 2 units.
/// // @see Brood::BroodUI::UIElement::SetFontSize() for more information
/// myMenu.SetCharacterSize( 20 );
/// 
/// // setting body color
/// myMenu.SetBodyColor( sf::Color::Magenta );
/// 
/// // Adding 3 menu to the menubar 
/// // and setting the menu title to "hello w", "b", and "c 
/// myMenu.AddMenuToMenuBar( "hello w" );
/// myMenu.AddMenuToMenuBar( "b" );
/// myMenu.AddMenuToMenuBar( "c" );
/// 
/// // adding 4 items to the first menu of the menu bar
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "aa" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ab" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ac" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ad" );
/// 
/// // adding 4 items to the second menu of the menu bar
/// myMenu.GetMenuList().at( 1 )->AddItemToMenu( "ba" );
/// myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bb" );
/// myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bc" );
/// myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bd" );
/// 
/// //app loop
/// while( !exit )
/// {
///		// event loop
///		
///		// logic 
///		if( !myMenu.GetMenuList().empty() )
///		{
///			auto menus = myMenu.GetMenuList();
///		
///			for( int i = 0; i < menus.size(); ++i )
///			{
///				menus.at( i )->DoElement();
///				// checking if the logics of the element is to be executed or not
///				if( menus.at( i )->IsSelected() )
///				{
///					auto itemList = menus.at( i )->GetItemList();
///					if( !itemList.empty() )
///					{
///						for( int i = 0; i < itemList.size(); ++i )
///						{
///							if( itemList.at( i )->DoElement() )
///							{
///								std::cout << "menu at " << i << " Pressed" << std::endl;
///								std::cout << "item at " << j << " Pressed" << std::endl;
///							}
///						}
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
class Brood::BroodUI::MenuBar : public Brood::BroodUI::UIElement
{
	// ============ public member function =============== 
public:
	// default constructor
	MenuBar( Brood::BroodUI::UIElement* a_parentPtr = nullptr );

	// default destructor
	virtual ~MenuBar();

	// copy constructor
	MenuBar( const MenuBar& a_otherElement );

	// assignment operator
	Brood::BroodUI::MenuBar& operator=( const MenuBar& a_otherElement );

	// ======= getter funciton =======

	// gets the menu list
	std::vector<Brood::BroodUI::DropDownMenu*>& GetMenuList();

	// ======= setter funciton =======

	// sets the menu's body sizse
	void SetBodySize( sf::Vector2f a_eachItemSize ) override;

	// sets the menu's body sizse
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override;

	// sets the menu's body position
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;

	// // sets the menu's body position
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;

	// sets the menu's font
	void SetFont( sf::Font* a_font );

	// sets font color
	virtual void SetFontColor( sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White );

	// sets the font size
	void SetFontSize( unsigned a_fontSize );

	// sets element body color
	virtual void SetBodyColor( sf::Color a_bodyColor );

	// sets active overlay color
	virtual void SetActiveOverlayColor( sf::Color a_color );

	// sets hot overlay color
	virtual void SetHotOverlayColor( sf::Color a_color );

	// adds menus to the menu bar
	void AddMenuToMenuBar( std::string a_menuName );

	// adds the passed DropDownMenu at back of menubar 
	// if a_createNew is true then create a new DropDownMenu 
	// using the passed item then adds the new DropDownMenu 
	// to the menubar
	void AddMenuToMenuBar( Brood::BroodUI::DropDownMenu* a_dropdownMenuPtrToAdd,
						   bool a_createNew = true );

	// adds item to a menu at given index
	void AddItemToMenu( unsigned a_index, std::string a_menuName );

	// adds the passed button to dropdown menu at passed index
	// if a_createNew is true then create a new button using 
	// the passed item then adds the new button to the DropDownMenu
	void AddItemToMenu( unsigned a_index,
						Brood::BroodUI::Button* a_buttonPtrToAdd,
						bool a_createNew = true );

	// draw funciton
	virtual void Draw( sf::RenderWindow& a_window ) override;

	// adds the element ID to the text
	virtual void Debugger();

	// ============ private member function ===============
private:

	// sets the menu's item size correctly
	void SetMenuBodySize( int a_itemIndex );

	// sets the menu's item position correctly
	void SetMenuPos( int a_itemIndex );

private:
	// ============ private member variables ===============

	/// stores the list of drop down menus
	std::vector<Brood::BroodUI::DropDownMenu*> m_menus;
};

// ======================================================================
// ================= end of MenuBar class ===============================
// ======================================================================