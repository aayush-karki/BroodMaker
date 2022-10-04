/*************************************************************************/
/// 
/// @file Deck.h 
/// 
/// @brief This file is a source file for Deck class.
/// 
/// It contains all of the defination of the member 
///		funciton of Deck class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "Deck.h"

// ======================================================================
// ================= start of Deck class ================================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
///	
/// Initializes the Deck object
/// 
/// @param m_parentPtr pointer to the parent element;
///		if parent does not exist then nullptr -> default value nullptr
/// 
Brood::Application::Components::Deck::Deck( Brood::BroodUI::UIElement* a_parentPtr ) :
	Brood::BroodUI::Button( a_parentPtr ), m_currUndealtCardIdx( 0 ), 
	m_cardInitFilePath(""), m_cardInitFileName(""), m_currActiveCardIdx(0)
{

	SetBodySize( 100, 50 );
	SetBodyPosition( 70, 100 );
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );

	m_cardList.resize(1, new CardInfo());
}

/// 
/// @brief destructor
/// 
Brood::Application::Components::Deck::~Deck()
{
	for( int idx = 0; idx < m_cardList.size(); ++idx )
	{
		delete m_cardList.at( idx );
	}
}

///
/// @public 
/// @brief copy constructor
/// 
/// @param a_other reference to the the deck 
///			object that is being copied from 
/// 
Brood::Application::Components::Deck::Deck( const Deck& a_other ) :
	Brood::BroodUI::Button( a_other ),
	m_currUndealtCardIdx( a_other.m_currUndealtCardIdx ),
	m_cardInitFilePath( a_other.m_cardInitFilePath ),
	m_cardInitFileName( a_other.m_cardInitFileName ),
	m_currActiveCardIdx( a_other.m_currActiveCardIdx )

{
	for( int idx = 0; idx < a_other.GetCardList().size(); ++idx )
	{
		this->m_cardList.push_back( new CardInfo( *( a_other.m_cardList.at( idx ) ) ) );
	}
}

///
/// @public 
/// @brief assignmnet operator
/// 
/// @param a_other reference to the the deck 
///			object that is being copied from 
/// 
Brood::Application::Components::Deck& Brood::Application::Components::Deck::operator=( const Deck& a_other )
{
	// checking for self assignment
	if( this == &a_other )
	{
		return *this;
	}

	// copying the button
	Brood::BroodUI::Button::operator=( a_other );

	// copying the card info
	for( int idx = 0; idx < a_other.GetCardList().size(); ++idx )
	{
		this->m_cardList.push_back( new CardInfo( *( a_other.m_cardList.at( idx ) ) ) );
	}

	this->m_currUndealtCardIdx = a_other.m_currUndealtCardIdx;
	this->m_cardInitFilePath = a_other.m_cardInitFilePath;
	this->m_cardInitFileName = a_other.m_cardInitFileName;
	this->m_currActiveCardIdx = a_other.m_currActiveCardIdx;

	return *this;
}

///
/// @public 
/// @brief Getter function to get the cardInfoList
/// 
/// @return constance reference to the card Info List
/// 
const std::vector< Brood::Application::Components::CardInfo*>& Brood::Application::Components::Deck::GetCardList() const
{
	return this->m_cardList;
}


///
/// @public 
/// @brief Gets a card info pointer to the passed index
/// 
/// @param a_cardInfoIdx card info at passed index
/// 
/// @return pointer to the card given index
Brood::Application::Components::CardInfo* Brood::Application::Components::Deck::GetCardPtrAtIdx( unsigned a_cardInfoIdx )
{
	return m_cardList.at( a_cardInfoIdx );
}

/// 
/// @public
/// @brief gets card Init file name
/// 
/// @return card Init file name
/// 
std::string Brood::Application::Components::Deck::GetCardInitFileName()
{
	return m_cardInitFileName;
}

/// 
/// @public
/// @brief gets card Init file path
/// 
/// @return card Init file path
/// 
std::string Brood::Application::Components::Deck::GetCardInitFilePath()
{
	return m_cardInitFilePath;
}

/// 
/// @public
/// @brief gets card current active card index
/// 
/// @return card Init file path
/// 
unsigned Brood::Application::Components::Deck::GetCurrActiveCardIdx()
{
	return m_currActiveCardIdx;
}

/// 
/// @public
/// @brief sets card current active card index
/// 
/// @return card Init file path
///
void Brood::Application::Components::Deck::SetCurrActiveCardIdx( unsigned a_currActiveCardIdx )
{
	m_currActiveCardIdx = a_currActiveCardIdx;
}

/// @brief resizes the card list
/// @param a_cardListSize 
void Brood::Application::Components::Deck::SetCardListSize( unsigned a_cardListSize )
{
	m_cardList.resize( a_cardListSize, new CardInfo() );
}

/// 
/// @public
/// @brief cards from a card Init file path
/// 
/// @param a_fileInitPath path to a file from which cards can be loaded into
/// 
bool Brood::Application::Components::Deck::LoadCardFromInitFile( std::string a_fileInitPath )
{
	/// open texture
	//	if( !Brood::UtilityFuncs::LoadTextureFromFile( m_texture, a_texturePath ) )
	//	{
	//		return false;
	//	}
	// 
	// saving the texture path
	std::size_t found = a_fileInitPath.find_last_of( "/\\" );
	m_cardInitFilePath = a_fileInitPath.substr( 0, found );
	m_cardInitFileName = a_fileInitPath.substr( found + 1 );

	return true;
}

///
/// @public 
/// @brief Function to deal the next undeal card
/// 
/// If all the card are dealt then it resets the dealt and shuffles it
/// 
/// @return a cardInfo object witht the dealt card
/// 
const Brood::Application::Components::CardInfo Brood::Application::Components::Deck::DealCard()
{
	Brood::Application::Components::CardInfo dealtCard( *( m_cardList.at( m_currUndealtCardIdx ) ) );

	++m_currUndealtCardIdx;

	// checking if the m_currUndealtCardIdx is at the end of the list
	if( m_currUndealtCardIdx >= m_cardList.size() )
	{
		ResetDeck();
	}

	return dealtCard;
}

/// 
/// @public
/// @brief shuffels the deck
/// 
void Brood::Application::Components::Deck::Shuffel()
{
	std::shuffle( m_cardList.begin(), m_cardList.end(), std::default_random_engine( Brood::Application::StaticVariables::ST_GlobalCoreVariables::stm_seed ) );
}

/// 
/// @public
/// @brief resets the m_currUndealt card index to zero and suffels the deck
/// 
void Brood::Application::Components::Deck::ResetDeck()
{
	m_currUndealtCardIdx = 0;

	// suffeling the deck
	Shuffel();
}

/// 
/// @public
/// @brief adds the passed card info into the list
/// 
/// @param a_cardToAdd card to add to the deck
/// 
void Brood::Application::Components::Deck::AddCardInfoToDeck( Brood::Application::Components::CardInfo a_cardToAdd )
{
	m_cardList.push_back( new CardInfo( a_cardToAdd ) );
}

// ======================================================================
// ================= end of Deck class ==================================
// ======================================================================