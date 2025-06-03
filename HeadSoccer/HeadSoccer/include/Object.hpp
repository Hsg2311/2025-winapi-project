#ifndef __object_hpp
#define __object_hpp

#include "common.hpp"

class Object {
public:
	Object( );
	Object( const std::string& name, const PointFloat& pos, const PointFloat& scale );

	Object( const Object& other );
	Object& operator=( const Object& other ) = delete;

	Object( Object&& other ) noexcept;
	Object& operator=( Object&& other ) = delete;

	virtual ~Object( ) = 0 {
		
	}

	virtual void update( ) { }
	virtual void render( HDC hdc ) { }

	virtual void onCollision( Object* other ) { }
	virtual void onCollisionEntry( Object* other ) { }
	virtual void onCollisionExit( Object* other ) { }

	void setName( const std::string& name ) {
		name_ = name;
	}
	void setPos( const PointFloat& pos ) {
		pos_ = pos;
	}
	void setScale( const PointFloat& scale ) {
		scale_ = scale;
	}
	void setAlive( bool alive ) {
		alive_ = alive;
	}

	const std::string& getName( ) const {
		return name_;
	}
	const PointFloat& getPos( ) const {
		return pos_;
	}
	const PointFloat& getScale( ) const {
		return scale_;
	}
	bool isAlive( ) const {
		return alive_;
	}

private:
	std::string name_;

protected:
	PointFloat pos_;
	PointFloat scale_;

private:
	bool alive_;
};

#endif	// __object_hpp