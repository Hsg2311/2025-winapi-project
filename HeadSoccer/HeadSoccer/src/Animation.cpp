#include "../include/Animation.hpp"
#include "../include/Timer.hpp"

void Animation::update( ) {
	accT_ += Timer::fdt( );
	while ( accT_ >= frames_[ currFrame_ ].duration ) {
		accT_ -= frames_[ currFrame_++ ].duration;
		currFrame_ %= frames_.size( );
	}
}

void Animation::render( HDC hdc, PointFloat objPos ) {
	auto sliceSize = frames_[ currFrame_ ].sliceSize;
	auto offset = frames_[ currFrame_ ].offset;
	auto lt = frames_[ currFrame_ ].lt;

	image_->draw( hdc,
		static_cast<int>( objPos.x - sliceSize.x / 2.f + offset.x ),
		static_cast<int>( objPos.y - sliceSize.y / 2.f + offset.y ),
		static_cast<int>( sliceSize.x ),
		static_cast<int>( sliceSize.y ),
		static_cast<int>( lt.x ),
		static_cast<int>( lt.y ),
		static_cast<int>( sliceSize.x ),
		static_cast<int>( sliceSize.y ) 
	);
}
