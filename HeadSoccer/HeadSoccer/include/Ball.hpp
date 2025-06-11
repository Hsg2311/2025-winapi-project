#include "Object.hpp"
#include "PointFloat.hpp"
#include "ResourceHandler.hpp"
#include "Image.hpp"

#include "../include/Camera.hpp"

class Ball : public Object {
public:
    Ball(std::string name) {
        image = ResourceHandler::loadImage(name, "assets/ball.png", true);
        velo_.x = 1.0f;
        velo_.y = -100.0f;
    }
    PointFloat velo_; // ¼Óµµ 

    void update() override;
    void render(HDC hdc)override;
    void kickleft();
    void kickright();
private:
    Image* image;
};