/*************************************************************************/
/// 
/// @file UI_ID.h 
/// 
/// @brief  This file is a header file for Id class 
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of Id class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Id class
///
/************************************************************************/

#pragma once

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		class Id;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class Id  "Id.h"
/// @brief The Id class generates a unique id for a elements and 
///		keeps track of its parent
/// 
class Brood::BroodUI::Id
{
	// ================= public member function =================  
public:
	Id( Id* a_parentID = nullptr, int a_index = -1 ); // default constructor;

	// getter functions
	const int GetParentID() const; // returns its parent id;
	const int GetElementID() const; // returns its id
	const int GetIdIndex() const; // returns its index relative to its parent
	const int GetTotalChildNum() const; // returns number of its child
	const Id* GetChildIdAtIdx( const int a_index ) const;
	bool HasChild() const;
	bool HasParent() const;

	void AddChild( const Brood::BroodUI::Id* a_childIdPtr ); // adds child to its child list
	void DeleteChildIdAtIdx( const int a_index ); // removes the child id at suppled index

	// ================= private member variables =================  
private:
	const int m_parentID; // stores the parents UI ID

	const int m_elementID; // stores its UI ID
	int m_index; // stores its hirecical index; relative to its parent
	bool m_hasChilds; // stores if it has childs or not
	std::vector<const Brood::BroodUI::Id*> m_allChildPtrs; // stores all the pointer to its childs 
	static unsigned GLOBAL_ID_NUM; // unique id is assigned based on this
};

// ====================== declaration of Id member functions =======================

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
inline Brood::BroodUI::Id::Id( Id* a_parentID, int a_index ) :
	m_parentID( (a_parentID != nullptr) ? a_parentID->GetElementID() : -1 ),
	m_elementID( GLOBAL_ID_NUM++ ), m_index( ( a_parentID != nullptr ) ? a_index : -1 ),
	m_hasChilds( false )
{}


///
/// @public
/// @brief Getter function to get the parent's ID
/// 
/// @note if the element has no parent then the parent Id returned is -1
///
/// @return parent's unique UI ID
/// 
inline const int Brood::BroodUI::Id::GetParentID() const
{
	return m_parentID;
}

///
/// @public
/// @brief Getter function to get the element's ID
/// 
/// @return element's unique UI ID
/// 
inline const int Brood::BroodUI::Id::GetElementID() const
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
inline const int Brood::BroodUI::Id::GetIdIndex() const
{
	return m_index;
}

///
/// @public
/// @brief Getter function to get how many child the element has
/// 
/// @return element's child list size
/// 
inline const int Brood::BroodUI::Id::GetTotalChildNum() const
{
	return m_allChildPtrs.size();
}

///
/// @public
/// @brief Getter function to check if the element has a child or not
/// 
/// @return true if the element has child/s; else returns false
/// 
inline bool Brood::BroodUI::Id::HasChild() const
{
	return m_hasChilds;
}

///
/// @public
/// @brief Getter function to check if the element has a parent or not
/// 
/// @return true if the element has parent; else returns false
/// 
inline bool Brood::BroodUI::Id::HasParent() const
{
	return m_parentID != -1;
}

///
/// @public
/// @brief adds the child to its child list
/// 
/// @param a_childIdPtr const pointer to the child id
/// 
inline void Brood::BroodUI::Id::AddChild( const Brood::BroodUI::Id* a_childIdPtr )
{
	m_allChildPtrs.push_back( a_childIdPtr );
}

