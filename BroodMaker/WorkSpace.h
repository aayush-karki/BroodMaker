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

	// pure virtual funciton
	virtual void InitializeWorkSpace() = 0; // initializes the component of a workspace
	virtual void Update() = 0; // all the logic for the workspace is here
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw to the screen

	virtual void Debugger() = 0; // debugger

/// @TODO: set the editor or game workspace varialbe here

	// ================= protected member function ==============

	// ===== helper funciton to create UI elements =====

	Brood::BroodUI::Button* DyCreateButton(sf::Vector2f a_size, sf::Vector2f a_pos, std::string a_text = "",
											sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::Button* DyCreateButton( float a_sizeX, float a_sizeY, float a_posX, float a_posY, std::string a_text = "",
											sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::TextBox* DyCreateTextBox( sf::Vector2f a_size, sf::Vector2f a_pos, std::string a_text = "",
											  bool a_isEditable = false,
											  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );
	Brood::BroodUI::TextBox* DyCreateTextBox( float a_sizeX, float a_sizeY,
											  float a_posX, float a_posY, std::string a_text = "",
											  bool a_isEditable = false,
											  sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor );

	// ================= protected data member ==================  
protected:
	sf::Font m_font; ///> font
	std::vector<Brood::BroodUI::UIElement*> m_allUIList; ///> stores list of all UI Elements pointer
	bool m_isDebugger; ///> true if debugger is on
};

// ======================================================================
// ================= end of WorkSpace class =============================
// ======================================================================