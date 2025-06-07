#include "Object.hpp"

class Player : public Object
{
public:
	int pnum_;

	void init1();
	void init2();
	void update();

	void render(HDC hdc);

	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

private:
	float speed;
	float jspeed;
	bool jumped;
};

