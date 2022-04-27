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

#include "stdafx.h"
#include "Dice.h"

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the button object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// @param a_numSides number of a side that the dice has;
///			-> default 6
/// 
Brood::Dice::Dice( int a_numSides, Brood::BroodUI::UIElement* a_parentPtr) :
	Brood::Dice::Dice( "", 0.0, a_numSides, a_parentPtr ) 
{}

/// 
/// @public
/// @overload
/// @brief Initializes the butoon object
/// 
/// 
/// @warning The sprite for the face of the should be lined linearly.
///		That is only one row of sprite should be present.
/// @warning Assumus that the sprites are square. 
/// 
/// This contructor is called when a texture is passed is passed 
/// 
/// @param a_texturePath file path to to the texture containing face of the dice;
///		it is a single texture that has texture for num faces of the dice
/// @parem a_spriteLength width of the single sprite
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// @param a_numSides number of a side that the dice has;
///			-> default 6
/// 
Brood::Dice::Dice( std::string a_texturePath, float a_spriteLength,
				   int a_numSides,
				   Brood::BroodUI::UIElement* a_parentPtr ) :
	Brood::BroodUI::Button( a_parentPtr), m_numSides( a_numSides )
{
	// settomg sprite height and length 
	SetSpriteLength( a_spriteLength );
	SetSpriteHeight( a_spriteLength );

	// loading the texture
	SetTextureFromFilePath( a_texturePath );

};

Brood::Dice::Dice( Brood::St_DiceParam& a_diceParam ) :
	Dice( a_diceParam.stm_texturePath, a_diceParam.stm_spriteLength,
		  a_diceParam.stm_numSides, a_diceParam.stm_parentPtr)
{}

Brood::Dice::~Dice()
{}


/// 
/// @public
/// @brief Draw funciton draws dice to the screen.
///			
/// @param a_window reference to the render window
/// 
void Brood::Dice::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::Button::Draw( a_window );
}

/// 
/// @public
/// @brief Rolls the dice to get a number between 0 and m_numSides
/// 
/// @return random number between 0 and m_numSides
/// 
 unsigned Brood::Dice::RollDice()
{

	unsigned currRoll = std::rand() % m_numSides;
	return currRoll + 1;
}
