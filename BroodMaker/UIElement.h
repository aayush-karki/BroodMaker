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
/// MapIdToElement is a struct that maps the unique ui element id to 
///		its element. 
/// 
/// It contains all of the declaration of the member 
///		funciton of UIElement class, ST_UIELementCtorParam struct, and 
///		MapIdToElement struct.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "UI_ID.h"
#include "MapIdToElement.h"
#include "ElementSelection.h"
#include "MouseHandler.h"
#include "GlobalVariables.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		enum class ENUM_UIType;
		class UIElement;
		class MapIdToElement;
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
	UI_textBox, ///> container for text  -> derived from UI_Element
	UI_button, ///> a button -> derived from UI_Element
	UI_dropDownMenu, ///> drop down menu; has items inside it -> derived from UI_Button
	UI_dropDownInput, ///> drop down input; has items inside it -> derived from UI_Button
	UI_menuBar, ///> menubar is a list of drop down menu stacked horizontally
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
/// For the UI element the order of update logic and rending matters.
/// 
/// Update Logic: We first check if we should execute the funciton for 
///		the element with DoElement() function which returns a boolean value.
///		Another method for some but not all of the UI Element is to check 
///		if the m_isSelected value is true or false. On the same note the 
///		order for checking update logic is from top left to bottom right--
///		like reading a english book.
/// 
/// Render Logic: The order for render logic is to go from bottom to top 
///		starting form bottom-right to left. This is because of how 
///		rendering works where things drawn last is always on top.
/// 
/// @TODO create a verticalmenus for ma UIElement. This could be used to
///		for Drop down menus. 
/// @todo create a font class whose job is to load and save font and replace 
///		all the m_font to object of that file
/// 
class Brood::BroodUI::UIElement
{
	// ================= public member function =================  
public:
	// default constructor
	UIElement( Brood::BroodUI::ENUM_UIType a_elementType,
			   Brood::BroodUI::UIElement* a_parentPtr = nullptr );

	// virtual default destructor
	virtual ~UIElement();

	// copy constructor
	UIElement( UIElement& a_otherElement );

	// assignment operator
	Brood::BroodUI::UIElement& operator=( UIElement& a_otherElement );

	// ======= getter functions ========

	// gets element type
	const Brood::BroodUI::ENUM_UIType GetElementType() const;

	// Get a reference to element body
	const sf::RectangleShape& GetBody() const;

	// get element body position
	const sf::Vector2f GetBodyPosition() const;

	// get element body size
	const sf::Vector2f GetBodySize() const;

	// get element body color
	const sf::Color GetBodyColor();

	// get element body active overlay color
	const sf::Color GetActiveOverlayColor();

	// get element body hot overlay color
	const sf::Color GetHotOverlayColor();

	// get element's Id pointer
	Brood::BroodUI::Id* GetElementIdPtr();

	// return the value of m_isSelected
	const bool IsSelected() const;

	// returns the text that is stored
	std::string GetText() const;

	// gets font size
	unsigned int GetFontSize() const;

	// ====== setter functions =======

	// sets element body color
	void SetBodyColor( sf::Color a_bodyColor );

	// sets element body size 
	virtual  void SetBodySize( sf::Vector2f  a_size );

	// sets element body size
	virtual void SetBodySize( float a_sizeX, float a_sizeY );

	// sets element body position
	virtual void SetBodyPosition( sf::Vector2f  a_pos, bool a_relativeToParent = false );

	// sets element body position
	virtual void SetBodyPosition( float a_posX, float a_posY, bool a_relativeToParent = false );

	// sets font
	void SetFont( sf::Font& a_font ); // sets font

	// sets font color
	void SetFontColor( sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White ); // sets font color

	// sets font size
	void SetFontSize( int a_fontSize = 12 );

	// sets text
	virtual void SetText( std::string a_text = "" );

	// sets the state of the element.
	virtual void SetSelected( bool a_selected );

	// sets active overlay color
	void SetActiveOverlayColor( sf::Color a_color );

	// sets hot overlay color
	void SetHotOverlayColor( sf::Color a_color );

	// funciton to check if the mouse is over element
	bool IsMouseOverElement();

	// funciton to check if element set as almost active element
	bool IsAlmostActiveElement();

	// funciton to check if element set as active element
	bool IsCurrActiveElement();

	// funciton to check if element is hot active element
	bool IsHotElement();

	// checks to see if the logic for the element is to be excecuted or not 
	virtual bool DoElement();

	// draw funciton
	virtual void Draw( sf::RenderWindow& a_window );

	virtual void Debugger(); // adds the element ID to the text

	// ================= protected member function =================  
protected:

	// to set the position of the text
	void SetTextPosition();

	// logic for if overlay is to be drawn or not
	void SetDrawOverlay();


	// ================= protected member variables =================  
protected:

	/// stores the type of element stored
	Brood::BroodUI::ENUM_UIType m_elementType;

	/// uniqie id of the element
	Brood::BroodUI::Id m_elementId;

	/// element body
	sf::RectangleShape m_body;

	///  element body
	sf::RectangleShape m_bodyOverLay;

	/// color when mouse is over it
	sf::Color m_hotOverlayColor;

	/// color when it is active element
	sf::Color m_activeOverlayColor;

	/// true if overlay is to be drawn
	bool m_drawOverlay;

	/// is true if the element is selected
	bool m_isSelected;

	/// text content
	sf::Text m_text;

	/// saves the text content
	std::string m_textContent;

	/// saves the text content before replacing by uiid
	std::string m_debugTextSave;

	/// element's font
	sf::Font* m_font;

	/// font size
	unsigned m_fontSize;

	/// is true if text is set and hence draw to screen
	bool m_drawText;
};

// ======================================================================
// ================= end of UIElement class =============================
// ======================================================================