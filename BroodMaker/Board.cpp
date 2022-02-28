/*************************************************************************/
/// 
/// @file Board.cpp 
/// 
/// @brief  This file is a source file for Board class.
/// 
/// It contains all of the defination of the member 
///		funciton of Board class.
/// 
/************************************************************************/

#include "Board.h"

/// 
/// @public
/// @brief Destructor
///
Board::~Board()
{
	// destryoing the dynamically created tiles
	std::vector< std::vector<Tiles*> >::iterator rowTile;
	std::vector<Tiles*>::iterator colTile;
	for( rowTile = m_boardTiles.begin(); rowTile != m_boardTiles.end(); rowTile++ )
	{
		for( colTile = rowTile->begin(); colTile != rowTile->end(); colTile++ )
		{
			delete ( *colTile );
		}
	}

	// destroying the dynamically created paths
	std::list<st_path*>::iterator currPath = m_paths.begin();
	for( ; currPath != m_paths.end(); ++currPath )
	{
		delete( *currPath );
	}
}

/// 
/// @public
/// @brief Draw funciton draws the board and tiles to the screen
/// 
/// I also envokes the tiles draw funcitons.
///			
/// @param a_window reference to the render window
/// 
void Board::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( this->m_boardBody );

	// drawing the tiles
	std::vector< std::vector<Tiles*> >::iterator rowTile;
	std::vector<Tiles*>::iterator colTile;
	for( rowTile = m_boardTiles.begin(); rowTile != m_boardTiles.end(); rowTile++ )
	{
		for( colTile = rowTile->begin(); colTile != rowTile->end(); colTile++ )
		{
			( *colTile )->Draw( a_window );
		}
	}
}

/// 
/// @public
/// @brief adds a player
/// 
/// @param a_playerSizeX size of the player in x-asix -> default 0.f
/// @param a_playerSizeY size of the player in y-asix -> default 0.f
/// @param a_playerStartRow represents on which row number 
///			the player starts -> default 0
/// @param a_PlayerStartCol represents on which column number 
///			the player starts-> default 0
///  
void Board::AddNewPlayer( float a_playerSizeX, float a_playerSizeY, 
						  int a_playerStartRow, int a_PlayerStartCol )
{
	st_path tempPath( a_playerStartRow, a_PlayerStartCol );

	// getting the path 
	std::list<st_path*>::iterator playerPathIte = m_paths.begin();
	for( ; playerPathIte != m_paths.end(); ++playerPathIte )
	{
		// check if this is the path
		break;

	}

	// Player tempPlayer = new Player()
}

/// 
/// @ private
/// @brief sets up the board 
/// 
/// It initializes the board as well as the tiles. 
/// Tiles are set up according to the 
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
void Board::InitializeBoard( int a_numRows, int a_numCols,
							 float a_boardSizeX, float a_boardSizeY,
							 float a_boardPosX, float a_boardPosY )
{
	this->m_boardPosX = a_boardPosX;
	this->m_boardPosY = a_boardPosY;

	// setting up the column and row number
	this->m_numRows = a_numRows;
	this->m_numCols = a_numCols;

	// setting up the board body
	this->m_boardBody.setSize( sf::Vector2f( a_boardSizeX, a_boardSizeY ) );
	this->m_boardBody.setPosition( a_boardPosX, a_boardPosY );
	this->m_boardBody.setFillColor( sf::Color::Blue );

	// setting up tiles
	float tileSizex = a_boardSizeX / a_numCols;
	float tileSizeY = a_boardSizeX / a_numRows;

	// resizing the vector
	m_boardTiles.resize( a_numRows, std::vector<Tiles*>( a_numCols ) );

	// filling the vector with tiles
	std::vector< std::vector<Tiles*> >::iterator rowTile;
	int currRow = 0;
	std::vector<Tiles*>::iterator colTile;
	int currCol = 0;

	for( rowTile = m_boardTiles.begin(); rowTile != m_boardTiles.end(); rowTile++ )
	{
		for( colTile = rowTile->begin(); colTile != rowTile->end(); colTile++ )
		{
			*colTile = new Tiles( currRow, currCol, tileSizex, tileSizeY, a_boardPosX, a_boardPosY );
			++currCol;
			
			/// todo: deleteme
			std::cout << ( *colTile )->GetPos().x << " " << ( *colTile )->GetPos().y << std::endl;
		}
		currCol = 0; // resetting the col value
		++currRow;
	}

	// saving path

	currRow = currCol = 0;
	bool dirRight = true;
	for( ; currRow < a_numRows; ++currRow )
	{
		if( currCol == a_numCols )
		{
			dirRight = false;
		}
		else if( currCol < 0 )
		{
			dirRight = true;
		}
		if( dirRight )
		{
			for( ; currCol < a_numCols; ++currCol )
			{
				st_path* tempPath = new st_path( currRow, currCol );
				m_paths.push_back( tempPath );
			}
		}
	}
}
