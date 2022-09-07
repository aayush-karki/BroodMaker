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
	Brood::BroodUI::UIElement( Brood::BroodUI::ENUM_UIType::UI_menuBar, a_parentPtr ),
	m_font( nullptr ), m_fontSize ( 0 )
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

	// deleting the font
	delete m_font;
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
	// making a new copy of the font and storing it as a pointer
	m_font = new sf::Font(*a_font);

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
void Brood::BroodUI::MenuBar::SetFontSize( int a_fontSize )
{
	float menuBarHeight = GetBodySize().y;

	// checking menu bar height
	if( menuBarHeight == 0 )
	{
		std::cerr << "The menu bar height is zero." << std::endl
			<< "Set the menubar height before setting the font size" << std::endl;
	}
	// chekcing if fontsize is greater than menu height - 2
	else if( a_fontSize > menuBarHeight - 2 )
	{
		std::cerr << "Font size is more than the menu bar height - 2." << std::endl
			<< "Setting the font size to current menubar height - 2" << std::endl
			<< "Setting the font size to " << menuBarHeight - 2 << std::endl;
		m_fontSize = menuBarHeight - 2;
	}
	else
	{
		m_fontSize = a_fontSize;
	}

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
/// @note assumes that menu bar is already set. @see SetMenuBarBodySize
/// @note assumes font is set. @see SetFont
/// @note assumes font size is set. @see SetCharacterSize
/// 
/// @param a_menuName name of the item
/// 
void Brood::BroodUI::MenuBar::AddMenuToMenuBar( std::string a_menuName)
{
	// create a DropDownMenu 
	Brood::BroodUI::DropDownMenu* menu = new Brood::BroodUI::DropDownMenu;

	//adding menu to the itemList
	m_menus.push_back( menu );

	// setting up the menubar
	menu->SetText( a_menuName );
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
	menu->GetElementIdPtr()->SetParent( GetElementIdPtr());
}

/// 
/// @public
/// @brief Function to add menu item to menu in menubar
///
/// @param a_menuItemName name of the item
/// 
void Brood::BroodUI::MenuBar::AddItemToMenu( unsigned a_index, std::string a_menuItemName )
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
		bodySizeX = m_fontSize * ( float)textLen * 2;
	}
	else if( textLen < 8 )
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