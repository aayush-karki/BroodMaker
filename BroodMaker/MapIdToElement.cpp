/*************************************************************************/
/// 
/// @file MapIdToElement.cpp 
/// 
/// @brief  This file is a source file for MapIdToElement class.
/// 
/// It contains all of the defination of the member 
///		funciton of MapIdToElement class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "MapIdToElement.h"

// ======================================================================
// ================= start of MapIdToElement class ======================
// ======================================================================

/// 
/// @static
/// @public
/// @brief Getter Funciton to get a reference to the map
/// 
/// @return reference to the map
/// 
std::map<const int, Brood::BroodUI::UIElement*>& Brood::BroodUI::MapIdToElement::GetMap()
{
	return stm_mapper;
}

/// 
/// @static
/// @public
/// @brief Getter Function to get the element that is mapped to from ui id. 
/// 
/// @param a_id unique id of the element that maps to its element pointer
/// 
/// @return pointer to the element whose unique id was mapped to; 
///		else returns nullptr if not matched
/// 
Brood::BroodUI::UIElement* Brood::BroodUI::MapIdToElement::GetElementPtrFromMap( int a_id )
{
	std::map<const int, Brood::BroodUI::UIElement*>::iterator findResult = stm_mapper.find( a_id );

	// return pointer to the element if true else reutrn nullptr and log it
	if( findResult == stm_mapper.end() )
	{
		std::cerr << "Error! Could not find a UIELmenet with id " << a_id << "." << std::endl;
		return nullptr;
	}
	return findResult->second;
}

/// 
/// @static
/// @public
/// @brief adds the id and element to the map
/// 
/// @param a_id unique id of the element that is mapped to its element pointer
/// @param a_elementPtr pointer to the element that has the passed uniquie UI_ID
/// 
/// @return true if adding was successfull; else false
/// 
bool Brood::BroodUI::MapIdToElement::AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr )
{
	auto addResult = stm_mapper.insert( std::pair<int, Brood::BroodUI::UIElement* > {a_id, a_elementPtr} );

	if( !addResult.second )
	{
		// inresertion was not successfull
		std::cerr << "Error! Insertion of UIELmenet with id " << a_id << " failed" << std::endl;
		return false;
	}

	return true;
}

/// 
/// @static
/// @public
/// @brief removes a entry with the id as a key from the map
/// 
/// @param a_id unique id of the element that is mapped to its element pointer
/// 
/// @return true if removal was successfull; else false
/// 
bool Brood::BroodUI::MapIdToElement::ReomveFromMap( int a_id )
{
	auto eraseResult = stm_mapper.erase( a_id );

	if( !eraseResult )
	{
		// removal was not successfull
		std::cerr << "Error! Removal of UIELmenet with id " << a_id << " failed" << std::endl;
		return false;
	}

	return true;
}

// ======================================================================
// ================= end of MapIdToElement Class ====================
// ======================================================================
