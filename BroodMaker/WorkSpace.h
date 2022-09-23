/*************************************************************************/
/// 
/// @file WorkSpace.h 
/// 
/// @brief  This file is a header file for WorkSpace class.
/// 
/// It contains all of the declaration of the member 
///		funciton of WorkSpace class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "MenuBar.h"
#include "DropDownInput.h"
#include "TextBox.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class WorkSpace;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of WorkSpace class ===========================
// ======================================================================

/// 
/// @ingroup Application
/// @class WorkSpace  "WorkSpace.h"
/// @brief a abstract base class that is parent to all the different 
///		workspace.
/// 
class Brood::Application::WorkSpace
{
	// ================= public member function =================  
public:
	// default constructor
	WorkSpace();
	// default destructor
	virtual ~WorkSpace();

	// setter function
	void SetFont( sf::Font* a_font );

	// pure virtual funciton
	virtual void InitializeWorkSpace() = 0; // initializes the component of a workspace
	virtual void Update() = 0; // all the logic for the workspace is here
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw to the screen

	virtual void Debugger() = 0; // debugger

/// @TODO: set the editor or game workspace varialbe here

	// ================= protected member function ==============

	// ===== helper funciton to dynamicallycreate UI elements =====

	// Dynamically create a button, initializes it, and adds
	// it to m_unNameList
	Brood::BroodUI::Button* DyCreateButton( sf::Vector2f a_size,
											sf::Vector2f a_pos,
											std::string a_text = "",
											sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::Button* DyCreateButton( float a_sizeX, float a_sizeY,
											float a_posX, float a_posY,
											std::string a_text = "",
											sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );

	// Dynamically create a textbox, initializes it, and adds
	// it to m_unNameList
	Brood::BroodUI::TextBox* DyCreateTextBox( sf::Vector2f a_size,
											  sf::Vector2f a_pos,
											  std::string a_text = "",
											  bool a_isEditable = false,
											  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::TextBox* DyCreateTextBox( float a_sizeX, float a_sizeY,
											  float a_posX, float a_posY,
											  std::string a_text = "",
											  bool a_isEditable = false,
											  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );

	// Dynamically create a Drop down Input, initializes it, 
	// and adds it to m_unNameList
	Brood::BroodUI::DropDownInput* DyCreateDropDownInput( sf::Vector2f a_size,
														  sf::Vector2f a_pos,
														  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::DropDownInput* DyCreateDropDownInput( float a_sizeX, float a_sizeY,
														  float a_posX, float a_posY,
														  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );

	// Dynamically createss a dropdown input Panel Element. 
	//		It has 2 UI element and its layout is 
	//		<textBox prompt> <dropdown input> 
	void DyCreateDropdownInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
											 Brood::BroodUI::TextBox** a_txtPromptPtr,
											 Brood::BroodUI::DropDownInput** a_ddiPtr,
											 std::string a_promptToDisplay,
											 std::vector<std::string> a_itemsToAdd,
											 unsigned a_firstItemLength = 0,
											 bool a_createFromTop = false );

	// Dynamically createss a Panel Element. 
	//		It has 4 UI element and its layout is 
	//		<textBox prompt> <button '<'> <textbox value> <button '>'> 
	void DyCreateDecIncPannelElement( sf::RectangleShape* a_panelBodyPtr,
									  Brood::BroodUI::TextBox** a_txtPromptPtr,
									  Brood::BroodUI::Button** a_btnDecPtr,
									  Brood::BroodUI::TextBox** a_txtValuePtr,
									  Brood::BroodUI::Button** a_btnIncPtr,
									  std::string a_promptToDisplay,
									  std::string a_valueToDisplay,
									  bool a_createFromTop = false );


	// ================= protected data member ==================  
protected:

	///> font
	sf::Font* m_font;
	std::vector<Brood::BroodUI::UIElement*> m_unNamedUIList; ///> stores list of all UI Elements pointer
	bool m_isDebugger; ///> true if debugger is on
};

// ======================================================================
// ================= end of WorkSpace class =============================
// ======================================================================