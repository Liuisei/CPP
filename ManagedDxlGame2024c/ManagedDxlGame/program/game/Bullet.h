﻿#pragma once
#include "../dxlib_ext/dxlib_ext.h"



class Bullet
{
public:
    Bullet(tnl::Vector3 spawn_position);
    ~Bullet();
    tnl::Vector3 position_;
    bool is_active_ = true;
    void update();
    void draw();
};
