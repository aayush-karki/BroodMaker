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
	st_path( int a_rowNum = 0, int a_colNum = 0 ); //default constructor
	~st_path(); // destructor
	st_path( const st_path& otherPath ); // copy constructor
	st_path& operator=( const st_path& otherPath ); // copy assignment

	// =============== public member variable ===================
public:
	int stm_rowNum = 0;
	int stm_colNum = 0;

};

bool operator==( const st_path& thisPath, const st_path& otherPath );// overloading == operator

// ================================== definations ==========================

/// 
/// @public
/// @brief default constructor
/// @param a_rowNum 
/// @param a_colNum 
/// 
inline st_path::st_path( int a_rowNum, int a_colNum )
	: stm_rowNum( a_rowNum ), stm_colNum( a_colNum )
{}

/// 
/// @public
/// @brief destuctor
/// 
inline st_path::~st_path()
{}

///
/// @public 
/// @brief copy constructor
/// @param otherPath reference to the the path 
///			structue that is being copied from 
/// 
inline st_path::st_path( const st_path & otherPath )
{
	this->stm_colNum = otherPath.stm_colNum;
	this->stm_rowNum = otherPath.stm_rowNum;
}

inline st_path& st_path::operator=( const st_path& otherPath )
{
	this->stm_colNum = otherPath.stm_colNum;
	this->stm_rowNum = otherPath.stm_rowNum;

	return* this;
}
