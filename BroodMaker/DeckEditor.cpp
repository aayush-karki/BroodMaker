/*************************************************************************/
/// 
/// @file DeckEditor.cpp 
/// 
/// @brief  This file is a source file for DeckEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of DeckEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "DeckEditor.h"

// ======================================================================
// ================= start of DeckEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::DeckEditor::DeckEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::DeckEditor::~DeckEditor()
{
	// all the dynamically created panel elements are 
	// destructed in the base class
}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It inializes the board,
///		setting section Dropdown Input.
//
void Brood::Application::DeckEditor::InitializeWorkSpace()
{
	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "General Deck and Card Settings" );
	m_txtSettingTitle->SetFontSize( 18 );


	// ==================== initializes the deck panel element ======================

	Brood::Application::Components::DeckManager* deckManagerPtr = m_gameData->GetDeckManagerPtr();

	// creating a panel element to control the current deck index
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckCurrIdxPrompt, &m_btnDeckDecCurrIdx,
								 &m_txtDeckCurrIdx, &m_btnDeckIncCurrIdx,
								 "Current deck index",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeckIdx() ) );


	// creating a panel element to control the deck sizeX
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckSizeXPrompt, &m_btnDeckDecSizeX,
								 &m_txtDeckSizeX, &m_btnDeckIncSizeX,
								 "Deck X Size",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeck()->GetBodySize().x ) );

	// creating a panel element to control the deck sizeY
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckSizeYPrompt, &m_btnDeckDecSizeY,
								 &m_txtDeckSizeY, &m_btnDeckIncSizeY,
								 "Deck Y Size",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeck()->GetBodySize().y ) );

	// creating a panel element to control the deck Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckPosXPrompt, &m_btnDeckDecPosX,
								 &m_txtDeckPosX, &m_btnDeckIncPosX,
								 "Deck X Pos",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeck()->GetBodyPosition().x ) );

	// creating a panel element to control the deck Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckPosYPrompt, &m_btnDeckDecPosY,
								 &m_txtDeckPosY, &m_btnDeckIncPosY,
								 "Deck Y Pos",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeck()->GetBodyPosition().y ) );

	// initializing the UI to control deck file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtDeckBgFileNamePrompt, &m_txtDeckBgFileInput,
									&m_btnDeckBgOpenFile, "Deck Texture Filename",
									deckManagerPtr->GetCurrActiveDeck()->GetSpriteBody().GetTextureFileName() );

	// initializing the UI to control deck cardInit file name 
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtCardInitFileNamePrompt, &m_txtCardInitFileInput,
									&m_btnCardInitOpenFile, "Deck Texture Filename",
									deckManagerPtr->GetCurrActiveDeck()->GetCardInitFileName() );

	// creating a panel element to control  number of cards in the deck
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardNumPrompt, &m_btnDecCardNum,
								 &m_txtCardNum, &m_btnIncCardNum,
								 "Total Number of Cards",
								 std::to_string( ( int )deckManagerPtr->GetCurrActiveDeck()->GetCardList().size() ) );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::DeckEditor::Update()
{
	// checks if the user interacted current deck index
	// panel Element
	UpdateCurrSelectedDeckIdx();

	// checks if the user interacted with the Deck 
	// x size panel Element
	UpdateDeckSizeX();

	// checks if the user interacted with the Deck 
	// y size panel Element
	UpdateDeckSizeY();

	// checks if the user interacted with the Deck 
	// x size panel Element
	UpdateDeckPosX();

	// checks if the user interacted with the Deck 
	// y Pos panel Element
	UpdateDeckPosY();

	// checks if the user interacted with the load 
	// deck texture panel Element
	UpdateDeckFileTexture();

	// checks if the user interacted with the load 
	// card init panel Element
	UpdateCardInitFile();

	// checks if the user interacted with the number
	// of card panel Element
	UpdateCardNumber();
}

