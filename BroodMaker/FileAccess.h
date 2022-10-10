/*************************************************************************/
/// 
/// @file FileAccess.h 
/// 
/// @brief  This file is a header file for FileAccess class.
/// 
/// It contains all of the declaration of the member 
///		funciton of FileAccess class.
/// It contains all of the inline funcitons defination of 
///		the member funciton of FileAccess class
///
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================

#pragma once
#include "GlobalVariables.h"

// ======================================================================
// ================= defining namespace =================================
// ======================================================================
namespace Brood
{
	namespace Application
	{
		class FileAccess;
	}
}
// ======================================================================
// ================= end of namespace defination ========================
// ======================================================================

// ======================================================================
// ================= start of FileAccess class ==========================
// ======================================================================

/// 
/// @ingroup Components
/// @class Board  "FileAccess.h"
/// @brief A container Class to create a board
/// 
/// @note that board orgin is set in the upper left corner;
///		 which will be consistent through out the applicaiton
/// 
class Brood::Application::FileAccess
{
	// ================== public member fuction =======================
public:
	// constructor
	FileAccess();

	// destructor
	~FileAccess();

	// opens the passed file
	bool OpenFile( std::string a_fullfileName );

	// creates a file and returns the file
	bool CreateFile( std::string a_fullfileName );

	// gets next line form the file
	bool GetNextLine( std::string& a_line );

	// goes back to the beginning of the file
	void Rewind();

	// removes all content form the file and goes to 
	// beginning of the file
	void RemoveAllContent();

	// appends a line to the end
	void WriteOneLineToFile( const std::string& a_line );

	// checks if the eof reached or not
	bool CheckEOF();

	// ========== private member functions ===============
private:

	/// file handler
	std::fstream m_fileHandler;

	std::filesystem::path m_filePath;
};


// ======================================================================
// ================= end of FileAccess class ============================
// ======================================================================