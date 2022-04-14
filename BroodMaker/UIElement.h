/*************************************************************************/
/// 
/// @file UIElement.h 
/// 
/// @brief  This file is a header file for UIElement class.
/// 
/// This is a abstract base class that is parent to all the different 
///		UI elements 
/// 
/// It contains all of the declaration of the member 
///		funciton of Board class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of Board class
///
/************************************************************************/

#pragma once
#include "UI_ID.h"
#include "ElementSelection.h"

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
		struct ST_UIELementCtorParam;
		class UIElement;
	}
}
// ====================== end of namespace  defination =======================

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

/// 
/// @struct
/// @brief a struct to inialize the UIElment class
/// 
struct Brood::BroodUI::ST_UIELementCtorParam
{

	// public data member
public:
	ENUM_UIType stm_elementType; ///> stores the type of element stored

	Brood::BroodUI::UIElement* stm_parentPtr = nullptr; ///> pointer to parent
	int stm_index = -1; ///> index; nth child of parent


	bool stm_relativeToParent; ///> is the given values relative to parent or not

	float stm_elementSizeX = 0.f; ///> element's width
	float stm_elementSizeY = 0.f; ///> element's length
	float stm_elementPosX = 0.f; ///> element's x-position on screen
	float stm_elementPosY = 0.f; ///> element's y-position on screen

	// public member function
public:

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
	ST_UIELementCtorParam( Brood::BroodUI::ENUM_UIType a_elementType,
						   Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1,
						   bool a_relativeToParent = false,
						   float a_elementSizeX = 0.f, float a_elementSizeY = 0.f,
						   float a_elementPosX = 0.f, float a_elementPosY = 0.f ) :
		stm_elementType( a_elementType ),
		stm_parentPtr( a_parentPtr ), stm_index( a_index ),
		stm_relativeToParent( a_relativeToParent ),
		stm_elementSizeX( a_elementSizeX ), stm_elementSizeY( a_elementSizeY ),
		stm_elementPosX( a_elementPosX ), stm_elementPosY( a_elementPosY )
	{}

};

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
			   Brood::BroodUI::UIElement* a_parentPtr = nullptr, int a_index = -1,
			   bool a_relativeToParent = false,
			   float a_elementSizeX = 0.f, float a_elementSizeY = 0.f,
			   float a_elementPosX = 0.f, float a_elementPosY = 0.f ); // default constructor

	UIElement( Brood::BroodUI::ST_UIELementCtorParam& a_ctorParam ); // constructor when the struct is passed
	virtual ~UIElement(); // virtual default destructor

	// getter functions
	const sf::RectangleShape& GetBody() const;
	const sf::Vector2f GetBodyPosition() const;
	const sf::Vector2f GetBodySize() const;
	Brood::BroodUI::Id* GetElementIdPtr();

	// funciton to check if the 
	bool IsActiveElement();
	bool IsHotElement();

	// mouse process
	virtual bool ProcessMouseDown( sf::Mouse::Button a_button ) = 0; // when mouse button is pressed
	virtual bool ProcessMouseUp( sf::Mouse::Button a_button ) = 0; // when mouse button is released
	virtual bool OnMouseMove() = 0; // what happens on mouse move
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw funciton

// ================= protected member function =================  
protected:

	// setter functions
	void SetBodyPosition( sf::Vector2f  a_pos );
	void SetBodyPosition( float a_posX, float a_posY );
	void SetBodySize( sf::Vector2f  a_size );
	void SetBodySize( float a_sizeX, float a_sizeY );

	// ================= private data member =================  
private:
	Brood::BroodUI::ENUM_UIType m_elementType; // stores the type of element stored
	Brood::BroodUI::Id m_elementId; // uniqie id of the element

	sf::RectangleShape m_body; // element body
};

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
/// @protected
/// @brief Setter function to set the element's Position
/// 
/// @param a_pos position of the element
/// 
inline void Brood::BroodUI::UIElement::SetBodyPosition( sf::Vector2f a_pos )
{
	m_body.setPosition( a_pos );
}

/// 
/// @protected
/// @brief Setter function to set the element's Position
/// 
/// @param a_posX x-position of the element
/// @param a_posY y-position of the element
/// 
inline void Brood::BroodUI::UIElement::SetBodyPosition( float a_posX, float a_posY )
{
	m_body.setPosition( a_posX, a_posY );
}

/// 
/// @protected
/// @brief Setter function to set the element's Size
/// 
/// @param a_size size of the element
/// 
inline void Brood::BroodUI::UIElement::SetBodySize( sf::Vector2f a_size )
{
	m_body.setSize( a_size );
}

/// 
/// @protected
/// @brief Setter function to set the element's Size
/// 
/// @param a_sizeX length of the element
/// @param a_sizeY width of the element
inline void Brood::BroodUI::UIElement::SetBodySize( float a_sizeX, float a_sizeY )
{
	m_body.setSize( sf::Vector2f( a_sizeX, a_sizeY ) );
}
