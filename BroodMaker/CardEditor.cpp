/*************************************************************************/
/// 
/// @file CardEditor.cpp 
/// 
/// @brief  This file is a source file for CardEditor class.
/// 
/// It contains all of the defination of the member 
///		funciton of CardEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "CardEditor.h"

// ======================================================================
// ================= start of CardEditor class =========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
/// @param a_gameData pointer to the game data object
/// @param a_panelPtr pointer to the panel body object
///
Brood::Application::CardEditor::CardEditor( Brood::Application::Components::GameDataManager* a_gameData,
											sf::RectangleShape* a_panelPtr ) :
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr ),
	m_selectedSettingIdx( 0 )
{
	InitializeWorkSpace();
}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::CardEditor::~CardEditor()
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
void Brood::Application::CardEditor::InitializeWorkSpace()
{
	// initializing the setting 
	InitailizeSettingSelectionDDI();

	// initializng the card display panel
	InializeCardDisplayPanel();

	// initializng the card display front componet panel
	InializeCardDisplayFcompPanel();

	// initializng the card display back componet panel
	InializeCardDisplayBcompPanel();

	// initializng the card info panel
	InializeCardInfoPanel();
}

/// 
/// @public
/// @virtual
/// @brief Updates function
/// 
///	Contains all the logic for the initial workspace 
///
void Brood::Application::CardEditor::Update()
{
	// upading the setting DDM
	UpdateSettingSelectionDDI();

	if( m_selectedSettingIdx == 0 )
	{
		// Update the card display panel
		UpdateCardDisplayPanel();
	}
	else if( m_selectedSettingIdx == 1 )
	{
		// Update the card display front componet panel
		UpdateCardDisplayFcompPanel();
		m_gameData->GetDisplayCardPtr()->SetCardFront( true );

	}
	else if( m_selectedSettingIdx == 2 )
	{
		// Update the card display back componet panel
		UpdateCardDisplayBcompPanel();
	}
	else
	{
		// Update the card info panel
		UpdateCardInfoPanel();
	}
}

/// 
/// @public
/// @virtual
/// @brief updates the display element
/// 
void Brood::Application::CardEditor::UpdateAllDispayElement()
{
	Brood::Application::Components::Deck* activeDeck = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck();
	
	// updating the display card
	m_gameData->GetDisplayCardPtr()->SetCardInfoToDisplay( activeDeck->GetCurrActiveCardPtr() );

	// ======================================================================
	// ========== update the panel elements in the CardDisplay Panel ========
	// ======================================================================

	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	m_txtCardSizeX->SetText( std::to_string( displayCardPtr->GetBodySize().x ) );
	m_txtCardSizeY->SetText( std::to_string( displayCardPtr->GetBodySize().y ) );

	m_txtCardPosX->SetText( std::to_string( displayCardPtr->GetBodyPosition().x ) );
	m_txtCardPosY->SetText( std::to_string( displayCardPtr->GetBodyPosition().y ) );

	m_txtCardFrontBgFileInput->SetText( displayCardPtr->GetFrontBgFileName() );
	m_txtCardBackBgFileInput->SetText( displayCardPtr->GetBackBgFileName());




	// ======================================================================
	// = update the panel elements in the CardDisplay Front component Panel =
	// ======================================================================
	
	// front time prompt
	m_txtCardFrontTimePromptSizeX->SetText( std::to_string( displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().x ) );
	m_txtCardFrontTimePromptSizeY->SetText( std::to_string( displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().y ) );

	m_txtCardFrontTimePromptPosX->SetText( std::to_string( displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().x ) );
	m_txtCardFrontTimePromptPosY->SetText( std::to_string( displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().y ) );

	// front time value
	m_txtCardFrontTimeValueSizeX->SetText( std::to_string( displayCardPtr->GetFrontTimeValuePtr()->GetBodySize().x ) );
	m_txtCardFrontTimeValueSizeY->SetText( std::to_string( displayCardPtr->GetFrontTimeValuePtr()->GetBodySize().y ) );

	m_txtCardFrontTimeValuePosX->SetText( std::to_string( displayCardPtr->GetFrontTimeValuePtr()->GetBodyPosition().x ) );
	m_txtCardFrontTimeValuePosY->SetText( std::to_string( displayCardPtr->GetFrontTimeValuePtr()->GetBodyPosition().y ) );

	// Up prompt
	m_txtCardUpPromptSizeX->SetText( std::to_string( displayCardPtr->GetUpPromptPtr()->GetBodySize().x ) );
	m_txtCardUpPromptSizeY->SetText( std::to_string( displayCardPtr->GetUpPromptPtr()->GetBodySize().y ) );

	m_txtCardUpPromptPosX->SetText( std::to_string( displayCardPtr->GetUpPromptPtr()->GetBodyPosition().x ) );
	m_txtCardUpPromptPosY->SetText( std::to_string( displayCardPtr->GetUpPromptPtr()->GetBodyPosition().y ) );

	// Up value
	m_txtCardUpValueSizeX->SetText( std::to_string( displayCardPtr->GetUpValuePtr()->GetBodySize().x ) );
	m_txtCardUpValueSizeY->SetText( std::to_string( displayCardPtr->GetUpValuePtr()->GetBodySize().y ) );

	m_txtCardUpValuePosX->SetText( std::to_string( displayCardPtr->GetUpValuePtr()->GetBodyPosition().x ) );
	m_txtCardUpValuePosY->SetText( std::to_string( displayCardPtr->GetUpValuePtr()->GetBodyPosition().y ) );

	// Down prompt
	m_txtCardDownPromptSizeX->SetText( std::to_string( displayCardPtr->GetDownPromptPtr()->GetBodySize().x ) );
	m_txtCardDownPromptSizeY->SetText( std::to_string( displayCardPtr->GetDownPromptPtr()->GetBodySize().y ) );

	m_txtCardDownPromptPosX->SetText( std::to_string( displayCardPtr->GetDownPromptPtr()->GetBodyPosition().x ) );
	m_txtCardDownPromptPosY->SetText( std::to_string( displayCardPtr->GetDownPromptPtr()->GetBodyPosition().y ) );

	// Down value
	m_txtCardDownValueSizeX->SetText( std::to_string( displayCardPtr->GetDownValuePtr()->GetBodySize().x ) );
	m_txtCardDownValueSizeY->SetText( std::to_string( displayCardPtr->GetDownValuePtr()->GetBodySize().y ) );

	m_txtCardDownValuePosX->SetText( std::to_string( displayCardPtr->GetDownValuePtr()->GetBodyPosition().x ) );
	m_txtCardDownValuePosY->SetText( std::to_string( displayCardPtr->GetDownValuePtr()->GetBodyPosition().y ) );

	// TurnCard 
	m_txtCardTurnCardSizeX->SetText( std::to_string( displayCardPtr->GetTurnCardPtr()->GetBodySize().x ) );
	m_txtCardTurnCardSizeY->SetText( std::to_string( displayCardPtr->GetTurnCardPtr()->GetBodySize().y ) );

	m_txtCardTurnCardPosX->SetText( std::to_string( displayCardPtr->GetTurnCardPtr()->GetBodyPosition().x ) );
	m_txtCardTurnCardPosY->SetText( std::to_string( displayCardPtr->GetTurnCardPtr()->GetBodyPosition().y ) );

	// ======================================================================
	// = update the panel elements in the CardDisplay back component Panel =
	// ======================================================================

	// Back time prompt
	m_txtCardBackTimePromptSizeX->SetText( std::to_string( displayCardPtr->GetBackTimePromptPtr()->GetBodySize().x ) );
	m_txtCardBackTimePromptSizeY->SetText( std::to_string( displayCardPtr->GetBackTimePromptPtr()->GetBodySize().y ) );

	m_txtCardBackTimePromptPosX->SetText( std::to_string( displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().x ) );
	m_txtCardBackTimePromptPosY->SetText( std::to_string( displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().y ) );

	// Back time value
	m_txtCardBackTimeValueSizeX->SetText( std::to_string( displayCardPtr->GetBackTimeValuePtr()->GetBodySize().x ) );
	m_txtCardBackTimeValueSizeY->SetText( std::to_string( displayCardPtr->GetBackTimeValuePtr()->GetBodySize().y ) );

	m_txtCardBackTimeValuePosX->SetText( std::to_string( displayCardPtr->GetBackTimeValuePtr()->GetBodyPosition().x ) );
	m_txtCardBackTimeValuePosY->SetText( std::to_string( displayCardPtr->GetBackTimeValuePtr()->GetBodyPosition().y ) );

	// Question prompt
	m_txtCardQuestionPromptSizeX->SetText( std::to_string( displayCardPtr->GetQuestionPromptPtr()->GetBodySize().x ) );
	m_txtCardQuestionPromptSizeY->SetText( std::to_string( displayCardPtr->GetQuestionPromptPtr()->GetBodySize().y ) );

	m_txtCardQuestionPromptPosX->SetText( std::to_string( displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().x ) );
	m_txtCardQuestionPromptPosY->SetText( std::to_string( displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().y ) );

	// Question value
	m_txtCardQuestionValueSizeX->SetText( std::to_string( displayCardPtr->GetQuestionValuePtr()->GetBodySize().x ) );
	m_txtCardQuestionValueSizeY->SetText( std::to_string( displayCardPtr->GetQuestionValuePtr()->GetBodySize().y ) );

	m_txtCardQuestionValuePosX->SetText( std::to_string( displayCardPtr->GetQuestionValuePtr()->GetBodyPosition().x ) );
	m_txtCardQuestionValuePosY->SetText( std::to_string( displayCardPtr->GetQuestionValuePtr()->GetBodyPosition().y ) );

	// Answer prompt
	m_txtCardAnswerPromptSizeX->SetText( std::to_string( displayCardPtr->GetAnswerPromptPtr()->GetBodySize().x ) );
	m_txtCardAnswerPromptSizeY->SetText( std::to_string( displayCardPtr->GetAnswerPromptPtr()->GetBodySize().y ) );

	m_txtCardAnswerPromptPosX->SetText( std::to_string( displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().x ) );
	m_txtCardAnswerPromptPosY->SetText( std::to_string( displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().y ) );

	// Answer value
	m_txtCardAnswerValueSizeX->SetText( std::to_string( displayCardPtr->GetAnswerValuePtr()->GetBodySize().x ) );
	m_txtCardAnswerValueSizeY->SetText( std::to_string( displayCardPtr->GetAnswerValuePtr()->GetBodySize().y ) );

	m_txtCardAnswerValuePosX->SetText( std::to_string( displayCardPtr->GetAnswerValuePtr()->GetBodyPosition().x ) );
	m_txtCardAnswerValuePosY->SetText( std::to_string( displayCardPtr->GetAnswerValuePtr()->GetBodyPosition().y ) );

	// Submit 
	m_txtCardSubmitSizeX->SetText( std::to_string( displayCardPtr->GetSubmitPtr()->GetBodySize().x ) );
	m_txtCardSubmitSizeY->SetText( std::to_string( displayCardPtr->GetSubmitPtr()->GetBodySize().y ) );

	m_txtCardSubmitPosX->SetText( std::to_string( displayCardPtr->GetSubmitPtr()->GetBodyPosition().x ) );
	m_txtCardSubmitPosY->SetText( std::to_string( displayCardPtr->GetSubmitPtr()->GetBodyPosition().y ) );


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
void Brood::Application::CardEditor::Draw( sf::RenderWindow& a_window )
{
	// drawing game component
	m_gameData->Draw( a_window );


	if( m_selectedSettingIdx == 0 )
	{
		// Draw the card display panel
		DrawCardDisplayPanel( a_window );
	}
	else if( m_selectedSettingIdx == 1 )
	{
		// Draw the card display front componet panel
		DrawCardDisplayFcompPanel( a_window );
	}
	else if( m_selectedSettingIdx == 2 )
	{
		// Draw the card display back componet panel
		DrawCardDisplayBcompPanel( a_window );
	}
	else
	{
		// Draw the card info panel
		DrawCardInfoPanel( a_window );
	}

	m_gameData->GetDisplayCardPtr()->Draw( a_window );

	// Drawing the setting selection drop down input
	m_ddiSettingSelection->Draw( a_window );
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::CardEditor::Debugger()
{
	// base class calls the unnamedUIList 
	Brood::Application::WorkSpace::Debugger();
}


/// 
/// @private
/// @brief Initializes the  setting Section dropdown input which is
///		at the top of the setting pannel
/// 
/// It has the 4 settings :
///		Display card Setting, 
///		Display card front componet Setting,
///		Display card back componet Setting
///		Existing info Card Setting
///
void Brood::Application::CardEditor::InitailizeSettingSelectionDDI()
{
	// initializing the setting selection DDI
	float panelSizeX = m_panelBodyPtr->getSize().x;
	float panelPosX = m_panelBodyPtr->getPosition().x;

	m_ddiSettingSelection = DyCreateDropDownInput( { panelSizeX , 40 },
												   { panelPosX, 50 },
												   Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor );

	m_ddiSettingSelection->AddItemToMenu( "Display card Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Display card f.component Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Display card b.component Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Existing Card Setting" );

	// setting the font size to 18
	m_ddiSettingSelection->SetFontSize( 18 );

	// setting the first item as the first 
	std::string itemName = m_ddiSettingSelection->GetItemList().at( m_selectedSettingIdx )->GetText();

	while( itemName.size() < 33 )
	{
		itemName = " " + itemName + " ";
	}

	m_ddiSettingSelection->SetText( itemName + " v" );
}

/// 
/// @private
/// @brief checks if the user interacted with setting Selection and
///		updates accordingly
/// 
void Brood::Application::CardEditor::UpdateSettingSelectionDDI()
{
	if( m_ddiSettingSelection->DoElement() )
	{
		std::cout << "myDropDownInput Pressed" << std::endl;
	}

	if( m_ddiSettingSelection->IsSelected() )
	{
		auto itemList = m_ddiSettingSelection->GetItemList();
		if( !itemList.empty() )
		{
			// checking if the logics of the items is to be executed or not
			for( int currIDx = 0; currIDx < itemList.size(); ++currIDx )
			{
				if( itemList.at( currIDx )->DoElement() )
				{
					// setting the elements name as the item's name
					// this is important so that the changes can be reflected in the
					// title
					// setting the first item as the first 
					std::string itemName = m_ddiSettingSelection->GetItemList().at( currIDx )->GetText();

					while( itemName.size() < 33 )
					{
						itemName = "     " + itemName + "     ";
					}

					m_ddiSettingSelection->SetText( itemName + "  v" );

					// executing the function
					std::cerr << "item at " << currIDx << "  Pressed with ID " <<
						itemList.at( currIDx )->GetText() << std::endl;

					m_selectedSettingIdx = currIDx;

					if( currIDx == 1 )
					{
						m_gameData->GetDisplayCardPtr()->SetCardFront( true );
					}
					else if( currIDx == 2 )
					{
						m_gameData->GetDisplayCardPtr()->SetCardFront( false );
					}
				}
			}
		}
	}
}

/// 
/// @private
/// @brief Initializes the panel element of the Card Display setting 
/// 
/// It initializes the folloing panel element: 
///		card X-position, card Y-position, card X-size, card Y-Size, 
///		CardFrontBg filename textur, CardFrontBg filename textur
///
void Brood::Application::CardEditor::InializeCardDisplayPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	// creating a panel element to control the card sizeX
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSizeXPrompt, &m_btnCardDecSizeX,
								 &m_txtCardSizeX, &m_btnCardIncSizeX,
								 "Card X Size",
								 std::to_string( ( int )displayCardPtr->GetBodySize().x ), true );

	// creating a panel element to control the card sizeY
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSizeYPrompt, &m_btnCardDecSizeY,
								 &m_txtCardSizeY, &m_btnCardIncSizeY,
								 "Card Y Size",
								 std::to_string( ( int )displayCardPtr->GetBodySize().y ) );

	// creating a panel element to control the card Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardPosXPrompt, &m_btnCardDecPosX,
								 &m_txtCardPosX, &m_btnCardIncPosX,
								 "Card X Pos",
								 std::to_string( ( int )displayCardPtr->GetBodyPosition().x ) );

	// creating a panel element to control the card Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardPosYPrompt, &m_btnCardDecPosY,
								 &m_txtCardPosY, &m_btnCardIncPosY,
								 "Card Y Pos",
								 std::to_string( ( int )displayCardPtr->GetBodyPosition().y ) );

	// initializing the UI to control deck card front bg file name
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtCardFrontBgFileNamePrompt, &m_txtCardFrontBgFileInput,
									&m_btnCardFrontBgOpenFile, "Card Front Bg Filename",
									displayCardPtr->GetFrontBgFileName() );

	// initializing the UI to control deck card Back bg file name
	// texture panel Elements
	DyCreateFileInputPannelElement( m_panelBodyPtr, &m_txtCardBackBgFileNamePrompt, &m_txtCardBackBgFileInput,
									&m_btnCardBackBgOpenFile, "Card Back Bg Filename",
									displayCardPtr->GetBackBgFileName() );
}

