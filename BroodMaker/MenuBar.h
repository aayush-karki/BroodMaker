
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
/// // making a MenuBar
/// Brood::BroodUI::MenuBar myMenu;
/// myMenu.SetBodySize( WINDOW_WIDTH, 30 );
/// myMenu.SetBodyPosition( 0, 0 );
/// myMenu.SetFont( &font );
/// myMenu.SetCharacterSize( 20 );
/// myMenu.SetBodyColor( sf::Color::Magenta );
/// 
/// myMenu.AddMenuToMenuBar( "hello w" );
/// myMenu.AddMenuToMenuBar( "b" );
/// myMenu.AddMenuToMenuBar( "c" );
/// 
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "aa" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ab" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ac" );
/// myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ad" );
/// 
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
	MenuBar( Brood::BroodUI::UIElement* a_parentPtr = nullptr);
	// default destructor
	virtual ~MenuBar();

	// getter funciton
	std::vector<Brood::BroodUI::DropDownMenu*>& GetMenuList(); // gets the menu list

	// setter function
	void SetBodySize( sf::Vector2f a_eachItemSize ) override; // sets the menu's body sizse
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override; // sets the menu's body sizse
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override; // sets the menu's body position
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override; // // sets the menu's body position
	void SetFont( sf::Font* a_font ); // sets the menu's font
	void SetFontSize( int a_fontSize ); // sets the font size

	void AddMenuToMenuBar( std::string a_menuName ); // adds menus to the menu bar
	void AddItemToMenu( unsigned a_index, std::string a_menuName); // adds item to a menu at given index

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function ===============
private:
	void SetMenuBodySize( int a_itemIndex ); // sets the menu's item size correctly
	void SetMenuPos( int a_itemIndex ); // sets the menu's item position correctly

private:
	// ============ private member variables ===============
	std::vector<Brood::BroodUI::DropDownMenu*> m_menus; ///> stores the list of drop down menus
	sf::Font* m_font; ///> pointer to the font
	unsigned m_fontSize; ///> font size
};

// ======================================================================
// ================= end of MenuBar class ===============================
// ======================================================================