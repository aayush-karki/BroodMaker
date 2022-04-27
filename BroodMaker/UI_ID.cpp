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
/// @brief default constructor
/// 
/// Initializes the data member of the function. 
/// 
/// @note If no parent is supplied, it initializes both 
///		m_parentId and m_index to -1.
/// 
/// @param a_parentID pointer to the Id of the parent if any; default to nullPtr
/// @param a_index  index of the element if any; default to 0
///
Brood::BroodUI::Id::Id( Id* a_parentID, int a_index ) :
	m_elementID( GLOBAL_ID_NUM++ ), m_hasChilds( false )
{
	Brood::BroodUI::Id::SetParent( a_parentID, a_index );
}


///
/// @public
/// @brief Getter function to get the parent's ID
/// 
/// @note if the element has no parent then the parent Id returned is -1
///
/// @return parent's unique UI ID
/// 
const int Brood::BroodUI::Id::GetParentID() const
{
	return m_parentID;
}

///
/// @public
/// @brief Getter function to get the element's ID
/// 
/// @return element's unique UI ID
/// 
const int Brood::BroodUI::Id::GetElementID() const
{
	return m_elementID;
}

///
/// @public
/// @brief Getter function to get the element's index
/// 
/// @note if the element has no parent then the index returned is -1
/// 
/// @return element's index relative to parent's child
/// 
const int Brood::BroodUI::Id::GetIdIndex() const
{
	return m_index;	
}

///
/// @public
/// @brief Getter function to get how many child the element has
/// 
/// @return element's child list size
/// 
const int Brood::BroodUI::Id::GetTotalChildNum() const
{
	return m_allChildPtrs.size();
}

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
Brood::BroodUI::Id* Brood::BroodUI::Id::GetChildIdAtIdx( const int a_index ) const
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
/// @brief Getter function to check if the element has a child or not
/// 
/// @return true if the element has child/s; else returns false
/// 
bool Brood::BroodUI::Id::HasChild() const
{
	return m_hasChilds;
}

///
/// @public
/// @brief Getter function to check if the element has a parent or not
/// 
/// @return true if the element has parent; else returns false
/// 
bool Brood::BroodUI::Id::HasParent() const
{
	return m_parentID != -1;
}

void Brood::BroodUI::Id::SetParent( Brood::BroodUI::Id* a_parentID, int a_index )
{
	//setting parent id
	m_parentID = a_parentID != nullptr ? a_parentID->GetElementID() : -1;

	m_index = a_parentID != nullptr ? a_index : -1;
}

///
/// @public
/// @brief adds the child to its child list
/// 
/// @param a_childIdPtr const pointer to the child id
/// 
int Brood::BroodUI::Id::AddChild( Brood::BroodUI::Id* a_childIdPtr)
{
	m_allChildPtrs.push_back( a_childIdPtr );
	m_hasChilds = true;

	return m_allChildPtrs.size() - 1;
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
	if( m_allChildPtrs.size() == NULL )
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
	std::vector<Brood::BroodUI::Id*>::iterator elementToDelete = m_allChildPtrs.begin() + a_index;
	m_allChildPtrs.erase( elementToDelete, elementToDelete + 1 );
}
