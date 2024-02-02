#pragma once

#include "memory"
#include "SceneTraditionManager.h"
class IScene;
class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void SetStartScene(IScene* startScene);

	void Run();
	void SceneChange(IScene* nextScene);
	void SceneTransition(IScene* nextScene);
private:
	std::unique_ptr<IScene> currentScene_;
	SceneTraditionManager* traditionManager_;
};