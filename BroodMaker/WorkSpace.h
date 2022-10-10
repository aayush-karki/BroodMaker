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
#include "GameDataManager.h"

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

	// initializes the component of a workspace
	virtual void InitializeWorkSpace() = 0;

	// all the logic for the workspace is here
	virtual void Update() = 0;

	// updates all the display elment
	virtual void UpdateAllDispayElement() = 0;

	// draw to the screen
	virtual void Draw( sf::RenderWindow& a_window ) = 0;

	// debugger
	virtual void Debugger() = 0;

	// setter function for game data
	virtual void SetGameDataManager( Brood::Application::Components::GameDataManager* a_gameDataManagerPtr);

	/// @TODO: set the editor or game workspace varialbe here

	// ================= protected member function ==============

	// ===========================================================
	// ===== helper funciton to dynamicallycreate UI elements =====
	// ===========================================================
	
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
											  std::string a_placeholderText = "",
											  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::TextBox* DyCreateTextBox( float a_sizeX, float a_sizeY,
											  float a_posX, float a_posY,
											  std::string a_text = "",
											  bool a_isEditable = false,
											  std::string a_placeholderText = "",
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

	// Dynamically createss a file input Panel Element. 
	//		It has 3 UI element and its layout is 
	//		<textBox prompt> 
	//		<textbox>  
	//		<open butotn>
	void DyCreateFileInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
										 Brood::BroodUI::TextBox** a_txtPromptPtr,
										 Brood::BroodUI::TextBox** a_txtFileInputPtr,
										 Brood::BroodUI::Button** a_btnOpenFilePtr,
										 std::string a_promptToDisplay,
										 std::string a_valueToDisplay,
										 bool a_createFromTop = false );

	// Dynamically createss a Test Input Panel Element. 
	//		It has 2 UI element and its layout is 
	//		<textBox prompt>  <textbox>  
	void DyCreateTextInputPannelElement( sf::RectangleShape* a_panelBodyPtr,
										 Brood::BroodUI::TextBox** a_txtPromptPtr,
										 Brood::BroodUI::TextBox** a_txtTextInputtPtr,
										 std::string a_promptToDisplay,
										 std::string a_valueToDisplay,
										 std::string a_placeHolderText,
										 bool a_createFromTop = false );

	// ===========================================================
	// =========== generalized update functions ==================
	// ===========================================================

	// TODO may be generalize for other editor too
	// TODO maybe could be made like a initializer function
	// TODO make this a signify if the if the element was 
	//		increased, decreased, or none
	
	// checks if the user interacted with the 
	// x size panel Element
	// This is a generalized update SizeX
	void UpdateDecIncSizeX( Brood::BroodUI::Button* a_btnDecSizeX,
							Brood::BroodUI::TextBox* a_txtSizeX,
							Brood::BroodUI::Button* a_btnIncSizeX,
							Brood::BroodUI::UIElement* a_elemnetToChangeSizeX,
							unsigned a_unit,
							unsigned a_lowerLimit,
							unsigned a_upperLimit );

	// checks if the user interacted with the 
	// x size panel Element
	// This is a generalized update SizeY
	void UpdateDecIncSizeY( Brood::BroodUI::Button* a_btnDecSizeY,
							Brood::BroodUI::TextBox* a_txtSizeY,
							Brood::BroodUI::Button* a_btnIncSizeY,
							Brood::BroodUI::UIElement* a_elemnetToChangeSizeY,
							unsigned a_unit,
							unsigned a_lowerLimit,
							unsigned a_upperLimit );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	void UpdateDecIncPosX( Brood::BroodUI::Button* a_btnDecPosX,
						   Brood::BroodUI::TextBox* a_txtPosX,
						   Brood::BroodUI::Button* a_btnIncPosX,
						   Brood::BroodUI::UIElement* a_elemnetToChangePosX,
						   unsigned a_unit,
						   unsigned a_lowerLimit,
						   unsigned a_upperLimit );

	// checks if the user interacted with the Card 
	// x Pos panel Element
	void UpdateDecIncPosY( Brood::BroodUI::Button* a_btnDecPosY,
						   Brood::BroodUI::TextBox* a_txtPosY,
						   Brood::BroodUI::Button* a_btnIncPosY,
						   Brood::BroodUI::UIElement* a_elemnetToChangePosX,
						   unsigned a_unit,
						   unsigned a_lowerLimit,
						   unsigned a_upperLimit );


	// ================= protected data member ==================  
protected:

	/// font
	sf::Font* m_font;

	/// game data
	static Brood::Application::Components::GameDataManager* m_gameData;

	/// stores list of all UI Elements pointer
	std::vector<Brood::BroodUI::UIElement*> m_unNamedUIList;

	/// true if debugger is on
	bool m_isDebugger;
};

// ======================================================================
// ================= end of WorkSpace class =============================
// ======================================================================