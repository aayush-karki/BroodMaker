
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

#pragma once
#include "DropDownMenu.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class MenuBar;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class MenuBar  "MenuBar.h"
/// @brief A class that represents a menu bar.
/// 
/// It is a class derived from UIElement class. It acts a a container 
/// that bundels DropDownmeus horizontoally.
/// 
/// 
/// ### Example Case
/// 
/// @code
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
/// // in the main loop
/// if( !myMenu.GetMenuList().empty() )
/// {
/// 	auto menus = myMenu.GetMenuList();
/// 
/// 	for( int i = 0; i < menus.size(); ++i )
/// 	{
/// 		menus.at( i )->DoElement();
/// 		if( menus.at( i )->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
/// 		{
/// 			menus.at( i )->SetSelected( true );
/// 		}
/// 		else
/// 		{
/// 			menus.at( i )->SetSelected( false );
/// 		}
/// 		if( menus.at( i )->IsSelected() )
/// 		{
/// 			auto itemList = menus.at( i )->GetItemList();
/// 			if( !itemList.empty() )
/// 			{
/// 				for( int i = 0; i < itemList.size(); ++i )
/// 				{
/// 					if( itemList.at( i )->DoElement() )
/// 					{
/// 						//myBoard.PlayerRollAndMove();
/// 					}
/// 				}
/// 			}
/// 		}
/// 	}
/// }
/// 
/// // drawing the element 
/// myDropDown.Draw( window );
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
	std::vector<Brood::BroodUI::DropDownMenu*>& GetMenuList();

	// setter function
	void SetBodySize( sf::Vector2f a_eachItemSize ) override;
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override;
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;
	void SetFont( sf::Font* a_font );
	void SetFontSize( int a_fontSize );

	void AddMenuToMenuBar( std::string a_menuName );
	void AddItemToMenu( unsigned a_index, std::string a_menuName);

	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual const int  Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton


	// ============ private member function ===============
private:
	void SetMenuBodySize( int a_itemIndex );
	void SetMenuPos( int a_itemIndex );

private:
	// ============ private member variables ===============
	std::vector<Brood::BroodUI::DropDownMenu*> m_menus; // stores the list of drop down menus
	sf::Font* m_font; // pointer to the font
	unsigned m_fontSize; // also determines the height of the menu
};