/// 
/// @private
/// @brief Updates the panel element of the Card Display setting 
/// 
/// It Updates the folloing panel element: 
///		card X-position, card Y-position, card X-size, card Y-Size, 
///		CardFrontBg filename textur, CardFrontBg filename textur
///
/// TODO make it so that when the display card pos changes the 
///		pos of it component also changed
/// 
void Brood::Application::CardEditor::UpdateCardDisplayPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	// checks if the user interacted with the Card 
	// x size panel Element
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
	float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;

	UpdateDecIncSizeX( m_btnCardDecSizeX, m_txtCardSizeX, m_btnCardIncSizeX,
					   displayCardPtr, 5, 0, boardWindowWidth );

	// checks if the user interacted with the Card 
	// x size panel Element
	uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
	UpdateDecIncSizeY( m_btnCardDecSizeY, m_txtCardSizeY, m_btnCardIncSizeY,
					   displayCardPtr, 5, 0, windowHieght );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	//UpdateCardPosX();
	UpdateDecIncPosX( m_btnCardDecPosX, m_txtCardPosX, m_btnCardIncPosX,
					  displayCardPtr, 5, 0, boardWindowWidth );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	//UpdateCardPosY();
	UpdateDecIncPosY( m_btnCardDecPosY, m_txtCardPosY, m_btnCardIncPosY,
					  displayCardPtr, 5, 90, windowHieght );

	// checks if the user interacted with the load 
	// Card texture panel Element
	UpdateCardFrontFileTexture();

	// checks if the user interacted with the load 
	// Card texture panel Element
	UpdateCardBackFileTexture();

}

/// 
/// @private
/// @brief Draws the panel element of the Card Display setting 
/// 
/// It draws the folloing panel element: 
///		card X-position, card Y-position, card X-size, card Y-Size, 
///		CardFrontBg filename textur, CardFrontBg filename textur
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::CardEditor::DrawCardDisplayPanel( sf::RenderWindow& a_window )
{
	// CardBackBg filename textur 
	m_btnCardBackBgOpenFile->Draw( a_window );
	m_txtCardBackBgFileInput->Draw( a_window );
	m_txtCardBackBgFileNamePrompt->Draw( a_window );

	// CardFrontBg filename textur 
	m_btnCardFrontBgOpenFile->Draw( a_window );
	m_txtCardFrontBgFileInput->Draw( a_window );
	m_txtCardFrontBgFileNamePrompt->Draw( a_window );

	// Card Position y
	m_btnCardIncPosY->Draw( a_window );
	m_txtCardPosY->Draw( a_window );
	m_btnCardDecPosY->Draw( a_window );
	m_txtCardPosYPrompt->Draw( a_window );

	// Card Position X
	m_btnCardIncPosX->Draw( a_window );
	m_txtCardPosX->Draw( a_window );
	m_btnCardDecPosX->Draw( a_window );
	m_txtCardPosXPrompt->Draw( a_window );

	// Card size y
	m_btnCardIncSizeY->Draw( a_window );
	m_txtCardSizeY->Draw( a_window );
	m_btnCardDecSizeY->Draw( a_window );
	m_txtCardSizeYPrompt->Draw( a_window );

	// Card size X
	m_btnCardIncSizeX->Draw( a_window );
	m_txtCardSizeX->Draw( a_window );
	m_btnCardDecSizeX->Draw( a_window );
	m_txtCardSizeXPrompt->Draw( a_window );
}

