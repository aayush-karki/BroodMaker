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
	m_toggleGameInfoRight(nullptr), m_currGameInfoIdx( 0 ),
	m_importGame(nullptr), m_loadPreviousEdits( nullptr ), 
	m_createNewEdit( nullptr ), m_showImportDialogBox(false),
	m_fileName( nullptr ), m_enterFileNameFeild( nullptr ),
	m_openFile( nullptr ), m_cancleSmall( nullptr ),
	m_showEnterFilenameDialogBox(false)
	
{
	/// @TODO load the game info file path
	/// @TODO add the create games and exit to the file path
	/// @TODO load the game texture
	
	/// @TODO Delete Me 
	m_gameInfoFilePathList.push_back( "Add Game" );
	m_gameInfoFilePathList.push_back( "Create Game" );
	m_gameInfoFilePathList.push_back( "Exit" );

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
	delete m_gameOrEditor;
	delete m_toggleGameInfoLeft;
	delete m_toggleGameInfoRight;
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
		std::cout << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}

	// creating the left toggle button
	m_toggleGameInfoLeft = new Brood::BroodUI::Button;
	m_toggleGameInfoLeft->SetBodySize( 150, 850 );
	m_toggleGameInfoLeft->SetBodyPosition( 0, 50 );
	m_toggleGameInfoLeft->SetFont( m_font );
	m_toggleGameInfoLeft->SetBodyColor( sf::Color( 108, 207, 209, 255 ) );
	m_toggleGameInfoLeft->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_toggleGameInfoLeft->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_toggleGameInfoLeft->SetText( "<-" );

	// creating the center button which will act as game / file selector
	m_gameOrEditor = new Brood::BroodUI::Button;
	m_gameOrEditor->SetBodySize( 600, 850 );
	m_gameOrEditor->SetBodyPosition( 150, 50 );
	m_gameOrEditor->SetFont( m_font );
	m_gameOrEditor->SetBodyColor( sf::Color( 232, 157, 198, 255 ) );
	m_gameOrEditor->SetHotOverlayColor( sf::Color( 191, 130, 163, 255 ) );
	m_gameOrEditor->SetActiveOverlayColor( sf::Color( 191, 130, 133, 255 ) );
	m_gameOrEditor->SetText( m_gameInfoFilePathList.at(0) );

	// creating the right toggle button
	m_toggleGameInfoRight = new Brood::BroodUI::Button;
	m_toggleGameInfoRight->SetBodySize( 150, 850 );
	m_toggleGameInfoRight->SetBodyPosition( 750, 50 );
	m_toggleGameInfoRight->SetFont( m_font );
	m_toggleGameInfoRight->SetBodyColor( sf::Color( 108, 207, 209, 255 ) );
	m_toggleGameInfoRight->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_toggleGameInfoRight->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_toggleGameInfoRight->SetText( "->" );

	/// @TODO create this as a verticalmenus
	m_importGame = new Brood::BroodUI::Button;
	m_importGame->SetBodySize( 500, 125 );
	m_importGame->SetBodyPosition( 200, 250 );
	m_importGame->SetFont( m_font );
	m_importGame->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_importGame->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_importGame->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_importGame->SetText( "Import Games" );

	m_loadPreviousEdits = new Brood::BroodUI::Button;
	m_loadPreviousEdits->SetBodySize( 500, 125 );
	m_loadPreviousEdits->SetBodyPosition( 200, 375 );
	m_loadPreviousEdits->SetFont( m_font );
	m_loadPreviousEdits->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_loadPreviousEdits->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_loadPreviousEdits->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_loadPreviousEdits->SetText( "Load Previous Edits" );

	m_createNewEdit = new Brood::BroodUI::Button;
	m_createNewEdit->SetBodySize( 500, 125 );
	m_createNewEdit->SetBodyPosition( 200, 500 );
	m_createNewEdit->SetFont( m_font );
	m_createNewEdit->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_createNewEdit->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_createNewEdit->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_createNewEdit->SetText( "Create New Edit" );

	m_cancle = new Brood::BroodUI::Button;
	m_cancle->SetBodySize( 500, 125 );
	m_cancle->SetBodyPosition( 200, 625 );
	m_cancle->SetFont( m_font );
	m_cancle->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_cancle->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_cancle->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_cancle->SetText( "Cancle" );

	m_fileName = new Brood::BroodUI::TextBox;
	m_fileName->SetBodySize( 500, 100 );
	m_fileName->SetBodyPosition( 200, 250 );
	m_fileName->SetFont( m_font );
	m_fileName->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_fileName->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_fileName->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_fileName->SetText( "Enter File Name" );

	m_enterFileNameFeild = new Brood::BroodUI::TextBox;
	m_enterFileNameFeild->SetBodySize( 500, 125 );
	m_enterFileNameFeild->SetBodyPosition( 200, 350 );
	m_enterFileNameFeild->SetFont( m_font );
	m_enterFileNameFeild->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_enterFileNameFeild->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_enterFileNameFeild->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_enterFileNameFeild->SetText( "" );
	m_enterFileNameFeild->SetEditable( true );

	m_openFile = new Brood::BroodUI::Button;
	m_openFile->SetBodySize( 500, 125 );
	m_openFile->SetBodyPosition( 200, 475 );
	m_openFile->SetFont( m_font );
	m_openFile->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_openFile->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_openFile->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_openFile->SetText( "Create New" );

	m_cancleSmall = new Brood::BroodUI::Button;
	m_cancleSmall->SetBodySize( 500, 125 );
	m_cancleSmall->SetBodyPosition( 200, 600 );
	m_cancleSmall->SetFont( m_font );
	m_cancleSmall->SetBodyColor( sf::Color( 57, 229, 220, 255 ) );
	m_cancleSmall->SetHotOverlayColor( sf::Color( 83, 156, 158, 255 ) );
	m_cancleSmall->SetActiveOverlayColor( sf::Color( 83, 158, 122, 255 ) );
	m_cancleSmall->SetText( "Cancle" );
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
		if( m_currGameInfoIdx == 0 )
		{
			m_showImportDialogBox = true;
		}
	}
	
	/// @TODO delete me this should be texture
	m_gameOrEditor->SetText( m_gameInfoFilePathList.at( m_currGameInfoIdx ));
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
		m_cancleSmall->Draw( a_window );
	}

}
