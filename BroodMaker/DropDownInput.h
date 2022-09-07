/*************************************************************************/
/// 
/// @file DropDownInput.h 
/// 
/// @brief  This file is a header file for DropDownInput class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DropDownInput class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "DropDownMenu.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class DropDownInput;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DropDownInput class ========================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class DropDownInput  "DropDownInput.h"
/// @brief A UI elemnt that represent a drop down menu. 
/// 
/// A class derived from DropDownMenu class. 
///		It contains a list of menus inside a single element.
///		The list of items are left aligned and below the menu title.
///		the size of the items is depended on the longest item name.
/// 
/// This class differes from the DropDownMenu class as for this class 
///		the title that is used in DropDownMenu is changed to relfect the 
///		selected item.
/// 
/// ### Example Case
/// 
class  Brood::BroodUI::DropDownInput : public Brood::BroodUI::DropDownMenu
{
	// ============ public member function =============== 
public:
	// default constructor
	DropDownInput( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
				   Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_dropDownInput );
	// default destructor
	virtual ~DropDownInput();

	void AddItemToMenu( std::string a_menuName, sf::Color a_color = Brood::ST_ColorVariables::stm_White ); // adds item to menu
};

