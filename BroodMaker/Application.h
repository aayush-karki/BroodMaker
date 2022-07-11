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
	// ================= public member variables =================  
public:
	Application(); // default contructor
	~Application(); // default destructor

	void RunApplicaiton(); // main loop of the program

	// ================= private member variables =================  
private:
	// =========== const variables=============
	const uint32_t m_WINDOW_HEIGHT = 900;
	const uint32_t m_WINDOW_WIDTH = 900;
	// current working directory of the applicaiton
	const std::string cwd = std::filesystem::current_path().string();
	sf::Font m_font;
	sf::RenderWindow m_window; // window obj
	sf::Event m_events; // event object 
	Brood::Application::InitialWorkSpace m_initailWorkSpace; // work spsdaces
	
	bool m_exit;

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


