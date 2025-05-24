#include "common.hpp"
#include <string>
#include "PointFloat.hpp"

class Object
{
public:
	Object();

	Object(const std::string& name, const PointFloat& pos, const PointFloat& scale);

	Object(const Object& other);
	Object& operator=(const Object& other) = delete;

	Object(Object&& other) noexcept;
	Object& operator=(Object&& other) = delete;

	virtual ~Object() = 0 {

	}

	void update();
	void render(HDC hdc);

	void setNmae(const std::string& name) {
		name_ = name;
	}

	void setPos(const PointFloat& pos) {
		pos_ = pos;
	}

	void setScale(const PointFloat& scale) {
		scale_ = scale;
	}

	const std::string& getName() const {
		return name_;
	}

	const PointFloat& getPos() const {
		return pos_;
	}

	const PointFloat& getScale() const {
		return scale_;
	}

private:
	std::string name_;
	PointFloat pos_;
	PointFloat scale_;
};

