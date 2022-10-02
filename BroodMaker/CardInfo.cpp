/*************************************************************************/
/// 
/// @file Card.cpp 
/// 
/// @brief  This file is a source file for Card class.
/// 
/// It contains all of the defination of the member 
///		funciton of Card class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#include "stdafx.h"
#include "CardInfo.h"

// ======================================================================
// ================= start of CardInfo class ============================
// ======================================================================

/// 
/// @public
/// @brief Default Constructor
/// 
Brood::Application::Components::CardInfo::CardInfo( unsigned a_time,
													unsigned a_correctNumSteps,
													unsigned a_incorrectNumSteps,
													std::string a_question,
													std::string a_correctAnswer ) :
	m_time( a_time ), m_correctNumSteps( a_correctNumSteps ),
	m_incorrectNumSteps( a_incorrectNumSteps ), m_question( a_question ),
	m_correctAnswer( a_correctAnswer )
{}

/// 
/// @public
/// @brief Default destructor
/// 
Brood::Application::Components::CardInfo::~CardInfo()
{}

/// 
/// @public
/// @brief copy constructor
/// @param a_other reference to the cardinfo which is used to 
///		copy the data form 
///
Brood::Application::Components::CardInfo::CardInfo( const Brood::Application::Components::CardInfo& a_other ) :
	CardInfo( a_other.m_time, a_other.m_correctNumSteps, a_other.m_incorrectNumSteps,
			  a_other.m_question, a_other.m_correctAnswer )
{}

/// 
/// @brief assignment operator
/// 
/// @param a_other reference to the cardinfo which is used to 
///		copy the data form 
/// 
/// @return pointer to this cardinfo
///
Brood::Application::Components::CardInfo& Brood::Application::Components::CardInfo::operator=( const Brood::Application::Components::CardInfo& a_other )
{
	// chekcing for self assignment
	if( this == &a_other )
	{
		return *this;
	}

	// copying the data
	this->m_time = a_other.m_time;
	this->m_correctNumSteps = a_other.m_correctNumSteps;
	this->m_incorrectNumSteps = a_other.m_incorrectNumSteps;
	this->m_question = a_other.m_question;
	this->m_correctAnswer = a_other.m_correctAnswer;

	return *this;
}

/// 
/// @public
/// @brief Getter funciton to get time to complete the question
/// 
/// @return the time the player has to answer the question
///
unsigned Brood::Application::Components::CardInfo::GetTime()
{
	return m_time;
}

/// 
/// @public
/// @brief getter funciton to get correct number of steps
/// 
/// @return number steps the player move forward if answered correctly
/// 
unsigned Brood::Application::Components::CardInfo::GetCorrectNumSteps()
{
	return m_correctNumSteps;
}

/// 
/// @public
/// @brief Getter funciton to get incorrect number of steps
/// 
/// @return number steps the player move backward if answered incorrectly
///
unsigned Brood::Application::Components::CardInfo::GetIncorrectNumSteps()
{
	return m_incorrectNumSteps;
}

/// 
/// @public
/// @brief Getter function to get question
/// 
/// @return question
///
std::string Brood::Application::Components::CardInfo::GetQuestion()
{
	return m_question;
}

/// 
/// @public
/// @brief Getter funcitonto get correct anser
/// 
/// @return correct answer
///
std::string Brood::Application::Components::CardInfo::GetCorrectAnswer()
{
	return m_correctAnswer;
}

/// 
/// @public
/// @brief Setter funciton to set time to complete the question
/// 
/// @param a_time the time the player has to answer the question
///
void Brood::Application::Components::CardInfo::SetTime( unsigned a_time )
{
	m_time = a_time;
}

/// 
/// @public
/// @brief setter funciton to get correct number of steps
/// 
/// @param a_correctNumSteps number steps the player move forward if answered correctly
/// 
void Brood::Application::Components::CardInfo::SetCorrectNumSteps( unsigned a_correctNumSteps )
{
	m_correctNumSteps = a_correctNumSteps;
}

/// 
/// @public
/// @brief Setter funciton to get incorrect number of steps
/// 
/// @param a_incorrectNumSteps number steps the player move backward if answered incorrectly
///
void Brood::Application::Components::CardInfo::SetIncorrectNumSteps( unsigned a_incorrectNumSteps )
{
	m_incorrectNumSteps = a_incorrectNumSteps;
}

/// 
/// @public
/// @brief Setter function to get question
/// 
/// @return a_question question
///
void Brood::Application::Components::CardInfo::SetQuestion( std::string a_question )
{
	m_question = a_question;
}

/// 
/// @public
/// @brief setter funcitonto get correct anser
/// 
/// @param a_correctAnswer correct answer
///
void Brood::Application::Components::CardInfo::SetCorrectAnswer( std::string a_correctAnswer )
{
	m_correctAnswer = a_correctAnswer;
}

// ======================================================================
// ================= end of CardInfo class ==============================
// ======================================================================