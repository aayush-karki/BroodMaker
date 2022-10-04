/*************************************************************************/
/// 
/// @file GameEditor.cpp 
/// 
/// @brief  This file is a source file for GameEditor class
/// 
/// It also contains all of the declaration of the GameEditor class's
///		member function.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "GameEditor.h"


// ======================================================================
// ================= start of EditorWorkspace class =====================
// ======================================================================

/// 
/// @brief default constructor
/// 
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///  
Brood::Application::GameEditor::GameEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
{
	InitializeWorkSpace();
}

/// 
/// @brief  default destructor
/// 
Brood::Application::GameEditor::~GameEditor()
{}

/// 
/// @public
/// @virtual
/// @brief Initializes the work space
/// 
/// It creates all the component of the workspace. It initializes 
///		the EditMOde tabs and the editor workspaces
//
void Brood::Application::GameEditor::InitializeWorkSpace()
{
	// creating the setting title
	m_txtSettingTitle = DyCreateTextBox( { m_panelBodyPtr->getSize().x, 40 },
										 { m_panelBodyPtr->getPosition().x, 50 }, "General Game Settings" );
	m_txtSettingTitle->SetFontSize( 18 );

	// creating a panel element to enter a game title
	DyCreateTextInputPannelElement( m_panelBodyPtr, &m_txtGameNamePrompt, &m_txtGameInput,
									"Game Title", "", "fun game", true );

	// initializing the UI to set the movement type
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtMovementTypePromt, &m_ddiMovementType,
										"Movement Type: ",
										{ "Star Dice then Card", "Dice Only", "Card Only" }, 19 );

	// initializing the UI to set the incorrect penalty
	DyCreateDropdownInputPannelElement( m_panelBodyPtr, &m_txtIncorectPenaltyPromt, &m_ddiIncorectPenalty,
										"Incorrect Penalty: ", { "Yes", "No" }, 27 );

	// initializing the UI to control minimum number of player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerMinNumPrompt, &m_btnPlayerDecMinNum,
								 &m_txtPlayerMinNum, &m_btnPlayerIncMinNum,
								 "Minimum Players",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetMinPlayer() ) );

	// initializing the UI to control maximum number of player
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtPlayerMaxNumPrompt, &m_btnPlayerDecMaxnNum,
								 &m_txtPlayerMaxNum, &m_btnPlayerIncMaxNum,
								 "Maximum Players",
								 std::to_string( ( int )m_gameData->GetPlayerManagerPtr()->GetMaxPlayer() ) );

	// initializing the UI to control number of deck
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckNumPrompt, &m_btnDeckDecNum,
								 &m_txtDeckNum, &m_btnDeckIncNum,
								 "Deck Number",
								 std::to_string( ( int )m_gameData->GetDeckManagerPtr()->GetDeckList().size() ) );

	// initializing the  m_titleScreenBtn
	m_titleScreenBtn = DyCreateButton( { 550, 550 }, { 10, 150 }, "Game Name" );
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::GameEditor::Update()
{
	// checking to see if the enter game title Element
	// was pressed
	UpdateGameTitleInput();

	// checking to see if the movement type panel Element
	// was pressed
	UpdateMovementTypePanelElement();

	// checking to see if the incorrect penalty panel 
	// Element was pressed
	UpdateIncorrectPenaltyPanelElement();

	// checking to see if the minimum Player number panel
	// element was pressed
	UpdateMinimumPlayerNumber();

	// checking to see if the maximum Player number panel
	// element was pressed
	UpdateMaximumPlayerNumber();

	// checking to see if the deck number panel
	// element was pressed
	UpdateDeckNumber();

}

