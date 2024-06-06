#include "Bullet.h"

extern Bullet* bullet_;

Bullet::Bullet(tnl::Vector3 spawn_position)
{
    position_ = spawn_position;
}

Bullet::~Bullet()
{
    
}

void Bullet::update()
{
    position_.y -= 20;
    if (position_.y < -100)
    {
        delete bullet_ ;
        bullet_ = nullptr;
    }
}

void Bullet::draw()
{
    DrawCircle(position_.x, position_.y, 5, -1);
}
