#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
程序要求：整型数组 10*20  20行10列
    *   -1: 墙
    *   0: 空白
    *   1: 下落的方块
    *   2: 落好的方块
*/
#define DSP(fmt, ...) printf(fmt, ##__VA_ARGS__);
#define ROW 22 
#define COL 12
enum 
{
    Wall= -1,
    Blank,
    Falling_Tetris,
    Stable_Tetris,
};

int Tetris_background[ROW][COL];

int Tetris_shape[2][4];

int Creat_Wall(int row, int column)
{
    int i= 0, j= 0;
    for(i= 0; i < row; i++) 
    {
        for(j= 0; j < column; j++)
        {
            if(row-1 ==i || 0 == i || 0 == j || column-1 == j)
            {
                Tetris_background[i][j] = Wall;
            }
            else
            {
                Tetris_background[i][j] = Blank;
            }
        }
    }
    for(i= 0; i < row; i++)
     {
        for(j= 0; j < column; j++)
        {
            if(column-1 == j)
            DSP("\n");
            switch (Tetris_background[i][j])
            {
                case Wall:
                {
                    DSP("■");
                }
                break;
                
                case Blank:
                {
                    DSP(" ");
                }
                break;
                case Falling_Tetris:
                {
                    DSP("□")
                }
                case Stable_Tetris:
                {
                    DSP("◇");
                }
            }
        }
        ;
     }

    return i + j;
}


int main(int argc, char *argv[])
{
    Creat_Wall(ROW, COL);
    system("pause");

}
//Date:2022/12/22/17:21