/*************************************************************************/
/// 
/// @file MapIdToElement.h 
/// 
/// @brief  This file is a header file for MapIdToElement
///		which are declared in BroodUI namespace.
/// 
/// MapIdToElement is a static class that maps the unique
///		ui element id to its element. 
/// 
/// It contains all of the declaration of the member 
///		funciton of MapIdToElement class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "UI_ID.h"
#include "UIElement.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class MapIdToElement;
		class UIElement;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of MapIdToElement class ======================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class MapIdToElement
/// @brief A static struct to handel the mapping of unique UI_ID to its element
///		for quick acceess 
/// 
class Brood::BroodUI::MapIdToElement
{
	// ================= public member function ===================  
public:
	// Getter functions
	static std::map<const int, Brood::BroodUI::UIElement*>& GetMap();
	static Brood::BroodUI::UIElement* GetElementPtrFromMap( int a_id );

	static bool AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr );
	static bool ReomveFromMap( int a_id );

	// ================= private member variables =================  
private:
	///> maps the unique UI ID to the element
	static std::map<const int, Brood::BroodUI::UIElement*> stm_mapper;
};

// ======================================================================
// ================= end of MapIdToElement calss ====================
// ======================================================================