/// 
/// @private
/// @brief Initializes the panel element of the Card Display 
///		front component setting 
/// 
/// It initializes the folloing panel element: 
///		card front time prompt X-position, 
///		card front time prompt Y-position,
///		card front time value X-position, 
///		card front time value Y-position,
///		card up prompt X-position, 
///		card up prompt Y-position,
///		card up value X-position, 
///		card up value Y-position,
///		card down prompt X-position, 
///		card down prompt Y-position,
///		card down value X-position, 
///		card down value Y-position,
///		card turn card X-position, 
///		card turn card Y-position
///		card front time prompt X-size, 
///		card front time prompt Y-size,
///		card front time value X-size, 
///		card front time value Y-size,
///		card up prompt X-size, 
///		card up prompt Y-size,
///		card up value X-size, 
///		card up value Y-size,
///		card down prompt X-size, 
///		card down prompt Y-size,
///		card down value X-size, 
///		card down value Y-size,
///		card turn card X-size, 
///		card turn card Y-size
///
void Brood::Application::CardEditor::InializeCardDisplayFcompPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	// creating a panel element to control the CardFrontTimePrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimePromptPosXPrompt, &m_btnCardFrontTimePromptDecPosX,
								 &m_txtCardFrontTimePromptPosX, &m_btnCardFrontTimePromptIncPosX,
								 "Front Time Pmt X Pos",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().x ), true );

	// creating a panel element to control the CardFrontTimePrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimePromptPosYPrompt, &m_btnCardFrontTimePromptDecPosY,
								 &m_txtCardFrontTimePromptPosY, &m_btnCardFrontTimePromptIncPosY,
								 "Front Time Pmt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardFrontTimeValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimeValuePosXPrompt, &m_btnCardFrontTimeValueDecPosX,
								 &m_txtCardFrontTimeValuePosX, &m_btnCardFrontTimeValueIncPosX,
								 "Front Time Val X Pos",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardFrontTimeValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimeValuePosYPrompt, &m_btnCardFrontTimeValueDecPosY,
								 &m_txtCardFrontTimeValuePosY, &m_btnCardFrontTimeValueIncPosY,
								 "Front Time Val Y Pos",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardUpPrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpPromptPosXPrompt, &m_btnCardUpPromptDecPosX,
								 &m_txtCardUpPromptPosX, &m_btnCardUpPromptIncPosX,
								 "Up Prompt X Pos",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardUpPrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpPromptPosYPrompt, &m_btnCardUpPromptDecPosY,
								 &m_txtCardUpPromptPosY, &m_btnCardUpPromptIncPosY,
								 "Up Prompt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardUpValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpValuePosXPrompt, &m_btnCardUpValueDecPosX,
								 &m_txtCardUpValuePosX, &m_btnCardUpValueIncPosX,
								 "Up Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardUpValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpValuePosYPrompt, &m_btnCardUpValueDecPosY,
								 &m_txtCardUpValuePosY, &m_btnCardUpValueIncPosY,
								 "Up Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardDownPrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownPromptPosXPrompt, &m_btnCardDownPromptDecPosX,
								 &m_txtCardDownPromptPosX, &m_btnCardDownPromptIncPosX,
								 "Down Prompt X Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardDownPrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownPromptPosYPrompt, &m_btnCardDownPromptDecPosY,
								 &m_txtCardDownPromptPosY, &m_btnCardDownPromptIncPosY,
								 "Down Prompt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardDownValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownValuePosXPrompt, &m_btnCardDownValueDecPosX,
								 &m_txtCardDownValuePosX, &m_btnCardDownValueIncPosX,
								 "Down Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardDownValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownValuePosYPrompt, &m_btnCardDownValueDecPosY,
								 &m_txtCardDownValuePosY, &m_btnCardDownValueIncPosY,
								 "Down Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardTurnCard Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardTurnCardPosXPrompt, &m_btnCardTurnCardDecPosX,
								 &m_txtCardTurnCardPosX, &m_btnCardTurnCardIncPosX,
								 "Turn Card X Pos",
								 std::to_string( ( int )displayCardPtr->GetTurnCardPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardTurnCard Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardTurnCardPosYPrompt, &m_btnCardTurnCardDecPosY,
								 &m_txtCardTurnCardPosY, &m_btnCardTurnCardIncPosY,
								 "Turn Card Y Pos",
								 std::to_string( ( int )displayCardPtr->GetTurnCardPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardFrontTimePrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimePromptSizeXPrompt, &m_btnCardFrontTimePromptDecSizeX,
								 &m_txtCardFrontTimePromptSizeX, &m_btnCardFrontTimePromptIncSizeX,
								 "Front Time Pmt X Size",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardFrontTimePrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimePromptSizeYPrompt, &m_btnCardFrontTimePromptDecSizeY,
								 &m_txtCardFrontTimePromptSizeY, &m_btnCardFrontTimePromptIncSizeY,
								 "Front Time Pmt Y Size",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardFrontTimeValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimeValueSizeXPrompt, &m_btnCardFrontTimeValueDecSizeX,
								 &m_txtCardFrontTimeValueSizeX, &m_btnCardFrontTimeValueIncSizeX,
								 "Front Time Val X Size",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardFrontTimeValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardFrontTimeValueSizeYPrompt, &m_btnCardFrontTimeValueDecSizeY,
								 &m_txtCardFrontTimeValueSizeY, &m_btnCardFrontTimeValueIncSizeY,
								 "Front Time Val Y Size",
								 std::to_string( ( int )displayCardPtr->GetFrontTimePromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardUpPrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpPromptSizeXPrompt, &m_btnCardUpPromptDecSizeX,
								 &m_txtCardUpPromptSizeX, &m_btnCardUpPromptIncSizeX,
								 "Up Prompt X Size",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardUpPrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpPromptSizeYPrompt, &m_btnCardUpPromptDecSizeY,
								 &m_txtCardUpPromptSizeY, &m_btnCardUpPromptIncSizeY,
								 "Up Prompt Y Size",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardUpValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpValueSizeXPrompt, &m_btnCardUpValueDecSizeX,
								 &m_txtCardUpValueSizeX, &m_btnCardUpValueIncSizeX,
								 "Up Value X Size",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardUpValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardUpValueSizeYPrompt, &m_btnCardUpValueDecSizeY,
								 &m_txtCardUpValueSizeY, &m_btnCardUpValueIncSizeY,
								 "Up Value Y Size",
								 std::to_string( ( int )displayCardPtr->GetUpPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardDownPrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownPromptSizeXPrompt, &m_btnCardDownPromptDecSizeX,
								 &m_txtCardDownPromptSizeX, &m_btnCardDownPromptIncSizeX,
								 "Down Prompt X Size",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardDownPrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownPromptSizeYPrompt, &m_btnCardDownPromptDecSizeY,
								 &m_txtCardDownPromptSizeY, &m_btnCardDownPromptIncSizeY,
								 "Down Prompt Y Size",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardDownValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownValueSizeXPrompt, &m_btnCardDownValueDecSizeX,
								 &m_txtCardDownValueSizeX, &m_btnCardDownValueIncSizeX,
								 "Down Value X Size",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardDownValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardDownValueSizeYPrompt, &m_btnCardDownValueDecSizeY,
								 &m_txtCardDownValueSizeY, &m_btnCardDownValueIncSizeY,
								 "Down Value Y Size",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardTurnCard Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardTurnCardSizeXPrompt, &m_btnCardTurnCardDecSizeX,
								 &m_txtCardTurnCardSizeX, &m_btnCardTurnCardIncSizeX,
								 "Turn Card X Size",
								 std::to_string( ( int )displayCardPtr->GetTurnCardPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardTurnCard Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardTurnCardSizeYPrompt, &m_btnCardTurnCardDecSizeY,
								 &m_txtCardTurnCardSizeY, &m_btnCardTurnCardIncSizeY,
								 "Turn Card Y Size",
								 std::to_string( ( int )displayCardPtr->GetTurnCardPtr()->GetBodySize().y ) );

}

/// 
/// @private
/// @brief Updates the panel element of the Card Display 
///		front component setting 
/// 
/// It Updates the folloing panel element: 
///		card front time prompt X-position, 
///		card front time prompt Y-position,
///		card front time value X-position, 
///		card front time value Y-position,
///		card up prompt X-position, 
///		card up prompt Y-position,
///		card up value X-position, 
///		card up value Y-position,
///		card down prompt X-position, 
///		card down prompt Y-position,
///		card down value X-position, 
///		card down value Y-position,
///		card turn card X-position, 
///		card turn card Y-position
///		card front time prompt X-size, 
///		card front time prompt Y-size,
///		card front time value X-size, 
///		card front time value Y-size,
///		card up prompt X-size, 
///		card up prompt Y-size,
///		card up value X-size, 
///		card up value Y-size,
///		card down prompt X-size, 
///		card down prompt Y-size,
///		card down value X-size, 
///		card down value Y-size,
///		card turn card X-size, 
///		card turn card Y-size
/// 
/// TODO make it so that card component are bound inside
/// 
void Brood::Application::CardEditor::UpdateCardDisplayFcompPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();
	unsigned displayCardLowerLimitX = displayCardPtr->GetBodyPosition().x;
	unsigned displayCardPosUpperLimitX = displayCardPtr->GetBodyPosition().x + displayCardPtr->GetBodySize().x;

	unsigned displayCardLowerLimitY = displayCardPtr->GetBodyPosition().y;
	unsigned displayCardPosUpperLimitY = displayCardPtr->GetBodyPosition().y + displayCardPtr->GetBodySize().y;

	// checks if the user interacted with the CardFrontTimePrompt 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardFrontTimePromptDecPosX, m_txtCardFrontTimePromptPosX, m_btnCardFrontTimePromptIncPosX,
					  displayCardPtr->GetFrontTimePromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardFrontTimePrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardFrontTimePromptDecPosY, m_txtCardFrontTimePromptPosY, m_btnCardFrontTimePromptIncPosY,
					  displayCardPtr->GetFrontTimePromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardFrontTimeValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardFrontTimeValueDecPosX, m_txtCardFrontTimeValuePosX, m_btnCardFrontTimeValueIncPosX,
					  displayCardPtr->GetFrontTimeValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardFrontTimeValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardFrontTimeValueDecPosY, m_txtCardFrontTimeValuePosY, m_btnCardFrontTimeValueIncPosY,
					  displayCardPtr->GetFrontTimeValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardUpPrompt 
		// x Pos panel Element
	UpdateDecIncPosX( m_btnCardUpPromptDecPosX, m_txtCardUpPromptPosX, m_btnCardUpPromptIncPosX,
					  displayCardPtr->GetUpPromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardUpPrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardUpPromptDecPosY, m_txtCardUpPromptPosY, m_btnCardUpPromptIncPosY,
					  displayCardPtr->GetUpPromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardUpValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardUpValueDecPosX, m_txtCardUpValuePosX, m_btnCardUpValueIncPosX,
					  displayCardPtr->GetUpValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardUpValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardUpValueDecPosY, m_txtCardUpValuePosY, m_btnCardUpValueIncPosY,
					  displayCardPtr->GetUpValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardDownPrompt 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardDownPromptDecPosX, m_txtCardDownPromptPosX, m_btnCardDownPromptIncPosX,
					  displayCardPtr->GetDownPromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardDownPrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardDownPromptDecPosY, m_txtCardDownPromptPosY, m_btnCardDownPromptIncPosY,
					  displayCardPtr->GetDownPromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardDownValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardDownValueDecPosX, m_txtCardDownValuePosX, m_btnCardDownValueIncPosX,
					  displayCardPtr->GetDownValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardDownValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardDownValueDecPosY, m_txtCardDownValuePosY, m_btnCardDownValueIncPosY,
					  displayCardPtr->GetDownValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardTurnCard 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardTurnCardDecPosX, m_txtCardTurnCardPosX, m_btnCardTurnCardIncPosX,
					  displayCardPtr->GetTurnCardPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardTurnCard 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardTurnCardDecPosY, m_txtCardTurnCardPosY, m_btnCardTurnCardIncPosY,
					  displayCardPtr->GetTurnCardPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardFrontTimePrompt 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardFrontTimePromptDecSizeX, m_txtCardFrontTimePromptSizeX, m_btnCardFrontTimePromptIncSizeX,
					   displayCardPtr->GetFrontTimePromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardFrontTimePrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardFrontTimePromptDecSizeY, m_txtCardFrontTimePromptSizeY, m_btnCardFrontTimePromptIncSizeY,
					   displayCardPtr->GetFrontTimePromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardFrontTimeValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardFrontTimeValueDecSizeX, m_txtCardFrontTimeValueSizeX, m_btnCardFrontTimeValueIncSizeX,
					   displayCardPtr->GetFrontTimeValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardFrontTimeValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardFrontTimeValueDecSizeY, m_txtCardFrontTimeValueSizeY, m_btnCardFrontTimeValueIncSizeY,
					   displayCardPtr->GetFrontTimeValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardUpPrompt 
		// x Size panel Element
	UpdateDecIncSizeX( m_btnCardUpPromptDecSizeX, m_txtCardUpPromptSizeX, m_btnCardUpPromptIncSizeX,
					   displayCardPtr->GetUpPromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardUpPrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardUpPromptDecSizeY, m_txtCardUpPromptSizeY, m_btnCardUpPromptIncSizeY,
					   displayCardPtr->GetUpPromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardUpValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardUpValueDecSizeX, m_txtCardUpValueSizeX, m_btnCardUpValueIncSizeX,
					   displayCardPtr->GetUpValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardUpValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardUpValueDecSizeY, m_txtCardUpValueSizeY, m_btnCardUpValueIncSizeY,
					   displayCardPtr->GetUpValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardDownPrompt 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardDownPromptDecSizeX, m_txtCardDownPromptSizeX, m_btnCardDownPromptIncSizeX,
					   displayCardPtr->GetDownPromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardDownPrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardDownPromptDecSizeY, m_txtCardDownPromptSizeY, m_btnCardDownPromptIncSizeY,
					   displayCardPtr->GetDownPromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardDownValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardDownValueDecSizeX, m_txtCardDownValueSizeX, m_btnCardDownValueIncSizeX,
					   displayCardPtr->GetDownValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardDownValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardDownValueDecSizeY, m_txtCardDownValueSizeY, m_btnCardDownValueIncSizeY,
					   displayCardPtr->GetDownValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardTurnCard 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardTurnCardDecSizeX, m_txtCardTurnCardSizeX, m_btnCardTurnCardIncSizeX,
					   displayCardPtr->GetTurnCardPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardTurnCard 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardTurnCardDecSizeY, m_txtCardTurnCardSizeY, m_btnCardTurnCardIncSizeY,
					   displayCardPtr->GetTurnCardPtr(), 5, 0, displayCardPosUpperLimitY );
}

/// 
/// @private
/// @brief Draws the panel element of the Card Display 
///		front component setting 
/// 
/// It draws the folloing panel element: 
///		card front time prompt X-position, 
///		card front time prompt Y-position,
///		card front time value X-position, 
///		card front time value Y-position,
///		card up prompt X-position, 
///		card up prompt Y-position,
///		card up value X-position, 
///		card up value Y-position,
///		card down prompt X-position, 
///		card down prompt Y-position,
///		card down value X-position, 
///		card down value Y-position,
///		card turn card X-position, 
///		card turn card Y-position
///		card front time prompt X-size, 
///		card front time prompt Y-size,
///		card front time value X-size, 
///		card front time value Y-size,
///		card up prompt X-size, 
///		card up prompt Y-size,
///		card up value X-size, 
///		card up value Y-size,
///		card down prompt X-size, 
///		card down prompt Y-size,
///		card down value X-size, 
///		card down value Y-size,
///		card turn card X-size, 
///		card turn card Y-size
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::CardEditor::DrawCardDisplayFcompPanel( sf::RenderWindow& a_window )
{
	// CardTurnCard Size y
	m_btnCardTurnCardIncSizeY->Draw( a_window );
	m_txtCardTurnCardSizeY->Draw( a_window );
	m_btnCardTurnCardDecSizeY->Draw( a_window );
	m_txtCardTurnCardSizeYPrompt->Draw( a_window );

	// CardTurnCard Size X
	m_btnCardTurnCardIncSizeX->Draw( a_window );
	m_txtCardTurnCardSizeX->Draw( a_window );
	m_btnCardTurnCardDecSizeX->Draw( a_window );
	m_txtCardTurnCardSizeXPrompt->Draw( a_window );

	// CardDownValue Size y
	m_btnCardDownValueIncSizeY->Draw( a_window );
	m_txtCardDownValueSizeY->Draw( a_window );
	m_btnCardDownValueDecSizeY->Draw( a_window );
	m_txtCardDownValueSizeYPrompt->Draw( a_window );

	// CardDownValue Size X
	m_btnCardDownValueIncSizeX->Draw( a_window );
	m_txtCardDownValueSizeX->Draw( a_window );
	m_btnCardDownValueDecSizeX->Draw( a_window );
	m_txtCardDownValueSizeXPrompt->Draw( a_window );

	// CardDownPrompt Size y
	m_btnCardDownPromptIncSizeY->Draw( a_window );
	m_txtCardDownPromptSizeY->Draw( a_window );
	m_btnCardDownPromptDecSizeY->Draw( a_window );
	m_txtCardDownPromptSizeYPrompt->Draw( a_window );

	// CardDownPrompt Size X
	m_btnCardDownPromptIncSizeX->Draw( a_window );
	m_txtCardDownPromptSizeX->Draw( a_window );
	m_btnCardDownPromptDecSizeX->Draw( a_window );
	m_txtCardDownPromptSizeXPrompt->Draw( a_window );

	// CardUpValue Size y
	m_btnCardUpValueIncSizeY->Draw( a_window );
	m_txtCardUpValueSizeY->Draw( a_window );
	m_btnCardUpValueDecSizeY->Draw( a_window );
	m_txtCardUpValueSizeYPrompt->Draw( a_window );

	// CardUpValue Size X
	m_btnCardUpValueIncSizeX->Draw( a_window );
	m_txtCardUpValueSizeX->Draw( a_window );
	m_btnCardUpValueDecSizeX->Draw( a_window );
	m_txtCardUpValueSizeXPrompt->Draw( a_window );

	// CardUpPrompt Size y
	m_btnCardUpPromptIncSizeY->Draw( a_window );
	m_txtCardUpPromptSizeY->Draw( a_window );
	m_btnCardUpPromptDecSizeY->Draw( a_window );
	m_txtCardUpPromptSizeYPrompt->Draw( a_window );

	// CardUpPrompt Size X
	m_btnCardUpPromptIncSizeX->Draw( a_window );
	m_txtCardUpPromptSizeX->Draw( a_window );
	m_btnCardUpPromptDecSizeX->Draw( a_window );
	m_txtCardUpPromptSizeXPrompt->Draw( a_window );

	// CardFrontTimeValue Size y
	m_btnCardFrontTimeValueIncSizeY->Draw( a_window );
	m_txtCardFrontTimeValueSizeY->Draw( a_window );
	m_btnCardFrontTimeValueDecSizeY->Draw( a_window );
	m_txtCardFrontTimeValueSizeYPrompt->Draw( a_window );

	// CardFrontTimeValue Size X
	m_btnCardFrontTimeValueIncSizeX->Draw( a_window );
	m_txtCardFrontTimeValueSizeX->Draw( a_window );
	m_btnCardFrontTimeValueDecSizeX->Draw( a_window );
	m_txtCardFrontTimeValueSizeXPrompt->Draw( a_window );

	// CardFrontTimePrompt Size y
	m_btnCardFrontTimePromptIncSizeY->Draw( a_window );
	m_txtCardFrontTimePromptSizeY->Draw( a_window );
	m_btnCardFrontTimePromptDecSizeY->Draw( a_window );
	m_txtCardFrontTimePromptSizeYPrompt->Draw( a_window );

	// CardFrontTimePrompt Size X
	m_btnCardFrontTimePromptIncSizeX->Draw( a_window );
	m_txtCardFrontTimePromptSizeX->Draw( a_window );
	m_btnCardFrontTimePromptDecSizeX->Draw( a_window );
	m_txtCardFrontTimePromptSizeXPrompt->Draw( a_window );


	// CardTurnCard Position y
	m_btnCardTurnCardIncPosY->Draw( a_window );
	m_txtCardTurnCardPosY->Draw( a_window );
	m_btnCardTurnCardDecPosY->Draw( a_window );
	m_txtCardTurnCardPosYPrompt->Draw( a_window );

	// CardTurnCard Position X
	m_btnCardTurnCardIncPosX->Draw( a_window );
	m_txtCardTurnCardPosX->Draw( a_window );
	m_btnCardTurnCardDecPosX->Draw( a_window );
	m_txtCardTurnCardPosXPrompt->Draw( a_window );

	// CardDownValue Position y
	m_btnCardDownValueIncPosY->Draw( a_window );
	m_txtCardDownValuePosY->Draw( a_window );
	m_btnCardDownValueDecPosY->Draw( a_window );
	m_txtCardDownValuePosYPrompt->Draw( a_window );

	// CardDownValue Position X
	m_btnCardDownValueIncPosX->Draw( a_window );
	m_txtCardDownValuePosX->Draw( a_window );
	m_btnCardDownValueDecPosX->Draw( a_window );
	m_txtCardDownValuePosXPrompt->Draw( a_window );

	// CardDownPrompt Position y
	m_btnCardDownPromptIncPosY->Draw( a_window );
	m_txtCardDownPromptPosY->Draw( a_window );
	m_btnCardDownPromptDecPosY->Draw( a_window );
	m_txtCardDownPromptPosYPrompt->Draw( a_window );

	// CardDownPrompt Position X
	m_btnCardDownPromptIncPosX->Draw( a_window );
	m_txtCardDownPromptPosX->Draw( a_window );
	m_btnCardDownPromptDecPosX->Draw( a_window );
	m_txtCardDownPromptPosXPrompt->Draw( a_window );

	// CardUpValue Position y
	m_btnCardUpValueIncPosY->Draw( a_window );
	m_txtCardUpValuePosY->Draw( a_window );
	m_btnCardUpValueDecPosY->Draw( a_window );
	m_txtCardUpValuePosYPrompt->Draw( a_window );

	// CardUpValue Position X
	m_btnCardUpValueIncPosX->Draw( a_window );
	m_txtCardUpValuePosX->Draw( a_window );
	m_btnCardUpValueDecPosX->Draw( a_window );
	m_txtCardUpValuePosXPrompt->Draw( a_window );

	// CardUpPrompt Position y
	m_btnCardUpPromptIncPosY->Draw( a_window );
	m_txtCardUpPromptPosY->Draw( a_window );
	m_btnCardUpPromptDecPosY->Draw( a_window );
	m_txtCardUpPromptPosYPrompt->Draw( a_window );

	// CardUpPrompt Position X
	m_btnCardUpPromptIncPosX->Draw( a_window );
	m_txtCardUpPromptPosX->Draw( a_window );
	m_btnCardUpPromptDecPosX->Draw( a_window );
	m_txtCardUpPromptPosXPrompt->Draw( a_window );

	// CardFrontTimeValue Position y
	m_btnCardFrontTimeValueIncPosY->Draw( a_window );
	m_txtCardFrontTimeValuePosY->Draw( a_window );
	m_btnCardFrontTimeValueDecPosY->Draw( a_window );
	m_txtCardFrontTimeValuePosYPrompt->Draw( a_window );

	// CardFrontTimeValue Position X
	m_btnCardFrontTimeValueIncPosX->Draw( a_window );
	m_txtCardFrontTimeValuePosX->Draw( a_window );
	m_btnCardFrontTimeValueDecPosX->Draw( a_window );
	m_txtCardFrontTimeValuePosXPrompt->Draw( a_window );

	// CardFrontTimePrompt Position y
	m_btnCardFrontTimePromptIncPosY->Draw( a_window );
	m_txtCardFrontTimePromptPosY->Draw( a_window );
	m_btnCardFrontTimePromptDecPosY->Draw( a_window );
	m_txtCardFrontTimePromptPosYPrompt->Draw( a_window );

	// CardFrontTimePrompt Position X
	m_btnCardFrontTimePromptIncPosX->Draw( a_window );
	m_txtCardFrontTimePromptPosX->Draw( a_window );
	m_btnCardFrontTimePromptDecPosX->Draw( a_window );
	m_txtCardFrontTimePromptPosXPrompt->Draw( a_window );
}

/// 
/// @private
/// @brief Initializes the panel element of the Card Display 
///		back component setting 
/// 
/// It initializes the folloing panel element: 
///		card back time prompt X-position, 
///		card back time prompt Y-position,
///		card back time value X-position, 
///		card back time value Y-position,
///		card question prompt X-position, 
///		card question prompt Y-position,
///		card question value X-position, 
///		card question value Y-position,
///		card answer prompt X-position, 
///		card answer prompt Y-position,
///		card answer value X-position, 
///		card answer value Y-position,
///		card submit X-position, 
///		card submit Y-position,
///		card back time prompt X-size, 
///		card back time prompt Y-size,
///		card back time value X-size, 
///		card back time value Y-size,
///		card question prompt X-size, 
///		card question prompt Y-size,
///		card question value X-size, 
///		card question value Y-size,
///		card answer prompt X-size, 
///		card answer prompt Y-size,
///		card answer value X-size, 
///		card answer value Y-size,
///		card submit X-size, 
///		card submit Y-size
///
void Brood::Application::CardEditor::InializeCardDisplayBcompPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	// creating a panel element to control the CardBackTimePrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimePromptPosXPrompt, &m_btnCardBackTimePromptDecPosX,
								 &m_txtCardBackTimePromptPosX, &m_btnCardBackTimePromptIncPosX,
								 "Back Time Pmt X Pos",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().x ), true );

	// creating a panel element to control the CardBackTimePrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimePromptPosYPrompt, &m_btnCardBackTimePromptDecPosY,
								 &m_txtCardBackTimePromptPosY, &m_btnCardBackTimePromptIncPosY,
								 "Back Time Pmt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardBackTimeValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimeValuePosXPrompt, &m_btnCardBackTimeValueDecPosX,
								 &m_txtCardBackTimeValuePosX, &m_btnCardBackTimeValueIncPosX,
								 "Back Time Val X Pos",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardBackTimeValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimeValuePosYPrompt, &m_btnCardBackTimeValueDecPosY,
								 &m_txtCardBackTimeValuePosY, &m_btnCardBackTimeValueIncPosY,
								 "Back Time Val Y Pos",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardQuestionPrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionPromptPosXPrompt, &m_btnCardQuestionPromptDecPosX,
								 &m_txtCardQuestionPromptPosX, &m_btnCardQuestionPromptIncPosX,
								 "Question Pmt X Pos",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardQuestionPrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionPromptPosYPrompt, &m_btnCardQuestionPromptDecPosY,
								 &m_txtCardQuestionPromptPosY, &m_btnCardQuestionPromptIncPosY,
								 "Question Pmt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardQuestionValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionValuePosXPrompt, &m_btnCardQuestionValueDecPosX,
								 &m_txtCardQuestionValuePosX, &m_btnCardQuestionValueIncPosX,
								 "Question Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardQuestionValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionValuePosYPrompt, &m_btnCardQuestionValueDecPosY,
								 &m_txtCardQuestionValuePosY, &m_btnCardQuestionValueIncPosY,
								 "Question Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardAnswerPrompt Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerPromptPosXPrompt, &m_btnCardAnswerPromptDecPosX,
								 &m_txtCardAnswerPromptPosX, &m_btnCardAnswerPromptIncPosX,
								 "Answer Prompt X Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardAnswerPrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerPromptPosYPrompt, &m_btnCardAnswerPromptDecPosY,
								 &m_txtCardAnswerPromptPosY, &m_btnCardAnswerPromptIncPosY,
								 "Answer Prompt Y Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardAnswerValue Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerValuePosXPrompt, &m_btnCardAnswerValueDecPosX,
								 &m_txtCardAnswerValuePosX, &m_btnCardAnswerValueIncPosX,
								 "Answer Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardAnswerValue Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerValuePosYPrompt, &m_btnCardAnswerValueDecPosY,
								 &m_txtCardAnswerValuePosY, &m_btnCardAnswerValueIncPosY,
								 "Answer Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardSubmit Pos X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSubmitPosXPrompt, &m_btnCardSubmitDecPosX,
								 &m_txtCardSubmitPosX, &m_btnCardSubmitIncPosX,
								 "Submit Button X Pos",
								 std::to_string( ( int )displayCardPtr->GetSubmitPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardSubmit Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSubmitPosYPrompt, &m_btnCardSubmitDecPosY,
								 &m_txtCardSubmitPosY, &m_btnCardSubmitIncPosY,
								 "Submit Button Y Pos",
								 std::to_string( ( int )displayCardPtr->GetSubmitPtr()->GetBodyPosition().y ) );

	// creating a panel element to control the CardBackTimePrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimePromptSizeXPrompt, &m_btnCardBackTimePromptDecSizeX,
								 &m_txtCardBackTimePromptSizeX, &m_btnCardBackTimePromptIncSizeX,
								 "Back Time Pmt X Size",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardBackTimePrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimePromptSizeYPrompt, &m_btnCardBackTimePromptDecSizeY,
								 &m_txtCardBackTimePromptSizeY, &m_btnCardBackTimePromptIncSizeY,
								 "Back Time Pmt Y Size",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardBackTimeValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimeValueSizeXPrompt, &m_btnCardBackTimeValueDecSizeX,
								 &m_txtCardBackTimeValueSizeX, &m_btnCardBackTimeValueIncSizeX,
								 "Back Time Val X Size",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardBackTimeValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardBackTimeValueSizeYPrompt, &m_btnCardBackTimeValueDecSizeY,
								 &m_txtCardBackTimeValueSizeY, &m_btnCardBackTimeValueIncSizeY,
								 "Back Time Val Y Size",
								 std::to_string( ( int )displayCardPtr->GetBackTimePromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardQuestionPrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionPromptSizeXPrompt, &m_btnCardQuestionPromptDecSizeX,
								 &m_txtCardQuestionPromptSizeX, &m_btnCardQuestionPromptIncSizeX,
								 "Question Pmt X Size",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardQuestionPrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionPromptSizeYPrompt, &m_btnCardQuestionPromptDecSizeY,
								 &m_txtCardQuestionPromptSizeY, &m_btnCardQuestionPromptIncSizeY,
								 "Question Pmt Y Size",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardQuestionValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionValueSizeXPrompt, &m_btnCardQuestionValueDecSizeX,
								 &m_txtCardQuestionValueSizeX, &m_btnCardQuestionValueIncSizeX,
								 "Question Value X Size",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardQuestionValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionValueSizeYPrompt, &m_btnCardQuestionValueDecSizeY,
								 &m_txtCardQuestionValueSizeY, &m_btnCardQuestionValueIncSizeY,
								 "Question Value Y Size",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardAnswerPrompt Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerPromptSizeXPrompt, &m_btnCardAnswerPromptDecSizeX,
								 &m_txtCardAnswerPromptSizeX, &m_btnCardAnswerPromptIncSizeX,
								 "Answer Prompt X Size",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardAnswerPrompt Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerPromptSizeYPrompt, &m_btnCardAnswerPromptDecSizeY,
								 &m_txtCardAnswerPromptSizeY, &m_btnCardAnswerPromptIncSizeY,
								 "Answer Prompt Y Size",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardAnswerValue Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerValueSizeXPrompt, &m_btnCardAnswerValueDecSizeX,
								 &m_txtCardAnswerValueSizeX, &m_btnCardAnswerValueIncSizeX,
								 "Answer Value X Size",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardAnswerValue Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardAnswerValueSizeYPrompt, &m_btnCardAnswerValueDecSizeY,
								 &m_txtCardAnswerValueSizeY, &m_btnCardAnswerValueIncSizeY,
								 "Answer Value Y Size",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodySize().y ) );

	// creating a panel element to control the CardSubmit Size X
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSubmitSizeXPrompt, &m_btnCardSubmitDecSizeX,
								 &m_txtCardSubmitSizeX, &m_btnCardSubmitIncSizeX,
								 "Submit Button X Size",
								 std::to_string( ( int )displayCardPtr->GetSubmitPtr()->GetBodySize().x ) );

	// creating a panel element to control the CardSubmit Size Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSubmitSizeYPrompt, &m_btnCardSubmitDecSizeY,
								 &m_txtCardSubmitSizeY, &m_btnCardSubmitIncSizeY,
								 "Submit Button Y Size",
								 std::to_string( ( int )displayCardPtr->GetSubmitPtr()->GetBodySize().y ) );

}

