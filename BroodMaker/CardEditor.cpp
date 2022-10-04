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

}

/// 
/// @public
/// @virtual
/// @brief updates the display element
/// 

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
/// It has the 3 settings : Board Settings, Player Settings, and Dice Settings
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
	m_ddiSettingSelection->AddItemToMenu( "New Card Setting" );
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

					while( itemName.size() < 39 )
					{
						itemName = " " + itemName + " ";
					}

					m_ddiSettingSelection->SetText( itemName + " v" );

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
/// @brief inializes the card Display Panel
/// 
void Brood::Application::CardEditor::InializeCardDisplayPanel()
{
	// ==================== initializes the display card  panel element ======================

	Brood::Application::Components::DisplayCard* displayCardPtr = m_gameData->GetDisplayCardPtr();

	// creating a panel element to control the card sizeX
	DyCreateDecIncPannelElement( m_panelBodyPtr, &m_txtCardSizeXPrompt, &m_btnCardDecSizeX,
								 &m_txtCardSizeX, &m_btnCardIncSizeX,
								 "Card X Size",
								 std::to_string( ( int )displayCardPtr->GetBodySize().x ) );

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

// ======================================================================
// ================= end of CardEditor class ============================
// ======================================================================
