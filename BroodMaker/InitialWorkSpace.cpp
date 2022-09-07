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

#include "stdafx.h"
#include "InitialWorkSpace.h"

#include <filesystem> /// @TODO delete me

/// 
/// @public
/// @brief default constructor
/// 
Brood::Application::InitialWorkSpace::InitialWorkSpace():
	WorkSpace(), m_gameOrEditor(nullptr), m_toggleGameInfoLeft(nullptr),
	m_toggleGameInfoRight(nullptr), m_currGameInfoIdx( 1 ),
	m_showImportDialogBox(false), m_importGame(nullptr),
	m_loadPreviousEdits( nullptr ), m_createNewEdit( nullptr ),
	m_cancle(nullptr), m_showEnterFilenameDialogBox( false ),
	m_fileName( nullptr ), m_enterFileNameFeild( nullptr ),
	m_openFile( nullptr )
{
	m_gameInfoFilePathList.push_back( "Exit" );
	m_gameInfoFilePathList.push_back( "Add Game" );

	/// @TODO load the game info file path
	/// @TODO add the create games and exit to the file path
	/// @TODO load the game texture
	


	InitializeWorkSpace();
}

/// 
/// @public
/// @virtual
/// @brief default destructor
//
Brood::Application::InitialWorkSpace::~InitialWorkSpace()
{
	// deallocating dynamically allocated uielements
	auto uiListPtr = m_allUIList.begin();

	while( uiListPtr != m_allUIList.end() )
	{
		delete ( *uiListPtr );
		++uiListPtr;
	}
}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace
//
void Brood::Application::InitialWorkSpace::InitializeWorkSpace()
{
	/// @TODO: delete me
	const std::string cwd = std::filesystem::current_path().string();
	std::string fileName = cwd;

	// loading font
	std::string fontFileLoc = cwd + "\\Assets\\Fonts\\arial.ttf";
	if( !( m_font.loadFromFile( fontFileLoc ) ) )
	{
		std::cerr << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}

	// creating the left toggle button
	m_toggleGameInfoLeft = DyCreateButton( { 150, 850 }, { 0, 50 }, "<-",
										   Brood::ST_ColorVariables::stm_AppSecondaryColor );

	// creating the center button which will act as game / file selector
	m_gameOrEditor = DyCreateButton( { 600, 850 }, { 150, 50 }, m_gameInfoFilePathList.at( 0 ) );

	//m_gameOrEditor = new Brood::BroodUI::Button;
	//m_gameOrEditor->SetBodySize( 600, 850 );
	//m_gameOrEditor->SetBodyPosition( 150, 50 );
	//m_gameOrEditor->SetFont( m_font );
	//m_gameOrEditor->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_gameOrEditor->SetText( m_gameInfoFilePathList.at(0) );
	//m_allUIList.push_back( m_toggleGameInfoLeft );

	// creating the right toggle button
	m_toggleGameInfoRight = DyCreateButton( { 150, 850 }, { 750, 50 }, "->",
											Brood::ST_ColorVariables::stm_AppSecondaryColor );
	//m_toggleGameInfoRight = new Brood::BroodUI::Button;
	//m_toggleGameInfoRight->SetBodySize( 150, 850 );
	//m_toggleGameInfoRight->SetBodyPosition( 750, 50 );
	//m_toggleGameInfoRight->SetFont( m_font );
	//m_toggleGameInfoRight->SetBodyColor( Brood::ST_ColorVariables::stm_AppSecondaryColor );
	//m_toggleGameInfoRight->SetText( "->" );

	/// @TODO create this as a verticalmenus
	m_importGame = DyCreateButton( { 500, 125 }, { 200, 250 },  "Import Games" );
	//m_importGame = new Brood::BroodUI::Button;
	//m_importGame->SetBodySize( 500, 125 );
	//m_importGame->SetBodyPosition( 200, 250 );
	//m_importGame->SetFont( m_font );
	//m_importGame->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_importGame->SetText( "Import Games" );

	m_loadPreviousEdits = DyCreateButton( { 500, 125 }, { 200, 375 }, "Load Previous Edits" );
	//m_loadPreviousEdits = new Brood::BroodUI::Button;
	//m_loadPreviousEdits->SetBodySize( 500, 125 );
	//m_loadPreviousEdits->SetBodyPosition( 200, 375 );
	//m_loadPreviousEdits->SetFont( m_font );
	//m_loadPreviousEdits->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_loadPreviousEdits->SetText( "Load Previous Edits" );

	m_createNewEdit = DyCreateButton( { 500, 125 }, { 200, 500 }, "Create New Edit" );
	//m_createNewEdit = new Brood::BroodUI::Button;
	//m_createNewEdit->SetBodySize( 500, 125 );
	//m_createNewEdit->SetBodyPosition( 200, 500 );
	//m_createNewEdit->SetFont( m_font );
	//m_createNewEdit->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_createNewEdit->SetText( "Create New Edit" );

	m_cancle = DyCreateButton( { 500, 125 }, { 200, 625 }, "Cancle" );
	//m_cancle = new Brood::BroodUI::Button;
	//m_cancle->SetBodySize( 500, 125 );
	//m_cancle->SetBodyPosition( 200, 625 );
	//m_cancle->SetFont( m_font );
	//m_cancle->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_cancle->SetText( "Cancle" );

	m_fileName = DyCreateTextBox( { 500, 100 }, { 200, 250 }, "Enter File Name" );
	//m_fileName = new Brood::BroodUI::TextBox;
	//m_fileName->SetBodySize( 500, 100 );
	//m_fileName->SetBodyPosition( 200, 250 );
	//m_fileName->SetFont( m_font );
	//m_fileName->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_fileName->SetText( "Enter File Name" );

	m_enterFileNameFeild = DyCreateTextBox( { 500, 125 }, { 200, 350 }, "", true );
	//m_enterFileNameFeild = new Brood::BroodUI::TextBox;
	//m_enterFileNameFeild->SetBodySize( 500, 125 );
	//m_enterFileNameFeild->SetBodyPosition( 200, 350 );
	//m_enterFileNameFeild->SetFont( m_font );
	//m_enterFileNameFeild->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_enterFileNameFeild->SetText( "" );
	//m_enterFileNameFeild->SetEditable( true );

	m_openFile = DyCreateButton( { 500, 125 }, { 200, 475 }, "Create New" );
	//m_openFile = new Brood::BroodUI::Button;
	//m_openFile->SetBodySize( 500, 125 );
	//m_openFile->SetBodyPosition( 200, 475 );
	//m_openFile->SetFont( m_font );
	//m_openFile->SetBodyColor( Brood::ST_ColorVariables::stm_AppPrimaryColor );
	//m_openFile->SetText( "Create New" );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::InitialWorkSpace::Update()
{
	if( m_showImportDialogBox )
	{
		if( m_importGame->DoElement() )
		{
			m_showImportDialogBox = false;
			m_showEnterFilenameDialogBox = true;
			m_openFile->SetText( "Open Game File" );
		}
		else if(m_loadPreviousEdits->DoElement())
		{
			m_showImportDialogBox = false;
			m_showEnterFilenameDialogBox = true;
			m_openFile->SetText( "Open Edit File" );
		}
		else if( m_createNewEdit->DoElement() )
		{
			m_showImportDialogBox = false;
			m_showEnterFilenameDialogBox = true;
			m_openFile->SetText( "Create Edit" );
			// create a new edit
		}
		else if( m_cancle->DoElement() )
		{
			m_showImportDialogBox = false;
		}
	}
	else if( m_showEnterFilenameDialogBox )
	{
		m_enterFileNameFeild->DoElement();

		if( m_openFile->DoElement() )
		{
			m_showEnterFilenameDialogBox = false;
			// do the intended thing by checking the 
			// text in m_openFile 

			// also clean the text box
		}
		else if( m_cancle->DoElement() )
		{
			m_showEnterFilenameDialogBox = false;
			// also clean the text box
		}
	}
	else if( m_toggleGameInfoLeft->DoElement() )
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
	else if ( m_toggleGameInfoRight->DoElement() )
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
	else if( m_gameOrEditor->DoElement() )
	{
		// execute the item at the index
		if( m_currGameInfoIdx == 1 )
		{
			m_showImportDialogBox = true;
		}
		else if( m_currGameInfoIdx == 0 )
		{
			Brood::ST_GlobalCoreVariables::stm_exit = true;
		}
	}
	
	/// @TODO delete me this should be texture
	if( !Brood::ST_GlobalCoreVariables::stm_is_debug_mode )
	{
		m_gameOrEditor->SetText( m_gameInfoFilePathList.at( m_currGameInfoIdx ));
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::InitialWorkSpace::Draw( sf::RenderWindow& a_window )
{
	m_toggleGameInfoLeft->Draw( a_window );
	m_gameOrEditor->Draw( a_window );
	m_toggleGameInfoRight->Draw( a_window );

	/// @TODO deleteme 
	if( m_showImportDialogBox )
	{
		m_importGame->Draw( a_window );
		m_loadPreviousEdits->Draw( a_window );
		m_createNewEdit->Draw( a_window );
		m_cancle->Draw( a_window );
	}

	if( m_showEnterFilenameDialogBox )
	{
		m_fileName->Draw( a_window );
		m_enterFileNameFeild->Draw( a_window );
		m_openFile->Draw( a_window );
		m_cancle->Draw( a_window );
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// This function helps in debugging the UI elements. Called once at the 
///		end of Inialization.
///
void Brood::Application::InitialWorkSpace::Debugger()
{
	auto uiListPtr = m_allUIList.begin();

	while( uiListPtr != m_allUIList.end() )
	{
		( *uiListPtr )->Debugger();
		++uiListPtr;
	}

	m_isDebugger = true;
}
