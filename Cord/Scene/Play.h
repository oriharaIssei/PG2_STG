#pragma once
#include "IScene.h"

#include "Player.h"
#include "Enemy.h"

#include "CollisionManager.h"

class Play :
	public IScene {
public:
	void Init()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	Play(SceneManager* host);
	~Play() = default;
private:
	Player* player_;
	Enemy* enemy_;

	CollisionManager* collision_;
};