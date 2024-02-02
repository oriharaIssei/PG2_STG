#pragma once

#include "SceneManager.h"
#include "Vec2.h"

class GameManager {
	///
	/// 静的
	///
public:
	static GameManager* GetInstance();
private:
	static Vec2f windowSize_;
	static const char kWindowTitle[];
public:
	static Vec2f GetWindowSize();

	///
	/// メンバ
	///
public:
	int Execute();
private:
	int main();
	void Loop();

	GameManager() = default;
	~GameManager() = default;
	GameManager(const GameManager&) = delete;
	const GameManager& operator=(const GameManager&) = delete;
private:
	SceneManager* sceneManager_;
};