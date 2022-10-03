/*************************************************************************/
/// 
/// @file InitialWorkSpace.cpp 
/// 
/// @brief  This file is a source file for InitialWorkSpace class.
/// 
/// It contains all of the defination of the member 
///		funciton of InitialWorkSpace class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "HomeWorkSpace.h"

#include <filesystem> /// @TODO delete me

// ======================================================================
// ================= start of InitialWorkSpace class ====================
// ======================================================================

/// 
/// @public
/// @brief default constructor
/// 
Brood::Application::HomeWorkSpace::HomeWorkSpace() :
	WorkSpace(), m_gameOrEditorBtn( nullptr ), m_toggleGameInfoLeftBtn( nullptr ),
	m_toggleGameInfoRightBtn( nullptr ), m_currGameInfoIdx( 1 ),
	m_showImportDialogBox( false ), m_importGameBtn( nullptr ),
	m_loadPreviousEditsBtn( nullptr ), m_createNewEditBtn( nullptr ),
	m_cancleBtn( nullptr ), m_showEnterFilenameDialogBox( false ),
	m_fileNameTxt( nullptr ), m_enterFileNameFeildTxt( nullptr ),
	m_openFileBtn( nullptr ), m_currWorkSpaceIdx( 0 ), m_isHomeWorkspace( true )
{
	m_gameInfoFilePathList.push_back( "Exit" );
	m_gameInfoFilePathList.push_back( "Add Game" );

	/// @TODO load the game info file path
	/// @TODO add the create games and exit to the file path
	/// @TODO load the game texture

	InitializeWorkSpace();


	/// @TODO deleteme
	m_isHomeWorkspace = false;
}

