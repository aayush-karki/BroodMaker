/*************************************************************************/
/// 
/// @file MouseHandler.cpp 
/// 
/// @brief  This file is a source file for MouseHandler class.
/// 
/// It contains all of the defination of the member 
///		funciton of MouseHandler class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "MouseHandler.h"
#include "UtilityFunctions.h"


// declaring the staic data member
sf::Cursor Brood::MouseHandler::m_cursor;
sf::Vector2i Brood::MouseHandler::m_currFrameMousePos;
sf::Vector2i Brood::MouseHandler::m_lastFrameMousePos;

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
		case (ENUM_MouseCursorType::CURSOR_text ):
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
