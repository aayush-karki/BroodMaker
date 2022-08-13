/*************************************************************************/
/// 
/// @file Application.h 
/// 
/// @brief  This file is a header file for Application class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Application class.
/// 
/// 
/************************************************************************/
#pragma once
#include <filesystem>

#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "MouseHandler.h"

#include "MenuBar.h"
#include "InitialWorkSpace.h"

#include "struct_path.h"
#include "Struct_CtorParam.h"

// =============================== defining namespace =======================
namespace Brood
{
	///
	/// @ingroup Brood
	/// @addtogroup Application
	/// 
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class Application;
	}
}
// ====================== end of namespace  defination =======================

#pragma once

/// 
/// @brief Applicaiton class provides the interface for the applicaiton
///
class Brood::Application::Application

{
	// ================= public member function =================  
public:
	Application(); // default contructor
	~Application(); // default destructor

	void RunApplicaiton(); // main loop of the program

	// ================= private member function =================  
private:
	void InitializeMenuBar();
	
	// ================= private member variables =================  
private:
	// =========== const variables=============
	const uint32_t m_WINDOW_HEIGHT = 900;
	const uint32_t m_WINDOW_WIDTH = 900;
	const std::string m_cwd = std::filesystem::current_path().string(); // current working directory of the applicaiton

	sf::Font m_font; // font obj 
	sf::RenderWindow m_window; // window obj
	sf::Event m_events; // event object 

	Brood::Application::InitialWorkSpace m_initailWorkSpace; // workspaces
	bool m_exit; // stores the state of the application
	Brood::BroodUI::MenuBar m_menuBar; // menu UI
	sf::RectangleShape m_menuBarBg; // backgroud for the menu bar

	/// todo: delete me
	Brood::St_DiceParam* diceParam;
	St_BoardParam* boardParam;
	Board* myBoard;
	Card* myCard;

	Brood::BroodUI::Button myButton;
	Brood::BroodUI::TextBox myTextBox;
	Brood::BroodUI::DropDownMenu myDropDown;
	Brood::BroodUI::MenuBar myMenu;
};