/// 
/// @private
/// @brief Updates the panel element of the Card Display 
///		back component setting 
/// 
/// It Updates the folloing panel element: 
///		card back time prompt X-position, 
///		card back time prompt Y-position,
///		card back time value X-position, 
///		card back time value Y-position,
///		card question prompt X-position, 
///		card question prompt Y-position,
///		card question value X-position, 
///		card question value Y-position,
///		card answer prompt X-position, 
///		card answer prompt Y-position,
///		card answer value X-position, 
///		card answer value Y-position,
///		card submit X-position, 
///		card submit Y-position,
///		card back time prompt X-size, 
///		card back time prompt Y-size,
///		card back time value X-size, 
///		card back time value Y-size,
///		card question prompt X-size, 
///		card question prompt Y-size,
///		card question value X-size, 
///		card question value Y-size,
///		card answer prompt X-size, 
///		card answer prompt Y-size,
///		card answer value X-size, 
///		card answer value Y-size,
///		card submit X-size, 
///		card submit Y-size
/// 
void Brood::Application::CardEditor::UpdateCardDisplayBcompPanel()
{
	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();
	unsigned displayCardLowerLimitX = displayCardPtr->GetBodyPosition().x;
	unsigned displayCardPosUpperLimitX = displayCardPtr->GetBodyPosition().x + displayCardPtr->GetBodySize().x;

	unsigned displayCardLowerLimitY = displayCardPtr->GetBodyPosition().y;
	unsigned displayCardPosUpperLimitY = displayCardPtr->GetBodyPosition().y + displayCardPtr->GetBodySize().y;

	// checks if the user interacted with the CardBackTimePrompt 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardBackTimePromptDecPosX, m_txtCardBackTimePromptPosX, m_btnCardBackTimePromptIncPosX,
					  displayCardPtr->GetBackTimePromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardBackTimePrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardBackTimePromptDecPosY, m_txtCardBackTimePromptPosY, m_btnCardBackTimePromptIncPosY,
					  displayCardPtr->GetBackTimePromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardBackTimeValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardBackTimeValueDecPosX, m_txtCardBackTimeValuePosX, m_btnCardBackTimeValueIncPosX,
					  displayCardPtr->GetBackTimeValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardBackTimeValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardBackTimeValueDecPosY, m_txtCardBackTimeValuePosY, m_btnCardBackTimeValueIncPosY,
					  displayCardPtr->GetBackTimeValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardQuestionPrompt 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardQuestionPromptDecPosX, m_txtCardQuestionPromptPosX, m_btnCardQuestionPromptIncPosX,
					  displayCardPtr->GetQuestionPromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardQuestionPrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardQuestionPromptDecPosY, m_txtCardQuestionPromptPosY, m_btnCardQuestionPromptIncPosY,
					  displayCardPtr->GetQuestionPromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardQuestionValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardQuestionValueDecPosX, m_txtCardQuestionValuePosX, m_btnCardQuestionValueIncPosX,
					  displayCardPtr->GetQuestionValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardQuestionValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardQuestionValueDecPosY, m_txtCardQuestionValuePosY, m_btnCardQuestionValueIncPosY,
					  displayCardPtr->GetQuestionValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardAnswerPrompt 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardAnswerPromptDecPosX, m_txtCardAnswerPromptPosX, m_btnCardAnswerPromptIncPosX,
					  displayCardPtr->GetAnswerPromptPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardAnswerPrompt 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardAnswerPromptDecPosY, m_txtCardAnswerPromptPosY, m_btnCardAnswerPromptIncPosY,
					  displayCardPtr->GetAnswerPromptPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardAnswerValue 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardAnswerValueDecPosX, m_txtCardAnswerValuePosX, m_btnCardAnswerValueIncPosX,
					  displayCardPtr->GetAnswerValuePtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardAnswerValue 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardAnswerValueDecPosY, m_txtCardAnswerValuePosY, m_btnCardAnswerValueIncPosY,
					  displayCardPtr->GetAnswerValuePtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardSubmit 
	// x Pos panel Element
	UpdateDecIncPosX( m_btnCardSubmitDecPosX, m_txtCardSubmitPosX, m_btnCardSubmitIncPosX,
					  displayCardPtr->GetSubmitPtr(), 5, displayCardLowerLimitX, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardSubmit 
	// y Pos panel Element
	UpdateDecIncPosY( m_btnCardSubmitDecPosY, m_txtCardSubmitPosY, m_btnCardSubmitIncPosY,
					  displayCardPtr->GetSubmitPtr(), 5, displayCardLowerLimitY, displayCardPosUpperLimitY );


	// checks if the user interacted with the CardBackTimePrompt 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardBackTimePromptDecSizeX, m_txtCardBackTimePromptSizeX, m_btnCardBackTimePromptIncSizeX,
					   displayCardPtr->GetBackTimePromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardBackTimePrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardBackTimePromptDecSizeY, m_txtCardBackTimePromptSizeY, m_btnCardBackTimePromptIncSizeY,
					   displayCardPtr->GetBackTimePromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardBackTimeValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardBackTimeValueDecSizeX, m_txtCardBackTimeValueSizeX, m_btnCardBackTimeValueIncSizeX,
					   displayCardPtr->GetBackTimeValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardBackTimeValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardBackTimeValueDecSizeY, m_txtCardBackTimeValueSizeY, m_btnCardBackTimeValueIncSizeY,
					   displayCardPtr->GetBackTimeValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardQuestionPrompt 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardQuestionPromptDecSizeX, m_txtCardQuestionPromptSizeX, m_btnCardQuestionPromptIncSizeX,
					   displayCardPtr->GetQuestionPromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardQuestionPrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardQuestionPromptDecSizeY, m_txtCardQuestionPromptSizeY, m_btnCardQuestionPromptIncSizeY,
					   displayCardPtr->GetQuestionPromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardQuestionValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardQuestionValueDecSizeX, m_txtCardQuestionValueSizeX, m_btnCardQuestionValueIncSizeX,
					   displayCardPtr->GetQuestionValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardQuestionValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardQuestionValueDecSizeY, m_txtCardQuestionValueSizeY, m_btnCardQuestionValueIncSizeY,
					   displayCardPtr->GetQuestionValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardAnswerPrompt 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardAnswerPromptDecSizeX, m_txtCardAnswerPromptSizeX, m_btnCardAnswerPromptIncSizeX,
					   displayCardPtr->GetAnswerPromptPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardAnswerPrompt 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardAnswerPromptDecSizeY, m_txtCardAnswerPromptSizeY, m_btnCardAnswerPromptIncSizeY,
					   displayCardPtr->GetAnswerPromptPtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardAnswerValue 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardAnswerValueDecSizeX, m_txtCardAnswerValueSizeX, m_btnCardAnswerValueIncSizeX,
					   displayCardPtr->GetAnswerValuePtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardAnswerValue 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardAnswerValueDecSizeY, m_txtCardAnswerValueSizeY, m_btnCardAnswerValueIncSizeY,
					   displayCardPtr->GetAnswerValuePtr(), 5, 0, displayCardPosUpperLimitY );

	// checks if the user interacted with the CardSubmit 
	// x Size panel Element
	UpdateDecIncSizeX( m_btnCardSubmitDecSizeX, m_txtCardSubmitSizeX, m_btnCardSubmitIncSizeX,
					   displayCardPtr->GetSubmitPtr(), 5, 0, displayCardPosUpperLimitX );

	// checks if the user interacted with the CardSubmit 
	// y Size panel Element
	UpdateDecIncSizeY( m_btnCardSubmitDecSizeY, m_txtCardSubmitSizeY, m_btnCardSubmitIncSizeY,
					   displayCardPtr->GetSubmitPtr(), 5, 0, displayCardPosUpperLimitY );

}

