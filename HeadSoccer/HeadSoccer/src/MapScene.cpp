#include "../include/MapScene.hpp"
#include "../include/Camera.hpp"

void MapScene::entry( ) {


	Camera::setPos( { 0.f, 0.f } );
}

void MapScene::exit( ) {
	Scene::destroyObjGroups( );
}
