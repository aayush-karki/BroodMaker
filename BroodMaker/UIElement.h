/*************************************************************************/
/// 
/// @file UIElement.h 
/// 
/// @brief  This file is a header file for UIElement class.
/// 
/// This is a abstract base class that is parent to all the different 
///		UI elments 
/// 
/// It contains all of the declaration of the member 
///		funciton of Board class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Board class
///
/************************************************************************/

#pragma once

namespace Brood
{

	///
	/// @ingroup Brood
	/// @addtogroup BroodUI
	/// @brief contains the UI used by BroodMaker
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

		class UIElement
		{};

	}
}