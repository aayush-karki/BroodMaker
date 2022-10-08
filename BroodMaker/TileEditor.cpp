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
// ================= start of TileEditor class ==========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::TileEditor::TileEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::TileEditor::~TileEditor()
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
void Brood::Application::TileEditor::InitializeWorkSpace()
{
	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "Path Settings" );
	m_txtSettingTitle->SetFontSize( 18 );

	Brood::Application::Components::Path* currActivePath = m_gameData->GetBoardPtr()->GetCurrentActivePath();

	// creating a panel element to control the currentActive tile's row
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileCurrRowPromt, &m_btnTileDecCurrRow,
								 &m_txtTileCurrRow, &m_btnTileIncCurrRow,
								 "Curr Active Tile Row",
								 std::to_string( ( int )currActivePath->GetTilePtr()->GetRow() ), true );

	// creating a panel element to control the currentActive tile's Col
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileCurrColPromt, &m_btnTileDecCurrCol,
								 &m_txtTileCurrCol, &m_btnTileIncCurrCol,
								 "Curr Active Tile Col",
								 std::to_string( ( int )currActivePath->GetTilePtr()->GetCol() ) );

	// initializing the UI to set the tile type
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtTileTypePromt, &m_ddiTileType,
										"Tile Type: ", { "Blank Tile",	"Tile Tile","Start Tile", "End Tile", "Bridge Tile" },
										19 );

	// creating a panel element to control the NextPath tile's row
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileNextPathRowPromt, &m_btnTileDecNextPathRow,
								 &m_txtTileNextPathRow, &m_btnTileIncNextPathRow,
								 "Next Tile Row",
								 std::to_string( ( int )currActivePath->GetBridgeEndPathPtr()->GetTilePtr()->GetRow() ) );

	// creating a panel element to control the NextPath tile's Col
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileNextPathColPromt, &m_btnTileDecNextPathCol,
								 &m_txtTileNextPathCol, &m_btnTileIncNextPathCol,
								 "Next Tile Col",
								 std::to_string( ( int )currActivePath->GetBridgeEndPathPtr()->GetTilePtr()->GetCol() ) );

	// creating a panel element to control the EndBridge tile's row
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileEndBridgeRowPromt, &m_btnTileDecEndBridgeRow,
								 &m_txtTileEndBridgeRow, &m_btnTileIncEndBridgeRow,
								 "End Bridge Tile Row",
								 std::to_string( ( int )currActivePath->GetBridgeEndPathPtr()->GetTilePtr()->GetRow() ) );

	// creating a panel element to control the EndBridge tile's Col
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileEndBridgeColPromt, &m_btnTileDecEndBridgeCol,
								 &m_txtTileEndBridgeCol, &m_btnTileIncEndBridgeCol,
								 "End Bridge Tile Col",
								 std::to_string( ( int )currActivePath->GetBridgeEndPathPtr()->GetTilePtr()->GetCol() ) );

	// creating a panel element to control the number of correct card
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileNumCorrectCardPromt, &m_btnTileDecNumCorrectCard,
								 &m_txtTileNumCorrectCard, &m_btnTileIncNumCorrectCard,
								 "Number of Card",
								 std::to_string( ( int )currActivePath->GetNumCardDraw() ) );

	// creating a panel element to control the assigned deck number
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtTileAssignedDeckIdxPromt, &m_btnTileDecAssignedDeckIdx,
								 &m_txtTileAssignedDeckIdx, &m_btnTileIncAssignedDeckIdx,
								 "Assigned Deck Index",
								 std::to_string( ( int )currActivePath->GetDeckIdx() ) );

	// initializing the UI to set the incorrect penalty
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtTileForceDiceRollPromt, &m_ddiTileForceDiceRoll,
										"Force Dice Roll: ", { "Yes", "No" }, 27 );

	// initializing the UI to control tile bg file name
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtTileBgFileNamePrompt, &m_txtTileBgFileInput,
									&m_btnTileBgOpenFile, "tile texture Filename",
									currActivePath->GetTilePtr()->GetSpriteBody().GetTextureFileName() );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::TileEditor::Update()
{
	// checks if the user interacted with the tile row
	// number panel Element
	UpdateTileRowNumber();

	// checks if the user interacted with the tile column
	// number panel Element
	UpdateTileColNumber();

	// checks if the user interacted with the tile type
	// panel Element
	UpdateTileType();

	// checks if the user interacted with the NextPath row
	// number panel Element
	UpdateNextPathRowNumber();

	// checks if the user interacted with the NextPath column
	// number panel Element
	UpdateNextPathColNumber();

	// checks if the user interacted with the EndBridge row
	// number panel Element
	UpdateEndBridgeRowNumber();

	// checks if the user interacted with the EndBridge column
	// number panel Element
	UpdateEndBridgeColNumber();

	// checks if the user interacted with the correct number 
	// of card panel Element
	UpdateCorrectCardNumber();

	// checks if the user interacted with the assign deck idx
	// panel Element
	UpdateAssinedDeckIdx();

	// checks if the user interacted with the force dice roll
	// panel Element
	UpdateForceDiceRoll();

	// checks if the user interacted with the load 
	// tile texture panel Element
	UpdateTileFileTexture();


}

