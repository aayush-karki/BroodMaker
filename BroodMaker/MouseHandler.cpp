/*************************************************************************/
/// 
/// @file MouseHandler.cpp 
/// 
/// @brief This file is a source file for MouseHandler class.
/// 
/// It contains all of the defination of the member 
///		funciton of MouseHandler class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "MouseHandler.h"
#include "UtilityFunctions.h"

// ======================================================================
// ================= start of MouseHandler class ========================
// ======================================================================

// declaring the staic data member

sf::Cursor Brood::MouseHandler::m_cursor;
sf::Vector2i Brood::MouseHandler::m_currFrameMousePos;
sf::Vector2i Brood::MouseHandler::m_lastFrameMousePos;
bool Brood::MouseHandler::m_lastFrameLeftMouseButtonPressed;
bool Brood::MouseHandler::m_lastFrameRightMouseButtonPressed;
bool Brood::MouseHandler::m_currFrameLeftMouseButtonPressed;
bool Brood::MouseHandler::m_currFrameRightMouseButtonPressed;

/// 
/// @static
/// @public
/// @brief Initializes the cursor and sets it for the window
/// 
/// @param a_window reference to the render window
/// 
void Brood::MouseHandler::InitializeCursor( sf::RenderWindow& a_window )
{
	ChangeCursorTo( a_window, ENUM_MouseCursorType::CURSOR_arrow );
}

///
/// @static
/// @public 
/// @brief a static function to keep track of the mouse Position
/// 
/// It keep track of mouse position last frame and this frame
/// 
/// @param a_window reference to the render window
/// 
void Brood::MouseHandler::UpdateMousePos( sf::RenderWindow& a_window )
{
	// setting the lastFrameMousePos to curr MousePos
	MouseHandler::m_currFrameMousePos = sf::Mouse::getPosition( a_window );
	MouseHandler::m_lastFrameMousePos = m_currFrameMousePos;
}

///
/// @static
/// @public 
/// @brief changes the cursor to specifed cursor type
/// 
/// @param a_window reference to render window
/// @param a_cursorType cursor type to change to 
/// 
void Brood::MouseHandler::ChangeCursorTo( sf::RenderWindow& a_window,
										  const Brood::MouseHandler::ENUM_MouseCursorType a_cursorType )
{
	// change the cursor according to the specified type
	switch( a_cursorType )
	{
		case ( ENUM_MouseCursorType::CURSOR_arrow ):
		{
			m_cursor.loadFromSystem( sf::Cursor::Arrow );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_wait ):
		{
			m_cursor.loadFromSystem( sf::Cursor::Wait );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_text ):
		{
			m_cursor.loadFromSystem( sf::Cursor::Text );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_hand ):
		{
			m_cursor.loadFromSystem( sf::Cursor::Hand );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_sizeHorizontal ):
		{
			m_cursor.loadFromSystem( sf::Cursor::SizeHorizontal );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_help ):
		{
			m_cursor.loadFromSystem( sf::Cursor::Help );
			break;
		}
		case ( ENUM_MouseCursorType::CURSOR_notAllowed ):
		{
			m_cursor.loadFromSystem( sf::Cursor::NotAllowed );
			break;
		}
	}

	// update the window's cursor 
	a_window.setMouseCursor( m_cursor );
}


