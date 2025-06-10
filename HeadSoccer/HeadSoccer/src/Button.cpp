#include "../include/Button.hpp"
#include "../include/PointFloat.hpp"
#include "../include/ResourceHandler.hpp"
#include "../include/EventHandler.hpp"
#include "../include/InputHandler.hpp"
#include "../include/Camera.hpp"
#include "../include/SceneHandler.hpp"
#include "../include/CharacterInfo.hpp"

extern CharacterInfo player1;
extern CharacterInfo player2;

Button::Button( const std::string& key, const std::string& fileName )
	: bMouseOn_{ false }, bLbtnDown_{ false }
{
	auto offBtnFilePath = fs::path( "assets/" + fileName + "_off.png" );
	auto onBtnFilePath = fs::path( "assets/" + fileName + "_on.png" );
	imageOff_ = ResourceHandler::loadImage( key + "_off", fs::canonical( offBtnFilePath ).string( ) );
	imageOn_ = ResourceHandler::loadImage( key + "_on", fs::canonical( onBtnFilePath ).string( ) );
}

void Button::update( ) {
	auto bLbtnTap = InputHandler::getKeyState( Key::MouseLbtn ) == KeyState::Tap;
	auto bLbtnAway = InputHandler::getKeyState( Key::MouseLbtn ) == KeyState::Away;

	if ( mouseOnCheck( ) ) {
		if ( bLbtnTap ) {
			bLbtnDown_ = true;
		}
		else if ( bLbtnAway ) {
			if ( bLbtnDown_ ) {
				mouseLbtnClicked( );
			}
			bLbtnDown_ = false;
		}
	}
	else {
		if ( bLbtnAway ) {
			bLbtnDown_ = false;
		}
	}

	componentUpdate( );
}

void Button::render( HDC hdc ) {
	auto relativePos = pos_ - Camera::getPos( );

	if ( bMouseOn_ ) {
		imageOn_->draw( hdc, relativePos );
	}
	else {
		imageOff_->draw( hdc, relativePos );
	}

	componentRender( hdc );
}

bool Button::mouseOnCheck( ) {
	auto mousePos = InputHandler::getMousePos( );

	auto objPos = getPos( );
	auto objScale = PointFloat( 
		static_cast<float>( imageOff_->width( ) ),
		static_cast<float>( imageOff_->height( ) )
	);

	if ( mousePos.x >= objPos.x - objScale.x / 2.f && mousePos.x <= objPos.x + objScale.x / 2.f
		&& mousePos.y >= objPos.y - objScale.y / 2.f && mousePos.y <= objPos.y + objScale.y / 2.f ) {
		bMouseOn_ = true;
		return true;
	}
	else {
		bMouseOn_ = false;
		return false;
	}
}

void Button::mouseLbtnClicked( ) {
	auto name = getName( );

	if ( name == "arcade_btn" ) {
		EventHandler::addEvent(
			Event{
				.type = EventType::ChangeScene,
				.wParam = static_cast<DWORD_PTR>( SceneType::SelectCharacter )
			}
		);
	}
	else if ( name == "back_button" ) {
		EventHandler::addEvent(
			Event{
				.type = EventType::ChangeScene,
				.wParam = static_cast<DWORD_PTR>( SceneType::Title )
			}
		);
	}
	else if ( name == "next_button" ) {
		EventHandler::addEvent(
			Event{
				.type = EventType::ChangeScene,
				.wParam = static_cast<DWORD_PTR>( SceneType::SelectStage )
			}
		);
	}
	else if ( name == "play_button" ) {
		EventHandler::addEvent(
			Event{
				.type = EventType::ChangeScene,
				.wParam = static_cast<DWORD_PTR>( SceneType::InGame )
			}
		);
	}
	else if (name == "left_up_button") {
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 왼쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("character"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 왼쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("flag"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 왼쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("stat"))
			}
		);
	}
	else if (name == "right_up_button") {
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 오른쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("character_right"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 오른쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("flag_right"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (1), // 오른쪽 캐릭터 인덱스 증가
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("stat_right"))
			}
		);
	}
	else if (name == "left_down_button") {
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (- 1), // 왼쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("character"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (-1), // 왼쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("flag"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (-1), // 왼쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("stat"))
			}
		);
	}
	else if (name == "right_down_button") {
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (-1), // 오른쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("character_right"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (-1), // 오른쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("flag_right"))
			}
		);
		EventHandler::addEvent(
			Event{
				.type = EventType::UpdateIndex,
				.wParam = static_cast<DWORD_PTR> (-1), // 오른쪽 캐릭터 인덱스 감소
				.lParam = reinterpret_cast<DWORD_PTR>(SceneHandler::getCurrScene()->getObjectByName("stat_right"))
			}
		);
	}
}