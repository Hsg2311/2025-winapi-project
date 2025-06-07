#include "../include/Game.hpp"
#include "../include/TitleScene.hpp"
#include "../include/Background.hpp"
#include "../include/Camera.hpp"

void TitleScene::entry( ) {
	auto bg = new Background( "title_bg", "title_bg.png" );

	auto clientWidth = Game::getRsl( ).x;
	auto clientHeight = Game::getRsl( ).y;
	bg->setPos( PointFloat( clientWidth / 2.f, clientHeight / 2.f ) );
	addObject( ObjectType::Background, bg );

	Camera::setPos( { 0.f, 0.f } );
}

void TitleScene::exit( ) {
}
