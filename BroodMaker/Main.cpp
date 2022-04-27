#include "stdafx.h"
#include <filesystem>

#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "MouseHandler.h"
#include "TextBox.h"

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
						//std::cout << myBoard.() << std::endl;
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


		// rendering 
		window.clear();
		myBoard.Draw( window );
		myCard.Draw( window );
		myButton.Draw( window );
		myTextBox.Draw(window);
		//window.draw(text);
		window.display();
	}

	// clean up

	// closing the window
	window.close();
}
