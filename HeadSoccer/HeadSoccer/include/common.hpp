#ifndef __common_hpp
#define __common_hpp

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <algorithm>	// min, max �Լ��� ���� �߻����� ���� ���Խ�Ŵ

namespace Gdiplus {
	using std::min;
	using std::max;
}

#include "util.hpp"
#include "PointFloat.hpp"

#include <string>
#include <string_view>
#include <utility>
#include <cstdint>
#include <cassert>

#include <array>
#include <vector>
#include <map>

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

enum class EventType {
	CreateObject,
	DestroyObject,
	ChangeScene,

	EOE
};

#endif	// __common_hpp