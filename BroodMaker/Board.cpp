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

	// destroying the players
	std::vector<Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		delete( *currPlayer );
	}

}

/// 
/// @public
/// @brief Draw funciton draws the board to the screen
/// 
/// It also envokes the tiles', dice's, and player draw funcitons.
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

	// drawing the players
	std::vector<Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		(*currPlayer)->Draw(a_window);
	}

	// drawing the dice
	m_dice.Draw( a_window );
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
	// getting the path 
	st_path tempPath( a_playerStartRow, a_PlayerStartCol );
	std::list<st_path*>::iterator playerPathIte = m_paths.begin();
	for( ; playerPathIte != m_paths.end(); ++playerPathIte )
	{
		if( tempPath == *( *playerPathIte ) )
		{
			break;
		}
	}

	// checking the path was found
	// this should not be a concernt for now as this is hard coded
	///@todo proper error handeling
	if( playerPathIte == m_paths.end() )
	{
		std::cout <<  "Error! Invalid row or column number" << std::endl;
		return;
	}

	// getting the tile size
	float tileSizeX = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	Player *tempPlayer = new Player( playerPathIte, a_playerSizeX, a_playerSizeY,
									m_boardPosX, m_boardPosY, tileSizeX, tileSizeY);
	// adding tempPlayer to the m_allPlayers
	m_allPlayers.push_back( tempPlayer );

	// checking if this is the first player created
	if( m_allPlayers.size() == 1 )
	{
		m_currPlayerIdx = 0;
	}
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
	// initialize currPlayer to -1
	m_currPlayerIdx = -1;

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

	// saving path

	currRow = currCol = 0;
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
/// @brief Moves the player along the path with 
///		respect to the dice roll
/// 
/// @param a_player pointer to the player to move
///  
void Board::PlayerRollAndMove( Player* a_player )
{
	// rolling the dice
	unsigned diceRoll = m_dice.RollDice();

	// getting the listIterator stored in the a_player
	std::list<st_path*>::iterator tempPathIte = a_player->GetCurrPathPos();

	// increasing the player along the path according the the dice roll
	for( unsigned i = 0; i < diceRoll; ++i )
	{
		++tempPathIte;

		// check if end is reached
		if( tempPathIte == m_paths.end() )
		{
			// end reached 
			--tempPathIte;
			break;
		}
	}

	// updating the player with new pos
	a_player->SetPosition( tempPathIte );
}

/// 
/// @public
/// @brief Getter function to get next player in the list
/// @return 
Player* Board::GetNextPlayer()
{
	++m_currPlayerIdx;
	if( m_currPlayerIdx == m_allPlayers.size() )
	{
		// looping to the first player
		m_currPlayerIdx = 0;
	}

	return m_allPlayers.at(m_currPlayerIdx);
}
