/*************************************************************************/
/// 
/// @file Dice.h 
/// 
/// @brief  This file is a header file for Dice class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Dice class.
///
/************************************************************************/
#pragma once
#include "stdafx.h"

#include "Button.h"

namespace Brood::Application
{
	namespace Components
	{
		class Dice;
		struct St_DiceSerialization;
	}
}

/// 
/// @ingroup Brood
/// @brief serialization for dice
struct Brood::Application::Components::St_DiceSerialization
{
	std::string m_texturePath; ///> file path to to the texture containing face of the dice
	float m_spriteLength; ///> sprite length and width
	unsigned m_numSides; // number of side in a die

};

///
/// @class Dice  "Dice.h"
/// 
/// @brief A class to create a dice. 
/// 
/// This class is derived form the Button class.
/// This Dice is a unbiased Dice. 
/// 
class Brood::Application::Components::Dice : public Brood::BroodUI::Button
{
	// ============= public member funciton =====================
public:
	// default constructor
	Dice( int a_numSides = 6, Brood::BroodUI::UIElement* a_parentPtr = nullptr );
	// constructor when a texture is passed
	Dice( std::string a_texturePath, int a_numSides = 6,
		  Brood::BroodUI::UIElement* a_parentPtr = nullptr );


	// default destructor
	virtual ~Dice();

	// setter function
	void SetBodySize( sf::Vector2f  a_size ) override;
	void SetBodySize( float a_sizeX, float a_sizeY )override;
	void SetNumSides( unsigned a_numSides );

	// sets texture
	bool SetTexture( std::string a_texturePath );

	// getter function
	const unsigned GetNumSides();

	unsigned RollDice(); // get a random num between 0 and m_numSides

	// ================ private member variables ==============
private:
	unsigned m_numSides; // number of side in a die
};