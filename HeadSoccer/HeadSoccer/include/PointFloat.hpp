#ifndef __pointfloat_hpp
#define __pointfloat_hpp

#include <Windows.h>
#include <cmath>
#include <cassert>

struct PointFloat {
	PointFloat( ) : x{ 0.f }, y{ 0.f } {}
	PointFloat( float x, float y ) : x{ x }, y{ y } {}
	PointFloat( const POINT& pt )
		: x{ static_cast<float>( pt.x ) },
		y{ static_cast<float>( pt.y ) } {}

	bool normalize( ) {
		auto hypotenuse = std::hypot( x, y );
		
		/*if ( hypotenuse == 0.f ) {
			return false;
		}*/
		assert( hypotenuse != 0.f );

		x /= hypotenuse;
		y /= hypotenuse;

		return true;
	}

	PointFloat& operator+( PointFloat rhs ) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	PointFloat& operator+( float rhs ) {
		x += rhs;
		y += rhs;
		return *this;
	}

	PointFloat& operator-( PointFloat rhs ) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	PointFloat& operator*( float rhs ) {
		x *= rhs;
		y *= rhs;
		return *this;
	}
	PointFloat& operator*( int rhs ) {
		x *= static_cast<float>( rhs );
		y *= static_cast<float>( rhs );
		return *this;
	}

	PointFloat& operator/( float rhs ) {
		assert( rhs != 0.f );
		x /= rhs;
		y /= rhs;
		return *this;
	}

	void operator-=( PointFloat rhs ) {
		x -= rhs.x;
		y -= rhs.y;
	}

	void operator+=( PointFloat rhs ) {
		x += rhs.x;
		y += rhs.y;
	}
	void operator+=( float rhs ) {
		x += rhs;
		y += rhs;
	}

	float x;
	float y;
};

#endif	// __pointfloat_hpp