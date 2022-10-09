/*************************************************************************/
/// 
/// @file GlobalVariables.cpp
/// 
/// @brief  This file is a source file for GlobalVariables stuct and
///		ColorVariable struct.
/// 
/// It contains all of the location declaration for the member the 
///		structs. 
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Data.h"

// ======================================================================
// ================= start of ST_GameData struct ========================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_GameData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_gameTitle;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_GameData::GetString()
{
	std::string dataString;

	dataString += stm_gameTitle + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_GameData struct defination ===============
// ======================================================================

// ======================================================================
// ================= start of ST_BoardData struct =======================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_BoardData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_numRow;
	stringBuffer >> stm_numCol;
	stringBuffer >> stm_boardSizeX;
	stringBuffer >> stm_boardSizeY;
	stringBuffer >> stm_boardPosX;
	stringBuffer >> stm_boardPosY;

}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_BoardData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_numRow ) + " ";
	dataString += std::to_string( stm_numCol ) + " ";
	dataString += std::to_string( stm_boardSizeX ) + " ";
	dataString += std::to_string( stm_boardSizeY ) + " ";
	dataString += std::to_string( stm_boardPosX ) + " ";
	dataString += std::to_string( stm_boardPosY ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_BoardData struct defination ==============
// ======================================================================

// ======================================================================
// ================= start of ST_CardInfoPrefabData struct ==============
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_CardInfoPrefabData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_time;
	stringBuffer >> stm_correctNumSteps;
	stringBuffer >> stm_incorrectNumSteps;
	stringBuffer >> stm_question;
	stringBuffer >> stm_correctAnswer;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_CardInfoPrefabData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_time );
	dataString += std::to_string( stm_correctNumSteps );
	dataString += std::to_string( stm_incorrectNumSteps );
	dataString += stm_question;
	dataString += stm_correctAnswer;

	return dataString;
}

// ======================================================================
// ================= end of ST_CardInfoPrefabData struct defination =====
// ======================================================================

// ======================================================================
// ================= start of ST_DeckPrefabData struct =================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_DeckPrefabData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_deckSizeX;
	stringBuffer >> stm_deckSizeY;
	stringBuffer >> stm_deckPosX;
	stringBuffer >> stm_deckPosY;
	stringBuffer >> stm_textureFileName;
	stringBuffer >> stm_numTotalCard;
	stringBuffer >> stm_cardInitFilename;
	stringBuffer >> stm_undealtCardIdx;
	stringBuffer >> stm_currActiveCardIdx;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_DeckPrefabData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_deckSizeX ) + " ";
	dataString += std::to_string( stm_deckSizeY ) + " ";
	dataString += std::to_string( stm_deckPosX ) + " ";
	dataString += std::to_string( stm_deckPosY ) + " ";
	dataString += stm_textureFileName + " ";
	dataString += std::to_string( stm_numTotalCard ) + " ";
	dataString += stm_cardInitFilename + " ";
	dataString += std::to_string( stm_undealtCardIdx ) + " ";
	dataString += std::to_string( stm_currActiveCardIdx ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_DeckPrefabData struct defination =========
// ======================================================================

// ======================================================================
// ================= start of ST_DeckManagerData struct =================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_DeckManagerData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_incorrectPenalty;
	stringBuffer >> stm_movementType;
	stringBuffer >> stm_currDecksIdx;
	stringBuffer >> stm_numDecks;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_DeckManagerData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_incorrectPenalty ) + " ";
	dataString += std::to_string( stm_movementType ) + " ";
	dataString += std::to_string( stm_currDecksIdx ) + " ";
	dataString += std::to_string( stm_numDecks ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_DeckManagerData struct defination ========
// ======================================================================

// ======================================================================
// ================= start of ST_DicePrefabData struct ==================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_DicePrefabData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_diceSizeX;
	stringBuffer >> stm_diceSizeY;
	stringBuffer >> stm_dicePosX;
	stringBuffer >> stm_dicePosY;
	stringBuffer >> stm_textureFileName;
	stringBuffer >> stm_numSides;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_DicePrefabData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_diceSizeX ) + " ";
	dataString += std::to_string( stm_diceSizeY ) + " ";
	dataString += std::to_string( stm_dicePosX ) + " ";
	dataString += std::to_string( stm_dicePosY ) + " ";
	dataString += stm_textureFileName + " ";
	dataString += std::to_string( stm_numSides );

	return dataString;
}

