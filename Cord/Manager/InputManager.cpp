#include "InputManager.h"

#include "Novice.h"

 char InputManager::keys_[256];
 char InputManager::preKeys_[256];

 int InputManager::mousePosX_;
 int InputManager::mousePosY_;

 int InputManager::mouseButton_[8];
 int InputManager::preMouseButton_[8];

void InputManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	memcpy(preMouseButton_, mouseButton_, 8);

	for (int i = 0; i < 8; i++) {
		mouseButton_[i] = Novice::IsPressMouse(i);
	}

	Novice::GetMousePosition(&mousePosX_, &mousePosY_);
}

bool InputManager::IsTrigger(int key) {
	return keys_[key] && !preKeys_[key];
}


bool InputManager::IsRelease(int key) {
	return !keys_[key] && preKeys_[key];
}

bool InputManager::IsPress(int key) {
	return keys_[key] && preKeys_[key];
}

Vec2f InputManager::MousePos() {
	return Vec2f(static_cast<float>(mousePosX_), static_cast<float>(mousePosY_));
}

bool InputManager::IsMouseButtonTrigger(int mouseButton) {
	return mouseButton_[mouseButton] && !preMouseButton_[mouseButton];
}

bool InputManager::IsMouseButtonRelease(int mouseButton) {
	return !mouseButton_[mouseButton] && preMouseButton_[mouseButton];
}

bool InputManager::IsMouseButtonPress(int mouseButton) {
	return  mouseButton_[mouseButton] && preMouseButton_[mouseButton];
}