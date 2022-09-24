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
// ====================== end of namespace defination ===================
// ======================================================================

// ======================================================================
// ====================== start of ID class =============================
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
	// default constructor
	Id( Id* a_parentIDPtr = nullptr );

	
	// default destrutor
	~Id( );

	// copy constructor
	Id(const Id& a_otherId);

	// assignment operator
	Id& operator=(const Id& a_otherId);

	// getter functions
	
	// returns its parent id;
	const int GetParentID() const;

	// returns Parent Id Ptr
	const Brood::BroodUI::Id* GetParentIDPtr() const;

	// returns Parent Id Ptr
	Brood::BroodUI::Id* GetParentIDPtr();

	// returns its id
	const int GetElementID() const;
	
	// returns the child index in the list
	const int GetChildIdx( const Brood::BroodUI::Id* a_childIDPtr ) const;

	// returns total number of its child
	const int GetTotalChildNum() const;

	// returns child at the passed index
	Id* GetChildIdAtIdx( const int a_index ) const;

	// returns true if it has a child 
	bool HasChild() const;

	// returns true if it has a parent
	bool HasParent() const;

	// setter functions
	
	// sets parent
	void SetParent( Id* a_parentID = nullptr ); 

	// adds child to its child list
	void AddChild( Brood::BroodUI::Id* a_childIdPtr ); 

	// removes the child at passed index
	void DeleteChildIdAtIdx( const int a_index ); 

	// ================= private member variables =================  
private:
	/// unique id is assigned based on this
	static unsigned GLOBAL_ID_NUM; 
	
	/// stores the parents UI ID pointer
	Brood::BroodUI::Id* m_parentIDPtr; 

	/// stores the parents UI ID
	int m_parentID; 
	
	/// stores its UI ID
	int m_elementID; 

	/// stores if it has childs or not
	bool m_hasChilds; 

	/// stores all the pointer to its childs 
	std::vector<Brood::BroodUI::Id*> m_allChildPtrs;
};

// ======================================================================
// ====================== end of ID class =======================
// ======================================================================