#include <iostream>
#include <SFML/Graphics.hpp>

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
	sf::RectangleShape recShape;
	recShape.setFillColor( sf::Color::Green );
	recShape.setSize( sf::Vector2f( 100.f, 100.f ) );

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
		window.draw( recShape );
		window.display();

	}

	// clean up

	// closing the window
	window.close();

}