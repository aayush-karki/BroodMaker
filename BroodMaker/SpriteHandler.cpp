
/*************************************************************************/
/// 
/// @file SpriteHandler.cpp 
/// 
/// @brief  This file is a source file for SpriteHandler class.
/// 
/// It contains all of the defination of the member 
///		funciton of SpriteHandler class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "SpriteHandler.h"

// ======================================================================
// ================= start of SpriteHandler class =======================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the SpriteHandler object
/// 
/// @param a_body pointer the body of the element
/// 
Brood::SpriteHandler::SpriteHandler( sf::RectangleShape* a_body ) :
	m_body( a_body ), m_texturePath( "" ),	m_spriteLength( 0.f ),
	m_spriteHeight( 0.f ), m_currSpriteIndex(0)
{}

/// 
/// @public
/// @brief default destrctor
///
Brood::SpriteHandler::~SpriteHandler()
{}

/// 
/// @public
/// @brief Copy Constructor
///	
/// 
/// @param a_otherSpriteHandler reference to the the other sprite handler
///		object that is being copied from 
///
Brood::SpriteHandler::SpriteHandler( const SpriteHandler & a_otherSpriteHandler )
{
	this->m_body = a_otherSpriteHandler.m_body;
	this->m_texture = a_otherSpriteHandler.m_texture;
	this->m_spriteLength = a_otherSpriteHandler.m_spriteLength;
	this->m_spriteHeight = a_otherSpriteHandler.m_spriteHeight;
	this->m_currSpriteIndex = a_otherSpriteHandler.m_currSpriteIndex;
}

/// 
/// @public
/// @brief  assignment operator
/// 
/// @param a_otherSpriteHandler reference to the the other sprite handler
///		object that is being copied from 
///
Brood::SpriteHandler& Brood::SpriteHandler::operator=( const Brood::SpriteHandler& a_otherSpriteHandler )
{
	// checking for self assignment
	if( this == &a_otherSpriteHandler )
	{
		return *this;
	}

	this->m_body = a_otherSpriteHandler.m_body;
	this->m_texture = a_otherSpriteHandler.m_texture;
	this->m_spriteLength = a_otherSpriteHandler.m_spriteLength;
	this->m_spriteHeight = a_otherSpriteHandler.m_spriteHeight;
	this->m_currSpriteIndex = a_otherSpriteHandler.m_currSpriteIndex;

	return *this;
}


/// 
/// @public
/// @brief setter funciton to set the sprite length
///
/// @param a_spriteLength length of the sprite
/// 
void Brood::SpriteHandler::SetSpriteLength( float a_spriteLength )
{
	m_spriteLength = a_spriteLength;
}

/// 
/// @public
/// @brief setter funciton to set the sprite height
///
/// @param a_spriteLength height of the sprite
/// 
void Brood::SpriteHandler::SetSpriteHeight( float a_spriteHeight )
{
	m_spriteHeight = a_spriteHeight;
}

/// 
/// @public
/// @brief loads and sets the texture from the file path 
/// 
/// It also saves the textureFilepath. By default uses the body size as 
///		the sprite size
/// 
/// @param a_texturePath file path to to the texture containing face of the dice;
/// 
/// @return returns true if texture was successfully set; else false
/// 
bool Brood::SpriteHandler::SetTextureFromFilePath( std::string a_texturePath )
{
	// open texture
	if( !Brood::UtilityFuncs::LoadTextureFromFile( m_texture, a_texturePath ) )
	{
		return false;
	}
	// saving the texture path
	m_texturePath = a_texturePath;

	// setting the texture
	m_body->setTexture( &m_texture );
	Brood::SpriteHandler::SetSpriteFromTexture( 0 );

	return true;
}

/// 
/// @public
/// @brief load and sets a texture from the stored texturePath
/// 
/// @return returns true if texture was successfully set; else false
/// 
bool Brood::SpriteHandler::SetTextureFromSavedFilePath()
{
	return SetTextureFromFilePath( m_texturePath );
}

/// 
/// @public
/// @brief Setter for texture
/// 
/// sets the texture from the texture vector if it is not empty. 
///		If either the sprite height and length is equal to zero 
///		then, it sets them to body's height and length
/// 
/// @warning Assumes that The sprite for the faces are lined linearly.
///		That is assumes that there is only one row of sprite.
/// 
/// @todo make the adaptable for number of rows and column
/// 
/// @param a_num index of sprite in the texture
/// 
void Brood::SpriteHandler::SetSpriteFromTexture( unsigned a_num )
{
	// checking if the sprite height and length is 0
	// then setting the height and length to body size
	if( m_spriteHeight == 0 || m_spriteLength == 0 )
	{
		m_spriteLength = m_body->getSize().x;
		m_spriteHeight = m_body->getSize().y;
	}

	sf::IntRect tempRect( m_spriteLength * a_num, 0, m_spriteLength, m_spriteHeight );
	m_body->setTextureRect( tempRect );

	// saving the index
	m_currSpriteIndex = a_num;
}

/// 
/// @brief Getter function to get the saved texture path
/// @return string containing the texture path
/// 
const std::string Brood::SpriteHandler::GetTexturePath()
{
	return m_texturePath;
}

/// 
/// @brief Getter function to get the saved sprite length
/// @return float value containing the sprite length
/// 
const float Brood::SpriteHandler::GetSpritLenght()
{
	return m_spriteLength;
}

/// 
/// @brief Getter function to get the saved sprite height
/// @return float value containing the sprite length
/// 
const float Brood::SpriteHandler::GetSpritHeight()
{
	return m_spriteHeight;
}

/// 
/// @brief Getter function to get the index of current Sprite
/// @return float value containing the sprite length
/// 
const unsigned Brood::SpriteHandler::GetcurrSpriteIndex()
{
	return m_currSpriteIndex;
}

/// 
/// @public
/// @brief Removes the texture
/// 
void Brood::SpriteHandler::RemoveTexture()
{
	m_body->setTexture( nullptr );

	sf::IntRect tempRect( 0, 0, 0, 0);
	m_body->setTextureRect(tempRect);
}

/// 
/// @public
/// @brief changes the texture of the element to its the element ID when debug is on
///		and changes it back to the texture it had before debugging when debug is off.
/// 
void Brood::SpriteHandler::Debugger()
{
	if( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode )
	{
		RemoveTexture();
	}
	else
	{
		SetSpriteFromTexture( m_currSpriteIndex );
	}
}

// ======================================================================
// ================= end of button class ================================
// ======================================================================