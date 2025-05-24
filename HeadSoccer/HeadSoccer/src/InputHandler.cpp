#include "common.hpp"
#include "InputHandler.hpp"

#include <array>

auto arrVK = std::array<std::uint8_t, etoi( Key::EOE )>{ 
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,

	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',

	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE
};

void InputHandler::init( ) {
	inputInfo_.reserve( etoi( Key::EOE ) );
	for ( auto i = 0u; i < etoi( Key::EOE ); ++i ) {
		inputInfo_.emplace_back( KeyState::None, false );
	}
}

void InputHandler::update( ) {
	for ( auto i = 0u; i < etoi( Key::EOE ); ++i ) {
		if ( GetAsyncKeyState( arrVK[ i ] ) & 0x8000 ) {
			if ( inputInfo_[ i ].isPressed ) {
				inputInfo_[ i ].state = KeyState::Hold;
			}
			else {
				inputInfo_[ i ].state = KeyState::Tap;
			}
			inputInfo_[ i ].isPressed = true;
		}
		else {
			if ( inputInfo_[ i ].isPressed ) {
				inputInfo_[ i ].state = KeyState::Away;
			}
			else {
				inputInfo_[ i ].state = KeyState::None;
			}
			inputInfo_[ i ].isPressed = false;
		}
	}
}

std::vector<InputInfo> InputHandler::inputInfo_;
