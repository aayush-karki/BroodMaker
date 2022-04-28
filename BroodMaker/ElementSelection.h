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
	static void SetCurrActiveElement( Brood::BroodUI::Id* a_idPtr );

	// getter function 
	static const Brood::BroodUI::Id* GetHotElement();
	static const Brood::BroodUI::Id* GetActiveElement();
	static const Brood::BroodUI::Id* GetCurrActiveElement();

	// ================= private member variables =================  
private:
	static Brood::BroodUI::Id* m_hotElementPtr; ///> stores the ptr to element id when the mouse is hovering over it
	static Brood::BroodUI::Id* m_activeElementPtr; ///> stores the ptr element id when the mouse is pressing on it
	static Brood::BroodUI::Id* m_currActiveElementPtr; ///> stores the ptr to element id which should be selected even 
													   ///> after the the LMB is released and utill new element is selected
};
