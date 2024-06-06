#include "Player.h"
#include "Bullet.h"

extern std::list<Bullet*> bullets_not_active_;
extern std::list<Bullet*> bullets_active_;

Player::Player(tnl::Vector3 spawn_position) { position_ = spawn_position; }

Player::~Player()
{
}

void Player::update()
{
    if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) { position_.x -= 10; }
    if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) { position_.x += 10; }
    if (tnl::Input::IsKeyDown(eKeys::KB_Z)) {
        if (bullets_not_active_.size() > 0) {
            auto bullet = bullets_not_active_.front();
            bullets_not_active_.pop_front();
            bullet->is_active_ = true;
            bullet->position_ = position_;
        }
        else { bullets_active_.emplace_back(new Bullet(position_)); }
    }
}


void Player::draw() { DrawBoxEx(position_, 30, 50, false, GetColor(0, 255, 0)); }
