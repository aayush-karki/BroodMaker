#include "stdafx.h"
#include "PlayerEditor.h"

/*************************************************************************/
/// 
/// @file TileEditor.cpp 
/// 
/// @brief  This file is a source file for TileEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of TileEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "TileEditor.h"

// ======================================================================
// ================= start of PlayerEditor class ========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
/// 
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::PlayerEditor::PlayerEditor( Brood::Application::Components::GameDataManager* a_gameData,
												sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::PlayerEditor::~PlayerEditor()
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
void Brood::Application::PlayerEditor::InitializeWorkSpace()
{
	// =======================================================================
	// ======= Initializing the elements in the Player setting =======
	// =======================================================================

	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "Player Settings" );
	m_txtSettingTitle->SetFontSize( 18 );

	// initializing the UI to control current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxPrompt, &m_btnPlayerDecCurrIdx,
								 &m_txtPlayerCurrIdx, &m_btnPlayerIncCurrIdx,
								 "Current Player Index",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetCurrActivePlayerIdx() ) );


	// initializing the UI to control Start row for new player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerStartRowPrompt, &m_btnPlayerDecStartRowNum,
								 &m_txtPlayerStartRowNum, &m_btnPlayerIncStartRowNum,
								 "Start Row",
								 std::to_string( 0 ) );

	// initializing the UI to control Start column for new player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerStartColPrompt, &m_btnPlayerDecStartColNum,
								 &m_txtPlayerStartColNum, &m_btnPlayerIncStartColNum,
								 "Start Column",
								 std::to_string( 0 ) );
	// initializing the UI to control x-size of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxSizeXPrompt, &m_btnPlayerDecCurrIdxSizeX,
								 &m_txtPlayerCurrIdxSizeX, &m_btnPlayerIncCurrIdxSizeX,
								 "Current Player X-Size",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody().getSize().x ) );

	// initializing the UI to control y-size of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxSizeYPrompt, &m_btnPlayerDecCurrIdxSizeY,
								 &m_txtPlayerCurrIdxSizeY, &m_btnPlayerIncCurrIdxSizeY,
								 "Current Player Y-Size",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody().getSize().y ) );

	// initializing the UI to control x-offset of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxOffsetXPrompt, &m_btnPlayerDecCurrIdxOffsetX,
								 &m_txtPlayerCurrIdxOffsetX, &m_btnPlayerIncCurrIdxOffsetX,
								 "Player X-Offset",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetX() ) );

	// initializing the UI to control y-offset of player
	// at current player index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerCurrIdxOffsetYPrompt, &m_btnPlayerDecCurrIdxOffsetY,
								 &m_txtPlayerCurrIdxOffsetY, &m_btnPlayerIncCurrIdxOffsetY,
								 "Player Y-Offset",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetY() ) );

	// initializing the UI to control player file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtplayerFileNamePrompt, &m_txtPlayerFileInput,
									&m_btnPlayerOpenFile, "Player Texture Filename",
									m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerSpriteBody().GetTextureFileName() );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
