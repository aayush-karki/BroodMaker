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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "ElementSelection.h"

// ======================================================================
// ============== start of ElemnetSelection class =======================
// ======================================================================

// allocating loaction for the static data member
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_activeElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_hotElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_currActiveElementPtr = nullptr;
bool Brood::BroodUI::ElementSelection::m_hotElementFlag = false;

/// 
/// @static
/// @public
/// @brief Setter function to set passed UI id as the hot element
/// 
/// @param a_idPtr pointer to UI_ID of the element the mouse is hovering over
/// 
void Brood::BroodUI::ElementSelection::SetHotElement( Brood::BroodUI::Id* a_idPtr )
{
	m_hotElementPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function to set the passed element id as active element
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
/// @brief Setter function sets the passed element id as current active element
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
/// @brief Setter function to hot element flag if a hot element is found
///		for a given frame.
/// 
/// It is set only once for any given frame.
/// 
/// @param a_found true if a hot element found for a given frame
/// 
void Brood::BroodUI::ElementSelection::SetHotElementFlag( bool a_found )
{
	m_hotElementFlag = a_found;
}

/// 
/// @static 
/// @public
/// @brief Getter function to get the pointer to hot element
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
/// @brief Getter function to gets the pointer to active element
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
/// @brief Getter function to gets the pointer to current active element
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
/// @brief Getter function gets the state of the m_hotElementFlag
/// 
/// @return state of the m_hotElementFlag
/// 
const bool Brood::BroodUI::ElementSelection::GetHotElementFlag()
{
	return m_hotElementFlag;
}

// ======================================================================
// ================ end of ElemnetSelection class =======================
// ======================================================================