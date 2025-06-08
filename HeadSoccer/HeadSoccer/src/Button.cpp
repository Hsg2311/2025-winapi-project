#include "../include/Button.hpp"
#include "../include/PointFloat.hpp"
#include "../include/ResourceHandler.hpp"
#include "../include/EventHandler.hpp"
#include "../include/InputHandler.hpp"
#include "../include/Camera.hpp"

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
	if ( getName( ) == "arcade_btn" ) {
		EventHandler::addEvent(
			Event{
				.type = EventType::ChangeScene,
				.wParam = static_cast<DWORD_PTR>( SceneType::SelectCharacter )
			}
		);
	}
}