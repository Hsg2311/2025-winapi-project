#ifndef __common_hpp
#define __common_hpp

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

//namespace Gdiplus {
//	using std::min;
//	using std::max;
//}

#include "util.hpp"
#include "PointFloat.hpp"

#include <string>
#include <string_view>
#include <utility>

#include <vector>
#include <array>

enum class ObjectType {
	Background,
	Player,
	Ball,

	EOE
};

enum class SceneType {
	Title,

	EOE
};

#endif	// __common_hpp