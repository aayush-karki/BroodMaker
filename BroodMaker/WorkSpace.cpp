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

#include "stdafx.h"
#include "WorkSpace.h"

/// 
/// @public
/// @brief default constructor
///
Brood::Application::WorkSpace::WorkSpace() : m_isDebugger( false ) 
{}

/// 
/// @public
/// @virtual
/// @brief default destructor
///
Brood::Application::WorkSpace::~WorkSpace()
{}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a button element and set its elements
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the button element
/// @param a_pos  postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default Brood::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
/// 
Brood::BroodUI::Button* Brood::Application::WorkSpace::DyCreateButton( sf::Vector2f a_size, sf::Vector2f a_pos,
																	   std::string a_text, sf::Color a_color )
{
	Brood::BroodUI::Button* buttonElement = new Brood::BroodUI::Button;
	buttonElement->SetBodySize( a_size );
	buttonElement->SetBodyPosition( a_pos );
	buttonElement->SetFont( m_font );
	buttonElement->SetBodyColor( a_color );
	buttonElement->SetText( a_text );
	
	// adding the newly created button to the UI elmente list
	m_allUIList.push_back( buttonElement );

	return buttonElement;
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a button element and set its elements
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the button element
/// @param a_sizeY width of the button element
/// @param a_posX x-postion of the button element
/// @param a_posY y-postion of the button element
/// @param a_text text to display in the button element ; default ""
/// @param a_color color of the button element ; default Brood::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created Button element
///
Brood::BroodUI::Button* Brood::Application::WorkSpace::DyCreateButton( float a_sizeX, float a_sizeY,
																	   float a_posX, float a_posY, 
																	  std::string a_text, sf::Color a_color )
{
	return Brood::Application::WorkSpace::DyCreateButton( { a_sizeX, a_sizeY }, { a_posX, a_posY },
														  a_text, a_color );
}

/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a textbox element and set its elements
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_size size of the textbox element
/// @param a_pos  postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; default Brood::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///  
Brood::BroodUI::TextBox* Brood::Application::WorkSpace::DyCreateTextBox( sf::Vector2f a_size, sf::Vector2f a_pos,
																		 std::string a_text, bool a_isEditable, 
																		 sf::Color a_color)
{
	Brood::BroodUI::TextBox* textBoxElement = new Brood::BroodUI::TextBox;
	textBoxElement->SetBodySize( a_size );
	textBoxElement->SetBodyPosition( a_pos );
	textBoxElement->SetFont( m_font );
	textBoxElement->SetBodyColor( a_color );
	textBoxElement->SetText( a_text );
	textBoxElement->SetEditable( a_isEditable );

	// adding the newly created textbox to the UI elmente list
	m_allUIList.push_back( textBoxElement );

	return textBoxElement;
}


/// 
/// 
/// @protected
/// @overlaoded
/// @brief helper function to dynamically create a textbox element and set its elements
/// 
/// @note assumes that m_font is loaded
/// 
/// @param a_sizeX length of the textbox element
/// @param a_sizeY width of the textbox element
/// @param a_posX x-postion of the textbox element
/// @param a_posY y-postion of the textbox element
/// @param a_text text to display in the textbox element ; default ""
/// @param a_isEditable true if the text box is editable; default false
/// @param a_color color of the textbox element ; default Brood::ST_ColorVariables::stm_AppPrimaryColor
/// 
/// @return pointer to dynamically created textbox element
///
Brood::BroodUI::TextBox* Brood::Application::WorkSpace::DyCreateTextBox( float a_sizeX, float a_sizeY, 
																		 float a_posX, float a_posY, 
																		 std::string a_text, bool a_isEditable, 
																		 sf::Color a_color )
{
	return Brood::Application::WorkSpace::DyCreateTextBox( { a_sizeX, a_sizeY }, { a_posX, a_posY },
														   a_text, a_isEditable, a_color );
}
