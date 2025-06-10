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
	Player(const std::string& name, int ss, int js, int ks, const std::string& lr,int num) {
		auto filePath = fs::path( "assets/" + name + "_player_" + lr + ".png" );
		auto keyVal = name + "_player_" + lr;
		image_ = ResourceHandler::loadImage( keyVal, fs::canonical( filePath ).string( ), true );
		
		kickpower = ks * 50.f;
		jumppower = -(js * 250.f);
		speed = ss * 50.f;
		jspeed = 0.0f;
		ldtimer_ = 0.0f;
		rdtimer_ = 0.0f;
		dashdis = 100.0f / 0.075f;
		dashtimer = 0.0f;
		dashintime = 0.0f;

		/*createAnimator( );
		auto str = std::string( "player_idle_" + lr );
		auto animFilePath = fs::path( "assets/" + str + ".png" );
		auto animImage = ResourceHandler::loadImage( str, fs::canonical( animFilePath ).string( ), true );
		getAnimator( )->createAnimation( str, animImage, PointFloat( 0.f, 0.f ),
			PointFloat( 93.f, 33.f ), PointFloat( 93.f, 0.f ), 6, 0.065f, PointFloat( 0.f, 53.f ) );
		getAnimator( )->play( str );*/

		createAnimator( );
		auto str = std::string( "player_run_" + lr );
		auto animFilePath = fs::path( "assets/" + str + ".png" );
		auto animImage = ResourceHandler::loadImage( str, fs::canonical( animFilePath ).string( ), true );
		getAnimator( )->createAnimation( str, animImage, PointFloat( 522.5f, 0.f ),
			PointFloat( 104.5f, 30.f ), PointFloat( -104.5f, 0.f ), 6, 0.07f, PointFloat( 0.f, 53.f ) );
		getAnimator( )->play( str );
		
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

