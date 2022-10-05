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
	m_gameData( a_gameData ), m_panelBodyPtr( a_panelPtr )
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
{}

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

	m_gameData->GetDisplayCardPtr()->Draw( a_window );

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
	m_ddiSettingSelection->AddItemToMenu( "Display card front componet Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Display card back componet Setting" );
	m_ddiSettingSelection->AddItemToMenu( "Existing Card Setting" );

	// setting the font size to 18
	m_ddiSettingSelection->SetFontSize( 18 );

	// setting the first item as the first 
	std::string itemName = m_ddiSettingSelection->GetItemList().at( m_selectedSettingIdx )->GetText();

	while( itemName.size() < 39 )
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
///		card X-postion, card Y-position, card X-size, card Y-Size, 
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
///		card X-postion, card Y-position, card X-size, card Y-Size, 
///		CardFrontBg filename textur, CardFrontBg filename textur
///
void Brood::Application::CardEditor::UpdateCardDisplayPanel()
{
	// checks if the user interacted with the Card 
	// x size panel Element
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;
	float boardWindowWidth = ( windowWidth * ( 100 - Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage ) ) / 100;
	UpdateSizeX( m_btnCardDecSizeX, m_txtCardSizeX, m_btnCardIncSizeX,
				 m_gameData->GetDisplayCardPtr(), 5, 0, boardWindowWidth );

	// checks if the user interacted with the Card 
	// x size panel Element
	uint32_t windowHieght = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height;
	UpdateSizeY( m_btnCardDecSizeY, m_txtCardSizeY, m_btnCardIncSizeY,
				 m_gameData->GetDisplayCardPtr(), 5, 0, windowHieght );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	//UpdateCardPosX();
	UpdatePosX( m_btnCardDecPosX, m_txtCardPosX, m_btnCardIncPosX,
				m_gameData->GetDisplayCardPtr(), 5, 0, boardWindowWidth );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	//UpdateCardPosY();
	UpdatePosY( m_btnCardDecPosY, m_txtCardPosY, m_btnCardIncPosY,
				m_gameData->GetDisplayCardPtr(), 5, 90, windowHieght );

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
///		card X-postion, card Y-position, card X-size, card Y-Size, 
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
///		card front time prompt X-postion, 
///		card front time prompt Y-position,
///		card front time value X-postion, 
///		card front time value Y-position,
///		card up prompt X-postion, 
///		card up prompt Y-position,
///		card up value X-postion, 
///		card up value Y-position,
///		card down prompt X-postion, 
///		card down prompt Y-position,
///		card down value X-postion, 
///		card down value Y-position,
///		card turn card X-postion, 
///		card turn card Y-position
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
								 "Down Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardTurnCard Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardTurnCardPosYPrompt, &m_btnCardTurnCardDecPosY,
								 &m_txtCardTurnCardPosY, &m_btnCardTurnCardIncPosY,
								 "Down Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetDownPromptPtr()->GetBodyPosition().y ) );
}

/// 
/// @private
/// @brief Updates the panel element of the Card Display 
///		front component setting 
/// 
/// It Updates the folloing panel element: 
///		card front time prompt X-postion, 
///		card front time prompt Y-position,
///		card front time value X-postion, 
///		card front time value Y-position,
///		card up prompt X-postion, 
///		card up prompt Y-position,
///		card up value X-postion, 
///		card up value Y-position,
///		card down prompt X-postion, 
///		card down prompt Y-position,
///		card down value X-postion, 
///		card down value Y-position,
///		card turn card X-postion, 
///		card turn card Y-position
/// 
void Brood::Application::CardEditor::UpdateCardDisplayFcompPanel()
{}

