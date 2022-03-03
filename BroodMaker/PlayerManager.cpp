#include "PlayerManager.h"

PlayerManager::~PlayerManager()
{
	// destroying the players
	std::vector<Player*>::iterator currPlayer = m_allPlayers.begin();
	for( ; currPlayer != m_allPlayers.end(); ++currPlayer )
	{
		delete( *currPlayer );
	}
}


/// 
/// @public
/// @brief adds a player
/// 
/// @param a_pathManager const reference to path manager
/// @param a_playerSizeX size of the player in x-asix -> default 0.f
/// @param a_playerSizeY size of the player in y-asix -> default 0.f
/// @param a_playerStartRow represents on which row number 
///			the player starts -> default 0
/// @param a_PlayerStartCol represents on which column number 
///			the player starts-> default 0
///  
void PlayerManager::AddNewPlayer( float a_playerSizeX, float a_playerSizeY,
								  int a_playerStartRow, int a_playerStartCol)
{
	// getting the path 
	st_path tempPath( a_playerStartRow, a_playerStartCol );
	std::list<st_path*>::iterator playerPathIte = m_PathManagerIte->GetPathBegin();
	for( ; playerPathIte != m_PathManagerIte->GetPathEnd(); ++playerPathIte )
	{
		if( tempPath == *( *playerPathIte ) )
		{
			break;
		}
	}

	// checking the path was found
	// this should not be a concernt for now as this is hard coded
	///@todo proper error handeling
	if( playerPathIte == m_PathManagerIte->GetPathEnd() )
	{
		std::cout << "Error! Invalid row or column number" << std::endl;
		return;
	}

	// getting the tile size
	float tileSizeX = m_BoardParmIte->stm_boardSizeX / m_BoardParmIte->stm_numCols;
	float tileSizeY = m_BoardParmIte->stm_boardSizeY / m_BoardParmIte->stm_numRows;

	Player* tempPlayer = new Player( playerPathIte, a_playerSizeX, a_playerSizeY,
									 m_BoardParmIte->stm_boardPosX, m_BoardParmIte->stm_boardPosY,
									 tileSizeX, tileSizeY );
	// adding tempPlayer to the m_allPlayers
	m_allPlayers.push_back( tempPlayer );

	// checking if this is the first player created
	if( m_allPlayers.size() == 1 )
	{
		m_currPlayerIdx = 0;
	}
}

/// 
/// @public
/// @brief Getter function to get next player in the list
/// @return next player who is supposed to be players if list is not empty
///	@return nullptr if the list is empty
Player* PlayerManager::GetNextPlayer()
{
	// no player in the list
	if( m_currPlayerIdx == -1 )
	{
		return nullptr;
	}

	++m_currPlayerIdx;
	if( m_currPlayerIdx == m_allPlayers.size() )
	{
		// looping to the first player
		m_currPlayerIdx = 0;
	}

	return m_allPlayers.at( m_currPlayerIdx );
}