/// 
/// @private
/// @brief Draws the panel element of the Card Display 
///		back component setting 
/// 
/// It draws the folloing panel element: 
///		card back time prompt X-position, 
///		card back time prompt Y-position,
///		card back time value X-position, 
///		card back time value Y-position,
///		card question prompt X-position, 
///		card question prompt Y-position,
///		card question value X-position, 
///		card question value Y-position,
///		card answer prompt X-position, 
///		card answer prompt Y-position,
///		card answer value X-position, 
///		card answer value Y-position,
///		card submit X-position, 
///		card submit Y-position,
///		card back time prompt X-size, 
///		card back time prompt Y-size,
///		card back time value X-size, 
///		card back time value Y-size,
///		card question prompt X-size, 
///		card question prompt Y-size,
///		card question value X-size, 
///		card question value Y-size,
///		card answer prompt X-size, 
///		card answer prompt Y-size,
///		card answer value X-size, 
///		card answer value Y-size,
///		card submit X-size, 
///		card submit Y-size
/// 
/// @param a_window reference to the render window
///
void Brood::Application::CardEditor::DrawCardDisplayBcompPanel( sf::RenderWindow& a_window )
{
	// CardSubmit Size y
	m_btnCardSubmitIncSizeY->Draw( a_window );
	m_txtCardSubmitSizeY->Draw( a_window );
	m_btnCardSubmitDecSizeY->Draw( a_window );
	m_txtCardSubmitSizeYPrompt->Draw( a_window );

	// CardSubmit Size X
	m_btnCardSubmitIncSizeX->Draw( a_window );
	m_txtCardSubmitSizeX->Draw( a_window );
	m_btnCardSubmitDecSizeX->Draw( a_window );
	m_txtCardSubmitSizeXPrompt->Draw( a_window );

	// CardAnswerValue Size y
	m_btnCardAnswerValueIncSizeY->Draw( a_window );
	m_txtCardAnswerValueSizeY->Draw( a_window );
	m_btnCardAnswerValueDecSizeY->Draw( a_window );
	m_txtCardAnswerValueSizeYPrompt->Draw( a_window );

	// CardAnswerValue Size X
	m_btnCardAnswerValueIncSizeX->Draw( a_window );
	m_txtCardAnswerValueSizeX->Draw( a_window );
	m_btnCardAnswerValueDecSizeX->Draw( a_window );
	m_txtCardAnswerValueSizeXPrompt->Draw( a_window );

	// CardAnswerPrompt Size y
	m_btnCardAnswerPromptIncSizeY->Draw( a_window );
	m_txtCardAnswerPromptSizeY->Draw( a_window );
	m_btnCardAnswerPromptDecSizeY->Draw( a_window );
	m_txtCardAnswerPromptSizeYPrompt->Draw( a_window );

	// CardAnswerPrompt Size X
	m_btnCardAnswerPromptIncSizeX->Draw( a_window );
	m_txtCardAnswerPromptSizeX->Draw( a_window );
	m_btnCardAnswerPromptDecSizeX->Draw( a_window );
	m_txtCardAnswerPromptSizeXPrompt->Draw( a_window );

	// CardQuestionValue Size y
	m_btnCardQuestionValueIncSizeY->Draw( a_window );
	m_txtCardQuestionValueSizeY->Draw( a_window );
	m_btnCardQuestionValueDecSizeY->Draw( a_window );
	m_txtCardQuestionValueSizeYPrompt->Draw( a_window );

	// CardQuestionValue Size X
	m_btnCardQuestionValueIncSizeX->Draw( a_window );
	m_txtCardQuestionValueSizeX->Draw( a_window );
	m_btnCardQuestionValueDecSizeX->Draw( a_window );
	m_txtCardQuestionValueSizeXPrompt->Draw( a_window );

	// CardQuestionPrompt Size y
	m_btnCardQuestionPromptIncSizeY->Draw( a_window );
	m_txtCardQuestionPromptSizeY->Draw( a_window );
	m_btnCardQuestionPromptDecSizeY->Draw( a_window );
	m_txtCardQuestionPromptSizeYPrompt->Draw( a_window );

	// CardQuestionPrompt Size X
	m_btnCardQuestionPromptIncSizeX->Draw( a_window );
	m_txtCardQuestionPromptSizeX->Draw( a_window );
	m_btnCardQuestionPromptDecSizeX->Draw( a_window );
	m_txtCardQuestionPromptSizeXPrompt->Draw( a_window );

	// CardBackTimeValue Size y
	m_btnCardBackTimeValueIncSizeY->Draw( a_window );
	m_txtCardBackTimeValueSizeY->Draw( a_window );
	m_btnCardBackTimeValueDecSizeY->Draw( a_window );
	m_txtCardBackTimeValueSizeYPrompt->Draw( a_window );

	// CardBackTimeValue Size X
	m_btnCardBackTimeValueIncSizeX->Draw( a_window );
	m_txtCardBackTimeValueSizeX->Draw( a_window );
	m_btnCardBackTimeValueDecSizeX->Draw( a_window );
	m_txtCardBackTimeValueSizeXPrompt->Draw( a_window );

	// CardBackTimePrompt Size y
	m_btnCardBackTimePromptIncSizeY->Draw( a_window );
	m_txtCardBackTimePromptSizeY->Draw( a_window );
	m_btnCardBackTimePromptDecSizeY->Draw( a_window );
	m_txtCardBackTimePromptSizeYPrompt->Draw( a_window );

	// CardBackTimePrompt Size X
	m_btnCardBackTimePromptIncSizeX->Draw( a_window );
	m_txtCardBackTimePromptSizeX->Draw( a_window );
	m_btnCardBackTimePromptDecSizeX->Draw( a_window );
	m_txtCardBackTimePromptSizeXPrompt->Draw( a_window );

	// CardSubmit Position y
	m_btnCardSubmitIncPosY->Draw( a_window );
	m_txtCardSubmitPosY->Draw( a_window );
	m_btnCardSubmitDecPosY->Draw( a_window );
	m_txtCardSubmitPosYPrompt->Draw( a_window );

	// CardSubmit Position X
	m_btnCardSubmitIncPosX->Draw( a_window );
	m_txtCardSubmitPosX->Draw( a_window );
	m_btnCardSubmitDecPosX->Draw( a_window );
	m_txtCardSubmitPosXPrompt->Draw( a_window );

	// CardAnswerValue Position y
	m_btnCardAnswerValueIncPosY->Draw( a_window );
	m_txtCardAnswerValuePosY->Draw( a_window );
	m_btnCardAnswerValueDecPosY->Draw( a_window );
	m_txtCardAnswerValuePosYPrompt->Draw( a_window );

	// CardAnswerValue Position X
	m_btnCardAnswerValueIncPosX->Draw( a_window );
	m_txtCardAnswerValuePosX->Draw( a_window );
	m_btnCardAnswerValueDecPosX->Draw( a_window );
	m_txtCardAnswerValuePosXPrompt->Draw( a_window );

	// CardAnswerPrompt Position y
	m_btnCardAnswerPromptIncPosY->Draw( a_window );
	m_txtCardAnswerPromptPosY->Draw( a_window );
	m_btnCardAnswerPromptDecPosY->Draw( a_window );
	m_txtCardAnswerPromptPosYPrompt->Draw( a_window );

	// CardAnswerPrompt Position X
	m_btnCardAnswerPromptIncPosX->Draw( a_window );
	m_txtCardAnswerPromptPosX->Draw( a_window );
	m_btnCardAnswerPromptDecPosX->Draw( a_window );
	m_txtCardAnswerPromptPosXPrompt->Draw( a_window );

	// CardQuestionValue Position y
	m_btnCardQuestionValueIncPosY->Draw( a_window );
	m_txtCardQuestionValuePosY->Draw( a_window );
	m_btnCardQuestionValueDecPosY->Draw( a_window );
	m_txtCardQuestionValuePosYPrompt->Draw( a_window );

	// CardQuestionValue Position X
	m_btnCardQuestionValueIncPosX->Draw( a_window );
	m_txtCardQuestionValuePosX->Draw( a_window );
	m_btnCardQuestionValueDecPosX->Draw( a_window );
	m_txtCardQuestionValuePosXPrompt->Draw( a_window );

	// CardQuestionPrompt Position y
	m_btnCardQuestionPromptIncPosY->Draw( a_window );
	m_txtCardQuestionPromptPosY->Draw( a_window );
	m_btnCardQuestionPromptDecPosY->Draw( a_window );
	m_txtCardQuestionPromptPosYPrompt->Draw( a_window );

	// CardQuestionPrompt Position X
	m_btnCardQuestionPromptIncPosX->Draw( a_window );
	m_txtCardQuestionPromptPosX->Draw( a_window );
	m_btnCardQuestionPromptDecPosX->Draw( a_window );
	m_txtCardQuestionPromptPosXPrompt->Draw( a_window );

	// CardBackTimeValue Position y
	m_btnCardBackTimeValueIncPosY->Draw( a_window );
	m_txtCardBackTimeValuePosY->Draw( a_window );
	m_btnCardBackTimeValueDecPosY->Draw( a_window );
	m_txtCardBackTimeValuePosYPrompt->Draw( a_window );

	// CardBackTimeValue Position X
	m_btnCardBackTimeValueIncPosX->Draw( a_window );
	m_txtCardBackTimeValuePosX->Draw( a_window );
	m_btnCardBackTimeValueDecPosX->Draw( a_window );
	m_txtCardBackTimeValuePosXPrompt->Draw( a_window );

	// CardBackTimePrompt Position y
	m_btnCardBackTimePromptIncPosY->Draw( a_window );
	m_txtCardBackTimePromptPosY->Draw( a_window );
	m_btnCardBackTimePromptDecPosY->Draw( a_window );
	m_txtCardBackTimePromptPosYPrompt->Draw( a_window );

	// CardBackTimePrompt Position X
	m_btnCardBackTimePromptIncPosX->Draw( a_window );
	m_txtCardBackTimePromptPosX->Draw( a_window );
	m_btnCardBackTimePromptDecPosX->Draw( a_window );
	m_txtCardBackTimePromptPosXPrompt->Draw( a_window );
}

