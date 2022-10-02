/*************************************************************************/
/// 
/// @file Tiles.cpp 
/// 
/// @brief  This file is a source file for Tiles class.
/// 
/// It contains the definaiton of the member 
///		funcitons of Tiles class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Tiles.h"

// ======================================================================
// ================= start of Tiles class ===============================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
/// 
Brood::Application::Components::Tiles::Tiles() : m_tileRowNum( 0 ), m_tileColNum( 0 )
{
	m_body.setFillColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );
}

/// 
/// @public
/// @brief Default Destructors
/// 
Brood::Application::Components::Tiles::~Tiles()
{}

/// 
/// @public
/// @brief Copy contrutor
/// 
Brood::Application::Components::Tiles::Tiles( const Brood::Application::Components::Tiles& a_otherTile ) :
	Brood::BroodUI::Button( a_otherTile ),
	m_tileRowNum( a_otherTile.m_tileRowNum ), m_tileColNum( a_otherTile.m_tileColNum )
{}

/// 
/// @public
/// @brief assignment operator
/// 
Brood::Application::Components::Tiles& Brood::Application::Components::Tiles::operator=( const Brood::Application::Components::Tiles& a_other )
{
	// checking for self assignment
	if( this == &a_other )
	{
		return *this;
	}

	// creating a temporary deck object
	Brood::BroodUI::Button::operator=( a_other );

	m_tileRowNum = a_other.m_tileRowNum;
	m_tileColNum = a_other.m_tileColNum;

	return *this;
}

/// 
/// @public
/// @brief  Getter Function to get the postion of the tile 
///			relative to the board's column and row
/// 
/// @return a vector2i containing the position of the tile;
///			.x-> is the tile's column number;
///			.y-> is the tile's row number.
///  
const sf::Vector2u Brood::Application::Components::Tiles::GetRowAndCol() const
{
	return sf::Vector2u( m_tileColNum, m_tileRowNum );
}

/// 
/// @public
/// @brief  Getter Function to get the row number of the tile 
///			relative to the board's row
/// 
/// @return row number of the tile relative to the board's row
/// 
const unsigned Brood::Application::Components::Tiles::GetRow() const
{
	return m_tileRowNum;
}

/// 
/// @public
/// @brief  Getter Function to get the col number of the tile 
///			relative to the board's col
/// 
/// @return col number of the tile relative to the board's col
///
const unsigned Brood::Application::Components::Tiles::GetCol() const
{
	return m_tileColNum;
}

/// 
/// @public
/// @brief  Setter Function to set the postion of the tile 
///			relative to the board's column and row
/// 
/// @param a_rowCol a vector2u containing the position of the tile;
///			.x-> is the tile's column number;
///			.y-> is the tile's row number.
void Brood::Application::Components::Tiles::SetRowAndCol( sf::Vector2u a_rowCol )
{
	SetRow( a_rowCol.x );
	SetCol( a_rowCol.y );
}

/// 
/// @public
/// @brief  Setter Function to set the row number of the tile 
///			relative to the board's row
/// 
/// @param a_row row number of the tile relative to the board's row
///
void Brood::Application::Components::Tiles::SetRow( unsigned a_row )
{
	m_tileRowNum = a_row;
}

/// 
/// @public
/// @brief  Setter Function to set the col number of the tile 
///			relative to the board's col
/// 
/// @param a_row row number of the tile relative to the board's col
///
void Brood::Application::Components::Tiles::SetCol( unsigned a_col )
{
	m_tileColNum = a_col;
}

/// 
/// @public
/// @brief updates the member variable and size of this tile
/// 
/// @param a_tileRowNum represents row number of the board -> default 0
/// @param a_tileColNum represents column of the board  -> default 0
/// @param a_tileSizeX size of each tile in x-asix -> default 0.f
/// @param a_tileSizeY size of each tile in y-asix -> default 0.f
/// @param a_boardPosX board's x-position on screen -> default 0.f
///			relative to the render window -> default 0.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 0.f
/// 
void Brood::Application::Components::Tiles::UpdateTile( unsigned a_tileRowNum, unsigned a_tileColNum,
														float a_tileSizeX, float a_tileSizeY,
														float a_boardPosX, float a_boardPosY )
{
	// setting up the column and row number
	this->m_tileRowNum = a_tileRowNum;
	this->m_tileColNum = a_tileColNum;

	// setting up the body
	this->m_body.setSize( sf::Vector2f( a_tileSizeX, a_tileSizeY ) );
	this->m_body.setPosition( a_boardPosX + a_tileColNum * a_tileSizeX,
							  a_boardPosY + a_tileRowNum * a_tileSizeY );

}

// ======================================================================
// ================= end of Tiles class =================================
// ======================================================================