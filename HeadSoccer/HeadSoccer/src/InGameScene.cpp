#include "../include/InGameScene.hpp"
#include "../include/Camera.hpp"
#include "../include/Background.hpp"
#include "../include/Button.hpp"
#include "../include/CharacterInfo.hpp"
#include "../include/Stopwatch.hpp"
#include "../include/Player.hpp"

extern StageNumber stageNum;
extern CharacterInfo player1;
extern CharacterInfo player2;

void InGameScene::entry( ) {
	Background* stageBg = nullptr;
	if ( stageNum == StageNumber::Stage1 ) {
		stageBg = new Background( "stage1_bg", "stage1.png", true );
	}
	else if ( stageNum == StageNumber::Stage2 ) {
		stageBg = new Background( "stage2_bg", "stage2.png", true );
	}
	else if ( stageNum == StageNumber::Stage3 ) {
		stageBg = new Background( "stage3_bg", "stage3.png", true );
	}
	else if ( stageNum == StageNumber::Stage4 ) {
		stageBg = new Background( "stage4_bg", "stage4.png", true );
	}

	assert( stageBg != nullptr );
	stageBg->setName( "stage_bg" );
	stageBg->setPos( PointFloat( 640.f, 360.f ) );
	addObject( ObjectType::Background, stageBg );

	auto timeUi = new Background( "time_ui", "time2.png", true );
	timeUi->setName( "time_ui" );
	timeUi->setPos( PointFloat( 640.f, 60.f ) );
	addObject( ObjectType::TimeUI, timeUi );

	auto stopwatch = new Stopwatch( PointFloat( 640.f, 80.f ), 120 );
	stopwatch->setName( "stopwatch" );
	addObject( ObjectType::TimeUI, stopwatch );

	auto pauseBtn = new Button( "pause_button", "pause_button", true );
	pauseBtn->setName( "pause_button" );
	pauseBtn->setPos( PointFloat( 1230.f, 40.f ) );
	addObject( ObjectType::Button, pauseBtn );

	auto p1ImageName = player1.getImage( );
	auto temp = std::string( );
	for ( auto c : p1ImageName ) {
		if ( c == '_' ) {
			break;
		}
		temp.push_back( c );
	}
	auto p1 = new Player( temp, player1.getSpeedStat(), player1.getKickStat(),
		player1.getJumpStat(), "left",1);
	p1->setName("player1");
	p1->setPos(PointFloat(300.f, 500.f));
	addObject(ObjectType::Player, p1);

	auto p1ImageName2 = player2.getImage();
	auto temp2 = std::string();
	for (auto c : p1ImageName2) {
		if (c == '_') {
			break;
		}
		temp2.push_back(c);
	}
	auto p2 = new Player(temp2, player2.getSpeedStat(), player2.getKickStat(),
		player2.getJumpStat(), "right",2);
	p2->setName("player2");
	p2->setPos(PointFloat(980.f, 500.f));
	addObject(ObjectType::Player, p2);

	// 임시 설정 값들 나중에 수정 필요

	auto player1Flag = new Background( "player1_flag", "k_flag_large.png", true );
	player1Flag->setName( "player1_flag" );
	player1Flag->setPos( PointFloat( 460.f, 60.f ) );
	addObject( ObjectType::InGameUI, player1Flag );

	auto player2Flag = new Background( "player2_flag", "k_flag_large.png", true );
	player2Flag->setName( "player2_flag" );
	player2Flag->setPos( PointFloat( 820.f, 60.f ) );
	addObject( ObjectType::InGameUI, player2Flag );

	auto zero = new Background( "zero", "goal_score_0.png", true );
	zero->setName( "zero" );
	zero->setPos( PointFloat( 460.f, 130.f ) );
	addObject( ObjectType::InGameUI, zero );

	auto nine = new Background( "nine", "goal_score_9.png", true );
	nine->setName( "nine" );
	nine->setPos( PointFloat( 820.f, 130.f ) );
	addObject( ObjectType::InGameUI, nine );

	auto p1Power = new Background( "player1_power", "power_left.png", true );
	p1Power->setName( "player1_power" );
	p1Power->setPos( PointFloat( 250.f, 60.f ) );
	addObject( ObjectType::InGameUI, p1Power );

	auto p2Power = new Background( "player2_power", "power_right.png", true );
	p2Power->setName( "player2_power" );
	p2Power->setPos( PointFloat( 1030.f, 60.f ) );
	addObject( ObjectType::InGameUI, p2Power );

	auto p1PowerGauge = new Background( "player1_power_gauge", "power_gauge_left.png", true );
	p1PowerGauge->setName( "player1_power_gauge" );
	p1PowerGauge->setPos( PointFloat( 250.f, 60.f ) );
	addObject( ObjectType::InGameUI, p1PowerGauge );

	auto p2PowerGauge = new Background( "player2_power_gauge", "power_gauge_right.png", true );
	p2PowerGauge->setName( "player2_power_gauge" );
	p2PowerGauge->setPos( PointFloat( 1030.f, 60.f ) );
	addObject( ObjectType::InGameUI, p2PowerGauge );

	auto p1FullPower = new Background( "player1_full_power", "full_power_left.png", true );
	p1FullPower->setName( "player1_full_power" );
	p1FullPower->setPos( PointFloat( 250.f, 63.f ) );
	addObject( ObjectType::InGameUI, p1FullPower );

	auto p2FullPower = new Background( "player2_full_power", "full_power_right.png", true );
	p2FullPower->setName( "player2_full_power" );
	p2FullPower->setPos( PointFloat( 1030.f, 63.f ) );
	addObject( ObjectType::InGameUI, p2FullPower );




	auto leftGoalPost = new Background( "goalpost_left", "goalpost_left.png", true );
	leftGoalPost->setName( "goalpost_left" );
	leftGoalPost->setPos( PointFloat( -20.f, 550.f ) );
	addObject( ObjectType::GoalPost, leftGoalPost );

	auto rightGoalPost = new Background( "goalpost_right", "goalpost_right.png", true );
	rightGoalPost->setName( "goalpost_right" );
	rightGoalPost->setPos( PointFloat( 1300.f, 550.f ) );
	addObject( ObjectType::GoalPost, rightGoalPost );
	
	Camera::getPos( ) = { 0.f, 0.f };
}

void InGameScene::exit( ) {
	Scene::destroyObjGroups( );
}
