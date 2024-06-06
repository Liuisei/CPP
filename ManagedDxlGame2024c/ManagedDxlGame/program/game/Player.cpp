#include "Player.h"
#include "Bullet.h"

extern Bullet* bullet_;

Player::Player(tnl::Vector3 spawn_position)
{
    position_ = spawn_position;
}

Player::~Player()
{
}

void Player::update()
{
    if (tnl::Input::IsKeyDown(eKeys::KB_LEFT))
    {
        position_.x -= 10;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT))
    {
        position_.x += 10;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_Z) && bullet_ == nullptr)
    {
        bullet_ = new Bullet(position_);
    }
}


void Player::draw()
{
    DrawBoxEx(position_, 30, 50, false, GetColor(0, 255, 0));
}
