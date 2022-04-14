/*************************************************************************/
/// 
/// @file MapIdToElement.h 
/// 
/// @brief  This file is a header file for MapIdToElement class.
/// 
/// It contains all of the declaration of the member 
///		funciton of MapIdToElement class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of MapIdToElement class
///
/************************************************************************/

#pragma once
#include "UI_ID.h"
#include "UIElement.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class MapIdToElement;
	}
}
// ==================== end of namespace  defination =======================


///
/// @ingroup BroodUI
/// @static 
/// @class MapIdToElement  "MapIdToElement.h"
/// @brief A class to handel the mapping of unique UI_ID to its element
///		for quick acceess 
/// 
class Brood::BroodUI::MapIdToElement
{

public:
	static std::map<const int, Brood::BroodUI::UIElement*>& GetMap();
	static Brood::BroodUI::UIElement* GetElementPtrFromMap( int a_id );
	static bool AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr );
	static bool ReomveFromMap( int a_id );


private:
	static std::map<const int, Brood::BroodUI::UIElement*> m_mapper;
};

/// 
/// @static
/// @public
/// @brief Getter Funciton
/// 
/// gets the map
/// 
/// @return reference to the map
/// 
inline std::map<const int, Brood::BroodUI::UIElement*>& Brood::BroodUI::MapIdToElement::GetMap()
{
	return m_mapper;
}
