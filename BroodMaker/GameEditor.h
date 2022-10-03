/*************************************************************************/
/// 
/// @file GameEditor.h 
/// 
/// @brief  This file is a header file for GameEditor class.
/// 
/// It contains all of the declaration of the member 
///		funciton of GameEditor class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "WorkSpace.h"
#include "DeckManager.h"
#include "PlayerManager.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class GameEditor;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of GameEditor class ==========================
// ======================================================================

/// 
/// @ingroup Application
/// @class BoardEditor  "GameEditor.h"
/// @brief It alows the users to tweek the general game setting 
///		and game rules.
///
/// It is a container that bundels elements that is present 
///		in GameEditor workspace
/// 
/// Derived form Workspace class
/// 
/// @todo allowd to enter number in the txt feild
/// 
class Brood::Application::GameEditor :
	public Brood::Application::WorkSpace
{
	// ================= public member function ===================  
public:
	// default constructor
	GameEditor( Brood::Application::Components::DeckManager* a_deckManagerPtr,
				Brood::Application::Components::PlayerManager* a_playerManagerPtr,
				sf::RectangleShape* a_panelPtr );

	// default destructor
	~GameEditor();
	// ===== virtual funcitons ====

	// initializes the component of a workspace
	void InitializeWorkSpace();

	// all the logic for the workspace is here
	void Update();

	// updates all the display elment
	void UpdateAllDispayElement();

	// reners to the screen
	void Draw( sf::RenderWindow& a_window );

	// Calls Debugger for all UI elements in this class
	void Debugger();


	// ================= private member function ================== 
private:

	// checks if the user interacted with the enter game
	// name panel element
	void UpdateGameTitleInput();

	// checks if the user interacted with the movement 
	// type panel Element
	void UpdateMovementTypePanelElement();

	// checks if the user interacted with the incorrect 
	// penalty panel Element
	void UpdateIncorrectPenaltyPanelElement();

	// checks if the user interacted with the minumum 
	// player number panel Element
	void UpdateMinimumPlayerNumber();

	// checks if the user interacted with the maximum 
	// player number panel Element
	void UpdateMaximumPlayerNumber();

	// checks if the user interacted with the Deck 
	// number panel Element
	void UpdateDeckNumber();

	// ================= private member variable ================== 
private:

	/// holds the panel body
	sf::RectangleShape* m_panelBodyPtr;

	/// show how the tile screen of game
	Brood::BroodUI::Button* m_titleScreenBtn;

	/// pointer to the deck manager
	Brood::Application::Components::DeckManager* m_deckManagerPtr;

	/// pointer to the player manager
	Brood::Application::Components::PlayerManager* m_playerManagerPtr;

	// ==== UI elements to show setting title  ====
	Brood::BroodUI::TextBox* m_txtSettingTitle;

	// ==== UI elements to enter a game title texture  ====

	/// holds the Game name prompt
	Brood::BroodUI::TextBox* m_txtGameNamePrompt;

	/// holds the Game name user enters
	Brood::BroodUI::TextBox* m_txtGameInput;

	// ==== UI elements to change the board movement rule ====

		/// holds the text Movement type prompt
	Brood::BroodUI::TextBox* m_txtMovementTypePromt;

	/// holds how the player can move: dice, 
	///	start with dice and then card, and 
	///	card no dice
	Brood::BroodUI::DropDownInput* m_ddiMovementType;

	// ==== UI elements to change the board Penalty rule ====

	/// holds the text Movement type prompt
	Brood::BroodUI::TextBox* m_txtIncorectPenaltyPromt;

	/// holds yes or no
	Brood::BroodUI::DropDownInput* m_ddiIncorectPenalty;

	// ==== UI elements to change the minimum player ====

	/// holds the text minimum player prompt
	Brood::BroodUI::TextBox* m_txtPlayerMinNumPrompt;

	/// clicking it will decrease the minium required player number by 1
	Brood::BroodUI::Button* m_btnPlayerDecMinNum;

	/// displays the Current minium required player number
	Brood::BroodUI::TextBox* m_txtPlayerMinNum;

	/// clicking it will increase the minium required player number by 1
	Brood::BroodUI::Button* m_btnPlayerIncMinNum;

	// ==== UI elements to change the maximum player ====

	/// holds the text maximum player prompt
	Brood::BroodUI::TextBox* m_txtPlayerMaxNumPrompt;

	/// clicking it will decrease the maximum required player number by 1
	Brood::BroodUI::Button* m_btnPlayerDecMaxnNum;

	/// displays the Current maximum required player number
	Brood::BroodUI::TextBox* m_txtPlayerMaxNum;

	/// clicking it will increase the maximum required player number by 1
	Brood::BroodUI::Button* m_btnPlayerIncMaxNum;

	// ==== UI elements to change the number of decks ====

	/// holds the text number of deck prompt
	Brood::BroodUI::TextBox* m_txtDeckNumPrompt;

	/// clicking it will decrease the maximum required player number by 1
	Brood::BroodUI::Button* m_btnDeckDecNum;

	/// displays the Current maximum required player number
	Brood::BroodUI::TextBox* m_txtDeckNum;

	/// clicking it will increase the maximum required player number by 1
	Brood::BroodUI::Button* m_btnDeckIncNum;


};

// ======================================================================
// ================= start of GameEditor class ==========================
// ======================================================================