/*************************************************************************/
/// 
/// @file MenuBar.h 
/// 
/// @brief  This file is a source file for MenuBar class.
/// 
/// It contains all of the defination of the member 
///		funciton of MenuBar class.
///
/************************************************************************/

#include "stdafx.h"
#include "MenuBar.h"

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the MenuBar object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::MenuBar::MenuBar( Brood::BroodUI::UIElement* a_parentPtr ) :
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_menuBar, a_parentPtr),
	m_font( nullptr )
{}

///
/// @public
/// @brief Default Destructor
/// 
Brood::BroodUI::MenuBar::~MenuBar()
{
	// deleting the menus 
	if( !m_menus.empty() )
	{
		for( int i = 0; i < m_menus.size(); ++i )
		{
			delete m_menus.at( i );
		}
	}
}

///
/// @public
/// @brief Getter funciton to get the menu List
/// 
/// @return reference to the menu list
/// 
std::vector<Brood::BroodUI::DropDownMenu*>& Brood::BroodUI::MenuBar::GetMenuList()
{
	return m_menus;
}

/// 
/// @public
/// @brief Setter function to set the size of each menu in the menubar
/// 
/// @param a_eachMenuSize length and height of menu item in the menubar -> sf::vector2f
/// 
void Brood::BroodUI::MenuBar::SetEachMenuSize( sf::Vector2f a_eachMenuSize )
{
	m_eachMenuSize = a_eachMenuSize;

	Brood::BroodUI::UIElement::SetBodySize( a_eachMenuSize );

	// resizing the itemes
	if( !m_menus.empty() )
	{
		// resizing and postioning all items according 
		// to the new menu size
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->SetBodySize( a_eachMenuSize );
			SetMenuPos( i );
		}
	}
}

/// 
/// @public
/// @brief Setter function to set the size of each menu in the menubar
/// 
/// @param a_menuSizeX length of each menu in the menubar
/// @param a_menuSizeY height of each menu in the menubar
/// 
void Brood::BroodUI::MenuBar::SetEachMenuSize( float a_menuSizeX, float a_menuSizeY )
{
	Brood::BroodUI::MenuBar::SetEachMenuSize( sf::Vector2f( a_menuSizeX, a_menuSizeY ) );
}

/// 
/// @public
/// @brief Setter function to set the size of each menu in the MenuBar
/// 
/// @param a_size length and height of menu item in the menubar -> sf::vector2f
/// 
void Brood::BroodUI::MenuBar::SetBodySize( sf::Vector2f a_size )
{
	Brood::BroodUI::MenuBar::SetEachMenuSize( a_size );
}

/// 
/// @public
/// @overload
/// @brief Setter function to set the size of each menu in the MenuBar
/// 
/// @param a_itemSizeX length of each menu in the menubar
/// @param a_itemSizeY height of each menu in the menubar
/// 
void Brood::BroodUI::MenuBar::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::MenuBar::SetEachMenuSize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the Button's Position.
/// 
/// @param a_pos position of the element 
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
///  
void Brood::BroodUI::MenuBar::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( a_pos, a_relativeToParent );

	// positining the itemes
	if( !m_menus.empty() )
	{
		// postion all items according to the new menu position
		for( int i = 0; i < m_menus.size(); ++i )
		{
			SetMenuPos( i );
		}
	}
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the Button's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
void Brood::BroodUI::MenuBar::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::MenuBar::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Setter function to set the font for the menu
/// 
/// @param a_font pointer to a loaded font
/// 
void Brood::BroodUI::MenuBar::SetFont( sf::Font* a_font )
{
	m_font = a_font;
	// positining the itemes
	if( !m_menus.empty() )
	{
		// postion all items according to the new menu position
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->SetFont( m_font );
		}
	}
}

/// 
/// @public
/// @brief Function to add menu menu to the menubar
///
/// It dynamically allocates memory for the item
/// 
/// @param a_menuName name of the item
/// 
void Brood::BroodUI::MenuBar::AddMenuToMenuBar( std::string a_menuName)
{
	// create a DropDownMenu and add it to the itemList
	Brood::BroodUI::DropDownMenu* menu = new Brood::BroodUI::DropDownMenu;
	m_menus.push_back( menu );

	// setting up the menubar
	menu->SetBodySize( m_eachMenuSize );
	SetMenuPos( m_menus.size() - 1 );
	menu->SetFont( m_font );
	menu->SetBodyColor( GetBodyColor() );
	menu->SetText( a_menuName );

	// setting up the id
	// adding the item as child of the dropDown
	GetElementIdPtr()->AddChild( menu->GetElementIdPtr() );
	// adding the dropdown as parent of the item
	menu->GetElementIdPtr()->SetParent( GetElementIdPtr());
}

/// 
/// @public
/// @brief Draw function 
/// 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::MenuBar::Draw( sf::RenderWindow& a_window )
{
	// drawing the menu identifier
	Brood::BroodUI::UIElement::Draw( a_window );

	if( !m_menus.empty() )
	{
		// draw its menus
		// positining the itemes
		// postion all items according to the new menu position
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->Draw( a_window );
		}
	}
}

/// 
/// @private
/// @brief helper funciton to position the menus correctly in the drop down list
///
/// @param a_itemIndex index of the menu in the menu list
/// 
void Brood::BroodUI::MenuBar::SetMenuPos( int a_itemIndex )
{
	// calculating the items positon, 
	// it is index + 1 as the menu's title itself occupies the first slot
	float itemPosX = GetBodyPosition().x + ( ( a_itemIndex ) * m_eachMenuSize.x );
	float itemPosY = GetBodyPosition().y;

	m_menus.at( a_itemIndex )->SetBodyPosition( itemPosX, itemPosY );
}