/// 
/// @public
/// @virtual
/// @brief default destructor
//
Brood::Application::HomeWorkSpace::~HomeWorkSpace()
{
	// dellocating the workspace
	for( unsigned idx = 0; idx < m_workSpacesList.size(); ++idx )
	{
		delete ( m_workSpacesList.at( idx ) );
	}
}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It inializes the ribbon 
///		tab, creates the left and right toggle button, game/edit seclection card,
///		importGames, loadPreviousEdits, CreateMew edit, cancle button, and create
///		new button. It also creates the  fileName, and enter FineName text feild
//
void Brood::Application::HomeWorkSpace::InitializeWorkSpace()
{
	// initializing menubar
	InitializeRibbionTabs();

	// creating the left toggle button
	m_toggleGameInfoLeftBtn = DyCreateButton( { 150, 850 }, { 0, 50 }, "<-",
											  Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	// creating the center button which will act as game / file selector
	m_gameOrEditorBtn = DyCreateButton( { 600, 850 }, { 150, 50 }, m_gameInfoFilePathList.at( 0 ) );

	// creating the right toggle button
	m_toggleGameInfoRightBtn = DyCreateButton( { 150, 850 }, { 750, 50 }, "->",
											   Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	/// @TODO create this as a verticalmenus

	// import games button
	m_importGameBtn = DyCreateButton( { 500, 125 }, { 200, 250 }, "Import Games" );

	// Load Previous Edits button
	m_loadPreviousEditsBtn = DyCreateButton( { 500, 125 }, { 200, 375 }, "Load Previous Edits" );

	// Create New Edit button
	m_createNewEditBtn = DyCreateButton( { 500, 125 }, { 200, 500 }, "Create New Edit" );

	// Cancle button
	m_cancleBtn = DyCreateButton( { 500, 125 }, { 200, 625 }, "Cancle" );

	// Enter File Name textbox
	m_fileNameTxt = DyCreateTextBox( { 500, 100 }, { 200, 250 }, "Enter File Name" );

	// Enter file name feild textbox
	m_enterFileNameFeildTxt = DyCreateTextBox( { 500, 125 }, { 200, 350 }, "", true, "<Enter a File Name>" );
	//m_enterFileNameFeild = new Brood::BroodUI::TextBox;
	//m_enterFileNameFeild->SetBodySize( 500, 125 );
	//m_enterFileNameFeild->SetBodyPosition( 200, 350 );
	//m_enterFileNameFeild->SetFont( m_font );
	//m_enterFileNameFeild->SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	//m_enterFileNameFeild->SetText( "" );
	//m_enterFileNameFeild->SetEditable( true );

	// Create New button
	m_openFileBtn = DyCreateButton( { 500, 125 }, { 200, 475 }, "Create New" );
	//m_openFile = new Brood::BroodUI::Button;
	//m_openFile->SetBodySize( 500, 125 );
	//m_openFile->SetBodyPosition( 200, 475 );
	//m_openFile->SetFont( m_font );
	//m_openFile->SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	//m_openFile->SetText( "Create New" );

	// createing 2 workspace, namely, initialWorkSpace, editorWorSpace,
	m_workSpacesList.push_back( new Brood::Application::EditorWorkspace() );
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
///
void Brood::Application::HomeWorkSpace::UpdateAllDispayElement()
{
	/// TODO fill this
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::HomeWorkSpace::Update()
{
	// check to see if logic of ribbion tab is to executed or not
	UpdateRibbionTabs();

	// chekcking to see which workspace is currently on and 
	// only updating that
	if( m_isHomeWorkspace )
	{
		UpdateHomeWorkspace();
	}
	else
	{
		m_workSpacesList.at( m_currWorkSpaceIdx )->Update();
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::HomeWorkSpace::Draw( sf::RenderWindow& a_window )
{
	// chekcking to see which workspace is currently on and 
		// only drawing that
	if( m_isHomeWorkspace )
	{
		m_toggleGameInfoLeftBtn->Draw( a_window );
		m_gameOrEditorBtn->Draw( a_window );
		m_toggleGameInfoRightBtn->Draw( a_window );

		/// @TODO deleteme 
		if( m_showImportDialogBox )
		{
			m_importGameBtn->Draw( a_window );
			m_loadPreviousEditsBtn->Draw( a_window );
			m_createNewEditBtn->Draw( a_window );
			m_cancleBtn->Draw( a_window );
		}

		if( m_showEnterFilenameDialogBox )
		{
			m_fileNameTxt->Draw( a_window );
			m_enterFileNameFeildTxt->Draw( a_window );
			m_openFileBtn->Draw( a_window );
			m_cancleBtn->Draw( a_window );
		}
	}
	else
	{
		m_workSpacesList.at( m_currWorkSpaceIdx )->Draw( a_window );
	}

	// menu bar
	m_ribbionTabs.Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::HomeWorkSpace::Debugger()
{
	Brood::Application::WorkSpace::Debugger();

	m_ribbionTabs.Debugger();

	for( unsigned idx = 0; idx < m_workSpacesList.size(); ++idx )
	{
		m_workSpacesList.at( idx )->Debugger();
	}

	m_isDebugger = true;
}

/// 
/// @private
/// @brief Initializes the ribbion tab bar which is at the top of the applicaiton
/// 
/// It has the file and help menus in it. 
/// 
/// File menu has Create new, Import games,
///		Load previous edits, and Save option under it.
/// 
/// Help menu has How to Use, Documentation, and About BroodMaker option under it.
/// 
/// 
void Brood::Application::HomeWorkSpace::InitializeRibbionTabs()
{
	m_ribbionTabs.SetBodySize( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width, 50 );
	m_ribbionTabs.SetBodyPosition( 0, 0 );
	m_ribbionTabs.SetFont( &Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_font );
	m_ribbionTabs.SetFontSize( 20 );
	//m_ribbionTabs.SetBodyColor(sf::Color( 118, 134, 144, 255 ));
	m_ribbionTabs.SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_MainMenu );

	m_ribbionTabs.AddMenuToMenuBar( "File" );
	m_ribbionTabs.AddItemToMenu( 0, "Create New" );
	m_ribbionTabs.AddItemToMenu( 0, "Import Game" );
	m_ribbionTabs.AddItemToMenu( 0, "Load Previous Edit" );
	m_ribbionTabs.AddItemToMenu( 0, "Export Edit" );
	m_ribbionTabs.AddItemToMenu( 0, "Save" );
	m_ribbionTabs.AddItemToMenu( 0, "Quit" );

	m_ribbionTabs.AddMenuToMenuBar( "Workspace" );
	m_ribbionTabs.AddItemToMenu( 1, "Home wokspace: ON" );
	m_ribbionTabs.AddItemToMenu( 1, "Editor wokspace: OFF" );
	m_ribbionTabs.AddItemToMenu( 1, "Game wokspace: OFF" );

	m_ribbionTabs.AddMenuToMenuBar( "Debug" );
	m_ribbionTabs.AddItemToMenu( 2, "Toggle Debugger: OFF" );

	m_ribbionTabs.AddMenuToMenuBar( "Help" );
	m_ribbionTabs.AddItemToMenu( 3, "How To Use" );
	m_ribbionTabs.AddItemToMenu( 3, "Documentation" );
	m_ribbionTabs.AddItemToMenu( 3, "About BroodMaker" );
}

/// 
/// @brief Checks to see if the ribbion tabs's logic is to be executed or not 
/// 
void Brood::Application::HomeWorkSpace::UpdateRibbionTabs()
{
	if( !m_ribbionTabs.GetMenuList().empty() )
	{
		std::vector<Brood::BroodUI::DropDownMenu*> menus = m_ribbionTabs.GetMenuList();

		bool executeMenuItem = false;
		unsigned iIdxExecute = 0;
		unsigned jIdxExecute = 0;
		// checking if the logics of the element is to be executed or not
		for( unsigned i = 0; i < menus.size(); ++i )
		{
			if( menus.at( i )->DoElement() )
			{
				/// @todo deleteME
				std::cout << "menu at " << i << " " << menus.at( i )->GetText() << " Pressed" << std::endl;
			}

			// checking if the logics of the element is to be executed or not
			if( menus.at( i )->IsSelected() )
			{
				auto itemList = menus.at( i )->GetItemList();
				if( !itemList.empty() )
				{
					for( unsigned j = 0; j < itemList.size(); ++j )
					{
						if( itemList.at( j )->DoElement() )
						{
							/// @todo deleteme
							std::cout << "menu at " << i << " Pressed" << std::endl;
							std::cout << "item at " << j << " Pressed" << std::endl;

							executeMenuItem = true;
							iIdxExecute = i;
							jIdxExecute = j;
							break;
						}
					}
				}
			}
		}

		/// @brief list of function to execute for each menu item
		if( executeMenuItem )
		{
			ExecuteMenuItem( iIdxExecute, jIdxExecute );
		}
	}
}

/// 
/// @private
/// @brief executes the funciton related to the menu item of the ribbon tabs
/// 
/// It contains all the funciton to execute for each menu item of the ribbon tabs
/// 
/// @param a_iIdx index of menu to execute
/// @param a_jIdx index of menu item to execute for given menu index i
/// 
void Brood::Application::HomeWorkSpace::ExecuteMenuItem( unsigned a_iIdx, unsigned a_jIdx )
{
	switch( a_iIdx )
	{
		case 0:
		{
			// file menu

			switch( a_jIdx )
			{
				case 0:
				{
					// Create New menu item
					break;
				} // j = 0 case when i = 0
				case 1:
				{
					// Import Game menu item
					break;
				} // j = 1 case when i = 0
				case 2:
				{
					// Load Previous Edit menu item
					break;
				} // j = 2 case when i = 0
				case 3:
				{
					// Export edit menu item
					break;
				} // j = 3 case when i = 0
				case 4:
				{
					// Save menu item
					break;
				} // j = 4 case when i = 0
				case 5:
				{
					// Quit menu item
					Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_exit = true;
					break;
				} // j = 4 case when i = 0
				default:
				{
					std::cerr << "menu item at index: " << a_jIdx << "not found for File menu" << std::endl;
					break;
				}
			}

			break;
		} // i = 0 case
		case 1:
		{
			// Workspace menu

			switch( a_jIdx )
			{
				case 0:
				{
					// set homeworkspace as true
					m_isHomeWorkspace = true;

					// updating the items text
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 0 )->SetText( "Home wokspace: ON" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 1 )->SetText( "Editor wokspace : OFF" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 2 )->SetText( "Game wokspace : OFF" );
					break;
				}
				case 1:
				{
					// set homeworkspace as false
					m_isHomeWorkspace = false;

					// 0th idx is for editor workspace
					m_currWorkSpaceIdx = 0;

					// updating the items text
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 0 )->SetText( "Home wokspace: OFF" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 1 )->SetText( "Editor wokspace : ON" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 2 )->SetText( "Game wokspace : OFF" );
					break;
				}
				case 2:
				{
					// set homeworkspace as false
					m_isHomeWorkspace = false;

					// 0th idx is for editor workspace
					// @todo change this to 1 once game editor is ready
					m_currWorkSpaceIdx = 0;

					// updating the items text
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 0 )->SetText( "Home wokspace: OFF" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 1 )->SetText( "Editor wokspace : OFF" );
					m_ribbionTabs.GetMenuList().at( a_iIdx )->GetItemList().at( 2 )->SetText( "Game wokspace : ON" );
					break;
				}

				default:
				{
					std::cerr << "menu item at index: " << a_jIdx << "not found for Workspace menu" << std::endl;
					break;
				}
			}
			break;
		} // i = 1 case
		case 2:
		{
			// debug menu

			switch( a_jIdx )
			{
				case 0:
				{
					// Toggle Debugger menu item
					Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode = !Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode;
					this->Debugger();
					break;
				}
				default:
				{
					std::cerr << "menu item at index: " << a_jIdx << "not found for debug menu" << std::endl;
					break;
				}
			}
			break;
		} // i = 2 case
		case 3:
		{
			// help menu

			switch( a_jIdx )
			{
				case 0:
				{
					// How To Use menu item
					break;
				}
				case 1:
				{
					// Documentation menu item
					break;
				}
				case 2:
				{
					// About BroodMaker menu item
					break;
				}
				default:
				{
					std::cerr << "menu item at index: " << a_jIdx << "not found for help menu" << std::endl;
					break;
				}
			}
			break;
		} // i = 3 case

		default:
		{
			break;
		}
	} // i Index switch
}

/// 
/// @private
/// @brief Holds the logic for the elements in the HomeWorkspace
/// 
void Brood::Application::HomeWorkSpace::UpdateHomeWorkspace()
{
	if( m_showImportDialogBox )
	{
		if( m_importGameBtn->DoElement() )
		{
			m_showImportDialogBox = false;
			m_showEnterFilenameDialogBox = true;
			m_openFileBtn->SetText( "Open Game File" );
		}
		else if( m_loadPreviousEditsBtn->DoElement() )
		{
			m_showImportDialogBox = false;
			m_showEnterFilenameDialogBox = true;
			m_openFileBtn->SetText( "Open Edit File" );
		}
		else if( m_createNewEditBtn->DoElement() )
		{
			m_showImportDialogBox = false;
			/*	m_showEnterFilenameDialogBox = true;
				m_openFileBtn->SetText( "Create Edit" );*/

				// create a new edit

		}
		else if( m_cancleBtn->DoElement() )
		{
			m_showImportDialogBox = false;
		}
	}
	else if( m_showEnterFilenameDialogBox )
	{
		m_enterFileNameFeildTxt->DoElement();

		if( m_enterFileNameFeildTxt->IsEnterPressed() &&
			m_enterFileNameFeildTxt->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() )
		{
			/// @todo deleteme
			std::cerr << "yup" << std::endl;
			std::cerr << m_enterFileNameFeildTxt->GetText() << std::endl;

			// resetting the m_eterPressed
			m_enterFileNameFeildTxt->SetEnterPressedFalse();

		}

		if( m_openFileBtn->DoElement() )
		{
			m_showEnterFilenameDialogBox = false;
			// do the intended thing by checking the 
			// text in m_openFile 

			// also clean the text box
		}
		else if( m_cancleBtn->DoElement() )
		{
			m_showEnterFilenameDialogBox = false;
			// also clean the text box
		}
	}
	else if( m_toggleGameInfoLeftBtn->DoElement() )
	{
		if( m_currGameInfoIdx == 0 )
		{
			m_currGameInfoIdx = m_gameInfoFilePathList.size() - 1;
		}
		else
		{
			--m_currGameInfoIdx;
		}
	}
	else if( m_toggleGameInfoRightBtn->DoElement() )
	{
		if( m_currGameInfoIdx == m_gameInfoFilePathList.size() - 1 )
		{
			m_currGameInfoIdx = 0;
		}
		else
		{
			++m_currGameInfoIdx;
		}
	}
	else if( m_gameOrEditorBtn->DoElement() )
	{
		// execute the item at the index
		if( m_currGameInfoIdx == 1 )
		{
			m_showImportDialogBox = true;
		}
		else if( m_currGameInfoIdx == 0 )
		{
			Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_exit = true;
		}
	}

	if( !Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode )
	{
		m_gameOrEditorBtn->SetText( m_gameInfoFilePathList.at( m_currGameInfoIdx ) );
	}
}


// ======================================================================
// ================= end of InitialWorkSpace class ======================
// ======================================================================