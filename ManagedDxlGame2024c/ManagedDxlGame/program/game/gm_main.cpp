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

class grid
{
public:
    int myx = 0;
    int myy = 0;
    int openx = 0;
    int openy = 0;
    int estimationcost = 0;
    int actualCost = 0;
    int score = 0;

    enum state
    {
        floor,
        wall,
        open,
        close,
        start,
        goal,
        loot
    };

    state gridState = floor;
};

int estimatedCostCalculation(int x, int y);


int horizon = 10;
int vertical = 10;

grid gridArray[100];
std::list<int> gridlist;


int start = 99;
int goal = 0;

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart()
{
    srand(time(0));
    SetFontSize(20);

    gridlist.push_front(start);

    for (int i = 0; i < vertical; ++i)
    {
        for (int j = 0; j < horizon; ++j)
        {
            grid m;
            m.myx = j;
            m.myy = i;
            if (rand() % 4 == 0) { m.gridState = grid::wall; }
            m.estimationcost = estimatedCostCalculation(i, j);
            gridArray[i * vertical + j] = m;
        }
    }

    gridArray[start].gridState = grid::start;
    gridArray[goal].gridState = grid::goal;
}

int estimatedCostCalculation(int x, int y)
{
    int goalx = goal / horizon;
    int goaly = goal % horizon;
    int distance = abs(x - goalx) + abs(y - goaly);
    return distance;
}

bool goalc(int target);

void openCalulation(int num)
{
    int x = gridArray[num].myx;
    int y = gridArray[num].myy;
    int estimationcost = gridArray[num].estimationcost;
    int openx = gridArray[num].myx;
    int openy = gridArray[num].myy;
    if (gridArray[num].gridState == grid::close) { return; }
    if (x > 0 && gridArray[x - 1 + y * horizon].gridState == grid::floor || gridArray[x - 1 + y * horizon].gridState ==
        grid::goal)
    {
        int target = x - 1 + y * horizon;
        gridArray[target].gridState = grid::open;
        gridArray[target].estimationcost = estimationcost + 1;
        gridArray[target].openx = openx;
        gridArray[target].openy = openy;
        gridlist.push_front(target);
        if (goalc(target)){return;}
    }
    if (x < horizon - 1 && gridArray[x + 1 + y * horizon].gridState == grid::floor || gridArray[x + 1 + y * horizon].
        gridState == grid::goal)
    {
        int target = x + 1 + y * horizon;
        gridArray[target].gridState = grid::open;
        gridArray[target].estimationcost = estimationcost + 1;
        gridArray[target].openx = openx;
        gridArray[target].openy = openy;
        gridlist.push_front(target);
        if (goalc(target)){return;}
    }
    if (y > 0 && gridArray[x + (y - 1) * horizon].gridState == grid::floor || gridArray[x + (y - 1) * horizon].gridState
        == grid::goal)
    {
        int target = x + (y - 1) * horizon;
        gridArray[target].gridState = grid::open;
        gridArray[target].estimationcost = estimationcost + 1;
        gridArray[target].openx = openx;
        gridArray[target].openy = openy;
        gridlist.push_front(target);
        if (goalc(target)){return;}
    }
    if (y < vertical - 1 && gridArray[x + (y + 1) * horizon].gridState == grid::floor || gridArray[x + (y + 1) *
        horizon].gridState == grid::goal)
    {
        int target = x + (y + 1) * horizon;
        gridArray[target].gridState = grid::open;
        gridArray[target].estimationcost = estimationcost + 1;
        gridArray[target].openx = openx;
        gridArray[target].openy = openy;
        gridlist.push_front(target);
        if (goalc(target)){return;}
    }
    gridArray[num].gridState = grid::close;
}

bool goalc(int target)
{
    if (target == goal)
    {
        while (target != start)
        {
            gridArray[target].gridState = grid::loot;
            target = gridArray[target].openx + gridArray[target].openy * horizon;
        }
        return true;
    }
    return false;
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time)
{
    for (int i = 0; i < horizon * vertical; ++i)
    {
        grid m = gridArray[i];
        const char* viw;
        if (m.gridState == grid::floor) viw = "_";
        else if (m.gridState == grid::wall) viw = "■";
        else if (m.gridState == grid::open) viw = "%d";
        else if (m.gridState == grid::close) viw = "X";
        else if (m.gridState == grid::start) viw = "S";
        else if (m.gridState == grid::loot) viw = ".";
        else viw = "G";
        if (m.gridState == grid::open || m.gridState == grid::close)
        {
            if (m.gridState == grid::open)
            {
                DrawStringEx(m.myx * 25, m.myy * 25, GetColor(0, 150, 0), "%d", m.estimationcost);
            }
            else
            {
                DrawStringEx(m.myx * 25, m.myy * 25, GetColor(150, 0, 0), "%d", m.estimationcost);
            }
        }
        else
        {
            DrawStringEx(m.myx * 25, m.myy * 25, GetColor(255, 255, 255), viw);
        }
    }
    /*
    for (int i = 0; i < horizon * vertical; ++i)
    {
        grid m = gridArray[i];
        DrawStringEx(m.myx * 25 + 500, m.myy * 25, GetColor(150, 0, 0), "%d", m.estimationcost);
    }
    */
    
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE))
    {
        for (int i = 0; i < gridlist.size(); ++i)
        {
            gridlist.sort([&](int a, int b) { return gridArray[a].estimationcost < gridArray[b].estimationcost; });
            int remove = gridlist.front();
            gridlist.pop_front();
            openCalulation(remove);
        }
    }
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd()
{
}
