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
Brood::Dice::Dice( int a_numSides, Brood::BroodUI::UIElement* a_parentPtr,
				   int a_index ) :
	Brood::BroodUI::Button( a_parentPtr, a_index ),
	m_numSides( a_numSides )
{
	m_spriteLength = 0.0;
	m_texturePath = "";
}

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
				   Brood::BroodUI::UIElement* a_parentPtr, int a_index ) :
	Brood::BroodUI::Button( a_parentPtr, a_index ), m_numSides( a_numSides ),
	m_texturePath( a_texturePath ), m_spriteLength( a_spriteLength )
{};

Brood::Dice::Dice( Brood::St_DiceParam& a_diceParam ) :
	Dice( a_diceParam.stm_texturePath, a_diceParam.stm_spriteLength,
		  a_diceParam.stm_numSides, a_diceParam.stm_parentPtr,
		  a_diceParam.stm_index )
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
/// @brief sets the texture from the file path 
/// 
/// It also saves the textureFilepath
/// 
/// @param a_texturePath file path to to the texture containing face of the dice;
/// 
/// @return returns true if texture was successfully set; else false
/// 
bool Brood::Dice::SetTextureFromFilePath( std::string a_texturePath )
{
	// open texture
	if( !Brood::UtilityFuncs::LoadTextureFromFile( m_texture, a_texturePath ) )
	{
		return false;
	}
	// saving the texture path
	m_texturePath = a_texturePath; 
	
	// setting the texture
	m_body.setTexture( &m_texture );
	Brood::Dice::SetSpriteFromTexture( 0 );

	return true;
}


