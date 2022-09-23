/*************************************************************************/
/// 
/// @file GlobalVariables.cpp
/// 
/// @brief  This file is a source file for GlobalVariables stuct and
///		ColorVariable struct.
/// 
/// It contains all of the location declaration for the member the 
///		structs. 
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "GlobalVariables.h"

// ======================================================================
// ================= start of ST_ColorVariables struct ==================
// ======================================================================

sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_Black = sf::Color::Black;
sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_White = sf::Color::White;

sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_HotOverlay = sf::Color( 186, 189, 201, 50 );
sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_CurrActiveOverlay = sf::Color( 36, 38, 46, 200 );

sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_MainMenu = sf::Color( 64, 73, 79, 255 );
sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_AppPrimaryColor = sf::Color( 73, 85, 123, 255 );
sf::Color Brood::Application::StaticVariables::ST_ColorVariables::stm_AppSecondaryColor = sf::Color( 99, 123, 168, 255 );

// ======================================================================
// ================= end of ST_ColorVariables struct ====================
// ======================================================================
// 
// ======================================================================
// ================= start of ST_GlobalCoreVariables struct =============
// ======================================================================

uint32_t Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_height = 900;
uint32_t Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_window_width = 900;

std::string Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_cwd = std::filesystem::current_path().string(); // current working directory of the applicaiton
sf::Font Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_font; // font

bool Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode = false;
bool Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_exit = false;

uint32_t Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_panelPercentage = 35;

// ======================================================================
// ================= end of ST_GlobalCoreVariables struct ===============
// ======================================================================