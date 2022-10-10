/*************************************************************************/
/// 
/// @file EditorWorkspace.cpp 
/// 
/// @brief  This file is a source file for EditorWorkspace class
/// 
/// It also contains all of the declaration of the EditorWorkspace
///		class's member function.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "EditorWorkspace.h"

// ======================================================================
// ================= start of EditorWorkspace class =====================
// ======================================================================

/// 
/// @brief default constructor
/// 
Brood::Application::EditorWorkspace::EditorWorkspace( Brood::Application::Components::GameDataManager* a_gameData ) :
	m_activeEditorIdx( 0 )
{
	
	this->m_gameData = a_gameData;

	InitializeWorkSpace();
}

/// 
/// @brief  default destructor
/// 
Brood::Application::EditorWorkspace::~EditorWorkspace()
{}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It initializes 
///		the EditMOde tabs and the editor workspaces
//
void Brood::Application::EditorWorkspace::InitializeWorkSpace()
{
	// initialzing the side panel
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;

	float panelSizeX = ( windowWidth * Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) / 100;
	float panelSizeY = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
	m_sidePanel.setSize( { panelSizeX ,panelSizeY } );

	float panelPoxX = windowWidth - panelSizeX;
	float panelPoxY = 50.f;
	m_sidePanel.setPosition( { panelPoxX ,panelPoxY } );

	m_sidePanel.setFillColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_MainMenu );

	// initializing the edit mode
	InitializeEditModeTabs();

	// ====== initializing the workspaces =======

	// initializing game editor
	m_editorWorkspaceList.push_back( new GameEditor( this->m_gameData, &m_sidePanel ) );

	// initializing boad editor
	m_editorWorkspaceList.push_back( new BoardEditor( this->m_gameData, &m_sidePanel ) );

	// initializing tile editor
	m_editorWorkspaceList.push_back( new TileEditor( this->m_gameData, &m_sidePanel ) );

	// initializing player editor
	m_editorWorkspaceList.push_back( new PlayerEditor( this->m_gameData, &m_sidePanel ) );

	// initializing dice editor
	m_editorWorkspaceList.push_back( new DiceEditor( this->m_gameData, &m_sidePanel ) );

	// initializing deck editor
	m_editorWorkspaceList.push_back( new DeckEditor( this->m_gameData, &m_sidePanel ) );

	// initializing card editor
	m_editorWorkspaceList.push_back( new CardEditor( this->m_gameData, &m_sidePanel ) );

}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::EditorWorkspace::Update()
{
	UpdateEditModeTabs();
	m_editorWorkspaceList.at( m_activeEditorIdx )->Update();
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::EditorWorkspace::Draw( sf::RenderWindow& a_window )
{
	//// drawing the board
	//m_board.Draw( a_window );

	//// drawing the dice
	//m_dice.Draw(a_window);

	// drawing the side panel
	a_window.draw( m_sidePanel );

	// drawing the editor workspace
	m_editorWorkspaceList.at( m_activeEditorIdx )->Draw( a_window );

	// drawing the edit tabs to screen
	for( unsigned i = 0; i < m_editModesTabs.size(); ++i )
	{
		m_editModesTabs.at( i )->Draw( a_window );
	}
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::EditorWorkspace::Debugger()
{
	Brood::Application::WorkSpace::Debugger();
}

/// 
/// @public
/// @virtual
/// @brief setter function for game data
/// 
void Brood::Application::EditorWorkspace::SetGameDataManager( Brood::Application::Components::GameDataManager* a_gameDataManagerPtr )
{
	this->m_gameData = a_gameDataManagerPtr;

	// updating all the the editor Workspace
	for( unsigned i = 0; i < m_editorWorkspaceList.size(); ++i )
	{
		m_editorWorkspaceList.at( i )->SetGameDataManager( this->m_gameData );
	}
}

/// 
/// @public
/// @virtual
/// @brief calls the updates all the display element for 
///		the current active editor
///
void Brood::Application::EditorWorkspace::UpdateAllDispayElement()
{
	for( unsigned i = 0; i < m_editorWorkspaceList.size(); ++i )
	{
		m_editorWorkspaceList.at(i)->UpdateAllDispayElement();
	}
}

/// 
/// @private
/// @brief Initializes the edit mode tab bar which is at the top of the edit 
///		window
/// 
/// It has the 4 edit modes in it: Board Edit, Tiles Edit, Path Edit, and Deck Edit
/// 
/// Board Edit allows for the general settings to be edited.
/// 
/// Tile Edit allows for tiles setting to be changed for indivisual tiles.
/// 
/// Path Edit allows for the path that the players take to be changed.
/// 
/// Deck Edit allows for the deck and card setting to be changed
/// 
void Brood::Application::EditorWorkspace::InitializeEditModeTabs()
{
	unsigned editModeTabWidthPercentage = 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage;
	float editModeTabWidth = ( ( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width * editModeTabWidthPercentage ) / 100 ) / float( 7 );
	unsigned currEdit = 0;
	//m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Game Edit" ) );
	//m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Board Edit" ) );
	//m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Tiles Edit" ) );
	//m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Deck Edit" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Game" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Board" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Tiles" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Player" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Dice" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Deck" ) );
	m_editModesTabs.push_back( DyCreateButton( { editModeTabWidth, 40 }, { editModeTabWidth * currEdit++, 50 }, "Card" ) );

	// setting up the font size of the tabs
	for( unsigned idx = 0; idx < m_editModesTabs.size(); ++idx )
	{
		m_editModesTabs.at( idx )->SetFontSize( 22 );
	}

	// setting the First tab--board edit as the active tab
	UpdateActiveEditorIdx( 0 );
	m_editModesTabs.at( 0 )->SetSelected( true );

}

/// 
/// @private
/// @brief Checks to see if the ribbion tabs's logic is to be executed or not 
/// 
void Brood::Application::EditorWorkspace::UpdateEditModeTabs()
{
	for( unsigned tabIdx = 0; tabIdx < m_editModesTabs.size(); ++tabIdx )
	{
		// checking if the tab was set to activate or not
		if( m_editModesTabs.at( tabIdx )->DoElement() )
		{
			// saving the idx that was selected
			std::cout << "edit tab at " << tabIdx << " " << m_editModesTabs.at( tabIdx )->GetText() << " Pressed" << std::endl;

			// setting the overlay to false for all the tabs
			for( unsigned i = 0; i < m_editModesTabs.size(); ++i )
			{
				m_editModesTabs.at( i )->SetSelected( false );
			}

			// setting the activated tab as selected
			UpdateActiveEditorIdx( tabIdx );
			UpdateAllDispayElement();
			break;
		}
	}
}

/// 
/// @private
/// @brief updates the edit Tab and selects the proper tab
/// 
void Brood::Application::EditorWorkspace::UpdateActiveEditorIdx( unsigned a_idx )
{
	// checking if the same idx was pressed
	if( a_idx == m_activeEditorIdx )
	{
		return;
	}

	// if the current a_activeEditorIdx or the a_editor is the tile ediot
	// which is at idx 2 then toggle the draw line
	if( a_idx == 2 || m_activeEditorIdx == 2)
	{
		// toggling the draw line
		m_gameData->GetBoardPtr()->ToggleDrawLine();
	}

	m_editModesTabs.at( a_idx )->SetSelected( true );
	m_activeEditorIdx = a_idx;

}

// ======================================================================
// ================= end of EditorWorkspace class =======================
// ======================================================================
