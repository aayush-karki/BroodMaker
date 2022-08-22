/*************************************************************************/
/// 
/// @file UIElement.cpp 
/// 
/// @brief  This file is a source file for UIElement class and 
///		struct MapIdToElement which is in BroodUI namespace
/// 
/// It also contains all of the declaration of the UIElement class's
///		member function.
/// It also contains all of the declaration of the static data member of
///		MapIdToElement struct.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "UIElement.h"

// declaring the static data member of the MapIdToElement struct
std::map<const int, Brood::BroodUI::UIElement*> Brood::BroodUI::ST_MapIdToElement::stm_mapper;

// ======================================================================
// ================= start of UIElement class ===========================
// ======================================================================

/// 
/// @public
/// @brief default Constructor
/// 
/// Inializes the member variables and adds it to the id to element map.
/// 
///	Sets hotelement overlay color to lighter overlay and 
///		sets activeOvelay to a darker overlay.
/// 
/// @param a_elementType Type of UI element 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::BroodUI::UIElement::UIElement( Brood::BroodUI::ENUM_UIType a_elementType,
									  Brood::BroodUI::UIElement* a_parentPtr ) :
	m_elementId( a_parentPtr != nullptr ? a_parentPtr->GetElementIdPtr() : nullptr ),
	m_elementType( a_elementType )
{
	// adding the elementID to map
	Brood::BroodUI::ST_MapIdToElement::AddToMap( GetElementIdPtr()->GetElementID(), this );

	// setting the overlay
	m_hotOverlayColor = sf::Color( 10, 71, 100, 50 ); // light white overlay
	m_activeOverlayColor = sf::Color( 10, 71, 100, 150 ); // darker white overlay
	m_drawOverlay = false;
}

/// 
/// @public
/// @virtual
/// @brief virtual destructor 
/// 
/// Deletes element form the parent's child list if parent exist and
///		assigns the its child element to the parent element if parent exist.
///		And finally deletes its id from the id to element map.
/// 
Brood::BroodUI::UIElement::~UIElement()
{
	Brood::BroodUI::UIElement* elementParentPtr = nullptr;

	// check if parent exist
	if( m_elementId.HasParent() )
	{
		// delete the this element from its parents child index array
		elementParentPtr = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( m_elementId.GetParentID() );
		int childIdx = elementParentPtr->GetElementIdPtr()->GetChildIdx( &m_elementId );
		elementParentPtr->GetElementIdPtr()->DeleteChildIdAtIdx( childIdx );
	}

	if( m_elementId.HasChild() )
	{
		// assigning the child to parent
		for( unsigned i = 0; i < m_elementId.GetTotalChildNum(); ++i )
		{
			auto childId = m_elementId.GetChildIdAtIdx( i );
			elementParentPtr->GetElementIdPtr()->AddChild( childId );
			childId->SetParent( elementParentPtr->GetElementIdPtr() );
		}
	}

	// delete the id form the map
	Brood::BroodUI::ST_MapIdToElement::ReomveFromMap( m_elementId.GetElementID() );
}

/// 
/// @public
/// @brief getter function to get the element type
/// 
/// @return the element type
/// 
const Brood::BroodUI::ENUM_UIType Brood::BroodUI::UIElement::GetElementType() const
{
	return m_elementType;
}

/// 
/// @public
/// @brief Getter function to get a reference to the element
/// 
/// @return constant reference to the element
/// 
const sf::RectangleShape& Brood::BroodUI::UIElement::GetBody() const
{
	return m_body;
}

/// 
/// @public
/// @brief Getter function to get the positon of the element
/// 
/// @return postion of the element
///
const sf::Vector2f Brood::BroodUI::UIElement::GetBodyPosition() const
{
	return m_body.getPosition();
}

/// 
/// @public
/// @brief Getter function to get the size of element
/// 
/// @return size of the body
///
const sf::Vector2f Brood::BroodUI::UIElement::GetBodySize() const
{
	return m_body.getSize();
}

/// 
/// @public
/// @brief Getter function to get the element's body color
/// 
/// @reutrn color of the body
///
const sf::Color Brood::BroodUI::UIElement::GetBodyColor()
{
	return m_body.getFillColor();
}

/// 
/// @public
/// @brief Getter function to get the element's active overlay color
/// 
/// @reutrn color of the body when it is active
///
const sf::Color Brood::BroodUI::UIElement::GetActiveOverlayColor()
{
	return m_activeOverlayColor;
}

/// 
/// @public
/// @brief Getter function to get the element's hot overlay color
/// 
/// @reutrn color of the body when it is hot
///
const sf::Color Brood::BroodUI::UIElement::GetHotOverlayColor()
{
	return m_hotOverlayColor;
}