/// 
/// @private
/// @brief Initializes the panel element of the Card Display 
///		back component setting 
/// 
/// It initializes the folloing panel element: 
///		Curr Deck Num prompt,
///		Curr Card Num prompt,
///		Curr Card Time prompt,
///		Curr Card up prompt,
///		Curr Card down prompt,
///		Curr Card question prompt,
///		Curr Card answer prompt,
///		turn card around
/// 
void Brood::Application::CardEditor::InializeCardInfoPanel()
{
	Brood::Application::Components::DeckManager* currDeckManagerPtr = m_gameData->GetDeckManagerPtr();
	Brood::Application::Components::Deck* CurrDeckPtr = currDeckManagerPtr->GetCurrActiveDeck();
	Brood::Application::Components::CardInfo* currCardPtr = CurrDeckPtr->GetCurrActiveCardPtr();

	// creating a panel element to control the curr active deck
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtDeckNumPrompt, &m_btnDecDeckNum,
								 &m_txtDeckNum, &m_btnIncDeckNum,
								 "Curr Active Deck Idx ",
								 std::to_string( ( int )currDeckManagerPtr->GetCurrActiveDeckIdx() ), true );

	// creating a panel element to control the curr active Card
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCurrCardNumPrompt, &m_btnDecCurrCardNum,
								 &m_txtCurrCardNum, &m_btnIncCurrCardNum,
								 "Curr Active Card Idx",
								 std::to_string( ( int )CurrDeckPtr->GetCurrActiveCardIdx() ) );

	// creating a panel element to control the curr active CardTime
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCurrCardTimePrompt, &m_btnDecCurrCardTime,
								 &m_txtCurrCardTime, &m_btnIncCurrCardTime,
								 "Card Time ",
								 std::to_string( ( int )currCardPtr->GetTime() ) );

	// creating a panel element to control the curr active CardUp
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCurrCardUpPrompt, &m_btnDecCurrCardUp,
								 &m_txtCurrCardUp, &m_btnIncCurrCardUp,
								 "Card Up ",
								 std::to_string( ( int )currCardPtr->GetCorrectNumSteps() ) );

	// creating a panel element to control the curr active CardDown
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCurrCardDownPrompt, &m_btnDecCurrCardDown,
								 &m_txtCurrCardDown, &m_btnIncCurrCardDown,
								 "Card Down ",
								 std::to_string( ( int )currCardPtr->GetIncorrectNumSteps() ) );

	// creating a panel element to enter a Card Question 
	DyCreateTextInputPannelElement( m_panelBodyPtr, &m_txtCurrCardQuestionPrompt, &m_txtCurrCardQuestionInput,
									"Card Question", "", "question" );

	// creating a panel element to enter a Card Answer 
	DyCreateTextInputPannelElement( m_panelBodyPtr, &m_txtCurrCardAnswerPrompt, &m_txtCurrCardAnswerInput,
									"Card Correct Answer", "", "answer" );

	// creating a button to turn the card
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;

	float panelSizeX = m_panelBodyPtr->getSize().x;
	float lastPanelElementSizeY = m_unNamedUIList.back()->GetBodySize().y;

	float panelPosX = m_panelBodyPtr->getPosition().x;
	float lastPanelElementPosY = m_unNamedUIList.back()->GetBodyPosition().y;
	// getting the color
	sf::Color panelColor;

	if( m_unNamedUIList.back()->GetBodyColor() == Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor )
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}
	else
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
	}

	m_btnTurnCardAround = DyCreateButton( { panelSizeX , 25 },
										  { panelPosX , lastPanelElementPosY + lastPanelElementSizeY },
										  "Turn Card", panelColor );

}

