#### 编译预处理指令
+ **<font color = blue>'#'**</font> 预处理指令
+ 不是C 语言的成分
+ `#define` 定义一个宏
    + 产生的顺序`*.c -> *.i -> *.s -> *.o ->  a.out/*.exe`
    + `#define`<名字> <值>
    + 结尾没有分号
    + 名字是一个字符串 值可以是任何东西
    + 在C语言的编译器开始编译之前,编译预处理程序(cpp)进行完全的 **<font color = red>文本替换('名字' 换成 '值')</font>** 

+ 命令`gcc *.c --save-temps`在 `*.i` 文件 可以看到
  
---

#### 宏
+ 如果一个宏的值有其他的宏的名字,也是会被替换的
+ 如果一个宏的值超过一行,行末需要加 **<font color = red>' \ '</font>**
+ 宏的值后面出现的注释不会被当作宏的值的一部分 ***空格会***
+ 宏可以只有名字没有值`#define _DEBUG`
+ 预定义的宏：

        __DATE__ 当前日期，一个以 “MMM DD YYYY” 格式表示的字符串常量。
        __TIME__ 当前时间，一个以 “HH:MM:SS” 格式表示的字符串常量。
        __FILE__ 这会包含当前文件名，一个字符串常量。

        __LINE__ 这会包含当前行号，一个十进制常量。

        __STDC__ 当编译器以 ANSI 标准编译时，则定义为 1；判断该文件是不是标准 C 程序
+ 用来把参数转换成字符串: **#** 字符串化（stringizing）
    + `#define P(A) printf("%s:%d\n",#A,A)`

```c
#define debug(…) printf(VA_ARGS)
// 缺省号代表一个可以变化的参数表。使用保留名 VA_ARGS 把参数传递给宏。当宏的调用展开时，实际的参数就传递给 printf()。

#define error_info(fmt, ...) printf("[PLC]:in [%s] [%s] at line [%d]\r\n"fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define debug_info(fmt,...) printf(fmt,##__VA_ARGS__)
#define MODULE_NAME "MY_LIBS"
#define error_printf(fmt,...) printf("[ERROR]["MODULE_NAME"](%s|%d)"fmt,__func__,__LINE__,##__VA_ARGS__)

```
+ 预处理器粘合剂： **##** 运算符
  + 可以用于类函数宏的替换部分。
  + 另外，还可以用于类对象宏的替换部分,这个运算符把两个语言符号组合成单个语言符号。
```c
#define XNAME(n) x##n
#define PXN(n) printf("x"#n" = %d\n",x##n)
int main(void)
{
    int XNAME(1)=12;//int x1=12;
    PXN(1);//printf("x1 = %d\n", x1);
    return 0;
}
输出结果：
x1=12
```
+ 可变参数宏 ···和__VA_ARGS__
```c
#define PR(...) printf(__VA_ARGS__)
int main()
{
    int wt=1,sp=2;
    PR("hello\n");
    PR("weight = %d, shipping = %d",wt,sp);
    return 0;
}

输出结果：
hello
weight = 1, shipping = 2
注意：省略号只能代替最后面的宏参数
#define W(x,...,y)错误！
```
+ ##__VA_ARGS__这里的 **##** 有特殊作用
  + 假如可变参数宏为空的时候，**##** 的作用就是让编译器忽略前面一个逗号，不然编译器会报错。
```c
#define debug(format, ...) fprintf (stderr, format, ## __VA_ARGS__)
```

+ 带参数的宏`#define CUBE(x) ((x)*(x)*(x))` 容易运算时出错
    + 需要带括号"( )",整个值需要带括号,参数出现的地方带括号
    + 可以带多个参数 `#define MAX(a,b) ((a)>(b):(a)?(b))`
    + 可以做很多函数，效率高但占用内存大
  
  ---

#### 代码
```c
#define PI 3.145
#define PI_2 2*PI // Pi * 2

#define PRT printf("%f\n", PI * 3.0);\
            printf("%f\n", PI_2 * 3.0)
#define _DEBUG

#define CUBE(x) ((x)*(x)*(x))

int main (void)
{
    printf("%f\n", PI_2 * 3.0);
    printf("%s\n%s\n%s\n%d", __FILE__, __DATE__,__TIME__, __LINE__);
    CUBE(5); // ((5)*(5)*(5))
    return 0;
}
```
---

#### 头文件
+ 在 C 语言或者 C++ 中，头文件一般为 .h 结尾，h 表示 header，因此被称为“头文件”，其实就是文本插入。
+ 头文件里一般存放公开的函数原型，数据类型等内容，其他模块需要使用这些函数或者数据类型时，只需包含相应头文件即可。
+ `#include <*.h>` 表示包含系统目录指定的头文件，如果在系统目录中找不到对应的头文件，会报错：<font color = red>No such file or directory！</font>
+ `#include "*.h"`表示包含指定的头文件，优先在当前工程的头文件目录寻找对应的头文件，如果在工程头文件目录中找不到对应的头文件，那么会继续在系统目录中查找对应的头文件，如果系统目录和工程头文件目录都找不到对应的头文件就会报错：<font color = red>No such file or directory！</font>
##### 1.头文件重复包含编译器报错
+ 通过宏定义解决头文件重复包含
  +   通过 `#ifndef / #define` 解决头文件重复包含(标准头文件结构)

```c
#ifndef __XXX_H__  //如果(没有定义宏__XXX_H__)
#define __XXX_H__  //那么直接定义宏__XXX_H__
int a = 1;           //定义变量a 并且赋值为 1
#endif             //结束程序
```
##### 2.通过 #pragma once 解决头文件重复包含
+ `#pragmaonce`是上述方式的简写，好处是再也不会有两个头文件因为使用了同样的 `__XXX_H__` 而被忽略了
##### 3.不希望对外公开的函数/变量
+ 在函数前面加上`static`此函数成为只能被所在编译单元中使用
+ 在全局变量面前加上`static`此全局变量成为只能被所在编译单元中使用
#### 声明和定义
+ 声明不产生代码，定义会产生代码
+ 一般来来说 头文件里只能声明，否则一个项目中多个编译单元中有重名的实体
    +  *某些编译器中允许几个编译单存在同名函数 / `weak` 修饰符强调这种存在*
+ `int i `变量定义
+ `extern int i` 变量声明(不能初始化)
---
***<div align =right>Date:2022/11/16</div>***
***<div align =right>UpDate:22/12/21</div>***
