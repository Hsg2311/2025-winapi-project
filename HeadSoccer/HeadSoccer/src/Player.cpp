#include "Player.hpp"
#include "Timer.hpp"
#include "InputHandler.hpp"

void Player::init1() {
    setName("p1");
    setPos(PointFloat(240.0f, 720.5f));
    setScale(PointFloat(20.0f, 50.0f));
    pnum_ = 1;
    speed = 300.0f;
    jumped = false;
}

void Player::init2() {
    setName("p2");
    setPos(PointFloat(1040.0f, 720.5f));
    setScale(PointFloat(20.0f, 50.0f));
    pnum_ = 2;
    speed = 300.0f;
    jumped = false;
}

void Player::render(HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush((255, 0, 0));
    HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc, static_cast<int>(pos_.x - scale_.x), static_cast<int>(pos_.y - scale_.y), static_cast<int>(pos_.x + scale_.x), static_cast<int>(pos_.y + scale_.y));
    SelectObject(hdc, oldbrush);
    DeleteObject(hBrush);
}

void Player::update() {
    float dt = Timer::fdt();

    float width = 1280.0f;
    float height = 720.5f;

    pos_.y += 1000.0f * dt;

    pos_.y += jspeed * dt;
    jspeed += 1000.0f * dt;

    if (pos_.y + scale_.y >= height) {
        pos_.y = height - scale_.y;
        jumped = false;
    }

    if (pnum_ == 1) {
        if (jumped == false && InputHandler::getKeyState(Key::W) == KeyState::Tap) {
            jspeed = -1500.0f; // 점프
            jumped = true;
        }
        if (InputHandler::getKeyState(Key::A) == KeyState::Tap ||
            InputHandler::getKeyState(Key::A) == KeyState::Hold) {
            pos_.x -= speed * dt; // 왼쪽
        }
        if (InputHandler::getKeyState(Key::D) == KeyState::Tap ||
            InputHandler::getKeyState(Key::D) == KeyState::Hold) {
            pos_.x += speed * dt; // 오른쪽
        }
    }

    if (pnum_ == 2) {
        if (jumped == false && InputHandler::getKeyState(Key::I) == KeyState::Tap) {
            jspeed = -1500.0f; //점프
            jumped = true;
        }
        if (InputHandler::getKeyState(Key::J) == KeyState::Tap ||
            InputHandler::getKeyState(Key::J) == KeyState::Hold) {
            pos_.x -= speed * dt; // 왼쪽
        }
        if (InputHandler::getKeyState(Key::L) == KeyState::Tap ||
            InputHandler::getKeyState(Key::L) == KeyState::Hold) {
            pos_.x += speed * dt; // 오른쪽
        }
    }

    if (pos_.x - scale_.x <= 0.0f) pos_.x = scale_.x;
    else if (pos_.x + scale_.x >= width) pos_.x = width - scale_.x;
}