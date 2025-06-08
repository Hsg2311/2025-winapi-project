#include "../include/CharacterScene.hpp"
#include "../include/Camera.hpp"

void CharacterScene::entry( ) {

	Camera::setPos( { 0.f, 0.f } );
}

void CharacterScene::exit( ) {
	Scene::destroyObjGroups( );
}

