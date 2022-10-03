/*************************************************************************/
/// 
/// @file DiceEditor.cpp 
/// 
/// @brief  This file is a source file for DiceEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of DiceEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "DiceEditor.h"

// ======================================================================
// ================= start of DiceEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::DiceEditor::DiceEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::DiceEditor::~DiceEditor()
{
	// all the dynamically created panel elements are 
	// destructed in the base class
}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It initializes the folloing panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works 
/// 
//
void Brood::Application::DiceEditor::InitializeWorkSpace()
{
	// =======================================================================
	// ======= Initializing the elements in the  dice setting =======
	// =======================================================================

	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "General Game Settings" );
	m_txtSettingTitle->SetFontSize( 18 );

	// initializing the UI to control number of sides for new Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSidePrompt, &m_btnDiceDecSide,
								 &m_txtDiceSide, &m_btnDiceIncSide,
								 "Dice Side Number",
								 std::to_string( m_gameData->GetDicePtr()->GetNumSides() ), true );

	// initializing the UI to control x-size of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSizeXPrompt, &m_btnDiceDecSizeX,
								 &m_txtDiceSizeX, &m_btnDiceIncSizeX,
								 "Dice X-Size",
								 std::to_string( ( int )m_gameData->GetDicePtr()->GetBodySize().x ) );

	// initializing the UI to control y-size of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDiceSizeYPrompt, &m_btnDiceDecSizeY,
								 &m_txtDiceSizeY, &m_btnDiceIncSizeY,
								 "Dice Y-Size",
								 std::to_string( ( int )m_gameData->GetDicePtr()->GetBodySize().y ) );

	// initializing the UI to control x-position of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDicePosXPrompt, &m_btnDiceDecPosX,
								 &m_txtDicePosX, &m_btnDiceIncPosX,
								 "Dice X-Position",
								 std::to_string( ( int )m_gameData->GetDicePtr()->GetBodyPosition().x ) );

	// initializing the UI to control y-position of Dice
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDicePosYPrompt, &m_btnDiceDecPosY,
								 &m_txtDicePosY, &m_btnDiceIncPosY,
								 "Dice Y-Position",
								 std::to_string( ( int )m_gameData->GetDicePtr()->GetBodyPosition().y ) );

	// initializing the UI to control dice file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtDiceFileNamePrompt, &m_txtDiceFileInput,
									&m_btnDiceOpenFile, "Dice Texture Filename",
									m_gameData->GetDicePtr()->GetSpriteBody().GetTexturePath() );

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
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the dice editor workspace 
/// 
/// Updates the panel element of the dice setting 
/// 
/// It Updates the following panel element: 
///		dice side number, dice x-size, dice y-size, 
///		dice x-pos, dice-ypos, dice texture filename input,
///		and roll a dice to check if the texture works 
///
void Brood::Application::DiceEditor::Update()
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
/// @public
/// @virtual
/// @brief updates the display element
/// 

///
void Brood::Application::DiceEditor::UpdateAllDispayElement()
{}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
/// 
/// @param a_window reference to the render window
///
void Brood::Application::DiceEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing game component
	m_gameData->Draw( a_window );

	// drawing the ui in the list
	Brood::Application::WorkSpace::Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::DiceEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
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
void Brood::Application::DiceEditor::UpdateDiceSideNum()
{
	// chekcing if the decrease the dice side number was pressed
	if( m_btnDiceDecSide->DoElement() )
	{
		// getting dice side number information
		unsigned currsideNum = m_gameData->GetDicePtr()->GetNumSides();

		// checking if the current dice size is 0 then do notthing
		if( currsideNum == 1 )
		{
			return;
		}

		// decrease the dice side number by 1 units
		m_gameData->GetDicePtr()->SetNumSides( currsideNum - 1 );

		// updating the textbox showing the dice side number value
		m_txtDiceSide->SetText( std::to_string( currsideNum - 1 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnDiceIncSide->DoElement() )
	{
		// getting dice side number information
		unsigned currsideNum = m_gameData->GetDicePtr()->GetNumSides();

		// checking if the current dice size is 0 then do notthing
		if( currsideNum == 100 )
		{
			return;
		}

		// decrease the dice side number by 1 units
		m_gameData->GetDicePtr()->SetNumSides( currsideNum + 1 );

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
void Brood::Application::DiceEditor::UpdateDiceSizeX()
{
	// chekcing if the decrease the dice X size was pressed
	if( m_btnDiceDecSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_gameData->GetDicePtr()->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if the current size.x is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodySize( currentSizeX - 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the incresase the dice X size was pressed
	else if( m_btnDiceIncSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_gameData->GetDicePtr()->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make dice to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( ( unsigned )m_gameData->GetDicePtr()->GetBodyPosition().x + currentSizeX + 5 >= boardWindowWidth )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodySize( currentSizeX + 5, currentSize.y );

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
void Brood::Application::DiceEditor::UpdateDiceSizeY()
{
	// chekcing if the decrease the dice Y size was pressed
	if( m_btnDiceDecSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_gameData->GetDicePtr()->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodySize( currentSize.x, currentSizeY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDiceSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the dice Y size was pressed
	else if( m_btnDiceIncSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_gameData->GetDicePtr()->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make dice to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		if( ( unsigned )m_gameData->GetDicePtr()->GetBodyPosition().y + currentSizeY + 5 >= windowHieght )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodySize( currentSize.x, currentSizeY + 5 );

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
void Brood::Application::DiceEditor::UpdateDicePosX()
{
	// chekcing if the decrease the Dice X postion was pressed
	if( m_btnDiceDecPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_gameData->GetDicePtr()->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosX == 0 )
		{
			return;
		}

		// decrease the Dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodyPosition( currentPosX - 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtDicePosX->SetText( std::to_string( currentPosX - 5 ) );
	}
	// chekcing if the Increase the Dice X postion was pressed
	else if( m_btnDiceIncPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_gameData->GetDicePtr()->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the Dice goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( currentPosX == boardWindowWidth - m_gameData->GetDicePtr()->GetBodyPosition().x )
		{
			return;
		}

		// increase the Dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodyPosition( currentPosX + 5, currentPos.y );

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
void Brood::Application::DiceEditor::UpdateDicePosY()
{
	// chekcing if the decrease the Dice Y postion was pressed
	if( m_btnDiceDecPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_gameData->GetDicePtr()->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the current postition is 90 then do notthing
		if( currentPosY == 90 )
		{
			return;
		}

		// decrease the dice y position by 5 units
		m_gameData->GetDicePtr()->SetBodyPosition( currentpos.x, currentPosY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDicePosY->SetText( std::to_string( currentPosY - 5 ) );
	}
	// chekcing if the increase the Dice Y postion was pressed
	else if( m_btnDiceIncPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_gameData->GetDicePtr()->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the dice goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t boardHeigh = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;

		if( currentPosY == boardHeigh - m_gameData->GetDicePtr()->GetBodySize().y )
		{
			return;
		}

		// increase the dice x position by 5 units
		m_gameData->GetDicePtr()->SetBodyPosition( currentpos.x, currentPosY + 5 );

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
void Brood::Application::DiceEditor::UpdateDiceFileTexture()
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
		if( !m_gameData->GetDicePtr()->SetTexture( diceTextureFilePath ) )
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
void Brood::Application::DiceEditor::UpdateRollDice()
{
	if( m_btnRollDice->DoElement() )
	{
		std::cerr << "Current Roll: " << m_gameData->GetDicePtr()->RollDice() << std::endl;
	}
}

// ======================================================================
// ================= end of DiceEditor class ============================
// ======================================================================
