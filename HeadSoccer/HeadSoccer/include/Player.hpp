#include "Object.hpp"

class Player : public Object
{
public:
	int pnum_;
	void init();
	void move();
private:
	float speed;
};

