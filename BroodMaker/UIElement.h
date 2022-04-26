/*************************************************************************/
/// 
/// @file UIElement.h 
/// 
/// @brief  This file is a header file for UIElement class and it also
///		contains a enum ENUM_UIType, struct ST_UIELementCtorParam, and
///		struct MapIdToElement which are declared in BroodUI namespace.
/// 
/// UIElement class is a abstract base class that is parent to 
///		all the different UI elements.
/// 
/// ENUM_UIType contains the types of UI elemente that are derived 
///		from UIElement class
/// 
/// ST_UIELementCtorParam provides a cleaner way to pass the arguments 
///		to inialize a sub-object of UIElemnt class
/// 
/// ST_MapIdToElement is a struct that maps the unique ui element id to 
///		its element. 
/// 
/// It contains all of the declaration of the member 
///		funciton of UIElement class, ST_UIELementCtorParam struct, and 
///		ST_MapIdToElement struct.
/// 
/// It contains all of the inline funcitons defination of 
///		the member funciton of UIElement class, ST_UIELementCtorParam 
///		struct, and ST_MapIdToElement struct
///
/************************************************************************/

#pragma once
#include "UI_ID.h"
#include "ElementSelection.h"
#include "MouseHandler.h"

// =============================== defining namespace =======================
namespace Brood
{
	///
	/// @ingroup Brood
	/// @addtogroup BroodUI
	/// 
	namespace BroodUI
	{
		// defining what component of this file will be inside namespace BroodUI
		enum class ENUM_UIType;
		struct ST_MapIdToElement;
		class UIElement;
	}
}
// ====================== end of namespace  defination =======================

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**					ENUM_UIType Enum class  defination										  */
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

/// 
/// @ingroup BroodUI
/// @enum ENUM_UIType
/// @brief list all the different ui elements
///
enum class Brood::BroodUI::ENUM_UIType
{
	UI_text, ///< stores a text; user-typed text or predefined text
	UI_textBox, ///< container for editText

	UI_button, ///< a button
	UI_dropDownMenu, ///< drop down menu; has items inside it 
	UI_scrollBar
};

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**					UIElement class  defination										  */
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

/// 
/// @ingroup BroodUI
/// @class UIElement  "UIElement.h"
/// @brief a abstract base class that is parent to all the different 
///		UI elements 
/// 
class Brood::BroodUI::UIElement
{
	// ================= public member function =================  
public:
	UIElement( Brood::BroodUI::ENUM_UIType a_elementType,
			   Brood::BroodUI::UIElement* a_parentPtr = nullptr,
			   int a_index = -1 ); // default constructor

	virtual ~UIElement(); // virtual default destructor

	// getter functions
	const sf::RectangleShape& GetBody() const;
	const sf::Vector2f GetBodyPosition() const;
	const sf::Vector2f GetBodySize() const;
	Brood::BroodUI::Id* GetElementIdPtr();
	const sf::Color GetInactiveOverlayColor();
	const sf::Color GetActiveOverlayColor();
	const sf::Color GetHotOverlayColor();

	// setter functions
	void SetBodySize( sf::Vector2f  a_size );
	void SetBodySize( float a_sizeX, float a_sizeY );
	void SetBodyColor( sf::Color a_bodyColor );
	void SetActiveOverlayColor( sf::Color a_color );
	void SetHotOverlayColor( sf::Color a_color );
	void SetDrawOverlay( bool a_drawOverlay = false );
	virtual void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false );
	virtual void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false );

	// funciton to check if the
	bool IsMouseOverElement();
	bool IsActiveElement();
	bool IsHotElement();

	// checks to see if the element is active and the funciton is to be carreied out or not
	// @todo: maybe make this a virtual function as button element is one press thing
	//		but a text editor is not 

	bool DoElement();

	// process mouse event
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) = 0; // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) = 0; // when mouse button is released
	virtual bool OnMouseMove() = 0; // what happens to the element on mouse move

	virtual bool Update() = 0; // update the element
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw funciton

	// ================= protected member variables =================  
protected:
	Brood::BroodUI::ENUM_UIType m_elementType; // stores the type of element stored
	Brood::BroodUI::Id m_elementId; // uniqie id of the element

	sf::RectangleShape m_body; // element body
	sf::RectangleShape m_bodyOverLay; // element body

	sf::Color m_hotOverlayColor; // color when mouse is over it
	sf::Color m_activeOverlayColor; // color when it is active element

	bool m_drawOverlay; // true if overlay is to be drawn
};

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**					ST_MapIdToElement struct  defination							  */
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/


///
/// @ingroup BroodUI
/// @static 
/// @struct MapIdToElement  "MapIdToElement.h"
/// @brief A struct to handel the mapping of unique UI_ID to its element
///		for quick acceess 
/// 
struct Brood::BroodUI::ST_MapIdToElement
{

public:
	static std::map<const int, Brood::BroodUI::UIElement*>& GetMap();
	static Brood::BroodUI::UIElement* GetElementPtrFromMap( int a_id );
	static bool AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr );
	static bool ReomveFromMap( int a_id );


