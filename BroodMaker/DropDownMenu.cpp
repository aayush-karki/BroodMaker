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
	m_font( nullptr ) , m_maxItemLength(0)
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

void Brood::BroodUI::DropDownMenu::SetText( std::string a_text )
{
	Brood::BroodUI::TextBox::SetText( a_text );

	// setting the max length
	if( m_maxItemLength < a_text.length() )
	{
		m_maxItemLength = a_text.length();
	}
}

/// 
/// @public
/// @brief Setter function to set the DropDownMenu's main item Size
/// 
/// @param a_size size of the DropDownMenu's item 
/// 
void Brood::BroodUI::DropDownMenu::SetBodySize( sf::Vector2f a_size )
{
	//checking if the new height for the bar body is smaller than the charsize
	if( a_size.y < GetFontSize() + 2 )
	{
		std::cerr << "Menu height needs to be 2 pixel bigger than charSize" << std::endl;
		return;
	}
	else if( a_size.y < GetFontSize() )
	{
		std::cerr << "Menu height cannot be smaller than Character Size cannot" << std::endl;
		return;
	}

	// setting the bar body size
	Brood::BroodUI::Button::SetBodySize( a_size );

	// setting the size of the each of the menu item if present
	SetEachItemSize();
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
	Brood::BroodUI::DropDownMenu::SetBodySize( { a_sizeX, a_sizeY } );
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
/// @brief setter funciton to set the Font size of the menu title and its items
/// 
/// @param a_charSize -> size of indivisual character in the SetEditabletext -> deafult 12
/// 
void Brood::BroodUI::DropDownMenu::SetFontSize( int a_fontSize )
{
	// setting the menu title font size
	Brood::BroodUI::TextBox::SetFontSize( a_fontSize );

	// setting the font size for its item
	for( int i = 0; i < m_items.size(); ++i )
	{
		float itemSizeY = GetBodySize().y;

		m_items.at( i )->SetFontSize( a_fontSize );
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

	// checking if the length is bigger than max length
	if( a_menuName.length() > m_maxItemLength )
	{
		// saving the max item length and changing length of each of itemBody
		m_maxItemLength = a_menuName.length();
		SetEachItemSize();
		SetEachItemPos();
	}

	// setting up the item which is at the end of the list
	SetItemSize( m_items.size() - 1 );
	SetItemPos( m_items.size() - 1 );
	item->SetBodyColor( GetBodyColor() );
	item->SetFont( *m_font );
	item->SetFontSize( GetFontSize() );
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
/// @brief helper funciton to position the item at given index correctly in the drop down list.
/// 
/// @param a_itemIndex index of the item in the drop down list
/// 
void Brood::BroodUI::DropDownMenu::SetItemPos( int a_itemIndex )
{
	// calculating the items positon, 
	// it is index + 1 as the menu's title itself occupies the first slot
	float itemPosX = GetBodyPosition().x;
	float itemPosY = GetBodyPosition().y + GetBodySize().y * ( a_itemIndex + 1 ) ;

	m_items.at( a_itemIndex )->SetBodyPosition( itemPosX, itemPosY );
}

/// 
/// @private
/// @brief helper funciton to size the items correctly in the drop down list
///
/// @param a_itemIndex index of the item in the drop down list
///
void Brood::BroodUI::DropDownMenu::SetItemSize( int a_itemIndex )
{
	// checking that index is not out of bound
	if( a_itemIndex > m_items.size() - 1 )
	{
		std::cerr << "Index out of range of menu with title" << GetText() << std::endl;
		return;
	}

	float menuLength = 0.f;
	// checking the length of max length in the menu
	if( m_maxItemLength < 3 )
	{
		menuLength = GetFontSize() * ( float )m_maxItemLength * 2;
	}
	else if( m_maxItemLength < 8 )
	{
		menuLength = GetFontSize() * ( float )m_maxItemLength / 1.5f;
	}
	else
	{
		menuLength = GetFontSize() * ( float )m_maxItemLength / 2.f;
	}

	// checking if the menuLength is less than menu main's body length
	if( menuLength < GetBodySize().x )
	{
		menuLength = GetBodySize().x;
	}

	m_items.at( a_itemIndex )->SetBodySize( menuLength, GetBodySize().y );
}

/// 
/// @private
/// @brief Setter function to set the size of each item in the drop down menus
/// 
void Brood::BroodUI::DropDownMenu::SetEachItemSize( )
{
	if( !m_items.empty() )
	{
		float menuLength = 0.f;
		// checking the length of max length in the menu
		if( m_maxItemLength < 3 )
		{
			menuLength = GetFontSize() * ( float )m_maxItemLength * 2;
		}
		else if( m_maxItemLength < 8 )
		{
			menuLength = GetFontSize() * ( float )m_maxItemLength / 1.5f;
		}
		else
		{
			menuLength = GetFontSize() * ( float )m_maxItemLength / 2.f;
		}

		// checking if the menuLength is less than menu main's body length
		if( menuLength < GetBodySize().x )
		{
			menuLength = GetBodySize().x;
		}

		// resizing the items
		for( int i = 0; i < m_items.size(); ++i )
		{
			float itemSizeY = GetBodySize().y;

			m_items.at( i )->SetBodySize( menuLength, itemSizeY );
		}
	}
}

/// 
/// @private
/// @brief Setter function to set the postiong of each item in the drop down menus
/// 
void Brood::BroodUI::DropDownMenu::SetEachItemPos()
{
	for( int i = 0; i < m_items.size(); ++i )
	{
		SetItemPos( i );
	}
}
