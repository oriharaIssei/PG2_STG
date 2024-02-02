#pragma once
#include "Actor.h"
#include "Color.h"

class Enemy :
	public Actor {
public:
	void Init()override;
	void Update()override;
	void Draw()override;

	void OnCollision()override;

	Enemy();
	~Enemy();
private:
	void (Enemy::* CurrentUpdate)();
	void (Enemy::* CurrentDraw)();

	void ReSpawnUpdate();
	void ReSpawnDraw();

	void MoveUpdate();
	void MoveDraw();
	
	void Wait2NextTargetPointUpdate();
	void Wait2NextTargetPointDraw();

	void SetNextTargetPoint();
private:
	int spawnTimer_;
	const int maxSpawnTime_ = 60;

	bool arrival2TargetPoint_;
	Vec2f targetPoint_;
	Color targetPointCircleColor_;

	int wait2NextTargetPointTime;
	const int maxWait2NextTargetPointTime = 60;
};