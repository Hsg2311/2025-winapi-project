#ifndef __input_handler_hpp
#define __input_handler_hpp

#include "util.hpp"

#include <vector>

enum class KeyState : std::uint8_t {
	Tap,
	Hold,
	Away,
	None
};

enum class Key : std::uint8_t {
	Up,
	Down,
	Left,
	Right,

	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,

	Alt,
	Ctrl,
	LShift,
	Space,
	Enter,
	Esc,

	EOE
};

struct InputInfo {
	KeyState state;
	bool isPressed;
};

class InputHandler {
public:
	static void init( );
	static void update( );

	static KeyState getKeyState( Key key ) {
		return inputInfo_[ etoi( key ) ].state;
	}

private:
	static std::vector<InputInfo> inputInfo_;
};

#endif	// __input_handler_hpp