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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once

// ======================================================================
// ===================== defining namespace =============================
// ======================================================================
namespace Brood
{
	///
	/// @ingroup Brood
	/// @addtogroup BroodUI
	///
	namespace BroodUI
	{
		class Id;
	}
}
// ======================================================================
// ====================== end of namespace defination ========================
// ======================================================================

// ======================================================================
// ====================== start of ID class =======================// ======================================================================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class Id  "Id.h"
/// @brief Class to provide a unique ID to the different UI elements.
/// 
/// All the UI elements has a unique ID. The Id class also  keeps track
///		of its parent and childs. This ID system is the core of the
///		intermediate GUI method. This ID helps us to keep track of which 
///		element is selected, or about to be selected and what action we 
///		should take
/// 
class Brood::BroodUI::Id
{
	// ================= public member function =================  
public:
	Id( Id* a_parentID = nullptr ); // default constructor;

	// getter functions
	const int GetParentID() const; // returns its parent id;
	const int GetElementID() const; // returns its id
	const int GetChildIdx( const Brood::BroodUI::Id* a_childIDPtr ) const; // returns the child index in the list
	const int GetTotalChildNum() const; // returns total number of its child
	Id* GetChildIdAtIdx( const int a_index ) const; // returns child at the passed index

	bool HasChild() const; // returns true if it has a child 
	bool HasParent() const; // returns true if it has a parent
	
	// setter functions
	void SetParent( Id* a_parentID = nullptr ); // sets parent
	
	void AddChild( Brood::BroodUI::Id* a_childIdPtr ); // adds child to its child list
	void DeleteChildIdAtIdx( const int a_index ); // removes the child at passed index

	// ================= private member variables =================  
private:
	static unsigned GLOBAL_ID_NUM; ///> unique id is assigned based on this
	int m_parentID; ///> stores the parents UI ID
	int m_elementID; ///> stores its UI ID
	bool m_hasChilds; ///> stores if it has childs or not
	std::vector<Brood::BroodUI::Id*> m_allChildPtrs; ///> stores all the pointer to its childs 
};

// ======================================================================
// ====================== end of ID class =======================
// ======================================================================