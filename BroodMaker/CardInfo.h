/*************************************************************************/
/*************************************************************************/
/// 
/// @file CardInfo.h 
/// 
/// @brief  This file is a header file for Dice class.
/// 
/// It contains all of the declaration of the member 
///		funciton of Dice class.
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood::Application
{
	namespace Components
	{
		class CardInfo;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of CardInfo class ============================
// ======================================================================

///
/// @class St_CardInfo  "CardInfo.h"
/// 
/// @brief A class to store the information that is to be 
///		displayed in the card
/// 
class Brood::Application::Components::CardInfo
{
	// ============== public memeber function =================
public:
	// default constructor
	CardInfo( unsigned a_time = 0, unsigned a_correctNumSteps = 0,
				 unsigned a_incorrectNumSteps = 0, std::string a_question = "",
				 std::string a_correctAnswer = "" );
	
	// default constructor
	~CardInfo();

	// copy constructor
	CardInfo( const CardInfo& a_other );

	// assignment constructor
	CardInfo& operator = ( const CardInfo& a_other );

	// getter funciton to get time
	unsigned GetTime();

	// getter funciton to get correct number of steps
	unsigned GetCorrectNumSteps();

	// getter funciton to get incorrect number of steps
	unsigned GetIncorrectNumSteps();

	// getter funciton to get question
	std::string GetQuestion();

	// getter funciton to get correct answer
	std::string GetCorrectAnswer();

	// setter funciton to get time
	void SetTime( unsigned a_time );

	// setter funciton to get correct number of steps
	void SetCorrectNumSteps( unsigned a_correctNumSteps );

	// setter funciton to get incorrect number of steps	
	void SetIncorrectNumSteps( unsigned a_incorrectNumSteps );

	// setter funciton to get question
	void SetQuestion( std::string a_question );

	// setter funciton to get correct anser
	void SetCorrectAnswer( std::string a_correctAnswer );

	// ============== private memeber variables =================
private:

	// following are in the front of the card

	/// the time the player has to answer the question
	unsigned m_time;

	/// number steps the player move forward if answered correctly
	unsigned m_correctNumSteps;

	/// number steps the player move backward if answered incorrectly
	unsigned m_incorrectNumSteps;

	// following are in the back of the card

	/// stores the question
	std::string m_question;

	// stores the correct answer
	std::string m_correctAnswer;
};

// ======================================================================
// ================= end of CardInfo class ==============================
// ======================================================================