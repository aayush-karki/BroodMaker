/*************************************************************************/
/// 
/// @file UIElement.cpp 
/// 
/// @brief  This file is a source file for UIElement class
///		which is in BroodUI namespace
/// 
/// It contains all of the declaration of the static data member of
///		UIElement class.
/// 
/************************************************************************/

#include "stdafx.h"
#include "UIElement.h"

/// 
/// @public
/// @brief default Constructor
/// 
/// Inializes the member variables
/// 
/// @param a_elementType Type of UI element 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// @param a_index the nth child of the parent; 
///		if parent does not exist then -1 -> default value -1
/// @param a_relativeToParent bool to indicate if the position is relative to 
///		parent or not; if false then the position is relative to render screen;
///		-> default false
/// @param a_elementSizeX element's width -> default 0.f
/// @param a_elementSizeY element's length -> default 0.f
/// @param a_elementPosX element's x-position on screen -> default 0.f
/// @param a_elementPosY element's y-position on screen -> default 0.f
/// 
Brood::BroodUI::UIElement::UIElement( Brood::BroodUI::ENUM_UIType a_elementType,
									  Brood::BroodUI::UIElement* a_parentPtr, int a_index,
									  bool a_relativeToParent,
									  float a_elementSizeX, float a_elementSizeY,
									  float a_elementPosX, float a_elementPosY):
	m_elementId( a_parentPtr->GetElementIdPtr(), a_index), m_elementType(a_elementType)
{
	// setting up the body size
	SetBodySize( a_elementSizeX, a_elementSizeY );

	// setting up the body position
	if( a_relativeToParent )
	{
		sf::Vector2f parentPos = a_parentPtr->GetBodyPosition();
		a_elementPosX += parentPos.x;
		a_elementPosY += parentPos.y;
	}
	SetBodyPosition( a_elementPosX, a_elementPosY );

}

/// 
/// @public
/// @brief Inializes the member variables
/// 
/// This contructor is called when a struct ST_UIELementCtorParam is passed 
/// 
/// @param a_ctorParam reference to ST_UIELementCtorParam struct
///  
Brood::BroodUI::UIElement::UIElement( Brood::BroodUI::ST_UIELementCtorParam& a_ctorParam ):
	UIElement(a_ctorParam.stm_elementType, a_ctorParam.stm_parentPtr, a_ctorParam.stm_index,
			   a_ctorParam.stm_relativeToParent, 
			   a_ctorParam.stm_elementSizeX, a_ctorParam.stm_elementSizeY,
			   a_ctorParam.stm_elementPosX, a_ctorParam.stm_elementPosY)
{}

Brood::BroodUI::UIElement::~UIElement()
{
	// delete the this element from its parents child index array
	// check if parent exist
	if( m_elementId.GetParentID() != -1 )
	{
		m_elementId.GetParent()->DeleteChildIdAtIdx( m_elementId.GetIdIndex() );
	}
}

