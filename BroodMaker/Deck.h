/*************************************************************************/
/// 
/// @file Deck.h 
/// 
/// @brief  This file is a header file for Deck class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Deck class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "stdafx.h"
#include "Button.h"
#include "CardInfo.h"
#include "GlobalVariables.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class Deck;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of Deck class ================================
// ======================================================================

///
/// @class Dice  "Deck.h"
/// 
/// @brief A class to create a Deck. 
/// 
/// It has all the card info init
/// 
/// 
/// TODO add a function and ctor to load from a file
/// 
class Brood::Application::Components::Deck :
	public Brood::BroodUI::Button
{
	// ============= public member funciton =====================
public:

	// default constructor
	Deck( Brood::BroodUI::UIElement* a_parentPtr = nullptr );

	// default destructor
	~Deck();

	// copy constructor
	Deck( const Brood::Application::Components::Deck& a_other );

	// assignment constructor
	Deck& operator = ( const Brood::Application::Components::Deck& a_other );

	// getter functions
	const std::vector< Brood::Application::Components::CardInfo*>& GetCardList() const;

	// gets pointer to the card at given index
	Brood::Application::Components::CardInfo* GetCardPtrAtIdx( unsigned a_cardInfoIdx );

	// returns the first undealt card and increases the counter by 1
	const CardInfo DealCard();

	// shuffels the cards in m_stock
	void Shuffel();

	// restes the currentCardidx to zero and reshuffels the deck
	void ResetDeck();


	// adds the passed card to the deck
	void AddCardInfoToDeck(
		Brood::Application::Components::CardInfo a_cardToAdd );

	// ============= private member variable =====================
private:
	// stack of undelt cards
	std::vector<Brood::Application::Components::CardInfo*> m_cardList;

	// holds the index of first undealt card
	unsigned m_currUndealtCardIdx;
};


// ======================================================================
// ================= start of Deck class ================================
// ======================================================================
