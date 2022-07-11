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
	m_initailWorkSpace()
{
	// initializing the randon seed
	std::srand( ( unsigned int )std::time( nullptr ) );

	m_exit = false;

	// initializing the mouse cursor
	Brood::MouseHandler::InitializeCursor( m_window );

	/// todo: delete me
	// create a board

	std::string fileName = cwd;
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
	std::string fontFileLoc = cwd + "\\Assets\\Fonts\\arial.ttf";
	if( !( m_font.loadFromFile( fontFileLoc ) ) )
	{
		std::cout << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}
	myCard = new Card( m_font, 300, 300, "5+3", "8", 3, 2, 1 );

	myButton.SetBodySize( 100, 50 );
	myButton.SetBodyPosition( 55, 0 );
	myButton.SetFont( m_font );
	myButton.SetBodyColor( sf::Color::Red );
	myButton.SetText( "-----" );

	myTextBox.SetBodySize( 100, 50 );
	myTextBox.SetBodyPosition( 160, 0 );
	myTextBox.SetBodyColor( sf::Color::White );
	myTextBox.SetFont( m_font );
	myTextBox.SetFontColor( sf::Color::Black );
	myTextBox.SetText( "hello" );
	myTextBox.SetEditable( true );
	myTextBox.SetLimit( true, 4 );

	// making a dropdownmenu
	myDropDown.SetBodySize( 150, 50 );
	myDropDown.SetBodyPosition( 265, 0 );
	myDropDown.SetFont( &m_font );
	myDropDown.SetBodyColor( sf::Color::Green );
	myDropDown.SetText( "MyDDM" );

	myDropDown.AddItemToMenu( "1st item" );
	myDropDown.AddItemToMenu( "2st item" );

	// making a dropdownmenu
	myMenu.SetBodySize( 150, 50 );
	myMenu.SetBodyPosition( 430, 0 );
	myMenu.SetFont( &m_font );
	myMenu.SetBodyColor( sf::Color::Magenta );

	myMenu.AddMenuToMenuBar( "a" );
	myMenu.AddMenuToMenuBar( "b" );
	myMenu.AddMenuToMenuBar( "c" );

	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "aa" );
	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ab" );
	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ac" );
	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ad" );

	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "ba" );
	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bb" );
	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bc" );
	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bd" );

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
					if( Brood::BroodUI::ElementSelection::GetCurrActiveElement() == nullptr )
					{
						break;
					}

					int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID();
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

		// at the start of a frame
		// clearing the hotelement flag
		Brood::BroodUI::ElementSelection::SetHotElementFlag( false );
		// updateing the mouse
		Brood::MouseHandler::UpdateMousePos( m_window );
		Brood::MouseHandler::UpdateMouseButtonStatus();

		// myBoard->Update();

		if( myButton.DoElement() )
		{
			myBoard->PlayerRollAndMove();
		}

		myTextBox.DoElement();

		myDropDown.DoElement();
		if( myDropDown.GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
		{
			myDropDown.SetSelected( true );
		}
		else
		{
			myDropDown.SetSelected( false );
		}
		if( myDropDown.IsSelected() )
		{
			auto itemList = myDropDown.GetItemList();
			// draw its items
			// positining the itemes
			if( !itemList.empty() )
			{
				// postion all items according to the new menu position
				for( int i = 0; i < itemList.size(); ++i )
				{
					itemList.at( i )->DoElement();
				}
			}
		}

		if( !myMenu.GetMenuList().empty() )
		{
			auto menus = myMenu.GetMenuList();

			for( int i = 0; i < menus.size(); ++i )
			{
				menus.at( i )->DoElement();
				if( menus.at( i )->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
				{
					menus.at( i )->SetSelected( true );
				}
				else
				{
					menus.at( i )->SetSelected( false );
				}
				if( menus.at( i )->IsSelected() )
				{
					auto itemList = menus.at( i )->GetItemList();
					if( !itemList.empty() )
					{
						for( int i = 0; i < itemList.size(); ++i )
						{
							if( itemList.at( i )->DoElement() )
							{
								myBoard->PlayerRollAndMove();
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
		myMenu.Draw( m_window );
		myDropDown.Draw( m_window );
		myTextBox.Draw( m_window );
		//window.draw(text);
		m_window.display();
	}

}

