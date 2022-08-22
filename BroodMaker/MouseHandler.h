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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	// defining what component of this file will be inside namespace BroodUI
	class MouseHandler;
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of MouseHandler class ========================
// ======================================================================
///
/// @ingroup Brood
/// @static 
/// @class MouseHandler  "MouseHandler.h"
/// @brief A class to handeler all mouse changes
/// 
class Brood::MouseHandler
{
	// ================= public member function =================  
public:
	/// 
	/// @enum
	/// @brief lists all the valid cursor type used
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
	static bool GetlastFrameLMSStatus();
	static bool GetCurrFrameLMSStatus();
	static bool GetCurrFrameRMSStatus();
	static bool GetlastFrameRMSStatus();

	// setter function
	static void UpdateMouseButtonStatus( );
	
	static bool IsLeftButtonHold();
	static bool IsLeftButtonPressed();
	static bool IsLeftButtonReleased();

	static bool IsRightButtonHold();
	static bool IsRightButtonPressed();
	static bool IsRightButtonReleased();

	// ================= private member variables =================  
private:
	static sf::Cursor m_cursor;

	static sf::Vector2i m_lastFrameMousePos;
	static sf::Vector2i m_currFrameMousePos;

	static bool m_lastFrameLeftMouseButtonPressed; // true == was pressed
	static bool m_lastFrameRightMouseButtonPressed; // true == was pressed
	static bool m_currFrameLeftMouseButtonPressed; // true == was pressed
	static bool m_currFrameRightMouseButtonPressed; // true == was pressed
};

// ======================================================================
// ================= end of MouseHandler class ==========================
// ======================================================================