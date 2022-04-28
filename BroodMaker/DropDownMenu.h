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
/// @brief a uielemnt that represent drop down menu. Contains a list of
///		menus inside a single item
/// 
/// A class derived from Button class.
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
	void SetEachItemSize( sf::Vector2f a_eachItemSize );
	void SetEachItemSize( float a_itemSizeX, float a_itemSizeY );
	void SetBodySize( sf::Vector2f a_eachItemSize );
	void SetBodySize( float a_itemSizeX, float a_itemSizeY );
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

	// ============ private member variables ===============
private:
	sf::Font* m_font; // pointer to the font

	std::vector<Brood::BroodUI::TextBox*> m_items; // stores the list of menus
	sf::Vector2f m_eachItemSize; // size of each item
};

