/*************************************************************************/
/// 
/// @file DropDownMenu.h 
/// 
/// @brief  This file is a header file for DropDownMenu class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DropDownMenu class.
///
/************************************************************************/
#pragma once

#include "UIElement.h"
#include "TextBox.h"

// =============================== defining namespace =======================
namespace Brood
{
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		class DropDownMenu;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup BroodUI
/// @class DropDownMenu  "DropDownMenu.h"
/// @brief a uielemnt that represent drop down menu. Contains a list of
///		menus inside a single item
/// 
/// A class derived from UI elements class.
/// 
class DropDownMenu
{
	// ============ public member function =============== 
	// default constructor
	DropDownMenu( Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 );
	// default destructor
	virtual ~DropDownMenu();

	// ============ private member variables ===============
	std::vector<Brood::BroodUI::TextBox*> m_items; // stores the list of menus
	bool m_isSelected; // true if it is currActive

};

