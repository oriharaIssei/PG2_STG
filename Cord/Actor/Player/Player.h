#pragma once
#include "Actor.h"

#include "Bullet.h"
#include "vector"

class Player :
    public Actor {
public:
    void Init()override;
    void Update()override;
    void Draw()override;

    void OnCollision()override;

    Player();
    ~Player();

private:
    void Move();
    void Shot();
private:
    std::vector<Bullet*> bullets_;

    Vec2f bulletDir_;

    int fullCoolTime_;
    int coolTime_;
public:
    Vec2f GetBulletDir()const;
};