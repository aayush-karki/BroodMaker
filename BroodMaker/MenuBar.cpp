/*************************************************************************/
/// 
/// @file MenuBar.cpp 
/// 
/// @brief  This file is a source file for MenuBar class.
/// 
/// It contains all of the defination of the member 
///		funciton of MenuBar class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "MenuBar.h"

// ======================================================================
// ================= start of MenuBar class =============================
// ======================================================================

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
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_menuBar, a_parentPtr )
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
/// @brief Copy constructor
/// 
/// @param a_otherElement reference to the MenuBar which is used to 
///		copy the data form 
/// 
Brood::BroodUI::MenuBar::MenuBar( const MenuBar& a_otherElement ) :
	Brood::BroodUI::UIElement( a_otherElement )
{
	// copying the the menu items by maling a deep copy
	std::vector<Brood::BroodUI::DropDownMenu*> otherMenus = a_otherElement.m_menus;
	std::vector<Brood::BroodUI::DropDownMenu*>::iterator otherMenusIte = otherMenus.begin();
	while( otherMenusIte != otherMenus.end() )
	{
		AddMenuToMenuBar( *otherMenusIte );
		++otherMenusIte;
	}
}


/// 
/// @brief assignment operator
/// 
/// @param a_otherElement reference to the dropdown menu which is used to 
///		copy the data form 
/// 
/// @return pointer to this element
/// 
Brood::BroodUI::MenuBar& Brood::BroodUI::MenuBar::operator=( const MenuBar& a_otherElement )
{
	// chekcing for self assignment
	if( this == &a_otherElement )
	{
		return *this;
	}

	// calling the assignment operator of the UIElement
	Brood::BroodUI::UIElement::operator=( a_otherElement );

	// copying the the menu items by maling a deep copy
	std::vector<Brood::BroodUI::DropDownMenu*> otherMenus = a_otherElement.m_menus;
	std::vector<Brood::BroodUI::DropDownMenu*>::iterator otherMenusIte = otherMenus.begin();
	while( otherMenusIte != otherMenus.end() )
	{
		AddMenuToMenuBar( *otherMenusIte );
		++otherMenusIte;
	}
	return *this;
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
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the MenuBar's size
/// 
/// @note this is the menu bar size and not the menu itself
/// 
/// @warning The menu height cannot be smaller than font size + 2 px.
/// 
/// @param a_size length and height the menubar -> sf::vector2f
/// 
void Brood::BroodUI::MenuBar::SetBodySize( sf::Vector2f a_size )
{
	//checking if the new height for the bar body is smaller than the charsize
	if( a_size.y < m_fontSize + 2 )
	{
		std::cerr << "Menu bar height needs to be 2 pixel bigger than charSize" << std::endl;
		return;
	}
	else if( a_size.y < m_fontSize )
	{
		std::cerr << "Menu bar height cannot be smaller than Character Size cannot" << std::endl;
		return;
	}

	// setting the bar body size
	Brood::BroodUI::UIElement::SetBodySize( a_size );

	// setting the height of the each of the menu item if present
	if( !m_menus.empty() )
	{
		for( int i = 0; i < m_menus.size(); ++i )
		{
			float itemSizeX = m_menus.at( i )->GetBodySize().x;
			float itemSizeY = GetBodySize().y;

			m_menus.at( i )->SetBodySize( itemSizeX, itemSizeY );
		}
	}
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the MenuBar's size
/// 
/// @note this is the menu bar size and not the menus size.
///		Menu size is determined by its content.
/// 
/// @param a_itemSizeX length of the menubar
/// @param a_itemSizeY height of the menubar
/// 
void Brood::BroodUI::MenuBar::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::MenuBar::SetBodySize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the menubar's Position.
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
			// setting the position of the menu in the menubar itself
			SetMenuPos( i );
		}
	}
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the menubar's Position
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
	Brood::BroodUI::UIElement::SetFont( *a_font );

	// setting the fonts of menus items
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
/// @brief Setter funtion to set the size of the font
/// 
///	This does not affect the menubar height at all.
/// 
/// @warning Before setting the font size set the menubar height
/// 
///	@warning Font size cannot be bigger than menu height - 2. If a 
///		a_fontSize is bigger than the menu height by menu height - 2.
///		then sets  the font size to menu height - 2
/// 
/// @param a_fontSize size of the font in pixel
/// 
void Brood::BroodUI::MenuBar::SetFontSize( unsigned a_fontSize )
{
	Brood::BroodUI::UIElement::SetFontSize( a_fontSize );

	// updating the charsize of all the item in the menu bar
	if( !m_menus.empty() )
	{
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->SetFontSize( m_fontSize );
		}
	}
}

