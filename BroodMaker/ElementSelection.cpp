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



/// 
/// @static
/// @public
/// @brief Setter function;
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
/// @brief Setter function.
/// 
/// Set the passed element id as active
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
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetCurrActiveElement( Brood::BroodUI::Id* a_idPtr )
{
	m_currActiveElementPtr = a_idPtr;
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
