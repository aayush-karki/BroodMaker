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
Brood::Application::BoardEditor::BoardEditor( Brood::Application::Components::Board* a_boardPtr ) :
	m_boardPtr( a_boardPtr ), m_playerManager()
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
	// initializing the board 
	m_boardPtr->InitializeBoard( 1, 1, 500, 500, 50, 200 );

	// Initializing the setting Section dropdown input
	InitailizeSettingSelectionDDI();

	// Initializing the general board setting panel element
	InitailizeGeneralBoardSettingPanel();


	// =======================================================================
	// ======= Initializing the elements in the  General board setting =======
	// =======================================================================

	DyCreateDecIncPannelElement( &m_txtPlayerMinNumPrompt, &m_btnPlayerDecMinNum,
								 &m_txtPlayerMinNuml, &m_btnPlayerIncMinNum,
								 "Minimum number of Players", std::to_string( ( int )m_boardPtr->GetNumCol() ) );

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

	m_boardPtr->Debugger();
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
	DyCreateDecIncPannelElement( &m_txtBoardPosPromtX, &m_btnBoardPosDecX,
								 &m_txtBoardPosX, &m_btnBoardPosIncX,
								 "X-Position", std::to_string( ( int )m_boardPtr->GetBoardPos().x ),
								 true );

	// initializing the UI to control board's Y position 
	DyCreateDecIncPannelElement( &m_txtBoardPosPromtY, &m_btnBoardPosDecY,
								 &m_txtBoardPosY, &m_btnBoardPosIncY,
								 "Y-Position", std::to_string( ( int )m_boardPtr->GetBoardPos().y ) );

	// initializing the UI to control board's X size 
	DyCreateDecIncPannelElement( &m_txtBoardSizePromtX, &m_btnBoardSizeDecX,
								 &m_txtBoardSizeX, &m_btnBoardSizeIncX,
								 "X-Size", std::to_string( ( int )m_boardPtr->GetBoardSize().x ) );

	// initializing the UI to control board's Y size 
	DyCreateDecIncPannelElement( &m_txtBoardSizePromtY, &m_btnBoardSizeDecY,
								 &m_txtBoardSizeY, &m_btnBoardSizeIncY,
								 "Y-Size", std::to_string( ( int )m_boardPtr->GetBoardSize().y ) );

	// initializing the UI to control board's row
	DyCreateDecIncPannelElement( &m_txtBoardRowPromt, &m_btnBoardDecRow,
								 &m_txtBoardRow, &m_btnBoardIncRow,
								 "Row Number", std::to_string( ( int )m_boardPtr->GetNumRow() ) );

	// initializing the UI to control board's column
	DyCreateDecIncPannelElement( &m_txtBoardColPromt, &m_btnBoardDecCol,
								 &m_txtBoardCol, &m_btnBoardIncCol,
								 "Column Number", std::to_string( ( int )m_boardPtr->GetNumCol() ) );

	// initializing the UI to set the movement type
	DyCreateDropdownInputPannelElement( &m_txtMovementTypePromt, &m_ddiMovementType,
										"Movement Type: ",
										{ "Star Dice then Card", "Dice Only", "Card Only" }, 19 );

	// initializing the UI to set the incorrect penalty
	DyCreateDropdownInputPannelElement( &m_txtIncorectPenaltyPromt, &m_ddiIncorectPenalty,
										"Incorrect Penalty: ", { "Yes", "No" }, 27 );
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
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;


	// initializing the setting selection DDI
	float settingSelectionDDIWidth = ( windowWidth * Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) / 100;
	m_ddiSettingSelection = DyCreateDropDownInput( { settingSelectionDDIWidth , 40 },
												   { windowWidth - settingSelectionDDIWidth, 50 },
												   Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	m_ddiSettingSelection->AddItemToMenu( "General Board Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Player Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Dice Setting" );

	// setting the font size to 18
	m_ddiSettingSelection->SetFontSize( 18 );

	// setting the first item as the first 
	std::string itemName = m_ddiSettingSelection->GetItemList().at( 0 )->GetText();

	while( itemName.size() < 39 )
	{
		itemName = " " + itemName + " ";
	}

	m_ddiSettingSelection->SetText( itemName + " v" );
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
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
		// getting position information
		unsigned currentRow = m_boardPtr->GetNumRow();

		// chekcing if the current size.Y is 100 then do notthing
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
	// chekcing if the decrease the Board row was pressed
	if( m_btnBoardDecCol->DoElement() )
	{
		// getting position information
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
		// getting position information
		unsigned currentCol = m_boardPtr->GetNumCol();

		// chekcing if the current size.Y is 100 then do notthing
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


// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================