/// 
/// @public
/// @brief Function to add menu to the menubar
///
/// It dynamically allocates memory for the menu and adds it to the list.
/// 
/// @note assumes that menu bar is already set. For more 
///		informantion @see Brood::BroodUI::MenuBar::SetMenuBodySize()
/// @note assumes font is set. For more 
///		informantion @see Brood::BroodUI::UIElement::SetFont()
/// @note assumes font size is set. For more 
///		informantion @see Brood::BroodUI::UIElement::SetCharacterSize()
/// 
/// @param a_menuName name of the item
/// 
void Brood::BroodUI::MenuBar::AddMenuToMenuBar( std::string a_menuName )
{
	// create a DropDownMenu 
	Brood::BroodUI::DropDownMenu* menu = new Brood::BroodUI::DropDownMenu;

	//adding menu to the itemList
	m_menus.push_back( menu );

	// setting up the menubar
	SetMenuBodySize( m_menus.size() - 1 ); // setting the menu size
	SetMenuPos( m_menus.size() - 1 ); // setting the menu pos
	menu->SetFont( m_font );
	menu->SetFontSize( m_fontSize );
	menu->SetText( a_menuName );
	menu->SetBodyColor( GetBodyColor() );

	// setting up the id
	// adding the item as child of the dropDown
	GetElementIdPtr()->AddChild( menu->GetElementIdPtr() );
	// adding the dropdown as parent of the item
	menu->GetElementIdPtr()->SetParent( GetElementIdPtr() );
}

/// 
/// @public
/// @brief Function to adds the passed DropDownMenu at back of 
///		menubar 
///
/// if a_createNew is true then create a new DropDownMenu 
///		using the passed item then adds the new DropDownMenu 
///		to the menubar
/// It dynamically allocates memory for the newly created item
///
/// @param a_dropdownMenuPtrToAdd pointer to the dropdownMenu
///		element which is used to add at the back
/// @param a_createNew if a_createNew is true then create a new  
///		dropdownMenu using the passed item then adds the new button 
/// 
void Brood::BroodUI::MenuBar::AddMenuToMenuBar( Brood::BroodUI::DropDownMenu* a_dropdownMenuPtrToAdd,
												bool a_createNew )
{
	Brood::BroodUI::DropDownMenu* menu;
	if( a_createNew )
	{
		menu = new Brood::BroodUI::DropDownMenu( ( *a_dropdownMenuPtrToAdd ) );
	}
	else
	{
		menu = a_dropdownMenuPtrToAdd;
	}

	//adding menu to the itemList
	m_menus.push_back( menu );

	SetMenuBodySize( m_menus.size() - 1 ); // setting the menu size
	SetMenuPos( m_menus.size() - 1 ); // setting the menu pos

	// setting up the id
	// adding the item as child of the dropDown
	GetElementIdPtr()->AddChild( menu->GetElementIdPtr() );
	// adding the dropdown as parent of the item
	menu->GetElementIdPtr()->SetParent( GetElementIdPtr() );
}

