#include "../include/Ball.hpp"
#include "../include/Timer.hpp"
#include "../include/Camera.hpp"

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
    auto relativePos = pos_ - Camera::getPos();
    if (image) {
        image->draw(hdc, relativePos);
    }
    componentRender(hdc);
}

void Ball::update() {
    float dt = Timer::fdt();
    static float timer = 0;
    timer += dt;
    if (timer >= 1.0f) { // �¿� �ӵ� ����
        velo_.x = velo_.x * 0.7;
        timer = 0.0f;
    }
    velo_.y += 1000.0f * dt; // �߷�
    pos_ += velo_ * dt;

    float fieldWidth = 1280.0f;
    float fieldHeight = 615.5f;

    if (pos_.x - scale_.x <= 0.0f) { // �޺�
        velo_.x = -velo_.x;
        pos_.x = 0.0f + scale_.x;
    }
    else if (pos_.x + scale_.x >= fieldWidth) { // ������
        velo_.x = -velo_.x;
        pos_.x = fieldWidth - scale_.x;
    }

    if (pos_.y - scale_.y <= 10.0f) { // õ�� �浹
        velo_.y = -velo_.y;
        pos_.y = 20.0f + scale_.y;
    }
    else if (pos_.y + scale_.y >= fieldHeight) { //���� �浹
        velo_.y = -velo_.y * 0.8f;
        pos_.y = fieldHeight - scale_.y;
    }
}