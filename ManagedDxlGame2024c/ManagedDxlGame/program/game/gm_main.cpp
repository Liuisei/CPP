//---------------------------------------------------------------------------------------------------------------
//
//
// [ 入門 ] hello world
// 
// ※ 画面に hello world の文字が出力されるだけのサンプルです
//
//---------------------------------------------------------------------------------------------------------------
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"

#include "Bullet.h"
#include "Player.h"

Player* player_ = nullptr;
Bullet* bullet_ = nullptr;
//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart()
{
    player_ = new Player(tnl::Vector3(500, 600, 0));

    srand(time(0));
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time)
{
    player_->update();
    if (bullet_)
    {
        bullet_->update();
    }
    
    player_->draw();
    if (bullet_)
    {
        bullet_->draw();
    }
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd()
{
}