/// 
/// @public
/// @virtual
/// @brief updates the display element
/// 
void Brood::Application::TileEditor::UpdateAllDispayElement()
{

	Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
	Brood::Application::Components::Path* currActivepathPtr = boardPtr->GetCurrentActivePath();

	// tile row value
	m_txtTileCurrRow->SetText( std::to_string( currActivepathPtr->GetTilePtr()->GetRow() ) );

	// tile column value
	m_txtTileCurrCol->SetText( std::to_string( currActivepathPtr->GetTilePtr()->GetCol() ) );

	// tile type
	unsigned itemIdx = ( int )currActivepathPtr->GetTileType();
	std::string itemName = m_ddiTileType->GetItemList().at( itemIdx )->GetText();
	m_ddiTileType->SetText( itemName );

	// next path row
	m_txtTileNextPathRow->SetText( std::to_string( currActivepathPtr->GetNextPathPtr()->GetTilePtr()->GetRow() ) );

	// next path col
	m_txtTileNextPathCol->SetText( std::to_string( currActivepathPtr->GetNextPathPtr()->GetTilePtr()->GetCol() ) );

	// Bridge End row
	m_txtTileEndBridgeRow->SetText( std::to_string( currActivepathPtr->GetBridgeEndPathPtr()->GetTilePtr()->GetRow() ) );

	// Bridge End col
	m_txtTileEndBridgeCol->SetText( std::to_string( currActivepathPtr->GetBridgeEndPathPtr()->GetTilePtr()->GetCol() ) );

	// Correct card number 
	m_txtTileNumCorrectCard->SetText( std::to_string( currActivepathPtr->GetNumCardDraw() ) );

	// assigned deck
	m_txtTileAssignedDeckIdx->SetText( std::to_string( currActivepathPtr->GetDeckIdx() ) );

	// Force dice roll
	itemIdx = !currActivepathPtr->GetForceDiceRoll();
	itemName = m_ddiTileForceDiceRoll->GetItemList().at( itemIdx )->GetText();
	while( itemName.size() < 27 )
	{
		itemName = " " + itemName + " ";
	}
	m_ddiTileForceDiceRoll->SetText( itemName + " v" );

	// tile file name
	m_txtTileBgFileInput->SetText( currActivepathPtr->GetTilePtr()->GetSpriteBody().GetTextureFileName() );

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
void Brood::Application::TileEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing game component
	m_gameData->Draw( a_window );

	// drawing the dynamically 
	Brood::Application::WorkSpace::Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::TileEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}

