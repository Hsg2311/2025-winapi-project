#include "Object.hpp"
#include <string>
#include "Resourcehandler.hpp"

class Player : public Object
{
public:
	Player(const std::string& name, int ss, int ks, int js, const std::string& lr,int num) {
		auto filePath = fs::path( "assets/" + name + "_player_" + lr + ".png" );
		auto keyVal = name + "_player_" + lr;
		image_ = ResourceHandler::loadImage(keyVal, fs::canonical(filePath).string(), true);
		
		kickpower = ks * 50.f;
		jumppower =  -( 1250.f + (40.f*js));
		speed = ss * 50.f;
		jspeed = 0.0f;
		ldtimer_ = 0.0f;
		rdtimer_ = 0.0f;
		dashdis = 100.0f / 0.075f;
		dashtimer = 0.0f;
		dashintime = 0.0f;
		pnum_ = num;
	}

	void update()override;
	void render(HDC hdc)override;


	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

private:
	Image* image_;
	std::string flag_;
	std::string leftorright_;
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

