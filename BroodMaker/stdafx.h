/*************************************************************************/
/// 
/// @file stdafx.h 
/// 
/// @brief  This file is a include file for include files which are not
///		changed infrequently
/// 
/// @note visusal studio uses this as precompile header 
/// 
/*************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// standard include files
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib> // for rand
//#include <ctime>
#include <list>
#include <string>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <limits>

// sfml include files
#include <SFML/Graphics.hpp>
