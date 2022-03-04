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

}

/// 
/// @public
/// @brief Draw funciton draws the board to the screen
/// 
/// It also envokes the tiles', dice's, and playermanger's
///		draw funcitons.
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
	
	// drawing players
	m_playerManger.Draw( a_window );

	// drawing the dice
	m_dice.Draw( a_window );
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
			//std::cout << ( *colTile )->GetPos().x << " " << ( *colTile )->GetPos().y << std::endl;
		}
		currCol = 0; // resetting the col value
		++currRow;
	}
}


/// 
/// @public
/// @brief Moves the player along the path with 
///		respect to the dice roll
/// 
/// @param a_player pointer to the player to move
///  
void Board::PlayerRollAndMove( )
{
	// checking if there are players or not
	Player* currPlayer = m_playerManger.GetNextPlayer();

	if( currPlayer == nullptr )
	{
		std::cout << "no player in the board" << std::endl;
	}

	// rolling the dice
	unsigned diceRoll = m_dice.RollDice();

	// getting the listIterator stored in the a_player
	std::list<st_path*>::iterator tempPathIte = currPlayer->GetCurrPathPos();

	// increasing the player along the path according the the dice roll
	for( unsigned i = 0; i < diceRoll; ++i )
	{
		++tempPathIte;

		// check if end is reached
		if( tempPathIte == m_pathsList.GetPathEnd() )
		{
			// end reached 
			--tempPathIte;
			break;
		}
	}

	// updating the player with new pos
	currPlayer->SetPosition( tempPathIte );
}

