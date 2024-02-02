#include "SceneManager.h"

#include "IScene.h"

#include "DrawFunction.h"

SceneManager::SceneManager() {
	traditionManager_ = new SceneTraditionManager(this);
}

SceneManager::~SceneManager() {
	currentScene_.reset();
}

void SceneManager::SetStartScene(IScene* startScene) {
	currentScene_.reset(startScene);
	currentScene_->Init();
}

void SceneManager::Run() {
	if (!traditionManager_->Update()) {
		currentScene_->Update();
	}

	//backGround
	DrawBox(
		{ 0.0f,0.0f },
		{ 1280.0f,720.0f },
		0x323232ff
	);

	currentScene_->Draw();
	traditionManager_->Draw();
}

void SceneManager::SceneChange(IScene* nextScene) {
	traditionManager_->Start(nextScene);
}

void SceneManager::SceneTransition(IScene* nextScene) {
	if (nextScene==nullptr) {
		return;
	}
	currentScene_->Unload();
	currentScene_.reset(nextScene);
	currentScene_->Init();
}