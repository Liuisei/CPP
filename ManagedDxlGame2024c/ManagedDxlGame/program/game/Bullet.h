#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "Bullet.h"


class Bullet
{
public:
    Bullet(tnl::Vector3 spawn_position);
    ~Bullet();
    tnl::Vector3 position_;
    void update();
    void draw();
};
