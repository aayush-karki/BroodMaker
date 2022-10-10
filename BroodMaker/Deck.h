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
#include "FileAccess.h"

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

	// initialize the deck
	void InitializeDeck( Brood::Application::Data::ST_DeckPrefabData& a_deckData );

	// returns the deck data to save 
	Brood::Application::Data::ST_DeckPrefabData GetDataToSave();

	// appends the the deck data to passed file 
	void SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr, std::string a_gameTitle,
	unsigned a_idx );

	// appends the the deck data to passed file 
	void LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr );

	// ============= getter functions ========

	// getter funciton to get the card list
	const std::vector< Brood::Application::Components::CardInfo*>& GetCardList() const;

	// gets pointer to the card at given index
	Brood::Application::Components::CardInfo* GetCardPtrAtIdx( unsigned a_cardInfoIdx );

	// gets card Init file name
	std::string GetCardInitFileName();

	// gets card Init file path
	std::string GetCardInitFilePath();

	// gets card current active card index
	unsigned GetCurrActiveCardIdx();

	// gets pointer to card  at current active card index
	CardInfo* GetCurrActiveCardPtr();

	// ============= setter functions ========
	
	// sets card current active card index
	void SetCurrActiveCardIdx( unsigned a_currActiveCardIdx );

	// sets deck size
	void SetCardListSize( unsigned a_cardListSize );

	// loads cards from a card Init file path
	bool LoadCardFromInitFile( std::string  a_fileInitPath);

	// loads cards from a card Init file path
	bool SaveCardToInitFile( std::string  a_fileInitPath );

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

	// holds the card init file Path
	std::string m_cardInitFilePath;

	// holds the card init file Path
	std::string m_cardInitFileName;

	// holds the index of card that is currently active
	unsigned m_currActiveCardIdx;
};


// ======================================================================
// ================= start of Deck class ================================
// ======================================================================
