#ifndef __map_scene_hpp
#define __map_scene_hpp

#include "Scene.hpp"

class MapScene : public Scene {
public:
	MapScene( ) {}
	MapScene( std::string_view sceneName )
		: Scene( sceneName ) {
	}

	virtual ~MapScene( ) { }

	void entry( ) override;
	void exit( ) override;
};

#endif  // __map_scene_hpp