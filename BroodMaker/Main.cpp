#include "stdafx.h"
#include "Application.h"

int main()
{
	Brood::Application::Application broodMaker;
	broodMaker.RunApplicaiton();
}

//
//#include "stdafx.h"
//#include <filesystem>
//
//#include "Board.h"
//#include "Player.h"
//#include "Card.h"
//#include "MouseHandler.h"
//
//#include "MenuBar.h"
//#include "InitialWorkSpace.h"
//
//#include "struct_path.h"
//#include "Struct_CtorParam.h"
//
//int main()
//{
//	// initializing the randon seed
//	std::srand( ( unsigned int )std::time( nullptr ) );
//	const std::string cwd = std::filesystem::current_path().string();
//	// tweeker
//	const uint32_t WINDOW_HEIGHT = 900;
//	const uint32_t WINDOW_WIDTH = 900;
//
//	bool exit = false;
//
//	// window object
//	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );
//
//	// event object 
//	sf::Event events;
//
//	// initializing the mouse cursor
//	Brood::MouseHandler::InitializeCursor( window );
//
//	// create a board
//	std::string fileName = cwd;
//	fileName += "\\Assets\\DiceTexture\\dice_";
//	fileName += std::to_string( 0 + 1 );
//	fileName += "_50_50.png";
//	/*Brood::St_DiceParam diceParam( fileName, 50.f, 1 );*/
//
//	// create a player
//	//Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
//
//	// loading font
//	sf::Font font;
//	std::string fontFileLoc = cwd + "\\Assets\\Fonts\\arial.ttf";
//	if( !( font.loadFromFile( fontFileLoc ) ) )
//	{
//		std::cerr << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
//	}
//
//	//Brood::BroodUI::Button myButton;
//	//myButton.SetBodySize( 100, 50 );
//	//myButton.SetBodyPosition( 55, 0 );
//	//myButton.SetFont( font );
//	//myButton.SetBodyColor( sf::Color::Red );
//	//myButton.SetText( "-----" );
//
//	Brood::BroodUI::TextBox myTextBox;
//	myTextBox.SetBodySize( 100, 50 );
//	myTextBox.SetBodyPosition( 160, 350 );
//	myTextBox.SetBodyColor( sf::Color::White );
//	myTextBox.SetFont( font );
//	myTextBox.SetFontSize( 25 );
//	myTextBox.SetFontColor( sf::Color::Black );
//	myTextBox.SetText( "hello is this god" );
//	myTextBox.SetEditable( true );
//	myTextBox.SetLimit( true, 4 );
//
//	// making a dropdownmenu
//	Brood::BroodUI::DropDownMenu myDropDown;
//	myDropDown.SetBodySize( 20, 50 );
//	myDropDown.SetBodyPosition( 265, 0 );
//	myDropDown.SetFont( &font );
//	myDropDown.SetFontSize( 20 );
//	myDropDown.SetBodyColor( sf::Color::Green );
//	myDropDown.SetText( "a" );
//
//	myDropDown.AddItemToMenu( "1st item" );
//	myDropDown.AddItemToMenu( "2st item" );
//	myDropDown.AddItemToMenu( "3rd" );
//	myDropDown.AddItemToMenu( "4th is a long one" );
//
//	// making a MenuBar
//	Brood::BroodUI::MenuBar myMenu;
//	myMenu.SetBodySize( WINDOW_WIDTH, 30 );
//	myMenu.SetBodyPosition(0,0 );
//	myMenu.SetFont( &font );
//	myMenu.SetCharacterSize( 20 );
//	myMenu.SetBodyColor( sf::Color::Magenta );
//
//	myMenu.AddMenuToMenuBar( "hello w" );
//	myMenu.AddMenuToMenuBar( "b" );
//	myMenu.AddMenuToMenuBar( "c" );
//
//	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "aa" );
//	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ab" );
//	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ac" );
//	myMenu.GetMenuList().at( 0 )->AddItemToMenu( "ad" );
//
//	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "ba" );
//	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bb" );
//	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bc" );
//	myMenu.GetMenuList().at( 1 )->AddItemToMenu( "bd" );
//
//	//Brood::Application::InitialWorkSpace myInitailWorkSpace;
//
//	//app loop
//	while( !exit )
//	{
//		// event polling
//		while( window.pollEvent( events ) )
//		{
//			switch( events.type )
//			{
//				case sf::Event::Closed:
//				{
//					exit = true;
//					break;
//				}
//				case sf::Event::TextEntered:
//				{
//					if( Brood::BroodUI::ElementSelection::GetCurrActiveElement() == nullptr )
//					{
//						break;
//					}
//
//					// checking if the current active element is a editable textbox
//					int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID();
//					Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
//					if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_textBox )
//					{
//						// checking if it is editable or not
//						Brood::BroodUI::TextBox* currActiveTextBox = ( Brood::BroodUI::TextBox* )currActiveElement;
//						if( currActiveTextBox->IsEditable() )
//						{
//							// if yes then sent the textEntered event to the element
//							currActiveTextBox->TypeOn( events );
//						}
//					}
//					break;
//				}
//			}
//		}
//
//		// ========================== logics ================================
//
//		// at the start of a frame
//		// clearing the hotElement flag
//		Brood::BroodUI::ElementSelection::SetHotElementFlag( false );
//		// updating the mouse
//		Brood::MouseHandler::UpdateMousePos( window );
//		Brood::MouseHandler::UpdateMouseButtonStatus();
//
//		myTextBox.DoElement();
//
//		myDropDown.DoElement();
//		if( myDropDown.IsSelected() )
//		{
//			auto itemList = myDropDown.GetItemList();
//
//			if( !itemList.empty() )
//			{
//				for( int i = 0; i < itemList.size(); ++i )
//				{
//					itemList.at( i )->DoElement();
//				}
//			}
//		}
//
//
//		if( !myMenu.GetMenuList().empty() )
//		{
//			auto menus = myMenu.GetMenuList();
//
//			for( int i = 0; i < menus.size(); ++i )
//			{
//				menus.at( i )->DoElement();
//				if( menus.at( i )->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() )
//				{
//					menus.at( i )->SetSelected( true );
//				}
//				else
//				{
//					menus.at( i )->SetSelected( false );
//				}
//				if( menus.at( i )->IsSelected() )
//				{
//					auto itemList = menus.at( i )->GetItemList();
//					if( !itemList.empty() )
//					{
//						for( int i = 0; i < itemList.size(); ++i )
//						{
//							if( itemList.at( i )->DoElement() )
//							{
//								//myBoard.PlayerRollAndMove();
//							}
//						}
//					}
//				}
//			}
//		}
//
//		//myInitailWorkSpace.Update();
//
//		// rendering 
//		window.clear();
//		//myInitailWorkSpace.Draw( window );
//
//		// menus
//		myMenu.Draw( window );
//		myTextBox.Draw( window );
//		myDropDown.Draw( window ); 
//		window.display();
//	}
//
//	// clean up
//
//	// closing the window
//	window.close();
//}