/// 
/// @public
/// @brief Getter function to get the pointer to the element Id object
/// 
/// @return  pointer to the element Id
/// 
Brood::BroodUI::Id* Brood::BroodUI::UIElement::GetElementIdPtr()
{
	return &m_elementId;
}

/// 
/// @public
/// @brief Setter function to set the element body color
/// 
/// @param a_bodyColor color of the body
///
void Brood::BroodUI::UIElement::SetBodyColor( sf::Color a_bodyColor )
{
	m_body.setFillColor( a_bodyColor );
}

/// 
/// @public
/// @virtual
/// @brief Setter function to set the element's Size
/// 
/// @param a_size size of the element
/// 
void Brood::BroodUI::UIElement::SetBodySize( sf::Vector2f a_size )
{
	m_body.setSize( a_size );
	m_bodyOverLay.setSize( a_size ); // overlay rectangle
}

/// 
/// @public
/// @virtual
/// @overload
/// @brief Setter function to set the element's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
/// 
void Brood::BroodUI::UIElement::SetBodySize( float a_sizeX, float a_sizeY )
{
	Brood::BroodUI::UIElement::SetBodySize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @public
/// @virtual
/// @brief Setter function to set the element's Position
/// 
/// It can also set the position relative to its parent if exist by passing a second 
///		parameter to true. If second parameter is pass as true and na parent does not
///		exist then it sets the position as it is 
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
	m_bodyOverLay.setPosition( a_pos ); 
}

/// 
/// @public
/// @virtual
/// @overload
/// @brief Setter function to set the element's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
void Brood::BroodUI::UIElement::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Setter function to set the element's active color
/// 
/// @param a_color color of the body when it is active
///
void Brood::BroodUI::UIElement::SetActiveOverlayColor( sf::Color a_color )
{
	m_activeOverlayColor = a_color;
}

/// 
/// @public
/// @brief Setter function to set the element's hot color
/// 
/// @param a_color color of the body when it is hot
///
void Brood::BroodUI::UIElement::SetHotOverlayColor( sf::Color a_color )
{
	m_hotOverlayColor = a_color;
}

