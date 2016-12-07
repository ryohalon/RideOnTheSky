#pragma once
#include "cinder/app/KeyEvent.h"
#include <set>
#include <memory>



#define KEY Key::Get()


class Key
{
private:

	struct KeyStatus;

	std::unique_ptr<KeyStatus> key_status;

public:

	Key();
	~Key();

	static Key& Get()
	{
		static Key key;

		return key;
	}

	void PushKey(const ci::app::KeyEvent& key_event);
	void PullKey(const ci::app::KeyEvent& key_event);

	void FlushInput();

	const bool& IsPushKey(const int &key);
	const bool& IsPressKey(const int &key);
	const bool& IsPullKey(const int &key);
};