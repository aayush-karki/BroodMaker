/*************************************************************************/
/// 
/// @file Application.cpp 
/// 
/// @brief  This file is a source file for Application class.
/// 
/// It contains all of the defination of the member 
///		funciton of Application class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Application.h"

// ======================================================================
// ================= start of Application class =========================
// ======================================================================

/// 
/// @brief default constructor
///	
/// Inializes the application and sets it up
/// 
Brood::Application::Application::Application() :
	m_window( sf::VideoMode( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height,
							 Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width ),
			  "BroodMaker" ), m_events(), m_mainWorkspace()
{
	// initializing the randon seed
	std::srand( ( unsigned int )std::time( nullptr ) );

	// initializing the mouse cursor
	Brood::MouseHandler::InitializeCursor( m_window );

	m_window.setFramerateLimit( 60 );

	/// @todo: delete me
	// initializing the board
	myBoard.InitializeBoard( 5, 5, 520.f, 600.f, 100.f, 100.f );
	myBoard.SetBoardSize( { 200,200 } );
	myBoard.SetBoardPos( { 300,200 } );

	// initializing the dice
	myDice.SetBodySize( 50, 50 );
	myDice.SetBodyPosition( 50, 50 );


	/// @todo delete me
	/*
	std::string fileName = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_cwd;
	fileName += "\\Assets\\DiceTexture\\dice_";
	fileName += std::to_string( 0 + 1 );
	fileName += "_50_50.png";

	//diceParam = new Brood::St_DiceParam( fileName, 50.f, 1 );
	//boardParam = new St_BoardParam( 10, 10, 520.f, 520.f, 100.f, 100.f );
	//myBoard = new Board( boardParam, diceParam );

	//// create a player
	////Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
	//myBoard->AddPlayer( 25.f, 25.f );

	//myCard = new Card( m_font, 300, 300, "5+3", "8", 3, 2, 1 );

	//// button with text
	//myButton.SetBodySize( 100, 50 );
	//myButton.SetBodyPosition( 55, 0 );
	//myButton.SetFont( m_font );
	//myButton.SetFontSize( 20 );
	//myButton.SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_Black );
	//myButton.SetBodyColor( sf::Color::Red );
	//myButton.SetText( "My button" );

	//// button with sprite
	//mySpriteButton.SetBodySize( 50, 50 );
	//mySpriteButton.SetBodyPosition( 55, 100 );
	//mySpriteButton.SetFont( m_font );
	//mySpriteButton.SetFontSize( 20 );
	//mySpriteButton.SetFontColor( sf::Color::Black );
	//mySpriteButton.SetBodyColor( sf::Color::Red );
	//// setting sprite height and length
	////mySpriteButton.GetSpriteBody().SetSpriteLength( 50 );
	////mySpriteButton.GetSpriteBody().SetSpriteHeight( 50 );
	//// loading the texture
	//mySpriteButton.GetSpriteBody().SetTextureFromFilePath( fileName );
	//mySpriteButton.GetSpriteBody().SetSpriteFromTexture( 0 );

	//myTextBox.SetBodySize( 100, 50 );
	//myTextBox.SetBodyPosition( 160, 0 );
	//myTextBox.SetBodyColor( sf::Color::White );
	//myTextBox.SetFont( m_font );
	//myTextBox.SetFontColor( sf::Color::Black );
	//myTextBox.SetFontSize( 20 );
	//myTextBox.SetText( "hell" );
	//myTextBox.SetEditable( true );
	//myTextBox.SetLimit( true, 4 );

	//// making a dropdownmenu
	//myDropDown.SetBodySize( 150, 50 );
	//myDropDown.SetBodyPosition( 265, 0 );
	//myDropDown.SetFont( &m_font );
	//myDropDown.SetFontSize( 20 );
	//myDropDown.SetBodyColor( sf::Color::Green );
	//myDropDown.SetText( "MY DDM");

	//myDropDown.AddItemToMenu( "1st item" );
	//myDropDown.AddItemToMenu( "2st item" );

	//// making a dropdownItem
	//myDropDownInput.SetBodySize( 150, 50 );
	//myDropDownInput.SetBodyPosition( 265, 120 );
	//myDropDownInput.SetFont( &m_font );
	//myDropDownInput.SetFontSize( 20 );
	//myDropDownInput.SetBodyColor( sf::Color::Green );
	//myDropDownInput.SetText( "MyDDM" );

	//myDropDownInput.AddItemToMenu( "1st item" );
	//myDropDownInput.AddItemToMenu( "2st item" );
	//myDropDownInput.AddItemToMenu( "longest of all item" );

	//// making a menubar
	////myMenu.SetBodySize( 150, 50 );
	////myMenu.SetBodyPosition( 430, 0 );
	////myMenu.SetFont( &m_font );
	////myMenu.SetFontSize( 20 );
	////myMenu.SetBodyColor( sf::Color::Magenta );
	//myMenu.SetBodySize( m_WINDOW_WIDTH, 50 );
	//myMenu.SetBodyPosition( 0, 0 );
	//myMenu.SetFont( &m_font );
	//myMenu.SetFontSize( 20 );
	//myMenu.SetBodyColor( sf::Color( 54, 59, 69 ) );

	//myMenu.AddMenuToMenuBar( "File" );
	//myMenu.AddMenuToMenuBar( "Help" );

	//myMenu.AddItemToMenu( 0, "Create New" );
	//myMenu.AddItemToMenu( 0, "Import Game" );
	//myMenu.AddItemToMenu( 0, "Load Previous Edit" );
	//myMenu.AddItemToMenu( 0, "Save" );

	//myMenu.AddItemToMenu( 1, "How To Use" );
	//myMenu.AddItemToMenu( 1, "Documentation" );
	//myMenu.AddItemToMenu( 1, "About BroodMaker" );

	Debugger();
	*/

}

