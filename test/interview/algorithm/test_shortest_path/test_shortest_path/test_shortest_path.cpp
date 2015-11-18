// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

// 一个8*8的方格子，A点在左下角，B点在右上角，求A点到B点的最短路径有多少条
// 从图中可以看出，A点到B点的最短路径为16，即A点横走8小格，纵走8小格才能最快到达B点，这是排列组合的问题，即从最短路径16中选取8个横走的小格子(或者从最短路径16中选取8个纵走的小格子)。所以从A点到B点的最短路径条数，直接可以算出来，
// 即为：从16个中选8个

//实现  设置坐标 从左上角为0,0 右下角为8,8 对应数组grid的点

size_t g_num = 0;  //统计A点到B点的最短路径条数

// 在9X9的数组中从某一点开始 向周围4个点访问超出数组范围、步长超过16、已重复的直接返回，遍历得出从8,0到 0,8的所有路径为16的计数
void shortestPathNumber(char grid[9][9], int row, int col, int &step)
{
    // 步长超过16或者范围超过的都直接返回
    if (row < 0 || row > 8 || col < 0 || col > 8 || grid[row][col] == '*' || step > 16)
    {
        return;
    }

    //达到终点0,8 没达到继续向四周访问
    if (row == 0 && col == 8) 
    {
        if (step == 16)  //已到达B点，且等于最短路径16，就累加
        {
            g_num++;
        }
    }
    else
    {
        grid[row][col] = '*'; //标记该点已访问
        step++;

        // 访问本点周围4个点
        shortestPathNumber(grid, row, col + 1, step);
        shortestPathNumber(grid, row + 1, col, step);
        shortestPathNumber(grid, row, col - 1, step);
        shortestPathNumber(grid, row - 1, col, step);

        //该点已经完成周围4个点遍历，则清除访问标记和步长，以便其他路径访问
        grid[row][col] = '.'; //回溯
        step--;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    char grid[9][9] = {0};
    int step = 0;
    shortestPathNumber(grid, 8, 0, step); //从A点开始搜索 8行0列
    cout<<"A点到B点的最短路径条数为: "<<g_num<<endl;

    return 0;
}