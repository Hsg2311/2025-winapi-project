#include "Button.hpp"
#include "EventHandler.hpp"
#include "InputHandler.hpp"
#include "PointFloat.hpp"
#include "resource.h"

void Button::update() {
	auto mousel = Key::MouseLbtn;

	if (mouseOnCheck()) {

		if (InputHandler::getKeyState(mousel)==KeyState::Tap) {
			bLbtnDown_ = true;
		}
		else if (InputHandler::getKeyState(mousel) == KeyState::Away) {

			if (bLbtnDown_) {
				mouseLbtnClicked();
			}
			bLbtnDown_ = false;
		}
	}
	else {
		if (InputHandler::getKeyState(mousel) == KeyState::Away) {
			bLbtnDown_ = false;
		}
	}
}

void Button::render(HDC hdc) {
	auto imageWidth = currTex_->getWidth();
	auto imageHeight = currTex_->getHeight();

	auto xDest = static_cast<int>(getPos().x - imageWidth / 2.f);
	auto yDest = static_cast<int>(getPos().y - imageHeight / 2.f);

	if (bMouseOn_) {
		currTex_->draw(hdc, xDest, yDest, imageWidth, imageHeight,
			0, 0, imageWidth, imageHeight, 255);
	}
	else {
		currTex_->draw(hdc, xDest, yDest, imageWidth, imageHeight,
			0, 0, imageWidth, imageHeight, 100);
	}

	componentRender(hdc);
}

bool Button::mouseOnCheck() {
	auto mousePos = InputHandler::getMousePos();
	auto objPos = getPos();
	auto objScale = getScale();

	if (mousePos.x >= objPos.x - objScale.x / 2.f && mousePos.x <= objPos.x + objScale.x / 2.f
		&& mousePos.y >= objPos.y - objScale.y / 2.f && mousePos.y <= objPos.y + objScale.y / 2.f) {
		bMouseOn_ = true;
		return true;
	}
	else {
		bMouseOn_ = false;
		return false;
	}
}

void Button::mouseOn() {
}

void Button::mouseLbtnUp() {
}

void Button::mouseLbtnClicked() {
	if (getName() == "Play Button") {

	}
	else if (getName() == "Start Button") {

	}
	else if (getName() == "Exit Button") {
		PostQuitMessage(0);
	}
}