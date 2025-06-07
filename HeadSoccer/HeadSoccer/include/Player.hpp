#include "Object.hpp"

class Player : public Object
{
public:
	int pnum_;

	void init();
	void move();



	void ispeed() {
		speed += 0.1f;
	}

	void dspeed() {
		if (speed > 0.1f) speed -= 0.1f;
	}

private:
	float speed;
};

