
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
/// @class DropDownMenu  "DropDownMenu.h"
/// @brief It is a container that bundels DropDownmeus.
/// 
/// It bundles then horizontoally
/// 
/// A class derived from UIElement class.
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
	void SetEachMenuSize( sf::Vector2f a_eachItemSize );
	void SetEachMenuSize( float a_itemSizeX, float a_itemSizeY );
	void SetBodySize( sf::Vector2f a_eachItemSize );
	void SetBodySize( float a_itemSizeX, float a_itemSizeY );
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;
	void SetFont( sf::Font* a_font );

	void AddMenuToMenuBar( std::string a_menuName);


	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual const int  Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton


	// ============ private member function ===============
private:
	void SetMenuPos( int a_itemIndex );

	// ============ private member variables ===============
	std::vector<Brood::BroodUI::DropDownMenu*> m_menus; // stores the list of drop down menus
	sf::Vector2f m_eachMenuSize; // size of each item

	sf::Font* m_font; // pointer to the font
};