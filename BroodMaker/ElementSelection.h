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
		class Id;
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
/// The main difference between currActiveElement and almostActiveElement is that
///		a element can be set as currActiveElement only when the left mouse button is 
///		released on top the element, an almostActiveElement is set when the left mouse 
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
	// ========= setter functions ========

	// setter function to set the hot element Id pointer
	static void SetHotElementIdPtr( Brood::BroodUI::Id* a_idPtr );

	// setter function to set the almost active element Id pointer
	static void SetAlmostActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr );

	// setter function to set the current active element Id pointer
	static void SetCurrActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr );

	// setter function to set the last active element Id pointer
	static void SetLastActiveElementIdPtr( Brood::BroodUI::Id* a_idPtr );

	// setter function to set the hot element Id pointer Flag
	static void SetHotElementIdPtrFlag( bool a_found );

	// ========= setter functions ========

	// getter function to get the hot element Id pointer
	static Brood::BroodUI::Id* GetHotElementIdPtr();

	// getter function to get the almost active element Id pointer
	static Brood::BroodUI::Id* GetAlmostActiveElementIdPtr();

	// getter function to get  the current active element Id pointer
	static Brood::BroodUI::Id* GetCurrActiveElementIdPtr();

	// getter function to get the last active element Id pointer
	static Brood::BroodUI::Id* GetLastActiveElementIdPtr();

	// getter function to getthe hot element Id pointer Flag
	static bool GetHotElementIdFlag();

	// debugging
	static void Debugger();
	static void DebugPrintSelectedElementID();

	// ================= private member variables =================  
private:

	/// stores the ptr to element id when the mouse is hovering over it
	static Brood::BroodUI::Id* m_hotElementIdPtr;

	/// is set to true as soon as hot element is found for a given frame
	static bool m_hotElementFlag;

	/// stores the ptr element id when the mouse is pressing on it
	static Brood::BroodUI::Id* m_almostActiveElementIdPtr;

	/// stores the ptr to element id which should be selected even 
	/// when the mouse is not over it. untill other elements are pressed
	/// after the the LMB is released and utill new element is selected
	static Brood::BroodUI::Id* m_currActiveElementIdPtr;

	/// stores the pointer to the last active element
	static Brood::BroodUI::Id* m_lastActiveElementIdPtr;
};

// ======================================================================
// ================ end of ElemnetSelection class =======================
// ======================================================================