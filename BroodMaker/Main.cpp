#include "stdafx.h"
#include <filesystem>

#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "MouseHandler.h"
#include "MenuBar.h"

#include "struct_path.h"
#include "Struct_CtorParam.h"


int main()
{
	// initializing the randon seed
	std::srand( ( unsigned int )std::time( nullptr ) );
	const std::string cwd = std::filesystem::current_path().string();
	// tweeker
	const uint32_t WINDOW_HEIGHT = 900;
	const uint32_t WINDOW_WIDTH = 900;

	bool exit = false;

	// window object
	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );

	// event object 
	sf::Event events;
	
	// initializing the mouse cursor
	Brood::MouseHandler::InitializeCursor( window );

	// create a board
	
	std::string fileName = cwd;
	fileName += "\\Assets\\DiceTexture\\dice_";
	fileName += std::to_string( 0 + 1 );
	fileName += "_50_50.png";
	Brood::St_DiceParam diceParam( fileName, 50.f, 1 );
	St_BoardParam boardParam( 10, 10, 520.f, 520.f, 100.f, 100.f );
	Board myBoard( &boardParam, &diceParam );

	// create a player
	//Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
	myBoard.AddPlayer( 25.f, 25.f );

	// loading font
	sf::Font font;
	std::string fontFileLoc = cwd + "\\Assets\\Fonts\\arial.ttf";
	if( !( font.loadFromFile( fontFileLoc ) ) )
	{
		std::cout << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
	}
	Card myCard( font, 300, 300, "5+3", "8", 3, 2, 1 );


	Brood::BroodUI::Button myButton;
	myButton.SetBodySize( 100, 50 );
	myButton.SetBodyPosition( 200, 0 );
	myButton.SetFont( font );
	myButton.SetBodyColor( sf::Color::Red );
	myButton.SetText( "-----" );

	Brood::BroodUI::TextBox myTextBox;
	myTextBox.SetBodySize( 100, 50 );
	myTextBox.SetBodyPosition( 350, 0 );
	myTextBox.SetBodyColor( sf::Color::White );
	myTextBox.SetFont( font );
	myTextBox.SetFontColor ( sf::Color::Black );
	myTextBox.SetText( "hello" );
	myTextBox.SetEditable( true );

	// making a dropdownmenu
	Brood::BroodUI::DropDownMenu myDropDown;
	myDropDown.SetBodySize( 150, 50 );
	myDropDown.SetBodyPosition( 500, 0 );
	myDropDown.SetFont( &font );
	myDropDown.SetBodyColor( sf::Color::Green );
	myDropDown.SetText( "MyDDM" );

	myDropDown.AddItemToMenu( "1st item" );
	myDropDown.AddItemToMenu( "2st item" );

	// making a dropdownmenu
	Brood::BroodUI::MenuBar myMenu;
	myMenu.SetBodySize( 150, 50 );
	myMenu.SetBodyPosition( 500, 75 );
	myMenu.SetFont( &font );
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

	//app loop
	while( !exit )
	{
		// event polling
		while( window.pollEvent( events ) )
		{
			switch( events.type )
			{
				case sf::Event::Closed:
				{
					exit = true;
					break;
				}
				case sf::Event::KeyPressed:
				{
					///@todo: delete me
					if( sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
					{
						myBoard.PlayerRollAndMove();
					}
					break;
				}
				case sf::Event::TextEntered:
				{
					///@todo: delete me
					myTextBox.TypeOn( events );
					break;
				}
				/*case sf::Event::MouseMoved:
				{
					Brood::MouseHandler::UpdateMousePos( window );
					break;
				}*/
			}
		}

		// ========================== logics ================================
		
		// updateing the mouse
		Brood::MouseHandler::UpdateMousePos( window );
		Brood::MouseHandler::UpdateMouseButtonStatus();

		myBoard.Update();
		myButton.DoElement();
		
		myTextBox.DoElement();
		if( myTextBox.GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
		{
			myTextBox.SetSelected( true );
		}
		else
		{
			myTextBox.SetSelected( false );
		}

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

			// draw its menus
			// positining the itemes
			// postion all items according to the new menu position
			for( int i = 0; i < menus.size(); ++i )
			{
				menus.at(i)->DoElement();
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
			}
		}
		// rendering 
		window.clear();
		myBoard.Draw( window );
		myCard.Draw( window );
		myButton.Draw( window );
		myTextBox.Draw( window );
		myDropDown.Draw( window );
		myMenu.Draw(window);
		//window.draw(text);
		window.display();
	}

	// clean up

	// closing the window
	window.close();
}
