#include "Enemy.h"

#include "CollisionManager.h"

#include "DrawFunction.h"

#include "random"

void Enemy::Init() {
	isAlive_ = true;

	pos_ = { 640.0f,256.0f };
	radius_ = 36.0f;
	dir_ = { 0.0f,0.0f };
	speed_ = 8.0f;

	//エネミーはtargetPointに向かって動く
	SetNextTargetPoint();

	color_ = 0xb33e5cff;
	targetPointCircleColor_ = 0xff000064;

	spawnTimer_ = maxSpawnTime_;
	wait2NextTargetPointTime = maxWait2NextTargetPointTime;

	CurrentUpdate = &Enemy::Wait2NextTargetPointUpdate;
	CurrentDraw = nullptr;
}

void Enemy::Update() {
	if (CurrentUpdate == nullptr) {
		return;
	}
	(this->*CurrentUpdate)();
}

void Enemy::Draw() {
	if (CurrentDraw == nullptr) {
		return;
	}
	(this->*CurrentDraw)();
}

void Enemy::OnCollision() {
	isAlive_ = false;
}

Enemy::Enemy() :Actor(ActorType::ENEMY, CollisionManager::GetInstance()) {
}

Enemy::~Enemy() {
}

void Enemy::ReSpawnUpdate() {
	--spawnTimer_;

	if (spawnTimer_ <= 0.0f) {
		isAlive_ = true;
		spawnTimer_ = maxSpawnTime_;

		CurrentUpdate = &Enemy::Wait2NextTargetPointUpdate;
		return;
	}
	CurrentDraw = &Enemy::ReSpawnDraw;
}

void Enemy::ReSpawnDraw() {
	if (spawnTimer_ % 5 < 2) {
		DrawCircle(
			pos_,
			radius_,
			color_.Int()
		);
	}
}

void Enemy::MoveUpdate() {
	if (!isAlive_) {
		CurrentUpdate = &Enemy::ReSpawnUpdate;

		std::random_device rand;
		std::mt19937_64 gen(rand());
		std::uniform_real_distribution<float> randPosX(radius_, 1280.0f - radius_);
		std::uniform_real_distribution<float> randPosY(radius_, 720.0f - radius_);
		pos_ = { randPosX(gen),randPosY(gen) };

		return;
	}

	dir_ = targetPoint_ - pos_;
	if (dir_.Length() <= 5.0f) {
		SetNextTargetPoint();
		CurrentUpdate = &Enemy::Wait2NextTargetPointUpdate;
		return;
	}

	dir_ = Normalize(dir_);

	pos_ += dir_ * speed_;
	CurrentDraw = &Enemy::MoveDraw;
}

void Enemy::MoveDraw() {
	DrawCircle(targetPoint_, radius_, targetPointCircleColor_.Int());
	DrawCircle(pos_, radius_, color_.Int());
}

void Enemy::SetNextTargetPoint() {
	targetPoint_ = pos_;
	while ((targetPoint_ - pos_).Length() <= 30.0f) {
		//エネミーはtargetPointに向かって動く
		std::random_device rand;
		std::mt19937_64 gen(rand());
		std::uniform_real_distribution<float> randPosX(radius_, 1280.0f - radius_);
		std::uniform_real_distribution<float> randPosY(radius_, 720.0f - radius_);

		targetPoint_ = { randPosX(gen),randPosY(gen) };
	}
}

void Enemy::Wait2NextTargetPointUpdate() {
	if (!isAlive_) {
		CurrentUpdate = &Enemy::ReSpawnUpdate;
		return;
	}

	--wait2NextTargetPointTime;

	if (wait2NextTargetPointTime <= 0) {
		wait2NextTargetPointTime = maxWait2NextTargetPointTime;
		CurrentUpdate = &Enemy::MoveUpdate;
	}

	CurrentDraw = &Enemy::Wait2NextTargetPointDraw;
}

void Enemy::Wait2NextTargetPointDraw() {
	if (wait2NextTargetPointTime % 5 < 2) {
		DrawCircle(
			targetPoint_,
			radius_,
			targetPointCircleColor_.Int()
		);
	}
	DrawCircle(pos_, radius_, color_.Int());
}