#include "InputHandler.hpp"


class Button : public InputHandler {
public:
	Button(const std::vector<Key>& info)
		: UserInterface(info)
		, bMouseOn_(false)
		, bLbtnDown_(false) {
	}
	virtual ~ClickableUI() {}

	virtual void update() override;
	virtual void render(HDC hdc) override;

	bool mouseOnCheck();

	void mouseOn();
	void mouseLbtnDown();
	void mouseLbtnUp();
	void mouseLbtnClicked();

	virtual Button* clone() override {
		return new ClickableUI{ *this };
	}

private:
	bool bMouseOn_;
	bool bLbtnDown_;
};