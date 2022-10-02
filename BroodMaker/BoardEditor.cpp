/*************************************************************************/
/// 
/// @file BoardEditor.cpp 
/// 
/// @brief  This file is a source file for BoardEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of BoardEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "BoardEditor.h"

// ======================================================================
// ================= start of BoardEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
/// 
Brood::Application::BoardEditor::BoardEditor( Brood::Application::Components::Board* a_boardPtr,
											  Brood::Application::Components::Dice* a_dicePtr,
											  sf::RectangleShape* a_panelPtr ) :
	m_boardPtr( a_boardPtr ), m_dicePtr( a_dicePtr ),
	m_playerManager( m_boardPtr->GetBoardPathList().at( 0 ).at( 0 ) ),
	m_drawCurretntActivePlayer( false ), m_panelBodyPtr( a_panelPtr ), m_selectedSettingIdx( 0 )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::BoardEditor::~BoardEditor()
{
	// all the dynamically created panel elements are 
	// destructed in the base class
}


/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It inializes the board,
///		setting section Dropdown Input.
//
void Brood::Application::BoardEditor::InitializeWorkSpace()
{
	// Initializing the setting Section dropdown input
	InitailizeSettingSelectionDDI();

	// Initializing the general board setting panel element
	InitailizeGeneralBoardSettingPanel();

	// Initializing the player setting panel element
	InitailizePlayerSettingPanel();

	// Initializing the dice setting panel element
	InitailizeDiceSettingPanel();
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::BoardEditor::Update()
{
	// checking to see if the elments of the
	//	Drop down input was pressed
	UpdateSettingSelectionDDI();

	// if the General board setting is selected
	if( m_selectedSettingIdx == 0 )
	{
		UpdateGeneralBoardSettingPanel();
	}
	// if the player setting is selected
	else if( m_selectedSettingIdx == 1 )
	{
		UpdatePlayerSettingPanel();
	}
	// if the dice setting is selected
	else if( m_selectedSettingIdx == 2 )
	{
		UpdateDiceSettingPanel();
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
/// 
/// @param a_window reference to the render window
///
void Brood::Application::BoardEditor::Draw( sf::RenderWindow& a_window )
{
	if( m_drawCurretntActivePlayer )
	{
		m_playerManager.GetPlayerAtCurrIdx()->Draw( a_window );
	}

	// if the General Board setting is selected
	if( m_selectedSettingIdx == 0 )
	{
		DrawGeneralBoardSettingPanel( a_window );
	}
	// if the player setting is selected
	else if( m_selectedSettingIdx == 1 )
	{
		DrawPlayerSettingPanel( a_window );
	}
	// if the dice setting is selected
	else if( m_selectedSettingIdx == 2 )
	{
		DrawDiceSettingPanel(a_window);
	}

	// Drawing the setting selection drop down input
	m_ddiSettingSelection->Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::BoardEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}

/// 
/// @private
/// @brief Initializes the  setting Section dropdown input which is
///		at the top of the setting pannel
/// 
/// It has the 3 settings : Board Settings, Player Settings, and Dice Settings
/// 
void Brood::Application::BoardEditor::InitailizeSettingSelectionDDI()
{
	// initializing the setting selection DDI
	float panelSizeX = m_panelBodyPtr->getSize().x;
	float panelPosX = m_panelBodyPtr->getPosition().x;

	m_ddiSettingSelection = DyCreateDropDownInput( { panelSizeX , 40 },
												   { panelPosX, 50 },
												   Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	m_ddiSettingSelection->AddItemToMenu( "General Board Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Player Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Dice Setting" );

	// setting the font size to 18
	m_ddiSettingSelection->SetFontSize( 18 );

	// setting the first item as the first 
	std::string itemName = m_ddiSettingSelection->GetItemList().at( m_selectedSettingIdx )->GetText();

	while( itemName.size() < 39 )
	{
		itemName = " " + itemName + " ";
	}

	m_ddiSettingSelection->SetText( itemName + " v" );
}

/// 
/// @private
/// @brief Initializes the panel element of the general board setting 
/// 
/// It initializes the folloing panel element: 
///		board X-postion, board Y-position, boardX-size, board Y-Size, 
///		board row, board column, player movement-type, incorrect-penalty
/// 
void Brood::Application::BoardEditor::InitailizeGeneralBoardSettingPanel()
{
	// =======================================================================
	// ======= Initializing the elements in the  General board setting =======
	// =======================================================================

	// initializing the UI to control board's X position 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardPosPromtX, &m_btnBoardPosDecX,
								 &m_txtBoardPosX, &m_btnBoardPosIncX,
								 "X-Position", std::to_string( ( int )m_boardPtr->GetBoardPos().x ),
								 true );

	// initializing the UI to control board's Y position 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardPosPromtY, &m_btnBoardPosDecY,
								 &m_txtBoardPosY, &m_btnBoardPosIncY,
								 "Y-Position", std::to_string( ( int )m_boardPtr->GetBoardPos().y ) );

	// initializing the UI to control board's X size 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardSizePromtX, &m_btnBoardSizeDecX,
								 &m_txtBoardSizeX, &m_btnBoardSizeIncX,
								 "X-Size", std::to_string( ( int )m_boardPtr->GetBoardSize().x ) );

	// initializing the UI to control board's Y size 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardSizePromtY, &m_btnBoardSizeDecY,
								 &m_txtBoardSizeY, &m_btnBoardSizeIncY,
								 "Y-Size", std::to_string( ( int )m_boardPtr->GetBoardSize().y ) );

	// initializing the UI to control board's row
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardRowPromt, &m_btnBoardDecRow,
								 &m_txtBoardRow, &m_btnBoardIncRow,
								 "Row Number", std::to_string( ( int )m_boardPtr->GetNumRow() ) );

	// initializing the UI to control board's column
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardColPromt, &m_btnBoardDecCol,
								 &m_txtBoardCol, &m_btnBoardIncCol,
								 "Column Number", std::to_string( ( int )m_boardPtr->GetNumCol() ) );

	// initializing the UI to set the movement type
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtMovementTypePromt, &m_ddiMovementType,
										"Movement Type: ",
										{ "Star Dice then Card", "Dice Only", "Card Only" }, 19 );

	// initializing the UI to set the incorrect penalty
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtIncorectPenaltyPromt, &m_ddiIncorectPenalty,
										"Incorrect Penalty: ", { "Yes", "No" }, 27 );
}

