#include "Object.hpp"
#include "Image.hpp"
#include "ResourceHandler.hpp"
#include "CharacterInfo.hpp"
#include<iostream>

class Player : public Object
{
public:
	Player()
		: Object(), speed(300.0f), jspeed(0.0f), ldtimer_(0.0f), rdtimer_(0.0f),
		dashdis(100.0f / 0.075f), dashtimer(0.0f), dashintime(0.0f),
		ldashed(false), rdashed(false), jumped(false) {
	}
	Player(const std::string& imagename,const int ks,const int js, const int ss,int num) {
		std::string a = "asset/" + imagename + "_player.png";
		std::cout<<imagename<<std::endl;
		head = ResourceHandler::loadImage(imagename, a, true);
		if (!head) {
			std::cerr << "Failed to load image: " << imagename << std::endl;
		}
		jspeed = 0.0f;
		ldtimer_ = 0.0f;
		rdtimer_ = 0.0f;
		dashdis = 100.0f / 0.075f;
		dashtimer = 0.0f;
		dashintime = 0.0f;
		ldashed = false;
		rdashed = false;
		jumped = false;
		speed = ss * 50.0f;
		jumppower = -(js * 250.0f);
		kickpower = ks * 50.0f;
		pnum_ = num;
	}

	void update() override;

	void render(HDC hdc) override;

	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

	std::string country;

	void setpum(int p) {
		pnum_ = p;
	}


	int getkick() const {
		return kickstat;
	}
	int getjump() const {
		return jumpstat;
	}
	int getspeed() const {
		return speedstat;
	}

private:
	Image* head;
	int pnum_;
	int kickstat;
	int jumpstat;
	int speedstat;
	float kickpower;
	float speed;
	float jspeed;
	float ldtimer_;
	float jumppower;
	float rdtimer_;
	float dashdis;
	float dashtimer;
	float dashintime;
	bool ldashed;
	bool rdashed;
	bool jumped;
};

