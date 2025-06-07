#ifndef __collider_hpp
#define __collider_hpp

#include "common.hpp"

class Collider {
public:
	Collider( )
		: offset_( ), finalPos_( ), scale_( )
		, id_{ nextId_++ }, collCnt_{ 0 } {}

	// need to implement a copy constructor and a move constructor

	Collider& operator=( const Collider& ) = delete;
	Collider& operator=( Collider&& ) = delete;

	void update( PointFloat objPos ) {
		finalPos_ = objPos + offset_;
	}

	void render( HDC hdc ) const;

	void setOffset( PointFloat offset ) {
		offset_ = offset;
	}
	void setScale( PointFloat scale ) {
		scale_ = scale;
	}

	PointFloat getOffset( ) const {
		return offset_;
	}
	PointFloat getScale( ) const {
		return scale_;
	}
	PointFloat getFinalPos( ) const {
		return finalPos_;
	}
	std::uint16_t id( ) const {
		return id_;
	}

	void addCollCnt( ) {
		++collCnt_;
	}
	void subCollCnt( ) {
		--collCnt_;
		assert( collCnt_ >= 0 );
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