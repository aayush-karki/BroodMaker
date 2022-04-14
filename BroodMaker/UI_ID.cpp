/*************************************************************************/
/// 
/// @file UI_ID.cpp 
/// 
/// @brief  This file is a source file for Id class
///		which is in BroodUI namespace
/// 
/// It contains all of the defination of the member 
///		funciton of Id class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "UI_ID.h"

/// @static
/// @public
/// @brief assigning a location for global id. 
/// 
/// It starts with 0 and only goes up.
/// 
unsigned Brood::BroodUI::Id::GLOBAL_ID_NUM = 0; // staring id

///
/// @public
/// @brief Getter function to get pointer to its child at the provided 
///		index
/// 
/// @note if there index suppied is out of bound then, it logs the error and
///		returns nullptr
/// 
/// @param a_index index at which the child's pointer to retrive form
/// 
/// @return pointer to child at the given index
/// 
const Brood::BroodUI::Id* Brood::BroodUI::Id::GetChildIdAtIdx( const int a_index ) const
{
	if( a_index > ( m_allChildPtrs.size() - 1 ) )
	{
		std::cerr << "Error!! the index " << a_index << "does not exit for element with ID: "
			<< m_elementID << std::endl;
		return nullptr;
	}
	else
	{
		return m_allChildPtrs.at( a_index );
	}
}