/// 
/// @private
/// @brief checks if the user interacted with the tile row panel
///	
/// Tile row panel contains the Tile row number promt textbox, 
///		Tile row number value text box, button to increase the
///		Tile row number, and button to decrease the Tile row
///		 number
/// 
/// Only the button to increase the Tile row number, and button 
///		to decrease the Tile row number are interactable
/// 
/// If the interactable button was pressed then the Tile row
///		is increased or decresed by 1. Tile row number
///		should be more than or equal to 0 but less than board 
///		row number
///
void Brood::Application::TileEditor::UpdateTileRowNumber()
{
	// chekcing if the decrease the tile row number was pressed
	if( m_btnTileDecCurrRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();

		// getting current tile row number
		unsigned currentTileRowNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetRow();
		unsigned currentTileColNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is 0 then do nothing
		if( currentTileRowNum == 0 )
		{
			return;
		}

		// decrease the tile row number by 1 units
		boardPtr->SetCurrentActiveTilePtr( boardPtr->GetBoardPathList().at( currentTileRowNum - 1 ).at( currentTileColNum ) );

		// updating the textbox showing the tile row value
		m_txtTileCurrRow->SetText( std::to_string( currentTileRowNum - 1 ) );

		UpdateAllDispayElement();
	}
	// chekcing if the increase the tile row number was pressed
	else if( m_btnTileIncCurrRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();

		// getting current tile row number
		unsigned currentTileRowNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetRow();
		unsigned currentTileColNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board row number then do nothing
		if( currentTileRowNum == boardPtr->GetNumRow() - 1 )
		{
			return;
		}

		// increase the tile row number by 1 units
		boardPtr->SetCurrentActiveTilePtr( boardPtr->GetBoardPathList().at( currentTileRowNum + 1 ).at( currentTileColNum ) );

		// updating the textbox showing the tile row value
		m_txtTileCurrRow->SetText( std::to_string( currentTileRowNum + 1 ) );

		UpdateAllDispayElement();
	}
}
/// 
/// @private
/// @brief checks if the user interacted with the tile column panel
///	
/// Tile column panel contains the tile column number promt textbox, 
///		tile column number value text box, button to increase the
///		tile column number, and button to decrease the tile column
///		 number
/// 
/// Only the button to increase the tile column number, and button 
///		to decrease the tile column number are interactable
/// 
/// If the interactable button was pressed then the tile column
///		is increased or decresed by 1. Tile column number
///		should be more than or equal to 0 but less than board 
///		column number
///
void Brood::Application::TileEditor::UpdateTileColNumber()
{
	// chekcing if the decrease the tile column number was pressed
	if( m_btnTileDecCurrCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();

		// getting current tile row number
		unsigned currentTileRowNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetRow();
		unsigned currentTileColNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartColNum is 0 then do nothing
		if( currentTileColNum == 0 )
		{
			return;
		}

		// decrease the tile column number by 1 units
		boardPtr->SetCurrentActiveTilePtr( boardPtr->GetBoardPathList().at( currentTileRowNum ).at( currentTileColNum - 1 ) );

		// updating the textbox showing the tile column value
		m_txtTileCurrCol->SetText( std::to_string( currentTileColNum - 1 ) );

		UpdateAllDispayElement();
	}
	// chekcing if the increase the tile column number was pressed
	else if( m_btnTileIncCurrCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();

		// getting current tile row number
		unsigned currentTileRowNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetRow();
		unsigned currentTileColNum = boardPtr->GetCurrentActivePath()->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board column number then do nothing
		if( currentTileColNum == boardPtr->GetNumCol() - 1 )
		{
			return;
		}
		// increase the tile column number by 1 units
		boardPtr->SetCurrentActiveTilePtr( boardPtr->GetBoardPathList().at( currentTileRowNum ).at( currentTileColNum + 1 ) );

		// updating the textbox showing the tile column value
		m_txtTileCurrCol->SetText( std::to_string( currentTileColNum + 1 ) );

		UpdateAllDispayElement();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the tile type panel
///	
///  Tile type panel contains Board  tile type promt textbox, 
///		and drop down input to select a tile type
/// 
/// Only the drop down input to select the tile type is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the five option avialble blank tile, tile tile, start tile,
///		end tile, bridge tile
/// 
void Brood::Application::TileEditor::UpdateTileType()
{
	if( m_ddiTileType->DoElement() )
	{
		std::cout << "myDropDownInput Pressed" << std::endl;
	}

	if( m_ddiTileType->IsSelected() )
	{
		auto itemList = m_ddiTileType->GetItemList();
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
					std::string itemName = m_ddiTileType->GetItemList().at( currIDx )->GetText();

					while( itemName.size() < 33 )
					{
						itemName = "     " + itemName + "     ";
					}

					m_ddiTileType->SetText( itemName + "  v" );

					// executing the function
					std::cerr << "item at " << currIDx << "  Pressed with ID " <<
						itemList.at( currIDx )->GetText() << std::endl;

					m_gameData->GetBoardPtr()->GetCurrentActivePath()->SetTileType( static_cast< Brood::Application::Components::ENUM_TileType >( currIDx ) );
				}
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the TileNextPath row panel
///	
/// TileNextPath row panel contains the TileNextPath row number promt textbox, 
///		TileNextPath row number value text box, button to increase the
///		TileNextPath row number, and button to decrease the TileNextPath row
///		 number
/// 
/// Only the button to increase the TileNextPath row number, and button 
///		to decrease the TileNextPath row number are interactable
/// 
/// If the interactable button was pressed then the TileNextPath row
///		is increased or decresed by 1. TileNextPath row number
///		should be more than or equal to 0 and can only be smaller 
///		or bigger than current tile row by 1
///
void Brood::Application::TileEditor::UpdateNextPathRowNumber()
{
	// chekcing if the decrease the tile row number was pressed
	if( m_btnTileDecNextPathRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currNextPathPtr = currActicepathPtr->GetNextPathPtr();

		// getting NextPath tile row number
		unsigned currentNextPathRowNum = currNextPathPtr->GetTilePtr()->GetRow();
		unsigned currentNextPathColNum = currNextPathPtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is 0 then do nothing
		if( currentNextPathRowNum == 0 )
		{
			return;
		}

		unsigned currTileRow = currActicepathPtr->GetTilePtr()->GetRow();
		if( currentNextPathRowNum == currTileRow || currentNextPathRowNum == currTileRow + 1 )
		{
			// decrease the tile row number by 1 units
			currActicepathPtr->SetNextPathPtr( boardPtr->GetBoardPathList().at( currentNextPathRowNum - 1 ).at( currentNextPathColNum ) );

			// updating the textbox showing the tile row value
			m_txtTileNextPathRow->SetText( std::to_string( currentNextPathRowNum - 1 ) );
		}

	}
	// chekcing if the increase the tile row number was pressed
	else if( m_btnTileIncNextPathRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currNextPathPtr = currActicepathPtr->GetNextPathPtr();

		// getting NextPath tile row number
		unsigned currentNextPathRowNum = currNextPathPtr->GetTilePtr()->GetRow();
		unsigned currentNextPathColNum = currNextPathPtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board row number then do nothing
		if( currentNextPathRowNum == boardPtr->GetNumRow() - 1 )
		{
			return;
		}

		unsigned currTileRow = currActicepathPtr->GetTilePtr()->GetRow();
		if( currentNextPathRowNum == currTileRow || currentNextPathRowNum == currTileRow - 1 )
		{
			// decrease the tile row number by 1 units
			currActicepathPtr->SetNextPathPtr( boardPtr->GetBoardPathList().at( currentNextPathRowNum + 1 ).at( currentNextPathColNum ) );

			// updating the textbox showing the tile row value
			m_txtTileNextPathRow->SetText( std::to_string( currentNextPathRowNum + 1 ) );
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the TileNextPath col panel
///	
/// TileNextPath col panel contains the TileNextPath col number promt textbox, 
///		TileNextPath col number value text box, button to increase the
///		TileNextPath col number, and button to decrease the TileNextPath col
///		 number
/// 
/// Only the button to increase the TileNextPath col number, and button 
///		to decrease the TileNextPath col number are interactable
/// 
/// If the interactable button was pressed then the TileNextPath col
///		is increased or decresed by 1. TileNextPath col number
///		should be more than or equal to 0 but less than board 
///		col number
///
void Brood::Application::TileEditor::UpdateNextPathColNumber()
{
	// chekcing if the decrease the tile column number was pressed
	if( m_btnTileDecNextPathCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currNextPathPtr = currActicepathPtr->GetNextPathPtr();

		// getting NextPath tile row number
		unsigned currentNextPathRowNum = currNextPathPtr->GetTilePtr()->GetRow();
		unsigned currentNextPathColNum = currNextPathPtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartColNum is 0 then do nothing
		if( currentNextPathColNum == 0 )
		{
			return;
		}

		unsigned currTileCol = currActicepathPtr->GetTilePtr()->GetCol();
		if( currentNextPathColNum == currTileCol || currentNextPathColNum == currTileCol + 1 )
		{
			// decrease the tile column number by 1 units
			currActicepathPtr->SetNextPathPtr( boardPtr->GetBoardPathList().at( currentNextPathRowNum ).at( currentNextPathColNum - 1 ) );

			// updating the textbox showing the tile column value
			m_txtTileNextPathCol->SetText( std::to_string( currentNextPathColNum - 1 ) );
		}

	}
	// chekcing if the increase the tile column number was pressed
	else if( m_btnTileIncNextPathCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currNextPathPtr = currActicepathPtr->GetNextPathPtr();

		// getting NextPath tile row number
		unsigned currentNextPathRowNum = currNextPathPtr->GetTilePtr()->GetRow();
		unsigned currentNextPathColNum = currNextPathPtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board column number then do nothing
		if( currentNextPathColNum == boardPtr->GetNumCol() - 1 )
		{
			return;
		}

		unsigned currTileCol = currActicepathPtr->GetTilePtr()->GetCol();
		if( currentNextPathColNum == currTileCol || currentNextPathColNum == currTileCol - 1 )
		{
			// increasing the tile column number by 1 units
			currActicepathPtr->SetNextPathPtr( boardPtr->GetBoardPathList().at( currentNextPathRowNum ).at( currentNextPathColNum + 1 ) );

			// updating the textbox showing the tile column value
			m_txtTileNextPathCol->SetText( std::to_string( currentNextPathColNum + 1 ) );
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the TileEndBridge row panel
///	
/// TileEndBridge row panel contains the TileEndBridge row number promt textbox, 
///		TileEndBridge row number value text box, button to increase the
///		TileEndBridge row number, and button to decrease the TileEndBridge row
///		 number
/// 
/// Only the button to increase the TileEndBridge row number, and button 
///		to decrease the TileEndBridge row number are interactable
/// 
/// If the interactable button was pressed then the TileEndBridge row
///		is increased or decresed by 1. TileEndBridge row number
///		should be more than or equal to 0 but less than board 
///		row number
///
void Brood::Application::TileEditor::UpdateEndBridgeRowNumber()
{
	// chekcing if the decrease the tile row number was pressed
	if( m_btnTileDecEndBridgeRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currEndBridgePtr = currActicepathPtr->GetBridgeEndPathPtr();

		// getting EndBridge tile row number
		unsigned currentEndBridgeRowNum = currEndBridgePtr->GetTilePtr()->GetRow();
		unsigned currentEndBridgeColNum = currEndBridgePtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is 0 then do nothing
		if( currentEndBridgeRowNum == 0 )
		{
			return;
		}

		// decrease the tile row number by 1 units
		currActicepathPtr->SetBridgeEndPathPtr( boardPtr->GetBoardPathList().at( currentEndBridgeRowNum - 1 ).at( currentEndBridgeColNum ) );

		// updating the textbox showing the tile row value
		m_txtTileEndBridgeRow->SetText( std::to_string( currentEndBridgeRowNum - 1 ) );
	}
	// chekcing if the increase the tile row number was pressed
	else if( m_btnTileIncEndBridgeRow->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currEndBridgePtr = currActicepathPtr->GetBridgeEndPathPtr();

		// getting EndBridge tile row number
		unsigned currentEndBridgeRowNum = currEndBridgePtr->GetTilePtr()->GetRow();
		unsigned currentEndBridgeColNum = currEndBridgePtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board row number then do nothing
		if( currentEndBridgeRowNum == boardPtr->GetNumRow() - 1 )
		{
			return;
		}

		// decrease the tile row number by 1 units
		currActicepathPtr->SetBridgeEndPathPtr( boardPtr->GetBoardPathList().at( currentEndBridgeRowNum + 1 ).at( currentEndBridgeColNum ) );

		// updating the textbox showing the tile row value
		m_txtTileEndBridgeRow->SetText( std::to_string( currentEndBridgeRowNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the TileEndBridge col panel
///	
/// TileEndBridge col panel contains the TileEndBridge col number promt textbox, 
///		TileEndBridge col number value text box, button to increase the
///		TileEndBridge col number, and button to decrease the TileEndBridge col
///		 number
/// 
/// Only the button to increase the TileEndBridge col number, and button 
///		to decrease the TileEndBridge col number are interactable
/// 
/// If the interactable button was pressed then the TileEndBridge col
///		is increased or decresed by 1. TileEndBridge col number
///		should be more than or equal to 0 but less than board 
///		col number
///
void Brood::Application::TileEditor::UpdateEndBridgeColNumber()
{
	// chekcing if the decrease the tile column number was pressed
	if( m_btnTileDecEndBridgeCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currEndBridgePtr = currActicepathPtr->GetBridgeEndPathPtr();

		// getting EndBridge tile row number
		unsigned currentEndBridgeRowNum = currEndBridgePtr->GetTilePtr()->GetRow();
		unsigned currentEndBridgeColNum = currEndBridgePtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartColNum is 0 then do nothing
		if( currentEndBridgeColNum == 0 )
		{
			return;
		}

		// decrease the tile column number by 1 units
		currActicepathPtr->SetBridgeEndPathPtr( boardPtr->GetBoardPathList().at( currentEndBridgeRowNum ).at( currentEndBridgeColNum - 1 ) );

		// updating the textbox showing the tile column value
		m_txtTileEndBridgeCol->SetText( std::to_string( currentEndBridgeColNum - 1 ) );

	}
	// chekcing if the increase the tile column number was pressed
	else if( m_btnTileIncEndBridgeCol->DoElement() )
	{
		Brood::Application::Components::Board* boardPtr = m_gameData->GetBoardPtr();
		Brood::Application::Components::Path* currActicepathPtr = boardPtr->GetCurrentActivePath();
		Brood::Application::Components::Path* currEndBridgePtr = currActicepathPtr->GetBridgeEndPathPtr();

		// getting EndBridge tile row number
		unsigned currentEndBridgeRowNum = currEndBridgePtr->GetTilePtr()->GetRow();
		unsigned currentEndBridgeColNum = currEndBridgePtr->GetTilePtr()->GetCol();

		// chekcing if the current currentStartRowNum is equal 
		// to the board column number then do nothing
		if( currentEndBridgeColNum == boardPtr->GetNumCol() - 1 )
		{
			return;
		}

		// increasing the tile column number by 1 units
		currActicepathPtr->SetBridgeEndPathPtr( boardPtr->GetBoardPathList().at( currentEndBridgeRowNum ).at( currentEndBridgeColNum + 1 ) );

		// updating the textbox showing the tile column value
		m_txtTileEndBridgeCol->SetText( std::to_string( currentEndBridgeColNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Correct card number
///	
/// Correct card number panel contains the Correct card number promt textbox, 
///		Correct card number value text box, button to increase the
///		Correct card number number, and button to decrease the 
///		Correct card number number
/// 
/// Only the button to increase the Correct card number, and button 
///		to decrease the Correct card number are interactable
/// 
/// If the interactable button was pressed then the Correct card number
///		is increased or decresed by 1.Correct card number
///		should be more than or equal to 1 but less than number of cards 
///		in the assigned deck
///
void Brood::Application::TileEditor::UpdateCorrectCardNumber()
{
	// chekcing if the decrease the Correct card number was pressed
	if( m_btnTileDecNumCorrectCard->DoElement() )
	{
		Brood::Application::Components::Path* currActivepathPtr = m_gameData->GetBoardPtr()->GetCurrentActivePath();

		// getting activ tile's Correct card number
		unsigned numCards = currActivepathPtr->GetNumCardDraw();

		// chekcing if the current numCards is 0 then do nothing
		if( numCards <= 1 )
		{
			return;
		}

		// decrease the tile Correct card number by 1 units
		currActivepathPtr->SetNumCardDraw( numCards - 1 );

		// updating the textbox showing the Correct card number value
		m_txtTileNumCorrectCard->SetText( std::to_string( numCards - 1 ) );
	}
	// chekcing if the increase the  Correct card number was pressed
	else if( m_btnTileIncNumCorrectCard->DoElement() )
	{
		Brood::Application::Components::Path* currActivepathPtr = m_gameData->GetBoardPtr()->GetCurrentActivePath();

		// getting activ tile's Correct card number
		unsigned numCards = currActivepathPtr->GetNumCardDraw();

		// chekcing if the current numCards is 0 then do nothing
		if( numCards >= currActivepathPtr->GetDeckPtr()->GetCardList().size() )
		{
			return;
		}

		// increasing the tile Correct card number by 1 units
		currActivepathPtr->SetNumCardDraw( numCards + 1 );

		// updating the textbox showing the Correct card number value
		m_txtTileNumCorrectCard->SetText( std::to_string( numCards + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Assigned deck number
///	
/// Assigned deck number panel contains the Assigned deck number promt textbox, 
///		Assigned deck number value text box, button to increase the
///		Assigned deck number number, and button to decrease the 
///		Assigned deck number number
/// 
/// Only the button to increase the Assigned deck number, and button 
///		to decrease the Assigned deck number are interactable
/// 
/// If the interactable button was pressed then the Assigned deck number
///		is increased or decresed by 1.Assigned deck number
///		should be more than or equal to 0 but less than number of cards 
///		in the assigned deck
///
void Brood::Application::TileEditor::UpdateAssinedDeckIdx()
{
	// chekcing if the decrease the Assigned deck number was pressed
	if( m_btnTileDecAssignedDeckIdx->DoElement() )
	{
		Brood::Application::Components::Path* currActivepathPtr = m_gameData->GetBoardPtr()->GetCurrentActivePath();

		// getting activ tile's Assigned deck number
		unsigned deckIdx = currActivepathPtr->GetDeckIdx();

		// chekcing if the current deckidx is 0 then do nothing
		if( deckIdx == 0 )
		{
			return;
		}

		// decrease the tile Assigned deck number by 1 units
		currActivepathPtr->SetDeckIdx( deckIdx - 1 );
		currActivepathPtr->SetDeckPtr( m_gameData->GetDeckManagerPtr()->GetDeckAtIdx( deckIdx - 1 ) );

		// updating the textbox showing the Assigned deck number value
		m_txtTileAssignedDeckIdx->SetText( std::to_string( deckIdx - 1 ) );

		// cheking if the number of correct card is more than current deck size
		if( currActivepathPtr->GetNumCardDraw() >= currActivepathPtr->GetDeckPtr()->GetCardList().size() )
		{
			currActivepathPtr->SetNumCardDraw( currActivepathPtr->GetDeckPtr()->GetCardList().size() );
			UpdateAllDispayElement();
		}

	}
	// chekcing if the increase the  Assigned deck number was pressed
	else if( m_btnTileIncAssignedDeckIdx->DoElement() )
	{
		Brood::Application::Components::Path* currActivepathPtr = m_gameData->GetBoardPtr()->GetCurrentActivePath();
		Brood::Application::Components::DeckManager* deckManagerPtr = m_gameData->GetDeckManagerPtr();

		// getting activ tile's Assigned deck number
		unsigned deckIdx = currActivepathPtr->GetDeckIdx();

		// chekcing if increasing the current deckidx by would make us 
		// go over num deck then do nothing
		if( deckIdx + 1 == deckManagerPtr->GetDeckList().size() )
		{
			return;
		}

		// decrease the tile Assigned deck number by 1 units
		currActivepathPtr->SetDeckIdx( deckIdx + 1 );
		currActivepathPtr->SetDeckPtr( deckManagerPtr->GetDeckAtIdx( deckIdx + 1 ) );

		// updating the textbox showing the Assigned deck number value
		m_txtTileAssignedDeckIdx->SetText( std::to_string( deckIdx + 1 ) );

		// cheking if the number of correct card is more than current deck size
		if( currActivepathPtr->GetNumCardDraw() >= currActivepathPtr->GetDeckPtr()->GetCardList().size() )
		{
			currActivepathPtr->SetNumCardDraw( currActivepathPtr->GetDeckPtr()->GetCardList().size() );
			UpdateAllDispayElement();

		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the force 
///		dice roll panel
///	
///  Tile type panel contains force dice roll panel promt 
///		textbox, and drop down input to select a yes or no
/// 
/// Only the drop down input to select the yes or no is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the two option avialble  yes and no
/// 
void Brood::Application::TileEditor::UpdateForceDiceRoll()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiTileForceDiceRoll->DoElement() || m_ddiTileForceDiceRoll->IsSelected() )
	{
		auto itemList = m_ddiTileForceDiceRoll->GetItemList();
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
				m_ddiTileForceDiceRoll->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;

				m_gameData->GetBoardPtr()->GetCurrentActivePath()->SetForceDiceRoll( !itemIdx );
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the laod tile texture 
///		panel
///	
/// Load tile texture file panel contains load tile texture file 
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
/// @warning the Texture for the file should be in \Assets\Textures\TileTexture\
///		as it loads them from there. 
/// 
void Brood::Application::TileEditor::UpdateTileFileTexture()
{
	if( m_txtTileBgFileInput->DoElement() )
	{
		m_txtTileBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnTileBgOpenFile->DoElement() || ( m_txtTileBgFileInput->IsEnterPressed() &&
											  m_txtTileBgFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string tileTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_tileTextures.string();

		tileTextureFilePath += "\\" + m_txtTileBgFileInput->GetText();


		// loading the texture file
		if( !m_gameData->GetBoardPtr()->GetCurrentActivePath()->GetTilePtr()->GetSpriteBody().SetTextureFromFilePath( tileTextureFilePath ) )
		{
			m_txtTileBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}

		// resetting the m_eterPressed
		m_txtTileBgFileInput->SetEnterPressedFalse();
	}
}


// ======================================================================
// ================= end of TileEditor class ============================
// ======================================================================