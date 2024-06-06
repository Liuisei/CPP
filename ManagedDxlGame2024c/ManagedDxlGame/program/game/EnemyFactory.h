#pragma once
#include "../dxlib_ext/dxlib_ext.h"



class EnemyFactory
{
public:
    EnemyFactory(tnl::Vector3 spawn_position);
    ~EnemyFactory();
    tnl::Vector3 position_;
    bool is_active_ = true;
    void update();
    void draw();
};
