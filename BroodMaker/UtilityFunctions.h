#pragma once
//#include "windows.h"
//#include "commdlg.h"

/// @defgroup Brood
namespace Brood
{
	/// @ingroup Brood UtilityFuncs
	/// 
	/// @brief It contains all the utility functions for which making a stand alone class
	///		would not make sense
	/// 
	namespace UtilityFuncs
	{
		/*#define HEAP_ALLOC(bytes) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bytes);
		#define HEAP_FREE(ptr) HeapFree(GetProcessHeap(), 0, ptr);/// */

		// a function to load the texture from a file
		bool LoadTextureFromFile( sf::Texture& a_texture, const std::string& a_cwd, std::string a_filePath );
		bool LoadTextureFromFile(sf::Texture& a_texture, std::string a_filePath);
		//static char* showOpenFileDialog( char* descriptionOfFile, char* fileExtension );
	}
}