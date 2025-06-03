#include "../include/Object.hpp"

Object::Object( )
	: name_( ), pos_( ),
	scale_( ), alive_{ true } {}

Object::Object( const std::string& name, const PointFloat& pos, const PointFloat& scale )
	: name_( name ), pos_( pos ),
	scale_( scale ), alive_{ true } {}

Object::Object( const Object& other )
	: name_( other.name_ ), pos_( other.pos_ ),
	scale_( other.scale_ ),	alive_{ true } {}

Object::Object( Object&& other ) noexcept
	: name_( std::move( other.name_ ) ),
	pos_( std::move( other.pos_ ) ),
	scale_( std::move( other.scale_ ) ),
	alive_{ std::exchange( other.alive_, false ) } {}
