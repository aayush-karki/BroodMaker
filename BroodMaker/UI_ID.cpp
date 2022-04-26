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


///
/// @public
/// @brief deletes the child at a_index from the child list
/// 
/// It erases the element at the given index
/// 
/// @param a_index index at which the child's pointer is to be deleted
/// 
void Brood::BroodUI::Id::DeleteChildIdAtIdx( const int a_index )
{
	if( m_allChildPtrs.empty() )
	{
		// child list is empty. 
		std::cerr << "Error! Cannot erase as the child list is empty." << std::endl;
		return;
	}
	else if( a_index > ( int )m_allChildPtrs.size() - 1 )
	{
		// trying to delete invalid index
		std::cerr << "Error! Tying to erase invalid index" << std::endl;
		return;
	}

	// delete the index
	std::vector<const Brood::BroodUI::Id*>::iterator elementToDelete = m_allChildPtrs.begin() + a_index;
	m_allChildPtrs.erase( elementToDelete, elementToDelete + 1 );
}
