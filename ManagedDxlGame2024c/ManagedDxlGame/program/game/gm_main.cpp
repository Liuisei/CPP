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
#include "Enemy.h"

Player* player_ = nullptr;

std::list<Bullet*> bullets_not_active_;
std::list<Bullet*> bullets_active_;
 std::list<Enemy*> Enemys_not_active_;
 std::list<Enemy*> Enemys_active_;
void Debug();

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
    Debug();
    player_->update();
    for (auto bullet : bullets_active_) { bullet->update(); }

    player_->draw();
    for (auto bullet : bullets_active_) { bullet->draw(); }
}

void Debug()
{
    DrawStringEx(0, 0, -1, "%d", bullets_not_active_.size());
    DrawStringEx(0, 10, -1, "%d", bullets_active_.size());
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd()
{
}
