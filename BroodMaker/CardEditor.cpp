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
{}

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
	m_btnCardBackBgOpenFile->Draw(a_window);
	m_txtCardBackBgFileInput->Draw(a_window);
	m_txtCardBackBgFileNamePrompt->Draw(a_window);

	// CardFrontBg filename textur 
	m_btnCardFrontBgOpenFile->Draw( a_window );
	m_txtCardFrontBgFileInput->Draw( a_window );
	m_txtCardFrontBgFileNamePrompt->Draw( a_window );

	// Card Position y
	m_btnCardIncPosY->Draw(a_window);
	m_txtCardPosY->Draw(a_window);
	m_btnCardDecPosY->Draw(a_window);
	m_txtCardPosYPrompt->Draw(a_window);

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

// ======================================================================
// ================= end of CardEditor class ============================
// ======================================================================
