#include "Object.hpp"

class Player : public Object
{
public:
	int pnum_;

	void init();
	void move();

	void pspeed() {
		speed += 0.1f;
	}

	void pspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

private:
	float speed;
};

