/*************************************************************************/
/// 
/// @file UI_ID.h 
/// 
/// @brief  This file is a header file for Id class 
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of Id class.
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
	Id( Id* a_parentID = nullptr ); // default constructor;

	// getter functions
	const int GetParentID() const; // returns its parent id;
	const int GetElementID() const; // returns its id
	const int GetChildIdx( const Brood::BroodUI::Id* a_childIDPtr ) const; // returns its index relative to its parent
	const int GetTotalChildNum() const; // returns number of its child
	Id* GetChildIdAtIdx( const int a_index ) const;

	bool HasChild() const;
	bool HasParent() const;
	
	void SetParent( Id* a_parentID = nullptr );
	
	void AddChild( Brood::BroodUI::Id* a_childIdPtr ); // adds child to its child list
	void DeleteChildIdAtIdx( const int a_index ); // removes the child id at suppled index

	// ================= private member variables =================  
private:
	int m_parentID; // stores the parents UI ID
	int m_elementID; // stores its UI ID
	bool m_hasChilds; // stores if it has childs or not
	std::vector<Brood::BroodUI::Id*> m_allChildPtrs; // stores all the pointer to its childs 
	static unsigned GLOBAL_ID_NUM; // unique id is assigned based on this
};
