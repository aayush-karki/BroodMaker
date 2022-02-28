#include "stdafx.h"
#include <filesystem>

#include "Board.h"
#include "Dice.h"
#include "Player.h"

#include "struct_path.h"

int main()
{

	// initializing the randon seed
	std::srand( std::time( nullptr ) );

	// tweeker
	const uint32_t WINDOW_HEIGHT = 900;
	const uint32_t WINDOW_WIDTH = 900;

	bool exit = false;

	// window object
	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );

	// event object 
	sf::Event events;

	// create a board
	Board myBoard( 10,10, 520.f, 520.f, 100.f, 100.f );

	/// @todo maybe it is better to make a textureManager
	// loading dice texture
	std::vector<sf::Texture> diceTexture;

	for( unsigned i = 0; i < 6; ++i )
	{
		sf::Texture tempTexture;

		/// @warning this might cause problem latter; cwd path might differ 
		std::string fileName = std::filesystem::current_path().string();

		// appending the path that has the dice texture
		fileName += "\\Assets\\DiceTexture\\dice_";
		fileName += std::to_string(i + 1);
		fileName += "_50_50.png";
		
		if( !( tempTexture.loadFromFile( fileName ) ) ) 
		{
			std::cout << "Error! Could not load " << fileName << "!!!!!!!" << std::endl;
		}

		diceTexture.push_back( std::move_if_noexcept( tempTexture ) );
	}

	Dice dice(&diceTexture, 50.f, 50.f, 0.f );

	// create a player
	Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );


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
			else if( events.type == sf::Event::KeyPressed)
			{
				///@todo: delete me
				if( sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
				{
					std::cout << dice.RollDice() << std::endl;
				}
			}
		}

		// logics

		// rendering 
		window.clear();
		myBoard.Draw( window );
		dice.Draw( window );
		player1.Draw(window);
		window.display();
	}

	// clean up
	
	// closing the window
	window.close();
}