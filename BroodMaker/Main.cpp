#include "stdafx.h"
#include <filesystem>

#include "Board.h"
#include "Player.h"

#include "struct_path.h"
#include "Struct_CtorParam.h"


int main()
{
	// initializing the randon seed
	std::srand( ( unsigned int ) std::time( nullptr ) );

	// tweeker
	const uint32_t WINDOW_HEIGHT = 900;
	const uint32_t WINDOW_WIDTH = 900;

	bool exit = false;

	// window object
	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );

	// event object 
	sf::Event events;

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

	// create a board
	const std::vector<sf::Texture>* diceTexturesVecPtr = &diceTexture;
	
	St_DiceParam diceParam( diceTexturesVecPtr, 50.f, 50.f, 0.f );
	St_BoardParam boardParam( 10, 10, 520.f, 520.f, 100.f, 100.f );
	Board myBoard( boardParam, diceParam);

	// create a player
	//Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
	myBoard.AddNewPlayer( 25.f, 25.f );

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
					//std::cout << myBoard.() << std::endl;
					myBoard.PlayerRollAndMove( myBoard.GetNextPlayer() );
				}
			}
		}

		// logics

		// rendering 
		window.clear();
		myBoard.Draw( window );
		window.display();
	}

	// clean up
	
	// closing the window
	window.close();
}