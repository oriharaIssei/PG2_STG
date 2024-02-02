#include "Title.h"
#include "Play.h"

#include "InputManager.h"
#include "Novice.h"
#include "GameManager.h"

void Title::Init() {
	titleButton_ = new Button(DIK_SPACE);
	titleButton_->Init(
		GameManager::GetWindowSize() * 0.5f,
		GameManager::GetWindowSize() * 0.5f,
		{ 0.0f,0.0f },
		{ 1400.0f,700.0f },
		0xc0c0c0ff,
		WHITE,
		"./Resource/title.png",
		[this]() {host_->SceneChange(new Play(host_));}
	);

	titleButton_->SetDirectKey(DIK_RETURN);
}

void Title::Update() {
	titleButton_->InputHandler();
	titleButton_->Update();
}

void Title::Draw() {
	titleButton_->Draw();
}

void Title::Unload() {
	delete titleButton_;
	titleButton_ = nullptr;
}

Title::Title(SceneManager* host) :IScene(host) {
	titleButton_ = nullptr;
};