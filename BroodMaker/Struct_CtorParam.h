/*************************************************************************/
/// 
/// @file Struct_CtorParam.h 
/// 
/// @brief  This file is a header file that contains all the different 
///		struct used to pass in different constructors
/// 
/// It contains both the declaration and defination of the member 
///		funciton of different initializer structure
/// It contains all of the inline funcitons defination of 
///		the member funciton of st_path structure
///
/************************************************************************/
#pragma once
#include "stdafx.h"

/// 
/// @struct St_BoardParam
/// @brief St_BoardParam a struct used as parameter when constructing
///		a Board object
/// 
/// This is used to pass to the constructor if the Board class
///
struct St_BoardParam
{
	// public member variables
public:
	int stm_numRows = 0; // number of tile rows in a board
	int  stm_numCols = 0; // number of tile columns in a board
	float stm_boardSizeX = 0.f; // board's width
	float stm_boardSizeY = 0.f; // board's length
	float stm_boardPosX = 0.f; // board's x-position on screen
	float stm_boardPosY = 0.f; // board's y-position on screen


	// public member function
public:

	/// 
	/// @public
	/// @brief default Constructor
	/// 
	/// Inializes the member variables
	/// 
	/// @param a_numRows number of tile rows in a board -> default 0
	/// @param a_numCols number of tile columns in a board-> default 0
	/// @param a_boardSizeX  board's width -> default 0.f
	/// @param a_boardSizeY board's length -> default 0.f
	/// @param a_boardPosX board's x-position on screen; 
	///			relative to the render window -> default 0.f
	/// @param a_boardPosY board's y-position on screen; 
	///			realtive to the render window -> default 0.f
	/// 
	St_BoardParam( int a_numRows = 0, int a_numCols = 0,
				float a_boardSizeX = 0.f, float a_boardSizeY = 0.f,
				float a_boardPosX = 0.f, float a_boardPosY = 0.f ):
		stm_numRows(a_numRows), stm_numCols( a_numCols ) , 
		stm_boardSizeX( a_boardSizeX ) , stm_boardSizeY( a_boardSizeY ),
		stm_boardPosX( a_boardPosX ), stm_boardPosY( a_boardPosY )
	{}
};

/// 
/// @struct St_DiceParam
/// @brief St_BoardParam a struct used as parameter when constructing
///		a Dice object
/// 
/// This is used to pass to the constructor if the Dice class
///
struct St_DiceParam
{
	// public member variables
public:
	float stm_diceSizeX = 0.f; // dice's width
	float stm_diceSizeY = 0.f; // dice's length
	float stm_dicePosX = 0.f; // dice's x-position on the screen
	float stm_dicePosY = 0.f; // dice's y-position on the screen
	int stm_numSides = 0; // number of a side that the dice has
	//  reference to the vector containing list of the texture
	const std::vector<sf::Texture>* stm_texturesVecPtr; 

	// public member function
public:
	/// 
	/// @public
	/// @brief Default constructor
	/// 
	/// @param a_diceTextures reference to the vector containing 
	///		list of the texture
	/// @param a_diceSizeX dice's width -> default 0.f
	/// @param a_diceSizeY dice's length -> default 0.f
	/// @param a_dicePosX dice's x-position on the screen;
	///			relative to the render window -> default 0.f
	/// @param a_dicePosY dice's y-position on the screen;
	///			relative to the render window -> default 0.f
	/// @param a_numSides number of a side that the dice has;
	///			-> default 6
	/// 
	St_DiceParam( const std::vector<sf::Texture>* a_texturesVecPtr,
				  float a_diceSizeX = 0.f, float a_diceSizeY = 0.f,
				  float a_dicePosX = 0.f, float a_dicePosY = 0.f,
				  int a_numSides = 6 ) :
		stm_texturesVecPtr( a_texturesVecPtr ),
		stm_diceSizeX( a_diceSizeX ), stm_diceSizeY( a_diceSizeY ),
		stm_dicePosX( a_dicePosX ), stm_dicePosY( a_dicePosY ),
		stm_numSides( a_numSides )
	{}
};