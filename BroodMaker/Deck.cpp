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
	m_cardInitFilePath( "" ), m_cardInitFileName( "" ), m_currActiveCardIdx( 0 )
{

	SetBodySize( 100, 50 );
	SetBodyPosition( 70, 100 );
	SetBodyColor( Brood::Application::StaticVariables::ST_ColorVariables::GetRandomColor() );

	m_cardList.resize( 1, new CardInfo() );
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
/// @brief  initializes the deck with the passed data
/// 
/// @param a_deckData reference of the deck data
/// 
void Brood::Application::Components::Deck::InitializeDeck( Brood::Application::Data::ST_DeckPrefabData& a_deckData )
{
	/// setting up the deck 
	SetBodySize( a_deckData.stm_deckSizeX, a_deckData.stm_deckSizeY );
	SetBodyPosition( a_deckData.stm_deckPosX, a_deckData.stm_deckPosY );

	if( !a_deckData.stm_textureFileName.empty() )
	{
		m_bodySprite.SetTextureFromFilePath( a_deckData.stm_textureFileName );
	}

	SetCardListSize( a_deckData.stm_numTotalCard );

	if( !a_deckData.stm_cardInitFilename.empty() )
	{
		m_cardInitFilePath = a_deckData.stm_cardInitFilename;
		LoadCardFromInitFile( m_cardInitFilePath );
	}

	m_currUndealtCardIdx = a_deckData.stm_undealtCardIdx;
	m_currActiveCardIdx = a_deckData.stm_currActiveCardIdx;

}

/// 
/// @public
/// @brief creates and returns deck data struct
/// 
/// @return cardInfo data struct with the deck data in it
/// 
Brood::Application::Data::ST_DeckPrefabData Brood::Application::Components::Deck::GetDataToSave()
{
	Brood::Application::Data::ST_DeckPrefabData deckData;

	/// setting up the deck 
	deckData.stm_deckSizeX = GetBodySize().x;
	deckData.stm_deckSizeY = GetBodySize().y;
	deckData.stm_deckPosX = GetBodyPosition().x;
	deckData.stm_deckPosY = GetBodyPosition().y;

	deckData.stm_textureFileName = m_bodySprite.GetTextureFileName();

	deckData.stm_numTotalCard = m_cardList.size();
	deckData.stm_cardInitFilename = m_cardInitFileName;

	deckData.stm_undealtCardIdx = m_currUndealtCardIdx;
	deckData.stm_currActiveCardIdx = m_currActiveCardIdx;

	return deckData;
}

/// 
/// @public
/// @brief  initializes the deck with the passed data
/// 
/// @param a_fileAccessPtr pointer to a file Access object
/// @param a_gameTitle title of the game
/// @param a_idx this deck index in the deck manager
///
void Brood::Application::Components::Deck::SaveDataToFile( Brood::Application::FileAccess* a_fileAccessPtr,
														   std::string a_gameTitle, unsigned a_idx )
{
	// chekcing if card fileinit is there are not
	if( m_cardInitFileName.empty() )
	{
		m_cardInitFileName = a_gameTitle + "_CardInit" + std::to_string( a_idx ) + ".BroodM";
	}

	// saving the cardinfo in the cardinit file
	// create a FileAccess object
	Brood::Application::FileAccess cardFile;

	std::filesystem::path cardInitFile = Brood::Application::StaticVariables::ST_Folders::stm_data / m_cardInitFileName;

	// checking it it has an extention or not
	if( !cardInitFile.has_extension()
		|| ( cardInitFile.extension().string() != ".BroodM" ) )
	{
		cardInitFile = ( cardInitFile.parent_path() / cardInitFile.stem() );
		cardInitFile += ".BroodM";
	}

	// creating/opening the file
	cardFile.CreateFile( cardInitFile.string() );

	//  writing the card into the file
	for( int idx = 0; idx < m_cardList.size(); ++idx )
	{
		cardFile.WriteOneLineToFile( m_cardList.at( idx )->GetDataToSave().GetString() );
	}

	// saving the deck data
	a_fileAccessPtr->WriteOneLineToFile( GetDataToSave().GetString() );
}

/// 
/// @public
/// @brief loads the deck and its path data from passed file
/// 
/// @param a_fileAccessPtr pointer to a file Access object
///
void Brood::Application::Components::Deck::LoadDataFromFile( Brood::Application::FileAccess* a_fileAccessPtr )
{
	// loading the deck data
	Brood::Application::Data::ST_DeckPrefabData deckData;
	std::string dataFromFile;

	a_fileAccessPtr->GetNextLine( dataFromFile );

	deckData.PopulateFromString( dataFromFile );
	InitializeDeck( deckData );
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

Brood::Application::Components::CardInfo* Brood::Application::Components::Deck::GetCurrActiveCardPtr()
{
	return m_cardList.at( m_currActiveCardIdx );
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
	unsigned prelastIdx = m_cardList.size();

	// dynamically removing the extra deck
	if( a_cardListSize < m_cardList.size() )
	{
		for( int idx = a_cardListSize - 1; idx < m_cardList.size(); ++idx )
		{
			delete m_cardList.at( idx );
		}
		m_cardList.resize( a_cardListSize );
	}
	else
	{
		for( int idx = m_cardList.size(); idx < m_cardList.size(); ++idx )
		{
			m_cardList.push_back( new Brood::Application::Components::CardInfo() );
		}
	}
}

/// 
/// @public
/// @brief loads cards from a card Init file path
/// 
/// @param a_fileInitPath path to a file from which cards can be loaded into
/// 
bool Brood::Application::Components::Deck::LoadCardFromInitFile( std::string a_fileInitPath )
{
	// saving the cardinfo in the cardinit file
	// create a FileAccess object
	Brood::Application::FileAccess cardFile;

	std::filesystem::path cardInitFile = Brood::Application::StaticVariables::ST_Folders::stm_data / a_fileInitPath;

	// checking it it has an extention or not
	if( !cardInitFile.has_extension()
		|| ( cardInitFile.extension().string() != ".BroodM" ) )
	{
		cardInitFile = ( cardInitFile.parent_path() / cardInitFile.stem() );
		cardInitFile += ".BroodM";
	}

	// creating/opening the file
	if( !cardFile.OpenFile( cardInitFile.string() ) )
	{
		return false;
	}

	m_cardList.clear();
	// loading hte card info
	while( !cardFile.CheckEOF() )
	{
		// loading the board data
		Brood::Application::Data::ST_CardInfoPrefabData cardData;
		std::string dataFromFile;

		cardFile.GetNextLine( dataFromFile );
		
		if( dataFromFile == "" )
		{
			break;
		}

		cardData.PopulateFromString( dataFromFile );

		m_cardList.push_back( new CardInfo() );
		m_cardList.back()->InitializeCard( cardData );
	}

	m_cardInitFileName = cardInitFile.filename().string();
	m_currActiveCardIdx = 0;

	return true;
}

/// 
/// @public
/// @brief saves cards to a card Init file path
/// 
/// @param a_fileInitPath path to a file to which cards can be saveed into
///
bool Brood::Application::Components::Deck::SaveCardToInitFile( std::string a_fileInitPath )
{
	// TODO SaceCardFromInitFile
	return false;
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