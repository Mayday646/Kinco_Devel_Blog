#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct point *getStruct(struct point *p)
{
    p->x = 4;
    p->y = 5;
    printf("get: %i %i\n", p->x, p->y);
    return p;
}

void output(struct point p)
{
    printf("out: %i %i\n", p.x, p.y);
}

void print(const struct point *p)
{
    printf("pri: %i %i\n", p->x, p->y);
}

int main(void)
{
    struct point y = {0, 0};
    output(y);
    getStruct(&y);
    output(y); 
    output(*getStruct(&y));
    print(getStruct(&y));
    *getStruct(&y) = (struct point){7, 8};
    printf("main: %i %i\n", y.x, y.y); // 赋值运算最后做;
    printf("%s",__func__);  // __func__当前函数名称
    
}
// 结构体的 引用 变量初始化 //Date: 2022/05/02 
/*
int main(void)
{
    struct date
    {
        int  years, month, day;
    };
    struct stu
    {
        int num, age;
        char  *name, sex;
        float score;
        struct date bir;
    } stu1,stu2={102, 16 ,"erqi",'F',89,1999,2,14}; //赋值 可传递赋值(date)；
#if 0
    stu1.birthday.day=13;
    stu1.num=27;
    stu1.name="erqi";
    scanf("%c%f",&stu1.sex,&stu1.score);
  #endif // 0
        stu1=stu2;
        printf("\tNO:%d\n\tName:%s\n",stu2.num,stu2.name);
        printf("\tSex:%c\n\tScore:%2.1f\n",stu2.sex,stu2.score);
        printf("\tBirdate:%d-%d-%d\n",stu2.bir.years,stu2.bir.month,stu2.bir.day);
}
*****************/
//定义结构体数组
/************
int main(void)
{
    struct date
    {
        int  years, month, day;
    };

    struct stu
    {
        int num, age;
        char  *name, sex;
        float score;
        struct date bir;
    } stus[2]={
                {12, 16 ,"erqi",'M',89,1999,2,14},
                {11, 17,"jiusan",'F',98,2000,4,12}
                };
                        //数组多变量赋值 可传递赋值(date)；
    for(int i=0; i<2; i++)
    {
        printf("\t-----------------------------------------\n");
        printf("\tNO:%d\n\tName:%s\n",stus[i].num,stus[i].name);
        printf("\tSex:%c\n\tScore:%2.1f\n",stus[i].sex,stus[i].score);
        printf("\tBirdate:%d-%d-%d\n",stus[i].bir.years,stus[i].bir.month,stus[i].bir.day);
        printf("\t-----------------------------------------\n");
    }
}
*************/
//指向结构体变量的指针
/***************
int main(void)
{
    struct stu
    {
        int num;
        char *name, sex;
        float score;
    }stus={1,"didi",'M',78};
    struct stu *p;
    p=&stus;
    // p=&stu;// X

    printf("\t-----------------------------------------\n");
    printf("\tNO:%d\n\tName:%s\n",stus.num,stus.name);
    printf("\tSex:%c\n\tScore:%2.1f\n",stus.sex,stus.score);
    printf("\t-----------------------------------------\n");

    printf("\t-----------------------------------------\n");
    printf("\tNO:%d\n\tName:%s\n",(*p).num,(*p).name);
    printf("\tSex:%c\n\tScore:%2.1f\n",(*p).sex,(*p).score);
    printf("\t-----------------------------------------\n");
    // (*p) .  成员列表
    printf("\t-----------------------------------------\n");
    printf("\tNO:%d\n\tName:%s\n",p->num,p->name);
    printf("\tSex:%c\n\tScore:%2.1f\n",p->sex,p->score);
    printf("\t-----------------------------------------\n");
    // p -> 成员列表
}
*/
```