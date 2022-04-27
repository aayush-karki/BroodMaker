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
#include "UtilityFunctions.h"

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
	int  stm_index;
	int  stm_numSides;

	///
	/// @public
	/// @brief  Default constructor of the struct
	/// 
	St_DiceParam( std::string a_texturePath, float a_spriteLength, int a_numSides = 6,
				  Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 ) :
		stm_texturePath( a_texturePath ), stm_spriteLength( a_spriteLength ),
		stm_numSides( a_numSides ), stm_parentPtr( a_parentPtr ), stm_index( a_index )
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
	Dice( int a_numSides = 6, Brood::BroodUI::UIElement* a_parentPtr = nullptr,
		  int a_index = -1 );
	// constructor when a texture is passed
	Dice( std::string a_texturePath, float a_spriteLength, int a_numSides = 6,
		  Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1 );
	// constructor when diceParam is passed
	Dice( Brood::St_DiceParam& a_diceParam );

	virtual ~Dice();

	bool SetTextureFromFilePath( std::string a_texturePath );
	bool SetTextureFromSavedFilePath();

	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) { return false; } // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) { return false; } // when mouse button is released
	virtual bool OnMouseMove() { return false; } // what happens to the element on mouse move
	virtual bool Update() { return false; } // update the element
	virtual void Draw( sf::RenderWindow& a_window ) override; // draw to screen
	unsigned RollDice(); // get a random num between 0 and m_numSides

	// ================ private member function ==============
private:

	void SetSpriteFromTexture( unsigned a_num ); // setter


	// ================ private member variables ==============
private:
	unsigned m_numSides; // number of side in a die

	std::string m_texturePath;
	sf::Texture m_texture; // reference to the a the texture of faces of dice
	float m_spriteLength; // sprite length and width
};

// ================== definations  =================

/// 
/// @private
/// @brief Setter for texture
/// 
/// sets the texture from the texture vector if it is not empty
/// 
/// @warning Assumes that The sprite for the faces are lined linearly.
///		That is assumes that there is only one row of sprite.
/// @warning Assumus that the sprites are square. 
/// 
/// @param a_num index of the texture
/// 
inline void Brood::Dice::SetSpriteFromTexture( unsigned a_num )
{
	sf::IntRect tempRect( m_spriteLength * a_num, 0, m_spriteLength, m_spriteLength );
	m_body.setTextureRect( tempRect );

}

/// 
/// @public
/// @brief Rolls the dice to get a number between 0 and m_numSides
/// 
/// @return random number between 0 and m_numSides
/// 
inline unsigned Brood::Dice::RollDice()
{

	unsigned currRoll = std::rand() % m_numSides;
	return currRoll + 1;
}

/// 
/// @public
/// @brief Opens a texture from the stored texturePath
/// 
/// @return returns true if texture was successfully set; else false
/// 
inline bool Brood::Dice::SetTextureFromSavedFilePath()
{
	return SetTextureFromFilePath( m_texturePath );
}
