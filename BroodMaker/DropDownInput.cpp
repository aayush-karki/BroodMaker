/*************************************************************************/
/// 
/// @file DropDownInput.cpp 
/// 
/// @brief  This file is a source file for DropDownInput class.
/// 
/// It contains all of the defination of the member 
///		funciton of DropDownInput class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "DropDownInput.h"

// ======================================================================
// ================= start of DropDownInput class ========================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the DropDownInput object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::DropDownInput::DropDownInput( Brood::BroodUI::UIElement* a_parentPtr,
											  Brood::BroodUI::ENUM_UIType a_enumType ) :
	Brood::BroodUI::DropDownMenu( a_parentPtr, a_enumType )
{}

///
/// @public
/// @brief Default Destructor
/// 
Brood::BroodUI::DropDownInput::~DropDownInput()
{}

/// 
/// @public
/// @brief Function to add menu item to the dropdown menu
///
/// It dynamically allocates memory for the item
/// 
/// @param a_menuName name of the item
/// @param a_color font color -> default sf::Color::White
/// 
void Brood::BroodUI::DropDownInput::AddItemToMenu( std::string a_menuName, sf::Color a_color )
{
	Brood::BroodUI::DropDownMenu::AddItemToMenu(a_menuName, a_color);

	SetBodySize( m_items.at( 0 )->GetBodySize() );
	SetTextPosition();
}