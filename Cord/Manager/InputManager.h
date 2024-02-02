#pragma once

#include "Vec2.h"

class InputManager {
public:
	static void Update();
private:
	static char keys_[256];
	static char preKeys_[256];

	static int mousePosX_;
	static int mousePosY_;

	static int mouseButton_[8];
	static int preMouseButton_[8];
public:
	static bool IsTrigger(int key);
	static bool IsRelease(int key);
	static bool IsPress(int key);

	static Vec2f MousePos();
	static bool IsMouseButtonTrigger(int mouseButton);
	static bool IsMouseButtonRelease(int mouseButton);
	static bool IsMouseButtonPress(int mouseButton);
};