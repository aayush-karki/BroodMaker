/*************************************************************************/
/// 
/// @file WorkSpace.cpp 
/// 
/// @brief  This file is a source file for WorkSpace class
/// 
/// It also contains all of the declaration of the WorkSpace class's
///		member function.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "WorkSpace.h"

// ======================================================================
// ================= start of WorkSpace class ===========================
// ======================================================================

/// 
/// @public
/// @brief default constructor
///
Brood::Application::WorkSpace::WorkSpace() :
	m_isDebugger( false ),
	m_font( &Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_font )
{}

/// 
/// @public
/// @virtual
/// @brief default destructor
///
Brood::Application::WorkSpace::~WorkSpace()
{
	// deallocating dynamically allocated uielements
	std::vector<Brood::BroodUI::UIElement*>::iterator uiListPtr = m_unNamedUIList.begin();

	while( uiListPtr != m_unNamedUIList.end() )
	{
		delete ( *uiListPtr );
		++uiListPtr;
	}
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::WorkSpace::Draw( sf::RenderWindow& a_window )
{
	std::vector<Brood::BroodUI::UIElement*>::reverse_iterator dyUIListIte = m_unNamedUIList.rbegin();
	while( dyUIListIte != m_unNamedUIList.rend() )
	{
		( *dyUIListIte )->Draw( a_window );
		++dyUIListIte;
	}
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::WorkSpace::Debugger()
{
	std::vector<Brood::BroodUI::UIElement*>::iterator uiListPtr = m_unNamedUIList.begin();

	while( uiListPtr != m_unNamedUIList.end() )
	{
		( *uiListPtr )->Debugger();
		++uiListPtr;
	}
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a button element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the button element
/// @param a_pos  postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default
///		 Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
/// 
Brood::BroodUI::Button* Brood::Application::WorkSpace::DyCreateButton( sf::Vector2f a_size, sf::Vector2f a_pos,
																	   std::string a_text, sf::Color a_color )
{
	Brood::BroodUI::Button* buttonElement = Brood::BroodUI::Button::DyCreateButton( a_size, a_pos, a_text, a_color );

	// adding the newly created button to the UI elmente list
	m_unNamedUIList.push_back( buttonElement );

	return buttonElement;
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a button element 
///		initializes it, and adds it to m_unNameList
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the button element
/// @param a_sizeY width of the button element
/// @param a_posX x-postion of the button element
/// @param a_posY y-postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
///
Brood::BroodUI::Button* Brood::Application::WorkSpace::DyCreateButton( float a_sizeX, float a_sizeY,
																	   float a_posX, float a_posY,
																	   std::string a_text,
																	   sf::Color a_color )
{
	return Brood::Application::WorkSpace::DyCreateButton( { a_sizeX, a_sizeY }, { a_posX, a_posY },
														  a_text, a_color );
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a textbox element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the textbox element
/// @param a_pos  postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; default 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///  
Brood::BroodUI::TextBox* Brood::Application::WorkSpace::DyCreateTextBox( sf::Vector2f a_size,
																		 sf::Vector2f a_pos,
																		 std::string a_text,
																		 bool a_isEditable,
																		 std::string a_placeholderText,
																		 sf::Color a_color )
{
	Brood::BroodUI::TextBox* textBoxElement = Brood::BroodUI::TextBox::DyCreateTextBox( a_size, a_pos,
																						a_text, a_isEditable,
																						a_placeholderText, a_color );

	// adding the newly created textbox to the UI elmente list
	m_unNamedUIList.push_back( textBoxElement );

	return textBoxElement;
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a textbox element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the textbox element
/// @param a_sizeY width of the textbox element
/// @param a_posX x-postion of the textbox element
/// @param a_posY y-postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; 
///		default Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///
Brood::BroodUI::TextBox* Brood::Application::WorkSpace::DyCreateTextBox( float a_sizeX, float a_sizeY,
																		 float a_posX, float a_posY,
																		 std::string a_text, bool a_isEditable,
																		 std::string a_placeholderText,
																		 sf::Color a_color )
{
	return Brood::Application::WorkSpace::DyCreateTextBox( { a_sizeX, a_sizeY }, { a_posX, a_posY },
														   a_text, a_isEditable, a_placeholderText, a_color );
}

/// 
/// @protected
/// @brief helper function to dynamically create a DropDownInput element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the DropDownInput element
/// @param a_pos  postion of the DropDownInput element
/// @param a_color color of the textbox element ; 
///		default Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created DropDownInput element
///  
Brood::BroodUI::DropDownInput* Brood::Application::WorkSpace::DyCreateDropDownInput( sf::Vector2f a_size, sf::Vector2f a_pos,
																					 sf::Color a_color )
{
	Brood::BroodUI::DropDownInput* DropDownInputElement = new Brood::BroodUI::DropDownInput;
	DropDownInputElement->SetBodySize( a_size );
	DropDownInputElement->SetBodyPosition( a_pos );
	DropDownInputElement->SetFont( m_font );
	DropDownInputElement->SetBodyColor( a_color );

	// adding the newly created textbox to the UI elmente list
	m_unNamedUIList.push_back( DropDownInputElement );

	return DropDownInputElement;
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a DropDownInput element 
///		initializes it, and adds it to m_unNameList
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the DropDownInput element
/// @param a_sizeY width of the DropDownInput element
/// @param a_posX x-postion of the DropDownInput element
/// @param a_posY y-postion of the DropDownInput element
/// @param a_color color of the textbox element ; default 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///
Brood::BroodUI::DropDownInput* Brood::Application::WorkSpace::DyCreateDropDownInput( float a_sizeX, float a_sizeY,
																					 float a_posX, float a_posY,
																					 sf::Color a_color )
{
	return Brood::Application::WorkSpace::DyCreateDropDownInput( { a_sizeX, a_sizeY }, { a_posX, a_posY }, a_color );
}


/// 
/// @private
/// @brief Dynamically creates a dropdown input Panel Element.
/// 
///  It occupies the whole pannel length. 
/// 
/// It can be position at the top of the panel if a_topElement is true,
///		as the second element if a_createFromTop is true, else below the
///		last creasted UI element.
/// 
/// @note both a_topElement and a_createFromTop can not be true at the
///		same time.
/// 
///	It alternates the color of the panel element. Color used are:
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor
///		and 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// 
/// @param a_panelBodyPtr pointer to panel body.
/// @param a_txtPromptPtr pointer to textbox pointer where the dynamically
///		 created textbox to display the prompt is stored
/// @param a_ddiPtr pointer to drop down input pointer where the dynamically
///		 created drop down input is stored
/// @param a_promptToDisplay text to display in the prompt textbox element
/// @param a_itemsToAdd list of item to add to the drop down input
/// @param a_firstItemLength the length of the string to display on the 
///		as the selected element -> default 0 do nothing
/// @param a_createFromTop is true if the created element should be positioned 
///		second element form the top -> default false
/// 
void Brood::Application::WorkSpace::DyCreateDropdownInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
																		Brood::BroodUI::TextBox** a_txtPromptPtr,
																		Brood::BroodUI::DropDownInput** a_ddiPtr,
																		std::string a_promptToDisplay,
																		std::vector<std::string> a_itemsToAdd,
																		unsigned a_firstItemLength,
																		bool a_createFromTop )
{
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;

	float panelSizeX = a_panelBodyPtr->getSize().x;
	float lastPanelElementSizeY = m_unNamedUIList.back()->GetBodySize().y;

	float panelPosX = a_panelBodyPtr->getPosition().x;
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

	// if a_createFromTop is passed as true then last panel is the first element 
	// so using that to get the lastPanelElementPosY 
	// and setting the color to stm_AppPrimaryColor
	if( a_createFromTop )
	{
		lastPanelElementPosY = m_unNamedUIList.front()->GetBodyPosition().y;
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}

	// creating a text box for displaying the promt
	*a_txtPromptPtr = DyCreateTextBox( panelSizeX / 2.f, 25,
									   panelPosX, lastPanelElementPosY + lastPanelElementSizeY,
									   a_promptToDisplay, false, "", panelColor );
	// setitng the font
	( *a_txtPromptPtr )->SetFontSize( 15 );

	// creating a dropdown input
	*a_ddiPtr = DyCreateDropDownInput( { panelSizeX / 2.f, 25 },
									   { panelPosX + ( panelSizeX / 2.f ), lastPanelElementPosY + lastPanelElementSizeY },
									   panelColor );

	// setitng the font
	( *a_ddiPtr )->SetFontSize( 15 );

	// adding the item to the dropdown input list 
	std::vector<std::string>::iterator itemToAddIte = a_itemsToAdd.begin();
	while( itemToAddIte != a_itemsToAdd.end() )
	{
		( *a_ddiPtr )->AddItemToMenu( *itemToAddIte );
		++itemToAddIte;
	}

	// setting the first item as the first 
	std::string itemName = ( *a_ddiPtr )->GetItemList().at( 0 )->GetText();

	if( a_firstItemLength != 0 )
	{
		while( itemName.size() < a_firstItemLength )
		{
			itemName = " " + itemName + " ";
		}
	}

	( *a_ddiPtr )->SetText( ( itemName + " v" ) );
}

/// 
/// @private
/// @brief Dynamically creates a Panel Element that can increase or decrease
///		a parameter.
/// 
///  It has 4 UI element and its layout is 
///	< textBox  prompt> <button '<'> <textbox value> <button '>' > 
/// 
/// For examaple: boardSize X < 20 >.
/// 
///	It alternates the color of the panel element. Color used are:
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor
///		and 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @param a_panelBodyPtr pointer to panel body.
/// @param a_txtPromptPtr pointer to textbox pointer where the dynamically
///		 created textbox to display the prompt is stored
/// @param a_btnDecPtr pointer to button pointer where the dynamically
///		 created button to display the '<' is stored
/// @param a_txtValuePtr pointer to textbox pointer where the dynamically
///		 created textbox to display the value is stored
/// @param a_btnIncPtr pointer to button pointer where the dynamically
///		 created button to display the '>' is stored
/// @param a_promptToDisplay text to display in the prompt textbox element
/// @param a_valueToDisplay text to display in the value textbox element
/// @param a_createFromTop is true if the created element should be positioned 
///		second element form the top
/// 
void Brood::Application::WorkSpace::DyCreateDecIncPannelElement( sf::RectangleShape* a_panelBodyPtr,
																 Brood::BroodUI::TextBox** a_txtPromptPtr,
																 Brood::BroodUI::Button** a_btnDecPtr,
																 Brood::BroodUI::TextBox** a_txtValuePtr,
																 Brood::BroodUI::Button** a_btnIncPtr,
																 std::string a_promptToDisplay,
																 std::string a_valueToDisplay,
																 bool a_createFromTop )
{
	float panelSizeX = a_panelBodyPtr->getSize().x;
	float lastPanelElementSizeY = m_unNamedUIList.back()->GetBodySize().y;
	float panelPosX = a_panelBodyPtr->getPosition().x;
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

	// if a_createFromTop is passed as true then this sould be treated 
	//		as second panel element.
	//		so using the front to get the lastPanelElementPosY 
	//		and setting the color to stm_AppPrimaryColor
	if( a_createFromTop )
	{
		lastPanelElementPosY = m_unNamedUIList.front()->GetBodyPosition().y;
		lastPanelElementSizeY = m_unNamedUIList.front()->GetBodySize().y;

		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}

	// creating a text box for displaying the promt
	*a_txtPromptPtr = DyCreateTextBox( panelSizeX / 2.f, 25,
									   panelPosX, lastPanelElementPosY + lastPanelElementSizeY,
									   a_promptToDisplay, false, "", panelColor );
	// setitng the font
	( *a_txtPromptPtr )->SetFontSize( 15 );


	// creating a butotn for decreasing the value
	*a_btnDecPtr = DyCreateButton( { panelSizeX / 10.f, 25 },
								   { panelPosX + panelSizeX / 2.f, lastPanelElementPosY + lastPanelElementSizeY },
								   "<", panelColor );
	// setitng the font
	( *a_btnDecPtr )->SetFontSize( 15 );


	// creating a text box for displaying the current value
	*a_txtValuePtr = DyCreateTextBox( { ( panelSizeX * 3 ) / 10, 25 },
									  { panelPosX + ( ( panelSizeX * 3 ) / 5 ), lastPanelElementPosY + lastPanelElementSizeY },
									  a_valueToDisplay, false, "", panelColor );
	// setitng the font
	( *a_txtValuePtr )->SetFontSize( 15 );

	// creating a butotn for increasing the value
	*a_btnIncPtr = DyCreateButton( { panelSizeX / 10.f, 25 },
								   { panelPosX + ( ( panelSizeX * 9 ) / 10 ), lastPanelElementPosY + lastPanelElementSizeY },
								   ">", panelColor );
	// setitng the font
	( *a_btnIncPtr )->SetFontSize( 15 );
}


/// 
/// @private
/// @brief Dynamically creates a Panel Element that user can enter a filename
/// 
///	It has 3 UI element and its layout is 
/// 
///		<textBox prompt> 
/// 
///		<textbox>  
///		
///		<open button>
/// 
/// For examaple: Player texture
/// 
///				(enter file name) <open>
/// 
///	It alternates the color of the panel element. Color used are:
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor
///		and 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @param a_panelBodyPtr pointer to panel body.
/// @param a_txtPromptPtr pointer to textbox pointer where the dynamically
///		 created textbox to display the prompt is stored
/// @param a_txtFileInputPtr pointer to textbox pointer where the dynamically
///		 created textbox to enter file name is stored
/// @param a_btnOpenFilePtr pointer to button pointer where the dynamically
///		 created button to display the 'open' is stored
/// @param a_promptToDisplay text to display in the prompt textbox element
/// @param a_valueToDisplay text to display in the value textbox element
/// @param a_createFromTop is true if the created element should be positioned 
///		second element form the top
///
void Brood::Application::WorkSpace::DyCreateFileInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
																	Brood::BroodUI::TextBox** a_txtPromptPtr,
																	Brood::BroodUI::TextBox** a_txtFileInputPtr,
																	Brood::BroodUI::Button** a_btnOpenFilePtr,
																	std::string a_promptToDisplay,
																	std::string a_valueToDisplay,
																	bool a_createFromTop )
{
	float panelSizeX = a_panelBodyPtr->getSize().x;
	float lastPanelElementSizeY = m_unNamedUIList.back()->GetBodySize().y;
	float panelPosX = a_panelBodyPtr->getPosition().x;
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

	// if a_createFromTop is passed as true then this sould be treated 
	//		as second panel element.
	//		so using the front to get the lastPanelElementPosY 
	//		and setting the color to stm_AppPrimaryColor
	if( a_createFromTop )
	{
		lastPanelElementPosY = m_unNamedUIList.front()->GetBodyPosition().y;
		lastPanelElementSizeY = m_unNamedUIList.front()->GetBodySize().y;

		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}

	// creating a text box for displaying the promt
	*a_txtPromptPtr = DyCreateTextBox( panelSizeX, 25,
									   panelPosX, lastPanelElementPosY + lastPanelElementSizeY,
									   a_promptToDisplay, false, "", panelColor );
	// setitng the font
	( *a_txtPromptPtr )->SetFontSize( 15 );

	// changing the color because the promt taks the whole lile
	if( panelColor == Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor )
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}
	else
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
	}

	// updaiting the last element size and position
	lastPanelElementSizeY = 25;
	lastPanelElementPosY += 25;


	// creating a text box for file input
	*a_txtFileInputPtr = DyCreateTextBox( panelSizeX, 25,
										  panelPosX, lastPanelElementPosY + lastPanelElementSizeY,
										  a_valueToDisplay, true, "<enter file name>", panelColor );

	// changing the color because the promt taks the whole lile
	if( panelColor == Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor )
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}
	else
	{
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
	}

	// updaiting the last element position
	lastPanelElementPosY += 25;

	// creating a open box to open file input
	*a_btnOpenFilePtr = DyCreateButton( { panelSizeX, 25 },
										{ panelPosX, lastPanelElementPosY + lastPanelElementSizeY },
										"Open Loaded File", panelColor );
	// setitng the font
	( *a_txtFileInputPtr )->SetFontSize( 12 );

	// setitng the font
	( *a_btnOpenFilePtr )->SetFontSize( 15 );

}
/// 
/// @private
/// @brief Dynamically creates a Panel Element that user can enter a text
/// 
///	It has 2 UI element and its layout is 
/// 
///		<textBox prompt> <textbox>  
///		
/// For examaple: Game Name	(enter file name) 
/// 
///	It alternates the color of the panel element. Color used are:
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor
///		and 
///		Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @param a_panelBodyPtr pointer to panel body.
/// @param a_txtPromptPtr pointer to textbox pointer where the dynamically
///		 created textbox to display the prompt is stored
/// @param a_txtTextInputtPtr pointer to textbox pointer where the dynamically
///		 created textbox to enter the text is stored
/// @param a_promptToDisplay text to display in the prompt textbox element
/// @param a_valueToDisplay text to display in the value textbox element
/// @param a_placeHolderText text to display in the value textbox element
/// @param a_createFromTop is true if the created element should be positioned 
///		second element form the top
///
void Brood::Application::WorkSpace::DyCreateTextInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
																	Brood::BroodUI::TextBox** a_txtPromptPtr,
																	Brood::BroodUI::TextBox** a_txtTextInputtPtr,
																	std::string a_promptToDisplay,
																	std::string a_valueToDisplay,
																	std::string a_placeHolderText,
																	bool a_createFromTop )
{
	uint32_t windowWidth = Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width;

	float panelSizeX = a_panelBodyPtr->getSize().x;
	float lastPanelElementSizeY = m_unNamedUIList.back()->GetBodySize().y;

	float panelPosX = a_panelBodyPtr->getPosition().x;
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

	// if a_createFromTop is passed as true then last panel is the first element 
	// so using that to get the lastPanelElementPosY 
	// and setting the color to stm_AppPrimaryColor
	if( a_createFromTop )
	{
		lastPanelElementPosY = m_unNamedUIList.front()->GetBodyPosition().y;
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor;
	}

	// creating a text box for displaying the promt
	*a_txtPromptPtr = DyCreateTextBox( panelSizeX / 2.f, 25,
									   panelPosX, lastPanelElementPosY + lastPanelElementSizeY,
									   a_promptToDisplay, false, "", panelColor );
	// setitng the font
	( *a_txtPromptPtr )->SetFontSize( 15 );

	// creating a dropdown input
	*a_txtTextInputtPtr = DyCreateTextBox( { panelSizeX / 2.f, 25 },
										   { panelPosX + ( panelSizeX / 2.f ), lastPanelElementPosY + lastPanelElementSizeY },
										   a_valueToDisplay, true, a_placeHolderText, panelColor );

	// setitng the font
	( *a_txtTextInputtPtr )->SetFontSize( 15 );
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
void Brood::Application::WorkSpace::UpdateDecIncSizeX( Brood::BroodUI::Button* a_btnDecSizeX,
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
		a_elemnetToChangeSizeX->SetText( a_elemnetToChangeSizeX->GetText() );

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
		a_elemnetToChangeSizeX->SetText( a_elemnetToChangeSizeX->GetText() );

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
void Brood::Application::WorkSpace::UpdateDecIncSizeY( Brood::BroodUI::Button* a_btnDecSizeY,
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
		a_elemnetToChangeSizeY->SetText( a_elemnetToChangeSizeY->GetText() );

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
		a_elemnetToChangeSizeY->SetText( a_elemnetToChangeSizeY->GetText() );

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
void Brood::Application::WorkSpace::UpdateDecIncPosX( Brood::BroodUI::Button* a_btnDecPosX,
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
		if( currentPosX + ( unsigned )a_elemnetToChangePosX->GetBodySize().x + a_unit >= a_upperLimit )
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
void Brood::Application::WorkSpace::UpdateDecIncPosY( Brood::BroodUI::Button* a_btnDecPosY,
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
		if( currentPosY + ( unsigned )a_elemnetToChangePosX->GetBodySize().y + a_unit >= a_upperLimit )
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
// ================= end of WorkSpace class =============================
// ======================================================================