// ======================================================================
// ================= end of ST_DicePrefabData struct defination =========
// ======================================================================

// ======================================================================
// ================= start of ST_DisplayCardData struct =================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_DisplayCardData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	// saving up body
	stringBuffer >> stm_displayCardSizeX;
	stringBuffer >> stm_displayCardSizeY;
	stringBuffer >> stm_displayCardPositionX;
	stringBuffer >> stm_displayCardPositionY;

	// saving file texture
	stringBuffer >> stm_displayCardFrontTextureFilename;
	stringBuffer >> stm_displayCardBackTextureFilename;

	// displays time user have to complete the answer

	stringBuffer >> stm_frontTimePromptSizeX;
	stringBuffer >> stm_frontTimePromptSizeY;

	stringBuffer >> stm_frontTimePromptPositionX;
	stringBuffer >> stm_frontTimePromptPositonY;

	stringBuffer >> stm_frontTimeValueSizeX;
	stringBuffer >> stm_frontTimeValueSizeY;

	stringBuffer >> stm_frontTimeValuePositionX;
	stringBuffer >> stm_frontTimeValuePositonY;

	// displays number of steps that user goes forward

	stringBuffer >> stm_upPromptSizeX;
	stringBuffer >> stm_upPromptSizeY;

	stringBuffer >> stm_upPromptPositionX;
	stringBuffer >> stm_upPromptPositonY;

	stringBuffer >> stm_upValueSizeX;
	stringBuffer >> stm_upValueSizeY;

	stringBuffer >> stm_upValuePositionX;
	stringBuffer >> stm_upValuePositonY;

	// displays number of steps that user goes backward

	stringBuffer >> stm_downPromptSizeX;
	stringBuffer >> stm_downPromptSizeY;

	stringBuffer >> stm_downPromptPositionX;
	stringBuffer >> stm_downPromptPositonY;

	stringBuffer >> stm_downValueSizeX;
	stringBuffer >> stm_downValueSizeY;

	stringBuffer >> stm_downValuePositionX;
	stringBuffer >> stm_downValuePositonY;

	// button to turn the card of the card

	stringBuffer >> stm_turnCardPromptSizeX;
	stringBuffer >> stm_turnCardPromptSizeY;

	stringBuffer >> stm_turnCardPromptPositionX;
	stringBuffer >> stm_turnCardPromptPositonY;

	// ========= back of the card =========

	// displays time user have to complete the answer

	stringBuffer >> stm_backTimePromptSizeX;
	stringBuffer >> stm_backTimePromptSizeY;

	stringBuffer >> stm_backTimePromptPositionX;
	stringBuffer >> stm_backTimePromptPositonY;

	stringBuffer >> stm_backTimeValueSizeX;
	stringBuffer >> stm_backTimeValueSizeY;

	stringBuffer >> stm_backTimeValuePositionX;
	stringBuffer >> stm_backTimeValuePositonY;

	// displays the answer that user has to answer

	stringBuffer >> stm_answerPromptSizeX;
	stringBuffer >> stm_answerPromptSizeY;

	stringBuffer >> stm_answerPromptPositionX;
	stringBuffer >> stm_answerPromptPositonY;

	stringBuffer >> stm_answerValueSizeX;
	stringBuffer >> stm_answerValueSizeY;

	stringBuffer >> stm_answerValuePositionX;
	stringBuffer >> stm_answerValuePositonY;

	// displays the textbox for user to enter theiranswer

	stringBuffer >> stm_answerPromptSizeX;
	stringBuffer >> stm_answerPromptSizeY;

	stringBuffer >> stm_answerPromptPositionX;
	stringBuffer >> stm_answerPromptPositonY;

	stringBuffer >> stm_answerValueSizeX;
	stringBuffer >> stm_answerValueSizeY;

	stringBuffer >> stm_answerValuePositionX;
	stringBuffer >> stm_answerValuePositonY;

	// button to show back of the card
	stringBuffer >> stm_submitButtonValueSizeX;
	stringBuffer >> stm_submitButtonValueSizeY;

	stringBuffer >> stm_submitButtonValuePositionX;
	stringBuffer >> stm_submitButtonValuePositonY;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_DisplayCardData::GetString()
{
	std::string dataString;

	// saving up body
	dataString += std::to_string( stm_displayCardSizeX ) + " ";
	dataString += std::to_string( stm_displayCardSizeY ) + " ";
	dataString += std::to_string( stm_displayCardPositionX ) + " ";
	dataString += std::to_string( stm_displayCardPositionY ) + " ";

	// saving file texture
	dataString += stm_displayCardFrontTextureFilename + " ";
	dataString += stm_displayCardBackTextureFilename + " ";

	// displays time user have to complete the answer

	dataString += std::to_string( stm_frontTimePromptSizeX ) + " ";
	dataString += std::to_string( stm_frontTimePromptSizeY ) + " ";

	dataString += std::to_string( stm_frontTimePromptPositionX ) + " ";
	dataString += std::to_string( stm_frontTimePromptPositonY ) + " ";

	dataString += std::to_string( stm_frontTimeValueSizeX ) + " ";
	dataString += std::to_string( stm_frontTimeValueSizeY ) + " ";

	dataString += std::to_string( stm_frontTimeValuePositionX ) + " ";
	dataString += std::to_string( stm_frontTimeValuePositonY ) + " ";

	// displays number of steps that user goes forward

	dataString += std::to_string( stm_upPromptSizeX ) + " ";
	dataString += std::to_string( stm_upPromptSizeY ) + " ";

	dataString += std::to_string( stm_upPromptPositionX ) + " ";
	dataString += std::to_string( stm_upPromptPositonY ) + " ";

	dataString += std::to_string( stm_upValueSizeX ) + " ";
	dataString += std::to_string( stm_upValueSizeY ) + " ";

	dataString += std::to_string( stm_upValuePositionX ) + " ";
	dataString += std::to_string( stm_upValuePositonY ) + " ";

	// displays number of steps that user goes backward

	dataString += std::to_string( stm_downPromptSizeX ) + " ";
	dataString += std::to_string( stm_downPromptSizeY ) + " ";

	dataString += std::to_string( stm_downPromptPositionX ) + " ";
	dataString += std::to_string( stm_downPromptPositonY ) + " ";

	dataString += std::to_string( stm_downValueSizeX ) + " ";
	dataString += std::to_string( stm_downValueSizeY ) + " ";

	dataString += std::to_string( stm_downValuePositionX ) + " ";
	dataString += std::to_string( stm_downValuePositonY ) + " ";

	// button to turn the card of the card

	dataString += std::to_string( stm_turnCardPromptSizeX ) + " ";
	dataString += std::to_string( stm_turnCardPromptSizeY ) + " ";

	dataString += std::to_string( stm_turnCardPromptPositionX ) + " ";
	dataString += std::to_string( stm_turnCardPromptPositonY ) + " ";

	// ========= back of the card =========

	// displays time user have to complete the answer

	dataString += std::to_string( stm_backTimePromptSizeX ) + " ";
	dataString += std::to_string( stm_backTimePromptSizeY ) + " ";

	dataString += std::to_string( stm_backTimePromptPositionX ) + " ";
	dataString += std::to_string( stm_backTimePromptPositonY ) + " ";

	dataString += std::to_string( stm_backTimeValueSizeX ) + " ";
	dataString += std::to_string( stm_backTimeValueSizeY ) + " ";

	dataString += std::to_string( stm_backTimeValuePositionX ) + " ";
	dataString += std::to_string( stm_backTimeValuePositonY ) + " ";

	// displays the answer that user has to answer

	dataString += std::to_string( stm_answerPromptSizeX ) + " ";
	dataString += std::to_string( stm_answerPromptSizeY ) + " ";

	dataString += std::to_string( stm_answerPromptPositionX ) + " ";
	dataString += std::to_string( stm_answerPromptPositonY ) + " ";

	dataString += std::to_string( stm_answerValueSizeX ) + " ";
	dataString += std::to_string( stm_answerValueSizeY ) + " ";

	dataString += std::to_string( stm_answerValuePositionX ) + " ";
	dataString += std::to_string( stm_answerValuePositonY ) + " ";

	// displays the textbox for user to enter theiranswer

	dataString += std::to_string( stm_answerPromptSizeX ) + " ";
	dataString += std::to_string( stm_answerPromptSizeY ) + " ";

	dataString += std::to_string( stm_answerPromptPositionX ) + " ";
	dataString += std::to_string( stm_answerPromptPositonY ) + " ";

	dataString += std::to_string( stm_answerValueSizeX ) + " ";
	dataString += std::to_string( stm_answerValueSizeY ) + " ";

	dataString += std::to_string( stm_answerValuePositionX ) + " ";
	dataString += std::to_string( stm_answerValuePositonY ) + " ";

	// button to show back of the card
	dataString += std::to_string( stm_submitButtonValueSizeX ) + " ";
	dataString += std::to_string( stm_submitButtonValueSizeY ) + " ";

	dataString += std::to_string( stm_submitButtonValuePositionX ) + " ";
	dataString += std::to_string( stm_submitButtonValuePositonY ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_DisplayCardData struct defination ========
// ======================================================================

// ======================================================================
// ================= start of ST_PlayerPrefabData struct ================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_PlayerPrefabData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );


	stringBuffer >> stm_playerSizeX;
	stringBuffer >> stm_playerSizeY;
	stringBuffer >> stm_playerOffsetX;
	stringBuffer >> stm_playerOffsetX;
	stringBuffer >> stm_textureFileName;
	stringBuffer >> stm_currRow;
	stringBuffer >> stm_currCol;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_PlayerPrefabData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_playerSizeX ) + " ";
	dataString += std::to_string( stm_playerSizeY ) + " ";
	dataString += std::to_string( stm_playerOffsetX ) + " ";
	dataString += std::to_string( stm_playerOffsetX ) + " ";
	dataString += stm_textureFileName + " ";
	dataString += std::to_string( stm_currRow ) + " ";
	dataString += std::to_string( stm_currCol ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_PlayerPrefabData struct defination =======
// ======================================================================

// ======================================================================
// ================= start of ST_PlayerManagerData struct ===============
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_PlayerManagerData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_maxPlayer;
	stringBuffer >> stm_minPlayer;
	stringBuffer >> stm_currPlayerIdx;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
/// @return string containg all the data appended to it seperated 
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_PlayerManagerData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_maxPlayer ) + " ";
	dataString += std::to_string( stm_minPlayer ) + " ";
	dataString += std::to_string( stm_currPlayerIdx ) + " ";

	return dataString;
}

