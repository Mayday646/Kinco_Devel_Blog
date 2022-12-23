#ifndef __TETRIS_H__
#define __TETRIS_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h> 
#include <time.h>

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

#define SHAPE_ROW 2
#define SHAPE_COL 4
#define CREATE_TIME 10
typedef enum 
{
    Wall= -1,
    Blank,
    Falling_Tetris,
    Stable_Tetris,
} MAP_TYPE;
/*
俄罗斯方块按照形状来分总共有七种，且都与字母相似，
所以一般都称为"Z", "S", "J", "L", "O", "T", "I"型方块。

字母“S”形的块叫做“罗德岛S”（Rhode Island S）

字母“Z”形的块叫做“克里夫兰Z”（Cleveland Z）

字母“J”形的块叫做“蓝色瑞克”（ Blue Ricky）

字母“L”形的块叫做“橘色瑞克”（Orange Ricky）

字母“O”形的块叫做“粉碎男孩”（Smashboy）

字母“T”形的块叫做“小T”（Teewee）

字母“I”形的块叫做“英雄”（Hero）
*/
typedef enum 
{
    Rhode_Island_S= 0, //S
    Cleveland_Z, //Z
    Blue_Ricky, //J 
    Orange_Ricky, // L
    Smash_boy, // O
    Teewee, // T
    Hero, // I
}BASE_TETRIS;

int i, j;/*变量的声明用于说明变量的属性(主要是变量的类型)；变量的定义除此之外还要引起存储器的分配。*/
char Tetris_background[ROW][COL];
char Tetris_shape[SHAPE_ROW][SHAPE_COL];
char save_previous_shape[SHAPE_ROW][SHAPE_COL];
// char Hero_shape[4]= {1, 1, 1, 1};

int Create_Tetris_Shape(void);
int Creat_Wall(int row, int column);
int Print_Tetris(int row, int column);
int Previous_tetris_shape(char already_shape[][SHAPE_COL]);
int print_tetris_shape(int row, int column, char array[][SHAPE_COL]);
int print_tetris_wall(int row, int column, char array[][COL]);
int Place_Tetris(void);
#endif
//Date:2022/12/23/13:58