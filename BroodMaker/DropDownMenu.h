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

#include "UIElement.h"
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
/// @brief a uielemnt that represent drop down menu. Contains a list of
///		menus inside a single item
/// 
/// A class derived from Button class.
/// 
class Brood::BroodUI::DropDownMenu: public Brood::BroodUI::Button
{
	// ============ public member function =============== 
	// default constructor
	DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 );
	// default destructor
	virtual ~DropDownMenu();

	// setter function
	void SetEachItemSize( sf::Vector2f a_eachItemSize );
	void SetEachItemSize( float a_itemSizeX, float a_itemSizeY );
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;
	void SetFont( sf::Font* a_font );

	void AddItemToMenu( std::string a_menuName, sf::Color a_color = sf::Color::White );

	// overrided funciton 
	///@todo redefine these functions 
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element

	virtual void Draw( sf::RenderWindow& a_window ) override; // draw funciton

	// ============ private member function ===============
	void SetItemPos( int a_itemIndex );

	// ============ private member variables ===============
	std::vector<Brood::BroodUI::TextBox*> m_items; // stores the list of menus
	sf::Vector2f m_eachItemSize; // size of each item

	bool m_isSelected; // true if it is currActive
	sf::Font* m_font; // pointer to the font


};

