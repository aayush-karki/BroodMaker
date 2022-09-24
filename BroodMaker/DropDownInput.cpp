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
/// @brief Copy constructor
/// 
/// @param a_otherElement reference to the dropdownInput which is used to 
///		copy the data form 
/// 
Brood::BroodUI::DropDownInput::DropDownInput( const Brood::BroodUI::DropDownInput& a_otherElement ) :
	Brood::BroodUI::DropDownMenu( a_otherElement )
{}

/// 
/// @brief assignment operator
/// 
/// @param a_otherElement reference to the dropdown menu which is used to 
///		copy the data form 
/// 
/// @return pointer to this element
/// 
Brood::BroodUI::DropDownInput& Brood::BroodUI::DropDownInput::operator=( const Brood::BroodUI::DropDownInput& a_otherElement )
{
	// chekcing for self assignment
	if( this == &a_otherElement )
	{
		return *this;
	}

	// calling the assignment operator of the UIElement
	Brood::BroodUI::DropDownMenu::operator=( a_otherElement );

	return *this;
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
void Brood::BroodUI::DropDownInput::AddItemToMenu( std::string a_menuName, sf::Color a_color )
{
	Brood::BroodUI::DropDownMenu::AddItemToMenu( a_menuName, a_color );

	SetBodySize( m_items.at( 0 )->GetBodySize() );
	SetTextPosition();
}

/// 
/// @public
/// @brief Function to add menu item to the dropdown menu
///
/// if a_createNew is true then create a new button using the 
///  passed item then adds the new button 
/// 
/// It dynamically allocates memory for the newly created item
/// 
/// @param a_buttonPtrToAdd pointer to the button element which 
///		is used to add
/// @param a_createNew if a_createNew is true then create a new  
///		button using the passed item then adds the new button 
/// 
void Brood::BroodUI::DropDownInput::AddItemToMenu( Brood::BroodUI::Button* a_buttonPtrToAdd, bool a_createNew )
{
	Brood::BroodUI::DropDownMenu::AddItemToMenu( a_buttonPtrToAdd, a_createNew );

	SetBodySize( m_items.at( 0 )->GetBodySize() );
	SetTextPosition();
}
