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
### 结构体指针
+ 首先用定义好的结构体，定义一个结构体变量，用结构体变量来为结构体指针初始化
  + 始终理解结构体是一种特殊的数据类型，根据数据类型，可以定义变量、指针和数组。

```c
struct student  //定义了一个结构体
{
    long stuid; 
    char name[10];
    int age;
    int score;
    student birthday;
}stu1;   //定义了一个结构体变量

    struct student stu2;  //因为结构体含有名字，所以可以继续定义结构体变量stu2
    struct student *stu3;   //定义了一个结构体指针

    stu3=&stu1; //同指针一样，结构体指针指向结构体变量

        /*可替换为     
    1）struct student *stu3=&stu1; //定义的同时初始化
    2）struct student *stu3;
    *stu3=stu1;
    */
    struct student stu4[10];  //定义了一个结构体数组
```
+ 如何用指针访问结构体变量的成员？

```c
//方法一：
//同结构体变量一样，通过成员选择运算符
 
    stu1.age=18;
    (*stu3).age=19;   //通过对stu3的解引用  

    //方法二：
    //通过指向运算符来访问，例如：

    stu3 -> age =19;
 
```
+ 构体嵌套的访问

```c
    //级联访问

    stu1.birthday.year = 1998;
    (*stu3).birthday.year =1998;
    stu3 -> birthday . year =1998;

    //三种方式。
```
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
    }r, *rp;

    rp = &r;
    !!! r.Px1.x, r.Px1.y; <==> rp->Px1.x <==> (*rp).Px1.x;
        r.Py1.x, r.Py1.y;
```
### 结构体数组的指针
+ 如何定义一个结构体数组的指针

```c
#include <stdio.h>
 
int main()
{
	typedef struct information  //定义了一个结构体
	{
		long stuid; 
		char name[10];
		int age;
		int score;
	}info;   //别名
	
	info stu[40]; //定义了一个结构体数组
	info *pt;   //定义了结构体指针
	pt = stu;   //指针初始化方法一
 
    info *pt1 = &stu[0]; //初始化方法二
 
    info *pt2 = stu;   //方法三
}
```
+ 如何访问结构体数组的指针

```c
    info stu[40];   //info为结构体标签的别名
    info *pt;
    pt = stu;

    stu[0].stuid =  1001;
    (*pt).stuid = 1001 ;
    pt -> stuid =1001; //三条语句等价
	
    stu[1].stuid =1002 ; 
    (pt++) -> stuid =1002; 
    (*pt++).stuid = 1002 ;  //语句等价
```
### 自定义数据类型 typedef:
```c
typedef unsigned int u_int32; // 要加 ';'
typedef struct ~~example~~ 
 {
    u_int32 x;
    u_int32 y;
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
### 枚举 :enum
```c

Typedef enum workday  //此处的workday可以省略，或者改成其他，不会影响后面
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //此处的workday为枚举型enum workday的别名，类似于int
workday today, tomorrow; //此处的workday颜色对应，变量today和tomorrow的类型为枚举型workday，也即enum workday
enum workday中的workday可以省略：
typedef enum
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //此处的workday为枚举型enum workday的别名
workday today, tomorrow; //变量today和tomorrow的类型为枚举型workday，也即enum workday
也可以用这种方式：
typedef enum workday   //VC6.0和MDK编译均未通过
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
};
workday today, tomorrow; //变量today和tomorrow的类型为枚举型workday，也即enum workday
注意：同一个程序中不能定义同名的枚举类型，不同的枚举类型中也不能存在同名的命名常量。
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

+ 大部分操作系统(windows、linux)都是小端模式，少部分,如MAC OS是大端模式。

---

***TEST CODE:***   
[<u>struct.c</u>](https://github.com/Mayday646/Kinco_Devel_Blog/blob/main/C_CODE/struct.c)



***<div align =right>Date:2022/11/14***  
	***UpDate:2022/11/20/23:44</div>***
