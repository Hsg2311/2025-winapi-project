#include "Object.hpp"
#include <string>

class Player : public Object
{
public:
	Player()
		: Object(), speed(300.0f), jspeed(0.0f), ldtimer_(0.0f), rdtimer_(0.0f),
		dashdis(100.0f / 0.075f), dashtimer(0.0f), dashintime(0.0f),
		ldashed(false), rdashed(false), jumped(false) {
	}
	int pnum_;

	void update();


	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

	std::string country;
	int kickstat;
	int jumpstat;
	int spedstat;
private:
	float speed;
	float jspeed;
	float ldtimer_;
	float rdtimer_;
	float dashdis;
	float dashtimer;
	float dashintime;
	bool ldashed;
	bool rdashed;
	bool jumped;
};

