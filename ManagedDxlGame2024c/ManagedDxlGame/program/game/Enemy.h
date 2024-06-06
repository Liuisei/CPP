#pragma once
#include "../dxlib_ext/dxlib_ext.h"



class Enemy
{
public:
    Enemy(tnl::Vector3 spawn_position);
    ~Enemy();
    tnl::Vector3 position_;
    bool is_active_ = true;
    void update();
    void draw();
};
