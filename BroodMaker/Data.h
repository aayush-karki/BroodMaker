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

/// TODO initialize alll of the data here to match the default values


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
	std::string stm_gameTitle = "";

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString(std::string a_string);

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;

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
	float stm_boardSizeX = 0;

	/// height of board
	float stm_boardSizeY = 0;

	/// x-cordinate of board's upper left corner
	float stm_boardPosX = 0;

	/// y-cordinate of board's upper left corner
	float stm_boardPosY = 0;

	/// number of tile Row in the board
	unsigned stm_numRow = 1;

	/// number of tile column in the board
	unsigned stm_numCol = 1;

	/// tile row number of the active tile
	unsigned stm_currActiveNumRow = 0;

	/// tile column number of the active tile
	unsigned stm_currActiveNumCol = 0;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	unsigned stm_time = 0;

	/// number of steps the user takes when their answer is correct
	unsigned stm_correctNumSteps = 0;

	/// number of steps the user takes when their answer is incorrect
	unsigned stm_incorrectNumSteps = 0;

	// ===== data in the back of the card =====

	/// question in the card
	std::string stm_question = "";

	/// correct answer to the quesiton
	std::string stm_correctAnswer = "";

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	float stm_deckSizeX= 0;

	/// height of deck
	float stm_deckSizeY= 0;

	/// x-cordinate of deck's upper left corner
	float stm_deckPosX= 0;

	/// y-cordinate of deck's upper left corner
	float stm_deckPosY= 0;

	/// filename for the texture
	std::string stm_textureFileName = "";

	/// filename for the card init
	std::string stm_cardInitFilename = "";

	/// number of card in this deck
	unsigned stm_numTotalCard= 1;

	/// idx of undealt card in this deck
	unsigned stm_undealtCardIdx= 0;

	/// idx of current active card in this deck
	unsigned stm_currActiveCardIdx= 0;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	unsigned stm_movementType= 0;

	/// incorrect penalty for the game
	bool stm_incorrectPenalty= false;

	/// total number of deck
	unsigned stm_numDecks= 1;

	/// current deck idx
	unsigned stm_currDecksIdx= 0;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	unsigned stm_numSides= 6;

	/// length of dice
	float stm_diceSizeX= 0;

	/// height of dice
	float stm_diceSizeY= 0;

	/// x-cordinate of dice's upper left corner
	float stm_dicePosX= 0;

	/// y-cordinate of dice's upper left corner
	float stm_dicePosY= 0;

	/// filename for the texture
	std::string stm_textureFileName = "";

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	float stm_displayCardSizeX= 0;

	/// width of display card
	float stm_displayCardSizeY= 0;

	/// x-cordinate of display card's upper left corner
	float stm_displayCardPositionX= 0;

	/// y-cordinate of display card's upper left corner
	float stm_displayCardPositionY= 0;

	/// filename for the front card texture
	std::string stm_displayCardFrontTextureFilename = "";

	/// filename for the back card texture
	std::string stm_displayCardBackTextureFilename = "";

	// ========= display Card front component setting ===========

	/// length of front Time Prompt
	float stm_frontTimePromptSizeX= 0;

	/// width of front Time Prompt
	float stm_frontTimePromptSizeY= 0;

	/// x-cordinate of front Time Prompt's upper left corner
	float stm_frontTimePromptPositionX= 0;

	/// y-cordinate of front Time Prompt's upper left corner
	float stm_frontTimePromptPositonY= 0;

	/// length of front time value
	float stm_frontTimeValueSizeX= 0;

	/// width of front time value
	float stm_frontTimeValueSizeY= 0;

	/// y-cordinate of front time value's upper left corner
	float stm_frontTimeValuePositionX= 0;

	/// x-cordinate of front time value's upper left corner
	float stm_frontTimeValuePositonY= 0;

	/// length of up prompt
	float stm_upPromptSizeX= 0;

	/// width of up prompt
	float stm_upPromptSizeY= 0;

	/// x-cordinate of up prompt's upper left corner
	float stm_upPromptPositionX= 0;

	/// y-cordinate of up prompt's upper left corner
	float stm_upPromptPositonY= 0;

	/// length of up value
	float stm_upValueSizeX= 0;

	/// width of up value
	float stm_upValueSizeY= 0;

	/// x-cordinate of up value's upper left corner
	float stm_upValuePositionX= 0;

	/// y-cordinate of up value's upper left corner
	float stm_upValuePositonY= 0;

	/// length of down prompt
	float stm_downPromptSizeX= 0;

	/// width of down prompt
	float stm_downPromptSizeY= 0;

	/// x-cordinate of down prompt's upper left corner
	float stm_downPromptPositionX= 0;

	/// y-cordinate of down prompt's upper left corner
	float stm_downPromptPositonY= 0;

	/// length of down value
	float stm_downValueSizeX= 0;

	/// width of down value
	float stm_downValueSizeY= 0;

	/// x-cordinate of down value's upper left corner
	float stm_downValuePositionX= 0;

	/// y-cordinate of down value's upper left corner
	float stm_downValuePositonY= 0;

	/// length of turn card prompt
	float stm_turnCardPromptSizeX= 0;

	/// width of turn card prompt
	float stm_turnCardPromptSizeY= 0;

	/// x-cordinate of turn card prompt's upper left corner
	float stm_turnCardPromptPositionX= 0;

	/// y-cordinate of turn card prompt's upper left corner
	float stm_turnCardPromptPositonY= 0;

	// ========== display Card back component setting ============

	/// length of back time prompt
	float stm_backTimePromptSizeX= 0;

	/// width of back time prompt
	float stm_backTimePromptSizeY= 0;

	/// x-cordinate of back time prompt's upper left corner
	float stm_backTimePromptPositionX= 0;

	/// y-cordinate of back time prompt's upper left corner
	float stm_backTimePromptPositonY= 0;

	/// length of back time value
	float stm_backTimeValueSizeX= 0;

	/// width of back time value
	float stm_backTimeValueSizeY= 0;

	/// x-cordinate of back time value's upper left corner
	float stm_backTimeValuePositionX= 0;

	/// y-cordinate of back time value's upper left corner
	float stm_backTimeValuePositonY= 0;

	/// length of question prompt
	float stm_questionPromptSizeX= 0;

	/// width of question prompt
	float stm_questionPromptSizeY= 0;

	/// x-cordinate of question prompt's upper left corner
	float stm_questionPromptPositionX= 0;

	/// y-cordinate of question prompt's upper left corner
	float stm_questionPromptPositonY= 0;

	/// length of question value
	float stm_questionValueSizeX= 0;

	/// width of question value
	float stm_questionValueSizeY= 0;

	/// x-cordinate of question value's upper left corner
	float stm_questionValuePositionX= 0;

	/// y-cordinate of question value's upper left corner
	float stm_questionValuePositonY= 0;

	/// length of answer prompt
	float stm_answerPromptSizeX= 0;

	/// width of answer prompt
	float stm_answerPromptSizeY= 0;

	/// x-cordinate of answer prompt's upper left corner
	float stm_answerPromptPositionX= 0;

	/// y-cordinate of answer prompt's upper left corner
	float stm_answerPromptPositonY= 0;

	/// length of answer value
	float stm_answerValueSizeX= 0;

	/// width of answer value
	float stm_answerValueSizeY= 0;

	/// x-cordinate of answer value's upper left corner
	float stm_answerValuePositionX= 0;

	/// y-cordinate of answer value's upper left corner
	float stm_answerValuePositonY= 0;

	/// length of submit button value
	float stm_submitButtonValueSizeX= 0;

	/// width of submit button value
	float stm_submitButtonValueSizeY= 0;

	/// x-cordinate of submit button value's upper left corner
	float stm_submitButtonValuePositionX= 0;

	/// y-cordinate of submit button value's upper left corner
	float stm_submitButtonValuePositonY= 0;

	// =========== functions ============= 
	
	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	float  stm_currRow= 0;

	/// tile column where the player is 
	float stm_currCol= 0;

	/// length of player
	float stm_playerSizeX= 0;

	/// height of player
	float stm_playerSizeY= 0;

	/// x-offset of player
	int stm_playerOffsetX= 0;

	/// y-offset of player
	int stm_playerOffsetY= 0;

	/// filename for the texture
	std::string stm_textureFileName = "";

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	unsigned stm_minPlayer= 1;

	/// maximum number of player= 0; unsinged
	unsigned stm_maxPlayer= 1;

	/// current player idx= 0; unsinged
	unsigned stm_currPlayerIdx= 0;

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
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
	unsigned stm_tileType= 0;

	/// tile row num
	unsigned stm_RowNum= 0;

	/// tile column num
	unsigned stm_ColNum= 0;

	/// next tile row num
	unsigned stm_nextTileRowNum= 0;

	/// next tile column num
	unsigned stm_nextTileColNum= 0;

	/// end bridge tile row num
	unsigned stm_endBridgeTileRowNum= 0;

	/// end bridge tile column num
	unsigned stm_endBridgeTileColNum= 0;

	/// nubmer of card to draw
	unsigned stm_numberCardDraw= 0;

	/// deck index that this tile is assigned to. 
	/// when player lands on this tile they will 
	/// draw adraw card from it.
	unsigned  stm_assignedDeckId= 0;

	/// if true rolls dice instead of drawing a card
	bool stm_forceDiceRoll= false;

	/// filename for the texture; std::string
	std::string stm_textureFileName = "";

	// =========== functions ============= 

	// populates the struct from passed string
	void PopulateFromString( std::string a_string );

	// creats a string and appends each data to its back
	// seperated by ' '
	const std::string GetString() const;
};

// ======================================================================
// ================= end of ST_PathPrefabData struct defination =========
// ======================================================================
