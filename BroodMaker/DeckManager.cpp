/*************************************************************************/
/// 
/// @file DeckManager.cpp 
/// 
/// @brief  This file is a source file for DeckManager class.
/// 
/// It contains all of the defination of the member 
///		funciton of DeckManager class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "DeckManager.h"

// ======================================================================
// ================= start of DeckManager class =========================
// ======================================================================

///
/// @brief default constructor
/// 
Brood::Application::Components::DeckManager::DeckManager() :
	m_currDeckIdx( 0 ), m_incorrectPenalty( true ),
	m_movementType( Brood::Application::Components::ENUM_MovementType::MOVEMENT_diceThenCard )
{
	m_deckList.resize( 1 );
}

///
/// @brief default destructor
/// 
Brood::Application::Components::DeckManager::~DeckManager()
{}

///
/// @brief copy constructor
/// 
/// @param a_otherDeckManager reference to the the deck manager 
///			object that is being copied from 
///
Brood::Application::Components::DeckManager::DeckManager( const Brood::Application::Components::DeckManager& a_otherDeckManager ) :
	m_currDeckIdx( a_otherDeckManager.m_currDeckIdx ), m_incorrectPenalty( a_otherDeckManager.m_incorrectPenalty ),
	m_movementType( a_otherDeckManager.m_movementType )


{
	std::vector<Brood::Application::Components::Deck>::const_iterator otherDeckListIte = a_otherDeckManager.m_deckList.begin();

	while( otherDeckListIte != a_otherDeckManager.m_deckList.end() )
	{
		this->m_deckList.push_back( Deck( *otherDeckListIte ) );
		++otherDeckListIte;
	}
}

///
/// @public 
/// @brief assignmnet operator
/// 
/// @param a_otherDeckManager reference to the the deck manager 
///			object that is being copied from  
///
Brood::Application::Components::DeckManager& Brood::Application::Components::DeckManager::operator=( const Brood::Application::Components::DeckManager& a_otherDeckManager )
{
	// checking for self assignment
	if( this == &a_otherDeckManager )
	{
		return *this;
	}

	// creating a temporary deck object
	Brood::Application::Components::DeckManager tempDeckManager( a_otherDeckManager );

	// swapping the deck of this object and tempDeckObject
	std::swap( this->m_deckList, tempDeckManager.m_deckList );

	this->m_currDeckIdx = a_otherDeckManager.m_currDeckIdx;
	this->m_incorrectPenalty = a_otherDeckManager.m_incorrectPenalty;
	this->m_movementType = a_otherDeckManager.m_movementType;

	return *this;
}

/// 
/// @brief getter function to get the deck at the passed index
/// 
/// @param a_deckIdx index from which the deck is to be returned
/// 
/// @return pointer to the deck at passed index if valid; else nullptr
/// 
Brood::Application::Components::Deck* Brood::Application::Components::DeckManager::GetDeckAtIdx( unsigned a_deckIdx )
{
	if( m_deckList.size() <= a_deckIdx )
	{
		return nullptr;
	}

	return &m_deckList.at( a_deckIdx );

}

/// 
/// @brief getter function to get the deck list
/// 
/// @return reference to the decklist
/// 
std::vector<Brood::Application::Components::Deck>& Brood::Application::Components::DeckManager::GetDeckList()
{
	return m_deckList;
}

/// 
/// @brief getter function to get current incorrect penalty value
/// 
/// @return current incorrect penalty value
/// 
bool Brood::Application::Components::DeckManager::GetIncorrectPenalty()
{
	return m_incorrectPenalty;
}

/// 
/// @brief getter function to get current movement type value
/// 
/// @return current current movement type value
/// 
Brood::Application::Components::ENUM_MovementType Brood::Application::Components::DeckManager::GetMovementType()
{
	return m_movementType;
}

/// 
/// @brief setter function to set current incorrect penalty value
/// 
/// @param a_incorrectPenatly incorrect penalty value to set
/// 
void Brood::Application::Components::DeckManager::SetIncorrectPenalty( bool a_incorrectPenatly )
{
	m_incorrectPenalty = a_incorrectPenatly;
}

/// 
/// @brief setter function to set current movement type value
/// 
/// @param a_movementType current movement type value to set
/// 
void Brood::Application::Components::DeckManager::SetMovementType( Brood::Application::Components::ENUM_MovementType a_movementType )
{
	m_movementType = a_movementType;
}


/// 
/// @brief Resizes the deck
/// 
/// @param a_deckSize deck size
/// 
void Brood::Application::Components::DeckManager::SetDeckSize( unsigned a_deckSize )
{
	m_deckList.resize( a_deckSize, Deck() );
}

/// 
/// @brief Setter funciton to set the current deck index
/// 
/// @param a_currDeckIdx deck index
/// 
void Brood::Application::Components::DeckManager::SetCurrDeckIdx( unsigned a_currDeckIdx )
{
	m_currDeckIdx = a_currDeckIdx;
}

/// 
/// @brief Adds a card to the deck at current index
/// 
/// @param a_cardToAdd card info to add the current deck
///
void Brood::Application::Components::DeckManager::AddCardToDeckAtCurrIdx( Brood::Application::Components::CardInfo a_cardToAdd )
{
	m_deckList.at( m_currDeckIdx ).AddCardInfoToDeck( a_cardToAdd );
}

/// 
/// @public
/// @virtual
/// @brief Draw funciton
/// 
/// Draws all the component to the screen
//
void Brood::Application::Components::DeckManager::Draw( sf::RenderWindow& a_window )
{
	// drawing all the decks
	std::vector<Brood::Application::Components::Deck>::iterator deckListIte = m_deckList.begin();

	while( deckListIte != m_deckList.end() )
	{
		( *deckListIte ).Draw( a_window );
		++deckListIte;
	}
}

/// 
/// @public
/// @virtual
/// @brief debugger funciton
/// 
/// This function helps in debugging the UI elements.
///
void Brood::Application::Components::DeckManager::Debugger()
{
	// debugging all the decks
	std::vector<Brood::Application::Components::Deck>::iterator deckListIte = m_deckList.begin();

	while( deckListIte != m_deckList.end() )
	{
		( *deckListIte ).Debugger();
		++deckListIte;
	}
}


// ======================================================================
// ================= end of DeckManager class ===========================
// ======================================================================