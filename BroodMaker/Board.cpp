#include "Board.h"

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

void Board::InitializeBoard( int a_numRows, int a_numCols,
							 float a_boardSizeX, float a_boardSizeY,
							 float a_boardPosX, float a_boardPosY )
{
	// setting up the column and row number
	this->m_numRows = a_numRows;
	this->m_numCols = a_numCols;

	// setting up the board body
	this->m_boardBody.setSize( sf::Vector2f( a_boardSizeX, a_boardSizeY ) );
	this->m_boardBody.setPosition( a_boardPosX, a_boardPosY );
	this->m_boardBody.setFillColor( sf::Color::Blue );

	// creating and adding tiles to the board
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
			std::cout << ( *colTile )->GetPos().x << " " << ( *colTile )->GetPos().y << std::endl;
			++currCol;
		}
		currCol = 0; // resetting the col value
		++currRow;
	}
}
