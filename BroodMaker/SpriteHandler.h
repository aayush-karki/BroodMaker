

/*************************************************************************/
/// 
/// @file SpriteHandler.h 
/// 
/// @brief  This file is a header file for SpriteHandler class 
///		which is in Brood namespace
/// 
/// It contains all of the declaration of the member 
///		funciton of BroodSprite class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "UtilityFunctions.h"
#include "GlobalVariables.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{	
	class SpriteHandler;
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of BroodSprite class =========================
// ======================================================================

/// 
/// @ingroup Brood
/// @class SpriteHandler  "SpriteHandler.h"
/// @brief a class to handel the sprite
/// 
/// This class has function to manupulate the sprite and textures.
///		It allows to load texture from file. 
/// 
/// @note A sprite sheet should always be horizontal
/// 
/// @code
///		// creating a button
/// 	Brood::BroodUI::Button mySpriteButton;
///		mySpriteButton.SetBodySize( 50, 50 );
///		mySpriteButton.SetBodyPosition( 55, 100 );
///		mySpriteButton.SetFont( font );
/// 
///		// loading the texture
///		mySpriteButton.GetSpriteBody().SetTextureFromFilePath( fileName );
///		// setting the second sprite from the texture file
///		mySpriteButton.GetSpriteBody().SetSpriteFromTexture( 1 );
///
/// @endcode
///
class Brood::SpriteHandler
{
	// ============ public member function =============== 
public:

	// default constructor
	SpriteHandler(sf::RectangleShape* a_body );

	// default destructor
	virtual ~SpriteHandler();

	// copy constructor
	SpriteHandler(const SpriteHandler& a_otherSpriteHandler);

	// assignment operator
	SpriteHandler& operator=( const SpriteHandler& a_otherSpriteHandler );

	// setter function
	void SetSpriteLength( float a_spriteLength ); // sets sprite length
	void SetSpriteHeight( float a_spriteHwight ); // sets sprite height

	bool SetTextureFromFilePath( std::string a_texturePath ); // loads and sets the texture form provided path 
	bool SetTextureFromSavedFilePath(); // loads and sets the texture from saved path
	void SetSpriteFromTexture( unsigned a_num ); // sets sprite from texture

	// getter function 
	const std::string GetTexturePath();
	const float GetSpritLenght();
	const float GetSpritHeight();
	const unsigned GetcurrSpriteIndex();
	
	void RemoveTexture(); // removes texture from the body
	void Debugger( ); // removes texture from the body for debuging purposes

	// ============ private member variables =============== 
private:
	sf::RectangleShape* m_body; ///> pointer to the body

	std::string m_texturePath; ///> saves the path to the texture
	sf::Texture m_texture; ///> reference to the  the texture opened from the path
	float m_spriteLength; ///> sprite length in the texture file
	float m_spriteHeight; ///> sprite height in the texture file
	unsigned m_currSpriteIndex; ///> saves the current index of sprite in the texture
};

// ======================================================================
// ================= end of button class ================================
// ======================================================================