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
//
//static char* Brood::UtilityFuncs::showOpenFileDialog( char* descriptionOfFile, char* fileExtension )
//{
//	char* result = 0;
//
//	const uint32_t fileNameSize = 512;
//	char* fileNameBuffer = ( char* )HEAP_ALLOC( fileNameSize );
//
//	OPENFILENAME openFileName = {};
//	openFileName.lStructSize = sizeof( OPENFILENAME );
//
//	char filter[ fileNameSize ] = {};
//	uint32_t stringIndex;
//	for( stringIndex = 0; descriptionOfFile[ stringIndex ] != 0; ++stringIndex )
//	{
//		filter[ stringIndex ] = descriptionOfFile[ stringIndex ];
//	}
//
//	++stringIndex;
//	filter[ stringIndex++ ] = '*';
//	filter[ stringIndex++ ] = '.';
//	for( uint32_t i = 0; fileExtension[ i ] != 0; ++i )
//	{
//		filter[ stringIndex++ ] = fileExtension[ i ];
//	}
//
//	openFileName.lpstrFilter = filter;
//	openFileName.lpstrFile = fileNameBuffer;
//	openFileName.nMaxFile = fileNameSize;
//	openFileName.Flags = OFN_FILEMUSTEXIST;
//	openFileName.lpstrDefExt = fileExtension;
//
//	if( GetOpenFileName( &openFileName ) != 0 )
//	{
//		result = fileNameBuffer;
//	}
//
//	return result;
//}