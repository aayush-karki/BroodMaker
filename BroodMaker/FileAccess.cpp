/*************************************************************************/
/// 
/// @file InitialWorkSpace.cpp 
/// 
/// @brief  This file is a source file for InitialWorkSpace class.
/// 
/// It contains all of the defination of the member 
///		funciton of InitialWorkSpace class.
/// 
/************************************************************************/

// ======================================================================
// ===================== included files =================================
// ======================================================================
#include "stdafx.h"
#include "FileAccess.h"

// ======================================================================
// ================= start of InitialWorkSpace class ====================
// ======================================================================

/// 
/// @public
/// @brief default constructor
/// 
Brood::Application::FileAccess::FileAccess() :
	m_fileHandler(), m_filePath()
{}

/// 
/// @public
/// @brief default destructor
/// 
Brood::Application::FileAccess::~FileAccess()
{
	m_fileHandler.close();
}

/// 
/// @public
/// @brief opens the passed file in read and write mode
///
/// @param a_fullfileName filepath to the file that is to be opened
/// 
/// @return true on successfull opening; else false
/// 
bool Brood::Application::FileAccess::OpenFile( std::string a_fullfileName )
{
	// File Open
	m_filePath = a_fullfileName;

	if( !m_filePath.empty() && !m_filePath.has_extension() )
	{
		m_filePath += ".txt";
	}

	m_fileHandler.open( a_fullfileName, std::ios::in | std::ios::out );

	// Check if the file has opened
	if( !m_fileHandler )
	{
		std::cerr << "Could not open File " << a_fullfileName << std::endl;
		return false;
	}


	return true;
}

/// 
/// @public
/// @brief Get the next line from the file.
///
/// @param  is the string where the extracted line is stored
/// 
/// @returns true if there was one.
///
bool  Brood::Application::FileAccess::GetNextLine( std::string& a_line )
{
	//if eof reached return false
	if( m_fileHandler.eof() )
	{
		return false;
	}

	std::getline( m_fileHandler, a_line );

	return true;
}

/// 
/// @brief removes all content form the file and points
/// the pointer to beginning of the file
/// 
void  Brood::Application::FileAccess::RemoveAllContent()
{
	std::filesystem::resize_file( m_filePath, 0 );
	m_fileHandler.clear();
	m_fileHandler.seekg( 0, std::ios::beg );
}

/// 
/// @public
/// @brief wrties a line to the the file.
///
/// @param  is the string that is added to the file 
///  
void  Brood::Application::FileAccess::WriteOneLineToFile( std::string& a_line )
{
	m_fileHandler << a_line << std::endl;
}

/// 
/// @public
/// @brief checks if the end of file is reached or not
/// 
/// @return true if file pointer is pointed at end of file
/// 
bool Brood::Application::FileAccess::CheckEOF()
{
	return m_fileHandler.eof();
}