/// 
/// @private
/// @brief Initializes the panel element of the general board setting 
/// 
/// It initializes the folloing panel element: 
///		Player start row, Player start column, Minimum Player number,
///		Maximum player number, Current player index, Draw current 
///		player, Current player X-Size, current player Y-size, 
///		Current player X-offset, Current player Y-offset, and
///		Current player texture file name
/// 
void Brood::Application::BoardEditor::InitailizePlayerSettingPanel()
{
	// =======================================================================
	// ======= Initializing the elements in the  General board setting =======
	// =======================================================================

	// initializing the UI to control Start row for new player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerStartRowPrompt, &m_btnPlayerDecStartRowNum,
								 &m_txtPlayerStartRowNum, &m_btnPlayerIncStartRowNum,
								 "Start Row",
								 std::to_string( 0 ), true );

	// initializing the UI to control Start column for new player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerStartColPrompt, &m_btnPlayerDecStartColNum,
								 &m_txtPlayerStartColNum, &m_btnPlayerIncStartColNum,
								 "Start Column",
								 std::to_string( 0 ) );

	// initializing the UI to control minimum number of player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerMinNumPrompt, &m_btnPlayerDecMinNum,
								 &m_txtPlayerMinNum, &m_btnPlayerIncMinNum,
								 "Minimum Players",
								 std::to_string( ( int )m_playerManager.GetMinPlayer() ) );

	// initializing the UI to control maximum number of player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerMaxNumPrompt, &m_btnPlayerDecMaxnNum,
								 &m_txtPlayerMaxNum, &m_btnPlayerIncMaxNum,
								 "Maximum Players",
								 std::to_string( ( int )m_playerManager.GetMaxPlayer() ) );

	// initializing the UI to control current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxPrompt, &m_btnPlayerDecCurrIdx,
								 &m_txtPlayerCurrIdx, &m_btnPlayerIncCurrIdx,
								 "Current Player Index",
								 std::to_string( ( int )m_playerManager.GetCurrActivePlayerIdx() ) );

	// initializing the UI to toggle draw player at current index 
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtDrawPlayerAtCurrIdxPromt, &m_ddiDrawPlayerAtCurrIdx,
										"Draw Current Player: ",
										{ "No", "Yes" }, 27 );

	// initializing the UI to control x-size of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxSizeXPrompt, &m_btnPlayerDecCurrIdxSizeX,
								 &m_txtPlayerCurrIdxSizeX, &m_btnPlayerIncCurrIdxSizeX,
								 "Current Player X-Size",
								 std::to_string( ( int )m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody().getSize().x ) );

	// initializing the UI to control y-size of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxSizeYPrompt, &m_btnPlayerDecCurrIdxSizeY,
								 &m_txtPlayerCurrIdxSizeY, &m_btnPlayerIncCurrIdxSizeY,
								 "Current Player Y-Size",
								 std::to_string( ( int )m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody().getSize().y ) );

	// initializing the UI to control x-offset of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxOffsetXPrompt, &m_btnPlayerDecCurrIdxOffsetX,
								 &m_txtPlayerCurrIdxOffsetX, &m_btnPlayerIncCurrIdxOffsetX,
								 "Player X-Offset",
								 std::to_string( ( int )m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetX() ) );

	// initializing the UI to control y-offset of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxOffsetYPrompt, &m_btnPlayerDecCurrIdxOffsetY,
								 &m_txtPlayerCurrIdxOffsetY, &m_btnPlayerIncCurrIdxOffsetY,
								 "Player Y-Offset",
								 std::to_string( ( int )m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetY() ) );

	// initializing the UI to control player file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtplayerFileNamePrompt, &m_txtPlayerFileInput,
									&m_btnPlayerOpenFile, "Player Texture Filename",
									m_playerManager.GetPlayerAtCurrIdx()->GetPlayerSpriteBody().GetTexturePath() );
}

/// 
/// @private
/// @brief Updates the panel element of the general board setting 
/// 
/// It Update the folloing panel element: 
///		board X-postion, board Y-position, boardX-size, board Y-Size, 
///		board row, board column, player movement-type, incorrect-penalty
///
void Brood::Application::BoardEditor::UpdateGeneralBoardSettingPanel()
{
	// checking to see if the Xpos panel Element was pressed
	UpdateBoardXPosPanelElement();

	// checking to see if the Ypos panel Element was pressed
	UpdateBoardYPosPanelElement();

	// checking to see if the Xsize panel Element was pressed
	UpdateBoardXSizePanelElement();

	// checking to see if the Ysize panel Element was pressed
	UpdateBoardYSizePanelElement();

	// checking to see if the row panel Element was pressed
	UpdateBoardRowPanelElement();

	// checking to see if the col panel Element was pressed
	UpdateBoardColPanelElement();

	// checking to see if the movement type panel Element
	// was pressed
	UpdateMovementTypePanelElement();

	// checking to see if the incorrect penalty panel 
	// Element was pressed
	UpdateIncorrectPenaltyPanelElement();
}

/// @private
/// @brief Draws the panel element of the general board setting 
/// 
/// It draws the folloing panel element: 
///		board X-postion, board Y-position, boardX-size, board Y-Size, 
///		board row, board column, player movement-type, incorrect-penalty
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::BoardEditor::DrawGeneralBoardSettingPanel( sf::RenderWindow& a_window )
{
	// Drawing the incorrect penalty panel Elements
	m_ddiIncorectPenalty->Draw( a_window );
	m_txtIncorectPenaltyPromt->Draw( a_window );

	// Drawing the movement type panel Elements
	m_ddiMovementType->Draw( a_window );
	m_txtMovementTypePromt->Draw( a_window );

	// Drawing the column panel Elements
	m_btnBoardIncCol->Draw( a_window );
	m_txtBoardCol->Draw( a_window );
	m_btnBoardDecCol->Draw( a_window );
	m_txtBoardColPromt->Draw( a_window );

	// Drawing the row panel Elements
	m_btnBoardIncRow->Draw( a_window );
	m_txtBoardRow->Draw( a_window );
	m_btnBoardDecRow->Draw( a_window );
	m_txtBoardRowPromt->Draw( a_window );

	// Drawing the Y size panel Elements
	m_btnBoardSizeIncY->Draw( a_window );
	m_txtBoardSizeY->Draw( a_window );
	m_btnBoardSizeDecY->Draw( a_window );
	m_txtBoardSizePromtY->Draw( a_window );

	// Drawing the X size panel Elements
	m_btnBoardSizeIncX->Draw( a_window );
	m_txtBoardSizeX->Draw( a_window );
	m_btnBoardSizeDecX->Draw( a_window );
	m_txtBoardSizePromtX->Draw( a_window );

	// Drawing the Y pos panel Elements
	m_btnBoardPosIncY->Draw( a_window );
	m_txtBoardPosY->Draw( a_window );
	m_btnBoardPosDecY->Draw( a_window );
	m_txtBoardPosPromtY->Draw( a_window );

	// Drawing the X pos panel Elements
	m_btnBoardPosIncX->Draw( a_window );
	m_txtBoardPosX->Draw( a_window );
	m_btnBoardPosDecX->Draw( a_window );
	m_txtBoardPosPromtX->Draw( a_window );
}

/// 
/// @private
/// @brief Updates the panel element of the player setting 
/// 
/// It Updates the folloing panel element: 
///		Player start row, Player start column, Minimum Player number,
///		Maximum player number, Current player index, Draw current 
///		player, Current player X-Size, current player Y-size, 
///		Current player X-offset, Current player Y-offset, and
///		Current player texture file name
///
void Brood::Application::BoardEditor::UpdatePlayerSettingPanel()
{
	// checking to see if the player start row number panel
			// element was pressed
	UpdateStartRowNumber();

	// checking to see if the player start column number 
	// panel element was pressed
	UpdateStartColNumber();

	// checking to see if the minimum Player number panel
	// element was pressed
	UpdateMinimumPlayerNumber();

	// checking to see if the maximum Player number panel
	// element was pressed
	UpdateMaximumPlayerNumber();

	// checking to see if the draw player at current index
	// panel element was pressed
	UpdateToggleDrawPlayerAtCurrIdx();

	// checking to see if the current selected player Index 
	// panel Element was pressed
	UpdateCurrSelectedPlayerIdx();

	// checking to see if the  x-size of current selected 
	// player Index panel Element was pressed
	UpdateCurrPlayerSizeX();

	// checking to see if the  y-size of current selected 
	// player Index panel Element was pressed
	UpdateCurrPlayerSizeY();

	// checking to see if the  x-offset of current selected 
	// player Index panel Element was pressed
	UpdateCurrPlayerOffsetX();

	// checking to see if the  y-offset of current selected 
	// player Index panel Element was pressed
	UpdateCurrPlayerOffsetY();

	// checks if the user interacted with the load 
	// player texture panel Element
	UpdateCurrPlayerFileTexture();
}

