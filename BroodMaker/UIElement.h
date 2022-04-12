/*************************************************************************/
/// 
/// @file UIElement.h 
/// 
/// @brief  This file is a header file for UIElement class.
/// 
/// This is a abstract base class that is parent to all the different 
///		UI elements 
/// 
/// It contains all of the declaration of the member 
///		funciton of Board class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Board class
///
/************************************************************************/

#pragma once
#include "UI_ID.h"

namespace Brood
{

	///
	/// @ingroup Brood
	/// @addtogroup BroodUI
	/// @brief scopes the UI used by BroodMaker
	/// 
	namespace BroodUI
	{
		/// 
		/// @ingroup BroodUI
		/// @enum ENUM_UIType
		/// @brief list all the different ui elements
		///
		enum class ENUM_UIType
		{
			UI_text, ///< stores a text; user-typed text or predefined text
			UI_textBox, ///< container for editText

			UI_button, ///< a button
			UI_dropDownMenu, ///< drop down menu; has items inside it 
			UI_scrollBar
		};

		/// 
		/// @ingroup BroodUI
		/// @class UIElement  "UIElement.h"
		/// @brief a abstract base class that is parent to all the different 
		///		UI elements 
		/// 
		class UIElement
		{

			// ================= public member function =================  
			UIElement(); // default constructor
			virtual ~UIElement(); // virtual default destructor

			virtual bool ProcessMouseDown(sf::Mouse::Button a_button) = 0; // called in the event that mouse button is pressed
			virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) = 0; // called in the event that mouse button is released
			// ================= private member function =================  

			// ================= private data member =================  
			ENUM_UIType m_elementType; // stores the type of element stored
			Brood::BroodUI::Id m_elementId; // uniqie id of the element
		};

	}
}