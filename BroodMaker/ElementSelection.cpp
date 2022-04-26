/*************************************************************************/
/// 
/// @file ElementSelection.cpp 
/// 
/// @brief  This file is a source file for ElementSelection class
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the static data member of
///		ElementSelection class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "ElementSelection.h"

// allocating loaction of the static data member
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_activeElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_hotElementPtr = nullptr;
Brood::BroodUI::Id* Brood::BroodUI::ElementSelection::m_currActiveElementPtr = nullptr;