/// It Updates the folloing panel element :
///		Player start row, Player start column, 
///		Current player index, Draw current 
///		player, Current player X-Size, current player Y-size, 
///		Current player X-offset, Current player Y-offset, and
///		Current player texture file name
///
void Brood::Application::PlayerEditor::Update()
{
	// checking to see if the player start row number panel
	// element was pressed
	UpdateStartRowNumber();

	// checking to see if the player start column number 
	// panel element was pressed
	UpdateStartColNumber();

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
/// @public
/// @virtual
/// @brief changes the displayed data on the panel for
///		current active player 
///
void Brood::Application::PlayerEditor::UpdateAllDispayElement()
{
	Brood::Application::Components::Player* currActivePlayer = m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx();

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
	m_txtPlayerFileInput->SetText( currActivePlayer->GetPlayerSpriteBody().GetTextureFileName() );
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
void Brood::Application::PlayerEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing the game data 
	m_gameData->Draw( a_window );

	// drawing the player
	m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->Draw( a_window );

	Brood::Application::WorkSpace::Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::PlayerEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
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
void Brood::Application::PlayerEditor::UpdateStartRowNumber()
{

	// chekcing if the decrease the start row number was pressed
	if( m_btnPlayerDecStartRowNum->DoElement() )
	{
		// getting current start row number
		unsigned currentStartRowNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is 0 then do nothing
		if( currentStartRowNum == 0 )
		{
			return;
		}

		// decrease the start row number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum - 1 ).at( currentStartColNum ) );

		// updating the textbox showing the start row value
		m_txtPlayerStartRowNum->SetText( std::to_string( currentStartRowNum - 1 ) );
	}
	// chekcing if the increase the start row number was pressed
	else if( m_btnPlayerIncStartRowNum->DoElement() )
	{
		// getting current start row number
		unsigned currentStartRowNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board row number then do nothing
		if( currentStartRowNum == m_boardPtr->GetNumRow() - 1 )
		{
			return;
		}

		// increase the start row number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum + 1 ).at( currentStartColNum ) );

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
void Brood::Application::PlayerEditor::UpdateStartColNumber()
{// chekcing if the decrease the start column number was pressed
	if( m_btnPlayerDecStartColNum->DoElement() )
	{
		// getting current start column number
		unsigned currentStartRowNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartColNum is 0 then do nothing
		if( currentStartColNum == 0 )
		{
			return;
		}

		// decrease the start column number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum ).at( currentStartColNum - 1 ) );

		// updating the textbox showing the start column value
		m_txtPlayerStartColNum->SetText( std::to_string( currentStartColNum - 1 ) );
	}
	// chekcing if the increase the start column number was pressed
	else if( m_btnPlayerIncStartColNum->DoElement() )
	{
		// getting current start column number
		unsigned currentStartRowNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetRow();
		unsigned currentStartColNum = m_gameData->GetPlayerManagerPtr()->GetPlayerStartPath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board column number then do nothing
		if( currentStartColNum == m_boardPtr->GetNumCol() - 1 )
		{
			return;
		}

		// increase the start column number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( currentStartRowNum ).at( currentStartColNum + 1 ) );

		// updating the textbox showing the start column value
		m_txtPlayerStartColNum->SetText( std::to_string( currentStartColNum + 1 ) );
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
void Brood::Application::PlayerEditor::UpdateCurrSelectedPlayerIdx()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnPlayerDecCurrIdx->DoElement() )
	{
		// getting current selceted player index
		unsigned currentPlayerIdx = m_gameData->GetPlayerManagerPtr()->GetCurrActivePlayerIdx();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to 0 then do nothing
		if( currentPlayerIdx == 0 )
		{
			return;
		}

		// decrease the current selceted player index by 1 units
		m_gameData->GetPlayerManagerPtr()->SetCurrActivePlayerIdx( currentPlayerIdx - 1 );

		// updating the textbox showing the current selceted player index value
		m_txtPlayerCurrIdx->SetText( std::to_string( currentPlayerIdx - 1 ) );

		// changing the displayed player data
		UpdateAllDispayElement();

	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnPlayerIncCurrIdx->DoElement() )
	{
		// getting position information
		unsigned currentPlayerIdx = m_gameData->GetPlayerManagerPtr()->GetCurrActivePlayerIdx();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to maimum number of player then do nothing
		if( currentPlayerIdx == m_gameData->GetPlayerManagerPtr()->GetMaxPlayer() - 1 )
		{
			return;
		}

		// decrease the current selceted player index by 1 units
		m_gameData->GetPlayerManagerPtr()->SetCurrActivePlayerIdx( currentPlayerIdx + 1 );

		// updating the textbox showing the current selceted player index value
		m_txtPlayerCurrIdx->SetText( std::to_string( currentPlayerIdx + 1 ) );

		// changing the displayed player data
		UpdateAllDispayElement();
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
void Brood::Application::PlayerEditor::UpdateCurrPlayerSizeX()
{
	// chekcing if the decrease the player X postion was pressed
	if( m_btnPlayerDecCurrIdxSizeX->DoElement() )
	{
		// getting player x-position information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

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
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeX = currentSize.x;

		// chekcing if the board goes out of the view if size is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		float playerPosX = playerBodyPtr->getPosition().x;
		float limitPosX = boardWindowWidth - currentSizeX +
			m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetX();

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
void Brood::Application::PlayerEditor::UpdateCurrPlayerSizeY()
{
	// chekcing if the decrease the player Y postion was pressed
	if( m_btnPlayerDecCurrIdxSizeY->DoElement() )
	{
		// getting player x-size information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

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
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		int currentSizeY = currentSize.y;


		// chekcing if increasing the size would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		float playerPosY = playerBodyPtr->getPosition().y;
		float limitPosY = windowHieght - currentSizeY +
			m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetY();

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
void Brood::Application::PlayerEditor::UpdateCurrPlayerOffsetX()
{
	// chekcing if the decrease the player X offset was pressed
	if( m_btnPlayerDecCurrIdxOffsetX->DoElement() )
	{
		// getting player x-offset information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );
		sf::Vector2f playerPos = playerBodyPtr->getPosition();

		int currentOffsetX = m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetX();

		// checking if the current player goes out of broad window
		if( playerPos.x + currentOffsetX == 0 )
		{
			return;
		}

		// decrease the player x offset by 5 units
		m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->SetPositionOffsetX( currentOffsetX - 5 );

		// updating the textbox showing the player x-offset value
		m_txtPlayerCurrIdxOffsetX->SetText( std::to_string( currentOffsetX - 5 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnPlayerIncCurrIdxOffsetX->DoElement() )
	{
		// getting player x-offset information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		sf::Vector2f playerPos = playerBodyPtr->getPosition();
		int currentOffsetX = m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetX();

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
		m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->SetPositionOffsetX( currentOffsetX + 5 );

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
void Brood::Application::PlayerEditor::UpdateCurrPlayerOffsetY()
{
	// chekcing if the decrease the player Y offset was pressed
	if( m_btnPlayerDecCurrIdxOffsetY->DoElement() )
	{
		// getting player y-offset information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );
		sf::Vector2f playerPos = playerBodyPtr->getPosition();

		int currentOffsetY = m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetY();

		// checking if the current player goes out of broad window
		if( playerPos.y + currentOffsetY == 0 )
		{
			return;
		}

		// decrease the player y offset by 5 units
		m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->SetPositionOffsetY( currentOffsetY - 5 );

		// updating the textbox showing the player y-offset value
		m_txtPlayerCurrIdxOffsetY->SetText( std::to_string( currentOffsetY - 5 ) );
	}
	// chekcing if the Increase the Board y postion was pressed
	else if( m_btnPlayerIncCurrIdxOffsetY->DoElement() )
	{
		// getting player y-offset information
		sf::RectangleShape* playerBodyPtr = &( m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerBody() );

		sf::Vector2f currentSize = playerBodyPtr->getSize();
		sf::Vector2f playerPos = playerBodyPtr->getPosition();
		int currentOffsetY = m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPositionOffsetY();

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
		m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->SetPositionOffsetY( currentOffsetY + 5 );

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
void Brood::Application::PlayerEditor::UpdateCurrPlayerFileTexture()
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
		if( !m_gameData->GetPlayerManagerPtr()->GetPlayerAtCurrIdx()->GetPlayerSpriteBody().SetTextureFromFilePath( playerTextureFilePath ) )
		{
			m_txtPlayerFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
			std::cerr << "Could not find: " << playerTextureFilePath << std::endl;
		}

		// resetting the m_eterPressed
		m_txtPlayerFileInput->SetEnterPressedFalse();
	}
}

// ======================================================================
// ================= end of PlayerEditor class ==========================
// ======================================================================