private:
	static std::map<const int, Brood::BroodUI::UIElement*> stm_mapper;
};

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
/// @brief Getter function to reference to the element
/// 
/// @return constant reference to the element
/// 
inline const sf::RectangleShape& Brood::BroodUI::UIElement::GetBody() const
{
	return m_body;
}

/// 
/// @public
/// @brief Getter function to get the positon
/// 
/// @return postion of the element
///
inline const sf::Vector2f Brood::BroodUI::UIElement::GetBodyPosition() const
{
	return m_body.getPosition();
}

/// 
/// @public
/// @brief Getter function to get the size of element
/// 
/// @return size of the body
///
inline const sf::Vector2f Brood::BroodUI::UIElement::GetBodySize() const
{
	return m_body.getSize();
}

/// @brief 
/// @return 
inline Brood::BroodUI::Id* Brood::BroodUI::UIElement::GetElementIdPtr()
{
	return &m_elementId;
}

/// 
/// @public
/// @brief Getter function to get the element's active color
/// 
/// @reutrn color of the body when it is active; sf::color
///
inline const sf::Color Brood::BroodUI::UIElement::GetActiveOverlayColor()
{
	return m_activeOverlayColor;
}

/// 
/// @public
/// @brief Getter function to get the element's hot color
/// 
/// @reutrn color of the body when it is hot; sf::color
///
inline const sf::Color Brood::BroodUI::UIElement::GetHotOverlayColor()
{
	return m_hotOverlayColor;
}

/// 
/// @virtual
/// @public
/// @overload
/// @brief Setter function to set the element's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// @param a_relativeToParent is true if the passed position is relative to its parent;
///			default -> false.
/// 
inline void Brood::BroodUI::UIElement::SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent )
{
	Brood::BroodUI::UIElement::SetBodyPosition( sf::Vector2f( a_posX, a_posY ), a_relativeToParent );
}

/// 
/// @public
/// @brief Setter function to set the element's Size
/// 
/// @param a_size size of the element
/// 
inline void Brood::BroodUI::UIElement::SetBodySize( sf::Vector2f a_size )
{
	m_body.setSize( a_size );
	m_bodyOverLay.setSize( a_size ); // overlay rectangle
}

/// 
/// @public
/// @overload
/// @brief Setter function to set the element's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
/// 
inline void Brood::BroodUI::UIElement::SetBodySize( float a_sizeX, float a_sizeY )
{
	m_body.setSize( sf::Vector2f( a_sizeX, a_sizeY ) );
	m_bodyOverLay.setSize( sf::Vector2f( a_sizeX, a_sizeY ) );
}

/// 
/// @public
/// @brief Setter function to set the element body color
/// 
/// @param a_bodyColor color of the body; sf::color
///
inline void Brood::BroodUI::UIElement::SetBodyColor( sf::Color a_bodyColor )
{
	m_body.setFillColor( a_bodyColor );
}

/// 
/// @public
/// @brief Setter function to set the element's active color
/// 
/// @param a_color color of the body when it is active; sf::color
///
inline void Brood::BroodUI::UIElement::SetActiveOverlayColor( sf::Color a_color )
{
	m_activeOverlayColor = a_color;
}

/// 
/// @public
/// @brief Setter function to set the element's hot color
/// 
/// @param a_color color of the body when it is hot; sf::color
///
inline void Brood::BroodUI::UIElement::SetHotOverlayColor( sf::Color a_color )
{
	m_hotOverlayColor = a_color;
}

/// 
/// @public
/// @brief Setter function to set if the overlay is to be drawn or not
/// 
/// @param a_drawOverlay true if the overlay is to be drawn
//
inline void Brood::BroodUI::UIElement::SetDrawOverlay( bool a_drawOverlay )
{
	m_drawOverlay = a_drawOverlay;
}


///
/// @public
/// @brief Checks if the element is the active element or not
/// 
/// @return true if it is the active element; else false
/// 
inline bool Brood::BroodUI::UIElement::IsActiveElement()
{
	if( ( Brood::BroodUI::ElementSelection::GetActiveElement() )->GetElementID() == m_elementId.GetElementID() )
	{
		return true;
	}
	return false;
}

///
/// @public
/// @brief Checks if the element is the hot element or not
/// 
/// @return true if it is the hot element; else false
/// 
inline bool Brood::BroodUI::UIElement::IsHotElement()
{
	if( ElementSelection::GetHotElement()->GetElementID() == m_elementId.GetElementID() )
	{
		return true;
	}
	return false;
}

///
/// @virtual
/// @public
/// @brief Draws the body to the render window
/// 
/// @param a_window reference to the render window
/// 
inline void Brood::BroodUI::UIElement::Draw( sf::RenderWindow& a_window )
{
	a_window.draw( m_body );

	// draw the over lay only if the overlay is turned on
	if( m_drawOverlay )
	{
		a_window.draw( m_bodyOverLay );
	}
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
/// @brief Getter Funciton
/// 
/// gets the map
/// 
/// @return reference to the map
/// 
inline std::map<const int, Brood::BroodUI::UIElement*>& Brood::BroodUI::ST_MapIdToElement::GetMap()
{
	return stm_mapper;
}