#ifndef __scene_hpp
#define __scene_hpp

#include "common.hpp"
#include "Object.hpp"

class Scene {
public:
	Scene( ) : name_( ), objGroups_( ) {}
	Scene( std::string_view name ) : name_( name ), objGroups_( ) {}

	Scene( const Scene& ) = delete;
	Scene& operator=( const Scene& ) = delete;
	Scene( Scene&& ) = delete;
	Scene& operator=( Scene&& ) = delete;

	virtual ~Scene( ) = 0 {
		for ( auto& group : objGroups_ ) {
			for ( auto obj : group ) {
				delete obj;
			}
		}
	}

	void update( ) {
		for ( auto& group : objGroups_ ) {
			for ( auto obj : group ) {
				if ( obj->isAlive( ) ) {
					obj->update( );
				}
			}
		}
	}

	void render( HDC hdc ) {
		for ( auto& group : objGroups_ ) {
			for ( auto iter = group.begin( ); iter != group.end( ); ) {
				if ( ( *iter )->isAlive( ) ) {
					( *iter )->render( hdc );
					++iter;
				}
				else {
					iter = group.erase( iter );
				}
			}
		}
	}

	virtual void entry( ) = 0;
	virtual void exit( ) = 0;

	void addObject( ObjectType type, Object* obj ) {
		objGroups_[ etoi( type ) ].push_back( obj );
	}

	const std::vector<Object*>& getGroup( ObjectType type ) {
		return objGroups_[ etoi( type ) ];
	}

private:
	std::string name_;
	std::array< std::vector<Object*>, etoi( ObjectType::EOE ) > objGroups_;
};

#endif	// __scene_hpp