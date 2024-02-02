#include "Bullet.h"
#include "Player.h"

#include "CollisionManager.h"

#include "DrawFunction.h"

void Bullet::Init() {
	isAlive_ = true;

	pos_ = Vec2f(host_->GetPos().x , host_->GetPos().y);

	radius_ = 16.0f;

	speed_ = 16.0f;

	if (host_->GetBulletDir()!=Vec2f(0.0f,0.0f)) {
	dir_ = host_->GetBulletDir();
	} else {
		dir_ = { 0.0f,1.0f };
	}

	color_ = 0xa4a8b4ff;
}

void Bullet::Update() {
	if (!isAlive_) {
		return;
	}
	pos_ += dir_ * speed_;
	if (pos_.x < -radius_ || pos_.x>1280 + radius_||
		pos_.y < -radius_ || pos_.y > 1280 + radius_) {
		isAlive_ = false;
	}
}

void Bullet::Draw() {
	if (!isAlive_) {
		return;
	}
	DrawCircle(pos_, radius_, color_.Int());
}

void Bullet::OnCollision() {
	isAlive_ = false;
}

Bullet::Bullet(Player* player_ptr) :Actor(ActorType::PLAYER, CollisionManager::GetInstance()) {
	host_ = std::unique_ptr<Player>(player_ptr);
}

Bullet::~Bullet() {
}