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
/// ST_MapIdToElement is a struct that maps the unique ui element id to 
///		its element. 
/// 
/// It contains all of the declaration of the member 
///		funciton of UIElement class, ST_UIELementCtorParam struct, and 
///		ST_MapIdToElement struct.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "UI_ID.h"
#include "ElementSelection.h"
#include "MouseHandler.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{ 
	namespace BroodUI
	{
		enum class ENUM_UIType;
		struct ST_MapIdToElement;
		class UIElement;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ENUM_UIType Enum class defination =========
// ======================================================================

/// 
/// @ingroup BroodUI
/// @enum ENUM_UIType
/// @brief list all the different ui elements
///
enum class Brood::BroodUI::ENUM_UIType
{
	UI_textBox, ///< container for text -> derived from UI_Element
	UI_button, ///< a button -> derived from UI_TextBox
	UI_dropDownMenu, ///< drop down menu; has items inside it -> derived from UI_Button
	UI_menuBar,
	UI_panel,
	UI_scrollBar /// @TODO add latter
};
// ======================================================================
// ================= end of ENUM_UIType Enum class defination ===========
// ======================================================================

// ======================================================================
// ================= start of UIElement class ===========================
// ======================================================================

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
			   Brood::BroodUI::UIElement* a_parentPtr = nullptr); // default constructor

	virtual ~UIElement(); // virtual default destructor

	// getter functions
	const Brood::BroodUI::ENUM_UIType GetElementType() const;
	const sf::RectangleShape& GetBody() const;
	const sf::Vector2f GetBodyPosition() const;
	const sf::Vector2f GetBodySize() const;
	const sf::Color GetBodyColor();
	const sf::Color GetActiveOverlayColor();
	const sf::Color GetHotOverlayColor();
	Brood::BroodUI::Id* GetElementIdPtr();

	// setter functions
	void SetBodyColor( sf::Color a_bodyColor );
	virtual  void SetBodySize( sf::Vector2f  a_size );
	virtual void SetBodySize( float a_sizeX, float a_sizeY );
	virtual void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false );
	virtual void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false );
	
	void SetActiveOverlayColor( sf::Color a_color );
	void SetHotOverlayColor( sf::Color a_color );
	void SetDrawOverlay( bool a_drawOverlay = false );

	// funciton to check if the
	bool IsMouseOverElement();
	bool IsActiveElement();
	bool IsCurrActiveElement();
	bool IsHotElement();

	virtual bool DoElement(); // checks to see if the logic for the element is to be excecuted or not 
	virtual void Draw( sf::RenderWindow& a_window ) = 0; // draw funciton

	// ================= protected member variables =================  
protected:
	Brood::BroodUI::ENUM_UIType m_elementType; ///> stores the type of element stored
	Brood::BroodUI::Id m_elementId; ///> uniqie id of the element

	sf::RectangleShape m_body; ///> element body
	sf::RectangleShape m_bodyOverLay; ///> element body

	sf::Color m_hotOverlayColor; ///> color when mouse is over it
	sf::Color m_activeOverlayColor; ///> color when it is active element

	bool m_drawOverlay; ///> true if overlay is to be drawn
};

// ======================================================================
// ================= end of UIElement class =============================
// ======================================================================

// ======================================================================
// ================= start of ST_MapIdToElement struct ==================
// ======================================================================

///
/// @ingroup BroodUI
/// @struct MapIdToElement  "MapIdToElement.h"
/// @brief A static struct to handel the mapping of unique UI_ID to its element
///		for quick acceess 
/// 
struct Brood::BroodUI::ST_MapIdToElement
{

	// ================= public member function ===================  
public:
	// Getter functions
	static std::map<const int, Brood::BroodUI::UIElement*>& GetMap();
	static Brood::BroodUI::UIElement* GetElementPtrFromMap( int a_id );

	static bool AddToMap( int a_id, Brood::BroodUI::UIElement* a_elementPtr );
	static bool ReomveFromMap( int a_id );

	// ================= private member variables =================  
private:
	///> maps the unique UI ID to the element
	static std::map<const int, Brood::BroodUI::UIElement*> stm_mapper;
};

// ======================================================================
// ================= end of ST_MapIdToElement struct ====================
// ======================================================================