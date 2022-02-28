/*************************************************************************/
/// 
/// @file struct_path.cpp 
/// 
/// @brief  This file is a source file for struct_path class.
/// 
/// It contains the definaiton of the member 
///		funcitons of Tiles class.
/// 
/************************************************************************/

#include "Struct_path.h"

/// 
/// @brief overloading the == operator
/// @param thisPath reference to st_path structure which is on left side of the == operator
/// @param otherPath reference to st_path structure which is on right side of the == operator
/// @return 
bool operator==( const st_path& thisPath, const st_path& otherPath )
{
	return (thisPath.stm_colNum == otherPath.stm_colNum && thisPath.stm_rowNum == otherPath.stm_rowNum );
}
