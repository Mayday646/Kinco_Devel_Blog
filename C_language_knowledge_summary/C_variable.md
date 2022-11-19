### 全局变量  
+ 全局变量和局部变量不同,不初始化会默认赋值 0
+ 指针会被赋值 ___<font color = blue>NULL___</font>
+ 只能用编译时刻已知的值来初始化全局变量
    + ` int a = 12; int b = a;  // 在 main 之前赋值会报错`
    + `const int a = 12; int b = a; //这样做是可以的`
- 初始化发生在 *main* 之前
- 如果函数内部有局部变量和全局变量重名,全局变量会被隐藏;
---

### 静态本地变量
+ 在本地变量定义时加上  ___<font color = blue>static___</font>修饰符成为静态本地变量。
    +  ***static***: 局部作用域本地可访问
    +  实际上是特殊的全局变量，位于相同的内存区域
+ 当函数离结束时，静态本地变量会 ***<font color =red> 继续存在并保持其值***</font>！
+ 会在 **第一次** 进入这个函数时初始化，后续再次进入函数时会保持上次时离开的值
+ 具有全局的生存期,函数内的局部作用域
  
```c
int f(void)
{
    static int a = 1;
    a += 2;
    printf("%d\n", a);
}

int main (void)
{
    f(); //a = 3
    f(); //a = 5 不会重新赋值；
}
```
  ---

### 返回指针的函数
+ `return`本地变量的地址是危险的
+ `return`全局变量或静态本地变量的地址是安全的
+ `return`在函数内 malloc 的内存是安全的，但是容易造成问题
+ 最好的做法是`return`传入的指针
  
```c++
int *f(void)
 {
    int i = 12;
    printf("%p", i);
    return &i;
 }

 int g(void)
 {
    int j = 34;
    printf("%p", j);
 }
int main(void)
{
    int *p =f();
    printf("f:%d\n", *p);
    g();
    printf("g:%d\n", *p);
}
```
<!-- <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd> 重启电脑-->

---

***<div align =right>Date:2022/11/16<div>***
