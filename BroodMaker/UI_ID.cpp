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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "UI_ID.h"

// ======================================================================
// ============== start of ID class =====================================
// ======================================================================

/// 
/// @static
/// @public
/// @brief assigning a location for global id. 
/// 
/// It starts with 0 and only goes up.
/// 
unsigned Brood::BroodUI::Id::GLOBAL_ID_NUM = 0; // starting id

/// 
/// @public
/// @brief default constructor
/// 
/// Initializes the data member of the class. 
/// 
/// @note If no parent is supplied, it initializes m_parentId to -1.
/// 
/// @param a_parentID pointer to the Id of the parent if any; default -> nullPtr
///
Brood::BroodUI::Id::Id( Id* a_parentID ) :
	m_elementID( GLOBAL_ID_NUM++ ), m_hasChilds( false )
{
	Brood::BroodUI::Id::SetParent( a_parentID);
}

/// 
/// @breif default destructor
/// 
Brood::BroodUI::Id::~Id()
{}

/// 
/// @brief Copy constructor
/// 
/// @param a_otherId reference to the Id from which Id is to be 
///		copied from
/// 
Brood::BroodUI::Id::Id( const Id & a_otherId ):
	Id()
{
	this->m_parentID = a_otherId.m_parentID;
	this->m_hasChilds = false;
}

///
/// @brief assignment operator
/// 
/// @param a_otherId reference to the Id from which Id is to be 
///		copied from
///
/// @return pointer to itself
///
Brood::BroodUI::Id& Brood::BroodUI::Id::operator=( const Id& a_otherId )
{
	// chekcing for self assignment
	if( this == &a_otherId )
	{
		return *this;
	}

	// removing itself as form all of its childs
}

///
/// @public
/// @brief Getter function to get the parent's ID
/// 
/// @return parent's unique UI ID if presents, else returns -1
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
/// @brief Getter function to get its child element's index in its list
/// 
/// @param a_childIDPtr pointer to the child whose index we are trying to find
/// 
/// @return child element's index in its child list; if no such child exists return -1
/// 
const int Brood::BroodUI::Id::GetChildIdx( const Brood::BroodUI::Id* a_childIDPtr ) const
{
	int idx = 0;
	
	// loop through the the child list
	std::vector<Brood::BroodUI::Id*>::const_iterator currChildId = m_allChildPtrs.begin();
	while( currChildId != m_allChildPtrs.end())
	{
		if( a_childIDPtr->GetElementID() == ( *currChildId )->GetElementID() )
		{
			// match found 
			return idx;
		}

		++currChildId;
		++idx;
	}

	std::cerr << "Error!! No such child exist for the element with ID:" <<
		m_elementID << std::endl;
	return -1;
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
/// @brief Getter function to get pointer of the passed child's index
/// 
/// @note if there index suppied is out of bound then, it logs the error and
///		returns nullptr
/// 
/// @param a_index index of the child in the elements's child list
/// 
/// @return pointer to child at the given index if present; else returns nullptr
/// 
Brood::BroodUI::Id* Brood::BroodUI::Id::GetChildIdAtIdx( const int a_index ) const
{
	if( a_index < 0 || a_index > ( m_allChildPtrs.size() - 1 ) )
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

///
/// @public
/// @brief Setter function to set the element's parent
/// 
/// @param a_parentID pointer to the parent element id object
/// 
void Brood::BroodUI::Id::SetParent( Brood::BroodUI::Id* a_parentID )
{
	m_parentID = a_parentID != nullptr ? a_parentID->GetElementID() : -1;
}

///
/// @public
/// @brief adds the child to its child list
/// 
/// @param a_childIdPtr pointer to the child id
/// 
void Brood::BroodUI::Id::AddChild( Brood::BroodUI::Id* a_childIdPtr )
{
	m_allChildPtrs.push_back( a_childIdPtr );
	m_hasChilds = true;
}

///
/// @public
/// @brief deletes the child at passed a_index from the child list
/// 
/// @param a_index index child's pointer in the child list to be deleted
/// 
void Brood::BroodUI::Id::DeleteChildIdAtIdx( const int a_index )
{
	if( m_allChildPtrs.size() == NULL )
	{
		// child list is empty. 
		std::cerr << "Error! Cannot erase as the child list is empty." << std::endl;
		return;
	}
	else if( a_index < 0 || a_index > ( int )m_allChildPtrs.size() - 1 )
	{
		// trying to delete invalid index
		std::cerr << "Error! Tying to erase invalid index" << std::endl;
		return;
	}

	// delete the index
	std::vector<Brood::BroodUI::Id*>::iterator elementToDelete = m_allChildPtrs.begin() + a_index;
	m_allChildPtrs.erase( elementToDelete, elementToDelete + 1 );

	// if the child list is empty then setting has child as false
	m_hasChilds = !m_allChildPtrs.empty();
}

// ======================================================================
// ====================== end of ID class ===============================
// ======================================================================