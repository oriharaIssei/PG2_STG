#pragma once
#include "Actor.h"

#include "memory"

class Player;
//=================================
// 発射される弾
//=================================
class Bullet :
	public Actor {
public:
	void Init()override;
	void Update()override;
	void Draw()override;

	void OnCollision()override;

	Bullet(Player* player_ptr);
	~Bullet();
private:
	std::unique_ptr<Player> host_;
};