/// 
/// @public
/// @brief Function to add menu item to menu in menubar
///
/// @param a_index menu bar which dropdown the item is to 
///		be added to
/// @param a_menuItemName name of the item
/// 
void Brood::BroodUI::MenuBar::AddItemToMenu( unsigned a_index,
											 std::string a_menuItemName )
{
	// checking if the index is valid
	if( a_index >= m_menus.size() )
	{
		std::cerr << "Invalid index!!!" << std::endl;
		return;
	}

	m_menus.at( a_index )->AddItemToMenu( a_menuItemName );
}

/// 
/// @public
/// @brief Function to adds the passed button to dropdown menu
///		at passed index
///
/// if a_createNew is true then create a new button using 
///		the passed item then adds the new button to the DropDownMenu
/// 
/// It dynamically allocates memory for the newly created item
///
/// @param a_index menu bar which dropdown the item is to 
///		be added to
/// @param a_buttonPtrToAdd pointer to the button element which 
///		is used to add
/// @param a_createNew if a_createNew is true then create a new  
///		button using the passed item then adds the new button 
/// 
void Brood::BroodUI::MenuBar::AddItemToMenu( unsigned a_index,
											 Brood::BroodUI::Button* a_buttonPtrToAdd,
											 bool a_createNew )
{
	// checking if the index is valid
	if( a_index >= m_menus.size() )
	{
		std::cerr << "Invalid index!!!" << std::endl;
		return;
	}

	m_menus.at( a_index )->AddItemToMenu( a_buttonPtrToAdd, a_createNew );
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
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->Draw( a_window );
		}
	}
}

/// 
/// @public
/// @brief changes the text of the element to its the element ID when debug is on
///		and changes it back to the text it had before debugging when debug is off.

/// 
void Brood::BroodUI::MenuBar::Debugger()
{
	Brood::BroodUI::UIElement::Debugger();

	if( !m_menus.empty() )
	{
		for( int i = 0; i < m_menus.size(); ++i )
		{
			m_menus.at( i )->Debugger();
		}
	}
}
/// 
/// @private
/// @brief helper funciton to set the body size of the menus correctly in the menubar
///
/// @param a_itemIndex index of the menu in the menu list
/// 
void Brood::BroodUI::MenuBar::SetMenuBodySize( int a_itemIndex )
{
	DropDownMenu* menuToChange = m_menus.at( a_itemIndex );
	unsigned textLen = menuToChange->GetText().length();
	float bodySizeX = 0.f;

	// checking the length of text in the menu
	if( textLen < 3 )
	{
		bodySizeX = m_fontSize * ( float )textLen * 2;
	}
	else if( textLen < 15 )
	{
		bodySizeX = m_fontSize * ( float )textLen / 1.5f;
	}
	else
	{
		bodySizeX = m_fontSize * ( float )textLen / 2.f;
	}

	// setting the body Size
	menuToChange->SetBodySize( bodySizeX, GetBodySize().y );
}

/// 
/// @private
/// @brief helper funciton to position the menus correctly in the menubar
///
/// @param a_itemIndex index of the menu in the menu list
/// 
void Brood::BroodUI::MenuBar::SetMenuPos( int a_itemIndex )
{
	// when itemIndex is 0 set the pos to same as the menubar 
	// as it is the first menu in the menubar
	if( a_itemIndex == 0 )
	{
		m_menus.at( a_itemIndex )->SetBodyPosition( GetBodyPosition() );
		return;
	}

	// else calculating the menu's positon in the menubar, 
	// the menu position depends on the end of the menu before it

	// getting the position of menu before this 
	sf::Vector2f secondLastMenuPos = m_menus.at( a_itemIndex - 1 )->GetBodyPosition();
	float lastMenuPosX = secondLastMenuPos.x + m_menus.at( a_itemIndex - 1 )->GetBodySize().x;

	// setting the Menu at givien index position
	// this also sets the postion of any item that the dropdown menu might have
	m_menus.at( a_itemIndex )->SetBodyPosition( lastMenuPosX, GetBodyPosition().y );
}

// ======================================================================
// ================= end of MenuBar class ===============================
// ======================================================================