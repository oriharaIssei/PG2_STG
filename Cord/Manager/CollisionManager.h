#pragma once

#include "Actor.h"

#include <vector>

class CollisionManager {
public:
	static CollisionManager* GetInstance();
public:
	void Update();
private:
	CollisionManager();
	~CollisionManager();
	CollisionManager(const CollisionManager& collisionManager) = delete;
	const CollisionManager& operator=(const CollisionManager& collisionManager) = delete;

private:
	std::vector<Actor*> actors_;
	Vec2f distance_;
public:
	void PushActor(Actor* actor);
};