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

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Dice.h"

// ======================================================================
// ================= start of Dice class ================================
// ======================================================================

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
	SetBodyPosition( 10, 100 );
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );
	Brood::BroodUI::Button::GetSpriteBody().SetTextureFromFilePath( a_texturePath );
}


/// 
/// @brief destructor
/// 
Brood::Application::Components::Dice::~Dice()
{}

///
/// @public 
/// @brief copy constructor
/// 
/// @param a_otherDice reference to the the dice 
///			structue that is being copied from 
/// 
Brood::Application::Components::Dice::Dice( const Brood::Application::Components::Dice& a_otherDice ) :
	Brood::BroodUI::Button( a_otherDice ), m_numSides( a_otherDice.m_numSides )
{}

///
/// @public 
/// @brief assignmnet operator
/// 
/// @param a_otherDice reference to the the path 
///			structue that is being copied from 
/// 
/// 
Brood::Application::Components::Dice& Brood::Application::Components::Dice::operator=( const Brood::Application::Components::Dice& a_otherDice )
{
	// checking for self assignment
	if( this == &a_otherDice )
	{
		return *this;
	}

	// calling the assignment operator of the UIElement
	Brood::BroodUI::Button::operator=( a_otherDice );

	this->m_numSides = a_otherDice.m_numSides;

	return *this;
}


/// 
/// @brief  initializes the dice with the passed data
/// 
/// @param a_deckData reference of the dice data
/// 
void Brood::Application::Components::Dice::InitializeDice( Brood::Application::Data::ST_DicePrefabData& a_diceData )
{
	m_numSides = a_diceData.stm_numSides;

	SetBodySize( a_diceData.stm_diceSizeX, a_diceData.stm_diceSizeY );
	SetBodyPosition( a_diceData.stm_dicePosX, a_diceData.stm_dicePosY );

	if( !a_diceData.stm_textureFileName.empty() )
	{
		m_bodySprite.SetTextureFromFilePath( a_diceData.stm_textureFileName );
	}
}

/// 
/// @public
/// @brief creates and returns dice data struct
/// 
/// @return dice data struct with the dice data in it
/// 
Brood::Application::Data::ST_DicePrefabData Brood::Application::Components::Dice::GetDataToSave()
{

	Brood::Application::Data::ST_DicePrefabData diceData;

	diceData.stm_diceSizeX = GetBodySize().x;
	diceData.stm_diceSizeY = GetBodySize().y;
	diceData.stm_dicePosX = GetBodyPosition().x;
	diceData.stm_dicePosY = GetBodyPosition().y;

	diceData.stm_textureFileName = m_bodySprite.GetTextureFileName();
	diceData.stm_numSides = m_numSides;

	return diceData;
}

/// 
/// @public
/// @brief loads the dice data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::Dice::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// saving the dice data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );
}

/// 
/// @public
/// @brief loads the dice and its path data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// 
void Brood::Application::Components::Dice::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// loading the dice data
	Brood::Application::Data::ST_DicePrefabData diceData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	diceData.PopulateFromString( dataFromFile );
	InitializeDice( diceData );
}

/// 
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

	GetSpriteBody().SetSpriteFromTexture( currRoll );

	return currRoll + 1;
}

// ======================================================================
// ================= end of Dice class ==================================
// ======================================================================