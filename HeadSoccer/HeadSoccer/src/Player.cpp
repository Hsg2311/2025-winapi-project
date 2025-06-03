#include "Player.hpp"
#include "Timer.hpp"
#include "InputHandler.hpp"

void Player::move() {
    float dt = Timer::fdt();
    const auto& inputInfo = InputHandler::getInputInfo();

    float dx = 0.0f, dy = 0.0f;

    if (inputInfo[etoi(Key::Up)].state == KeyState::Tap ||
        inputInfo[etoi(Key::Up)].state == KeyState::Hold) {
        dy -= speed; // 위로 이동
    }
    if (inputInfo[etoi(Key::Down)].state == KeyState::Tap ||
        inputInfo[etoi(Key::Down)].state == KeyState::Hold) {
        dy += speed; // 아래로 이동
    }
    if (inputInfo[etoi(Key::Left)].state == KeyState::Tap ||
        inputInfo[etoi(Key::Left)].state == KeyState::Hold) {
        dx -= speed; // 왼쪽으로 이동
    }
    if (inputInfo[etoi(Key::Right)].state == KeyState::Tap ||
        inputInfo[etoi(Key::Right)].state == KeyState::Hold) {
        dx += speed; // 오른쪽으로 이동
    }

    if (dx != 0.0f || dy != 0.0f) {
        float length = std::sqrt(dx * dx + dy * dy);
        if (length > 0) {
            dx = dx / length * speed * dt;
            dy = dy / length * speed * dt;
            pos_.x += dx;
            pos_.y += dy;
        }
    }
}