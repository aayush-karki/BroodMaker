/*************************************************************************/
/// 
/// @file DropDownMenu.cpp 
/// 
/// @brief  This file is a source file for DropDownMenu class.
/// 
/// It contains all of the defination of the member 
///		funciton of DropDownMenu class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "DropDownMenu.h"

// ======================================================================
// ================= start of DropDownMenu class ========================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the DropDownMenu object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::DropDownMenu::DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr,
											Brood::BroodUI::ENUM_UIType a_enumType ) :
	Brood::BroodUI::Button( a_parentPtr, a_enumType ),
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
std::vector<Brood::BroodUI::Button*>& Brood::BroodUI::DropDownMenu::GetItemList()
{
	return m_items;
}

/// 
/// @public
/// @brief Setter function to set the text for DropDownMenu 
///
/// @param a_text text to set the text for DropDownMenu
/// 
void Brood::BroodUI::DropDownMenu::SetText( std::string a_text )
{
	Brood::BroodUI::UIElement::SetText( a_text );

	// setting the max length
	if( m_maxItemLength < a_text.length() )
	{
		m_maxItemLength = a_text.length();
	}
}

/// 
/// @public
/// @brief Setter function to set the DropDownMenu's Size
/// 
/// @param a_size size of the DropDownMenu 
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
/// @brief Setter function to set the DropDownMenu's size
/// 
/// @param a_sizeX length of the DropDownMenu 
/// @param a_sizeY width of the DropDownMenu
/// 
void Brood::BroodUI::DropDownMenu::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::DropDownMenu::SetBodySize( { a_sizeX, a_sizeY } );
}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the DropDownMenu's Position.
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
/// @brief Setter function to set the DropDownMenu's Position
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
	Brood::BroodUI::UIElement::SetFontSize( a_fontSize );

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
	Brood::BroodUI::Button* item = new Brood::BroodUI::Button;
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
/// @brief checks if the logics of the element is to be executed or not
/// 
/// It checks the mouse position and button state to determine if to execute the 
///		elements logic or not. It does this by manupulating the element selection class.
///		It also set the overlay
/// 
/// @return true if the element's funciton is to be executed; else false
///
bool Brood::BroodUI::DropDownMenu::DoElement()
{
	bool doElement = Brood::BroodUI::UIElement::DoElement();

	// this if-code-block makes it so that the if a menu of a memubar is open
	// then hover over its sibiling menus should expand/open the sibling menu.
	// 
	// if current active element's parent and hot element parent are the 
	// same then set the hot element as the current active element
	if( Brood::BroodUI::ElementSelection::GetHotElementIdPtr() == &m_elementId &&
		Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() != nullptr &&
		m_elementId.HasParent() )
	{
		// getting the curr active element's elementId
		const Brood::BroodUI::Id* currActiveId = Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr();
		const int currActiveElementId = currActiveId->GetElementID();

		// getting the pointer to curr active element
		Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );

		// getting the this element's parentptr
		Brood::BroodUI::UIElement* thisElementparentElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( m_elementId.GetParentID() );

		// checking if the currActive is dropdown and its parent is menu bar and this element and curr
		if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_dropDownMenu &&
			thisElementparentElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_menuBar &&
			GetElementIdPtr()->GetParentID() == currActiveId->GetParentID() )
		{
			Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( currActiveElement->GetElementIdPtr() );
			Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( &m_elementId );
		}
	}


	// chekcing if this element is currActive and is not hot when 
	// left mouse button is not pressed
	Brood::BroodUI::Id* hotElementLocalCopy = Brood::BroodUI::ElementSelection::GetHotElementIdPtr();
	
	if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() &&
		Brood::MouseHandler::IsLeftButtonPressed() &&
		GetElementIdPtr() != hotElementLocalCopy )
	{
		// chekcing if the hot element is its child 
		bool isHotElementValidChild = false;
		std::vector<Brood::BroodUI::Button*>::iterator childElementsIte = m_items.begin();

		while( childElementsIte != m_items.end() )
		{
			if( ( *childElementsIte )->GetElementIdPtr() == hotElementLocalCopy )
			{
				isHotElementValidChild = true;
				break;
			}
			else
			{
				++childElementsIte;
			}
		}

		// if the hot element is not a valid child of this dropdown menu
		// then this element should not be currActive
		if( !isHotElementValidChild )
		{
			Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( &m_elementId );
			Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );
		}
	}

	SetSelected( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() == &m_elementId );

	// setting up overlay
	SetDrawOverlay();

	return doElement;
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
/// @public
/// @brief changes the text/texture of the element to its the element ID when debug is on
///		and changes it back to the text/texture it had before debugging when debug is off.

/// 
void Brood::BroodUI::DropDownMenu::Debugger()
{
	Brood::BroodUI::Button::Debugger();

	if( !m_items.empty() )
	{
		for( int i = 0; i < m_items.size(); ++i )
		{
			m_items.at( i )->Debugger();
		}
	}
}

/// 
/// @protected
/// @brief helper funciton to position the item at given index correctly 
///		in the drop down list.
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
/// @protected
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
		menuLength = GetFontSize() * ( float )m_maxItemLength / 1.7f;
	}

	// checking if the menuLength is less than menu main's body length
	if( menuLength < GetBodySize().x )
	{
		menuLength = GetBodySize().x;
	}

	m_items.at( a_itemIndex )->SetBodySize( menuLength, GetBodySize().y );
}

/// 
/// @protected
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
			menuLength = GetFontSize() * ( float )m_maxItemLength / 1.7f;
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
/// @protected
/// @brief Setter function to set the postiong of each item in the drop down menus
/// 
void Brood::BroodUI::DropDownMenu::SetEachItemPos()
{
	for( int i = 0; i < m_items.size(); ++i )
	{
		SetItemPos( i );
	}
}

// ======================================================================
// ================= end of DropDownMenu class ==========================
// ======================================================================