#ifndef __animator_hpp
#define __animator_hpp

#include "common.hpp"
#include "Animation.hpp"

class Animator {
public:
	Animator( const std::string& name, Image* image,
		PointFloat lt, PointFloat sliceSize, PointFloat step,
		std::uint8_t frameCnt, float duration, PointFloat offset = { 0.0f, 0.0f } )
		: anims_( ), currAnim_( nullptr )
	{
		auto anim = find( name );
		assert( anim == nullptr );

		anims_[ name ] = new Animation( name, image, lt, sliceSize, step, frameCnt, duration, offset );
	}

	~Animator( ) {
		for ( auto [null, anim] : anims_ ) {
			delete anim;
		}
		anims_.clear( );
	}

	Animation* find( const std::string& name );
	void play( const std::string& name );

	void update( ) {
		currAnim_->update( );
	}

	void render( HDC hdc, PointFloat objPos ) {
		currAnim_->render( hdc, objPos );
	}

private:
	std::map<std::string, Animation*> anims_;
	Animation* currAnim_;
};

#endif	// __animator_hpp