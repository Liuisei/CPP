#pragma once
#include "../dxlib_ext/dxlib_ext.h"


class Player
{
public:
    Player(tnl::Vector3 spawn_position);
    ~Player();
    tnl::Vector3 position_;
    void update();
    void draw();
};
