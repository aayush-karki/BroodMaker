/*************************************************************************/
/// 
/// @file DropDownInput.h 
/// 
/// @brief  This file is a header file for DropDownInput class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DropDownInput class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "DropDownMenu.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace BroodUI
	{
		class DropDownInput;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of DropDownInput class ========================
// ======================================================================

/// 
/// @ingroup BroodUI
/// @class DropDownInput  "DropDownInput.h"
/// @brief A UI elemnt that represent a drop down menu. 
/// 
/// A class derived from DropDownMenu class. 
///		It contains a list of menus inside a single element.
///		The list of items are left aligned and below the menu title.
///		the size of the items is depended on the longest item name.
/// 
/// @note This class differes from the DropDownMenu class as for this class 
///		the title that is used in DropDownMenu is changed to relfect the 
///		selected item. So it is important to add line of code below when 
///		your item's DoElement() returns true.
///		@code {.cpp}
///			// see the example case for more information
///			myDropDownInput.SetText( itemList.at( i )->GetText() );
///		@endcode
///		
/// ### Example Case
/// @code {.cpp}
/// 
/// // window object
/// sf::RenderWindow window( sf::VideoMode( 500, 500 ), "BroodMaker" );
///
/// // event object 
/// sf::Event events;
/// 
/// // creating a DropDownInput object
/// Brood::BroodUI::DropDownInput myDropDownInput; 
/// 
/// // setting size and position
/// myDropDownInput.SetBodySize( 150, 50 );
/// myDropDownInput.SetBodyPosition( 265, 120 );
/// 
/// // setting the font which is required to display the text
/// myDropDownInput.SetFont( &font );
/// 
/// // setting the font size. It should be less than the body height by 2 units.
/// // @see Brood::BroodUI::Textbox::SetFontSize() for more information
/// myDropDownInput.SetFontSize( 20 );
/// 
/// // setting body color
/// myDropDownInput.SetBodyColor( sf::Color::Green );
/// 
/// // adding 2 items to the menu
/// myDropDownInput.AddItemToMenu( "1st item" );
/// myDropDownInput.AddItemToMenu( "2st item" );
/// myDropDownInput.AddItemToMenu( "longest of all item" );
/// 
/// //app loop
/// while( !exit )
/// {
///		// event loop
///		
///		// logic 
/// 
///		// checking if the logics of the element is to be executed or not
///		if(myDropDownInput.DoElement())
///		{
///			std::cout << "myDropDownInput Pressed" << std::endl;
///		}
///		if( myDropDownInput.IsSelected() )
///		{
///			auto itemList = myDropDownInput.GetItemList();
///			if( !itemList.empty() )
///			{
///				// checking if the logics of the items is to be executed or not
///				for( int i = 0; i < itemList.size(); ++i )
///				{
///					if( itemList.at( i )->DoElement() )
///					{
///						// setting the elements name as the item's name
///						// this is important so that the changes can be reflected in the
///						// title
///						myDropDownInput.SetText( itemList.at( i )->GetText() );
///		
///						// executing the function
///						std::cerr << "item at " << i << "  Pressed with ID " <<
///							itemList.at( i )->GetText() << std::endl;
///					}
///				}
///			}
///		}
/// 
///		// rendering
///		myDropDown.Draw( window );
/// }
/// 
/// @endcode
/// 
class  Brood::BroodUI::DropDownInput : public Brood::BroodUI::DropDownMenu
{
	// ============ public member function =============== 
public:
	// default constructor
	DropDownInput( Brood::BroodUI::UIElement* a_parentPtr = nullptr,
				   Brood::BroodUI::ENUM_UIType a_enumType = Brood::BroodUI::ENUM_UIType::UI_dropDownInput );
	// default destructor
	virtual ~DropDownInput();

	// copy constructor
	DropDownInput( const DropDownInput& a_otherElement );

	// assignment operator
	Brood::BroodUI::DropDownInput& operator=( const DropDownInput& a_otherButton );

	// adds item to menu
	virtual void AddItemToMenu( std::string a_menuName,
								sf::Color a_color = Brood::Application::StaticVariables::ST_ColorVariables::stm_White );

	// adds the passed button to dropdown menu if a_createNew is true
	// then create a new button using the passed item then adds 
	// the new button 
	virtual void AddItemToMenu( Brood::BroodUI::Button* a_buttonPtrToAdd,
								bool a_createNew = true );
};