/// 
/// @static
/// @public
/// @brief Getter function to get the last frame mouse position
/// @return  last frame mouse position
/// 
sf::Vector2i Brood::MouseHandler::GetLastFrameMousePos()
{
	return m_lastFrameMousePos;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the currrent frame mouse position
///
/// @return  currrent frame mouse position
/// 
sf::Vector2i Brood::MouseHandler::GetCurrFrameMousePos()
{
	return m_currFrameMousePos;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the last frame left mouse 
///		button press status
///
/// @return  currrent last frame left mouse button press status
/// 
bool Brood::MouseHandler::GetlastFrameLMSStatus()
{
	return m_lastFrameLeftMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the current frame left mouse 
///		button press status
///
/// @return  currrent current frame left mouse button press status
/// 
bool Brood::MouseHandler::GetCurrFrameLMSStatus()
{
	return m_currFrameLeftMouseButtonPressed;
}

/// /// 
/// @static
/// @public
/// @brief Getter function to get the last frame right mouse 
///		button press status
///
/// @return  currrent last frame right mouse button press status
/// 
bool Brood::MouseHandler::GetlastFrameRMSStatus()
{
	return m_lastFrameRightMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Getter function to get the current frame right mouse 
///		button press status
///
/// @return  currrent current frame right mouse button press status
/// 
bool Brood::MouseHandler::GetCurrFrameRMSStatus()
{
	return m_currFrameRightMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief  Updates mouse button status and saves the mouse button status 
///		for this frame and last frame
/// 
/// @note only consideres left and right mouse button
/// 
void Brood::MouseHandler::UpdateMouseButtonStatus()
{
	// save the current state
	m_lastFrameLeftMouseButtonPressed = m_currFrameLeftMouseButtonPressed;
	m_lastFrameRightMouseButtonPressed = m_currFrameRightMouseButtonPressed;

	// checking if it was press or release event
	if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
	{
		m_currFrameLeftMouseButtonPressed = true;
	}
	else
	{
		m_currFrameLeftMouseButtonPressed = false;
	}

	// checking if it was press or release event
	if( sf::Mouse::isButtonPressed( sf::Mouse::Right ) )
	{
		m_currFrameRightMouseButtonPressed = true;
	}
	else
	{
		m_currFrameRightMouseButtonPressed = false;
	}
}

/// 
/// @static
/// @public
/// @brief Check if the left mouse button is in hold state
/// 
/// @return  true if the left mouse button is in hold state
/// 
bool Brood::MouseHandler::IsLeftButtonHold()
{
	return m_lastFrameLeftMouseButtonPressed && m_currFrameLeftMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Check if the left mouse button is pressed or not
/// 
/// @return  true if the left mouse button is pressed
/// 
bool Brood::MouseHandler::IsLeftButtonPressed()
{
	return !m_lastFrameLeftMouseButtonPressed && m_currFrameLeftMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Check if the left mouse button is released or not
/// 
/// @return  true if the left mouse button is released
/// 
bool Brood::MouseHandler::IsLeftButtonReleased()
{
	return m_lastFrameLeftMouseButtonPressed && !m_currFrameLeftMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Check if the right mouse button is in hold state
/// 
/// @return  true if the right mouse button is in hold state
/// 
bool Brood::MouseHandler::IsRightButtonHold()
{
	return m_lastFrameRightMouseButtonPressed && m_currFrameRightMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Check if the right mouse button is pressed or not
/// 
/// @return  true if the right mouse button is pressed
/// 
bool Brood::MouseHandler::IsRightButtonPressed()
{
	return !m_lastFrameRightMouseButtonPressed && m_currFrameRightMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Check if the right mouse button is released or not
/// 
/// @return  true if the rrght mouse button is released
/// 
bool Brood::MouseHandler::IsRightButtonReleased()
{
	return m_lastFrameRightMouseButtonPressed && !m_currFrameRightMouseButtonPressed;
}

/// 
/// @static
/// @public
/// @brief Prints the mouse states like button press and current position
///
void Brood::MouseHandler::Debugger()
{
	// printing the mouse pos
	std::cout << "Current Frame Mouse X position: " << m_currFrameMousePos.x << std::endl;
	std::cout << "Current Frame Mouse Y position: " << m_currFrameMousePos.y << std::endl;
	std::cout << std::endl;
	std::cout << "Last Frame Mouse X position: " << m_lastFrameMousePos.x << std::endl;
	std::cout << "Last Frame Mouse Y position: " << m_lastFrameMousePos.y << std::endl;
	std::cout << std::endl;

	// printing the left mouse state
	std::cout << "LMB hold " << std::boolalpha << IsLeftButtonHold() << std::endl;
	std::cout << "LMB pressed " << std::boolalpha << IsLeftButtonPressed() << std::endl;
	std::cout << "LMB released " << std::boolalpha << IsLeftButtonReleased() << std::endl;
	std::cout << std::endl;

	// printing the right mouse state
	std::cout << "RMB hold " << std::boolalpha << IsRightButtonHold() << std::endl;
	std::cout << "RMB pressed " << std::boolalpha << IsRightButtonPressed() << std::endl;
	std::cout << "RMB released " << std::boolalpha << IsRightButtonReleased() << std::endl;
	std::cout << std::endl;
}

// ======================================================================
// ================= end of MouseHandler class ==========================
// ======================================================================