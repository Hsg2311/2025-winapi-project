#include "../include/SceneHandler.hpp"
#include "../include/TitleScene.hpp"
#include "../include/CharacterScene.hpp"

void SceneHandler::init( ) {
	scenes_[ etoi( SceneType::Title ) ] = new TitleScene( "Title Scene" );
	scenes_[ etoi( SceneType::SelectCharacter ) ] = new CharacterScene( "Select Character Scene" );

	assert( scenes_[ etoi( SceneType::Title ) ] != nullptr );
	assert( scenes_[ etoi( SceneType::SelectCharacter ) ] != nullptr );

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
