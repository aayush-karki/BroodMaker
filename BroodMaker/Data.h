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
	/// @ingroup Application
	/// @addtogroup Data 
	///
	namespace Data
	{
		struct ST_GameData; /// contains all the general data about the game
		struct ST_BoardData; /// data for a board
		struct ST_CardInfoPrefabData; /// data for a card
		struct ST_DeckPrefabData; /// data for a deck
		struct ST_DeckManagerData; /// data for a deck manager
		struct ST_DicePrefabData; /// data for a dice
		struct ST_DisplayCardData; /// data for a display card
		struct ST_PlayerPrefabData; /// data data for a player
		struct ST_PlayerManagerData; /// data for a player manager
		struct ST_PathPrefabData; /// data for a path
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ST_GameData struct defination =============
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_ApplicationData
/// @brief contains all the general data about the game
///  
struct Brood::Application::Data::ST_GameData
{
	/// name of the game; std:string
	std::string stm_gameTitle;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString(std::string a_string);

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();

	//int stm_totalTileTypes; /// total number of tile prefabs
	//int stm_totalDeckTypes; /// total number of deck prefabs
	//int stm_totalDiceTypes; /// total number of dice prefabs
	//int stm_totalPLayerTypes;  /// total number of player prefabs
	//int stm_playerNum; /// number of player set
	//int stm_minPlayerNumer;  /// minimum number of player required to play the game
	//int stm_maxPlayerNumer; /// maximum number of player allowed for a game
	//int stm_currPlayerTurn; /// index of player whose turn it is currently
	////std::vector<int stm_tileIdList; /// list of prefab tile's unique id for each tile.
	////								 /// number of element == numCol * numRow
	////std::vector<int stm_deckIdList; /// list of prefab deck's unique id for each deck.
	////								 /// number of element == numDeck
	////std::vector<int stm_diceIdList; // list of prefab dice's unique id for each dice.
	////								 /// number of element == numDice
	////std::vector<int stm_playerIdList; /// list of player 's unique id
	////								   /// number of element == numPlayer
	////								   /// in playing order.
	////std::vector<int stm_playedCardIdList; /// list of played card's unique id
};

// ======================================================================
// ================= end of ST_GameData struct defination ===============
// ======================================================================

// ======================================================================
// ================= start of ST_BoardData struct defination ============
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_BoardData
/// @brief contains data about the board
///  
struct Brood::Application::Data::ST_BoardData
{
	/// length of board
	float stm_boardSizeX;

	/// height of board
	float stm_boardSizeY;

	/// x-cordinate of board's upper left corner
	float stm_boardPosX;

	/// y-cordinate of board's upper left corner
	float stm_boardPosY;

	/// number of tile Row in the board
	unsigned stm_numRow;

	/// number of tile column in the board
	unsigned stm_numCol;

	/// tile row number of the active tile
	unsigned stm_currActiveNumRow;

	/// tile column number of the active tile
	unsigned stm_currActiveNumCol;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_BoardData struct defination ==============
// ======================================================================

// ======================================================================
// ================= start of ST_CardInfoPrefabData struct defination =======
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_CardPrefabData
/// @brief data in a card and other use full data
/// 
/// card data is loaded into this from a file / stored into a file
///
struct Brood::Application::Data::ST_CardInfoPrefabData
{
	// ===== data in the front of the card =====

	/// number of second that the user has to answer the question
	unsigned stm_time;

	/// number of steps the user takes when their answer is correct
	unsigned stm_correctNumSteps;

	/// number of steps the user takes when their answer is incorrect
	unsigned stm_incorrectNumSteps;

	// ===== data in the back of the card =====

	/// question in the card
	std::string stm_question;

	/// correct answer to the quesiton
	std::string stm_correctAnswer;

	/// index of the deck that this card is part of
	unsigned stm_deckIndex;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_CardInfoPrefabData struct defination =====
// ======================================================================

// ======================================================================
// ================= start of ST_DeckPrefabData struct defination =======
// ======================================================================

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
	/// length of deck
	float stm_deckSizeX;

	/// height of deck
	float stm_deckSizeY;

	/// x-cordinate of deck's upper left corner
	float stm_deckPosX;

	/// y-cordinate of deck's upper left corner
	float stm_deckPosY;

	/// filename for the texture
	std::string stm_textureFileName;

	/// filename for the card init
	std::string stm_cardInitFilename;

	/// number of card in this deck
	unsigned stm_numTotalCard;

	/// idx of undealt card in this deck
	unsigned stm_undealtCardIdx;

	/// idx of current active card in this deck
	unsigned stm_currActiveCardIdx;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_DeckPrefabData struct defination =========
// ======================================================================

// ======================================================================
// ================= start of ST_DeckManagerData struct defination =======
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_DeckManagerData
/// @brief contains deck manager data for one deck prefab
///  
struct Brood::Application::Data::ST_DeckManagerData
{
	/// movementType of the deck; 
	/// Brood::Application::Components::ENUM_MovementType stored as unsigned
	unsigned stm_movementType;

	/// incorrect penalty for the game
	bool stm_incorrectPenalty;

	/// total number of deck
	unsigned stm_numDecks;

	/// current deck idx
	unsigned stm_currDecksIdx;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_DeckManagerData struct defination =========
// ======================================================================

// ======================================================================
// ================= start of ST_DicePrefabData struct defination =======
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_DicePrefabData
/// @brief contains dice prefab data
/// 
struct Brood::Application::Data::ST_DicePrefabData
{
	/// number of side in the dice
	unsigned stm_numSides;

	/// length of dice
	float stm_diceSizeX;

	/// height of dice
	float stm_diceSizeY;

	/// x-cordinate of dice's upper left corner
	float stm_dicePosX;

	/// y-cordinate of dice's upper left corner
	float stm_dicePosY;

	/// filename for the texture
	std::string stm_textureFileName;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_DicePrefabData struct defination =========
// ======================================================================

// ======================================================================
// ================= start of ST_DisplayCardData struct defination ======
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_DisplayCardData
/// @brief contains display card data
/// 
struct Brood::Application::Data::ST_DisplayCardData
{
	// ========== Display Card Setting ==============

	/// length of display card
	float stm_displayCardSizeX;

	/// width of display card
	float stm_displayCardSizeY;

	/// x-cordinate of display card's upper left corner
	float stm_displayCardPositionX;

	/// y-cordinate of display card's upper left corner
	float stm_displayCardPositionY;

	/// filename for the front card texture
	std::string stm_displayCardFrontTextureFilename;

	/// filename for the back card texture
	std::string stm_displayCardBackTextureFilename;

	// ========= display Card front component setting ===========

	/// length of front Time Prompt
	float stm_frontTimePromptSizeX;

	/// width of front Time Prompt
	float stm_frontTimePromptSizeY;

	/// x-cordinate of front Time Prompt's upper left corner
	float stm_frontTimePromptPositionX;

	/// y-cordinate of front Time Prompt's upper left corner
	float stm_frontTimePromptPositonY;

	/// length of front time value
	float stm_frontTimeValueSizeX;

	/// width of front time value
	float stm_frontTimeValueSizeY;

	/// y-cordinate of front time value's upper left corner
	float stm_frontTimeValuePositionX;

	/// x-cordinate of front time value's upper left corner
	float stm_frontTimeValuePositonY;

	/// length of up prompt
	float stm_upPromptSizeX;

	/// width of up prompt
	float stm_upPromptSizeY;

	/// x-cordinate of up prompt's upper left corner
	float stm_upPromptPositionX;

	/// y-cordinate of up prompt's upper left corner
	float stm_upPromptPositonY;

	/// length of up value
	float stm_upValueSizeX;

	/// width of up value
	float stm_upValueSizeY;

	/// x-cordinate of up value's upper left corner
	float stm_upValuePositionX;

	/// y-cordinate of up value's upper left corner
	float stm_upValuePositonY;

	/// length of down prompt
	float stm_downPromptSizeX;

	/// width of down prompt
	float stm_downPromptSizeY;

	/// x-cordinate of down prompt's upper left corner
	float stm_downPromptPositionX;

	/// y-cordinate of down prompt's upper left corner
	float stm_downPromptPositonY;

	/// length of down value
	float stm_downValueSizeX;

	/// width of down value
	float stm_downValueSizeY;

	/// x-cordinate of down value's upper left corner
	float stm_downValuePositionX;

	/// y-cordinate of down value's upper left corner
	float stm_downValuePositonY;

	/// length of turn card prompt
	float stm_turnCardPromptSizeX;

	/// width of turn card prompt
	float stm_turnCardPromptSizeY;

	/// x-cordinate of turn card prompt's upper left corner
	float stm_turnCardPromptPositionX;

	/// y-cordinate of turn card prompt's upper left corner
	float stm_turnCardPromptPositonY;

	// ========== display Card back component setting ============

	/// length of back time prompt
	float stm_backTimePromptSizeX;

	/// width of back time prompt
	float stm_backTimePromptSizeY;

	/// x-cordinate of back time prompt's upper left corner
	float stm_backTimePromptPositionX;

	/// y-cordinate of back time prompt's upper left corner
	float stm_backTimePromptPositonY;

	/// length of back time value
	float stm_backTimeValueSizeX;

	/// width of back time value
	float stm_backTimeValueSizeY;

	/// x-cordinate of back time value's upper left corner
	float stm_backTimeValuePositionX;

	/// y-cordinate of back time value's upper left corner
	float stm_backTimeValuePositonY;

	/// length of question prompt
	float stm_questionPromptSizeX;

	/// width of question prompt
	float stm_questionPromptSizeY;

	/// x-cordinate of question prompt's upper left corner
	float stm_questionPromptPositionX;

	/// y-cordinate of question prompt's upper left corner
	float stm_questionPromptPositonY;

	/// length of question value
	float stm_questionValueSizeX;

	/// width of question value
	float stm_questionValueSizeY;

	/// x-cordinate of question value's upper left corner
	float stm_questionValuePositionX;

	/// y-cordinate of question value's upper left corner
	float stm_questionValuePositonY;

	/// length of answer prompt
	float stm_answerPromptSizeX;

	/// width of answer prompt
	float stm_answerPromptSizeY;

	/// x-cordinate of answer prompt's upper left corner
	float stm_answerPromptPositionX;

	/// y-cordinate of answer prompt's upper left corner
	float stm_answerPromptPositonY;

	/// length of answer value
	float stm_answerValueSizeX;

	/// width of answer value
	float stm_answerValueSizeY;

	/// x-cordinate of answer value's upper left corner
	float stm_answerValuePositionX;

	/// y-cordinate of answer value's upper left corner
	float stm_answerValuePositonY;

	/// length of submit button value
	float stm_submitButtonValueSizeX;

	/// width of submit button value
	float stm_submitButtonValueSizeY;

	/// x-cordinate of submit button value's upper left corner
	float stm_submitButtonValuePositionX;

	/// y-cordinate of submit button value's upper left corner
	float stm_submitButtonValuePositonY;

	// =========== functions ============= 
	
	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_DisplayCardData struct defination ========
// ======================================================================

// ======================================================================
// ================= start of ST_PlayerPrefabData struct defination =====
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_PlayerPrefabData
/// @brief contains player prefab data
/// 
struct Brood::Application::Data::ST_PlayerPrefabData
{
	/// tile row where the player is
	float  stm_currRow;

	/// tile column where the player is 
	float stm_currCol;

	/// length of player
	float stm_playerSizeX;

	/// height of player
	float stm_playerSizeY;

	/// x-offset of player
	int stm_playerOffsetX;

	/// y-offset of player
	int stm_playerOffsetY;

	/// filename for the texture
	std::string stm_textureFileName;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_PlayerPrefabData struct defination =======
// ======================================================================


// ======================================================================
// ================= start of ST_PlayerManagerData struct defination =====
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_PlayerManagerData
/// @brief contains player manager data
/// 
struct Brood::Application::Data::ST_PlayerManagerData
{
	/// minimum number of player; unsinged
	unsigned stm_minPlayer;

	/// maximum number of player; unsinged
	unsigned stm_maxPlayer;

	/// current player idx; unsinged
	unsigned stm_currPlayerIdx;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_PlayerManagerData struct defination =======
// ======================================================================


// ======================================================================
// ================= start of ST_PathPrefabData struct defination =======
// ======================================================================

/// 
/// @ingroup Data
/// @struct ST_TilePrefabData
/// @brief contains tile data for one tile prefab
/// 
struct  Brood::Application::Data::ST_PathPrefabData
{
	/// type of the tile  has number;
	/// Brood::Application::Components::ENUM_TileType stored as unsigned
	unsigned stm_tileType;

	/// tile row num
	unsigned stm_RowNum;

	/// tile column num
	unsigned stm_ColNum;

	/// next tile row num
	unsigned stm_nextTileRowNum;

	/// next tile column num
	unsigned stm_nextTileColNum;

	/// end bridge tile row num
	unsigned stm_endBridgeTileRowNum;

	/// end bridge tile column num
	unsigned stm_endBridgeTileColNum;

	/// nubmer of card to draw
	unsigned stm_numberCardDraw;

	/// deck index that this tile is assigned to. 
	/// when player lands on this tile they will 
	/// draw adraw card from it.
	unsigned  stm_assignedDeckId;

	/// if true rolls dice instead of drawing a card
	bool stm_forceDiceRoll;

	/// filename for the texture; std::string
	std::string stm_textureFileName;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	std::string GetString();
};

// ======================================================================
// ================= end of ST_PathPrefabData struct defination =========
// ======================================================================
