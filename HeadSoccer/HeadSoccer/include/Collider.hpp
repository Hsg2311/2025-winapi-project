#ifndef __collider_hpp
#define __collider_hpp

#include "common.hpp"

class Collider {
public:
	Collider( PointFloat offset, PointFloat scale )
		: offset_( offset ), finalPos_( ), scale_( scale ),
		id_( nextId_++ ), collCnt_{ } {}

	// need to implement a copy constructor and a move constructor

	Collider& operator=( const Collider& ) = delete;
	Collider& operator=( Collider&& ) = delete;

	void update( PointFloat objPos ) {
		finalPos_ = objPos + offset_;
	}

	void render( HDC hdc ) const {
		auto pen = CreatePen( PS_SOLID, 1, RGB( 0, 255, 0 ) );
		if ( collCnt_ > 0 ) {
			pen = CreatePen( PS_SOLID, 1, RGB( 255, 0, 0 ) );
		}

		auto brush = (HBRUSH)GetStockObject( HOLLOW_BRUSH );

		auto oldPen = (HPEN)SelectObject( hdc, pen );
		auto oldBrush = (HBRUSH)SelectObject( hdc, brush );

		Rectangle( hdc,
			static_cast<int>( finalPos_.x - scale_.x / 2.f ),
			static_cast<int>( finalPos_.y - scale_.y / 2.f ),
			static_cast<int>( finalPos_.x + scale_.x / 2.f ),
			static_cast<int>( finalPos_.y + scale_.y / 2.f )
		);

		SelectObject( hdc, oldPen );
		SelectObject( hdc, oldBrush );
	}

private:
	PointFloat offset_;
	PointFloat finalPos_;
	PointFloat scale_;
	std::uint16_t id_;
	std::int32_t collCnt_;

	static std::uint16_t nextId_;
};

#endif	// __collider_hpp