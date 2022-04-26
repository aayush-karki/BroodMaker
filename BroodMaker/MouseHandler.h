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

// =============================== defining namespace =======================
namespace Brood
{
	// defining what component of this file will be inside namespace BroodUI
	class MouseHandler;
}
// ======================= end of namespace  defination =======================

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
	//static bool UpdateMouseStatus();
	
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

	static bool m_lastFrameLeftMouseButtonStatus; // true == was pressed
	static bool m_lastFrameRightMouseButtonStatus; // true == was pressed
	static bool m_currFrameLeftMouseButtonStatus; // true == was pressed
	static bool m_currFrameRightMouseButtonStatus; // true == was pressed
};


/// 
/// @static
/// @public
/// @brief Getter function to get the currrent frame mouse position
///
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
/// @brief Getter function to get the last frame left mouse 
///		button press status
///
/// @return  currrent last frame left mouse button press status
/// 
inline bool Brood::MouseHandler::GetlastFrameLMSStatus()
{
	return m_lastFrameLeftMouseButtonStatus;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the current frame left mouse 
///		button press status
///
/// @return  currrent current frame left mouse button press status
/// 
inline bool Brood::MouseHandler::GetCurrFrameLMSStatus()
{
	return m_currFrameLeftMouseButtonStatus;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the last frame right mouse 
///		button press status
///
/// @return  currrent last frame right mouse button press status
/// 
inline bool Brood::MouseHandler::GetlastFrameRMSStatus()
{
	return m_lastFrameRightMouseButtonStatus;
}


/// 
/// @static
/// @public
/// @brief Getter function to get the current frame right mouse 
///		button press status
///
/// @return  currrent current frame right mouse button press status
/// 
inline bool Brood::MouseHandler::GetCurrFrameRMSStatus()
{
	return m_currFrameRightMouseButtonStatus;
}

/// 
/// @static
/// @public
/// @brief Check if the left mouse button is in hold state
/// 
/// @return  true if the left mouse button is in hold state
/// 
inline bool Brood::MouseHandler::IsLeftButtonHold()
{
	return m_lastFrameLeftMouseButtonStatus && m_currFrameLeftMouseButtonStatus;
}


/// 
/// @static
/// @public
/// @brief Check if the left mouse button is pressed or not
/// 
/// @return  true if the left mouse button is pressed
/// 
inline bool Brood::MouseHandler::IsLeftButtonPressed()
{
	return !m_lastFrameLeftMouseButtonStatus && m_currFrameLeftMouseButtonStatus;
}

/// 
/// @static
/// @public
/// @brief Check if the left mouse button is released or not
/// 
/// @return  true if the left mouse button is released
/// 
inline bool Brood::MouseHandler::IsLeftButtonReleased()
{
	return m_lastFrameLeftMouseButtonStatus && !m_currFrameLeftMouseButtonStatus;
}
/// 
/// @static
/// @public
/// @brief Check if the right mouse button is in hold state
/// 
/// @return  true if the right mouse button is in hold state
/// 
inline bool Brood::MouseHandler::IsRightButtonHold()
{
	return m_lastFrameRightMouseButtonStatus && m_currFrameRightMouseButtonStatus;
}


/// 
/// @static
/// @public
/// @brief Check if the right mouse button is pressed or not
/// 
/// @return  true if the right mouse button is pressed
/// 
inline bool Brood::MouseHandler::IsRightButtonPressed()
{
	return !m_lastFrameRightMouseButtonStatus && m_currFrameRightMouseButtonStatus;
}

/// 
/// @static
/// @public
/// @brief Check if the right mouse button is released or not
/// 
/// @return  true if the rrght mouse button is released
/// 
inline bool Brood::MouseHandler::IsRightButtonReleased()
{
	return m_lastFrameRightMouseButtonStatus && !m_currFrameRightMouseButtonStatus;
}
