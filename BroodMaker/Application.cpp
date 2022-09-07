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

#include "stdafx.h"
#include "Application.h"

/// 
/// @brief default constructor
///	
/// Inializes the application and sets it up
/// 
Brood::Application::Application::Application():
	m_window( sf::VideoMode( Brood::ST_GlobalCoreVariables::stm_window_height, 
							 Brood::ST_GlobalCoreVariables::stm_window_width ),
			  "BroodMaker" ), m_initailWorkSpace(), m_events()
{
	// initializing the randon seed
	std::srand( ( unsigned int )std::time( nullptr ) );

	// initializing the mouse cursor
	Brood::MouseHandler::InitializeCursor( m_window );

	// loading font
	std::string fontFileLoc = Brood::ST_GlobalCoreVariables::stm_cwd + "\\Assets\\Fonts\\arial.ttf";
	if( !( m_font.loadFromFile( fontFileLoc ) ) )
	{
		std::cerr << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}

	// initializing menubar
	InitializeMenuBar();

	/// todo: delete me
	// create a board

	std::string fileName = Brood::ST_GlobalCoreVariables::stm_cwd;
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
	//myButton.SetFontColor( Brood::ST_ColorVariables::stm_Black );
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
	///*mySpriteButton.GetSpriteBody().SetSpriteLength( 50 );
	//mySpriteButton.GetSpriteBody().SetSpriteHeight( 50 );*/
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
	///*myMenu.SetBodySize( 150, 50 );
	//myMenu.SetBodyPosition( 430, 0 );
	//myMenu.SetFont( &m_font );
	//myMenu.SetFontSize( 20 );
	//myMenu.SetBodyColor( sf::Color::Magenta );*/
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

	//Debugger();
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
	/// @todo deleteme
	//Debugger();

	//app loop
	while( !Brood::ST_GlobalCoreVariables::stm_exit )
	{
		// polling for any events
		Brood::Application::Application::PollEvents();

		// ========================== logics ================================

		// ==== at the start of a frame ====
		// clearing the hotelement flag
		Brood::BroodUI::ElementSelection::SetHotElementIdPtrFlag( false );
		// updateing the mouse
		Brood::MouseHandler::UpdateMousePos( m_window );
		Brood::MouseHandler::UpdateMouseButtonStatus();

		// checking if debugger is turned on
		if( Brood::ST_GlobalCoreVariables::stm_is_debug_mode )
		{
			Brood::BroodUI::ElementSelection::Debugger();
		}

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

		if( !m_menuBar.GetMenuList().empty() )
		{
			auto menus = m_menuBar.GetMenuList();

			bool executeMenuItem = false;
			unsigned iIdxExecute = 0;
			unsigned jIdxExecute = 0;
			// checking if the logics of the element is to be executed or not
			for( unsigned i = 0 ; i < menus.size(); ++i )
			{
				if( menus.at( i )->DoElement() )
				{
					/// @todo deleteME
					std::cout << "menu at " << i << " " << menus.at(i)->GetText() << " Pressed" << std::endl;
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
				ExecuteMenuItem(iIdxExecute, jIdxExecute);
			}

		}

		m_initailWorkSpace.Update();


		// rendering 
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
				Brood::ST_GlobalCoreVariables::stm_exit = true;
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
///		right to left. @see UIElement class for more explation.
///
void Brood::Application::Application::Draw()
{
	m_window.clear();

	//myBoard->Draw( m_window );
	//myCard->Draw( m_window );

	//// menus
	//myButton.Draw( m_window );
	//mySpriteButton.Draw( m_window );
	//myDropDown.Draw( m_window );
	//myDropDownInput.Draw( m_window );
	//myTextBox.Draw( m_window );

	// workspace
	m_initailWorkSpace.Draw( m_window );

	// menu bar
	m_menuBar.Draw( m_window );
	//myMenu.Draw( m_window );

	// displaying te window
	m_window.display();
}


/// 
/// @private
/// @brief Initializes the main menu bar which is at the top of the applicaiton
/// 
/// It has the file and help menus in it. 
/// 
/// File menu has Create new, Import games,
///		Load previous edits, and Save option under it.
/// 
/// Help menu has How to Use, Documentation, and About BroodMaker option under it.
/// 
/// 
void Brood::Application::Application::InitializeMenuBar()
{
	m_menuBar.SetBodySize( Brood::ST_GlobalCoreVariables::stm_window_width, 50 );
	m_menuBar.SetBodyPosition( 0, 0 );
	m_menuBar.SetFont( &m_font );
	m_menuBar.SetFontSize( 20 );
	//m_menuBar.SetBodyColor(sf::Color( 118, 134, 144, 255 ));
	m_menuBar.SetBodyColor(Brood::ST_ColorVariables::stm_MainMenu);

	m_menuBar.AddMenuToMenuBar( "File" );
	m_menuBar.AddItemToMenu( 0, "Create New" );
	m_menuBar.AddItemToMenu( 0, "Import Game" );
	m_menuBar.AddItemToMenu( 0, "Load Previous Edit" );
	m_menuBar.AddItemToMenu( 0, "Save" );
	m_menuBar.AddItemToMenu( 0, "Quit" );

	m_menuBar.AddMenuToMenuBar( "Debug" );
	m_menuBar.AddItemToMenu( 1, "Toggle Debugger: OFF" );

	m_menuBar.AddMenuToMenuBar( "Help" );
	m_menuBar.AddItemToMenu( 2, "How To Use" );
	m_menuBar.AddItemToMenu( 2, "Documentation" );
	m_menuBar.AddItemToMenu( 2, "About BroodMaker" );

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
	m_menuBar.Debugger();
	m_initailWorkSpace.Debugger();
}

/// 
/// @private
/// @brief executes the funciton related to the menu item.
/// 
/// It contains all the funciton to execute for each menu item.
/// 
/// @param a_iIdx index of menu to execute
/// @param a_jIdx index of menu item to execute for given menu index i
/// 
void Brood::Application::Application::ExecuteMenuItem( unsigned a_iIdx, unsigned a_jIdx )
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
					// Save menu item
					break;
				} // j = 3 case when i = 0
				case 4:
				{
					// Quit menu item
					Brood::ST_GlobalCoreVariables::stm_exit = true;
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
			// debug menu
			switch( a_jIdx )
			{
				case 0:
				{
					// Toggle Debugger menu item
					Brood::ST_GlobalCoreVariables::stm_is_debug_mode = !Brood::ST_GlobalCoreVariables::stm_is_debug_mode;
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
		} // i = 1 case
		case 2:
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
		} // i = 2 case

		default:
		{
			break;
		}
	} // i Index switch

}
