// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

// һ��8*8�ķ����ӣ�A�������½ǣ�B�������Ͻǣ���A�㵽B������·���ж�����
// ��ͼ�п��Կ�����A�㵽B������·��Ϊ16����A�����8С������8С�������쵽��B�㣬����������ϵ����⣬�������·��16��ѡȡ8�����ߵ�С����(���ߴ����·��16��ѡȡ8�����ߵ�С����)�����Դ�A�㵽B������·��������ֱ�ӿ����������
// ��Ϊ����16����ѡ8��

//ʵ��  �������� �����Ͻ�Ϊ0,0 ���½�Ϊ8,8 ��Ӧ����grid�ĵ�

size_t g_num = 0;  //ͳ��A�㵽B������·������

// ��9X9�������д�ĳһ�㿪ʼ ����Χ4������ʳ������鷶Χ����������16�����ظ���ֱ�ӷ��أ������ó���8,0�� 0,8������·��Ϊ16�ļ���
void shortestPathNumber(char grid[9][9], int row, int col, int &step)
{
    // ��������16���߷�Χ�����Ķ�ֱ�ӷ���
    if (row < 0 || row > 8 || col < 0 || col > 8 || grid[row][col] == '*' || step > 16)
    {
        return;
    }

    //�ﵽ�յ�0,8 û�ﵽ���������ܷ���
    if (row == 0 && col == 8) 
    {
        if (step == 16)  //�ѵ���B�㣬�ҵ������·��16�����ۼ�
        {
            g_num++;
        }
    }
    else
    {
        grid[row][col] = '*'; //��Ǹõ��ѷ���
        step++;

        // ���ʱ�����Χ4����
        shortestPathNumber(grid, row, col + 1, step);
        shortestPathNumber(grid, row + 1, col, step);
        shortestPathNumber(grid, row, col - 1, step);
        shortestPathNumber(grid, row - 1, col, step);

        //�õ��Ѿ������Χ4�����������������ʱ�ǺͲ������Ա�����·������
        grid[row][col] = '.'; //����
        step--;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    char grid[9][9] = {0};
    int step = 0;
    shortestPathNumber(grid, 8, 0, step); //��A�㿪ʼ���� 8��0��
    cout<<"A�㵽B������·������Ϊ: "<<g_num<<endl;

    return 0;
}