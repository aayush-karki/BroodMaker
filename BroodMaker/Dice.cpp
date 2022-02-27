/*************************************************************************/
/// 
/// @file Dice.h 
/// 
/// @brief  This file is a source file for Dice class.
/// 
/// It contains all of the defination of the member 
///		funciton of Dice class.
///
/************************************************************************/

#include "Dice.h"

/// 
/// @public
/// @brief Draw funciton draws dice to the screen.
///			
/// @param a_window reference to the render window
/// 
void Dice::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_diceBody );
}

/// 
/// @private
/// @brief Initializes the Dice
/// 
/// @param a_diceSizeX dice's width -> default 0.f
/// @param a_diceSizeY dice's length -> default 0.f
/// @param a_dicePosX dice's x-position on the screen;
///			relative to the render window -> default 0.f
/// @param a_dicePosY dice's y-position on the screen;
///			relative to the render window -> default 0.f
/// @param a_numSides number of a side that the dice has;
///			-> default 6
///
void Dice::InitializeDice( float a_diceSizeX, float a_diceSizeY, float a_dicePosX, float a_dicePosY, int a_numSides )
{
	m_numSides = a_numSides;

	this->m_diceBody.setSize( sf::Vector2f( a_diceSizeX, a_diceSizeY ) );
	this->m_diceBody.setPosition( a_dicePosX, a_dicePosY );
	this->m_diceBody.setFillColor( sf::Color::Magenta );
}


