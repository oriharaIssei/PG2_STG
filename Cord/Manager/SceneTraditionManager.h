#pragma once

#include "Color.h"

class IScene;
class SceneManager;
class SceneTraditionManager {
public:
	void Start(IScene* next);
	bool Update();
	void Draw();

	SceneTraditionManager(SceneManager* host);
private:
	void (SceneTraditionManager::*CurrentUpdate)();
	void Fade_In();
	void Fade_Out();
private:
	SceneManager* host_;

	const int fullTime_ = 48;
	float easedT_;
	int currentTime_;

	Color boxColor_;
	IScene* next_;
};