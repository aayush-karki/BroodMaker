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

/// todo fix the bug where the tiles are not loaded properly. their
/// for the tiles, the next path line is set to first tile

/// 
/// @public
/// @brief default constructor
/// 
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::BoardEditor::BoardEditor( Brood::Application::Components::GameDataManager* a_gameData,
											  sf::RectangleShape* a_panelPtr ) :
	m_panelBodyPtr( a_panelPtr )
{
	this->m_gameData = a_gameData;

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
/// It creates all the component of the workspace. 
///		It initializes the folloing panel element: 
///		board X-postion, board Y-position, boardX-size, board Y-Size, 
///		board row, board column
//
void Brood::Application::BoardEditor::InitializeWorkSpace()
{
	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "Board Setting" );
	m_txtSettingTitle->SetFontSize( 18 );

	// =======================================================================
	// ======= Initializing the elements in the  General board setting =======
	// =======================================================================

	// initializing the UI to control board's X size 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardSizePromtX, &m_btnBoardSizeDecX,
								 &m_txtBoardSizeX, &m_btnBoardSizeIncX,
								 "X-Size", std::to_string( ( int )m_gameData->GetBoardPtr()->GetBoardSize().x ) );

	// initializing the UI to control board's Y size 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardSizePromtY, &m_btnBoardSizeDecY,
								 &m_txtBoardSizeY, &m_btnBoardSizeIncY,
								 "Y-Size", std::to_string( ( int )m_gameData->GetBoardPtr()->GetBoardSize().y ) );

	// initializing the UI to control board's X position 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardPosPromtX, &m_btnBoardPosDecX,
								 &m_txtBoardPosX, &m_btnBoardPosIncX,
								 "X-Position", std::to_string( ( int )m_gameData->GetBoardPtr()->GetBoardPos().x ) );

	// initializing the UI to control board's Y position 
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardPosPromtY, &m_btnBoardPosDecY,
								 &m_txtBoardPosY, &m_btnBoardPosIncY,
								 "Y-Position", std::to_string( ( int )m_gameData->GetBoardPtr()->GetBoardPos().y ) );

	// initializing the UI to control board's row
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardRowPromt, &m_btnBoardDecRow,
								 &m_txtBoardRow, &m_btnBoardIncRow,
								 "Row Number", std::to_string( ( int )m_gameData->GetBoardPtr()->GetNumRow() ) );

	// initializing the UI to control board's column
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtBoardColPromt, &m_btnBoardDecCol,
								 &m_txtBoardCol, &m_btnBoardIncCol,
								 "Column Number", std::to_string( ( int )m_gameData->GetBoardPtr()->GetNumCol() ) );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace.
///		It Update the folloing panel element: 
///		board X-postion, board Y-position, boardX-size, board Y-Size, 
///		board row, board column
///
void Brood::Application::BoardEditor::Update()
{
	// checking to see if the Xsize panel Element was pressed
	UpdateBoardXSizePanelElement();

	// checking to see if the Ysize panel Element was pressed
	UpdateBoardYSizePanelElement();

	// checking to see if the Xpos panel Element was pressed
	UpdateBoardXPosPanelElement();

	// checking to see if the Ypos panel Element was pressed
	UpdateBoardYPosPanelElement();

	// checking to see if the row panel Element was pressed
	UpdateBoardRowPanelElement();

	// checking to see if the col panel Element was pressed
	UpdateBoardColPanelElement();
}

