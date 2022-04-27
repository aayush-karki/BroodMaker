/*************************************************************************/
/// 
/// @file Button.h 
/// 
/// @brief  This file is a source file for Button class.
/// 
/// It contains all of the defination of the member 
///		funciton of Button class.
///
/************************************************************************/

#include "stdafx.h"
#include "Button.h"

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the button object
/// 
/// @note by default it sets the text that is displayed on the button to empty string
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::Button::Button( Brood::BroodUI::UIElement* a_parentPtr,
								Brood::BroodUI::ENUM_UIType a_enumType ) :
	Brood::BroodUI::TextBox( a_parentPtr, a_enumType ),
	m_drawText( false ), m_texturePath( "" ),
	m_spriteLength( 0.0f ), m_spriteHeight( 0.0f )
{
	SetEditable( false );
}

/// 
/// @public
/// @brief default destrctor
///
Brood::BroodUI::Button::~Button()
{}


/// 
/// @public
/// @brief setter funciton to set the sprite length
///
/// @param a_spriteLength length of the sprite
/// 
void Brood::BroodUI::Button::SetSpriteLength( float a_spriteLength )
{
	m_spriteLength = a_spriteLength;
}

/// 
/// @public
/// @brief setter funciton to set the sprite height
///
/// @param a_spriteLength height of the sprite
/// 
void Brood::BroodUI::Button::SetSpriteHeight( float a_spriteHeight )
{
	m_spriteHeight = a_spriteHeight;
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
bool Brood::BroodUI::Button::SetTextureFromFilePath( std::string a_texturePath )
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
	Brood::BroodUI::Button::SetSpriteFromTexture( 0 );

	return true;
}

/// 
/// @public
/// @brief Opens a texture from the stored texturePath
/// 
/// @return returns true if texture was successfully set; else false
/// 
bool Brood::BroodUI::Button::SetTextureFromSavedFilePath()
{
	return SetTextureFromFilePath( m_texturePath );
}

/// 
/// @public
/// @brief Draw function 
/// @param a_window reference to render window
/// 
void Brood::BroodUI::Button::Draw( sf::RenderWindow& a_window )
{
	Brood::BroodUI::TextBox::Draw( a_window );
}

/// 
/// @private
/// @brief Setter for texture
/// 
/// sets the texture from the texture vector if it is not empty
/// 
/// @warning Assumes that The sprite for the faces are lined linearly.
///		That is assumes that there is only one row of sprite.
/// 
/// @todo make the adaptable for number of rows and column
/// 
/// @param a_num index of the texture
/// 
void Brood::BroodUI::Button::SetSpriteFromTexture( unsigned a_num )
{
	sf::IntRect tempRect( m_spriteLength * a_num, 0, m_spriteLength, m_spriteHeight );
	m_body.setTextureRect( tempRect );
}