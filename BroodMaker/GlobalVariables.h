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
	/// 
	/// @addtogroup Application
	/// 
	namespace StaticVariables
	{
		struct ST_ColorVariables;
		struct ST_GlobalCoreVariables;
		struct ST_Folders;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ST_ColorVariables struct ==================
// ======================================================================

/// 
/// @ingroup StaticVariables
/// @struct ST_ColorVariables "GlobalVariables.h"
/// @brief static struct for all the colors used in the applicaiton
///
struct Brood::Application::StaticVariables::ST_ColorVariables
{
	// ========== black and white color ========
	
	/// sf::Color::Black
	static sf::Color stm_Black; 
	
	/// sf::Color::White
	static sf::Color stm_White; 

	// ======== overlay colors ==========
	
	/// Lavender Gray with alpha of 50
	static sf::Color stm_HotOverlay; 
	
	/// Raisin Black with alpha of 200
	static sf::Color stm_CurrActiveOverlay; 

	// ======== other colors ==========

	/// Charcoal
	static sf::Color stm_MainMenu;
	
	/// Purple Navy
	static sf::Color stm_AppPrimaryColor; 
	
	/// Pastel Pink
	static sf::Color stm_AppSecondaryColor;
	
	/// Venetian Red
	static sf::Color stm_ErrorColor; 

	/// generates random color
	static sf::Color GetRandomColor();
};
// ======================================================================
// ================= end of ST_ColorVariables struct ====================
// ======================================================================

// ======================================================================
// ================= start of ST_GlobalCoreVariables struct =============
// ======================================================================

/// 
/// @ingroup StaticVariables
/// @struct ST_ColorVariables "GlobalVariables.h"
/// @brief static struct for all the global Core Variables
///
struct Brood::Application::StaticVariables::ST_GlobalCoreVariables
{
	/// holds the application height
	static uint32_t stm_window_height;

	/// holds the application width
	static uint32_t stm_window_width;

	/// stores the font that is used through out the applicaiton
	static sf::Font stm_font;

	/// holds the state of debugger; true if debug mode is on
	static bool stm_is_debug_mode; 


	/// stores the state of the application; false if the application 
	///	is running
	static bool stm_exit; 

	/// holds the percentage of size of the application side pannel
	///	compare to the applicaiton window
	static uint32_t stm_panelPercentage;
};

// ======================================================================
// ================= end of ST_GlobalCoreVariables struct ===============
// ======================================================================



// ======================================================================
// ================= start of ST_Folders struct =========================
// ======================================================================

/// 
/// @ingroup StaticVariables
/// @struct ST_ColorVariables "GlobalVariables.h"
/// @brief static struct for all path to folder
///
struct Brood::Application::StaticVariables::ST_Folders
{
	/// current working directory of the applicaiton
	static std::filesystem::path stm_cwd;

	/// path to assets folder. It is a sub folder of CWD
	static std::filesystem::path stm_assets;

	/// path to font folder. It is a sub folder of Assets folder
	static std::filesystem::path stm_fonts;

	/// path to Texture folder. It is a sub folder of Assets folder
	static std::filesystem::path stm_Textures;

	/// path to diceTexture folder. It is a sub folder of Textures folder
	static std::filesystem::path stm_diceTextures;

	/// path to playerTextures folder. It is a sub folder of Textures folder
	static std::filesystem::path stm_playerTextures;
};

// ======================================================================
// ================= end of ST_Folders struct ===========================
// ======================================================================


