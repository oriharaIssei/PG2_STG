#include "Player.h"

#include "CollisionManager.h"

#include "Novice.h"
#include "DrawFunction.h"

void Player::Init() {
	isAlive_ = true;

	pos_ = { 680.0f,560.0f };
	radius_ = 24.0f;
	speed_ = 8.0f;

	fullCoolTime_ = 16;
	coolTime_ = fullCoolTime_;

	color_ = 0x0095b9ff;

	if (!bullets_.empty()) {
		bullets_.clear();
	}
}

void Player::Update() {
	if (!isAlive_) {
		if (Novice::CheckHitKey(DIK_SPACE)) {
			isAlive_ = true;
		}
		return;
	}
	coolTime_ = coolTime_ >= 0 ? --coolTime_ : 0;

	Move();

	Shot();

	for (auto bullet : bullets_) {
		if (!bullet->GetIsAlive()) {
			continue;
		}
		bullet->Update();
	}
}

void Player::Draw() {
	if (isAlive_) {
		DrawCircle(pos_, radius_ , color_.Int());
	}

	for (auto bullet : bullets_) {
		if (!bullet->GetIsAlive() 
			||
			bullet == nullptr) {
			continue;
		}
		bullet->Draw();
	}
}

void Player::OnCollision() {
	isAlive_ = false;
}

Player::Player() :Actor(ActorType::PLAYER, CollisionManager::GetInstance()) {
}

Player::~Player() {
	if (bullets_.empty()) {
		return;
	}
	bullets_.clear();
}

void Player::Move() {
	dir_.x = static_cast<float>(Novice::CheckHitKey(DIK_D) - Novice::CheckHitKey(DIK_A));
	dir_.y = static_cast<float>(Novice::CheckHitKey(DIK_S) - Novice::CheckHitKey(DIK_W));

	dir_ = Normalize(dir_);

	pos_ += dir_ * speed_;
	if (dir_ != Vec2f(0.0f, 0.0f)) {
		bulletDir_ = dir_;
	}
}

void Player::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		if (coolTime_ <= 0) {
			coolTime_ = fullCoolTime_;
			for (auto bullet : bullets_) {
				if (!bullet->GetIsAlive()) {
					bullet->Init();
					return;
				}
			}
			Bullet* newBullet = new Bullet(this);
			newBullet->Init();
			bullets_.push_back(newBullet);
		}
	}
}

Vec2f Player::GetBulletDir() const {
	return bulletDir_;
}