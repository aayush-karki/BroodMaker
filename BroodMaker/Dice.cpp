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
Brood::Application::Components::Dice::Dice( int a_numSides, Brood::BroodUI::UIElement* a_parentPtr ) :
	Brood::Application::Components::Dice::Dice( "", a_numSides, a_parentPtr )
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
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// @param a_numSides number of a side that the dice has;
///			-> default 6
/// 
Brood::Application::Components::Dice::Dice( std::string a_texturePath,
											int a_numSides,
											Brood::BroodUI::UIElement* a_parentPtr ) :
	Brood::BroodUI::Button( a_parentPtr ), m_numSides( a_numSides )
{
	SetBodySize( 50, 50 );
	SetBodyPosition( 10,100);
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );
	Brood::BroodUI::Button::GetSpriteBody().SetTextureFromFilePath( a_texturePath );
}


/// 
/// @brief destructor
/// 
Brood::Application::Components::Dice::~Dice()
{}

/// /// 
/// @public
/// @virtual
/// @brief Setter function to set the dice's Size
/// 
/// @param a_size size of the element
/// 
void Brood::Application::Components::Dice::SetBodySize( sf::Vector2f a_size )
{
	Brood::BroodUI::UIElement::SetBodySize( a_size );

	GetSpriteBody().SetSpriteHeight( a_size.x );
	GetSpriteBody().SetSpriteLength( a_size.x );
}

/// 
/// @public
/// @virtual
/// @overload
/// @brief Setter function to set the dice's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
/// 
void Brood::Application::Components::Dice::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::Application::Components::Dice::SetBodySize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @brief Sets number of side the dice has
///
/// @param a_numSides number of sides the dice has
/// 
void Brood::Application::Components::Dice::SetNumSides( unsigned a_numSides )
{
	m_numSides = a_numSides;
}

/// 
/// @brief Sets texture for the dice
///
/// @param a_texturePathfile path to to the texture containing face of the dice;
///		it is a single texture that has texture for num faces of the dice
/// 
bool Brood::Application::Components::Dice::SetTexture( std::string a_texturePath )
{
	// loading the texture
	return GetSpriteBody().SetTextureFromFilePath( a_texturePath );
}

/// 
/// @public
/// @brief Getter function to get the dice's number of sides
/// 
/// @return dice's saved number of side
///
const unsigned Brood::Application::Components::Dice::GetNumSides()
{
	return m_numSides;
}

/// 
/// @public
/// @brief Rolls the dice to get a number between 0 and m_numSides
/// 
/// This also sets the sprite from the loaded texture
/// 
/// @return random number between 0 and m_numSides
/// 
unsigned Brood::Application::Components::Dice::RollDice()
{

	unsigned currRoll = std::rand() % m_numSides;

	GetSpriteBody().SetSpriteFromTexture(currRoll);

	return currRoll + 1;
}
