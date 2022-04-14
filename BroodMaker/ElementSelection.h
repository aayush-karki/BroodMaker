/*************************************************************************/
/// 
/// @file ElementSelection.h 
/// 
/// @brief  This file is a header file for ElementSelection class.
/// 
/// This class stores what element the is selected and what could be selected
/// 
/// It contains all of the declaration of the member 
///		funciton of ElementSelection class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of ElementSelection class
///
/************************************************************************/

#pragma once

#include "UI_ID.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class ElementSelection;
	}
}
// =============================== end of namespace  defination =======================

		///
		/// @ingroup BroodUI 
		/// @ static
		/// @brief stores what element the is selected and what could be selected
		///
class Brood::BroodUI::ElementSelection
{
	// ================= public member function =================  
public:
	// setter function 
	static void SetActiveElement( Brood::BroodUI::Id* a_idPtr );
	static void SetHotElement( Brood::BroodUI::Id* a_idPtr );

	// getter function 
	static const Brood::BroodUI::Id* GetActiveElement();
	static const Brood::BroodUI::Id* GetHotElement();

	// ================= private data member =================  
private:
	static Brood::BroodUI::Id* m_hotElementPtr; ///> stores the ptr to id of element when the mouse is hovering over it
	static Brood::BroodUI::Id* m_activeElementPtr; ///> stores the ptr id of element when the mouse is selecting it
};

/// 
/// @static
/// @public
/// @brief Setter function.
/// 
/// Set the passed element id as active
/// 
/// @param a_idPtr pointer to UI_ID of the selected element
/// 
inline void Brood::BroodUI::ElementSelection::SetActiveElement( Brood::BroodUI::Id* a_idPtr )
{
	m_activeElementPtr = a_idPtr;
}

/// 
/// @static
/// @public
/// @brief Setter function;
/// 
/// Set the passed element id as hot
/// 
/// @param a_idPtr pointer to UI_ID of the element the mouse is hover over
/// 
inline void Brood::BroodUI::ElementSelection::SetHotElement( Brood::BroodUI::Id* a_idPtr )
{
	m_hotElementPtr = a_idPtr;
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
inline const Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetActiveElement()
{
	return m_activeElementPtr;
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
inline const Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::GetHotElement()
{
	return m_hotElementPtr;
}
