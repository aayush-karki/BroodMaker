

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
/// @todo make this animatable. next Sprit() which get the next sprite and
///		loops back to idx 0
///
class Brood::SpriteHandler
{
	// ============ public member function =============== 
public:

	// default constructor
	SpriteHandler( sf::RectangleShape* a_body );

	// default destructor
	virtual ~SpriteHandler();

	// copy constructor
	SpriteHandler( const SpriteHandler& a_otherSpriteHandler );

	// assignment operator
	SpriteHandler& operator=( const SpriteHandler& a_otherSpriteHandler );

	// ====== setter function =====

	// sets sprite length
	void SetSpriteLength( float a_spriteLength );

	// sets sprite height
	void SetSpriteHeight( float a_spriteHwight );

	// loads and sets the texture form provided path 
	bool SetTextureFromFilePath( std::string a_texturePath );

	// loads and sets the texture form provided path 
	bool SetTextureFromFilePath( std::string a_textureDirectoryPath,
								 std::string a_textureFileName );

	// loads and sets the texture from saved path
	bool SetTextureFromSavedFilePath();

	// sets sprite from texture
	void SetSpriteFromTexture( unsigned a_num );

	// ====== getter function =====

	// getter function to get the textureFilename
	const std::string GetTextureFileName();

	// getter function to get the file path
	const std::string GetTextureDirectoryPath();

	// getter function to get the sprite length
	const float GetSpritLenght();

	// getter function to get the sprite height
	const float GetSpritHeight();

	// getter function to get the current sprite index
	const unsigned GetcurrSpriteIndex();

	// removes texture from the body
	void RemoveTexture();

	// removes texture from the body for debuging purposes
	void Debugger();

	// ============ private member variables =============== 
private:

	///> pointer to the body
	sf::RectangleShape* m_body;

	///> saves the directory path to the texture
	std::string m_textureDirectoryPath;

	///> saves the path to the texture
	std::string m_textureFileName;

	///> reference to the  the texture opened from the path
	sf::Texture m_texture;

	///> sprite length in the texture file
	float m_spriteLength;

	float m_spriteHeight;
	///> sprite height in the texture file

	///> saves the current index of sprite in the texture
	unsigned m_currSpriteIndex;
};

// ======================================================================
// ================= end of button class ================================
// ======================================================================