/// 
/// @private
/// @brief Draws the panel element of the general board setting 
/// 
/// It Draws the folloing panel element: 
///		Player start row, Player start column, Minimum Player number,
///		Maximum player number, Current player index, Draw current 
///		player, Current player X-Size, current player Y-size, 
///		Current player X-offset, Current player Y-offset, and
///		Current player texture file name
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::BoardEditor::DrawPlayerSettingPanel( sf::RenderWindow& a_window )
{
	// Drawing the player file name texture panel 
	// Elements
	m_btnPlayerOpenFile->Draw( a_window );
	m_txtPlayerFileInput->Draw( a_window );
	m_txtplayerFileNamePrompt->Draw( a_window );

	// Drawing the y-offset current Selected player 
	// index panel Elements
	m_btnPlayerIncCurrIdxOffsetY->Draw( a_window );
	m_txtPlayerCurrIdxOffsetY->Draw( a_window );
	m_btnPlayerDecCurrIdxOffsetY->Draw( a_window );
	m_txtPlayerCurrIdxOffsetYPrompt->Draw( a_window );

	// Drawing the X-offset current Selected player 
	// index panel Elements
	m_btnPlayerIncCurrIdxOffsetX->Draw( a_window );
	m_txtPlayerCurrIdxOffsetX->Draw( a_window );
	m_btnPlayerDecCurrIdxOffsetX->Draw( a_window );
	m_txtPlayerCurrIdxOffsetXPrompt->Draw( a_window );

	// Drawing the y-size current Selected player 
	// index panel Elements
	m_btnPlayerIncCurrIdxSizeY->Draw( a_window );
	m_txtPlayerCurrIdxSizeY->Draw( a_window );
	m_btnPlayerDecCurrIdxSizeY->Draw( a_window );
	m_txtPlayerCurrIdxSizeYPrompt->Draw( a_window );

	// Drawing the x-size current Selected player 
	// index panel Elements
	m_btnPlayerIncCurrIdxSizeX->Draw( a_window );
	m_txtPlayerCurrIdxSizeX->Draw( a_window );
	m_btnPlayerDecCurrIdxSizeX->Draw( a_window );
	m_txtPlayerCurrIdxSizeXPrompt->Draw( a_window );

	// Drawing the toggle draw player at current index
	m_ddiDrawPlayerAtCurrIdx->Draw( a_window );
	m_txtDrawPlayerAtCurrIdxPromt->Draw( a_window );

	// Drawing the current Selected player index
	// panel Elements
	m_btnPlayerIncCurrIdx->Draw( a_window );
	m_txtPlayerCurrIdx->Draw( a_window );
	m_btnPlayerDecCurrIdx->Draw( a_window );
	m_txtPlayerCurrIdxPrompt->Draw( a_window );

	// Drawing the maximum Player number panel Elements
	m_btnPlayerIncMaxNum->Draw( a_window );
	m_txtPlayerMaxNum->Draw( a_window );
	m_btnPlayerDecMaxnNum->Draw( a_window );
	m_txtPlayerMaxNumPrompt->Draw( a_window );

	// Drawing the minimum Player number panel Elements
	m_btnPlayerIncMinNum->Draw( a_window );
	m_txtPlayerMinNum->Draw( a_window );
	m_btnPlayerDecMinNum->Draw( a_window );
	m_txtPlayerMinNumPrompt->Draw( a_window );

	// Drawing the Start column number panel Elements
	m_btnPlayerIncStartColNum->Draw( a_window );
	m_txtPlayerStartColNum->Draw( a_window );
	m_btnPlayerDecStartColNum->Draw( a_window );
	m_txtPlayerStartColPrompt->Draw( a_window );

	// Drawing the Start row number panel Elements
	m_btnPlayerIncStartRowNum->Draw( a_window );
	m_txtPlayerStartRowNum->Draw( a_window );
	m_btnPlayerDecStartRowNum->Draw( a_window );
	m_txtPlayerStartRowPrompt->Draw( a_window );
}

/// 
/// @private
/// @brief Initializes the panel element of the dice setting 
/// 
/// It initializes the folloing panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works 
/// 
void Brood::Application::BoardEditor::InitailizeDiceSettingPanel()
{
	// =======================================================================
		// ======= Initializing the elements in the  dice setting =======
		// =======================================================================

		// initializing the UI to control number of sides for new Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSidePrompt, &m_btnDiceDecSide,
								 &m_txtDiceSide, &m_btnDiceIncSide,
								 "Dice Side Number",
								 std::to_string( m_dicePtr->GetNumSides() ), true );

	// initializing the UI to control x-size of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSizeXPrompt, &m_btnDiceDecSizeX,
								 &m_txtDiceSizeX, &m_btnDiceIncSizeX,
								 "Dice X-Size",
								 std::to_string( ( int )m_dicePtr->GetBodySize().x ) );

	// initializing the UI to control y-size of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSizeYPrompt, &m_btnDiceDecSizeY,
								 &m_txtDiceSizeY, &m_btnDiceIncSizeY,
								 "Dice Y-Size",
								 std::to_string( ( int )m_dicePtr->GetBodySize().y ) );

	// initializing the UI to control x-position of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDicePosXPrompt, &m_btnDiceDecPosX,
								 &m_txtDicePosX, &m_btnDiceIncPosX,
								 "Dice X-Position",
								 std::to_string( ( int )m_dicePtr->GetBodyPosition().x ) );

	// initializing the UI to control y-position of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDicePosYPrompt, &m_btnDiceDecPosY,
								 &m_txtDicePosY, &m_btnDiceIncPosY,
								 "Dice Y-Position",
								 std::to_string( ( int )m_dicePtr->GetBodyPosition().y ) );

	// initializing the UI to control dice file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtDiceFileNamePrompt, &m_txtDiceFileInput,
									&m_btnDiceOpenFile, "Dice Texture Filename",
									m_dicePtr->GetSpriteBody().GetTexturePath() );

	// initializing a UI to roll a dice
	m_btnRollDice = DyCreateButton( { m_panelBodyPtr->getSize().x, 25 },
									{ m_panelBodyPtr->getPosition().x,
									m_unNamedUIList.back()->GetBodyPosition().y + m_unNamedUIList.back()->GetBodySize().y },
									"Roll Dice",
									m_unNamedUIList.back()->GetBodyColor() == Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor ?
									Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor :
									Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );

	// setitng the font for roll dice
	m_btnRollDice->SetFontSize( 15 );
}

/// 
/// @private
/// @brief Updates the panel element of the dice setting 
/// 
/// It Updates the following panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works 
/// 
void Brood::Application::BoardEditor::UpdateDiceSettingPanel()
{
	// checks if the user interacted with the Dice 
			// side number panel Element
	UpdateDiceSideNum();

	// checks if the user interacted with the Dice 
	// x size panel Element
	UpdateDiceSizeX();

	// checks if the user interacted with the Dice 
	// y size panel Element
	UpdateDiceSizeY();

	// checks if the user interacted with the Dice 
	// x size panel Element
	UpdateDicePosX();

	// checks if the user interacted with the Dice 
	// y Pos panel Element
	UpdateDicePosY();

	// checks if the user interacted with the load 
	// Dice texture panel Element
	UpdateDiceFileTexture();

	// checks if roll dice was pressed
	UpdateRollDice();
}

/// 
/// @private
/// @brief Draws the panel element of the dice setting 
/// 
/// It Draws the following panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works 
/// 
void Brood::Application::BoardEditor::DrawDiceSettingPanel( sf::RenderWindow& a_window )
{
	// Drawing the roll Dice panel Elements
	m_btnRollDice->Draw( a_window );

	// Drawing the Dice file name texture panel 
	// Elements
	m_btnDiceOpenFile->Draw( a_window );
	m_txtDiceFileInput->Draw( a_window );
	m_txtDiceFileNamePrompt->Draw( a_window );

	// Drawing the y-Pos current Selected Dice 
	// index panel Elements
	m_btnDiceIncPosY->Draw( a_window );
	m_txtDicePosY->Draw( a_window );
	m_btnDiceDecPosY->Draw( a_window );
	m_txtDicePosYPrompt->Draw( a_window );

	// Drawing the X-Pos current Selected Dice 
	// index panel Elements
	m_btnDiceIncPosX->Draw( a_window );
	m_txtDicePosX->Draw( a_window );
	m_btnDiceDecPosX->Draw( a_window );
	m_txtDicePosXPrompt->Draw( a_window );

	// Drawing the y-size current Selected Dice 
	// index panel Elements
	m_btnDiceIncSizeY->Draw( a_window );
	m_txtDiceSizeY->Draw( a_window );
	m_btnDiceDecSizeY->Draw( a_window );
	m_txtDiceSizeYPrompt->Draw( a_window );

	// Drawing the x-size current Selected Dice 
	// index panel Elements
	m_btnDiceIncSizeX->Draw( a_window );
	m_txtDiceSizeX->Draw( a_window );
	m_btnDiceDecSizeX->Draw( a_window );
	m_txtDiceSizeXPrompt->Draw( a_window );

	// Drawing the x-size current Selected Dice 
	// index panel Elements
	m_btnDiceIncSide->Draw( a_window );
	m_txtDiceSide->Draw( a_window );
	m_btnDiceDecSide->Draw( a_window );
	m_txtDiceSidePrompt->Draw( a_window );
}


