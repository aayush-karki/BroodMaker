/*************************************************************************/
/// 
/// @file UIElement.cpp 
/// 
/// @brief  This file is a source file for UIElement class and 
///		struct MapIdToElement which is in BroodUI namespace
/// 
/// It also contains all of the declaration of the static data member of
///		MapIdToElement struct.
/// 
/************************************************************************/

#include "stdafx.h"
#include "UIElement.h"

// declaring the static data member of the MapIdToElement struct
std::map<const int, Brood::BroodUI::UIElement*> Brood::BroodUI::ST_MapIdToElement::stm_mapper;

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**						UIElement's member function declarations					  */
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

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
/// 
Brood::BroodUI::UIElement::UIElement( Brood::BroodUI::ENUM_UIType a_elementType,
									  Brood::BroodUI::UIElement* a_parentPtr,
									  int a_index ) :
	m_elementId( a_parentPtr != nullptr ? a_parentPtr->GetElementIdPtr() : nullptr, a_index ),
	m_elementType( a_elementType )
{
	m_hotOverlayColor = sf::Color( 10, 71, 100, 50 ); // light white overlay
	m_activeOverlayColor = sf::Color( 10, 71, 100, 150 ); // darker white overlay
	m_drawOverlay = false;
}

/// 
/// @virtual
/// @public
/// @brief virtual destructor 
Brood::BroodUI::UIElement::~UIElement()
{
	// delete the this element from its parents child index array
	// check if parent exist
	if( m_elementId.GetParentID() != -1 )
	{
		auto elementParentPtr = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( m_elementId.GetParentID() );
		elementParentPtr->GetElementIdPtr()->DeleteChildIdAtIdx( m_elementId.GetIdIndex() );
	}
}

/// 
/// @virtual
/// @public
/// @brief Setter function to set the element's Position
/// 
/// @param a_pos position of the element 
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
///  
void Brood::BroodUI::UIElement::SetBodyPosition( sf::Vector2f a_pos, bool a_relativeToParent )
{
	// setting up the body position
	if( a_relativeToParent && m_elementId.HasParent() )
	{
		Brood::BroodUI::UIElement* parentPtr = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( m_elementId.GetParentID() );
		sf::Vector2f parentPos = parentPtr->GetBodyPosition();
		a_pos.x += parentPos.x;
		a_pos.y += parentPos.y;
	}

	m_body.setPosition( a_pos );
	m_bodyOverLay.setPosition( a_pos ); // overlay rectangle
}

/// 
/// @public
/// @brief Check if the mouse is hovering over the element
/// 
/// @return true if the mouse is over the element; else false
/// 
bool Brood::BroodUI::UIElement::IsMouseOverElement()
{
	sf::Vector2f elementSize = GetBodySize();
	sf::Vector2f elementPos = GetBodyPosition();

	sf::Vector2i mousePos = Brood::MouseHandler::GetCurrFrameMousePos();

	// chekcing if the mouse curr pos lies inside the element
	if( mousePos.x > elementPos.x && mousePos.x < elementPos.x + elementSize.x &&
		mousePos.y > elementPos.y && mousePos.y < elementPos.y + elementSize.y )
	{
		return true; // the mouse pointer is inside the element
	}

	return false;
}

/// 
/// @public
/// @brief checks if the logics of the element is to be executed or not
/// 
/// In the process updates the element selector --that is current active and hot 
///		element. It also set the overlay
/// 
/// @return true if the elements funciton's is to be executed
/// 
bool Brood::BroodUI::UIElement::DoElement()
{
	bool result = false;

	// check if the mouse is over the element and 
	// update the element selector
	if( IsMouseOverElement() )
	{
		Brood::BroodUI::ElementSelection::SetHotElement( &m_elementId );
	}
	else
	{
		// mouse is not over this element.
		// if the hot element is still this element then 
		// removing the element as the hot element
		if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
		{
			Brood::BroodUI::ElementSelection::SetHotElement( nullptr );
		}
	}

	// checking if the element is active and should we change its active status
	if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetActiveElement() )
	{
		if( Brood::MouseHandler::IsLeftButtonReleased() )
		{
			// pointer is over the element at the time of the button release
			if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
			{
				result = true;
				Brood::BroodUI::ElementSelection::SetCurrActiveElement( &m_elementId );
			}

			// reset the active element
			// as the left mouse button was released the current element should 
			// not be active element
			Brood::BroodUI::ElementSelection::SetActiveElement( nullptr );
		}
	}
	// check if the element is hot and should we make it active and remove currActiveElement
	else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
	{
		if( Brood::MouseHandler::IsLeftButtonPressed() )
		{
			Brood::BroodUI::ElementSelection::SetActiveElement( &m_elementId );
			Brood::BroodUI::ElementSelection::SetCurrActiveElement( nullptr );
		}
	}

	// setting up the over lay
	if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetActiveElement() )
	{
		m_bodyOverLay.setFillColor( m_activeOverlayColor );
		m_drawOverlay = true;
	}
	else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
	{
		m_bodyOverLay.setFillColor( m_hotOverlayColor );
		m_drawOverlay = true;
	}
	else
	{
		m_drawOverlay = false;
	}

	return result;
}


/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**					ST_MapIdToElement's member function declarations				  */
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

/// 
/// @static
/// @public
/// @brief Getter Function
/// 
/// Gets the element that is mapped to from id. if the element was 
///		not found returns nullptr
/// 
/// @param a_id unique id of the element that is mapped to the 
/// 
/// @return pointer to the element whose unique id is the parameter;
/// 
Brood::BroodUI::UIElement* Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( int a_id )
{
	std::map<const int, Brood::BroodUI::UIElement*>::iterator findResult = stm_mapper.find( a_id );

	// return pointer to the element if true else reutrn nullptr
	return findResult != stm_mapper.end() ? findResult->second : nullptr;
}

/// 
/// @static
/// @public
/// @brief adds the id and element to the map
/// 
/// @param a_id unique id of the element that is mapped to the 
/// @param a_elementPtr pointer to the element that has the passed uniquie UI_ID
/// 
/// @return true if adding was successfull; else false
/// 
bool Brood::BroodUI::ST_MapIdToElement::AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr )
{
	auto addResult = stm_mapper.insert( std::pair<int, Brood::BroodUI::UIElement* > {a_id, a_elementPtr} );

	if( !addResult.second )
	{
		// inresertion was not successfull
		std::cerr << "Error! Insertion of UIELmenet with id " << a_id << " failed" << std::endl;
		return false;
	}

	return true;
}

/// 
/// @static
/// @public
/// @brief removes a entry with the id as a key from the map
/// 
/// @param a_id unique id of the element that is mapped to the 
/// 
/// @return true if removal was successfull; else false
/// 
bool Brood::BroodUI::ST_MapIdToElement::ReomveFromMap( int a_id )
{

	auto eraseResult = stm_mapper.erase( a_id );

	if( !eraseResult )
	{
		// removal was not successfull
		std::cerr << "Error! Removal of UIELmenet with id " << a_id << " failed" << std::endl;
		return false;
	}

	return true;
}