/// 
/// @public
/// @virtual
/// @brief updates the display element
/// 
void Brood::Application::DeckEditor::UpdateAllDispayElement()
{
	Brood::Application::Components::DeckManager* deckManagerPtr = m_gameData->GetDeckManagerPtr();

	// deck current active index 
	m_txtDeckCurrIdx->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeckIdx() ) );

	// Deck X Size 
	m_txtDeckSizeX->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeck()->GetBodySize().x ) );

	// Deck y Size 
	m_txtDeckSizeY->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeck()->GetBodySize().y ) );

	// Deck X position 
	m_txtDeckPosX->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeck()->GetBodyPosition().x ) );

	// Deck y position 
	m_txtDeckPosY->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeck()->GetBodyPosition().y ) );

	// Deck file name
	m_txtDeckBgFileInput->SetText( deckManagerPtr->GetCurrActiveDeck()->GetSpriteBody().GetTextureFileName() );

	// Card Init file name
	m_txtCardInitFileInput->SetText( deckManagerPtr->GetCurrActiveDeck()->GetCardInitFileName() );

	// number of cards
	m_txtCardNum->SetText( std::to_string( deckManagerPtr->GetCurrActiveDeck()->GetCardList().size() ));
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
/// 
/// @param a_window reference to the render window
///
void Brood::Application::DeckEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing game component
	m_gameData->Draw( a_window );

	// drawing the dynamically created elements
	Brood::Application::WorkSpace::Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::DeckEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}


