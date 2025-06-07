#include "../include/Animator.hpp"

Animation* Animator::find( const std::string& name ) {
	auto anim = anims_.find( name );

	if ( anim == anims_.end( ) ) {
		return nullptr;
	}

	assert( anim->second != nullptr );
	return anim->second;
}

void Animator::play( const std::string& name ) {
	currAnim_ = find( name );
	assert( currAnim_ != nullptr );
}
