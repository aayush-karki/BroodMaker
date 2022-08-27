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
	m_window( sf::VideoMode( m_WINDOW_WIDTH, m_WINDOW_HEIGHT ), "BroodMaker" ),
	m_initailWorkSpace(), m_events()
{
	// initializing the randon seed
	std::srand( ( unsigned int )std::time( nullptr ) );

	m_exit = false;

	// initializing the mouse cursor
	Brood::MouseHandler::InitializeCursor( m_window );

	/// todo: delete me
	// create a board

	std::string fileName = m_cwd;
	fileName += "\\Assets\\DiceTexture\\dice_";
	fileName += std::to_string( 0 + 1 );
	fileName += "_50_50.png";

	diceParam = new Brood::St_DiceParam( fileName, 50.f, 1 );
	boardParam = new St_BoardParam( 10, 10, 520.f, 520.f, 100.f, 100.f );
	myBoard = new Board( boardParam, diceParam );

	// create a player
	//Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
	myBoard->AddPlayer( 25.f, 25.f );

	// loading font
	std::string fontFileLoc = m_cwd + "\\Assets\\Fonts\\arial.ttf";
	if( !( m_font.loadFromFile( fontFileLoc ) ) )
	{
		std::cerr << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}
	myCard = new Card( m_font, 300, 300, "5+3", "8", 3, 2, 1 );

	// button with text
	myButton.SetBodySize( 100, 50 );
	myButton.SetBodyPosition( 55, 0 );
	myButton.SetFont( m_font );
	myButton.SetFontSize( 20 );
	myButton.SetFontColor( sf::Color::Black );
	myButton.SetBodyColor( sf::Color::Red );
	myButton.SetText( std::to_string(myButton.GetElementIdPtr()->GetElementID()) );

	// button with sprite
	mySpriteButton.SetBodySize( 50, 50 );
	mySpriteButton.SetBodyPosition( 55, 100 );
	mySpriteButton.SetFont( m_font );
	mySpriteButton.SetFontSize( 20 );
	mySpriteButton.SetFontColor( sf::Color::Black );
	mySpriteButton.SetBodyColor( sf::Color::Red );
	// setting sprite height and length 
	/*mySpriteButton.GetSpriteBody().SetSpriteLength( 50 );
	mySpriteButton.GetSpriteBody().SetSpriteHeight( 50 );*/
	// loading the texture
	mySpriteButton.GetSpriteBody().SetTextureFromFilePath( fileName );
	mySpriteButton.GetSpriteBody().SetSpriteFromTexture( 0 );

	myTextBox.SetBodySize( 100, 50 );
	myTextBox.SetBodyPosition( 160, 0 );
	myTextBox.SetBodyColor( sf::Color::White );
	myTextBox.SetFont( m_font );
	myTextBox.SetFontColor( sf::Color::Black );
	myTextBox.SetFontSize( 20 );
	myTextBox.SetText( std::to_string( myTextBox.GetElementIdPtr()->GetElementID() ) );
	myTextBox.SetEditable( true );
	myTextBox.SetLimit( true, 4 );

	// making a dropdownmenu
	myDropDown.SetBodySize( 150, 50 );
	myDropDown.SetBodyPosition( 265, 0 );
	myDropDown.SetFont( &m_font );
	myDropDown.SetFontSize( 20 );
	myDropDown.SetBodyColor( sf::Color::Green );
	myDropDown.SetText( std::to_string( myDropDown.GetElementIdPtr()->GetElementID() ));

	myDropDown.AddItemToMenu( "1st item" );
	myDropDown.AddItemToMenu( "2st item" );

	// making a dropdownItem
	myDropDownInput.SetBodySize( 150, 50 );
	myDropDownInput.SetBodyPosition( 265, 120 );
	myDropDownInput.SetFont( &m_font );
	myDropDownInput.SetFontSize( 20 );
	myDropDownInput.SetBodyColor( sf::Color::Green );
	myDropDownInput.SetText( "MyDDM" );

	myDropDownInput.AddItemToMenu( "1st item" );
	myDropDownInput.AddItemToMenu( "2st item" );
	myDropDownInput.AddItemToMenu( "longest of all item" );

	// making a menubar
	myMenu.SetBodySize( 150, 50 );
	myMenu.SetBodyPosition( 430, 0 );
	myMenu.SetFont( &m_font );
	myMenu.SetFontSize( 20 );
	myMenu.SetBodyColor( sf::Color::Magenta );

	myMenu.AddMenuToMenuBar( "a" );
	myMenu.AddMenuToMenuBar( "b" );
	myMenu.AddMenuToMenuBar( "c" );

	myMenu.AddItemToMenu( 0, "aa" );
	myMenu.AddItemToMenu( 0, "ab" );
	myMenu.AddItemToMenu( 0, "ac" );
	myMenu.AddItemToMenu( 0, "ad" );

	myMenu.AddItemToMenu( 1, "ba" );
	myMenu.AddItemToMenu( 1, "bb" );
	myMenu.AddItemToMenu( 1, "bc" );
	myMenu.AddItemToMenu( 1, "bd" );

	Debugger();
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
	//app loop
	while( !m_exit )
	{
		// event polling
		while( m_window.pollEvent( m_events ) )
		{
			switch( m_events.type )
			{
				case sf::Event::Closed:
				{
					m_exit = true;
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

		// ========================== logics ================================

		// ==== at the start of a frame ====
		// clearing the hotelement flag
		Brood::BroodUI::ElementSelection::SetHotElementIdPtrFlag( false );
		// updateing the mouse
		Brood::MouseHandler::UpdateMousePos( m_window );
		Brood::MouseHandler::UpdateMouseButtonStatus();

		// myBoard->Update();

		if( myButton.DoElement() )
		{
			std::cout << "button Pressed" << std::endl;
		}

		myTextBox.DoElement();

		if( myDropDown.DoElement() )
		{
			std::cout << "myDropDown Pressed" << std::endl;
		}
		if( myDropDown.IsSelected() )
		{
			auto itemList = myDropDown.GetItemList();
			// draw its items
			// positining the itemes
			if( !itemList.empty() )
			{
				// checking if the logics of the items is to be executed or not
				for( int i = 0; i < itemList.size(); ++i )
				{
					if( itemList.at( i )->DoElement() )
					{
						std::cerr << "item at " << i << " Pressed with ID"<< 
							itemList.at( i )->GetText() <<	std::endl;

					}
				}
			}
		}

		if(myDropDownInput.DoElement())
		{
			std::cout << "myDropDownInput Pressed" << std::endl;
		}
		if( myDropDownInput.IsSelected() )
		{
			auto itemList = myDropDownInput.GetItemList();
			if( !itemList.empty() )
			{
				// checking if the logics of the items is to be executed or not
				for( int i = 0; i < itemList.size(); ++i )
				{
					if( itemList.at( i )->DoElement() )
					{
						// setting the elements name as the item's name
						myDropDownInput.SetText( itemList.at( i )->GetText() );
						
						// executing the function
						std::cerr << "item at " << i << "  Pressed with ID " <<
							itemList.at( i )->GetText() << std::endl;


					}
				}
			}
		}

		if( !myMenu.GetMenuList().empty() )
		{
			auto menus = myMenu.GetMenuList();

			for( int i = 0; i < menus.size(); ++i )
			{
				if( menus.at( i )->DoElement() )
				{
					std::cout << "menu at " << i << " Pressed" << std::endl;
				}
				// checking if the logics of the element is to be executed or not
				if( menus.at( i )->IsSelected() )
				{
					auto itemList = menus.at( i )->GetItemList();
					if( !itemList.empty() )
					{
						for( int j = 0; j < itemList.size(); ++j )
						{
							if( itemList.at( j )->DoElement() )
							{
								std::cout << "menu at " << i << " Pressed" << std::endl;
								std::cout << "item at " << j << " Pressed" << std::endl;
							}
						}
					}
				}
			}
		}

		//m_initailWorkSpace.Update();

		// rendering 
		m_window.clear();
		m_initailWorkSpace.Draw( m_window );

		//myBoard->Draw( m_window );
		//myCard->Draw( m_window );

		// menus
		myButton.Draw( m_window );
		mySpriteButton.Draw( m_window );
		myMenu.Draw( m_window );
		myDropDown.Draw( m_window );
		myDropDownInput.Draw( m_window );
		myTextBox.Draw( m_window );
		//window.draw(text);
		m_window.display();
	}
}

/// 
/// @public
/// @brief changes the text of the element to its the element ID
/// 
void Brood::Application::Application::Debugger()
{
	myButton.Debugger();
	mySpriteButton.Debugger();
	myTextBox.Debugger();
	myDropDown.Debugger();
	myDropDownInput.Debugger();
	myMenu.Debugger();
}

/// 
/// @brief Initializes the drop down menu bar
/// 
void Brood::Application::Application::InitializeMenuBar()
{
	//myMenu.SetBodySize( 150, 50 );
	//myMenu.SetBodyPosition( 430, 0 );
	//myMenu.SetFont( &m_font );
	//myMenu.SetBodyColor( sf::Color::Magenta );

	//myMenu.AddMenuToMenuBar( "a" );
	//myMenu.AddMenuToMenuBar( "b" );
	//myMenu.AddMenuToMenuBar( "c" );

	//myMenu.GetMenuList().at( 0 )->AddItemToMenu( "aa" );
	//myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ab" );
	//myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ac" );
	//myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ad" );

	//myMenu.GetMenuList().at( 1 )->AddItemToMenu( "ba" );
	//myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bb" );
	//myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bc" );
	//myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bd" );
}

