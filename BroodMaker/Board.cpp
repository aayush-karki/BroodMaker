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

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "Board.h"


// ======================================================================
// ================= start of Board class ===============================
// ======================================================================

/// 
/// @public
/// @brief default  Constructor
/// 
/// It initializes the board as well as the tiles. 
/// Tiles are set up according to the 
/// 
/// @param a_numRows number of tile rows in a board -> default 1
/// @param a_numCols number of tile columns in a board-> default 1
/// @param a_boardSizeX  board's width -> default 50.f
/// @param a_boardSizeY board's length -> default 50.f
/// @param a_boardPosX board's x-position on screen; 
///			relative to the render window -> default 50.f
/// @param a_boardPosY board's y-position on screen; 
///			realtive to the render window -> default 50.f
/// 
Brood::Application::Components::Board::Board( unsigned a_numRows,
											  unsigned a_numCols,
											  float a_boardSizeX,
											  float a_boardSizeY,
											  float a_boardPosX,
											  float a_boardPosY )
{
	InitializeBoard( a_numRows, a_numCols,
					 a_boardSizeX, a_boardSizeY,
					 a_boardPosX, a_boardPosY );
}

/// 
/// @public
/// @brief Destructor
///
Brood::Application::Components::Board::~Board()
{
	// destryoing the dynamically created tiles
	std::vector< std::vector<Path*> >::iterator rowTile;
	std::vector<Path*>::iterator colTile;
	for( rowTile = m_boardPaths.begin(); rowTile != m_boardPaths.end(); rowTile++ )
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
void Brood::Application::Components::Board::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( this->m_boardBody );

	// drawing the tiles
	std::vector< std::vector<Path*> >::iterator rowTile;
	std::vector<Path*>::iterator colTile;
	for( rowTile = m_boardPaths.begin(); rowTile != m_boardPaths.end(); rowTile++ )
	{
		for( colTile = rowTile->begin(); colTile != rowTile->end(); colTile++ )
		{
			( *colTile )->Draw( a_window );
		}
	}

	//// drawing players
	//m_playerManger.Draw( a_window );

	//// drawing the dice
	//m_dice.Draw( a_window );
}

/// 
/// @public
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
void Brood::Application::Components::Board::InitializeBoard( unsigned a_numRows, unsigned a_numCols,
															 float a_boardSizeX, float a_boardSizeY,
															 float a_boardPosX, float a_boardPosY )
{
	// setting up the board body
	this->SetBoardSize( a_boardSizeX, a_boardSizeY );
	this->m_boardBody.setPosition( a_boardPosX, a_boardPosY );
	this->m_boardBody.setFillColor( sf::Color::Blue );

	// setting up the column and row number
	this->SetNumCol( a_numCols );
	this->SetNumRow( a_numRows );

	/// @todo delete me
	for( unsigned currRowNum = 0; currRowNum < m_numRows; ++currRowNum )
	{
		for( unsigned currColNum = 0; currColNum < m_numCols; ++currColNum )
		{
			m_boardPaths.at( currRowNum ).at( currColNum )->GetTilePtr()->SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );
		}
	}
}

/// 
/// @public
/// @brief Setter funciton to set the number of row in the board 
/// 
/// @param a_numRows number of tile rows to set in a board 
/// 
void Brood::Application::Components::Board::SetNumRow( unsigned a_numRows )
{
	if( a_numRows > m_numRows )
	{
		IncreaseNumRow( a_numRows );
	}
	else
	{
		DecreaseNumRow( a_numRows );
	}
}

/// 
/// @public
/// @brief Setter funciton to set the number of col in the board 
/// 
/// @param a_numCols number of tile col to set in a board 
/// 
void Brood::Application::Components::Board::SetNumCol( unsigned a_numCols )
{
	if( a_numCols > m_numCols )
	{
		IncreaseNumCol( a_numCols );
	}
	else
	{
		DecreaseNumCol( a_numCols );
	}
}

