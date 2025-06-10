#include "Object.hpp"
#include <string>
#include "Resourcehandler.hpp"

class Player : public Object
{
public:
	Player()
		: Object(), speed(300.0f), jspeed(0.0f), ldtimer_(0.0f), rdtimer_(0.0f),
		dashdis(100.0f / 0.075f), dashtimer(0.0f), dashintime(0.0f),
		ldashed(false), rdashed(false), jumped(false) {
	}
	Player(const std::string& name, int speed, int jump, int kick, const std::string& lr) {
		image_ = ResourceHandler::loadImage(name, name + "_player_" + lr + ".png", true);
		
		kickpower = kick*50.f;
		jumppower = -(jump * 250.f);
		speed = speed * 50.f;
		jspeed = 0.0f;
		ldtimer_ = 0.0f;
		rdtimer_ = 0.0f;
		dashdis = 100.0f / 0.075f;
		dashtimer = 0.0f;
		dashintime = 0.0f;
	}

	void update()override;
	void render(HDC hdc)override;


	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

	std::string country;
private:
	Image* image_;
	std::string flag_;
	float kickpower;
	float jumppower;
	int pnum_;
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

