/*************************************************************************/
/// 
/// @file Application.h 
/// 
/// @brief  This file is a header file for Application class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Application class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include <filesystem>

#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Card.h"
#include "MouseHandler.h"

#include "TextBox.h"
#include "MenuBar.h"
#include "DropDownInput.h"

#include "HomeWorkSpace.h"

#include "Path.h"
#include "Struct_CtorParam.h"
#include "GlobalVariables.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	///
	/// @ingroup Brood
	/// @addtogroup Application
	/// 
	namespace Application
	{
		class Application;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Application class =========================
// ======================================================================

/// 
/// @ingroup Application
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
	// ================= private member function =================  
private:

	///> polls for any event
	void PollEvents();
	
	///> draws to screen
	void Draw();
	
	void CreateWorkSpace();

	///> calls the UI ELement Debugger
	void Debugger(); 

	// ================= private member variables =================  
private:
	
	///> window obj
	sf::RenderWindow m_window; 
	
	///> event object 
	sf::Event m_events; 

	///> initial workspace object
	Brood::Application::HomeWorkSpace m_mainWorkspace;

	/// @todo delete me
	Brood::Application::Components::Board myBoard;
	Brood::Application::Components::Dice myDice;

};

// ======================================================================
// ================= end of button class ================================
// ======================================================================