///
/// @private
/// @brief checks if the user interacted with the current selceted deck 
///		index panel
///	
/// Current selceted deck index panel contains  current selceted Deck 
///		index promt textbox, current selceted Deck index value text box, 
///		button to increase the current selceted Deck index, and button 
///		to decrease the current selceted Deck index
/// 
/// Only the button to increase the current selceted Deck index, and 
///		button to decrease the current selceted Deck index are interactable
/// 
/// If the interactable button was pressed then the current selceted Deck 
///		index is increased or decresed by 1. current selceted Deck index
///		should be more than or equal to 1 but less than Deck number
///
void Brood::Application::DeckEditor::UpdateCurrSelectedDeckIdx()
{
	// chekcing if the decrease the current selceted Deck index was pressed
	if( m_btnDeckDecCurrIdx->DoElement() )
	{
		// getting current selceted Deck index
		unsigned currentDeckIdx = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeckIdx();

		// chekcing if the current currentMaxDeckNum id 
		// equal to 0 then do nothing
		if( currentDeckIdx == 0 )
		{
			return;
		}

		// decrease the current selceted Deck index by 1 units
		m_gameData->GetDeckManagerPtr()->SetCurrActiveDeckIdx( currentDeckIdx - 1 );

		// updating the textbox showing the current selceted Deck index value
		m_txtDeckCurrIdx->SetText( std::to_string( currentDeckIdx - 1 ) );

		// changing the displayed Deck data
		UpdateAllDispayElement();

	}
	// chekcing if the increase the current selceted Deck index was pressed
	else if( m_btnDeckIncCurrIdx->DoElement() )
	{
		// getting position information
		unsigned currentDeckIdx = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeckIdx();

		// chekcing if the current currentMaxDeckNum id 
		// equal to maimum number of Deck then do nothing
		if( currentDeckIdx == m_gameData->GetDeckManagerPtr()->GetDeckList().size() - 1 )
		{
			return;
		}

		// decrease the current selceted Deck index by 1 units
		m_gameData->GetDeckManagerPtr()->SetCurrActiveDeckIdx( currentDeckIdx + 1 );

		// updating the textbox showing the current selceted Deck index value
		m_txtDeckCurrIdx->SetText( std::to_string( currentDeckIdx + 1 ) );

		// changing the displayed Deck data
		UpdateAllDispayElement();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Deck x size panel
///	
/// Deck X size panel contains current Deck X size promt textbox, 
///		current Deck X size value text box, button to increase the
///		current Deck X size, and button to decrease the current 
///		Deck X size.
/// 
/// Only the button to increase the current Deck X size, and button 
///		to decrease the current Deck X size are interactable
/// 
/// If the interactable button was pressed then the current Deck 
///		X size is increased or decresed by 5 if the current Deck
///		does not go outside the board window 
///
void Brood::Application::DeckEditor::UpdateDeckSizeX()
{
	// chekcing if the decrease the Deck X size was pressed
	if( m_btnDeckDecSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if the current size.x is 0 then do notthing
		if( currentSizeX == 0 )
		{
			return;
		}

		// decrease the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodySize( currentSizeX - 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtDeckSizeX->SetText( std::to_string( currentSizeX - 5 ) );
	}
	// chekcing if the incresase the Deck X size was pressed
	else if( m_btnDeckIncSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make Deck to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( ( unsigned )m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition().x + currentSizeX + 5 >= boardWindowWidth )
		{
			return;
		}

		// increase the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodySize( currentSizeX + 5, currentSize.y );

		// updating the textbox showing the x-positon value
		m_txtDeckSizeX->SetText( std::to_string( currentSizeX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Deck y size panel
///	
/// Deck Y size panel contains current Deck y size promt textbox, 
///		current Deck y size value text box, button to increase the
///		current Deck y size, and button to decrease the current 
///		Deck y size.
/// 
/// Only the button to increase the current Deck y size, and button 
///		to decrease the current Deck y size are interactable
/// 
/// If the interactable button was pressed then the current Deck 
///		y size is increased or decresed by 5 if the current Deck
///		does not go outside the board window 
///
void Brood::Application::DeckEditor::UpdateDeckSizeY()
{
	// chekcing if the decrease the Deck Y size was pressed
	if( m_btnDeckDecSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is 0 then do nothing
		if( currentSizeY == 0 )
		{
			return;
		}

		// decrease the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodySize( currentSize.x, currentSizeY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDeckSizeY->SetText( std::to_string( currentSizeY - 5 ) );
	}
	// chekcing if the Increase the Deck Y size was pressed
	else if( m_btnDeckIncSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make Deck to go
		// out of the board window
		// 
		// getting the board window width
		uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
		if( ( unsigned )m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition().y + currentSizeY + 5 >= windowHieght )
		{
			return;
		}

		// increase the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodySize( currentSize.x, currentSizeY + 5 );

		// updating the textbox showing the x-positon value
		m_txtDeckSizeY->SetText( std::to_string( currentSizeY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Deck x position panel
///	
/// Deck X position panel contains current Deck X position promt textbox, 
///		current Deck X position value text box, button to increase the
///		current Deck X position, and button to decrease the current 
///		Deck X position.
/// 
/// Only the button to increase the current Deck X position, and button 
///		to decrease the current Deck X position are interactable
/// 
/// If the interactable button was pressed then the current Deck 
///		X position is increased or decresed by 1 if the current Deck
///		does not go outside the board window 
///
void Brood::Application::DeckEditor::UpdateDeckPosX()
{
	// chekcing if the decrease the Deck X postion was pressed
	if( m_btnDeckDecPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the current postition is 0 then do notthing
		if( currentPosX == 0 )
		{
			return;
		}

		// decrease the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodyPosition( currentPosX - 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtDeckPosX->SetText( std::to_string( currentPosX - 5 ) );
	}
	// chekcing if the Increase the Deck X postion was pressed
	else if( m_btnDeckIncPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition();
		int currentPosX = currentPos.x;

		// chekcing if the Deck goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
		float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

		if( currentPosX == boardWindowWidth - m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition().x )
		{
			return;
		}

		// increase the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodyPosition( currentPosX + 5, currentPos.y );

		// updating the textbox showing the x-positon value
		m_txtDeckPosX->SetText( std::to_string( currentPosX + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the player Y Offset panel
///	
/// Player Y Offset panel contains current player Y Offset promt textbox, 
///		current player Y Offset value text box, button to increase the
///		current player Y Offset, and button to decrease the current 
///		player Y Offset.
/// 
/// Only the button to increase the current player Y Offset, and button 
///		to decrease the current player Y Offset are interactable
/// 
/// If the interactable button was pressed then the current player 
///		Y Offset is increased or decresed by 1 if the current player
///		does not go outside the board window 
///
void Brood::Application::DeckEditor::UpdateDeckPosY()
{
	// chekcing if the decrease the Deck Y postion was pressed
	if( m_btnDeckDecPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the current postition is 90 then do notthing
		if( currentPosY == 90 )
		{
			return;
		}

		// decrease the Deck y position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodyPosition( currentpos.x, currentPosY - 5 );

		// updating the textbox showing the x-positon value
		m_txtDeckPosY->SetText( std::to_string( currentPosY - 5 ) );
	}
	// chekcing if the increase the Deck Y postion was pressed
	else if( m_btnDeckIncPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentpos = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodyPosition();
		int currentPosY = currentpos.y;

		// chekcing if the Deck goes out of the view if position is 
		// increased any further

		// getting the board window width
		uint32_t boardHeigh = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;

		if( currentPosY == boardHeigh - m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetBodySize().y )
		{
			return;
		}

		// increase the Deck x position by 5 units
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->SetBodyPosition( currentpos.x, currentPosY + 5 );

		// updating the textbox showing the x-positon value
		m_txtDeckPosY->SetText( std::to_string( currentPosY + 5 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the laod Deck texture 
///		panel
///	
/// Load Deck texture file panel contains load Deck texture file 
///		promt textbox, textbox to enter the file name, and button to 
///		open and load the file.
/// 
/// Only the textbox to enter the file name, and button to 
///		open and load the file are interactable
/// 
/// If the interactable button was pressed then it opens the filename 
///		entered
/// 
/// @warning Texture should always be in .png form
/// @warning the Texture for the file should be in \Assets\Textures\DeckTexture\
///		as it loads them from there. 
/// 
void Brood::Application::DeckEditor::UpdateDeckFileTexture()
{
	if( m_txtDeckBgFileInput->DoElement() )
	{
		m_txtDeckBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnDeckBgOpenFile->DoElement() || ( m_txtDeckBgFileInput->IsEnterPressed() &&
											  m_txtDeckBgFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string deckTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_deckTextures.string();

		deckTextureFilePath += "\\" + m_txtDeckBgFileInput->GetText();


		// loading the texture file
		if( !m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetSpriteBody().SetTextureFromFilePath( deckTextureFilePath ) )
		{
			m_txtDeckBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}

		// resetting the m_eterPressed
		m_txtDeckBgFileInput->SetEnterPressedFalse();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the laod card init
///		panel
///	
/// Load card init file panel contains load card init file 
///		promt textbox, textbox to enter the file name, and button to 
///		open and load the file.
/// 
/// Only the textbox to enter the file name, and button to 
///		open and load the file are interactable
/// 
/// If the interactable button was pressed then it opens the filename 
///		entered
/// 
/// @warning Texture should always be in .png form
/// @warning the Texture for the file should be in \data\
///		as it loads them from there. 
///
void Brood::Application::DeckEditor::UpdateCardInitFile()
{
	if( m_txtCardInitFileInput->DoElement() )
	{
		m_txtCardInitFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnCardInitOpenFile->DoElement() || ( m_txtCardInitFileInput->IsEnterPressed() &&
												m_txtCardInitFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string dataFilePath = Brood::Application::StaticVariables::ST_Folders::stm_data.string();

		dataFilePath += "\\" + m_txtDeckBgFileInput->GetText();

		// checking if the .txt was provided or not
		std::size_t found = m_txtDeckBgFileInput->GetText().find_last_of('.');

		if( found == std::string::npos )
		{
			dataFilePath += ".txt";
		}

		// loading the texture file
		if( !m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->LoadCardFromInitFile( dataFilePath ) )
		{
			m_txtDeckBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}
		else
		{
			/// TODO load the card info form the INIT file
		}

		// resetting the m_eterPressed
		m_txtDeckBgFileInput->SetEnterPressedFalse();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the Card number panel
///	
/// Card number panel contains Card number promt textbox, 
///		Card number number value text box, button to increase the
///		Card number number, and button to decrease the Card number
/// 
/// Only the button to increase the Card number, and button 
///		to decrease the Card number are interactable
/// 
/// If the interactable button was pressed then the Card
///		number is increased or decresed by 1. Card number
///		should be more than or equal to 1
///
void Brood::Application::DeckEditor::UpdateCardNumber()
{
	// chekcing if the decrease the card number was pressed
	if( m_btnDecCardNum->DoElement() )
	{
		Brood::Application::Components::Deck* activeDeckPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck();
		
		// getting current number of cards
		unsigned currentTotalCardNum = activeDeckPtr->GetCardList().size();

		// chekcing if the current currentDeckNum is 
		// equal to 1 then do nothing
		if( currentTotalCardNum == 1 )
		{
			return;
		}

		// decrease the deck number by 1 units
		activeDeckPtr->SetCardListSize( currentTotalCardNum - 1 );

		// updating the textbox showing the deck value
		m_txtCardNum->SetText( std::to_string( currentTotalCardNum - 1 ) );

		// chekcing if the currIdx is higher than max deck
		if( activeDeckPtr->GetCurrActiveCardIdx() >= currentTotalCardNum - 1 )
		{
			activeDeckPtr->SetCurrActiveCardIdx( currentTotalCardNum - 2 );
		}
	}
	// chekcing if the increase the deck number was pressed
	else if( m_btnIncCardNum->DoElement() )
	{
		Brood::Application::Components::Deck* activeDeckPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck();

		// getting current deck number
		unsigned currentTotalCardNum = activeDeckPtr->GetCardList().size();

		// increase the deck number by 1 units
		activeDeckPtr->SetCardListSize( currentTotalCardNum + 1 );

		// updating the textbox showing the deck value
		m_txtCardNum->SetText( std::to_string( currentTotalCardNum + 1 ) );
	}
}


// ======================================================================
// ================= end of DeckEditor class ============================
// ======================================================================
