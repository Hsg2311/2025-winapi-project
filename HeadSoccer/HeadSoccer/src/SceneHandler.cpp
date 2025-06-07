#include "../include/SceneHandler.hpp"
#include "../include/TitleScene.hpp"

void SceneHandler::init( ) {
	scenes_[ etoi( SceneType::Title ) ] = new TitleScene( "Title Scene" );

	assert( scenes_[ etoi( SceneType::Title ) ] != nullptr );

	currScene_ = scenes_[ etoi( SceneType::Title ) ];
	currScene_->entry( );
}

void SceneHandler::changeScene( SceneType type ) {
	currScene_->exit( );
	currScene_ = scenes_[ etoi( type ) ];
	currScene_->entry( );
}

std::array<Scene*, etoi( SceneType::EOE )> SceneHandler::scenes_;
Scene* SceneHandler::currScene_;