/// 
/// @brief default destructor
///	
/// cleans up after the applicaiton
/// 
Brood::Application::Application::~Application()
{
	// cleaning the application

	// closing the window
	m_window.close();
}

///
/// @brief Contains the main loop for the applicaiton
/// 
void Brood::Application::Application::RunApplicaiton()
{
	// ========= main app loop ==============================================
	while( !Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_exit )
	{
		// ========= polling for any events =================================
		// polling for any events
		Brood::Application::Application::PollEvents();

		// ========= logics =================================================

		// ==== at the start of a frame ====
		// clearing the hotelement flag
		Brood::BroodUI::ElementSelection::SetHotElementIdPtrFlag( false );
		// updateing the mouse
		Brood::MouseHandler::UpdateMousePos( m_window );
		Brood::MouseHandler::UpdateMouseButtonStatus();

		// checking if debugger is turned on
		if( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode )
		{
			std::cout << "\x1B[2J\x1B[H";
			Brood::MouseHandler::Debugger();
			Brood::BroodUI::ElementSelection::Debugger();
		}

		/// @todo delete me
		/*
		// myBoard->Update();

		//if( myButton.DoElement() )
		//{
		//	std::cout << "button Pressed" << std::endl;
		//}

		//myTextBox.DoElement();

		//if( myDropDown.DoElement() )
		//{
		//	std::cout << "myDropDown Pressed" << std::endl;
		//}
		//if( myDropDown.IsSelected() )
		//{
		//	auto itemList = myDropDown.GetItemList();
		//	// draw its items
		//	// positining the itemes
		//	if( !itemList.empty() )
		//	{
		//		// checking if the logics of the items is to be executed or not
		//		for( int i = 0; i < itemList.size(); ++i )
		//		{
		//			if( itemList.at( i )->DoElement() )
		//			{
		//				std::cerr << "item at " << i << " Pressed with ID"<<
		//					itemList.at( i )->GetText() <<	std::endl;

		//			}
		//		}
		//	}
		//}

		//if(myDropDownInput.DoElement())
		//{
		//	std::cout << "myDropDownInput Pressed" << std::endl;
		//}
		//if( myDropDownInput.IsSelected() )
		//{
		//	auto itemList = myDropDownInput.GetItemList();
		//	if( !itemList.empty() )
		//	{
		//		// checking if the logics of the items is to be executed or not
		//		for( int i = 0; i < itemList.size(); ++i )
		//		{
		//			if( itemList.at( i )->DoElement() )
		//			{
		//				// setting the elements name as the item's name
		//				myDropDownInput.SetText( itemList.at( i )->GetText() );
		//
		//				// executing the function
		//				std::cerr << "item at " << i << "  Pressed with ID " <<
		//					itemList.at( i )->GetText() << std::endl;


		//			}
		//		}
		//	}
		//}

		//if( !myMenu.GetMenuList().empty() )
		//{
		//	auto menus = myMenu.GetMenuList();

		//	for( int i = 0; i < menus.size(); ++i )
		//	{
		//		if( menus.at( i )->DoElement() )
		//		{
		//			std::cout << "menu at " << i << " Pressed" << std::endl;
		//		}
		//		// checking if the logics of the element is to be executed or not
		//		if( menus.at( i )->IsSelected() )
		//		{
		//			auto itemList = menus.at( i )->GetItemList();
		//			if( !itemList.empty() )
		//			{
		//				for( int j = 0; j < itemList.size(); ++j )
		//				{
		//					if( itemList.at( j )->DoElement() )
		//					{
		//						std::cout << "menu at " << i << " Pressed" << std::endl;
		//						std::cout << "item at " << j << " Pressed" << std::endl;
		//					}
		//				}
		//			}
		//		}
		//	}
		//}
		*/

		// updating the initialworkspace
		m_mainWorkspace.Update();

		// ========= rendering ==============================================
		Brood::Application::Application::Draw();
	}
}