//#include "stdafx.h"
//#include <filesystem>
//
//#include "Board.h"
//#include "Player.h"
//#include "Card.h"
//#include "MouseHandler.h"
//
//#include "MenuBar.h"
//#include "InitialWorkSpace.h"
//
//#include "struct_path.h"
//#include "Struct_CtorParam.h"
//
//int main()
//{
//	// initializing the randon seed
//	std::srand( ( unsigned int )std::time( nullptr ) );
//	const std::string cwd = std::filesystem::current_path().string();
//	// tweeker
//	const uint32_t WINDOW_HEIGHT = 900;
//	const uint32_t WINDOW_WIDTH = 900;
//
//	bool exit = false;
//
//	// window object
//	sf::RenderWindow window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT ), "BroodMaker" );
//
//	// event object 
//	sf::Event events;
//
//	// initializing the mouse cursor
//	Brood::MouseHandler::InitializeCursor( window );
//
//	// create a board
//
//	std::string fileName = cwd;
//	fileName += "\\Assets\\DiceTexture\\dice_";
//	fileName += std::to_string( 0 + 1 );
//	fileName += "_50_50.png";
//	Brood::St_DiceParam diceParam( fileName, 50.f, 1 );
//	St_BoardParam boardParam( 10, 10, 520.f, 520.f, 100.f, 100.f );
//	//Board myBoard( &boardParam, &diceParam );
//
//	// create a player
//	//Player player1( 0, 0, 25.f, 25.f, 100.f, 100.f );
//	//myBoard.AddPlayer( 25.f, 25.f );
//
//	// loading font
//	sf::Font font;
//	std::string fontFileLoc = cwd + "\\Assets\\Fonts\\arial.ttf";
//	if( !( font.loadFromFile( fontFileLoc ) ) )
//	{
//		std::cout << "Error! Could not load " << fontFileLoc << "!!!!!!!" << std::endl;
//	}
//	//Card myCard( font, 300, 300, "5+3", "8", 3, 2, 1 );
//
//	Brood::BroodUI::Button myButton;
//	myButton.SetBodySize( 100, 50 );
//	myButton.SetBodyPosition( 55, 0 );
//	myButton.SetFont( font );
//	myButton.SetBodyColor( sf::Color::Red );
//	myButton.SetText( "-----" );
//
//	Brood::BroodUI::Button mySpriteButton;
//	mySpriteButton.SetBodySize( 50, 50 );
//	mySpriteButton.SetBodyPosition( 55, 100 );
//	mySpriteButton.SetFont( font );
//	// setting sprite height and length 
//	/*mySpriteButton.GetSpriteBody().SetSpriteLength( 50 );
//	mySpriteButton.GetSpriteBody().SetSpriteHeight( 50 );*/
//	// loading the texture
//	mySpriteButton.GetSpriteBody().SetTextureFromFilePath( fileName );
//	mySpriteButton.GetSpriteBody().SetSpriteFromTexture( 0 );
//
//	Brood::BroodUI::TextBox myTextBox;
//	myTextBox.SetBodySize( 100, 50 );
//	myTextBox.SetBodyPosition( 160, 0 );
//	myTextBox.SetBodyColor( sf::Color::White );
//	myTextBox.SetFont( font );
//	myTextBox.SetFontColor( sf::Color::Black );
//	myTextBox.SetText( "hello" );
//	myTextBox.SetEditable( true );
//	myTextBox.SetLimit( true, 4 );
//
//	// making a dropdownmenu
//	Brood::BroodUI::DropDownMenu myDropDown;
//	myDropDown.SetBodySize( 150, 50 );
//	myDropDown.SetBodyPosition( 265, 0 );
//	myDropDown.SetFont( &font );
//	myDropDown.SetBodyColor( sf::Color::Green );
//	myDropDown.SetText( "MyDDM" );
//
//	myDropDown.AddItemToMenu( "1st item" );
//	myDropDown.AddItemToMenu( "2st item" );
//
//	// making a menubar
//	Brood::BroodUI::MenuBar myMenu;
//	myMenu.SetBodySize( 150, 50 );
//	myMenu.SetBodyPosition( 430, 0 );
//	myMenu.SetFont( &font );
//	myMenu.SetFontSize( 20 );
//	myMenu.SetBodyColor( sf::Color::Magenta );
//
//	myMenu.AddMenuToMenuBar( "a" );
//	myMenu.AddMenuToMenuBar( "b" );
//	myMenu.AddMenuToMenuBar( "c" );
//
//	myMenu.AddItemToMenu( 0, "aa" );
//	myMenu.AddItemToMenu( 0, "ab" );
//	myMenu.AddItemToMenu( 0, "ac" );
//	myMenu.AddItemToMenu( 0, "ad" );
//
//	myMenu.AddItemToMenu( 1, "ba" );
//	myMenu.AddItemToMenu( 1, "bb" );
//	myMenu.AddItemToMenu( 1, "bc" );
//	myMenu.AddItemToMenu( 1, "bd" );
//
//	Brood::Application::InitialWorkSpace myInitailWorkSpace;
//
//	//app loop
//	while( !exit )
//	{
//		// event polling
//		while( window.pollEvent( events ) )
//		{
//			switch( events.type )
//			{
//				case sf::Event::Closed:
//				{
//					exit = true;
//					break;
//				}
//				case sf::Event::TextEntered:
//				{
//					if( Brood::BroodUI::ElementSelection::GetCurrActiveElement() == nullptr )
//					{
//						break;
//					}
//
//					int currActiveElementId = Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID();
//					Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
//					if( currActiveElement->GetElementType() == Brood::BroodUI::ENUM_UIType::UI_textBox )
//					{
//						// checking if it is editable or not
//						Brood::BroodUI::TextBox* currActiveTextBox = ( Brood::BroodUI::TextBox* )currActiveElement;
//						if( currActiveTextBox->IsEditable() )
//						{
//							// if yes then sent the textEntered event to the element
//							currActiveTextBox->TypeOn( events );
//						}
//					}
//					break;
//				}
//			}
//		}
//
//		// ========================== logics ================================
//
//		// at the start of a frame
//		// clearing the hotelement flag
//		Brood::BroodUI::ElementSelection::SetHotElementFlag( false );
//		// updateing the mouse
//		Brood::MouseHandler::UpdateMousePos( window );
//		Brood::MouseHandler::UpdateMouseButtonStatus();
//
//		// myBoard.Update();
//
//		if( myButton.DoElement() )
//		{
//			//myBoard.PlayerRollAndMove();
//		}
//
//
//		myTextBox.DoElement();
//
//		myDropDown.DoElement();
//		
//		if( myDropDown.IsSelected() )
//		{
//			auto itemList = myDropDown.GetItemList();
//			// draw its items
//			// positining the itemes
//			if( !itemList.empty() )
//			{
//				// postion all items according to the new menu position
//				for( int i = 0; i < itemList.size(); ++i )
//				{
//					itemList.at( i )->DoElement();
//				}
//			}
//		}
//
//		if( !myMenu.GetMenuList().empty() )
//		{
//			auto menus = myMenu.GetMenuList();
//
//			for( int i = 0; i < menus.size(); ++i )
//			{
//				menus.at( i )->DoElement();
//				// checking if the logics of the element is to be executed or not
//				if( menus.at( i )->IsSelected() )
//				{
//					auto itemList = menus.at( i )->GetItemList();
//					if( !itemList.empty() )
//					{
//						for( int i = 0; i < itemList.size(); ++i )
//						{
//							if( itemList.at( i )->DoElement() )
//							{
//								//myBoard.PlayerRollAndMove();
//							}
//						}
//					}
//				}
//			}
//		}
//
//		//myInitailWorkSpace.Update();
//
//		// rendering 
//		window.clear();
//		//myInitailWorkSpace.Draw( window );
//
//		//myBoard.Draw( window );
//		//myCard.Draw( window );
//
//		// menus
//		myButton.Draw( window );
//		mySpriteButton.Draw( window );
//		myMenu.Draw( window );
//		myDropDown.Draw( window );
//		myTextBox.Draw( window );
//		//window.draw(text);
//		window.display();
//	}
//
//	// clean up
//
//	// closing the window
//	window.close();
//}