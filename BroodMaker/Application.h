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

#include "TextBox.h"
#include "MenuBar.h"
#include "DropDownInput.h"
#include "InitialWorkSpace.h"

#include "struct_path.h"
#include "Struct_CtorParam.h"
#include "GlobalVariables.h"

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

protected:
	void PollEvents();
	void Draw();
	// ================= private member function =================  
private:
	void InitializeMenuBar();
	void Debugger(); // calls the UI ELement Debugger

	void ExecuteMenuItem(unsigned a_iIdx, unsigned a_jIdx);
	
	// ================= private member variables =================  
private:
	// =========== const variables=============
	sf::Font m_font; // font obj 
	sf::RenderWindow m_window; // window obj
	sf::Event m_events; // event object 

	Brood::BroodUI::MenuBar m_menuBar; // menu UI
	Brood::Application::InitialWorkSpace m_initailWorkSpace; // workspaces
};



