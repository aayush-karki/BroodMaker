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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "Button.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class Dice;
	}
}

// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Dice class ================================
// ======================================================================

///
/// @ingroup Components
/// @class Dice  "Dice.h"
/// @brief A class to create a dice. 
/// 
/// This class is derived form the Button class.
/// This Dice is a unbiased Dice. 
/// 
class Brood::Application::Components::Dice :
	public Brood::BroodUI::Button
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

	// copy constructor
	Dice( const Dice& a_otherDice );

	// assignment operator
	Dice& operator=( const Dice& a_otherDice );

	// setter function to set the body size
	void SetBodySize( sf::Vector2f  a_size ) override;

	// setter function to set the body size
	void SetBodySize( float a_sizeX, float a_sizeY )override;

	// setter function to set number of sides the dice has
	void SetNumSides( unsigned a_numSides );

	// sets texture
	bool SetTexture( std::string a_texturePath );

	// getter function
	const unsigned GetNumSides();

	// get a random num between 0 and m_numSides
	unsigned RollDice();

	// ================ private member variables ==============
private:

	/// number of side in a die
	unsigned m_numSides;
};

// ======================================================================
// ================= end of Dice class ==================================
// ======================================================================