/// 
/// @public
/// @virtual
/// @brief calls the updates all the display element for 
///		the current active editor
///
void Brood::Application::BoardEditor::UpdateAllDispayElement()
{
	Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();

	// board x Position 
	m_txtBoardPosX->SetText( std::to_string( boardPtr->GetBoardPos().x ) );

	// board y Position 
	m_txtBoardPosY->SetText( std::to_string( boardPtr->GetBoardPos().y ) );

	// board y Position 
	m_txtBoardSizeX->SetText( std::to_string( boardPtr->GetBoardSize().x ) );

	// board y Position 
	m_txtBoardSizeY->SetText( std::to_string( boardPtr->GetBoardSize().y ) );

	// board row number
	m_txtBoardRow->SetText( std::to_string( boardPtr->GetNumRow() ) );

	// board column number
	m_txtBoardCol->SetText( std::to_string( boardPtr->GetNumCol() ) );
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
	// drawing game component
	m_gameData->Draw( a_window );

	Brood::Application::WorkSpace::Draw( a_window );
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
		sf::Vector2f currentPos = m_gameData->GetBoardPtr()->GetBoardPos();
		int currentPosX = currentPos.x;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosX == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardPos( currentPosX - 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtBoardPosX->SetText( std::to_string( currentPosX - 5 ) );
	}
	// chekcing if the Increase the Board X postion was pressed
	else if( m_btnBoardPosIncX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_gameData->GetBoardPtr()->GetBoardPos();
		int currentPosX = currentPos.x;

		// chekcing if the board goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( currentPosX == boardWindowWidth - m_gameData->GetBoardPtr()->GetBoardSize().x )
		{
			return;
		}

		// increase the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardPos( currentPosX + 5, currentPos.y );

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
		sf::Vector2f currentpos = m_gameData->GetBoardPtr()->GetBoardPos();
		int currentPosY = currentpos.y;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosY == 90 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardPos( currentpos.x, currentPosY - 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardPosY->SetText( std::to_string( currentPosY - 5 ) );
	}
	// chekcing if the increase the Board Y postion was pressed
	else if( m_btnBoardPosIncY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_gameData->GetBoardPtr()->GetBoardPos();
		int currentPosY = currentpos.y;

		// chekcing if the board goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t boardHeigh = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;

		if( currentPosY == boardHeigh - m_gameData->GetBoardPtr()->GetBoardSize().y )
		{
			return;
		}

		// increase the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardPos( currentpos.x, currentPosY + 5 );

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
		sf::Vector2f currentSize = m_gameData->GetBoardPtr()->GetBoardSize();
		int currentSizeX = currentSize.x;

		// chekcing if the current size.x is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardSize( currentSizeX - 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the incresase the Board X size was pressed
	else if( m_btnBoardSizeIncX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_gameData->GetBoardPtr()->GetBoardSize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( ( unsigned )m_gameData->GetBoardPtr()->GetBoardPos().x + currentSizeX + 5 >= boardWindowWidth )
		{
			return;
		}

		// increase the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardSize( currentSizeX + 5, currentSize.y );

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
		sf::Vector2f currentSize = m_gameData->GetBoardPtr()->GetBoardSize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardSize( currentSize.x, currentSizeY - 5 );

		// updating the textbox showing the x-positon value
		m_txtBoardSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the Board Y size was pressed
	else if( m_btnBoardSizeIncY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_gameData->GetBoardPtr()->GetBoardSize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make board to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		if( ( unsigned )m_gameData->GetBoardPtr()->GetBoardPos().y + currentSizeY + 5 >= windowHieght )
		{
			return;
		}

		// increase the board x position by 5 units
		m_gameData->GetBoardPtr()->SetBoardSize( currentSize.x, currentSizeY + 5 );

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
		unsigned currentRow = m_gameData->GetBoardPtr()->GetNumRow();

		// chekcing if the current row num is 0 then do nothing
		if( currentRow <= 1 )
		{
			return;
		}

		// decrease the board row number by 1 units
		m_gameData->GetBoardPtr()->SetNumRow( currentRow - 1, nullptr );

		// updating the textbox showing the row value
		m_txtBoardRow->SetText( std::to_string( currentRow - 1 ) );
	}
	// chekcing if the increase the Board row was pressed
	else if( m_btnBoardIncRow->DoElement() )
	{
		// getting row information
		unsigned currentRow = m_gameData->GetBoardPtr()->GetNumRow();

		// chekcing if the current row is 100 then do notthing
		if( currentRow > 100 )
		{
			return;
		}

		// increase the board row number by 1 units
		m_gameData->GetBoardPtr()->SetNumRow( currentRow + 1, m_gameData->GetDeckManagerPtr()->GetDeckAtIdx( 0 ) );

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
		unsigned currentCol = m_gameData->GetBoardPtr()->GetNumCol();

		// chekcing if the current row num is 0 then do nothing
		if( currentCol <= 1 )
		{
			return;
		}

		// decrease the board row number by 1 units
		m_gameData->GetBoardPtr()->SetNumCol( currentCol - 1, nullptr );

		// updating the textbox showing the column value
		m_txtBoardCol->SetText( std::to_string( currentCol - 1 ) );
	}
	// chekcing if the increase the Board column was pressed
	else if( m_btnBoardIncCol->DoElement() )
	{
		// getting column information
		unsigned currentCol = m_gameData->GetBoardPtr()->GetNumCol();

		// chekcing if the current column is 100 then do notthing
		if( currentCol > 100 )
		{
			return;
		}

		// increase the board row number by 1 units
		m_gameData->GetBoardPtr()->SetNumCol( currentCol + 1, m_gameData->GetDeckManagerPtr()->GetDeckAtIdx( 0 ) );

		// updating the textbox showing the column value
		m_txtBoardCol->SetText( std::to_string( currentCol + 1 ) );
	}
}

// ======================================================================
// ================= end of BoardEditor class ===========================
// ======================================================================