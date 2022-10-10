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
	m_deckList.push_back( new Deck() );
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
	for( int idx = 0; idx < a_otherDeckManager.m_deckList.size(); ++idx )
	{
		this->m_deckList.push_back( new Deck( *( a_otherDeckManager.m_deckList.at( idx ) ) ) );
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
/// @public
/// @brief  initializes the deck manager with the passed data
/// 
/// @param a_deckManagerData reference of the deck manager data
/// 
void Brood::Application::Components::DeckManager::InitializeDeckManager( Brood::Application::Data::ST_DeckManagerData& a_deckManagerData )
{
	m_incorrectPenalty = a_deckManagerData.stm_incorrectPenalty;
	m_movementType = static_cast< Brood::Application::Components::ENUM_MovementType >( a_deckManagerData.stm_movementType );
	m_currDeckIdx = a_deckManagerData.stm_currDecksIdx;
	SetDeckSize( a_deckManagerData.stm_numDecks );
}

/// @public
/// @brief creates and returns deck manager data struct
/// 
/// @return cardInfo data struct with the deck manager data in it
/// 
Brood::Application::Data::ST_DeckManagerData Brood::Application::Components::DeckManager::GetDataToSave()
{
	Brood::Application::Data::ST_DeckManagerData deckManagerData;

	deckManagerData.stm_incorrectPenalty = m_incorrectPenalty;
	deckManagerData.stm_movementType = ( unsigned )m_movementType;
	deckManagerData.stm_currDecksIdx = m_currDeckIdx;
	deckManagerData.stm_numDecks = m_deckList.size();

	return deckManagerData;
}
/// 
/// @public
/// @brief saves the deck manager and its path data to passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// @param a_gameTitle title of the game
/// 
void Brood::Application::Components::DeckManager::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr,
																  std::string a_gameTile )
{
	// saving the deck manger data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );

	// saving the deck's data
	for( unsigned numDecks = 0; numDecks < m_deckList.size(); ++numDecks )
	{
		m_deckList.at( numDecks )->SaveDataToFile( a_fileAccessPtr, a_gameTile, numDecks );
	}
}

/// 
/// @public
/// @brief loads the deck manager  from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
///
void Brood::Application::Components::DeckManager::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// loading the deck manager data
	Brood::Application::Data::ST_DeckManagerData deckManagerData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	deckManagerData.PopulateFromString( dataFromFile );
	InitializeDeckManager( deckManagerData );

	// initialing the decs
	for( unsigned numDecks = 0; numDecks < m_deckList.size(); ++numDecks )
	{
		m_deckList.at( numDecks )->LoadDataFromFile( a_fileAccessPtr );
	}


}

/// 
/// @brief getter funciton to get the current deck index
/// 
/// @return current deck index
/// 
unsigned Brood::Application::Components::DeckManager::GetCurrActiveDeckIdx()
{
	return m_currDeckIdx;
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

	return m_deckList.at( a_deckIdx );

}

/// 
/// @brief getter function to get the deck list
/// 
/// @return reference to the decklist
/// 
std::vector<Brood::Application::Components::Deck*>& Brood::Application::Components::DeckManager::GetDeckList()
{
	return m_deckList;
}

/// 
/// @brief getter function to get the current active deck 
/// 
/// @return pointer to current active deck
/// 
Brood::Application::Components::Deck* Brood::Application::Components::DeckManager::GetCurrActiveDeck()
{
	return m_deckList.at( m_currDeckIdx );
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
	unsigned prelastIdx = m_deckList.size();
	sf::Vector2f preLastIdxPos = m_deckList.back()->GetBodyPosition();

	// dynamically removing the extra deck
	if( a_deckSize < m_deckList.size() )
	{
		for( int idx = a_deckSize - 1; idx < m_deckList.size(); ++idx )
		{
			delete m_deckList.at( idx );
		}
		m_deckList.resize( a_deckSize );
	}
	else
	{
		for( int idx = m_deckList.size() ; idx < a_deckSize; ++idx )
		{
			m_deckList.push_back(new Brood::Application::Components::Deck());
		}
	}

	// positioning all the newly created decks
	for( prelastIdx; prelastIdx < m_deckList.size(); ++prelastIdx )
	{
		preLastIdxPos.x += 40;
		m_deckList.at( prelastIdx )->SetBodyPosition( preLastIdxPos );
	}
}

/// 
/// @brief Setter funciton to set the current deck index
/// 
/// @param a_currDeckIdx deck index
/// 
void Brood::Application::Components::DeckManager::SetCurrActiveDeckIdx( unsigned a_currDeckIdx )
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
	m_deckList.at( m_currDeckIdx )->AddCardInfoToDeck( a_cardToAdd );
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
	std::vector<Brood::Application::Components::Deck*>::iterator deckListIte = m_deckList.begin();

	while( deckListIte != m_deckList.end() )
	{
		( *deckListIte )->Draw( a_window );
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
	std::vector<Brood::Application::Components::Deck*>::iterator deckListIte = m_deckList.begin();

	while( deckListIte != m_deckList.end() )
	{
		//( *deckListIte ).Debugger();
		( *deckListIte )->Debugger();
		++deckListIte;
	}
}


// ======================================================================
// ================= end of DeckManager class ===========================
// ======================================================================