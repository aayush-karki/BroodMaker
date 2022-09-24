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

	// initializes the cursor
	static void InitializeCursor( sf::RenderWindow& a_window );

	// updates the mouse pos
	static void UpdateMousePos( sf::RenderWindow& a_window );

	// changes the cursor to the specified cursor
	static void ChangeCursorTo( sf::RenderWindow& a_window,
								const Brood::MouseHandler::ENUM_MouseCursorType a_cursorType );

	// ====== getter function ======

	// gets the mosuse position on last frame
	static sf::Vector2i GetLastFrameMousePos();

	// gets the mosuse position on current frame
	static sf::Vector2i GetCurrFrameMousePos();

	// gets the left mouse button status on last frame
	// i.e. is if it was pressed or not
	static bool GetlastFrameLMSStatus();

	// gets the left mouse button status on current frame
	// i.e. is if it is pressed or not
	static bool GetCurrFrameLMSStatus();

	// gets the right mouse button status on last frame
	// i.e. is if it was pressed or not
	static bool GetlastFrameRMSStatus();

	// gets the right mouse button status on current frame
	// i.e. is if it is pressed or not
	static bool GetCurrFrameRMSStatus();

	//Updates mouse button status and saves the mouse 
	// button status for this frame and last frame
	static void UpdateMouseButtonStatus();

	// checkes to see if the left mouse button is held or not
	static bool IsLeftButtonHold();

	// checkes to see if the left mouse button is pressed or not
	static bool IsLeftButtonPressed();

	// checkes to see if the left mouse button is released or not
	static bool IsLeftButtonReleased();

	// checkes to see if the right mouse button is held or not
	static bool IsRightButtonHold();

	// checkes to see if the right mouse button is pressed or not
	static bool IsRightButtonPressed();

	// checkes to see if the right mouse button is released or not
	static bool IsRightButtonReleased();

	// debugger
	static void Debugger();

	// ================= private member variables =================  
private:
	// holds the cursor to display
	static sf::Cursor m_cursor;

	// stores the last frame mouse position
	static sf::Vector2i m_lastFrameMousePos;

	// stores the current frame mouse position
	static sf::Vector2i m_currFrameMousePos;

	// holds left mouse button state for last frame, true == was pressed
	static bool m_lastFrameLeftMouseButtonPressed;

	// holds right mouse button state for last frame, true == was pressed
	static bool m_lastFrameRightMouseButtonPressed;

	// holds left mouse button state for current frame, true == was pressed
	static bool m_currFrameLeftMouseButtonPressed; 
	
	// holds right mouse button state for current frame, true == was pressed
	static bool m_currFrameRightMouseButtonPressed;
};

// ======================================================================
// ================= end of MouseHandler class ==========================
// ======================================================================