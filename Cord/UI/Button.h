#pragma once

#include "Vec2.h"
#include "Color.h"

#include <functional>

class Button {
public:
	Button() = default;
	Button(int directKeyNum);

	~Button();

	void Init(const Vec2f& pos,
		const Vec2f& size,
		const Vec2f& srcPos,
		const Vec2f& srcSize,
		unsigned int nomalColor,
		unsigned int selectedColor,
		const char* gh);
	void Init(const Vec2f& pos,
		const Vec2f& size,
		const Vec2f& srcPos,
		const Vec2f& srcSize,
		unsigned int nomalColor,
		unsigned int selectedColor,
		const char* gh,
		std::function<void()> releasedFuncPtr);
	void Init(const Vec2f& pos,
		const Vec2f& size,
		const Vec2f& srcPos,
		const Vec2f& srcSize,
		unsigned int nomalColor,
		unsigned int selectedColor,
		int gh);
	void Init(const Vec2f& pos,
		const Vec2f& size,
		const Vec2f& srcPos,
		const Vec2f& srcSize,
		unsigned int nomalColor,
		unsigned int selectedColor,
		int gh,
		std::function<void()> releasedFuncPtr);

	
	void Update();
	void Draw();

	void InputHandler();
private:
	void (Button::* CurrentUpdate)();
	void Select_Update();
	void Trigger_Update();
	void Release_Update();

	bool CheckIsInside();
	bool CheckIsReleaseDirectKeys();
private:
	Vec2f pos_;
	Vec2f size_;

	Vec2f srcPos_;
	Vec2f srcSize_;

	enum colorType {
		NOMAL,
		SELECTED
	};
	Color color_[2];
	Color* currentColor_;

	bool isInside_;

	int gh_;

	std::vector<int> directKeyNums_;

	std::vector<std::function<void()>> releasedFunc_;
public:
	bool GetIsInside()const;

	Vec2f GetPos()const;
	void SetPos(const Vec2f& pos);

	Vec2f GetSize()const;
	void SetSize(const Vec2f& size);

	void SetDirectKey(int directKeyNum);
};