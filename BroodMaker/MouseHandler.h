/*************************************************************************/
/// 
/// @file MouseHandler.h 
/// 
/// @brief  This file is a header file for MouseHandler class.
/// 
/// It contains all of the declaration of the member 
///		funciton of MouseHandler class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of MouseHandler class
///
/************************************************************************/

#pragma once
#include "UIElement.h"

namespace Brood
{
	///
	/// @static 
	/// @class MouseHandler  "MouseHandler.h"
	/// @brief A class to handeler all mouse changes
	/// 
	class MouseHandler
	{
		// ================= public member function =================  
	public:
		/// 
		/// @enum
		/// @brief lists all the valid cursor type used
		/// 
		/// 
		enum class ENUM_MouseCursorType
		{
			CURSOR_arrow, ///> default cursor
			CURSOR_wait, ///> busy cursor
			CURSOR_text, ///> I-beam cursor, when hovering overa field allowing text entry
			CURSOR_hand, ///> Pointing hand cursor
			CURSOR_sizeHorizontal, ///> horizontal cursor with arrow head at both ends 
			CURSOR_help, ///> help cursor with ? on it
			CURSOR_notAllowed ///> action not allowed cursor
		};

		static void InitializeCursor( sf::RenderWindow& a_window );
		static void UpdateMousePos( sf::RenderWindow& a_window ); // updates the mouse pos
		
		static void ChangeCursorTo( sf::RenderWindow& a_window, 
									const Brood::MouseHandler::ENUM_MouseCursorType a_cursorType );

		// getter function
		static sf::Vector2i GetLastFrameMousePos();
		static sf::Vector2i GetCurrFrameMousePos();

		static bool IsButtonPressed( sf::Mouse::Button 	button ); // returns true if button was pressed
		static bool IsHit(BroodUI::UIElement* a_uiElementPtr); /// @todo define the function 

		// ================= private data amember =================  
	private:
		static sf::Cursor m_cursor;

		static sf::Vector2i m_lastFrameMousePos;
		static sf::Vector2i m_currFrameMousePos;
	};
}

/// 
/// @static
/// @public
/// @brief Getter function to get the currrent frame mouse position
/// @return  currrent frame mouse position
/// 
inline sf::Vector2i Brood::MouseHandler::GetCurrFrameMousePos()
{
	return m_currFrameMousePos;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the last frame mouse position
/// @return  last frame mouse position
/// 
inline sf::Vector2i Brood::MouseHandler::GetLastFrameMousePos()
{
	return m_lastFrameMousePos;
}

/// 
/// @static
/// @public
/// @brief Check if the button specified was pressed or not
/// @param button 
/// @return 
inline bool Brood::MouseHandler::IsButtonPressed( sf::Mouse::Button button )
{
	return sf::Mouse::isButtonPressed( button );
}

inline bool Brood::MouseHandler::IsHit( BroodUI::UIElement* a_uiElementPtr )
{
	return false;
}
