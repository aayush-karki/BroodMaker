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

namespace Brood
{
	// defining what component of this file will be inside namespace BroodUI
	class Dice;
	struct St_DiceSerialization;
	struct St_DiceParam;
}

/// 
/// @ingroup Brood
/// @brief serialization for dice
struct Brood::St_DiceSerialization
{
	std::string m_texturePath; ///> file path to to the texture containing face of the dice
	float m_spriteLength; ///> sprite length and width
	unsigned m_numSides; // number of side in a die

};

struct Brood::St_DiceParam
{
	std::string  stm_texturePath;
	float stm_spriteLength;
	Brood::BroodUI::UIElement* stm_parentPtr;
	int  stm_numSides;

	///
	/// @public
	/// @brief  Default constructor of the struct
	/// 
	St_DiceParam( std::string a_texturePath, float a_spriteLength, int a_numSides = 6,
				  Brood::BroodUI::UIElement* a_parentPtr = nullptr) :
		stm_texturePath( a_texturePath ), stm_spriteLength( a_spriteLength ),
		stm_numSides( a_numSides ), stm_parentPtr( a_parentPtr )
	{};
};

///
/// @class Dice  "Dice.h"
/// 
/// @brief A class to create a dice. 
/// 
/// This class is derived form the Button class.
/// This Dice is a unbiased Dice. 
/// 
class Brood::Dice : public Brood::BroodUI::Button
{
	// ============= public member funciton =====================
public:
	// default constructor
	Dice( int a_numSides = 6, Brood::BroodUI::UIElement* a_parentPtr = nullptr);
	// constructor when a texture is passed
	Dice( std::string a_texturePath, float a_spriteLength, int a_numSides = 6,
		  Brood::BroodUI::UIElement* a_parentPtr = nullptr );
	// constructor when diceParam is passed
	Dice( Brood::St_DiceParam& a_diceParam );

	// default destructor
	virtual ~Dice();

	// overrided funciton 
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw to screen
	
	unsigned RollDice(); // get a random num between 0 and m_numSides

	// ================ private member variables ==============
private:
	unsigned m_numSides; // number of side in a die
};