/*************************************************************************/
/// 
/// @file BoardEditor.h 
/// 
/// @brief  This file is a header file for BoardEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of BoardEditor class.
/// 
/// 
/************************************************************************/
#pragma once
#include "MenuBar.h" // includes all the other uiElements

// =============================== defining namespace =======================
namespace Brood
{
	namespace Application
	{
		// defining what component of this file will be inside namespace BroodUI
		class BoardEditor;
	}
}
// ====================== end of namespace  defination =======================

/// 
/// @ingroup Application
/// @class BoardEditor  "BoardEditor.h"
/// @brief It is a container that bundels elements that is present in
///		BoardEditor workspace
/// 
class Brood::Application::BoardEditor
{
public:
	// default constructor
	BoardEditor();
	// default destructor
	~BoardEditor();

private:
	// add the data needed to setup the boardEditor workspace
};