/// 
/// @private
/// @brief Updates the panel element of the Card Display 
///		back component setting 
/// 
/// It Updates the folloing panel element: 
///		Curr Deck Num prompt,
///		Curr Card Num prompt,
///		Curr Card Time prompt,
///		Curr Card up prompt,
///		Curr Card down prompt,
///		Curr Card question prompt,
///		Curr Card answer prompt,
///		turn card around
/// 
void Brood::Application::CardEditor::UpdateCardInfoPanel()
{

	// checks if the user interacted with the 
	// current selceted deck index panel
	UpdateCurrSelectedDeckIdx();

	// checks if the user interacted with the 
	// current selceted deck index panel
	UpdateCurrSelectedCardIdx();

	// checks if the user interacted with the 
	// time panel
	UpdateCurrCardInfoTime();

	// checks if the user interacted with the 
	// Up panel
	UpdateCurrCardInfoUp();

	// checks if the user interacted with the 
	// Down panel
	UpdateCurrCardInfoDown();

	// checks if the user interacted with the
	// enter curr card question panel element
	UpdateCurrCardQuestionInput();

	// checks if the user interacted with the
	// enter curr card answer panel element
	UpdateCurrCardAnswerInput();

	// checks if the user interacted with the
	// turn card panel element
	UpdateTurnCard();
}

/// 
/// @private
/// @brief Draws the panel element of the Card Display 
///		back component setting 
/// 
/// It draws the folloing panel element: 
///		Curr Deck idx prompt,
///		Curr Card idx prompt,
///		Curr Card Time prompt,
///		Curr Card up prompt,
///		Curr Card down prompt,
///		Curr Card question prompt,
///		Curr Card answer prompt,
///		turn card around
/// 
/// @param a_window reference to the render window
///
void Brood::Application::CardEditor::DrawCardInfoPanel( sf::RenderWindow& a_window )
{
	// drawing turn card
	m_btnTurnCardAround->Draw( a_window );

	// drawing curr active CurrCardAnswer panel element
	m_txtCurrCardAnswerPrompt->Draw( a_window );
	m_txtCurrCardAnswerInput->Draw( a_window );

	// drawing curr active CurrCardQuestion panel element
	m_txtCurrCardQuestionPrompt->Draw( a_window );
	m_txtCurrCardQuestionInput->Draw( a_window );

	// drawing curr active CurrCardDown panel element
	m_btnIncCurrCardDown->Draw( a_window );
	m_txtCurrCardDown->Draw( a_window );
	m_btnDecCurrCardDown->Draw( a_window );
	m_txtCurrCardDownPrompt->Draw( a_window );

	// drawing curr active CurrCardUp panel element
	m_btnIncCurrCardUp->Draw( a_window );
	m_txtCurrCardUp->Draw( a_window );
	m_btnDecCurrCardUp->Draw( a_window );
	m_txtCurrCardUpPrompt->Draw( a_window );

	// drawing curr active CurrCardTime panel element
	m_btnIncCurrCardTime->Draw( a_window );
	m_txtCurrCardTime->Draw( a_window );
	m_btnDecCurrCardTime->Draw( a_window );
	m_txtCurrCardTimePrompt->Draw( a_window );

	// drawing curr active CurrCardNum panel element
	m_btnIncCurrCardNum->Draw( a_window );
	m_txtCurrCardNum->Draw( a_window );
	m_btnDecCurrCardNum->Draw( a_window );
	m_txtCurrCardNumPrompt->Draw( a_window );

	// drawing curr active deck panel element
	m_btnIncDeckNum->Draw( a_window );
	m_txtDeckNum->Draw( a_window );
	m_btnDecDeckNum->Draw( a_window );
	m_txtDeckNumPrompt->Draw( a_window );
}

