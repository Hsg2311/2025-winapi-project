#include "../include/InGameScene.hpp"
#include "../include/Camera.hpp"
#include "../include/Background.hpp"
#include "../include/Button.hpp"
#include "../include/CharacterInfo.hpp"
#include "../include/Player.hpp"

extern StageNumber stageNum;
extern CharacterInfo player1;
extern CharacterInfo player2;


void InGameScene::entry( ) {
	Background* stageBg = nullptr;

	auto* p1=new Player(player1.getImage(), player1.getKickStat(), player1.getJumpStat(), player1.getSpeedStat(), 1);
	
	p1->setName("player 1");
	p1->setPos(PointFloat(240.f, 160.f));
	addObject(ObjectType::Player, p1);

	auto* p2 = new Player(player2.getImage(), player2.getKickStat(), player2.getJumpStat(), player2.getSpeedStat(), 2);
	p2->setName("player 2");
	p2->setPos(PointFloat(1080.f, 160.f));
	addObject(ObjectType::Player, p2);

	if ( stageNum == StageNumber::Stage1 ) {
		stageBg = new Background( "stage1_bg", "stage1.png", false );
	}
	else if ( stageNum == StageNumber::Stage2 ) {
		stageBg = new Background( "stage2_bg", "stage2.png", false );
	}
	else if ( stageNum == StageNumber::Stage3 ) {
		stageBg = new Background( "stage3_bg", "stage3.png", false );
	}
	else if ( stageNum == StageNumber::Stage4 ) {
		stageBg = new Background( "stage4_bg", "stage4.png", false );
	}

	assert( stageBg != nullptr );
	stageBg->setName( "stage_bg" );
	stageBg->setPos( PointFloat( 640.f, 360.f ) );
	addObject( ObjectType::Background, stageBg );

	auto timeUi = new Background( "time_ui", "time2.png", true );
	timeUi->setName( "time_ui" );
	timeUi->setPos( PointFloat( 640.f, 60.f ) );
	addObject( ObjectType::Background, timeUi );

	auto pauseBtn = new Button( "pause_button", "pause_button", true );
	pauseBtn->setName( "pause_button" );
	pauseBtn->setPos( PointFloat( 1230.f, 40.f ) );
	addObject( ObjectType::Button, pauseBtn );
	
	Camera::getPos( ) = { 0.f, 0.f };
}

void InGameScene::exit( ) {
	Scene::destroyObjGroups( );
}
