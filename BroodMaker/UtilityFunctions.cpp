#include "stdafx.h"
#include "UtilityFunctions.h"

/// 
/// @brief It opens a texture form a file and loads it into the texture
/// 
/// It also log to console if texture loading was unsucessful
/// 
/// @param a_texture reference to the texture object where the loaded texture is to be stored
/// @param a_filePath file path that points to the texture to be loaded
/// @return true if the texture was loaded successfully; else returns false
///
bool Brood::UtilityFuncs::LoadTextureFromFile( sf::Texture& a_texture, std::string a_filePath )
{
	if( !( a_texture.loadFromFile( a_filePath ) ) )
	{
		std::cerr << "Error! Could not load " << a_filePath << "!!!!!!!" << std::endl;
		return false;
	}
	return true;
}

/// 
/// @overlaod
/// @brief It opens a texture form a file and loads it into the texture
/// 
/// It also log to console if texture loading was unsucessful
/// 
/// @param a_texture reference to the texture object where the loaded texture is to be stored
/// @param a_cwd current working directory
/// @param a_filePath file path that points to the texture to be loaded
/// @return true if the texture was loaded successfully; else returns false
///
bool Brood::UtilityFuncs::LoadTextureFromFile( sf::Texture& a_texture, const std::string& a_cwd, std::string a_filePath )
{
	return LoadTextureFromFile( a_texture, a_cwd + a_filePath );
}