/// 
/// @private
/// @brief Draws the panel element of the Card Display 
///		front component setting 
/// 
/// It draws the folloing panel element: 
///		card front time prompt X-postion, 
///		card front time prompt Y-position,
///		card front time value X-postion, 
///		card front time value Y-position,
///		card up prompt X-postion, 
///		card up prompt Y-position,
///		card up value X-postion, 
///		card up value Y-position,
///		card down prompt X-postion, 
///		card down prompt Y-position,
///		card down value X-postion, 
///		card down value Y-position,
///		card turn card X-postion, 
///		card turn card Y-position
/// 
/// @param a_window reference to the render window
/// 
void Brood::Application::CardEditor::DrawCardDisplayFcompPanel( sf::RenderWindow& a_window )
{
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
///		card back time prompt X-postion, 
///		card back time prompt Y-position,
///		card back time value X-postion, 
///		card back time value Y-position,
///		card question prompt X-postion, 
///		card question prompt Y-position,
///		card question value X-postion, 
///		card question value Y-position,
///		card answer prompt X-postion, 
///		card answer prompt Y-position,
///		card answer value X-postion, 
///		card answer value Y-position,
///		card submit X-postion, 
///		card submit Y-position
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
								 "Question Prompt X Pos",
								 std::to_string( ( int )displayCardPtr->GetQuestionPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardQuestionPrompt Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardQuestionPromptPosYPrompt, &m_btnCardQuestionPromptDecPosY,
								 &m_txtCardQuestionPromptPosY, &m_btnCardQuestionPromptIncPosY,
								 "Question Prompt Y Pos",
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
								 "Answer Value X Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().x ) );

	// creating a panel element to control the CardSubmit Pos Y
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSubmitPosYPrompt, &m_btnCardSubmitDecPosY,
								 &m_txtCardSubmitPosY, &m_btnCardSubmitIncPosY,
								 "Answer Value Y Pos",
								 std::to_string( ( int )displayCardPtr->GetAnswerPromptPtr()->GetBodyPosition().y ) );
}

/// 
/// @private
/// @brief Updates the panel element of the Card Display 
///		back component setting 
/// 
/// It Updates the folloing panel element: 
///		card back time prompt X-postion, 
///		card back time prompt Y-position,
///		card back time value X-postion, 
///		card back time value Y-position,
///		card question prompt X-postion, 
///		card question prompt Y-position,
///		card question value X-postion, 
///		card question value Y-position,
///		card answer prompt X-postion, 
///		card answer prompt Y-position,
///		card answer value X-postion, 
///		card answer value Y-position,
///		card submit X-postion, 
///		card submit Y-position
/// 
void Brood::Application::CardEditor::UpdateCardDisplayBcompPanel()
{}

