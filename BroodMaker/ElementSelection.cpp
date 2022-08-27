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
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_almostActiveElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_hotElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_currActiveElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_lastActiveElementIdPtr = nullptr;
bool Brood::BroodUI::ElementSelection::m_hotElementFlag = false;

Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_debugSaveAlmostActiveElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_debugSaveHotElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_debugSaveCurrActiveElementIdPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_debugSaveLastActiveElementPtr = nullptr;

/// 
/// @static
/// @public
/// @brief Setter function to set passed UI id as the hot element
/// 
/// @param a_idPtr pointer to UI_ID of the element the mouse is hovering over
/// 
void Brood::BroodUI::ElementSelection::SetHotElementIdPtr( Brood::BroodUI::Id* a_idPtr )
{
	m_hotElementIdPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function to set the passed element id as active element
///
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetAlmostActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr )
{
	m_almostActiveElementIdPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function sets the passed element id as current active element
/// 
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr )
{
	m_currActiveElementIdPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function sets the passed element id as last active element
/// 
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
void Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr )
{
	m_lastActiveElementIdPtr = a_idPtr;
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
void Brood::BroodUI::ElementSelection::SetHotElementIdPtrFlag( bool a_found )
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
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetHotElementIdPtr()
{
	return m_hotElementIdPtr;
}

/// 
/// @static 
/// @public
/// @brief Getter function to gets the pointer to active element
/// 
/// @return the pointer to active element
/// 
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetAlmostActiveElementIdPtr()
{
	return m_almostActiveElementIdPtr;
}

/// 
/// @static 
/// @public
/// @brief Getter function to gets the pointer to current active element
/// 
/// @return the pointer to current active element
/// 
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr()
{
	return m_currActiveElementIdPtr;
}

/// 
/// @static 
/// @public
/// @brief Getter function to gets the pointer to current active element
/// 
/// @return the pointer to current active element
/// 
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr()
{
	return m_lastActiveElementIdPtr;
}


/// 
/// @static 
/// @public
/// @brief Getter function gets the state of the m_hotElementFlag
/// 
/// @return state of the m_hotElementFlag
/// 
bool Brood::BroodUI::ElementSelection::GetHotElementIdFlag()
{
	return m_hotElementFlag;
}

/// 
/// @static
/// @public
/// @brief Function to print the id of all the element selection pointer, namely:
///		HotElement, AlmostActiveElement, CurrActiveElement, and LastActiveElement
///  
void Brood::BroodUI::ElementSelection::Debugger()
{
	if( m_debugSaveHotElementIdPtr != m_hotElementIdPtr && m_hotElementIdPtr != nullptr )
	{
		m_debugSaveHotElementIdPtr = m_hotElementIdPtr;
		std::cout << "HotElement " << m_hotElementIdPtr->GetElementID() << std::endl;
	}
	if( m_debugSaveAlmostActiveElementIdPtr != m_almostActiveElementIdPtr && m_almostActiveElementIdPtr != nullptr )
	{
		m_debugSaveAlmostActiveElementIdPtr = m_almostActiveElementIdPtr;
		std::cout << "AlmostActiveElement " << m_almostActiveElementIdPtr->GetElementID() << std::endl;
	}
	if( m_debugSaveCurrActiveElementIdPtr != m_currActiveElementIdPtr && m_currActiveElementIdPtr != nullptr )
	{
		m_debugSaveCurrActiveElementIdPtr = m_currActiveElementIdPtr;
		std::cout << "CurrActiveElement " << m_currActiveElementIdPtr->GetElementID() << std::endl;
	}
	if( m_debugSaveLastActiveElementPtr != m_lastActiveElementIdPtr && m_lastActiveElementIdPtr != nullptr )
	{
		m_debugSaveLastActiveElementPtr = m_lastActiveElementIdPtr;
		std::cout << "LasrActiveElement " << m_lastActiveElementIdPtr->GetElementID() << std::endl;
	}

}

/// 
/// @public
/// @brief Print the selected Element ID if any
///
void Brood::BroodUI::ElementSelection::DebugPrintSelectedElementID()
{
	if( m_hotElementIdPtr != nullptr )
	{
		std::cout << "HotElement " << m_hotElementIdPtr->GetElementID() << std::endl;
	}
	if( m_almostActiveElementIdPtr != nullptr )
	{
		std::cout << "AlmostActiveElement " << m_almostActiveElementIdPtr->GetElementID() << std::endl;
	}
	if( m_currActiveElementIdPtr != nullptr )
	{
		std::cout << "CurrActiveElement " << m_currActiveElementIdPtr->GetElementID() << std::endl;
	}
	if( m_lastActiveElementIdPtr != nullptr )
	{
		std::cout << "LasrActiveElement " << m_lastActiveElementIdPtr->GetElementID() << std::endl;
	}
}

// ======================================================================
// ================ end of ElemnetSelection class =======================
// ======================================================================