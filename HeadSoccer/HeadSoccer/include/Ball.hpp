#include "Object.hpp"
#include "PointFloat.hpp"

class Ball : public Object {
public:
    PointFloat velo_; // �ӵ� 

    void update();
    void init();
	void render(HDC hdc);
    void kickleft();
    void kickright();
};