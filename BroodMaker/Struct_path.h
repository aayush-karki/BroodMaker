/*************************************************************************/
/// 
/// @file Struct_path.h 
/// 
/// @brief  This file is a header file for st_path structure.
/// 
/// It contains all of the declaration of the member 
///		funciton of st_path structure
/// It contains all of the inline funcitons defination of 
///		the member funciton of st_path structure
///
/************************************************************************/
#pragma once
/// 
/// @struct st_path
/// @brief st_path is a node used for linkedlist.
/// 
/// This is used as a node for the path linked list.
/// A linked list for the path is necessary to conver the 2d board into
/// a liner path.
/// It stores the corresponding row number and colon number 
/// of the tile in the board
/// 
///
struct st_path
{
	// =============== public member function ===================
public:
	/// @public
	/// @brief default constructor
	/// @param a_rowNum 
	/// @param a_colNum 
	st_path( int a_rowNum = 0, int a_colNum = 0 )
		: stm_rowNum( a_rowNum ), stm_colNum( a_colNum )
	{}

	// =============== public member variable ===================
public:
	int stm_rowNum = 0;
	int stm_colNum = 0;

};