/// 
/// @public
/// @brief Setter funciton to set the board size
/// 
///	It also updates the tiles by decreasing the size to keep the 
///		number of rows and number of columns constant
/// 
/// @param a_boardSize size of the board 
/// 
void Brood::Application::Components::Board::SetBoardSize( sf::Vector2f a_boardSize )
{
	// setting the body size
	m_boardBody.setSize( a_boardSize );

	// only change the tile sets it the lastRowNum and colNUm is not zero
	if( m_numRows == 0 || m_numCols == 0 )
	{
		return;
	}

	// updating the tiles
	UpdateBoardPath( 0, m_numRows, 0, m_numCols );
}

/// 
/// @public
/// @brief Setter funciton to set the board size
/// 
///	It also updates the tiles by decreasing the size to keep the 
///		number of rows and number of columns constant
/// 
/// @param a_boardSizeX  board's width
/// @param a_boardSizeY board's length
/// 
void Brood::Application::Components::Board::SetBoardSize( float a_boardSizeX, float a_boardSizeY )
{
	Brood::Application::Components::Board::SetBoardSize( { a_boardSizeX, a_boardSizeY } );
}

/// 
/// @public
/// @brief Setter funciton to set the board position
/// 
///	It also updates the tiles by moving it
/// 
/// @param a_boardPos postition of the board 
/// 
void Brood::Application::Components::Board::SetBoardPos( sf::Vector2f a_boardPos )
{
	// setting the size of the board body
	m_boardBody.setPosition( a_boardPos );



	UpdateBoardPath( 0, m_numRows, 0, m_numCols );
}

/// 
/// @public
/// @brief Setter funciton to set the board position
/// 
///	It also updates the tiles by moving it
/// 
/// @param a_boardPosX  board's width 
/// @param a_boardPosY board's length 
/// 
void Brood::Application::Components::Board::SetBoardPos( float a_boardPosX, float a_boardPosY )
{
	Brood::Application::Components::Board::SetBoardPos( { a_boardPosX, a_boardPosY } );
}


/// 
/// @public
/// @brief Getter funciton to get the number of rows in the board
/// 
/// @returns number of rows in the board
///
const unsigned Brood::Application::Components::Board::GetNumRow()  const
{
	return m_numRows;
}

/// 
/// @public
/// @brief Getter funciton to get the number of columns in the board
/// 
/// @returns number of columns in the board
///
const unsigned Brood::Application::Components::Board::GetNumCol() const
{
	return m_numCols;
}

/// 
/// @public
/// @brief Getter funciton to get the board size
/// 
/// @returns board size
///
const sf::Vector2f Brood::Application::Components::Board::GetBoardSize() const
{
	return m_boardBody.getSize();
}


/// 
/// @public
/// @brief Getter funciton to get the board position
/// 
/// @returns board position
///
const sf::Vector2f Brood::Application::Components::Board::GetBoardPos() const
{
	return m_boardBody.getPosition();
}