/// 
/// @private
/// @brief checks if the user interacted with the laod Card texture 
///		panel
///	
/// Load Card front texture file panel contains load Card front texture file 
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
/// @warning the Texture for the file should be in \Assets\Textures\CardTexture\
///		as it loads them from there. 
/// 
void Brood::Application::CardEditor::UpdateCardFrontFileTexture()
{
	if( m_txtCardFrontBgFileInput->DoElement() )
	{
		m_txtCardFrontBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnCardFrontBgOpenFile->DoElement() || ( m_txtCardFrontBgFileInput->IsEnterPressed() &&
												   m_txtCardFrontBgFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string CardFrontTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_cardTextures.string();

		CardFrontTextureFilePath += "\\" + m_txtCardFrontBgFileInput->GetText();


		// loading the texture file
		if( !m_gameData->GetDisplayCardPtr()->SetFrontBgFileName( CardFrontTextureFilePath ) )
		{
			m_txtCardFrontBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}

		// resetting the m_eterPressed
		m_txtCardFrontBgFileInput->SetEnterPressedFalse();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the laod Card texture 
///		panel
///	
/// Load Card Back texture file panel contains load Card Back texture file 
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
/// @warning the Texture for the file should be in \Assets\Textures\CardTexture\
///		as it loads them from there. 
/// 
void Brood::Application::CardEditor::UpdateCardBackFileTexture()
{
	if( m_txtCardBackBgFileInput->DoElement() )
	{
		m_txtCardBackBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_White );
	}

	// check if load the button waas pressed or enter was pressed
	if( m_btnCardBackBgOpenFile->DoElement() || ( m_txtCardBackBgFileInput->IsEnterPressed() &&
												  m_txtCardBackBgFileInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() ) )
	{
		std::string CardBackTextureFilePath = Brood::Application::StaticVariables::ST_Folders::stm_cardTextures.string();

		CardBackTextureFilePath += "\\" + m_txtCardBackBgFileInput->GetText();


		// loading the texture file
		if( !m_gameData->GetDisplayCardPtr()->SetBackBgFileName( CardBackTextureFilePath ) )
		{
			m_txtCardBackBgFileInput->SetFontColor( Brood::Application::StaticVariables::ST_ColorVariables::stm_ErrorColor );
		}

		// resetting the m_eterPressed
		m_txtCardBackBgFileInput->SetEnterPressedFalse();
	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted deck 
///		index panel
///	
/// Current selceted deck index panel contains  current selceted deck 
///		index promt textbox, current selceted deck index value text box, 
///		button to increase the current selceted deck index, and button 
///		to decrease the current selceted deck index
/// 
/// Only the button to increase the current selceted deck index, and 
///		button to decrease the current selceted deck index are interactable
/// 
/// If the interactable button was pressed then the current selceted deck 
///		index is increased or decresed by 1. current selceted deck index
///		should be more than or equal to 0 but less than minimum deck number
///
void Brood::Application::CardEditor::UpdateCurrSelectedDeckIdx()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnDecDeckNum->DoElement() )
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
		m_txtDeckNum->SetText( std::to_string( currentDeckIdx - 1 ) );

		// changing the displayed Deck data
		UpdateAllDispayElement();

	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnIncDeckNum->DoElement() )
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
		m_txtDeckNum->SetText( std::to_string( currentDeckIdx + 1 ) );

		// changing the displayed Deck data
		UpdateAllDispayElement();
	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted Card 
///		index panel
///	
/// Current selceted Card index panel contains  current selceted Card 
///		index promt textbox, current selceted Card index value text box, 
///		button to increase the current selceted Card index, and button 
///		to decrease the current selceted Card index
/// 
/// Only the button to increase the current selceted Card index, and 
///		button to decrease the current selceted Card index are interactable
/// 
/// If the interactable button was pressed then the current selceted Card 
///		index is increased or decresed by 1. current selceted Card index
///		should be more than or equal to 0 but less than minimum Card number
///
void Brood::Application::CardEditor::UpdateCurrSelectedCardIdx()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnDecCurrCardNum->DoElement() )
	{
		// getting the current active deck
		Brood::Application::Components::Deck* currentDeckPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck();

		// getting current selceted Card index
		unsigned currentCardIdx = currentDeckPtr->GetCurrActiveCardIdx();

		// chekcing if the current currentMaxCardNum id 
		// equal to 0 then do nothing
		if( currentCardIdx == 0 )
		{
			return;
		}

		// decrease the current selceted Card index by 1 units
		currentDeckPtr->SetCurrActiveCardIdx( currentCardIdx - 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardNum->SetText( std::to_string( currentCardIdx - 1 ) );

		// changing the displayed Card data
		UpdateAllDispayElement();

	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnIncCurrCardNum->DoElement() )
	{
		// getting the current active deck
		Brood::Application::Components::Deck* currentDeckPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck();

		// getting current selceted Card index
		unsigned currentCardIdx = currentDeckPtr->GetCurrActiveCardIdx();

		// chekcing if the current currentMaxCardNum id 
		// equal to maimum number of Card then do nothing
		if( currentCardIdx == currentDeckPtr->GetCardList().size() - 1 )
		{
			return;
		}

		// decrease the current selceted Card index by 1 units
		currentDeckPtr->SetCurrActiveCardIdx( currentCardIdx + 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardNum->SetText( std::to_string( currentCardIdx + 1 ) );

		// changing the displayed Card data
		UpdateAllDispayElement();


	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted Card 
///		time panel
///	
/// Current selceted Card index panel contains  current selceted Card 
///		time promt textbox, current selceted Card time value text box, 
///		button to increase the current selceted Card time, and button 
///		to decrease the current selceted Card time
/// 
/// Only the button to increase the current selceted Card time, and 
///		button to decrease the current selceted Card time are interactable
/// 
/// If the interactable button was pressed then the current selceted Card 
///		time is increased or decresed by 1. current selceted Card index
///		should be more than or equal to 0 
///
void Brood::Application::CardEditor::UpdateCurrCardInfoTime()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnDecCurrCardTime->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentTime = currentCardInfoPtr->GetTime();

		// chekcing if the current currentMaxCardNum id 
		// equal to 0 then do nothing
		if( currentTime == 0 )
		{
			return;
		}

		// decrease the current selceted Card index by 1 units
		currentCardInfoPtr->SetTime( currentTime - 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardTime->SetText( std::to_string( currentTime - 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnIncCurrCardTime->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentTime = currentCardInfoPtr->GetTime();

		// increase the current selceted Card index by 1 units
		currentCardInfoPtr->SetTime( currentTime + 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardTime->SetText( std::to_string( currentTime + 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted Card 
///		Up panel
///	
/// Current selceted Card index panel contains  current selceted Card 
///		Up promt textbox, current selceted Card Up value text box, 
///		button to increase the current selceted Card Up, and button 
///		to decrease the current selceted Card Up
/// 
/// Only the button to increase the current selceted Card Up, and 
///		button to decrease the current selceted Card Up are interactable
/// 
/// If the interactable button was pressed then the current selceted Card 
///		Up is increased or decresed by 1. current selceted Card index
///		should be more than or equal to 0 
///
void Brood::Application::CardEditor::UpdateCurrCardInfoUp()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnDecCurrCardUp->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentUp = currentCardInfoPtr->GetCorrectNumSteps();

		// chekcing if the current currentMaxCardNum id 
		// equal to 0 then do nothing
		if( currentUp == 0 )
		{
			return;
		}

		// decrease the current selceted Card index by 1 units
		currentCardInfoPtr->SetCorrectNumSteps( currentUp - 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardUp->SetText( std::to_string( currentUp - 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnIncCurrCardUp->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentUp = currentCardInfoPtr->GetCorrectNumSteps();

		// increase the current selceted Card index by 1 units
		currentCardInfoPtr->SetCorrectNumSteps( currentUp + 1 );

		// updating the textbox showing the current selceted Card index value
		m_txtCurrCardUp->SetText( std::to_string( currentUp + 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
}

///
/// @private
/// @brief checks if the user interacted with the current selceted Card 
///		Down panel
///	
/// Current selceted Card index panel contains  current selceted Card 
///		Down promt textbox, current selceted Card Down value text box, 
///		button to increase the current selceted Card Down, and button 
///		to decrease the current selceted Card Down
/// 
/// Only the button to increase the current selceted Card Down, and 
///		button to decrease the current selceted Card Down are interactable
/// 
/// If the interactable button was pressed then the current selceted Card 
///		Down is increased or decresed by 1. current selceted Card index
///		should be more than or equal to 0 
///
void Brood::Application::CardEditor::UpdateCurrCardInfoDown()
{
	// chekcing if the decrease the current selceted player index was pressed
	if( m_btnDecCurrCardDown->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentDown = currentCardInfoPtr->GetIncorrectNumSteps();

		// chekcing if the current currentMaxCardNum id 
		// equal to 0 then do nothing
		if( currentDown == 0 )
		{
			return;
		}

		// decrease the current selceted Card index by 1 units
		currentCardInfoPtr->SetIncorrectNumSteps( currentDown - 1 );

		// Downdating the textbox showing the current selceted Card index value
		m_txtCurrCardDown->SetText( std::to_string( currentDown - 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
	// chekcing if the increase the current selceted player index was pressed
	else if( m_btnIncCurrCardDown->DoElement() )
	{
		// getting the current active card
		Brood::Application::Components::CardInfo* currentCardInfoPtr = m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr();

		// getting current selceted Card index
		unsigned currentDown = currentCardInfoPtr->GetIncorrectNumSteps();

		// increase the current selceted Card index by 1 units
		currentCardInfoPtr->SetIncorrectNumSteps( currentDown + 1 );

		// Downdating the textbox showing the current selceted Card index value
		m_txtCurrCardDown->SetText( std::to_string( currentDown + 1 ) );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the set Curr Card 
///		Question panel
///	
/// Curr Card Question panel contains Curr Card Question promt textbox, 
///		and textbox to enter the Curr Card Question.
/// 
/// Only the textbox to enter the Curr Card Question is interactable
/// 
/// If the interactable textbox was pressed then it allows the
///		user to set the game title
/// 
void Brood::Application::CardEditor::UpdateCurrCardQuestionInput()
{
	m_txtCurrCardQuestionInput->DoElement();

	// check if game title textbox was de selected then save 
	// the name to the title screen
	if( m_txtCurrCardQuestionInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() )
	{
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr()->SetQuestion( m_txtCurrCardQuestionInput->GetText() );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();

		// resetting the m_eterPressed
		m_txtCurrCardQuestionInput->SetEnterPressedFalse();
		// TODO change the folder name 
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the set Curr Card 
///		Answer panel
///	
/// Curr Card Answer panel contains Curr Card Answer promt textbox, 
///		and textbox to enter the Curr Card Answer.
/// 
/// Only the textbox to enter the Curr Card Answer is interactable
/// 
/// If the interactable textbox was pressed then it allows the
///		user to set the game title
/// 
void Brood::Application::CardEditor::UpdateCurrCardAnswerInput()
{
	m_txtCurrCardAnswerInput->DoElement();

	// check if game title textbox was de selected then save 
	// the name to the title screen
	if( m_txtCurrCardAnswerInput->GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetLastActiveElementIdPtr() )
	{
		m_gameData->GetDeckManagerPtr()->GetCurrActiveDeck()->GetCurrActiveCardPtr()->SetCorrectAnswer( m_txtCurrCardAnswerInput->GetText() );

		// updating the display card
		m_gameData->GetDisplayCardPtr()->UpdateDisplayedText();

		// resetting the m_eterPressed
		m_txtCurrCardAnswerInput->SetEnterPressedFalse();
		// TODO change the folder name 
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the turn card panel
///	
/// turn card panel contains only turn card button to turn the 
///		display card.
/// 
/// Only the button to turn the display card is interactable.
///		
/// If the interactable button was pressed then it allows the
///		user to turn the display card.
/// 
void Brood::Application::CardEditor::UpdateTurnCard()
{
	if( m_btnTurnCardAround->DoElement() )
	{
		// updating the display card
		m_gameData->GetDisplayCardPtr()->ToggleCardFace();
	}
}

// ======================================================================
// ================= end of CardEditor class ============================
// ======================================================================
