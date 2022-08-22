/*************************************************************************/
/// 
/// @file ElementSelection.h 
/// 
/// @brief  This file is a header file for ElementSelection class.
/// 
/// This class store stores the currently active element, hot element,
///		and element which on the verge of being selected
///		
/// It contains all of the declaration of the member funciton of 
///		ElementSelection class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "UI_ID.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class ElementSelection;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ElemnetSelection class ====================
// ======================================================================

///
/// @ingroup BroodUI 
/// @class ElementSelection "ElementSelection.h"
/// @brief A static class to store which element is selected and what could be selected next
/// 
/// It is a static class and can be accessed for anywere in the code base.
///		It keeps stores the currently active element--m_currActiveElement,
///		which element is in the verge of being active--m_activeElement,
///		and which element is the mouse cursor over--m_hotElement.
/// 
/// The main difference between currActiveElement and active element is that
///		a element can be set as currActiveElement only when the left mouse button is 
///		released on top the element, a activeElement is set when the left mouse 
///		button is pressed but has not be released yet.
/// 
/// To prevent multiple element slection--which can happen when more than one element 
///		overlaps, for example open menubar may cover other elements below it--it has 
///		a m_hotElementFlag member variable which gets set to true as soon as the first
///		element under the mouse cursor is found. So it is suggested to  check for 
///		elements starting from the top to bottom and going form left to right.
/// 
class Brood::BroodUI::ElementSelection
{
	// ================= public member function =================  
public:
	// setter function 
	static void SetActiveElement( Brood::BroodUI::Id* a_idPtr );
	static void SetHotElement( Brood::BroodUI::Id* a_idPtr );
	static void SetCurrActiveElement( Brood::BroodUI::Id* a_idPtr );
	static void SetHotElementFlag(bool a_found );

	// getter function 
	static const Brood::BroodUI::Id* GetHotElement();
	static const Brood::BroodUI::Id* GetActiveElement();
	static const Brood::BroodUI::Id* GetCurrActiveElement();
	static const bool GetHotElementFlag();

	// ================= private member variables =================  
private:
	///> stores the ptr to element id when the mouse is hovering over it
	static Brood::BroodUI::Id* m_hotElementPtr; 
	
	///> is set to true as soon as hot element is found for a given frame
	static bool m_hotElementFlag; 
	
	///> stores the ptr element id when the mouse is pressing on it
	static Brood::BroodUI::Id* m_activeElementPtr; 

	///> stores the ptr to element id which should be selected even 
	///> when the mouse is not over it. untill other elements are pressed
	///> after the the LMB is released and utill new element is selected
	static Brood::BroodUI::Id* m_currActiveElementPtr; 
};

// ======================================================================
// ================ end of ElemnetSelection class =======================
// ======================================================================