/// 
/// @public
/// @virtual
/// @brief updates the display element
///
void Brood::Application::GameEditor::UpdateAllDispayElement()
{
	// game title
	m_titleScreenBtn->SetText( m_gameData->GetGameTitle().empty() ? "Game Title" : m_gameData->GetGameTitle() );

	// movement type
	unsigned itemIdx = ( int )m_gameData->GetDeckManagerPtr()->GetMovementType();
	std::string itemName = m_ddiMovementType->GetItemList().at( itemIdx )->GetText();
	m_ddiMovementType->SetText( itemName );

	// incorrect penalty
	itemIdx = !m_gameData->GetDeckManagerPtr()->GetIncorrectPenalty();
	itemName = m_ddiIncorectPenalty->GetItemList().at( itemIdx )->GetText();
	while( itemName.size() < 27 )
	{
		itemName = " " + itemName + " ";
	}

	// we know the size of the elemnt
	m_ddiIncorectPenalty->SetText( itemName + " v" );

	// minimum player
	m_txtPlayerMinNum->SetText( std::to_string( m_gameData->GetPlayerManagerPtr()->GetMinPlayer() ) );

	// maximum player
	m_txtPlayerMaxNum->SetText( std::to_string( m_gameData->GetPlayerManagerPtr()->GetMaxPlayer() ) );

	// nubmer of deck
	m_txtDeckNum->SetText( std::to_string( m_gameData->GetDeckManagerPtr()->GetDeckList().size() ) );
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::GameEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing the title screen
	m_titleScreenBtn->Draw( a_window );

	// drawing the ui in the list
	Brood::Application::WorkSpace::Draw( a_window );

}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::GameEditor::Debugger()
{
	Brood::Application::WorkSpace::Debugger();
}

/// 
/// @private
/// @brief checks if the user interacted with the set Game Title name 
///		panel
///	
/// Game tiel panel contains game title promt textbox, 
///		and textbox to enter the game title.
/// 
/// Only the textbox to enter the game title is interactable
/// 
/// If the interactable textbox was pressed then it allows the
///		player to set the game title
/// 
/// 
void Brood::Application::GameEditor::UpdateGameTitleInput()
{
	m_txtGameInput->DoElement();

	// check if game title textbox was de selected then save 
	// the name to the title screen
	if( m_txtGameInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() )
	{
		m_titleScreenBtn->SetText( m_txtGameInput->GetText() );

		m_gameData->SetGameTitle( m_txtGameInput->GetText() );

		// resetting the m_eterPressed
		m_txtGameInput->SetEnterPressedFalse();

		// TODO change the folder name 
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the movement type panel
///	
///  Movement type panel contains Board  movement type promt textbox, 
///		and drop down input to select a movement type
/// 
/// Only the drop down input to select the movement type is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the three option avialble  dice, start with dice and then 
///		card, and card no dice
/// 
void Brood::Application::GameEditor::UpdateMovementTypePanelElement()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiMovementType->DoElement() || m_ddiMovementType->IsSelected() )
	{
		auto itemList = m_ddiMovementType->GetItemList();
		unsigned itemIdx = 0;
		bool itemPressed = false;
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( itemIdx; itemIdx < itemList.size(); ++itemIdx )
			{
				itemPressed = itemList.at( itemIdx )->DoElement();
				if( itemPressed )
				{
					break;
				}
			}

			if( itemPressed )
			{
				// setting the elements name as the item's name
				// this is important so that the changes can be reflected in the
				// title

				std::string itemName = itemList.at( itemIdx )->GetText();

				while( itemName.size() < 19 )
				{
					itemName = " " + itemName + " ";
				}

				// we know the size of the elemnt
				m_ddiMovementType->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;

				m_gameData->GetDeckManagerPtr()->SetMovementType( static_cast< Brood::Application::Components::ENUM_MovementType >( itemIdx ) );
			}
		}
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the incorrect penalty panel
///	
///  Incorrect penalty panel contains Board incorrect penalty promt textbox, 
///		and drop down input to select a yes or no for incorrect penalty
/// 
/// Only the drop down input to select the incorrect penalty is interactable
/// 
/// If the interactable  drop down input was pressed then it expand to 
///		show the two option avialble  Yes and No
///
void Brood::Application::GameEditor::UpdateIncorrectPenaltyPanelElement()
{
	//checking if the logics of the element is to be executed or not
	if( m_ddiIncorectPenalty->DoElement() || m_ddiIncorectPenalty->IsSelected() )
	{
		auto itemList = m_ddiIncorectPenalty->GetItemList();
		unsigned itemIdx = 0;
		bool itemPressed = false;
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( itemIdx; itemIdx < itemList.size(); ++itemIdx )
			{
				itemPressed = itemList.at( itemIdx )->DoElement();
				if( itemPressed )
				{
					break;
				}
			}

			if( itemPressed )
			{
				// setting the elements name as the item's name
				// this is important so that the changes can be reflected in the
				// title

				std::string itemName = itemList.at( itemIdx )->GetText();

				while( itemName.size() < 27 )
				{
					itemName = " " + itemName + " ";
				}

				// we know the size of the elemnt
				m_ddiIncorectPenalty->SetText( itemName + " v" );

				// executing the function
				std::cerr << "item at " << itemIdx << "  Pressed with ID " <<
					itemList.at( itemIdx )->GetText() << std::endl;

				m_gameData->GetDeckManagerPtr()->SetIncorrectPenalty( !itemIdx );
			}
		}
	}
}


