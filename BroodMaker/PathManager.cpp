#include "stdafx.h"
#include "PathManager.h"

/// 
/// @public
/// @brief default constructor
/// 
/// @note By default it creats a snake like path.
///		say, if the board is of 3,3 say 
///			0,0 | 0,1 | 0,2
///			1,0 | 1,1 | 1,2
///			2,0 | 2,1 | 2,2
/// 
/// Then the default path would be: 
///			0,0 -> 0,1 -> 0,2
///						   |
///						   v
///			1,0 <- 1,1 <- 1,2
///			 |
///			 v
///			2,0 -> 2,1 -> 2,2
///  
/// or, in a list:
///  
///		0,0 -> 0,1 -> 0,2 -> 1,2 -> 1,1 -> 1,0 -> 2,0 -> 2,1 -> 2,2
/// 
/// @param a_numRows number of tile rows in a board -> default 0
/// @param a_numCols number of tile columns in a board-> default 0
/// 
PathManager::PathManager( unsigned a_numRows, unsigned a_numCols )
{
	int currRow = 0;
	int currCol = 0;
	bool dirRight = true;
	std::cout << a_numCols << std::endl;

	for( ; currRow < a_numRows; ++currRow )
	{
		if( currCol == a_numCols )
		{
			dirRight = false;
			--currCol; // adjusting col to be 9-> largest legal col num
		}
		else if( currCol < 0 )
		{
			dirRight = true;
			++currCol; // adjusting col to be 0-> smallest legal col num 
		}
		/// @todo something is worng here 
		if( dirRight )
		{
			for( ; currCol < a_numCols; ++currCol )
			{
				st_path* tempPath = new st_path( currRow, currCol );
				m_paths.push_back( tempPath );
				/// @todo delete me
				st_path* temp = m_paths.back();
				std::cout << temp->stm_rowNum << " " << temp->stm_colNum << std::endl;
			}
		}
		else
		{
			for( ; currCol >= 0; --currCol )
			{
				st_path* tempPath = new st_path( currRow, currCol );
				m_paths.push_back( tempPath );
				/// @todo delete me
				std::cout << m_paths.back()->stm_rowNum << " " << m_paths.back()->stm_colNum << std::endl;

			}
		}
	}
}

/// 
/// @public
/// @brief Destructor
///
PathManager::~PathManager()
{
	// destroying the dynamically created paths
	std::list<st_path*>::iterator currPath = m_paths.begin();
	for( ; currPath != m_paths.end(); ++currPath )
	{
		delete( *currPath );
	}
}
