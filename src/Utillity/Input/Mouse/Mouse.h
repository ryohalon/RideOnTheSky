#pragma once
#include "cinder/app/MouseEvent.h"
#include <set>
#include <memory>

#define MOUSE Mouse::Get()


class Mouse
{
private:

	struct MouseStatus;

	std::unique_ptr<MouseStatus> mouse_status;

public:

	Mouse();
	~Mouse();

	static Mouse& Get()
	{
		static Mouse mouse;

		return mouse;
	}

	//マウスの座標の取得
	ci::Vec2i GetMousePosition();
	float GetMouseWheelValue();

	//入力情報の削除
	void FlushInput();

	void UpdateMousePosition(const ci::app::MouseEvent& mouse_event);
	void UpdateMouseWheelValue(const ci::app::MouseEvent& mouse_event);
	void PushButton(const ci::app::MouseEvent& mouse_event);
	void PullButton(const ci::app::MouseEvent& mouse_event);

	bool IsPushButton();
	bool IsPushButton(const int &button);
	bool IsPressButton();
	bool IsPressButton(const int &button);
	bool IsPullButton();
	bool IsPullButton(const int &button);
};