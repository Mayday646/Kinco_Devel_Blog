## 结构声明形式三种方式

```c
1.
    struct example {
        int x;
        int y;
        int z;
    };
struct example p1 ,p2;
2.
    struct {
        int x;
        int y;
        int z;
    };
//！ p1 ,p2 是无名结构 里面有x, y, z;
3.
    struct example {
        int x;
        int y;
        int z;
    }p1, p2; // p1 p2 在此定义
```
---
### 结构体初始化:
```c
    struct example p1 = {1, 2, 3}; 
//依次赋值

    struct example p2 = {.x = 4, .z = 5}
//指定赋值 不指定的成员默认值是 0  
    p1 = p2 
 p1.x = p2.x, p1.y=p2.y // 可以直接进行赋值运算，数组不行
// 可以不初始化 
struct example today;   
today = (struct example) ={1, 2, 3};

struct example *pDate = &today;
// 结构变量不是地址 做右值 要带 '&' 
```
---
### 结构体数组
```c
 struct example  arr[] = {
        {4, 5},
        {6, 7},
        ...,
    };
```
---

### 结构体中的结构  
结构体嵌套
```c
    struct example_2 {
        struct example Px1;
        struct example Py1;
    }r , *rp;

    rp = &r;
    !!! r.Px1.x, r.Px1.y; <==> rp->Px1.x <==> (*rp).Px1.x;
        r.Py1.x, r.Py1.y;
```
### 自定义数据类型 typedef:
```c
typedef struct ~~example~~ 
 {
    int x;
    int y;
}Data; //! Data d <==> struct example d
typedef char*[10] String;  //String是 十个 字符 的数组
```
- - -
### 联合体 :union
```c
typedef union {
       int c;
       char ch[sizeof(int)];  
    }CHI;
int main(void)
{
    CHI test;
    int i;
    test.i = 0x45d2;
    for(i = 0; i< sizeof(int); i++)
    {
        printf("%02hhX", chi.ch[i]);
    }
    printf("\n");
    return 0;
}
```
---

<font size =3 color =red face ="幼圆">
大端模式中字数据的高字节存储在低地址中，而字数据的低字节则存放在高地址中。
<br/>在小端存储模式中，低地址中存放的是字数据的低字节，高地址存放的是字数据的高字节
</font>  

<font size =2  face ="幼圆">
<br/>
16位宽的数0x1234在小端模式CPU内存中的存放方式（假设从地址0x4000开始存放）为

小端模式：
|内存地址|0x4000|0x4001|
|:----:|:----:|:----:|
|数据|0x34|0x12|
   
大端模式：
|内存地址|0x4000|0x4001|
|:----:|:----:|:----:|
|数据|0x12|0x34|
</font>

---

#### 代码部分：

```c
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
**Date:2022/11/14**
