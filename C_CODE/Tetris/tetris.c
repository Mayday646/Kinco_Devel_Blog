
#include "tetris.h"
// char Hero_flag= 0;
int cnt= CREATE_TIME;

int Create_Tetris_Shape(void)
{
    memset(Tetris_shape, Blank, sizeof(Tetris_shape));
    //memset函数按字节对内存块进行初始化，所以不能用它将 int 数组初始化为0和-1之外的其他值
    // 更改为 char 类型
    //print_tetris_shape(2, 3, Tetris_shape);
    srand((BYTE)time(NULL));
    int index= rand() % 7;
    // int hero= 6;
    // index= hero;
    printf("___index = %d\n",index);
    switch (index) 
    {
        case Rhode_Island_S:
        {
            Tetris_shape[0][1]= Falling_Tetris; Tetris_shape[0][2]= Falling_Tetris; 
            Tetris_shape[1][0]= Falling_Tetris; Tetris_shape[1][1]= Falling_Tetris;
        }    
        break;
        case Cleveland_Z:
        {
            Tetris_shape[0][0]= Falling_Tetris; Tetris_shape[0][1]= Falling_Tetris; 
            Tetris_shape[1][1]= Falling_Tetris; Tetris_shape[1][2]= Falling_Tetris;
        }
        break;
        case Blue_Ricky:
        {
            Tetris_shape[0][0]= Falling_Tetris; Tetris_shape[1][0]= Falling_Tetris;
            Tetris_shape[1][1]= Falling_Tetris; Tetris_shape[1][2]= Falling_Tetris; 
        }
        break;
        case Orange_Ricky:
        {
            Tetris_shape[0][2]= Falling_Tetris; Tetris_shape[1][0]= Falling_Tetris;
            Tetris_shape[1][1]= Falling_Tetris; Tetris_shape[1][2]= Falling_Tetris;
        }
        break;
        case Smash_boy:
        {
            Tetris_shape[0][1]= Falling_Tetris; Tetris_shape[0][2]= Falling_Tetris;
            Tetris_shape[1][1]= Falling_Tetris; Tetris_shape[1][2]= Falling_Tetris;
        }
        break;
        case Teewee:
        {
            Tetris_shape[0][1]= Falling_Tetris; Tetris_shape[1][0]= Falling_Tetris;
            Tetris_shape[1][1]= Falling_Tetris; Tetris_shape[1][2]= Falling_Tetris;
        }
        break;
        case Hero:
        {
            Tetris_shape[1][0]= Falling_Tetris; Tetris_shape[1][1]= Falling_Tetris; 
            Tetris_shape[1][2]= Falling_Tetris; Tetris_shape[1][3]= Falling_Tetris; 
        
        }
        break;

        default:
            DSP("Invalid");
            return -1;
        break;
    }

    print_tetris_shape(SHAPE_ROW, SHAPE_COL, Tetris_shape);
    DSP("\n");
    return 0;
}

int Creat_Wall(int row, int column)
{
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
    return row + column;
}

int Print_Tetris(int row, int column)
{
     for(i= 0; i < row; i++)
    {
        for(j= 0; j < column; j++)
        {
            switch (Tetris_background[i][j])
            {
                case Wall:
                {
                    DSP("口")
                }
                break;
                
                case Blank:
                {
                    DSP("  ");
                }
                break;
                case Falling_Tetris:
                {
                    DSP("□")
                }
                break;
                case Stable_Tetris:
                {
                   DSP("■");
                }
                break;
                default:
                    return -1;
                break;
            }
            if(column-1 == j)
            DSP("\n");
        }
    }
    return 0;
}

int print_tetris_shape(int row, int column, char array[][SHAPE_COL])
{
    printf("\n");
    for(i= 0; i < row; i++)
    {
        for(j= 0; j < column; j++)
        {
            printf("%d", array[i][j]);
            if(column-1 == j )
                printf("\n");
        }
    }
    return 0;

}

int print_tetris_wall(int row, int column, char array[][COL])
{
    printf("\n");
    for(i= 0; i < row; i++)
    {
        for(j= 0; j < column; j++)
        {
            printf("%2d", array[i][j]);
            if(column-1 == j )
                printf("\n");
        }
    }
    return 0;

}

int Place_Tetris(void)
{
   
    for(i= 0; i < 2; i++)
    {
        for(j= 0; j < 4; j++)
        {
            Tetris_background[i+1][j+4]= Tetris_shape[i][j];
        }
    }

    return 0;

}  

int test(void)
{
    char Hero_shape1[3][3];
    memset(Hero_shape1, 1, sizeof(Hero_shape1));  
    for(i= 0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            printf("%d ", Hero_shape1[i][j]);
            if(j != 0 && j % 2 == 0)
            printf("\n");
        }
    }
    return 0;
}

int Stable_tetris(void)
{
    if(cnt == CREATE_TIME - 1)
    {
        goto Exit; 
    }
    for(i= 0; i < 2; i++)
    {
        for(j= 0; j < 4; j++)
        {
            if(Falling_Tetris == save_previous_shape[i][j])
            {
                save_previous_shape[i][j]= Stable_Tetris;
            }
            Tetris_background[i+ROW-3][j+4]= save_previous_shape[i][j];
        }
    }
 Exit:
    return 0;
}

int Previous_tetris_shape(char already_shape[][SHAPE_COL])
{
    memcpy(save_previous_shape, already_shape, sizeof(save_previous_shape));
    return 0;
}

int main(int argc, char *argv[])
{
    while (cnt--)
    {
        Creat_Wall(ROW, COL);
        Create_Tetris_Shape();
        Previous_tetris_shape(Tetris_shape);
        Place_Tetris();
        Stable_tetris();
        // print_tetris_wall(ROW, COL, Tetris_background);
        Print_Tetris(ROW, COL);
        getchar();
    }
    system("pause");
     return 0;
}
//Date:2022/12/22/17:21