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
		class DeckManager;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
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
	DeckManager( const Brood::Application::Components::DeckManager& a_otherPlayerManager );

	// assignment operator
	DeckManager& operator=( const Brood::Application::Components::DeckManager& a_otherPlayerManager );

	// getter funciton to get the deck at the passed index
	Brood::Application::Components::Deck* GetDeckAtIdx( unsigned a_deckIdx);

	// getter function to get the decklist
	std::vector<Brood::Application::Components::Deck>& GetDeckList();

	// sets deck size
	void SetDeckSize(unsigned a_deckSize);

	// sets current deck index
	void SetCurrDeckIdx(unsigned a_currDeckIdx);

	// adds card to the back of current selected deck
	void AddCardToDeckAtCurrIdx(Brood::Application::Components::CardInfo a_cardToAdd);

	// ===================== private member variables ===================
private:
	// current deck index 
	unsigned m_currDeckIdx;

	// deck list
	std::vector<Brood::Application::Components::Deck> m_deckList;

};

// ======================================================================
// ================= end of DeckManager class ===========================
// ======================================================================