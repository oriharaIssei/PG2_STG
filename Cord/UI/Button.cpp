#include "Button.h"

#include "Novice.h"
#include "InputManager.h"
#include "DrawFunction.h"

Button::Button(int directKeyNum) {
	directKeyNums_.push_back(directKeyNum);

	currentColor_ = nullptr;
	CurrentUpdate = nullptr;
}

Button::~Button() {
	if (!directKeyNums_.empty()) {
		directKeyNums_.clear();
	}

	if (!releasedFunc_.empty()) {
		releasedFunc_.clear();
	}
}

void Button::Init(
	const Vec2f& pos,
	const Vec2f& size,
	const Vec2f& srcPos,
	const Vec2f& srcSize,
	unsigned int nomalColor,
	unsigned int selectedColor,
	const char* gh) {
	pos_ = pos;
	size_ = size;

	srcPos_ = srcPos;
	srcSize_ = srcSize;

	color_[NOMAL] = nomalColor;
	color_[SELECTED] = selectedColor;
	currentColor_ = &color_[NOMAL];

	gh_ = Novice::LoadTexture(gh);
}

void Button::Init(
	const Vec2f& pos,
	const Vec2f& size,
	const Vec2f& srcPos,
	const Vec2f& srcSize,
	unsigned int nomalColor,
	unsigned int selectedColor,
	const char* gh,
	std::function<void()> releasedFuncPtr) {
	Init(pos,
		size,
		srcPos,
		srcSize,
		nomalColor,
		selectedColor,
		gh);
	releasedFunc_.push_back(releasedFuncPtr);
}

void Button::Init(const Vec2f& pos, const Vec2f& size, const Vec2f& srcPos, const Vec2f& srcSize, unsigned int nomalColor, unsigned int selectedColor, int gh) {
	pos_ = pos;
	size_ = size;

	srcPos_ = srcPos;
	srcSize_ = srcSize;

	color_[NOMAL] = nomalColor;
	color_[SELECTED] = selectedColor;
	currentColor_ = &color_[NOMAL];

	gh_ = gh;
}

void Button::Init(const Vec2f& pos, const Vec2f& size, const Vec2f& srcPos, const Vec2f& srcSize, unsigned int nomalColor, unsigned int selectedColor, int gh, std::function<void()> releasedFuncPtr) {
	Init(pos,
		size,
		srcPos,
		srcSize,
		nomalColor,
		selectedColor,
		gh);
	releasedFunc_.push_back(releasedFuncPtr);
}

void Button::Update() {
	currentColor_ = &color_[isInside_];
	if (CurrentUpdate == nullptr) {
		return;
	}
	(this->*CurrentUpdate)();
}

void Button::Draw() {
	DrawQuad(
		pos_,
		size_,
		srcPos_,
		srcSize_,
		gh_,
		currentColor_->Int()
	);
}

bool Button::CheckIsInside() {
	if (pos_.x - (size_.x / 2.0f) < InputManager::MousePos().x &&
		pos_.x + (size_.x / 2.0f) > InputManager::MousePos().x
		&&
		pos_.y - (size_.y / 2.0f) < InputManager::MousePos().y &&
		pos_.y + (size_.y / 2.0f) > InputManager::MousePos().y) {
		return true;
	}
	return false;
}

bool Button::CheckIsReleaseDirectKeys() {
	if (directKeyNums_.empty()) {
		return false;
	}

	for (auto directKeyNum : directKeyNums_) {
		if (InputManager::IsRelease(directKeyNum)) {
			return true;
		}
	}
	return false;
}

void Button::InputHandler() {
	if (CheckIsReleaseDirectKeys()) {
		isInside_ = true;
		CurrentUpdate = &Button::Release_Update;
		return;
	}

	isInside_ = CheckIsInside();

	if (!isInside_) {
		return;
	}

	if (CurrentUpdate == nullptr) {
		CurrentUpdate = &Button::Select_Update;
	}
}

void Button::Select_Update() {
	if (!isInside_) {
		CurrentUpdate = nullptr;
		return;
	}

	if (isInside_ && InputManager::IsMouseButtonPress(0)) {
		CurrentUpdate = &Button::Trigger_Update;
		return;
	}
}

void Button::Trigger_Update() {
	if (!isInside_) {
		CurrentUpdate = nullptr;
		return;
	}

	if (isInside_) {
		if (InputManager::IsMouseButtonRelease(0)) {
			CurrentUpdate = &Button::Release_Update;
			return;
		}
	}
}

void Button::Release_Update() {
	if (!isInside_) {
		return;
	}
	for (auto func : releasedFunc_) {
		func();
	}
	CurrentUpdate = nullptr;
}

bool Button::GetIsInside() const {
	return isInside_;
}

Vec2f Button::GetPos() const {
	return pos_;
}

void Button::SetPos(const Vec2f& pos) {
	pos_ = pos;
}

Vec2f Button::GetSize() const {
	return size_;
}

void Button::SetSize(const Vec2f& size) {
	size_ = size;
}

void Button::SetDirectKey(int directKeyNum) {
	directKeyNums_.push_back(directKeyNum);
}