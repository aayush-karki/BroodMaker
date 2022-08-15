/*************************************************************************/
/// 
/// @file ElementSelection.cpp 
/// 
/// @brief  This file is a source file for ElementSelection class
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the static data member of
///		ElementSelection class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "ElementSelection.h"

// allocating loaction of the static data member
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_activeElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_hotElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_currActiveElementPtr = nullptr;
bool Brood::BroodUI::ElementSelection::m_hotElementFlag = false;

/// 
/// @static
/// @public
/// @brief Setter function
/// 
/// Set the passed element id as hot
/// 
/// @param a_idPtr pointer to UI_ID of the element the mouse is hover over
/// 
void Brood::BroodUI::ElementSelection::SetHotElement( Brood::BroodUI::Id* a_idPtr )
{
	m_hotElementPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function
/// 
/// Set the passed element id as active
/// 
/// @note  activeElement differs from currActiveElement as the prior stores 
///		element id when the mouse is pressing on it while the latter stores 
///		element id of even when the mouse is not over it  untill other elements 
///		are pressed.
///		
/// 
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetActiveElement( Brood::BroodUI::Id* a_idPtr )
{
	m_activeElementPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function.
/// 
/// Set the passed element id as current active
/// 
/// @note  activeElement differs from currActiveElement as the prior stores 
///		element id when the mouse is pressing on it while the latter stores 
///		element id of even when the mouse is not over it  untill other elements 
///		are pressed.
/// 
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetCurrActiveElement( Brood::BroodUI::Id* a_idPtr )
{
	m_currActiveElementPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function.
/// 
/// Flags if the hot element is found for a given frame. It is set only once
///		for a given frame.
/// 
/// @param a_found true if a hot element is set in a given 
/// 
void Brood::BroodUI::ElementSelection::SetHotElementFlag( bool a_found )
{
	m_hotElementFlag = a_found;
}

/// 
/// @static 
/// @public
/// @brief Getter function;
/// 
/// Gets the pointer to hot element
/// 
/// @return the pointer to hot element
/// 
const Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetHotElement()
{
	return m_hotElementPtr;
}

/// 
/// @static 
/// @public
/// @brief Getter function;
/// 
/// Gets the pointer to active element
/// 
/// @return the pointer to active element
/// 
const Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetActiveElement()
{
	return m_activeElementPtr;
}

/// 
/// @static 
/// @public
/// @brief Getter function;
/// 
/// Gets the pointer to current active element
/// 
/// @return the pointer to current active element
/// 
const Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetCurrActiveElement()
{
	return m_currActiveElementPtr;
}


/// 
/// @static 
/// @public
/// @brief Getter function;
/// 
/// Gets the state of the m_hotElementFlag
/// 
/// @return state of the m_hotElementFlag
/// 
const bool Brood::BroodUI::ElementSelection::GetHotElementFlag()
{
	return m_hotElementFlag;
}
