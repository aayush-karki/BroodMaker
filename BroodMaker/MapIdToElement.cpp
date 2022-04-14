/*************************************************************************/
/// 
/// @file MapIdToElement.cpp 
/// 
/// @brief  This file is a source file for MapIdToElement class
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the static data member of
///		MapIdToElement class and member function
/// 
/************************************************************************/


#include "stdafx.h"
#include "MapIdToElement.h"

// declaring the static data member
std::map<const int, Brood::BroodUI::UIElement*> Brood::BroodUI::MapIdToElement::m_mapper;


/// 
/// @static
/// @public
/// @brief Getter Function
/// 
/// Gets the element that is mapped to from id. if the element was 
///		not found returns nullptr
/// 
/// @param a_id unique id of the element that is mapped to the 
/// 
/// @return pointer to the element whose unique id is the parameter;
/// 
Brood::BroodUI::UIElement* Brood::BroodUI::MapIdToElement::GetElementPtrFromMap( int a_id )
{
	std::map<const int, Brood::BroodUI::UIElement*>::iterator findResult = m_mapper.find( a_id );

	// return pointer to the element if true else reutrn nullptr
	return findResult != m_mapper.end() ? findResult->second: nullptr;
}

/// 
/// @static
/// @public
/// @brief adds the id and element to the map
/// 
/// @param a_id unique id of the element that is mapped to the 
/// @param a_elementPtr pointer to the element that has the passed uniquie UI_ID
/// 
/// @return true if adding was successfull; else false
/// 
bool Brood::BroodUI::MapIdToElement::AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr )
{
	auto addResult = m_mapper.insert( std::pair<int, Brood::BroodUI::UIElement* > {a_id, a_elementPtr} );

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
/// @param a_id unique id of the element that is mapped to the 
/// 
/// @return true if removal was successfull; else false
/// 
bool Brood::BroodUI::MapIdToElement::ReomveFromMap( int a_id )
{

	auto eraseResult = m_mapper.erase( a_id );

	if( !eraseResult )
	{
		// removal was not successfull
		std::cerr << "Error! Removal of UIELmenet with id " << a_id << " failed" << std::endl;
		return false;
	}

	return true;
}