/// 
/// @private
/// @brief changes the displayed data on the panel for
///		current active player 
/// 
void Brood::Application::BoardEditor::ChangeDisplayedPlayerData()
{
	;
	Brood::Application::Components::Player* currActivePlayer = m_playerManager.GetPlayerAtCurrIdx();

	// updating the textbox showing the player's data 

	// players x-size
	m_txtPlayerCurrIdxSizeX->SetText( std::to_string( currActivePlayer->GetPlayerBody().getSize().x ) );

	// players y-size
	m_txtPlayerCurrIdxSizeY->SetText( std::to_string( currActivePlayer->GetPlayerBody().getSize().y ) );

	// players x-offset
	m_txtPlayerCurrIdxOffsetX->SetText( std::to_string( currActivePlayer->GetPositionOffsetX() ) );

	// players y-offset
	m_txtPlayerCurrIdxOffsetY->SetText( std::to_string( currActivePlayer->GetPositionOffsetY() ) );

	// players texture file path
	m_txtPlayerFileInput->SetText( currActivePlayer->GetPlayerSpriteBody().GetTexturePath() );
}

/// 
/// @private
/// @brief checks if the user interacted with setting Selection and
///		updates accordingly
/// 
void Brood::Application::BoardEditor::UpdateSettingSelectionDDI()
{
	if( m_ddiSettingSelection->DoElement() )
	{
		std::cout << "myDropDownInput Pressed" << std::endl;
	}

	if( m_ddiSettingSelection->IsSelected() )
	{
		auto itemList = m_ddiSettingSelection->GetItemList();
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( int currIDx = 0; currIDx < itemList.size(); ++currIDx )
			{
				if( itemList.at( currIDx )->DoElement() )
				{
					// setting the elements name as the item's name
					// this is important so that the changes can be reflected in the
					// title
					// setting the first item as the first 
					std::string itemName = m_ddiSettingSelection->GetItemList().at( currIDx )->GetText();

					while( itemName.size() < 39 )
					{
						itemName = " " + itemName + " ";
					}

					m_ddiSettingSelection->SetText( itemName + " v" );

					// executing the function
					std::cerr << "item at " << currIDx << "  Pressed with ID " <<
						itemList.at( currIDx )->GetText() << std::endl;

					m_selectedSettingIdx = currIDx;
				}
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the x position panel
///	
/// X position panel contains Board X position promt textbox, 
///		Board X postion value text box, button to increase the
///		Board X position, and button to decrease the Board X postion.
/// 
/// Only the button to increase the Board X position, and button 
///		to decrease the Board X postion are interactable
/// 
/// If the interactable button was pressed then the X pos is 
///		increased or decresed by 5 if the board does not go 
///		outside the board window
/// 
void Brood::Application::BoardEditor::UpdateBoardXPosPanelElement()
{
	// chekcing if the decrease the Board X postion was pressed
	if( m_btnBoardPosDecX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_boardPtr->GetBoardPos();
		int currentPosX = currentPos.x;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosX == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_boardPtr->SetBoardPos( currentPosX - 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtBoardPosX->SetText( std::to_string( currentPosX - 5 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnBoardPosIncX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_boardPtr->GetBoardPos();
		int currentPosX = currentPos.x;

		// chekcing if the board goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( currentPosX == boardWindowWidth - m_boardPtr->GetBoardSize().x )
		{
			return;
		}

		// increase the board x position by 5 units
		m_boardPtr->SetBoardPos( currentPosX + 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtBoardPosX->SetText( std::to_string( currentPosX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the y position panel
///	
/// Y position panel contains Board Y position promt textbox, 
///		Board Y postion value text box, button to increase the
///		Board Y position, and button to decrease the Board Y postion.
/// 
/// Only the button to increase the Board Y position, and button 
///		to decrease the Board Y postion are interactable
/// 
/// If the interactable button was pressed then the Y pos is 
///		increased or decresed by 5 if the board does not go 
///		outside the board window
/// 
void Brood::Application::BoardEditor::UpdateBoardYPosPanelElement()
{
	// chekcing if the decrease the Board Y postion was pressed
	if( m_btnBoardPosDecY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_boardPtr->GetBoardPos();
		int currentPosY = currentpos.y;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosY == 90 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_boardPtr->SetBoardPos( currentpos.x, currentPosY - 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardPosY->SetText( std::to_string( currentPosY - 5 ) );
	}
	// chekcing if the increase the Board Y postion was pressed
	else if( m_btnBoardPosIncY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_boardPtr->GetBoardPos();
		int currentPosY = currentpos.y;

		// chekcing if the board goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t boardHeigh = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;

		if( currentPosY == boardHeigh - m_boardPtr->GetBoardSize().y )
		{
			return;
		}

		// increase the board x position by 5 units
		m_boardPtr->SetBoardPos( currentpos.x, currentPosY + 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardPosY->SetText( std::to_string( currentPosY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the x size panel
///	
/// X size panel contains Board X size promt textbox, 
///		Board X size value text box, button to increase the
///		Board X size, and button to decrease the Board X size.
/// 
/// Only the button to increase the Board X size, and button 
///		to decrease the Board X size are interactable
/// 
/// If the interactable button was pressed then the X size is 
///		increased or decresed by 5 if the board does not go 
///		outside the board window 
///
void Brood::Application::BoardEditor::UpdateBoardXSizePanelElement()
{
	// chekcing if the decrease the Board X size was pressed
	if( m_btnBoardSizeDecX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_boardPtr->GetBoardSize();
		int currentSizeX = currentSize.x;

		// chekcing if the current size.x is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_boardPtr->SetBoardSize( currentSizeX - 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the incresase the Board X size was pressed
	else if( m_btnBoardSizeIncX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_boardPtr->GetBoardSize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( ( unsigned )m_boardPtr->GetBoardPos().x + currentSizeX + 5 >= boardWindowWidth )
		{
			return;
		}

		// increase the board x position by 5 units
		m_boardPtr->SetBoardSize( currentSizeX + 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeX->SetText( std::to_string( currentSizeX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the y size panel
///	
/// Y Size panel contains Board Y size promt textbox, 
///		Board Y size value text box, button to increase the
///		Board Y size, and button to decrease the Board Y size.
/// 
/// Only the button to increase the Board Y size, and button 
///		to decrease the Board Y size are interactable
/// 
/// If the interactable button was pressed then the Y size is 
///		increased or decresed by 5 if the board does not go 
///		outside the board window 
/// 
void Brood::Application::BoardEditor::UpdateBoardYSizePanelElement()
{
	// chekcing if the decrease the Board Y size was pressed
	if( m_btnBoardSizeDecY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_boardPtr->GetBoardSize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_boardPtr->SetBoardSize( currentSize.x, currentSizeY - 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the Board Y size was pressed
	else if( m_btnBoardSizeIncY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_boardPtr->GetBoardSize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		if( ( unsigned )m_boardPtr->GetBoardPos().y + currentSizeY + 5 >= windowHieght )
		{
			return;
		}

		// increase the board x position by 5 units
		m_boardPtr->SetBoardSize( currentSize.x, currentSizeY + 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeY->SetText( std::to_string( currentSizeY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the row panel
///	
/// Row panel contains Board row number promt textbox, 
///		Board row number value text box, button to increase the
///		Board row number, and button to decrease the Board row number.
/// 
/// Only the button to increase the Board row number, and button 
///		to decrease the Board row number are interactable
/// 
/// If the interactable button was pressed then the Board row number is 
///		increased or decresed by 1. Row number should be more than 1 
///		but less than 100
/// 
void Brood::Application::BoardEditor::UpdateBoardRowPanelElement()
{
	// chekcing if the decrease the Board row was pressed
	if( m_btnBoardDecRow->DoElement() )
	{
		// getting row information
		unsigned currentRow = m_boardPtr->GetNumRow();

		// chekcing if the current row num is 0 then do nothing
		if( currentRow <= 1 )
		{
			return;
		}

		// decrease the board row number by 1 units
		m_boardPtr->SetNumRow( currentRow - 1 );

		// updating the textbox showing the row value
		m_txtBoardRow->SetText( std::to_string( currentRow - 1 ) );
	}
	// chekcing if the increase the Board row was pressed
	else if( m_btnBoardIncRow->DoElement() )
	{
		// getting row information
		unsigned currentRow = m_boardPtr->GetNumRow();

		// chekcing if the current row is 100 then do notthing
		if( currentRow > 100 )
		{
			return;
		}

		// increase the board row number by 1 units
		m_boardPtr->SetNumRow( currentRow + 1 );

		// updating the textbox showing the row value
		m_txtBoardRow->SetText( std::to_string( currentRow + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the column panel
///	
/// Column panel contains Board column number promt textbox, 
///		Board column number value text box, button to increase the
///		Board column number, and button to decrease the Board column number.
/// 
/// Only the button to increase the Board column number, and button 
///		to decrease the Board column number are interactable
/// 
/// If the interactable button was pressed then the Board column number is 
///		increased or decresed by 1. Column number should be more than 1 
///		but less than 100
/// 
void Brood::Application::BoardEditor::UpdateBoardColPanelElement()
{
	// chekcing if the decrease the Board column was pressed
	if( m_btnBoardDecCol->DoElement() )
	{
		// getting column informantion
		unsigned currentCol = m_boardPtr->GetNumCol();

		// chekcing if the current row num is 0 then do nothing
		if( currentCol <= 1 )
		{
			return;
		}

		// decrease the board row number by 1 units
		m_boardPtr->SetNumCol( currentCol - 1 );

		// updating the textbox showing the column value
		m_txtBoardColPromt->SetText( std::to_string( currentCol - 1 ) );
	}
	// chekcing if the increase the Board column was pressed
	else if( m_btnBoardIncCol->DoElement() )
	{
		// getting column information
		unsigned currentCol = m_boardPtr->GetNumCol();

		// chekcing if the current column is 100 then do notthing
		if( currentCol > 100 )
		{
			return;
		}

		// increase the board row number by 1 units
		m_boardPtr->SetNumCol( currentCol + 1 );

		// updating the textbox showing the column value
		m_txtBoardCol->SetText( std::to_string( currentCol + 1 ) );
	}
}


/// 
/// @private
/// @brief checks if the user interacted with the movement type panel
///	
///  Movement type panel contains Board  movement type promt textbox, 
///		and drop down input to select a movement type
/// 
/// Only the drop down input to select the movement type is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the three option avialble  dice, start with dice and then 
///		card, and card no dice
/// 
void Brood::Application::BoardEditor::UpdateMovementTypePanelElement()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiMovementType->DoElement() || m_ddiMovementType->IsSelected() )
	{
		auto itemList = m_ddiMovementType->GetItemList();
		unsigned itemIdx = 0;
		bool itemPressed = false;
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( itemIdx; itemIdx < itemList.size(); ++itemIdx )
			{
				itemPressed = itemList.at( itemIdx )->DoElement();
				if( itemPressed )
				{
					break;
				}
			}

			if( itemPressed )
			{
				// setting the elements name as the item's name
				// this is important so that the changes can be reflected in the
				// title

				std::string itemName = itemList.at( itemIdx )->GetText();

				while( itemName.size() < 19 )
				{
					itemName = " " + itemName + " ";
				}

				// we know the size of the elemnt
				m_ddiMovementType->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the incorrect penalty panel
///	
///  Incorrect penalty panel contains Board incorrect penalty promt textbox, 
///		and drop down input to select a yes or no for incorrect penalty
/// 
/// Only the drop down input to select the incorrect penalty is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the two option avialble  Yes and No
///
void Brood::Application::BoardEditor::UpdateIncorrectPenaltyPanelElement()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiIncorectPenalty->DoElement() || m_ddiIncorectPenalty->IsSelected() )
	{
		auto itemList = m_ddiIncorectPenalty->GetItemList();
		unsigned itemIdx = 0;
		bool itemPressed = false;
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( itemIdx; itemIdx < itemList.size(); ++itemIdx )
			{
				itemPressed = itemList.at( itemIdx )->DoElement();
				if( itemPressed )
				{
					break;
				}
			}

			if( itemPressed )
			{
				// setting the elements name as the item's name
				// this is important so that the changes can be reflected in the
				// title

				std::string itemName = itemList.at( itemIdx )->GetText();

				while( itemName.size() < 27 )
				{
					itemName = " " + itemName + " ";
				}

				// we know the size of the elemnt
				m_ddiIncorectPenalty->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the start row panel
///	
/// Start row panel contains the start row number promt textbox, 
///		start row number value text box, button to increase the
///		start row number, and button to decrease the start row
///		 number
/// 
/// Only the button to increase the start row number, and button 
///		to decrease the start row number are interactable
/// 
/// If the interactable button was pressed then the start row
///		is increased or decresed by 1. Start row number
///		should be more than or equal to 0 but less than board 
///		row number
///
void Brood::Application::BoardEditor::UpdateStartRowNumber()
{

	// chekcing if the decrease the start row number was pressed
	if( m_btnPlayerDecStartRowNum->DoElement() )
	{
		// getting current start row number
		unsigned currentStartRowNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is 0 then do nothing
		if( currentStartRowNum == 0 )
		{
			return;
		}

		// decrease the start row number by 1 units
		m_playerManager.SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum - 1 ).at( currentStartColNum ) );

		// updating the textbox showing the start row value
		m_txtPlayerStartRowNum->SetText( std::to_string( currentStartRowNum - 1 ) );
	}
	// chekcing if the increase the start row number was pressed
	else if( m_btnPlayerIncStartRowNum->DoElement() )
	{
		// getting current start row number
		unsigned currentStartRowNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board row number then do nothing
		if( currentStartRowNum == m_boardPtr->GetNumRow() - 1 )
		{
			return;
		}

		// increase the start row number by 1 units
		m_playerManager.SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum + 1 ).at( currentStartColNum ) );

		// updating the textbox showing the start row value
		m_txtPlayerStartRowNum->SetText( std::to_string( currentStartRowNum + 1 ) );
	}
}
/// 
/// @private
/// @brief checks if the user interacted with the start column panel
///	
/// Start column panel contains the start column number promt textbox, 
///		start column number value text box, button to increase the
///		start column number, and button to decrease the start column
///		 number
/// 
/// Only the button to increase the start column number, and button 
///		to decrease the start column number are interactable
/// 
/// If the interactable button was pressed then the start column
///		is increased or decresed by 1. Start column number
///		should be more than or equal to 0 but less than board 
///		column number
///
void Brood::Application::BoardEditor::UpdateStartColNumber()
{// chekcing if the decrease the start column number was pressed
	if( m_btnPlayerDecStartColNum->DoElement() )
	{
		// getting current start column number
		unsigned currentStartRowNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartColNum is 0 then do nothing
		if( currentStartColNum == 0 )
		{
			return;
		}

		// decrease the start column number by 1 units
		m_playerManager.SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum ).at( currentStartColNum - 1 ) );

		// updating the textbox showing the start column value
		m_txtPlayerStartColNum->SetText( std::to_string( currentStartColNum - 1 ) );
	}
	// chekcing if the increase the start column number was pressed
	else if( m_btnPlayerIncStartColNum->DoElement() )
	{
		// getting current start column number
		unsigned currentStartRowNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_playerManager.GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board column number then do nothing
		if( currentStartColNum == m_boardPtr->GetNumCol() - 1 )
		{
			return;
		}

		// increase the start column number by 1 units
		m_playerManager.SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum ).at( currentStartColNum + 1 ) );

		// updating the textbox showing the start column value
		m_txtPlayerStartColNum->SetText( std::to_string( currentStartColNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the minumum player panel
///	
/// Minumum player panel contains minimum player number promt textbox, 
///		minimum player number value text box, button to increase the
///		minimum player number, and button to decrease the minimum 
///		player number
/// 
/// Only the button to increase the minimum player number, and button 
///		to decrease the minimum player number are interactable
/// 
/// If the interactable button was pressed then the minimum player
///		number is increased or decresed by 1. Minimum player number
///		should be more than or equal to 0 but less than Maximum player
///		number
///
void Brood::Application::BoardEditor::UpdateMinimumPlayerNumber()
{
	// chekcing if the decrease the minimum player number was pressed
	if( m_btnPlayerDecMinNum->DoElement() )
	{
		// getting current minimum Player number
		unsigned currentMinPlayerNum = m_playerManager.GetMinPlayer();

		// chekcing if the current currentMinPlayerNum is 0 then do nothing
		if( currentMinPlayerNum == 0 )
		{
			return;
		}

		// decrease the minimum player number by 1 units
		m_playerManager.SetMinPlayer( currentMinPlayerNum - 1 );

		// updating the textbox showing the minimum player value
		m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum - 1 ) );
	}
	// chekcing if the increase the minimum player number was pressed
	else if( m_btnPlayerIncMinNum->DoElement() )
	{
		// chekcing if the decrease the minimum player number was pressed
		unsigned currentMinPlayerNum = m_playerManager.GetMinPlayer();

		// chekcing if the current minimum player number is 
		// equal to current maximum player number the do nothing
		if( currentMinPlayerNum == m_playerManager.GetMaxPlayer() )
		{
			return;
		}

		// decrease the minimum player number by 1 units
		m_playerManager.SetMinPlayer( currentMinPlayerNum + 1 );

		// updating the textbox showing the minimum player value
		m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the maximum player panel
///	
/// Minumum player panel contains maximum player number promt textbox, 
///		maximum player number value text box, button to increase the
///		maximum player number, and button to decrease the maximum 
///		player number
/// 
/// Only the button to increase the maximum player number, and button 
///		to decrease the maximum player number are interactable
/// 
/// If the interactable button was pressed then the maximum player
///		number is increased or decresed by 1. Maximum player number
///		should be more than or equal to minimum player number
///		but less than 10
///
void Brood::Application::BoardEditor::UpdateMaximumPlayerNumber()
{
	// chekcing if the decrease the maximum player number was pressed
	if( m_btnPlayerDecMaxnNum->DoElement() )
	{
		// getting current maximum Player number
		unsigned currentMaxPlayerNum = m_playerManager.GetMaxPlayer();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to currentMinPlayerNum then do nothing
		if( currentMaxPlayerNum == m_playerManager.GetMinPlayer() )
		{
			return;
		}

		// decrease the maximum player number by 1 units
		m_playerManager.SetMaxPlayer( currentMaxPlayerNum - 1 );

		// updating the textbox showing the maximum player value
		m_txtPlayerMaxNum->SetText( std::to_string( currentMaxPlayerNum - 1 ) );

		// chekcing if the currIdx is higher than max player
		if( m_playerManager.GetCurrActivePlayerIdx() >= currentMaxPlayerNum - 1 )
		{
			m_playerManager.SetCurrActivePlayerIdx( currentMaxPlayerNum - 2 );

			// updating the textbox showing the current selceted player index value
			m_txtPlayerCurrIdx->SetText( std::to_string( m_playerManager.GetCurrActivePlayerIdx() ) );

			// changing the displayed player data
			ChangeDisplayedPlayerData();
		}
	}
	// chekcing if the increase the maximum player number was pressed
	else if( m_btnPlayerIncMaxNum->DoElement() )
	{
		// getting current maximum Player number
		unsigned currentMaxPlayerNum = m_playerManager.GetMaxPlayer();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to 10 then do nothing
		if( currentMaxPlayerNum == 10 )
		{
			return;
		}

		// decrease the maximum player number by 1 units
		m_playerManager.SetMaxPlayer( currentMaxPlayerNum + 1 );

		// updating the textbox showing the maximum player value
		m_txtPlayerMaxNum->SetText( std::to_string( currentMaxPlayerNum + 1 ) );
	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted player 
///		index panel
///	
/// Current selceted player index panel contains  current selceted player 
///		index promt textbox, current selceted player index value text box, 
///		button to increase the current selceted player index, and button 
///		to decrease the current selceted player index
/// 
/// Only the button to increase the current selceted player index, and 
///		button to decrease the current selceted player index are interactable
/// 
/// If the interactable button was pressed then the current selceted player 
///		index is increased or decresed by 1. current selceted player index
///		should be more than or equal to 0 but less than minimum player number
///
void Brood::Application::BoardEditor::UpdateCurrSelectedPlayerIdx()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnPlayerDecCurrIdx->DoElement() )
	{
		// getting current selceted player index
		unsigned currentPlayerIdx = m_playerManager.GetCurrActivePlayerIdx();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to 0 then do nothing
		if( currentPlayerIdx == 0 )
		{
			return;
		}

		// decrease the current selceted player index by 1 units
		m_playerManager.SetCurrActivePlayerIdx( currentPlayerIdx - 1 );

		// updating the textbox showing the current selceted player index value
		m_txtPlayerCurrIdx->SetText( std::to_string( currentPlayerIdx - 1 ) );

		// changing the displayed player data
		ChangeDisplayedPlayerData();

	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnPlayerIncCurrIdx->DoElement() )
	{
		// getting position information
		unsigned currentPlayerIdx = m_playerManager.GetCurrActivePlayerIdx();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to maimum number of player then do nothing
		if( currentPlayerIdx == m_playerManager.GetMaxPlayer() - 1 )
		{
			return;
		}

		// decrease the current selceted player index by 1 units
		m_playerManager.SetCurrActivePlayerIdx( currentPlayerIdx + 1 );

		// updating the textbox showing the current selceted player index value
		m_txtPlayerCurrIdx->SetText( std::to_string( currentPlayerIdx + 1 ) );

		// changing the displayed player data
		ChangeDisplayedPlayerData();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the draw player at current
///		index panel
///	
///  Draw player at current index panel contains draw player at current 
///		panel  promt textbox, and drop down input to select a yes or no
///		for draw player at current panel 
/// 
/// Only the drop down input to togle player at current index  is
///		interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the two option avialble  Yes and No
///
void Brood::Application::BoardEditor::UpdateToggleDrawPlayerAtCurrIdx()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiDrawPlayerAtCurrIdx->DoElement() || m_ddiDrawPlayerAtCurrIdx->IsSelected() )
	{
		auto itemList = m_ddiDrawPlayerAtCurrIdx->GetItemList();
		unsigned itemIdx = 0;
		bool itemPressed = false;
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( itemIdx; itemIdx < itemList.size(); ++itemIdx )
			{
				itemPressed = itemList.at( itemIdx )->DoElement();
				if( itemPressed )
				{
					break;
				}
			}

			if( itemPressed )
			{
				// setting the elements name as the item's name
				// this is important so that the changes can be reflected in the
				// title

				std::string itemName = itemList.at( itemIdx )->GetText();

				while( itemName.size() < 27 )
				{
					itemName = " " + itemName + " ";
				}

				// we know the size of the elemnt
				m_ddiDrawPlayerAtCurrIdx->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;
				m_drawCurretntActivePlayer = itemIdx;
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player x size panel
///	
/// Player X size panel contains current player X size promt textbox, 
///		current player X size value text box, button to increase the
///		current player X size, and button to decrease the current 
///		player X size.
/// 
/// Only the button to increase the current player X size, and button 
///		to decrease the current player X size are interactable
/// 
/// If the interactable button was pressed then the current player 
///		X size is increased or decresed by 5 if the current player
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateCurrPlayerSizeX()
{
	// chekcing if the decrease the player X postion was pressed
	if( m_btnPlayerDecCurrIdxSizeX->DoElement() )
	{
		// getting player x-position information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeX = currentSize.x;

		// checking if the current player size is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the player x size by 5 units
		playerBodyPtr->setSize( { ( float )currentSizeX - 5, currentSize.y } );

		// updating the textbox showing the player x-size value
		m_txtPlayerCurrIdxSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnPlayerIncCurrIdxSizeX->DoElement() )
	{
		// getting player x-size information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeX = currentSize.x;

		// chekcing if the board goes out of the view if size is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		float playerPosX = playerBodyPtr->getPosition().x;
		float limitPosX = boardWindowWidth - currentSizeX +
			m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetX();

		if( currentSizeX == boardWindowWidth - currentSizeX || playerPosX >= limitPosX )
		{
			return;
		}

		// increase the player x size by 5 units
		playerBodyPtr->setSize( { ( float )currentSizeX + 5, currentSize.y } );

		// updating the textbox showing the player x-size value
		m_txtPlayerCurrIdxSizeX->SetText( std::to_string( currentSizeX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player y size panel
///	
/// Player Y size panel contains current player y size promt textbox, 
///		current player y size value text box, button to increase the
///		current player y size, and button to decrease the current 
///		player y size.
/// 
/// Only the button to increase the current player y size, and button 
///		to decrease the current player y size are interactable
/// 
/// If the interactable button was pressed then the current player 
///		y size is increased or decresed by 5 if the current player
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateCurrPlayerSizeY()
{
	// chekcing if the decrease the player Y postion was pressed
	if( m_btnPlayerDecCurrIdxSizeY->DoElement() )
	{
		// getting player x-size information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the player y size by 5 units
		playerBodyPtr->setSize( { currentSize.x, ( float )currentSizeY - 5 } );

		// updating the textbox showing the player x-size value
		m_txtPlayerCurrIdxSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the Board Y size was pressed
	else if( m_btnPlayerIncCurrIdxSizeY->DoElement() )
	{
		// getting player x-size information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeY = currentSize.y;


		// chekcing if increasing the size would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		float playerPosY = playerBodyPtr->getPosition().y;
		float limitPosY = windowHieght - currentSizeY +
			m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetY();

		if( ( unsigned )m_boardPtr->GetBoardPos().y + currentSizeY + 5 >= windowHieght
			|| playerPosY >= limitPosY )
		{
			return;
		}

		// decrease the player y size by 5 units
		playerBodyPtr->setSize( { currentSize.x, ( float )currentSizeY + 5 } );

		// updating the textbox showing the player y-size value
		m_txtPlayerCurrIdxSizeY->SetText( std::to_string( currentSizeY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player x Offset panel
///	
/// Player X Offset panel contains current player X Offset promt textbox, 
///		current player X Offset value text box, button to increase the
///		current player X Offset, and button to decrease the current 
///		player X Offset.
/// 
/// Only the button to increase the current player X Offset, and button 
///		to decrease the current player X Offset are interactable
/// 
/// If the interactable button was pressed then the current player 
///		X Offset is increased or decresed by 1 if the current player
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateCurrPlayerOffsetX()
{
	// chekcing if the decrease the player X offset was pressed
	if( m_btnPlayerDecCurrIdxOffsetX->DoElement() )
	{
		// getting player x-offset information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );
		sf::Vector2f playerPos = playerBodyPtr->getPosition();

		int currentOffsetX = m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetX();

		// checking if the current player goes out of broad window
		if( playerPos.x + currentOffsetX == 0 )
		{
			return;
		}

		// decrease the player x offset by 5 units
		m_playerManager.GetPlayerAtCurrIdx()->SetPositionOffsetX( currentOffsetX - 5 );

		// updating the textbox showing the player x-offset value
		m_txtPlayerCurrIdxOffsetX->SetText( std::to_string( currentOffsetX - 5 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnPlayerIncCurrIdxOffsetX->DoElement() )
	{
		// getting player x-offset information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		sf::Vector2f playerPos = playerBodyPtr->getPosition();
		int currentOffsetX = m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetX();

		// chekcing if the board goes out of the view if offset is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		float limitPosX = boardWindowWidth - currentSize.x + currentOffsetX;

		if( playerPos.x + currentOffsetX >= limitPosX )
		{
			return;
		}

		// increase the player x offset by 5 units
		m_playerManager.GetPlayerAtCurrIdx()->SetPositionOffsetX( currentOffsetX + 5 );

		// updating the textbox showing the player x-offset value
		m_txtPlayerCurrIdxOffsetX->SetText( std::to_string( currentOffsetX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player Y Offset panel
///	
/// Player Y Offset panel contains current player Y Offset promt textbox, 
///		current player Y Offset value text box, button to increase the
///		current player Y Offset, and button to decrease the current 
///		player Y Offset.
/// 
/// Only the button to increase the current player Y Offset, and button 
///		to decrease the current player Y Offset are interactable
/// 
/// If the interactable button was pressed then the current player 
///		Y Offset is increased or decresed by 1 if the current player
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateCurrPlayerOffsetY()
{
	// chekcing if the decrease the player Y offset was pressed
	if( m_btnPlayerDecCurrIdxOffsetY->DoElement() )
	{
		// getting player y-offset information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );
		sf::Vector2f playerPos = playerBodyPtr->getPosition();

		int currentOffsetY = m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetY();

		// checking if the current player goes out of broad window
		if( playerPos.y + currentOffsetY == 0 )
		{
			return;
		}

		// decrease the player y offset by 5 units
		m_playerManager.GetPlayerAtCurrIdx()->SetPositionOffsetY( currentOffsetY - 5 );

		// updating the textbox showing the player y-offset value
		m_txtPlayerCurrIdxOffsetY->SetText( std::to_string( currentOffsetY - 5 ) );
	}
	// chekcing if the Increase the Board y postion was pressed
	else if( m_btnPlayerIncCurrIdxOffsetY->DoElement() )
	{
		// getting player y-offset information
		sf::RectangleShape* playerBodyPtr = &( m_playerManager.GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		sf::Vector2f playerPos = playerBodyPtr->getPosition();
		int currentOffsetY = m_playerManager.GetPlayerAtCurrIdx()->GetPositionOffsetY();

		// chekcing if the board goes out of the view if offset is 
		// increased any further

		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		float playerPosY = playerBodyPtr->getPosition().y;
		float limitPosY = windowHieght - currentSize.y + currentOffsetY;

		if( playerPos.y + currentOffsetY >= limitPosY )
		{
			return;
		}

		// increase the player y offset by 5 units
		m_playerManager.GetPlayerAtCurrIdx()->SetPositionOffsetY( currentOffsetY + 5 );

		// updating the textbox showing the player y-offset value
		m_txtPlayerCurrIdxOffsetY->SetText( std::to_string( currentOffsetY + 5 ) );
	}
}


/// 
/// @private
/// @brief checks if the user interacted with the laod player texture 
///		panel
///	
/// Load player texture file panel contains load player texture file 
///		promt textbox, textbox to enter the file name, and button to 
///		open and load the file.
/// 
/// Only the textbox to enter the file name, and button to 
///		open and load the file are interactable
/// 
/// If the interactable button was pressed then it opens the filename 
///		entered
/// 
/// @warning the Texture for the file should be in "cwd\Assets\Textures\PlayerTexture\"
///		as it loads them from there
/// 
void Brood::Application::BoardEditor::UpdateCurrPlayerFileTexture()
{
	if( m_txtPlayerFileInput->DoElement() )
	{
		m_txtPlayerFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}


	// check if load the button waas pressed or enter was pressed
	if( m_btnPlayerOpenFile->DoElement() || ( m_txtPlayerFileInput->IsEnterPressed() &&
											  m_txtPlayerFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string playerTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_playerTextures.string();
		playerTextureFilePath += m_txtPlayerFileInput->GetText();

		// loading the texture file
		if( !m_playerManager.GetPlayerAtCurrIdx()->GetPlayerSpriteBody().SetTextureFromFilePath( playerTextureFilePath ) )
		{
			m_txtPlayerFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
			std::cerr << "Could not find: " << playerTextureFilePath << std::endl;
		}

		// resetting the m_eterPressed
		m_txtPlayerFileInput->SetEnterPressedFalse();
	}

}

/// 
/// @private
/// @brief checks if the user interacted with the dice side number
///		panel
///	
/// dice side number panel contains current diceside number promt 
///		textbox, current dice side number value text box, button 
///		to increase the current dice side number, and button to
///		decrease the current dice side number.
/// 
/// Only the button to increase the current dice side number, and
///		button to decrease the current dice side number are 
///		interactable
/// 
/// If the interactable button was pressed then the current dice 
///		side number is increased or decresed by 1. The side number
///		can be between 1 and 100
///
void Brood::Application::BoardEditor::UpdateDiceSideNum()
{
	// chekcing if the decrease the dice side number was pressed
	if( m_btnDiceDecSide->DoElement() )
	{
		// getting dice side number information
		unsigned currsideNum = m_dicePtr->GetNumSides();

		// checking if the current dice size is 0 then do notthing
		if( currsideNum == 1 )
		{
			return;
		}

		// decrease the dice side number by 1 units
		m_dicePtr->SetNumSides( currsideNum - 1 );

		// updating the textbox showing the dice side number value
		m_txtDiceSide->SetText( std::to_string( currsideNum - 1 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnDiceIncSide->DoElement() )
	{
		// getting dice side number information
		unsigned currsideNum = m_dicePtr->GetNumSides();

		// checking if the current dice size is 0 then do notthing
		if( currsideNum == 100 )
		{
			return;
		}

		// decrease the dice side number by 1 units
		m_dicePtr->SetNumSides( currsideNum + 1 );

		// updating the textbox showing the dice side number value
		m_txtDiceSide->SetText( std::to_string( currsideNum + 1 ) );
	}
}


/// 
/// @private
/// @brief checks if the user interacted with the dice x size panel
///	
/// dice X size panel contains current dice X size promt textbox, 
///		current dice X size value text box, button to increase the
///		current dice X size, and button to decrease the current 
///		dice X size.
/// 
/// Only the button to increase the current dice X size, and button 
///		to decrease the current dice X size are interactable
/// 
/// If the interactable button was pressed then the current dice 
///		X size is increased or decresed by 5 if the current dice
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateDiceSizeX()
{
	// chekcing if the decrease the dice X size was pressed
	if( m_btnDiceDecSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_dicePtr->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if the current size.x is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the dice x position by 5 units
		m_dicePtr->SetBodySize( currentSizeX - 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the incresase the dice X size was pressed
	else if( m_btnDiceIncSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_dicePtr->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make dice to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( ( unsigned )m_dicePtr->GetBodyPosition().x + currentSizeX + 5 >= boardWindowWidth )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_dicePtr->SetBodySize( currentSizeX + 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeX->SetText( std::to_string( currentSizeX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the dice y size panel
///	
/// dice Y size panel contains current dice y size promt textbox, 
///		current dice y size value text box, button to increase the
///		current dice y size, and button to decrease the current 
///		dice y size.
/// 
/// Only the button to increase the current dice y size, and button 
///		to decrease the current dice y size are interactable
/// 
/// If the interactable button was pressed then the current dice 
///		y size is increased or decresed by 5 if the current dice
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateDiceSizeY()
{
	// chekcing if the decrease the dice Y size was pressed
	if( m_btnDiceDecSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_dicePtr->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the dice x position by 5 units
		m_dicePtr->SetBodySize( currentSize.x, currentSizeY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the dice Y size was pressed
	else if( m_btnDiceIncSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_dicePtr->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make dice to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		if( ( unsigned )m_dicePtr->GetBodyPosition().y + currentSizeY + 5 >= windowHieght )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_dicePtr->SetBodySize( currentSize.x, currentSizeY + 5 );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeY->SetText( std::to_string( currentSizeY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the dice x position panel
///	
/// dice X position panel contains current dice X position promt textbox, 
///		current dice X position value text box, button to increase the
///		current dice X position, and button to decrease the current 
///		dice X position.
/// 
/// Only the button to increase the current dice X position, and button 
///		to decrease the current dice X position are interactable
/// 
/// If the interactable button was pressed then the current dice 
///		X position is increased or decresed by 1 if the current dice
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateDicePosX()
{
	// chekcing if the decrease the Dice X postion was pressed
	if( m_btnDiceDecPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_dicePtr->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosX == 0 )
		{
			return;
		}

		// decrease the Dice x position by 5 units
		m_dicePtr->SetBodyPosition( currentPosX - 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtDicePosX->SetText( std::to_string( currentPosX - 5 ) );
	}
	// chekcing if the Increase the Dice X postion was pressed
	else if( m_btnDiceIncPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_dicePtr->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the Dice goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( currentPosX == boardWindowWidth - m_dicePtr->GetBodyPosition().x )
		{
			return;
		}

		// increase the Dice x position by 5 units
		m_dicePtr->SetBodyPosition( currentPosX + 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtDicePosX->SetText( std::to_string( currentPosX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player Y Offset panel
///	
/// Player Y Offset panel contains current player Y Offset promt textbox, 
///		current player Y Offset value text box, button to increase the
///		current player Y Offset, and button to decrease the current 
///		player Y Offset.
/// 
/// Only the button to increase the current player Y Offset, and button 
///		to decrease the current player Y Offset are interactable
/// 
/// If the interactable button was pressed then the current player 
///		Y Offset is increased or decresed by 1 if the current player
///		does not go outside the board window 
///
void Brood::Application::BoardEditor::UpdateDicePosY()
{
	// chekcing if the decrease the Dice Y postion was pressed
	if( m_btnDiceDecPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_dicePtr->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the current postition is 90 then do notthing
		if( currentPosY == 90 )
		{
			return;
		}

		// decrease the dice y position by 5 units
		m_dicePtr->SetBodyPosition( currentpos.x, currentPosY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDicePosY->SetText( std::to_string( currentPosY - 5 ) );
	}
	// chekcing if the increase the Dice Y postion was pressed
	else if( m_btnDiceIncPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_dicePtr->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the dice goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t boardHeigh = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;

		if( currentPosY == boardHeigh - m_dicePtr->GetBodySize().y )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_dicePtr->SetBodyPosition( currentpos.x, currentPosY + 5 );

		// updating the textbox showing the x-positon value
		m_txtDicePosY->SetText( std::to_string( currentPosY + 5 ) );
	}
}


/// 
/// @private
/// @brief checks if the user interacted with the laod dice texture 
///		panel
///	
/// Load dice texture file panel contains load dice texture file 
///		promt textbox, textbox to enter the file name, and button to 
///		open and load the file.
/// 
/// Only the textbox to enter the file name, and button to 
///		open and load the file are interactable
/// 
/// If the interactable button was pressed then it opens the filename 
///		entered
/// 
/// @warning Texture should always be in .png form
/// @warning the Texture for the file should be in \Assets\Textures\DiceTexture\
///		as it loads them from there. 
void Brood::Application::BoardEditor::UpdateDiceFileTexture()
{
	if( m_txtDiceFileInput->DoElement() )
	{
		m_txtDiceFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnDiceOpenFile->DoElement() || ( m_txtDiceFileInput->IsEnterPressed() &&
											m_txtDiceFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string diceTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_diceTextures.string();

		diceTextureFilePath += m_txtDiceFileInput->GetText();


		// loading the texture file
		if( !m_dicePtr->SetTexture( diceTextureFilePath ) )
		{
			m_txtDiceFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}

		// resetting the m_eterPressed
		m_txtDiceFileInput->SetEnterPressedFalse();
	}

}

/// 
/// @private
/// @brief checks if the user interacted with the roll dice panel
///	
/// Roll dice contains a button to roll a dice
/// 
/// Only the  button to roll a dice is interactable
/// 
/// If the interactable button was pressed then it rolls a dice
/// 
/// @warning Texture should always be in .png form
/// @warning the Texture for the file should be in \\Assets\\Textures\\DiceTexture\\
///		as it loads them from there. Do not include .png
void Brood::Application::BoardEditor::UpdateRollDice()
{
	if( m_btnRollDice->DoElement() )
	{
		std::cerr << "Current Roll: " << m_dicePtr->RollDice() << std::endl;
	}
}


// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================