// ======================================================================
// ================= end of ST_PlayerManagerData struct defination ======
// ======================================================================

// ======================================================================
// ================= start of ST_PathPrefabData struct ==================
// ======================================================================

/// 
/// @public
/// @brief populates the struct from passed string
/// @param a_string string containing all of the data seperated by ' '
/// 
void Brood::Application::Data::ST_PathPrefabData::PopulateFromString( std::string a_string )
{
	std::stringstream stringBuffer( a_string );

	stringBuffer >> stm_tileType;
	stringBuffer >> stm_RowNum;
	stringBuffer >> stm_ColNum;
	stringBuffer >> stm_nextTileRowNum;
	stringBuffer >> stm_nextTileColNum;
	stringBuffer >> stm_endBridgeTileRowNum;
	stringBuffer >> stm_endBridgeTileColNum;
	stringBuffer >> stm_numberCardDraw;
	stringBuffer >> stm_assignedDeckId;
	stringBuffer >> stm_forceDiceRoll;
	stringBuffer >> stm_textureFileName;
}

/// 
/// @public
/// @brief  creats a string and appends each data to its back
/// seperated by ' '
///		by ' ' 
/// 
std::string Brood::Application::Data::ST_PathPrefabData::GetString()
{
	std::string dataString;

	dataString += std::to_string( stm_tileType ) + " ";
	dataString += std::to_string( stm_RowNum ) + " ";
	dataString += std::to_string( stm_ColNum ) + " ";
	dataString += std::to_string( stm_nextTileRowNum ) + " ";
	dataString += std::to_string( stm_nextTileColNum ) + " ";
	dataString += std::to_string( stm_endBridgeTileRowNum ) + " ";
	dataString += std::to_string( stm_endBridgeTileColNum ) + " ";
	dataString += std::to_string( stm_numberCardDraw ) + " ";
	dataString += std::to_string( stm_assignedDeckId ) + " ";
	dataString += std::to_string( stm_forceDiceRoll ) + " ";
	dataString += stm_textureFileName;

	return dataString;
}

// ======================================================================
// ================= end of ST_PathPrefabData struct defination =========
// ======================================================================
