#include "Enemy.h"

extern std::list<Enemy*> Enemys_not_active_;
extern std::list<Enemy*> Enemys_active_;

Enemy::Enemy(tnl::Vector3 spawn_position) { position_ = spawn_position; }

Enemy::~Enemy()
{
}

void Enemy::update()
{
    if (!is_active_) { return; }

    position_.y -= 20;
    if (position_.y > 100) {
        is_active_ = false;
        Enemys_not_active_.emplace_back(this);
    }
}


void Enemy::draw()
{
    if (!is_active_) { return; }
    DrawCircle(position_.x, position_.y, 10, -1);
}
