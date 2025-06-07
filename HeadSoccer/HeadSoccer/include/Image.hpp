#ifndef __image_hpp
#define __image_hpp

#include "common.hpp"
#include "Res.hpp"

#include <atlimage.h>

class Image : public Resource {
	Image( ) : Resource( ), image_( ) {}
	Image( std::string_view key, const std::string& filePath )
		: Resource( key ), image_( ) {
		auto path = std::wstring( filePath.begin( ), filePath.end( ) );
		image_.Load( path.c_str( ) );
	}

	virtual ~Image( ) {}

	void load( const std::string& filePath ) {
		auto path = std::wstring( filePath.begin( ), filePath.end( ) );
		image_.Load( path.c_str( ) );
	}

	void draw( HDC hdc, const PointFloat& objPos ) {
		image_.Draw( hdc,
			static_cast<int>( objPos.x - image_.GetWidth( ) / 2.f ),
			static_cast<int>( objPos.y - image_.GetHeight( ) / 2.f ),
			image_.GetWidth( ), image_.GetHeight( ) );
	}

	void draw( HDC hdc, int xDest, int yDest, int nDestWidth, int nDestHeight,
		int xSrc, int ySrc, int nSrcWidth, int nSrcHeight ) 
	{
		image_.Draw( hdc, xDest, yDest, nDestWidth, nDestHeight,
			xSrc, ySrc, nSrcWidth, nSrcHeight );
	}

	void draw( HDC hdc, int xDest, int yDest, int nDestWidth, int nDestHeight,
		int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, BYTE alpha ) 
	{
		image_.AlphaBlend( hdc, xDest, yDest, nDestWidth, nDestHeight,
			xSrc, ySrc, nSrcWidth, nSrcHeight, alpha );
	}

	std::int32_t width( ) const {
		return image_.GetWidth( );
	}

	std::int32_t height( ) const {
		return image_.GetHeight( );
	}

private:
	CImage image_;
};

#endif	// __image_hpp