/// 
/// @public
/// @brief Getter funciton to get the board path list by reference
/// 
/// @returns  board path list by reference
///
const std::vector<std::vector<Brood::Application::Components::Path*>>& Brood::Application::Components::Board::GetBoardPathList() const
{
	return m_boardPaths;
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// This function helps in debugging the UI elements. Called once at the 
///		end of Inialization.
///
void Brood::Application::Components::Board::Debugger()
{
	std::vector< std::vector<Path*> >::iterator rowTile;
	std::vector<Path*>::iterator colTile;

	// iterating over the rows
	for( rowTile = m_boardPaths.begin(); rowTile != m_boardPaths.end(); rowTile++ )
	{
		// iterating over the columns
		for( colTile = rowTile->begin(); colTile != rowTile->end(); colTile++ )
		{
			( *colTile )->GetTilePtr()->Debugger();
		}
	}
}

/// 
/// @private 
/// @brief Increases and populates the number of row in the board and
///		updates the old tiles
///
/// @param a_numRows number of tile rows to set in a board 
/// 
void Brood::Application::Components::Board::IncreaseNumRow( unsigned a_numRows )
{
	// saving the curr row num for later use
	unsigned lastRowNum = m_numRows;
	m_numRows = a_numRows;

	// resizing the board tiles
	m_boardPaths.resize( m_numRows, std::vector<Path*>( m_numCols ) );

	// only change the tile sets it the lastRowNum and colNUm is not zero
	if( m_numRows == 0 || m_numCols == 0 )
	{
		return;
	}

	float tileSizex = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	// updating the old tiles's size and position in the board
	// ignore if the lastRow num == 0 as there are no tiles to be updated
	if( lastRowNum != 0 )
	{
		UpdateBoardPath( 0, lastRowNum, 0, m_numCols );
	}

	// creating new tiles for newly added rows
	UpdateBoardPath( lastRowNum, m_numRows, 0, m_numCols, true );
}

/// 
/// @private 
/// @brief Decreases the number of row in the board and updates the old tiles 
///		and deallocates the removed row
///
/// @param a_numRows number of tile rows to set in a board 
/// 
void Brood::Application::Components::Board::DecreaseNumRow( unsigned a_numRows )
{
	// saving the curr row num for later use
	unsigned lastRowNum = m_numRows;
	m_numRows = a_numRows;

	// deallocating the tiles in the row that needs to be romoved
	// m_numRows < lastRowNum this is alwyas the case if this funciton is called
	unsigned currRowNum = m_numRows;
	for( ; currRowNum < lastRowNum; ++currRowNum )
	{
		for( unsigned currColNum = 0; currColNum < m_numCols; ++currColNum )
		{
			delete ( m_boardPaths.at( currRowNum ).at( currColNum ) );
		}
	}

	// resizing the board tiles
	m_boardPaths.resize( m_numRows, std::vector<Path*>( m_numCols ) );

	// only change the tile sets it the lastRowNum and colNUm is not zero
	if( m_numRows == 0 || m_numCols == 0 )
	{
		return;
	}

	float tileSizex = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	// updating the old tiles's size and position in the board
	UpdateBoardPath( 0, m_numRows, 0, m_numCols );
}

/// 
/// @private 
/// @brief Increases and populates the number of columns in the board and
///		updates the old tiles
///
/// @param a_numCols number of tile cols to set in a board 
/// 
void Brood::Application::Components::Board::IncreaseNumCol( unsigned a_numCols )
{
	// saving the curr row num for later use
	unsigned lastColNum = m_numCols;
	m_numCols = a_numCols;

	// resizing the board tiles
	for( unsigned currRowNum = 0; currRowNum < m_numRows; ++currRowNum )
	{
		m_boardPaths.at( currRowNum ).resize( m_numCols );
	}

	// only change the tile sets it the lastRowNum and colNUm is not zero
	if( m_numRows == 0 || lastColNum == 0 )
	{
		return;
	}

	float tileSizex = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	// updating the old tiles's size and position in the board
	// ignore if the lastColnum == 0 as there are no tiles to be updated
	if( lastColNum != 0 )
	{
		UpdateBoardPath( 0, m_numRows, 0, lastColNum );
	}

	// creating new tiles for newly added col
	UpdateBoardPath( 0, m_numRows, lastColNum, m_numCols, true );
}

/// 
/// @private 
/// @brief Decreases the number of columns in the board and updates the old tiles 
///		and deallocates the removed columns
///
/// @param a_numCols number of tile columns to set in a board 
/// 
void Brood::Application::Components::Board::DecreaseNumCol( unsigned a_numCols )
{
	// saving the curr column num for later use
	unsigned lastColNum = m_numCols;
	m_numCols = a_numCols;

	// deallocating the tiles in the column that needs to be romoved
	// m_numCols < m_numCols this is alwyas the case if this funciton is called

	for( unsigned currRowNum = 0; currRowNum < m_numRows; ++currRowNum )
	{
		for( unsigned currColNum = m_numCols; currColNum < lastColNum; ++currColNum )
		{
			delete ( m_boardPaths.at( currRowNum ).at( currColNum ) );
		}
	}

	// resizing the board tiles
	// resizing the board tiles
	for( unsigned currRowNum = 0; currRowNum < m_numRows; ++currRowNum )
	{
		m_boardPaths.at( currRowNum ).resize( m_numCols );
	}

	// only change the tile sets it the lastRowNum and colNUm is not zero
	if( m_numRows == 0 || m_numCols == 0 )
	{
		return;
	}

	float tileSizex = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	// updating the old tiles's size and position in the board
	UpdateBoardPath( 0, m_numRows, 0, m_numCols );
}

/// @private 
/// @brief updates the path specified by passed param in board by using the member variables.
/// 
///	It updates the tile starting form a_rowBegin to including a_rowEnd  for the rows and 
///		for the column starting from a_colBegin to including a_colEnd. It calls 
///		Brood::Application::Components::Tiles::UpdateTile() on each tile.
/// 
/// @param a_rowBegin index of row from where the tiles update should start
/// @param a_rowEnd index of row from where the tiles update should end
/// @param a_colBegin index of column from where the tiles update should start
/// @param a_colEnd index of column from where the tiles update should end
/// @param a_createNew true if new tiles should be created before updating the tiles -> default false
///  
void Brood::Application::Components::Board::UpdateBoardPath( unsigned a_rowBegin, unsigned a_rowEnd,
															 unsigned a_colBegin, unsigned a_colEnd,
															 bool a_createNew )
{
	float tileSizex = m_boardBody.getSize().x / m_numCols;
	float tileSizeY = m_boardBody.getSize().y / m_numRows;

	for( unsigned currRowNum = a_rowBegin; currRowNum < a_rowEnd; ++currRowNum )
	{
		for( unsigned currColNum = a_colBegin; currColNum < a_colEnd; ++currColNum )
		{
			if( a_createNew )
			{
				m_boardPaths.at( currRowNum ).at( currColNum ) = new Path();
			}

			m_boardPaths.at( currRowNum ).at( currColNum )->GetTilePtr()->UpdateTile( currRowNum, currColNum,
																					  tileSizex, tileSizeY,
																					  m_boardBody.getPosition().x,
																					  m_boardBody.getPosition().y );
		}
	}
}

/// 
/// @public
/// @brief incapsulate the player Manager addNewPlayer
/// 
// void Board::AddPlayer( float a_playerSizeX, float a_playerSizeY,
//							  int a_playerStartRow, int a_playerStartCol )
//{
//	m_playerManger.AddNewPlayer( a_playerSizeX, a_playerSizeY,
//								 a_playerStartRow, a_playerStartCol );
//}

/// 
/// @public
/// @brief Getter function 
/// @return a const reference to the dice member variable
// Brood::Dice& Board::GetDice()
//{
//	return m_dice;
//}

/// 
/// @public
/// @brief Moves the player along the path with 
///		respect to the dice roll
/// 
/// @param a_player pointer to the player to move
///  
//void Board::PlayerRollAndMove()
//{
//	// checking if there are players or not
//	Player* currPlayer = m_playerManger.GetNextPlayer();
//
//	if( currPlayer == nullptr )
//	{
//		std::cerr << "no player in the board" << std::endl;
//	}
//
//	// rolling the dice
//	unsigned diceRoll = m_dice.RollDice();
//
//	// getting the listIterator stored in the a_player
//	std::list<st_path*>::iterator tempPathIte = currPlayer->GetCurrPathPos();
//
//	// increasing the player along the path according the the dice roll
//	for( unsigned i = 0; i < diceRoll; ++i )
//	{
//		++tempPathIte;
//
//		// check if end is reached
//		if( tempPathIte == m_pathsList.GetPathEnd() )
//		{
//			// end reached 
//			--tempPathIte;
//			break;
//		}
//	}
//
//	// updating the player with new pos
//	currPlayer->SetPosition( tempPathIte );
//}

//void Board::Update()
//{
//	
//	// checking if dice was clicked
//	if( m_dice.DoElement() )
//	{
//		PlayerRollAndMove();
//	}
//}

// ======================================================================
// ================= end of Board class =================================
// ======================================================================