/// 
/// @protecteed
/// @brief This function polls the event object for any event
///
void Brood::Application::Application::PollEvents()
{
	// event polling
	while( m_window.pollEvent( m_events ) )
	{
		switch( m_events.type )
		{
			case sf::Event::Closed:
			{
				Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_exit = true;
				break;
			}
			case sf::Event::TextEntered:
			{
				if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() == nullptr )
				{
					break;
				}

				// checking if the current active element is a editable textbox
				int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr()->GetElementID();
				Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
				if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_textBox )
				{
					// checking if it is editable or not
					Brood::BroodUI::TextBox* currActiveTextBox = ( Brood::BroodUI::TextBox* )currActiveElement;
					if( currActiveTextBox->IsEditable() )
					{
						// if yes then sent the textEntered event to the element
						currActiveTextBox->TypeOn( m_events );
					}
				}
				break;
			}
		}
	}
}

/// 
/// @protecteed
/// @brief Draws object to screen. 
/// 
/// @note the elements should be drawn form bottom to top, 
///		right to left. @see Brood::BroodUI::UIElement class 
///		for more explation.
///
void Brood::Application::Application::Draw()
{
	// setting the window background color after clearing the screen
	m_window.clear( sf::Color( 49, 49, 49 ) );


	/// @todo delete me
	/*
	//myBoard->Draw( m_window );
	//myCard->Draw( m_window );

	//// menus
	//myButton.Draw( m_window );
	//mySpriteButton.Draw( m_window );
	//myDropDown.Draw( m_window );
	//myDropDownInput.Draw( m_window );
	//myTextBox.Draw( m_window );
	//myMenu.Draw( m_window );
	*/

	// workspace
	m_mainWorkspace.Draw( m_window );

	/// @todo delete me
	//myBoard.Draw( m_window );
	//myDice.Draw( m_window );

	// displaying te window
	m_window.display();
}

/// 
/// @private
/// @brief changes the text of the element to its the element ID
///		
/// This function helps in debugging the UI elements. Called once at the 
///		end of Inialization.
/// 
void Brood::Application::Application::Debugger()
{
	m_mainWorkspace.Debugger();
}

// ======================================================================
// ================= end of Applicaiton class ===========================
// ======================================================================