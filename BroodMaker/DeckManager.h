/*************************************************************************/
/// 
/// @file DeckManager.h 
/// 
/// @brief  This file is a header file for DeckManager class.
/// 
/// It contains all of the declaration of the member 
///		funciton of DeckManager class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#pragma once
#include "Deck.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		enum class ENUM_MovementType;
		class DeckManager;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of ENUM_MovementType Enum class defination ===
// ======================================================================

/// 
/// @ingroup Components
/// @enum ENUM_MovementType
/// @brief list all the different movement type
///
enum class Brood::Application::Components::ENUM_MovementType
{
	MOVEMENT_diceThenCard, ///> when the dice if forced for on the start
	MOVEMENT_diceOnly, ///> when the dice is only used
	MOVEMENT_cardOnly, ///> when the dice if forced for on the start
};

// ======================================================================
// ================= end of ENUM_UIType Enum class defination ===========
// ======================================================================

// ======================================================================
// ================= start of DeckManager class =========================
// ======================================================================

///
/// @ingroup Components
/// @class PlayerManager  "DeckManager.h"
/// m_minPlayer
/// @brief A PlayerManager Class manages all player realted things
/// 
class Brood::Application::Components::DeckManager
{
	// ===================== private member function ===================
public:
	// default constructor
	DeckManager();

	// destructor
	~DeckManager();

	// copy constructor
	DeckManager( const Brood::Application::Components::DeckManager& a_otherDeckManager );

	// assignment operator
	DeckManager& operator=( const Brood::Application::Components::DeckManager& a_otherDeckManager );

	// getter funciton to get the deck at the passed index
	Brood::Application::Components::Deck* GetDeckAtIdx( unsigned a_deckIdx );

	// getter function to get the decklist
	std::vector<Brood::Application::Components::Deck>& GetDeckList();

	// getter funciton to get incorrect penalty 
	bool GetIncorrectPenalty();

	// getter funciton to get movement type
	Brood::Application::Components::ENUM_MovementType GetMovementType();

	// getter funciton to get incorrect penalty 
	void SetIncorrectPenalty( bool  a_incorrectPenatly );

	// getter funciton to get movement type
	void SetMovementType( Brood::Application::Components::ENUM_MovementType a_movementType);

	// sets deck size
	void SetDeckSize( unsigned a_deckSize );

	// sets current deck index
	void SetCurrDeckIdx( unsigned a_currDeckIdx );

	// adds card to the back of current selected deck
	void AddCardToDeckAtCurrIdx( Brood::Application::Components::CardInfo a_cardToAdd );

	// ===================== private member variables ===================
private:

	// ture if the incorrect penalty rule should be enforced or not
	bool m_incorrectPenalty;

	// stores the movement type used
	Brood::Application::Components::ENUM_MovementType m_movementType;

	// current deck index 
	unsigned m_currDeckIdx;

	// deck list
	std::vector<Brood::Application::Components::Deck> m_deckList;
};

// ======================================================================
// ================= end of DeckManager class ===========================
// ======================================================================