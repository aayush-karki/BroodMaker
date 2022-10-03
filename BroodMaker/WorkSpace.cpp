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
	Brood::BroodUI::Button* buttonElement = new Brood::BroodUI::Button;
	buttonElement->SetBodySize( a_size );
	buttonElement->SetBodyPosition( a_pos );
	buttonElement->SetFont( *m_font );
	buttonElement->SetBodyColor( a_color );
	buttonElement->SetText( a_text );

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
	Brood::BroodUI::TextBox* textBoxElement = new Brood::BroodUI::TextBox;
	textBoxElement->SetBodySize( a_size );
	textBoxElement->SetBodyPosition( a_pos );
	textBoxElement->SetFont( *m_font );
	textBoxElement->SetBodyColor( a_color );
	textBoxElement->SetText( a_text );
	textBoxElement->SetEditable( a_isEditable );
	textBoxElement->SetPlaceHolderText( a_placeholderText );

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
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
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

		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
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

		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
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
		panelColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor;
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


// ======================================================================
// ================= end of WorkSpace class =============================
// ======================================================================