/// 
/// @private
/// @brief Draws the panel element of the Card Display 
///		back component setting 
/// 
/// It draws the folloing panel element: 
///		card back time prompt X-postion, 
///		card back time prompt Y-position,
///		card back time value X-postion, 
///		card back time value Y-position,
///		card question prompt X-postion, 
///		card question prompt Y-position,
///		card question value X-postion, 
///		card question value Y-position,
///		card answer prompt X-postion, 
///		card answer prompt Y-position,
///		card answer value X-postion, 
///		card answer value Y-position,
///		card submit X-postion, 
///		card submit Y-position
/// 
/// @param a_window reference to the render window
///
void Brood::Application::CardEditor::DrawCardDisplayBcompPanel( sf::RenderWindow& a_window )
{
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

void Brood::Application::CardEditor::InializeCardInfoPanel()
{}

void Brood::Application::CardEditor::UpdateCardInfoPanel()
{}

void Brood::Application::CardEditor::DrawCardInfoPanel( sf::RenderWindow& a_window )
{}

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
/// @brief checks if the user interacted with the element 
///		SizeX panel
///	
/// SizeX panel contains current element SizeX promt textbox, 
///		current element SizeX value text box, button to increase the
///		current element SizeX, and button to decrease the 
///		element SizeX.
/// 
/// Only the button to increase the SizeX, and button 
///		to decrease SizeX are interactable
/// 
/// If the interactable button was pressed then the SizeX 
///		is increased or decresed by specified units if the 
///		current element does not go outside the upper limit
///
/// @param a_btnDecSizeX pointer to the element's panel 
///		decSizeX button 
/// @param a_txtSizeX pointer to the element's panel 
///		sizeX value textbox
/// @param a_btnIncSizeX pointer to the element's panel 
///		incSizeX button
/// @param a_elemnetToChangeSizeX pointer to the element whose 
///		size being controlled
/// @param a_unit unit to increase or decrease
/// @param a_lowerLimit the minimum SizeX of the element
/// @param a_upperLimit the maximum SizeX of the element
/// 
void Brood::Application::CardEditor::UpdateSizeX( Brood::BroodUI::Button* a_btnDecSizeX,
												  Brood::BroodUI::TextBox* a_txtSizeX,
												  Brood::BroodUI::Button* a_btnIncSizeX,
												  Brood::BroodUI::UIElement* a_elemnetToChangeSizeX,
												  unsigned a_unit,
												  unsigned a_lowerLimit,
												  unsigned a_upperLimit )
{
	// chekcing if the decrease the X size was pressed
	if( a_btnDecSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = a_elemnetToChangeSizeX->GetBodySize();
		int currentSizeX = currentSize.x;

		// checking if the decreasing the element's size any further 
		// would make the element size less than the lower limit
		if( currentSizeX - a_unit + 1 <= a_lowerLimit )
		{
			return;
		}

		// decrease the x position by a_unit units
		a_elemnetToChangeSizeX->SetBodySize( currentSizeX - a_unit, currentSize.y );

		// updating the textbox showing the x-positon value
		a_txtSizeX->SetText( std::to_string( currentSizeX - a_unit ) );
	}
	// chekcing if the incresase the X size was pressed
	else if( a_btnIncSizeX->DoElement() )
	{
		// getting x-size information
		sf::Vector2f currentSize = a_elemnetToChangeSizeX->GetBodySize();
		int currentSizeX = currentSize.x;

		// chekcing if increasing the size.x would make element to go
		// over the upper limit
		if( ( unsigned )a_elemnetToChangeSizeX->GetBodyPosition().x + currentSizeX + a_unit >= a_upperLimit )
		{
			return;
		}

		// increase the x position by a_unit units
		a_elemnetToChangeSizeX->SetBodySize( currentSizeX + a_unit, currentSize.y );

		// updating the textbox showing the x-positon value
		a_txtSizeX->SetText( std::to_string( currentSizeX + a_unit ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the element 
///		SizeY panel
///	
/// SizeY panel contains current element SizeY promt textbox, 
///		current element SizeY value text box, button to increase the
///		current element SizeY, and button to decrease the 
///		element SizeY.
/// 
/// Only the button to increase the SizeY, and button 
///		to decrease SizeY are interactable
/// 
/// If the interactable button was pressed then the SizeY 
///		is increased or decresed by specified units if the 
///		current element does not go outside the upper limit
///
/// @param a_btnDecSizeY pointer to the element's panel 
///		decSizeY button 
/// @param a_txtSizeY pointer to the element's panel 
///		sizeY value textbox
/// @param a_btnIncSizeY pointer to the element's panel 
///		incSizeY button
/// @param a_elemnetToChangeSizeY pointer to the element whose 
///		size being controlled
/// @param a_unit unit to increase or decrease
/// @param a_lowerLimit the minimum SizeY of the element
/// @param a_upperLimit the maximum SizeY of the element
/// 
void Brood::Application::CardEditor::UpdateSizeY( Brood::BroodUI::Button* a_btnDecSizeY,
												  Brood::BroodUI::TextBox* a_txtSizeY,
												  Brood::BroodUI::Button* a_btnIncSizeY,
												  Brood::BroodUI::UIElement* a_elemnetToChangeSizeY,
												  unsigned a_unit,
												  unsigned a_lowerLimit,
												  unsigned a_upperLimit )
{
	// chekcing if the decrease the Y size was pressed
	if( a_btnDecSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = a_elemnetToChangeSizeY->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if the current size.Y is lower limit
		if( currentSizeY - a_unit + 1 <= a_lowerLimit )
		{
			return;
		}

		// decrease the x position by a_unit units
		a_elemnetToChangeSizeY->SetBodySize( currentSize.x, currentSizeY - a_unit );

		// updating the textbox showing the x-positon value
		a_txtSizeY->SetText( std::to_string( currentSizeY - a_unit ) );
	}
	// chekcing if the Increase the Y size was pressed
	else if( a_btnIncSizeY->DoElement() )
	{
		// getting y-size information
		sf::Vector2f currentSize = a_elemnetToChangeSizeY->GetBodySize();
		int currentSizeY = currentSize.y;

		// chekcing if increasing the size would make elemet 
		// go over the upper limit
		if( ( unsigned )a_elemnetToChangeSizeY->GetBodyPosition().y + currentSizeY + a_unit >= a_upperLimit )
		{
			return;
		}

		// increase the Card x position by a_unit units
		a_elemnetToChangeSizeY->SetBodySize( currentSize.x, currentSizeY + a_unit );

		// updating the textbox showing the x-positon value
		a_txtSizeY->SetText( std::to_string( currentSizeY + a_unit ) );
	}
}

/// 
/// @private
/// @brief checks if the user interacted with the element 
///		PosX panel
///	
/// PosX panel contains current element PosX promt textbox, 
///		current element PosX value text box, button to increase the
///		current element PosX, and button to decrease the 
///		element PosX.
/// 
/// Only the button to increase the PosX, and button 
///		to decrease PosX are interactable
/// 
/// If the interactable button was pressed then the PosX 
///		is increased or decresed by specified units if the 
///		current element does not go outside the upper limit
///
/// @param a_btnDecPosX pointer to the element's panel 
///		decPosX button 
/// @param a_txtPosX pointer to the element's panel 
///		PosX value textbox
/// @param a_btnIncPosX pointer to the element's panel 
///		incPosX button
/// @param a_elemnetToChangePosX pointer to the element whose 
///		size being controlled
/// @param a_unit unit to increase or decrease
/// @param a_lowerLimit the minimum PosX of the element
/// @param a_upperLimit the maximum PosX of the element
/// 
void Brood::Application::CardEditor::UpdatePosX( Brood::BroodUI::Button* a_btnDecPosX,
												 Brood::BroodUI::TextBox* a_txtPosX,
												 Brood::BroodUI::Button* a_btnIncPosX,
												 Brood::BroodUI::UIElement* a_elemnetToChangePosX,
												 unsigned a_unit,
												 unsigned a_lowerLimit,
												 unsigned a_upperLimit )
{
	// chekcing if the decrease the Card X postion was pressed
	if( a_btnDecPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = a_elemnetToChangePosX->GetBodyPosition();
		int currentPosX = currentPos.x;

		// checking if decreasing the element position any further
		// would make the element goes under lower limit 
		if( currentPosX - a_unit + 1 <= a_lowerLimit )
		{
			return;
		}

		// checking if decreasing the element position any further
		// would make the element goes over upper limit 
		if( currentPosX - a_unit <= a_lowerLimit )
		{
			return;
		}

		// decrease the Card x position by a_unit units
		a_elemnetToChangePosX->SetBodyPosition( currentPosX - a_unit, currentPos.y );

		// updating the textbox showing the x-positon value
		a_txtPosX->SetText( std::to_string( currentPosX - a_unit ) );
	}
	// chekcing if the Increase the Card X postion was pressed
	else if( a_btnIncPosX->DoElement() )
	{
		// getting x-position information
		sf::Vector2f currentPos = a_elemnetToChangePosX->GetBodyPosition();
		int currentPosX = currentPos.x;

		// checking if increased the element position any further
		// would make the element goes over upper limit 
		if( currentPosX + ( unsigned )m_gameData->GetDisplayCardPtr()->GetBodySize().x + a_unit >= a_upperLimit )
		{
			return;
		}

		// increase the Card x position by a_unit units
		a_elemnetToChangePosX->SetBodyPosition( currentPosX + a_unit, currentPos.y );

		// updating the textbox showing the x-positon value
		a_txtPosX->SetText( std::to_string( currentPosX + a_unit ) );
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
void Brood::Application::CardEditor::UpdatePosY( Brood::BroodUI::Button* a_btnDecPosY,
												 Brood::BroodUI::TextBox* a_txtPosY,
												 Brood::BroodUI::Button* a_btnIncPosY,
												 Brood::BroodUI::UIElement* a_elemnetToChangePosX,
												 unsigned a_unit,
												 unsigned a_lowerLimit,
												 unsigned a_upperLimit )
{
	// chekcing if the decrease the Card Y postion was pressed
	if( a_btnDecPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentPos = a_elemnetToChangePosX->GetBodyPosition();
		int currentPosY = currentPos.y;

		// checking if decreasing the element position any further
		// would make the element goes under lower limit 
		if( currentPosY - a_unit + 1 <= a_lowerLimit )
		{
			return;
		}

		// decrease the Card y position by a_unit units
		a_elemnetToChangePosX->SetBodyPosition( currentPos.x, currentPosY - a_unit );

		// updating the textbox showing the x-positon value
		a_txtPosY->SetText( std::to_string( currentPosY - a_unit ) );
	}
	// chekcing if the increase the Card Y postion was pressed
	else if( a_btnIncPosY->DoElement() )
	{
		// getting y-position information
		sf::Vector2f currentPos = a_elemnetToChangePosX->GetBodyPosition();
		int currentPosY = currentPos.y;

		// checking if increased the element position any further
		// would make the element goes over upper limit 
		if( currentPosY + ( unsigned )m_gameData->GetDisplayCardPtr()->GetBodySize().y + a_unit >= a_upperLimit )
		{
			return;
		}

		// increase the Card x position by 5 units
		a_elemnetToChangePosX->SetBodyPosition( currentPos.x, currentPosY + 5 );

		// updating the textbox showing the x-positon value
		a_txtPosY->SetText( std::to_string( currentPosY + 5 ) );
	}
}


// ======================================================================
// ================= end of CardEditor class ============================
// ======================================================================
