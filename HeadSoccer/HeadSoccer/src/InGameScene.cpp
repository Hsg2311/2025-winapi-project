#include "../include/InGameScene.hpp"
#include "../include/Camera.hpp"
#include "../include/Background.hpp"
#include "../include/Button.hpp"

extern StageNumber stageNum;

void InGameScene::entry( ) {
	Background* stageBg = nullptr;
	if ( stageNum == StageNumber::Stage1 ) {
		stageBg = new Background( "stage1_bg", "stage1.png" );
	}
	else if ( stageNum == StageNumber::Stage2 ) {
		stageBg = new Background( "stage2_bg", "stage2.png" );
	}
	else if ( stageNum == StageNumber::Stage3 ) {
		stageBg = new Background( "stage3_bg", "stage3.png" );
	}
	else if ( stageNum == StageNumber::Stage4 ) {
		stageBg = new Background( "stage4_bg", "stage4.png" );
	}

	assert( stageBg != nullptr );
	stageBg->setName( "stage_bg" );
	stageBg->setPos( PointFloat( 640.f, 360.f ) );
	addObject( ObjectType::Background, stageBg );

	auto timeUi = new Background( "time_ui", "time2.png" );
	timeUi->setName( "time_ui" );
	timeUi->setPos( PointFloat( 640.f, 60.f ) );
	addObject( ObjectType::Background, timeUi );

	auto pauseBtn = new Button( "pause_button", "pause_button" );
	pauseBtn->setName( "pause_button" );
	pauseBtn->setPos( PointFloat( 1230.f, 40.f ) );
	addObject( ObjectType::Button, pauseBtn );
	
	Camera::getPos( ) = { 0.f, 0.f };
}

void InGameScene::exit( ) {
	Scene::destroyObjGroups( );
}
