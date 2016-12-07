#include "Key.h"


struct Key::KeyStatus
{
	std::set<int> push_key;
	std::set<int> press_key;
	std::set<int> pull_key;
};



Key::Key()
{
	key_status = std::make_unique<KeyStatus>();
}

Key::~Key()
{

}

void Key::PushKey(const ci::app::KeyEvent& key_event)
{
	if (key_status->press_key.find(key_event.getCode()) == key_status->press_key.cend())
	{
		key_status->push_key.insert(key_event.getCode());
		key_status->press_key.insert(key_event.getCode());
	}
}

void Key::PullKey(const ci::app::KeyEvent& key_event)
{
	key_status->press_key.erase(key_event.getCode());
	key_status->pull_key.insert(key_event.getCode());
}

void Key::FlushInput()
{
	key_status->push_key.clear();
	key_status->pull_key.clear();
}

const bool& Key::IsPushKey(const int &key)
{
	return key_status->push_key.find(key) != key_status->push_key.cend();
}

const bool& Key::IsPressKey(const int &key)
{
	return key_status->press_key.find(key) != key_status->press_key.cend();
}

const bool& Key::IsPullKey(const int &key)
{
	return key_status->pull_key.find(key) != key_status->pull_key.cend();
}