#include "stdafx.h"
#include "Board.h"

/// 
/// @brief 
///
/// @return 
/// 
int main()
{
	// tweeker
	const uint32_t WINDOW_HEIGHT = 900;
	const uint32_t WINDOW_WIDTH = 900;

	bool exit = false;

	// window object
	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );

	// event object 
	sf::Event events;

	// create a board
	Board myBoard( 2, 2, 520, 520, 100, 100 );

	//app loop
	while( !exit )
	{
		// event polling
		while( window.pollEvent( events ) )
		{
			if( events.type == sf::Event::Closed )
			{
				exit = true;
			}
		}

		// logics

		// rendering 
		window.clear();
		myBoard.Draw(window);
		window.display();
	}

	// clean up

	// closing the window
	window.close();

}