/// 
/// @public
/// @brief Setter function to set if the overlay is to be drawn or not
/// 
/// @param a_drawOverlay true if the overlay is to be drawn
//
void Brood::BroodUI::UIElement::SetDrawOverlay( bool a_drawOverlay )
{
	m_drawOverlay = a_drawOverlay;
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
/// @brief Checks if the element is the active element or not
/// 
/// @return true if it is the active element; else false
/// 
bool Brood::BroodUI::UIElement::IsActiveElement()
{
	return Brood::BroodUI::ElementSelection::GetActiveElement()->GetElementID() == m_elementId.GetElementID();
}

///
/// @public
/// @brief Checks if the element is the current active element or not
/// 
/// @return true if it is the curr active element; else false
/// 
bool Brood::BroodUI::UIElement::IsCurrActiveElement()
{
	return Brood::BroodUI::ElementSelection::GetCurrActiveElement()->GetElementID() == m_elementId.GetElementID();
}

///
/// @public
/// @brief Checks if the element is the hot element or not
/// 
/// @return true if it is the hot element; else false
/// 
bool Brood::BroodUI::UIElement::IsHotElement()
{
	return ElementSelection::GetHotElement()->GetElementID() == m_elementId.GetElementID();
}

/// 
/// @public
/// @brief checks if the logics of the element is to be executed or not
/// 
/// It checks the mouse position and button state to determine if to execute the 
///		elements logic or not. It does this by manupulating the element selection class.
///		It also set the overlay
/// 
/// @return true if the element's funciton is to be executed; else false
/// 
bool Brood::BroodUI::UIElement::DoElement()
{
	bool result = false;

	// check if the mouse is over the element and 
	// update the element selector
	if( IsMouseOverElement() )
	{
		// checking if for this frame the hot element is already found.
		// we need to check this so that if 2 elements overlap with eachother 
		// then we need to prevent the element below from being hot element.
		// we can do this safely as we know that the do element is called form
		// top to bottom, and only moves to next element once its child element 
		// are dealt with. This is specifically the case for the drop downs
		if( !Brood::BroodUI::ElementSelection::GetHotElementFlag() )
		{
			// setting the hot element as no other element was set as one before
			Brood::BroodUI::ElementSelection::SetHotElement( &m_elementId );
			// setting the hot element flag as true
			Brood::BroodUI::ElementSelection::SetHotElementFlag( true );
		}

		// this if-code-block makes it so that the if a menu of a memubar is open
		// then hover over its sibiling menus should expand/open the sibling menu.
		// 
		// if current active element's parent and hot element parent are the 
		// same then set the hot element as the current active element
		if( m_elementType == Brood::BroodUI::ENUM_UIType::UI_dropDownMenu &&
			Brood::BroodUI::ElementSelection::GetCurrActiveElement() != nullptr )
		{
			// getting the curr active element's elementId
			const Brood::BroodUI::Id* currActiveId = Brood::BroodUI::ElementSelection::GetCurrActiveElement();
			const int currActiveElementId = currActiveId->GetElementID();

			// getting the pointer to curr active element
			Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );

			if( currActiveElement->m_elementType == Brood::BroodUI::ENUM_UIType::UI_dropDownMenu &&
				GetElementIdPtr()->GetParentID() == currActiveId->GetParentID() )
			{
				Brood::BroodUI::ElementSelection::SetCurrActiveElement( &m_elementId );
			}
		}
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
			// checking if the pointer is over the element at the time of the button release
			if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
			{
				result = true;
				Brood::BroodUI::ElementSelection::SetCurrActiveElement( &m_elementId );
			}
			else
			{
				// resetting the active element
				// as the left mouse button was released the current element should 
				// not be active element
				Brood::BroodUI::ElementSelection::SetCurrActiveElement( nullptr );
				Brood::BroodUI::ElementSelection::SetActiveElement( nullptr );
			}
		}
	}
	// check if the element is hot and should we make it active and remove currActiveElement
	else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElement() )
	{
		if( Brood::MouseHandler::IsLeftButtonPressed() )
		{
			Brood::BroodUI::ElementSelection::SetActiveElement( &m_elementId );

			// if the parent element of the element where a left click was made
			// is a dropdown menu  and the parent element is the CurrActiveElement  then
			// it should not be changed on left click as the left click was done inside the 
			// dropdown menus area.
			// if this is not true than different element was click so set currActiveElement to 
			// nullptr

			// getting the curr active element's elemetnId
			const Brood::BroodUI::Id* currActiveId = Brood::BroodUI::ElementSelection::GetCurrActiveElement();
			if( currActiveId != nullptr )
			{
				const int currActiveElementId = currActiveId->GetElementID();

				// getting the pointer to this element's parent's elementId
				Brood::BroodUI::UIElement* currActiveElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( currActiveElementId );
				const int parentElementID = GetElementIdPtr()->GetParentID();

				if( parentElementID != -1 )
				{
					Brood::BroodUI::UIElement* parentElement = Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( parentElementID );
					if( parentElement->m_elementType != Brood::BroodUI::ENUM_UIType::UI_dropDownMenu ||
						parentElementID != currActiveId->GetElementID() )
					{
						Brood::BroodUI::ElementSelection::SetCurrActiveElement( nullptr );
					}
				}
				else
				{
					Brood::BroodUI::ElementSelection::SetCurrActiveElement( nullptr );
				}

			}
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
	else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElement() &&
			 m_elementType == Brood::BroodUI::ENUM_UIType::UI_dropDownMenu )
	{
		m_bodyOverLay.setFillColor( m_activeOverlayColor );
		m_drawOverlay = true;
	}
	else
	{
		m_drawOverlay = false;
	}

	return result;
}

///
/// @public
/// @virtual
/// @brief Draws the body to the render window
/// 
/// @param a_window reference to the render window
/// 
void Brood::BroodUI::UIElement::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_body );

	// draw the over lay only if the overlay is turned on
	if( m_drawOverlay )
	{
		a_window.draw( m_bodyOverLay );
	}
}

// ======================================================================
// ================= end of UIElement class =============================
// ======================================================================


// ======================================================================
// ================= start of ST_MapIdToElement struct ==================
// ======================================================================

/// 
/// @static
/// @public
/// @brief Getter Funciton to get a reference to the map
/// 
/// @return reference to the map
/// 
std::map<const int, Brood::BroodUI::UIElement*>& Brood::BroodUI::ST_MapIdToElement::GetMap()
{
	return stm_mapper;
}

/// 
/// @static
/// @public
/// @brief Getter Function to get the element that is mapped to from ui id. 
/// 
/// @param a_id unique id of the element that maps to its element pointer
/// 
/// @return pointer to the element whose unique id was mapped to; 
///		else returns nullptr if not matched
/// 
Brood::BroodUI::UIElement* Brood::BroodUI::ST_MapIdToElement::GetElementPtrFromMap( int a_id )
{
	std::map<const int, Brood::BroodUI::UIElement*>::iterator findResult = stm_mapper.find( a_id );

	// return pointer to the element if true else reutrn nullptr and log it
	if( findResult == stm_mapper.end() )
	{
		std::cerr << "Error! Could not find a UIELmenet with id " << a_id << "." << std::endl;
		return nullptr;
	}
	return findResult->second;
}

/// 
/// @static
/// @public
/// @brief adds the id and element to the map
/// 
/// @param a_id unique id of the element that is mapped to its element pointer
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
/// @param a_id unique id of the element that is mapped to its element pointer
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

// ======================================================================
// ================= end of ST_MapIdToElement struct ====================
// ======================================================================