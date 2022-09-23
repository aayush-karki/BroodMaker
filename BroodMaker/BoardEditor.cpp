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
											  sf::RectangleShape* a_panelPtr ) :
	m_boardPtr( a_boardPtr ), m_playerManager(), m_drawCurretntActivePlayer( false ),
	m_panelBodyPtr( a_panelPtr ), m_selectedSettingIdx( 1 )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::BoardEditor::~BoardEditor()
{}


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
	// setting up the player manager
	m_playerManager.SetPlayerStartPath( m_boardPtr->GetBoardPathList().at( 0 ).at( 0 ) );

	// Initializing the setting Section dropdown input
	InitailizeSettingSelectionDDI();

	// Initializing the general board setting panel element
	InitailizeGeneralBoardSettingPanel();


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

		// checking to see if the movement type panel Element was pressed
		UpdateMovementTypePanelElement();

		// checking to see if the incorrect penalty panel Element was pressed
		UpdateIncorrectPenaltyPanelElement();
	}
	// if the player setting is selected
	else if( m_selectedSettingIdx == 1 )
	{
		// checking to see if the minimum Player number panel Element was pressed
		UpdateMinimumPlayerNumber();

		// checking to see if the maximum Player number panel Element was pressed
		UpdateMaximumPlayerNumber();
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::BoardEditor::Draw( sf::RenderWindow& a_window )
{
	//// drawing the dynamically created UI elements 
	//// as we are creating the panels element form top to bottom
	//// we can just loop from the buttom to top to draw the elements 
	//// in correct order
	//std::vector<Brood::BroodUI::UIElement*>::reverse_iterator currrevIte = m_unNamedUIList.rbegin();

	//while( currrevIte != m_unNamedUIList.rend() )
	//{
	//	( *currrevIte )->Draw( a_window );
	//	++currrevIte;
	//}

	if( m_drawCurretntActivePlayer )
	{
		m_playerManager.GetPlayerAtCurrIdx()->Draw( a_window );
	}

	// if the General Board setting is selected
	if( m_selectedSettingIdx == 0 )
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
	// if the player setting is selected
	else if( m_selectedSettingIdx == 1 )
	{
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
///		X-postion, Y-position, X-size, Y-Size, 
///		row, column, movement-type, incorrect-penalty
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

		// decrease the board x position by 5 units
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

		// decrease the board x position by 5 units
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

		// decrease the board x position by 5 units
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

		// decrease the board x position by 5 units
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

		// decrease the board row number by 1 units
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

		// decrease the board row number by 1 units
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

	/// @todo  fix this 
		//// chekcing if the decrease the start row number was pressed
		//if( m_btnPlayerDecStartRowNum->DoElement() )
		//{
		//	// getting current minimum Player number
		//	unsigned currentStartRowrNum = m_playerManager.GetPlayerStartPath()

		//	// chekcing if the current currentMinPlayerNum is 0 then do nothing
		//	if( currentMinPlayerNum == 0 )
		//	{
		//		return;
		//	}

		//	// decrease the minimum player number by 1 units
		//	m_playerManager.SetMinPlayer( currentMinPlayerNum - 1 );

		//	// updating the textbox showing the minimum player value
		//	m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum - 1 ) );
		//}
		//// chekcing if the increase the minimum player number was pressed
		//else if( m_btnPlayerIncStartRowNum->DoElement() )
		//{
		//	// getting position information
		//	unsigned currentMinPlayerNum = m_playerManager.GetMinPlayer();

		//	// chekcing if the current minimum player number is 
		//	// equal to current maximum player number the do nothing
		//	if( currentMinPlayerNum == m_playerManager.GetMaxPlayer() )
		//	{
		//		return;
		//	}

		//	// decrease the minimum player number by 1 units
		//	m_playerManager.SetMinPlayer( currentMinPlayerNum + 1 );

		//	// updating the textbox showing the minimum player value
		//	m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum + 1 ) );
		//}
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
///		 should be more than or equal to 0 but less than Maximum player
///		 number
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
		// getting position information
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
///		 should be more than or equal to minimum player number
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
	}
	// chekcing if the increase the maximum player number was pressed
	else if( m_btnPlayerIncMaxNum->DoElement() )
	{
		// getting position information
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

// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================
