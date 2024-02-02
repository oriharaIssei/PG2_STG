#include "SceneTraditionManager.h"

#include "Easing.h"
#include "DrawFunction.h"
#include "GameManager.h"

void SceneTraditionManager::Start(IScene* next) {
	next_ = next;
	currentTime_ = 0;

	CurrentUpdate = &SceneTraditionManager::Fade_In;
}

bool SceneTraditionManager::Update() {
	if (CurrentUpdate==nullptr) {
		return false;
	}
	(this->*CurrentUpdate)();
	return true;
}

void SceneTraditionManager::Draw() {
	if (CurrentUpdate==nullptr) {
		return;
	}

	DrawBox(
		{0.0f,0.0f},
		GameManager::GetWindowSize(),
		boxColor_.Int()
	);
}

SceneTraditionManager::SceneTraditionManager(SceneManager* host) {
	host_ = host;
}

void SceneTraditionManager::Fade_In() {
	++currentTime_;

	boxColor_.alpha = static_cast<unsigned int>(EasingLerp(&Easing::easeInQuart, static_cast<float>(currentTime_) / static_cast<float>(fullTime_), 0x00, 0xff));

	if (currentTime_>=fullTime_) {
		CurrentUpdate = &SceneTraditionManager::Fade_Out;
		currentTime_ = fullTime_;
		host_->SceneTransition(next_);
	}
}

void SceneTraditionManager::Fade_Out() {
	--currentTime_;

	boxColor_.alpha = static_cast<unsigned int>(EasingLerp(&Easing::easeInQuart, static_cast<float>(currentTime_) / static_cast<float>(fullTime_),0x00, 0xff));

	if (currentTime_ <= 0) {
		CurrentUpdate = nullptr;
	}
}