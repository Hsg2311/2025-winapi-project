#include "Object.hpp"

class Button : public Object {
public:
	virtual ~Button() {}

	virtual void update() override;
	virtual void render(HDC hdc) override;

	bool mouseOnCheck();

	void mouseOn();
	void mouseLbtnUp();
	void mouseLbtnClicked();

private:
	bool bMouseOn_;
	bool bLbtnDown_;
};