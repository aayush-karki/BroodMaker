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
	m_elementType( a_elementType ), m_fontSize( 0 ), m_isSelected( false ), 
	m_textContent(""), m_debugTextSave ("")
{
	// adding the elementID to map
	Brood::BroodUI::ST_MapIdToElement::AddToMap( GetElementIdPtr()->GetElementID(), this );

	// setting the overlay
	m_hotOverlayColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_HotOverlay; 
	m_activeOverlayColor = Brood::Application::StaticVariables::ST_ColorVariables::stm_CurrActiveOverlay;
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
/// @overload
/// @brief getter funciton to get if the element is curretly selected or not
/// 
/// @return true if it is currently selected; else false
/// 
const bool Brood::BroodUI::UIElement::IsSelected() const
{
	return m_isSelected;
}

/// 
/// @public
/// @brief getter funciton to get the user typed text that is stored in the element
/// 
/// @return all the user typed text that is stored in the element
/// 
std::string Brood::BroodUI::UIElement::GetText() const
{
	return m_text.getString();
}

/// 
/// @public
/// @brief getter funciton to get the font size
/// 
/// @return size of the font
/// 
unsigned int Brood::BroodUI::UIElement::GetFontSize() const
{
	return m_fontSize;
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
	// checking if the new height for the body is greater than the charsize by 2
	// font size has not been inialized
	if( a_size.y >= m_fontSize + 2  || m_fontSize == 0 )
	{
		m_body.setSize( a_size ); // setting the body size
		m_bodyOverLay.setSize( a_size ); // overlay rectangle
	}
	else if( a_size.y < m_fontSize )
	{
		std::cerr << "body height cannot be smaller than font Size cannot" << std::endl;
		return;
	}
	else
	{
		std::cerr << "body height needs to be 2 pixel bigger than font size" << std::endl;
		return;
	}
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

	// setting the text position
	if( m_text.getString() != "" )
	{
		Brood::BroodUI::UIElement::SetTextPosition();
	}
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
/// @brief setter function to set the font size
/// 
void Brood::BroodUI::UIElement::SetFont( sf::Font& a_font )
{
	m_font = &a_font;
	m_text.setFont( a_font );
}

/// 
/// @public
/// @brief setter function to set the Font color
/// 
/// param a_color font color -> default sf::Color::White
/// 
void Brood::BroodUI::UIElement::SetFontColor( sf::Color a_color )
{
	m_text.setFillColor( a_color );
}

/// 
/// @public
/// @brief setter function to set the Font size
/// 
/// @note If the font size is more than body height by
/// 
/// @param a_charSize -> size of indivisual character in the SetEditabletext -> deafult 12
/// 
void Brood::BroodUI::UIElement::SetFontSize( int a_fontSize )
{
	float bodyHeight = GetBodySize().y;

	// checking menu bar height
	if( bodyHeight <= 2 )
	{
		std::cerr << "The body height is less than or equal to 2." << std::endl
			<< "Set the body height to more than 2 before setting the font size" << std::endl;
		return;
	}
	// checking if fontsize is greater than menu height - 2
	else if( a_fontSize > bodyHeight - 2 )
	{
		std::cerr << "Font size is more than the body height - 2." << std::endl
			<< "Setting the font size to current body height - 2" << std::endl
			<< "Setting the font size to " << bodyHeight - 2 << std::endl;
		m_fontSize = ( unsigned )bodyHeight - 2;
	}
	else
	{
		m_fontSize = ( unsigned )a_fontSize;
	}

	m_text.setCharacterSize( m_fontSize );
}

/// 
/// @public
/// @brief setter function to set the text that is displayed in the button
/// 
/// @warning It assumes that the font for the text is already set
/// 
/// @param a_text text to show on the buttom -> default empty string
/// 
void Brood::BroodUI::UIElement::SetText( std::string a_text )
{
	m_text.setString( a_text );
	m_textContent = a_text;

	m_drawText = ( a_text != "" );

	Brood::BroodUI::UIElement::SetTextPosition();
}

/// 
/// @public
/// @brief setter function to set the state of the element i.e. if it is 
///		seleected or not
/// 
/// @param a_selected true if current text box is selected or not
/// 
void Brood::BroodUI::UIElement::SetSelected( bool a_selected )
{
	m_isSelected = a_selected;
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
void Brood::BroodUI::UIElement::SetDrawOverlay(  )
{
	// setting up the over lay
	if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetAlmostActiveElementIdPtr() ||
		GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() )
	{
		m_bodyOverLay.setFillColor( m_activeOverlayColor );
		m_drawOverlay = true;
	}
	else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElementIdPtr() )
	{
		m_bodyOverLay.setFillColor( m_hotOverlayColor );
		m_drawOverlay = true;
	}
	else
	{
		m_drawOverlay = false;
	}
}

/// 
/// @public
/// @brief changes the text of the element to its the element ID when debug is on
///		and changes it back to the text it had before debugging when debug is off.
/// 
void Brood::BroodUI::UIElement::Debugger()
{
	if( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_is_debug_mode )
	{
		// saving the text
		m_debugTextSave = m_textContent;

		// chaning the text to UI ID
		SetText( std::to_string( GetElementIdPtr()->GetElementID() ) );
	}
	else
	{
		SetText( m_debugTextSave );
	}
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
	return Brood::BroodUI::ElementSelection::GetAlmostActiveElementIdPtr()->GetElementID() == m_elementId.GetElementID();
}

///
/// @public
/// @brief Checks if the element is the current active element or not
/// 
/// @return true if it is the curr active element; else false
/// 
bool Brood::BroodUI::UIElement::IsCurrActiveElement()
{
	return Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr()->GetElementID() == m_elementId.GetElementID();
}

///
/// @public
/// @brief Checks if the element is the hot element or not
/// 
/// @return true if it is the hot element; else false
/// 
bool Brood::BroodUI::UIElement::IsHotElement()
{
	return ElementSelection::GetHotElementIdPtr()->GetElementID() == m_elementId.GetElementID();
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
	bool doElement = false;

	// if the mouse is over this the element and a hot element is not already found
	// then set this element as the hot element 
	//
	// we need to check to see if hot element was already found or not
	// so that if 2 elements overlap with eachother then we need to prevent 
	// the element below from being hot element.
	// we can do this safely as we know that the do element is called form
	// top to bottom, and only moves to next element once its child element 
	// are dealt with. This is specifically the case when drop downs is open.
	//
	if( IsMouseOverElement() && !Brood::BroodUI::ElementSelection::GetHotElementIdFlag() )
	{
		Brood::BroodUI::ElementSelection::SetHotElementIdPtr( GetElementIdPtr() );
		Brood::BroodUI::ElementSelection::SetHotElementIdPtrFlag( true );
	}
	// mouse is not over this element
	// checking if the this element was previously hot element
	else if ( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElementIdPtr() )
	{
		Brood::BroodUI::ElementSelection::SetHotElementIdPtr( nullptr );
	}
	// for left button press
	// check if the element is hot and if the left mouse button was pressed 
	// then set it as almostActive Element
	if( Brood::MouseHandler::IsLeftButtonPressed() &&
		GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElementIdPtr() )
	{
		Brood::BroodUI::ElementSelection::SetAlmostActiveElementIdPtr( &m_elementId );
	}
	// for almost active element
	// checking if the element is almost active and should we change its almost active status
	else if( Brood::MouseHandler::IsLeftButtonReleased() )
	{
		if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetAlmostActiveElementIdPtr() )
		{
			// checking if the mouse is over the element at the time of the button release
			if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetHotElementIdPtr() )
			{
				doElement = true;
				if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() != nullptr )
				{
					Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() );
				}
				Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( &m_elementId );
			}
			else
			{
				// resetting the currActiveElement 
				// saving the lastActiveElement
				if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() != nullptr )
				{
					Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() );
				}
				// as the left mouse button was released the current element should 
				// not be active element
				Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );

			}
			// resetting the almostActiveElement cause left mouse button was released
			Brood::BroodUI::ElementSelection::SetAlmostActiveElementIdPtr( nullptr );
		}
		// checking if the left mouse butoon was released outside of the elment when the element
		// is also currActive element then setting the curr active to null
		else if( GetElementIdPtr() == Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() &&
				 GetElementIdPtr() != Brood::BroodUI::ElementSelection::GetHotElementIdPtr() &&
				 !IsSelected())
		{
			if( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() != nullptr )
			{
				Brood::BroodUI::ElementSelection::SetLastActiveElementIdPtr( Brood::BroodUI::ElementSelection::GetCurrActiveElementIdPtr() );
			}
			Brood::BroodUI::ElementSelection::SetCurrActiveElementIdPtr( nullptr );

			// resetting the almostActiveElement cause left mouse button was released
			Brood::BroodUI::ElementSelection::SetAlmostActiveElementIdPtr( nullptr );
		}
	}

	// setting up overlay
	SetDrawOverlay();

	return doElement;
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
	
	// draw the text only when the text is present
	if( m_drawText )
	{
		a_window.draw( m_text );
	}
}

/// 
/// @protected
/// @brief setter funciton to set the position of the text.
/// 
/// Sets the position of the text such that it is always centered
/// 
void Brood::BroodUI::UIElement::SetTextPosition()
{
	// getting m_text's center
	float textCenterX = m_text.getLocalBounds().width / ( float )2;
	float textCenterY = m_text.getCharacterSize() / float( 1.5 );

	// getting te postion of the text; origin is at the top left of the text

	float xPosText = ( GetBodyPosition().x + GetBodySize().x / 2 ) - textCenterX;
	float yPosText = ( GetBodyPosition().y + GetBodySize().y / 2 ) - textCenterY;

	m_text.setPosition( xPosText, yPosText );
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