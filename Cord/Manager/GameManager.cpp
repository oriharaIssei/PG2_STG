#include "GameManager.h"

#include "Title.h"

#include <Novice.h>
#include "InputManager.h"

Vec2f GameManager::windowSize_ = { 1280.0f,720.0f };
const char GameManager::kWindowTitle[] = "LC1B_08_オリハラ_イッセイ_PG2_評価課題02";

int GameManager::Execute() {
	return main();
}

int GameManager::main() {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, static_cast<int>(windowSize_.x), static_cast<int>(windowSize_.y));

	sceneManager_ = new SceneManager();
	sceneManager_->SetStartScene(new Title(sceneManager_));

	Loop();

	delete sceneManager_;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

void GameManager::Loop() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// 入力情報を受け取る
		InputManager::Update();

		sceneManager_->Run();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}
}

GameManager* GameManager::GetInstance() {
	static GameManager instance;
	return &instance;
}

Vec2f GameManager::GetWindowSize() {
	return windowSize_;
}