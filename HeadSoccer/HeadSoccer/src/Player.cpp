#include "Player.hpp"
#include "Timer.hpp"
#include "InputHandler.hpp"

void Player::move() {
    float dt = Timer::fdt();

    if (pnum_ == 1) {
        if (InputHandler::getKeyState(Key::W) == KeyState::Tap ||
            InputHandler::getKeyState(Key::W) == KeyState::Hold) {
            pos_.y -= speed * dt; // 점프
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
    else if (pnum_ == 2) {
        if (InputHandler::getKeyState(Key::I) == KeyState::Tap ||
            InputHandler::getKeyState(Key::I) == KeyState::Hold) {
            pos_.y -= speed * dt; // 점프
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
}