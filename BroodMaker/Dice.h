/*************************************************************************/
/// 
/// @file Dice.h 
/// 
/// @brief  This file is a header file for Dice class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Dice class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Dice class
///
/************************************************************************/
#pragma once
#include "stdafx.h"

///
/// @class Dice  "Dice.h"
/// 
/// @brief A Dice Class
/// 
/// This Dice is a unbiased Dice. 
/// 
class Dice
{
	// ============= public member funciton =====================
public: 

	// default constructor
	Dice( float a_diceSizeX = 0.f, float a_diceSizeY = 0.f,
		  float a_dicePosX = 0.f, float a_dicePosY = 0.f,
		  int a_numSides = 6);
	// constructor when a texture is passed
	Dice( const std::vector<sf::Texture> *a_texturesVecPtr,
		  float a_diceSizeX = 0.f, float a_diceSizeY = 0.f,
		  float a_dicePosX = 0.f, float a_dicePosY = 0.f,
		  int a_numSides = 6 );
	void Draw( sf::RenderWindow& a_window ); // draw to screen
	unsigned RollDice(); // get a random num between 0 and m_numSides

	// ================ private member function ==============
private:
	void InitializeDice( float a_diceSizeX = 0.f, float a_diceSizeY = 0.f,
						 float a_dicePosX = 0.f, float a_dicePosY = 0.f,
						 int a_numSides = 6 ); 

	void SetTextureFromTextureVec( unsigned a_num ); // testure setter from the tetuer vec
	// ================ private member variables ==============
private:
	unsigned m_numSides; // number of side in a die
	sf::RectangleShape m_diceBody; // body of the die; this is what render

	const std::vector<sf::Texture> *m_texturesVecPtr; // pointer to the a vector that stores the texture of faces of dice
	/// @todo could do this with a code?

};

/// 
/// @public
/// @brief Rolls the dice to get a number between 0 and m_numSides
/// 
/// @return random number between 0 and m_numSides
/// 
inline unsigned Dice::RollDice()
{
	
	unsigned currRoll = std::rand() % m_numSides;
	SetTextureFromTextureVec( currRoll );

	return currRoll + 1;
}

/// 
/// @public
/// @brief Default constructor
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
inline Dice::Dice( float a_diceSizeX, float a_diceSizeY,
			float a_dicePosX, float a_dicePosY,
			int a_numSides )
{
	InitializeDice( a_diceSizeX, a_diceSizeY, a_dicePosX, a_dicePosY, a_numSides );
}


/// 
/// @public
/// @brief constructor
/// 
/// This constuctor is called when the texture is also passed.
/// 
/// @param a_diceTextures reference to the vector containing 
///				list of the texture
/// @param a_diceSizeX dice's width -> default 0.f
/// @param a_diceSizeY dice's length -> default 0.f
/// @param a_dicePosX dice's x-position on the screen;
///			relative to the render window -> default 0.f
/// @param a_dicePosY dice's y-position on the screen;
///			relative to the render window -> default 0.f
/// @param a_numSides number of a side that the dice has;
///			-> default 6
///
inline Dice::Dice( const std::vector<sf::Texture> *a_diceTextures,
				   float a_diceSizeX, float a_diceSizeY,
				   float a_dicePosX, float a_dicePosY,
				   int a_numSides ) : Dice( a_diceSizeX, a_diceSizeY,
											a_dicePosX, a_dicePosY,
											a_numSides )
{
	m_texturesVecPtr = a_diceTextures;

	// settig curr texture  
	SetTextureFromTextureVec( 0  ); 
}

/// 
/// @private
/// @brief Setter for texture
/// 
/// sets the texture from the texture vector if it is not empty
/// 
/// @param a_num index of the texture
/// 
inline void Dice::SetTextureFromTextureVec( unsigned a_num )
{
	if( !m_texturesVecPtr->empty() )
	{
		m_diceBody.setTexture( &m_texturesVecPtr->at( a_num ) );
	}
}