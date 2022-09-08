/*************************************************************************/
/// 
/// @file Data.h 
/// 
/// @brief  This file is a header file for all the Data that the 
///		application uses
/// 
/// It  contains enums declaration used by the Application namely: 
///		movement type, and incorect penalty
/// 
/// It also contains all of the data sturct declaration used by the 
///		application namely: applicaiton data, board data, 
///		path data, tile data, deck data card data, player data, 
///		and dice data
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once

/// @TODO make a better image handler
/// @TODO add a image to  ST_TilePrefabaData, ST_DeckPrefabData,
///		ST_PlayerPrefabData, ST_DicePrefabData, and ST_CardPrefabData

/// @TODO create a system data that 
///		adds fonts, colors, size, screen height/length
///		and, current game status other things that the applicaiton might use
///		here
///		Basically have all the static system variables here...
///

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	///
	///
	/// @ingroup Application
	/// @addtogroup Data 
	///
	namespace Data
	{
		enum class ENUM_MovementType;
		enum class ENUM_IncorrectPenalty;

		// defining what component of this file will be inside namespace BroodUI
		struct ST_ApplicationData; ///> contains all the general data about the game
		struct ST_BoardData; ///> board data for a specific game
		struct ST_PathData; ///> path data for the board
		struct ST_TilePrefabData; ///> tile data for one type of tile
		struct ST_DeckPrefabData; ///> deck data for one type of deck
		struct ST_CardPrefabData; ///> card data for one card
		struct ST_PlayerPrefabData; ///> player data for one player
		struct ST_DicePrefabData; ///> dice data for one dice
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of button class ==============================
// ======================================================================

/// 
/// @ingroup Data
/// @enum ENUM_MovementType
/// @brief movement type specified for a tile 
/// 
enum class Brood::Application::Data::ENUM_MovementType
{
	MOVETYPE_dice, ///> when the dice is used to move
	MOVETYPE_card, ///> when the card is used to move
};

/// 
/// @ingroup Data
/// @enum ENUM_IncorrectPenalty
/// @brief IncorrectPenalty specified for a tile when player
///		lands on that tile and gets the answer incorrect. 
/// 
enum class Brood::Application::Data::ENUM_IncorrectPenalty
{
	INPENALTY_noPenalty, ///> when no penalty is given
	INPENALTY_cardPenalty, ///> when player moves back the number 
						  ///> of spaces specified in the card
};

/// 
/// @ingroup Data
/// @struct ST_ApplicationData
/// @brief contains all the general data about the game
///  
struct Brood::Application::Data::ST_ApplicationData
{
	

	int stm_totalTileTypes; ///> total number of tile prefabs
	int stm_totalDeckTypes; ///> total number of deck prefabs
	int stm_totalDiceTypes; ///> total number of dice prefabs
	int stm_totalPLayerTypes;  ///> total number of player prefabs
	int stm_playerNum; ///> number of player set
	int stm_minPlayerNumer;  ///> minimum number of player required to play the game
	int stm_maxPlayerNumer; ///> maximum number of player allowed for a game
	int stm_currPlayerTurn; ///> index of player whose turn it is currently
	std::vector<int> stm_tileIdList; ///> list of prefab tile's unique id for each tile.
									 ///> number of element == numCol * numRow
	std::vector<int> stm_deckIdList; ///> list of prefab deck's unique id for each deck.
									 ///> number of element == numDeck
	std::vector<int> stm_diceIdList; // list of prefab dice's unique id for each dice.
									 ///> number of element == numDice
	std::vector<int> stm_playerIdList; ///> list of player 's unique id
									   ///> number of element == numPlayer
									   ///> in playing order.
	std::vector<int> stm_playedCardIdList; ///> list of played card's unique id
};

/// 
/// @ingroup Data
/// @struct ST_BoardData
/// @brief contains data about the board
///  
struct Brood::Application::Data::ST_BoardData
{
	float stm_boardPosX; ///> x-cordinate of board's upper left corner
	float stm_boardPosY; ///> y-cordinate of board's upper left corner
	float stm_tileSizeX; ///> length of one tile
	float stm_tileSizeY; ///> height of one tile
	int stm_numRow; ///> number of tile Row
	int stm_numColumn; ///> number of tile column
};

/// 
/// @ingroup Data
/// @struct ST_PathData
/// @brief contains path data
/// 
/// In the applicaiton Path is stored as a doublely linked list
///		 with bool is_bridge, bridge_tile_pointer, previous pointer, 
///		and nextpointer 
/// 
/// In the file, the line number indicats the tile number
///		and if the value is -1 then it is not a bridge tile
///		else the idx of tile is where the bridge would would take 
///		the player on correct answer
/// 
/// @note For a 3 by 3 board, the tile numbers is like row1(1-2-3-), 
///		row2(4-5-6-), and row3(7-8-9)
///  
struct Brood::Application::Data::ST_PathData
{
	std::vector<int> stm_pathData;
};

/// 
/// @ingroup Data
/// @struct ST_TilePrefabData
/// @brief contains tile data for one tile prefab
/// 
struct  Brood::Application::Data::ST_TilePrefabData
{
	/// @TODO add image 
	int stm_assignedDeckId; ///> unique id of the deck that tile uses to draw card from
	int stm_numberCardDraw; ///> nubmer of card to draw
	int stm_uniqueTileId; ///> unique tile prefab id
	bool stm_forceDiceRoll; ///> if true rolls dice instead of drawing a card
	Brood::Application::Data::ENUM_MovementType stm_movementType; /// type of the movement that the player will use on this tile
	Brood::Application::Data::ENUM_IncorrectPenalty stm_incorectPenaltyType; /// type of the penalty that the player will get on incorrect ansert
};

/// 
/// @ingroup Data
/// @struct ST_DeckPrefabData
/// @brief contains deck data for one deck prefab
/// 
/// Decks are unique in the released game. As the position of where they are in 
///		in the screen will be different
/// 
struct Brood::Application::Data::ST_DeckPrefabData
{
	/// @TODO add image , and filename to the card question
	int stm_uniqueDeckId; ///> unique deck prefab id
	int stm_numTotalCard; ///> number of card in this deck
	float stm_deckPosX; ///> x-cordinate of deck's upper left corner
	float stm_deckPosY; ///> y-cordinate of deck's upper left corner
	float stm_deckSizeX; ///> length of deck
	float stm_deckSizeY; ///> height of deck
};

/// 
/// @ingroup Data
/// @struct ST_CardPrefabData
/// @brief data in a card and other use full data
/// 
/// card data is loaded into this from a file / stored into a file
///
struct Brood::Application::Data::ST_CardPrefabData
{
	/// @TODO add image for bg(front and back) , and filename to the card question
	// data in the front of the card
	int stm_time; ///> number of second that the user has to answer the question
	int stm_correctNumSteps; ///> number of steps the user takes when their answer is correct
	int stm_incorrectNumSteps; ///> number of steps the user takes when their answer is incorrect

	// data in the back of the card
	std::string stm_question; ///> question in the card
	std::string stm_correctAnswer; ///> correct answer to the quesiton

	int stm_deckIndex; ///> index of the deck that this card is part of
};

/// 
/// @ingroup Data
/// @struct ST_PlayerPrefabData
/// @brief contains player prefab data
/// 
struct Brood::Application::Data::ST_PlayerPrefabData
{
	/// @TODO add image
	int stm_currColumn; ///> tile column where the player is 
	int stm_currRow; ///> tile row where the player is
	float stm_playerSizeX; ///> length of player
	float stm_playerSizeY; ///> height of player
	int stm_uniquePlayerId; ///> unique player prefab id
	int stm_playerIndex; ///> index of the plauyer in the stm_playerIdList
};

/// 
/// @ingroup Data
/// @struct ST_DicePrefabData
/// @brief contains dice prefab data
/// 
struct Brood::Application::Data::ST_DicePrefabData
{
	/// @TODO add image
	int stm_numSides; ///> number of side in the dice
	float stm_dicePosX; ///> x-cordinate of dice's upper left corner
	float stm_dicePosY; ///> y-cordinate of dice's upper left corner
	float stm_diceSizeX; ///> length of dice
	float stm_diceSizeY; ///> height of dice
};