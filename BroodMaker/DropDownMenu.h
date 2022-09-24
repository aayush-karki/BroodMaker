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
/// // @see Brood::BroodUI::Textbox::SetFontSize() for more information
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
///						std::cout << "item at " << i << " Pressed" << std::endl;
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
class Brood::BroodUI::DropDownMenu : public Brood::BroodUI::Button
{
	// ============ public member function =============== 
public:
	// default constructor
	DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
				  Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_dropDownMenu );
	// default destructor
	virtual ~DropDownMenu();

	// copy constructor
	DropDownMenu( const DropDownMenu& a_otherElement );

	// assignment operator
	Brood::BroodUI::DropDownMenu& operator=( const DropDownMenu& a_otherElement );

	// getter funciton
	std::vector<Brood::BroodUI::Button*>& GetItemList();

	// ======== setter function =======

	// sets text of the title menu
	void SetText( std::string a_text = "" );

	// sets body size
	void SetBodySize( sf::Vector2f a_eachItemSize ) override;

	// sets body size
	void SetBodySize( float a_itemSizeX, float a_itemSizeY ) override;

	// sets body position
	void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false ) override;

	// sets body position
	void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false ) override;

	// sets font for the menus
	void SetFont( sf::Font* a_font );

	// sets fonts size
	void SetFontSize( unsigned a_fontSize = 12 );

	// adds item to menu
	virtual void AddItemToMenu( std::string a_menuName,
						sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White );

	// adds the passed button to dropdown menu if a_createNew is true
	// then create a new button using the passed item then adds 
	// the new button 
	virtual void AddItemToMenu( Brood::BroodUI::Button* a_buttonPtrToAdd,
						bool a_createNew = true );

	// overrided funciton 

	// checks to see if the logic for the element is to 
	// be excecuted or not 
	virtual bool DoElement() override;

	// draw funciton
	virtual void Draw( sf::RenderWindow& a_window ) override;

	// adds the element ID to the text
	virtual void Debugger();

	// ============ protected member function ===============
protected:

	// ====== helper funcitons ========

	// position menu item at given index correctly
	void SetItemPos( int a_itemIndex );

	// size the menu item at given index correctly
	void SetItemSize( int a_itemIndex );

	// size all the menu item correctly
	void SetEachItemSize();

	// position all the menu item correctly
	void SetEachItemPos();

	// ============ protected member variables ===============
protected:

	/// stores the list of menus
	std::vector<Brood::BroodUI::Button*> m_items;

	/// holds the length of the longest menu item
	size_t m_maxItemLength;
};

// ======================================================================
// ================= end of DropDownMenu class ==========================
// ======================================================================