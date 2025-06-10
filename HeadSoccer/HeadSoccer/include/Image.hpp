#ifndef __image_hpp
#define __image_hpp

#include "common.hpp"
#include "Res.hpp"

#include <atlimage.h>

class Image : public Resource {
public:
	Image( ) : Resource( ), image_( ) {}
	Image( std::string_view key, const std::string& filePath, bool premultipliedAlpha )
		: Resource( key ), image_( ) {
		auto path = std::wstring( filePath.begin( ), filePath.end( ) );
		image_.Load( path.c_str( ) );

		if ( !image_.IsNull( ) && premultipliedAlpha ) {
			setPremultipliedAlpha( );
		}
	}

	virtual ~Image( ) {}

	void setPremultipliedAlpha( ) {
		unsigned char* pCol = nullptr;
		auto width = image_.GetWidth( );
		auto height = image_.GetHeight( );

		for ( auto y = 0; y < height; ++y ) {
			for ( auto x = 0; x < width; ++x ) {
				pCol = (unsigned char*)image_.GetPixelAddress( x, y );
				auto alpha = pCol[ 3 ];

				if ( alpha < 255 ) {
					pCol[ 0 ] = ( ( pCol[ 0 ] * alpha ) + 127 ) / 255;
					pCol[ 1 ] = ( ( pCol[ 1 ] * alpha ) + 127 ) / 255;
					pCol[ 2 ] = ( ( pCol[ 2 ] * alpha ) + 127 ) / 255;
				}
			}
		}
	}

	void load( const std::string& filePath, bool premultipliedAlpha ) {
		auto path = std::wstring( filePath.begin( ), filePath.end( ) );
		image_.Load( path.c_str( ) );

		if ( !image_.IsNull( ) && premultipliedAlpha ) {
			setPremultipliedAlpha( );
		}
	}

	void draw( HDC hdc, const PointFloat& objPos ) {
		image_.Draw( hdc,
			static_cast<int>( objPos.x - image_.GetWidth( ) / 2.f ),
			static_cast<int>( objPos.y - image_.GetHeight( ) / 2.f ),
			image_.GetWidth( ), image_.GetHeight( ) );
	}

	void draw(HDC hdc, const PointFloat& objPos, int stat, int offset) {
		int originalWidth = image_.GetWidth();
		int originalHeight = image_.GetHeight();

		// 10ĭ���� ������ �� ĭ�� �� ���
		int segmentWidth = originalWidth / 10;

		// statlen�� 0 ���� �Ǵ� 10 �ʰ� �� ��� ó��
		int effectiveSegments = (stat <= 0) ? 1 : ((stat > 10) ? 10 : stat);
		int effectiveWidth = effectiveSegments * segmentWidth;
		if (effectiveWidth > originalWidth) effectiveWidth = originalWidth;

		// �ҽ� ����: ���ʿ��� effectiveSegments ĭ��ŭ�� �߶�
		int srcX = 0; // ���ʿ��� ����
		int srcWidth = effectiveWidth;
		int srcHeight = originalHeight;

		// ��� ũ��� ��ġ ���
		int drawX = static_cast<int>(objPos.x ) -15;
		int drawY = static_cast<int>(objPos.y - originalHeight / 2.f)+offset;

		// �̹��� �׸��� (�ҽ� ���� ����)
		image_.Draw(hdc, drawX, drawY, effectiveWidth, originalHeight,
			srcX, 0, srcWidth, srcHeight);
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

	HDC getDC( ) const {
		return image_.GetDC( );
	}

	void releaseDC( ) {
		image_.ReleaseDC( );
	}

private:
	CImage image_;
};

#endif	// __image_hpp