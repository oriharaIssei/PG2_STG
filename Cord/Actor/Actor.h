#pragma once

#include "Vec2.h"
#include "Color.h"

//==================================
//画面上で動くものの基底クラス
//==================================
enum class ActorType {
	PLAYER,
	ENEMY
};
class CollisionManager;
class Actor {
public:
	Actor(ActorType type,CollisionManager* coll);
	virtual ~Actor();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void OnCollision() = 0;
protected:
	Vec2f pos_;
	float radius_;

	Vec2f dir_;
	float speed_;

	int spawnTimer_;
	int fullSpawnTime_;
	bool isAlive_;

	Color color_;
private:
	ActorType type_;
public:
	ActorType GetType()const;

	Vec2f GetPos()const;
	void SetPos(const Vec2f& pos);
	float GetRadius()const;

	Vec2f GetDir()const;
	float GetSpeed()const;
	bool GetIsAlive()const;
};