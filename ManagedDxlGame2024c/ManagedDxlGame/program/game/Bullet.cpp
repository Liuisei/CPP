#include "Bullet.h"

extern std::list<Bullet*> bullets_not_active_;
extern std::list<Bullet*> bullets_active_;

Bullet::Bullet(tnl::Vector3 spawn_position) { position_ = spawn_position; }

Bullet::~Bullet()
{
}

void Bullet::update()
{
    if (!is_active_) { return; }

    position_.y -= 20;
    if (position_.y < -100) {
        is_active_ = false;
        bullets_not_active_.emplace_back(this);
    }
}


void Bullet::draw()
{
    if (!is_active_) { return; }
    DrawCircle(position_.x, position_.y, 5, -1);
}
