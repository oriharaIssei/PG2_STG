#include "GameManager.h"
#include <Novice.h>

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	GameManager* game = GameManager::GetInstance();
	return game->Execute();
}