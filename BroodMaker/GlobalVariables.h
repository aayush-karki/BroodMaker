/**************************************************************************/
/// 
/// @file GlobalVariables.h 
/// 
/// @brief  This file is a header file for color variables
/// 
/// It contains all of the variables and defines for the 
///		color variables
/// 
/*************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace StaticVariables
	{
		struct ST_ColorVariables;
		struct ST_GlobalCoreVariables;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ST_ColorVariables struct ==================
// ======================================================================

/// 
/// @ingroup Application
/// @struct ST_ColorVariables "GlobalVariables.h"
/// @brief static struct for all the colors used in the applicaiton
///
struct Brood::Application::StaticVariables::ST_ColorVariables
{
	// black and white color
	static sf::Color stm_Black; ///> sf::Color::Black
	static sf::Color stm_White; ///> sf::Color::White

	// overlay colors
	static sf::Color stm_HotOverlay; ///> Lavender Gray with alpha of 50
	static sf::Color stm_CurrActiveOverlay; ///> Raisin Black with alpha of 200


	static sf::Color stm_MainMenu; // Charcoal
	static sf::Color stm_AppPrimaryColor; ///> Purple Navy
	static sf::Color stm_AppSecondaryColor; ///> Pastel Pink

	// sf::Color( 57, 229, 220, 255 ) ); 
};
// ======================================================================
// ================= end of ST_ColorVariables struct ====================
// ======================================================================

// ======================================================================
// ================= start of ST_GlobalCoreVariables struct =============
// ======================================================================

/// 
/// @ingroup Brood
/// @struct ST_ColorVariables "GlobalVariables.h"
/// @brief static struct for all the global Core Variables
///
struct Brood::Application::StaticVariables::ST_GlobalCoreVariables
{
	static uint32_t stm_window_height;
	static uint32_t stm_window_width;
	static std::string stm_cwd; // current working directory of the applicaiton
	static bool stm_is_debug_mode; // true if debug mode is on
	static bool stm_exit; // stores the state of the application
};

// ======================================================================
// ================= end of ST_GlobalCoreVariables struct ===============
// ======================================================================


