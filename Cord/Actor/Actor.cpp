#include "Actor.h"

#include "CollisionManager.h"

Actor::Actor(ActorType type,CollisionManager* coll) {
	type_ = type;

	pos_ = Vec2f(0.0f, 0.0f);
	speed_ = 0.0f;
	isAlive_ = false;
	coll->PushActor(this);
}

Actor::~Actor() {
}

ActorType Actor::GetType() const {
	return type_;
}

Vec2f Actor::GetPos() const {
	return pos_;
}

void Actor::SetPos(const Vec2f& pos) {
	pos_ = pos;
}

Vec2f Actor::GetDir() const {
	return dir_;
}

float Actor::GetSpeed() const {
	return speed_;
}

float Actor::GetRadius() const {
	return radius_;
}

bool Actor::GetIsAlive() const {
	return isAlive_;
}