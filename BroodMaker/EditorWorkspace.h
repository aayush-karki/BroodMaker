/*************************************************************************/
/// 
/// @file EditorWorkspace.h 
/// 
/// @brief  This file is a header file for InitialWorkSpace class.
/// 
/// It contains all of the declaration of the member 
///		funciton of InitialWorkSpace class.
/// 
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "WorkSpace.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class EditorWorkspace;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of EditorWorkspace class =====================
// ======================================================================

///
/// @ingroup Application
/// @class BoardEditor  "EditorWorkspace.h"
/// @brief It is a container that bundels and control all the different 
///		editor workspace, namely Board Editor, Tile Editor, Path Editor, and
///		Deck Editor
/// 
/// Editor WorkSpace is where the user edit or tweek different setting to make
///		a game project
/// 
/// Derived from the WorkSpace class 
/// 
class Brood::Application::EditorWorkspace : public Brood::Application::WorkSpace
{};

// ======================================================================
// ================= end of EditorWorkspace class =======================
// ======================================================================