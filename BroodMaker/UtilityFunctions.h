#pragma once

/// @defgroup Brood
namespace Brood
{
	/// 
	/// @ingroup Brood UtilityFuncs
	/// 
	/// @brief It contains all the utility functions for which making a stand alone class
	///		would not make sense
	/// 
	namespace UtilityFuncs
	{
		// a function to load the texture from a file
		bool LoadTextureFromFile( sf::Texture& a_texture, const std::string& a_cwd, std::string a_filePath );
		bool LoadTextureFromFile(sf::Texture& a_texture, std::string a_filePath);
	}
}