#include "Ball.hpp"
#include "Timer.hpp"

void Ball::init() {
    setName("Ball");
    setPos(PointFloat(640.0f, 360.0f));
    setScale(PointFloat(20.0f, 20.0f));
    velo_.x = 1.0f;
    velo_.y = -100.0f;
}

void Ball::kickleft() {
    if (velo_.x <= 0)velo_.x += -500.0f;
    else  velo_.x = -velo_.x - 500.0f;
    if (velo_.y <= 0)velo_.y += -100.0f;
    else velo_.y = -velo_.y - 100.0f;
}   

void Ball::kickright() {
    if (velo_.x >= 0)velo_.x += 500.0f;
    else velo_.x = -velo_.x + 500.0f;
    if (velo_.y <= 0)velo_.y += -100.0f;
    else velo_.y = -velo_.y - 100.0f;
}

void Ball::render(HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush((255,0,0));
    HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, hBrush);
    Ellipse(hdc, static_cast<int>(pos_.x-scale_.x), static_cast<int>(pos_.y - scale_.y), static_cast<int>(pos_.x + scale_.x), static_cast<int>(pos_.y + scale_.y));
    SelectObject(hdc, oldbrush);
    DeleteObject(hBrush);
}

void Ball::update() {
    float dt = Timer::fdt();
    static float timer = 0;
    timer += dt;    
    if (timer >= 1.0f) { // 좌우 속도 감소
        kickleft();
        velo_.x = velo_.x * 0.7;
        timer = 0.0f;
    }
    velo_.y += 1000.0f * dt; // 중력
    pos_ += velo_ * dt;

    float fieldWidth = 1280.0f;
    float fieldHeight = 720.5f;

    if (pos_.x - scale_.x <= 0.0f) { // 왼벽
        velo_.x = -velo_.x; 
        pos_.x = 0.0f + scale_.x; 
    }
    else if (pos_.x + scale_.x >= fieldWidth) { // 오른벽
        velo_.x = -velo_.x; 
        pos_.x = fieldWidth - scale_.x; 
    }

    if (pos_.y - scale_.y <= 10.0f) { // 천장 충돌
        velo_.y = -velo_.y ;
        pos_.y = 20.0f + scale_.y;
    }
    else if (pos_.y + scale_.y >= fieldHeight) { //지면 충돌
        velo_.y = -velo_.y * 0.8f;
        pos_.y = fieldHeight - scale_.y;
    }
}