#include "Play.h"
#include "Title.h"

#include "InputManager.h"
#include "Novice.h"

void Play::Init() {
	collision_ = CollisionManager::GetInstance();

	player_ = new Player();
	enemy_ = new Enemy();

	player_->Init();
	enemy_->Init();
}

void Play::Update() {
	if (InputManager::IsRelease(DIK_RETURN)) {
		host_->SceneChange(new Title(host_));
		return;
	}

	player_->Update();
	enemy_->Update();

	collision_->Update();
}

void Play::Draw() {
	player_->Draw();
	enemy_->Draw();
}

void Play::Unload() {
	delete player_;
	delete enemy_;
}

Play::Play(SceneManager* host) :IScene(host) {};