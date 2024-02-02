#include "CollisionManager.h"

#include <Vec2.h>

CollisionManager* CollisionManager::GetInstance() {
	static CollisionManager instance;
	return &instance;
}

CollisionManager::CollisionManager() {
	distance_ = Vec2f(0.0f, 0.0f);
}

CollisionManager::~CollisionManager() {
	if (actors_.empty()) {
		return;
	}
	actors_.clear();
}

void CollisionManager::Update() {
	std::vector<Actor*>::iterator giverItr = actors_.begin();
	for (; giverItr != actors_.end();++giverItr) {
		Actor* giver = *giverItr;
		if (giver == nullptr ||
			!giver->GetIsAlive()) {
			continue;
		}

		std::vector<Actor*>::iterator receiverItr = giverItr + 1;
		for (; receiverItr != actors_.end();++receiverItr) {
			Actor* receiver = *receiverItr;

			if (receiver == nullptr ||
				!receiver->GetIsAlive() ||
				giver->GetType() == receiver->GetType()) {
				continue;
			}

			distance_ = giver->GetPos() - receiver->GetPos();

			if (distance_.Length() < giver->GetRadius() + receiver->GetRadius()) {
				giver->OnCollision();
				receiver->OnCollision();
			}
		}
	}
}

void CollisionManager::PushActor(Actor* actor) {
	actors_.push_back(actor);
}