/// 
/// @private
/// @brief checks if the user interacted with the minumum player panel
///	
/// Minumum player panel contains minimum player number promt textbox, 
///		minimum player number value text box, button to increase the
///		minimum player number, and button to decrease the minimum 
///		player number
/// 
/// Only the button to increase the minimum player number, and button 
///		to decrease the minimum player number are interactable
/// 
/// If the interactable button was pressed then the minimum player
///		number is increased or decresed by 1. Minimum player number
///		should be more than or equal to 0 but less than Maximum player
///		number
///
void Brood::Application::GameEditor::UpdateMinimumPlayerNumber()
{
	// chekcing if the decrease the minimum player number was pressed
	if( m_btnPlayerDecMinNum->DoElement() )
	{
		// getting current minimum Player number
		unsigned currentMinPlayerNum = m_gameData->GetPlayerManagerPtr()->GetMinPlayer();

		// chekcing if the current currentMinPlayerNum is 0 then do nothing
		if( currentMinPlayerNum == 0 )
		{
			return;
		}

		// decrease the minimum player number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetMinPlayer( currentMinPlayerNum - 1 );

		// updating the textbox showing the minimum player value
		m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum - 1 ) );
	}
	// chekcing if the increase the minimum player number was pressed
	else if( m_btnPlayerIncMinNum->DoElement() )
	{
		// chekcing if the decrease the minimum player number was pressed
		unsigned currentMinPlayerNum = m_gameData->GetPlayerManagerPtr()->GetMinPlayer();

		// chekcing if the current minimum player number is 
		// equal to current deck number the do nothing
		if( currentMinPlayerNum == m_gameData->GetPlayerManagerPtr()->GetMaxPlayer() )
		{
			return;
		}

		// decrease the minimum player number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetMinPlayer( currentMinPlayerNum + 1 );

		// updating the textbox showing the minimum player value
		m_txtPlayerMinNum->SetText( std::to_string( currentMinPlayerNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the deck panel
///	
/// Minumum player panel contains deck number promt textbox, 
///		deck number value text box, button to increase the
///		deck number, and button to decrease the maximum 
///		player number
/// 
/// Only the button to increase the deck number, and button 
///		to decrease the deck number are interactable
/// 
/// If the interactable button was pressed then the deck
///		number is increased or decresed by 1. Maximum player number
///		should be more than or equal to minimum player number
///		but less than 10
///
void Brood::Application::GameEditor::UpdateMaximumPlayerNumber()
{
	// chekcing if the decrease the deck number was pressed
	if( m_btnPlayerDecMaxnNum->DoElement() )
	{
		// getting current maximum Player number
		unsigned currentMaxPlayerNum = m_gameData->GetPlayerManagerPtr()->GetMaxPlayer();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to currentMinPlayerNum then do nothing
		if( currentMaxPlayerNum == m_gameData->GetPlayerManagerPtr()->GetMinPlayer() )
		{
			return;
		}

		// decrease the deck number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetMaxPlayer( currentMaxPlayerNum - 1 );

		// updating the textbox showing the deck value
		m_txtPlayerMaxNum->SetText( std::to_string( currentMaxPlayerNum - 1 ) );

		// chekcing if the currIdx is higher than max player
		if( m_gameData->GetPlayerManagerPtr()->GetCurrActivePlayerIdx() >= currentMaxPlayerNum - 1 )
		{
			m_gameData->GetPlayerManagerPtr()->SetCurrActivePlayerIdx( currentMaxPlayerNum - 2 );
		}
	}
	// chekcing if the increase the deck number was pressed
	else if( m_btnPlayerIncMaxNum->DoElement() )
	{
		// getting current maximum Player number
		unsigned currentMaxPlayerNum = m_gameData->GetPlayerManagerPtr()->GetMaxPlayer();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to 10 then do nothing
		if( currentMaxPlayerNum == 10 )
		{
			return;
		}

		// decrease the deck number by 1 units
		m_gameData->GetPlayerManagerPtr()->SetMaxPlayer( currentMaxPlayerNum + 1 );

		// updating the textbox showing the deck value
		m_txtPlayerMaxNum->SetText( std::to_string( currentMaxPlayerNum + 1 ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the deck number panel
///	
/// Deck number panel contains deck number promt textbox, 
///		deck number number value text box, button to increase the
///		deck number number, and button to decrease the deck number
/// 
/// Only the button to increase the deck number, and button 
///		to decrease the deck number are interactable
/// 
/// If the interactable button was pressed then the deck
///		number is increased or decresed by 1. deck number
///		should be more than or equal to 1
///		but less than 10
///
void Brood::Application::GameEditor::UpdateDeckNumber()
{
	// chekcing if the decrease the deck number was pressed
	if( m_btnDeckDecNum->DoElement() )
	{
		// getting current deck number
		unsigned currentDeckNum = m_gameData->GetDeckManagerPtr()->GetDeckList().size();

		// chekcing if the current currentDeckNum is 
		// equal to 1 then do nothing
		if( currentDeckNum == 1 )
		{
			return;
		}

		// decrease the deck number by 1 units
		m_gameData->GetDeckManagerPtr()->SetDeckSize( currentDeckNum - 1 );

		// updating the textbox showing the deck value
		m_txtDeckNum->SetText( std::to_string( currentDeckNum - 1 ) );

		// chekcing if the currIdx is higher than max deck
		if( m_gameData->GetDeckManagerPtr()->GetCurrActiveDeckIdx() >= currentDeckNum - 1 )
		{
			m_gameData->GetDeckManagerPtr()->SetCurrActiveDeckIdx( currentDeckNum - 2 );
		}
	}
	// chekcing if the increase the deck number was pressed
	else if( m_btnDeckIncNum->DoElement() )
	{
		// getting current deck number
		unsigned currentDeckNum = m_gameData->GetDeckManagerPtr()->GetDeckList().size();

		// chekcing if the current currentMaxPlayerNum id 
		// equal to 10 then do nothing
		if( currentDeckNum == 10 )
		{
			return;
		}

		// decrease the deck number by 1 units
		m_gameData->GetDeckManagerPtr()->SetDeckSize( currentDeckNum + 1 );

		// updating the textbox showing the deck value
		m_txtDeckNum->SetText( std::to_string( currentDeckNum + 1 ) );
	}
}