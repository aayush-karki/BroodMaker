/*************************************************************************/
/// 
/// @file DropDownMenu.h 
/// 
/// @brief  This file is a source file for DropDownMenu class.
/// 
/// It contains all of the defination of the member 
///		funciton of DropDownMenu class.
///
/************************************************************************/

#include "stdafx.h"
#include "DropDownMenu.h"

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the DropDownMenu object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::DropDownMenu::DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr) :
	Brood::BroodUI::Button( a_parentPtr, Brood::BroodUI::ENUM_UIType::UI_dropDownMenu),
	m_font( nullptr )
{}

///
/// @public
/// @brief Default Destructor
/// 
Brood::BroodUI::DropDownMenu::~DropDownMenu()
{
	// deleting the menus 
	if( !m_items.empty() )
	{
		for( int i = 0; i < m_items.size(); ++i )
		{
			delete m_items.at( i );
		}
	}
	
}

///
/// @public
/// @brief Getter funciton to get the item List
/// 
/// @return reference to the item list
/// 
std::vector<Brood::BroodUI::TextBox*>& Brood::BroodUI::DropDownMenu::GetItemList()
{
	return m_items;
}

/// 
/// @public
/// @brief Setter function to set the size of each item in the drop down menus
/// 
/// @param a_eachItemSize length and height of each item in the menu -> sf::vector2f
/// 
void Brood::BroodUI::DropDownMenu::SetEachItemSize( sf::Vector2f a_eachItemSize )
{
	m_eachItemSize = a_eachItemSize;

	Brood::BroodUI::Button::SetBodySize( a_eachItemSize );

	// resizing the itemes
	if( !m_items.empty() )
	{
		// resizing and postioning all items according 
		// to the new menu size
		for( int i = 0; i < m_items.size(); ++i )
		{
			m_items.at( i )->SetBodySize( a_eachItemSize );
			SetItemPos( i );
		}
	}
}

/// 
/// @public
/// @brief Setter function to set the size of each item in the drop down menus
/// 
/// @param a_itemSizeX length of each item
/// @param a_itemSizeY height of each item
/// 
void Brood::BroodUI::DropDownMenu::SetEachItemSize( float a_itemSizeX, float a_itemSizeY )
{
	Brood::BroodUI::DropDownMenu::SetEachItemSize( sf::Vector2f( a_itemSizeX, a_itemSizeY ) );
}

/// 
/// @public
/// @brief Setter function to set the DropDownMenu's item Size
/// 
/// @param a_size size of the DropDownMenu's item 
/// 
void Brood::BroodUI::DropDownMenu::SetBodySize( sf::Vector2f a_size )
{
	Brood::BroodUI::DropDownMenu::SetEachItemSize( a_size );
}

/// 
/// @public
/// @overload
/// @brief Setter function to set the DropDownMenu's item Size
/// 
/// @param a_sizeX length of the DropDownMenu's item 
/// @param a_sizeY width of the DropDownMenu's item 
/// 
void Brood::BroodUI::DropDownMenu::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::DropDownMenu::SetEachItemSize( sf::Vector2f( a_sizeX, a_sizeY ) );
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
void Brood::BroodUI::DropDownMenu::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	Brood::BroodUI::Button::SetBodyPosition( a_pos, a_relativeToParent );

	// positining the itemes
	if( !m_items.empty() )
	{
		// postion all items according to the new menu position
		for( int i = 0; i < m_items.size(); ++i )
		{
			SetItemPos( i );
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
void Brood::BroodUI::DropDownMenu::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::DropDownMenu::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Setter function to set the font for the menu
/// 
/// @param a_font pointer to a loaded font
/// 
void Brood::BroodUI::DropDownMenu::SetFont( sf::Font* a_font )
{
	m_font = a_font;
	Brood::BroodUI::Button::SetFont( *a_font );

	// setting fonts of all the menu in the dropdown
	// positining the itemes
	if( !m_items.empty() )
	{
		// postion all items according to the new menu position
		for( int i = 0; i < m_items.size(); ++i )
		{
			m_items.at( i )->SetFont(*m_font);
		}
	}
}

/// 
/// @public
/// @brief Function to add menu item to the dropdown menu
///
/// It dynamically allocates memory for the item
/// 
/// @param a_menuName name of the item
/// @param a_color font color -> default sf::Color::White
/// 
void Brood::BroodUI::DropDownMenu::AddItemToMenu( std::string a_menuName, sf::Color a_color )
{
	// create a textbox and add it to the itemList
	Brood::BroodUI::TextBox* item = new Brood::BroodUI::TextBox;
	m_items.push_back( item );

	// setting up the item
	item->SetBodySize( m_eachItemSize );
	SetItemPos( m_items.size() - 1 );
	item->SetBodyColor( GetBodyColor() );
	item->SetFont( *m_font );
	item->SetFontColor( a_color );
	item->SetText( a_menuName );

	// setting up the id
	// adding the item as child of the dropDown
	GetElementIdPtr()->AddChild( item->GetElementIdPtr() );
	// adding the dropdown as parent of the item
	item->GetElementIdPtr()->SetParent( GetElementIdPtr());
}

/// 
/// @public
/// @brief Draw function 
/// 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::DropDownMenu::Draw( sf::RenderWindow& a_window )
{
	// drawing the menu identifier
	Brood::BroodUI::Button::Draw( a_window );

	if( IsSelected() )
	{
		// draw its items
		if( !m_items.empty() )
		{
			for( int i = 0; i < m_items.size(); ++i )
			{
				m_items.at( i )->Draw( a_window );
			}
		}
	}
}

/// 
/// @private
/// @brief helper funciton to position the items correctly in the drop down list
///
/// @param a_itemIndex index of the item in the drop down list
/// 
void Brood::BroodUI::DropDownMenu::SetItemPos( int a_itemIndex )
{
	// calculating the items positon, 
	// it is index + 1 as the menu's title itself occupies the first slot
	float itemPosX = GetBodyPosition().x;
	float itemPosY = GetBodyPosition().y + ( (a_itemIndex + 1) * m_eachItemSize.y );

	m_items.at( a_itemIndex )->SetBodyPosition( itemPosX, itemPosY );
}

