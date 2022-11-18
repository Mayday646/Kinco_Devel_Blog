### C标准输入输出
+ `printf`
    + `%[flags][width][.prec][hlL]type`
  
---

|[flags]|含义|[width][prec]|含义|[hlL]|含义|
|:--:|:--:|:--:|:--:|:--:|:--:|  
|' - '|左对齐|number|最小字符|hh|char|
|' + '|右对齐|' * '|下一参数是字符|h|short|
|(space)|正数留空|.number|小数点后的位数|l|long|
|0|填充不兼容' - '|" .* "|下一参数小数点后的位数|L|long double|

```c    
    printf ("%9d\n", 123); //   %[flags][width]
    printf ("%-9d\n", 123); //  %[+/-]  [9]
    printf ("%9.2f\n", 123.0)   //“9”:整个输出占9位“.2”小数点后两位
```

<div align =left>
    <img src="https://cdn.jsdelivr.net/gh/Mayday646/Kinco_Devel_Blog/Default_Picture_Dir/printf_type.png" alt="printf_type" width="600"/>
</div>

```c
    int *num;
    printf("%d%n\n",1234,&num); 
    // num =4, 输出到“%n” 时记录已输出的字符数量 存放在 *num 所指向的地址
```

---

+ `scanf`
  + `%[flag]type`

|[flags]|含义|[flags]|含义|
|:--:|:--:|:--:|:--:| 
|number|最大字符数|l|long/double|
|hh|char|ll|long long|
|h|short|L|long double|
|' * '|跳过|

```c
    int num;
    scanf("%*d%d", &num); // 跳过第一次输入的“整型”
```
<div align =left>
    <img src="https://cdn.jsdelivr.net/gh/Mayday646/Kinco_Devel_Blog/Default_Picture_Dir/scanf_type.jpg" alt="scanf_type" width="600"/>
</div>

+ [...]
    + 例子: [.^]
   ![scanf_GPS](https://cdn.jsdelivr.net/gh/Mayday646/Kinco_Devel_Blog/Default_Picture_Dir/scanf_GPS.jpg)

### `printf` 和 `scanf` 的返回值
+  `printf`: ***<font color =blue>int</font>*** 类型,读入的项目数 `\n`  算一个字符,也计算入内 
+  `scanf`: ***<font color =blue>int</font>*** 类型,输出的字符数
```c

    scanf("%d%d", &a, &b);
    // 如果a和b都被成功读入，那么scanf()的返回值就是2；
    // 如果只有a被成功读入，返回值为1；
    // 如果a和b都未被成功读入，返回值为0；
    // 如果遇到错误或遇到end of file，返回值为EOF。
    //EOF是一个预定义的常量，等于-1;
```
+  在严格要求的程序中，应该判断每次调用 scanf或printf的返回值，从而了解程序运行是否存在问题

---

### 文件输入输出
+ `FILE* fopen(const char *restrict path, const char *restrict mode, ...)`
+ `int fclose(FILE *stream, ...)`
+ `fscanf(FILE *stream, ...)`
+ `fprintf(FILE *stream, ...)`

`fopen`: “mode”
|||
|:--:|:--:|
|r|只读|
|r+|读写，从头文件开始|
|w|只写，不存在则新建，存在则清空|
|w+|读写，不存在则新建，存在则清空|
|a|追加，不存在则新建，存在则从文件尾开始|
|..x|只新建，文件存在则不能打开|

```c
    FILE *fp = fopen("filename", "mode");
    //filename：文件名，mode：打开的模式;
    //这函数返回一个指向打开文件的指针。返回空指针（NULL）值表示错误。
    if(fp)
    {
        int num;
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        fclose(fp);
    }
    else
    {
        printf ("Could not open file")
    }
```

---

### 二进制文件

+ 所有文件最终都是二进制
+ 文本文件是最简单的方式可读写文件
  + >more， tail
  + >cat
  + >vim  
+ 二进制文件需要专门的程序来读写
+ 文本文件的输入输出是格式化,可能经过转码
  

#### 二进制文件读写

+ `size_t fread(void *restrict prt, size_t size, size_t nitems, FILE *restrict stream )`
+ `size_t fwrite(void *restrict prt, size_t size, size_t nitems, FILE *restrict stream )`
    + ***FILE 指针*** 是最后一个参数
    + `return` 成功读写字节数
  
`nitems`：
+ 二进制文件的读写一般是通过对一个结构变量操作进行
+ `nitems`是说明这次读写几个结构变量

```c
#define LEN 20
typedef struct {

    char name[LEN];
    int gender;
    int age;

}Student;

```


<!-- 
- ![#f03c15](https://via.placeholder.com/15/f03c15/000000?text=+) `#f03c15`
- ![#c5f015](https://via.placeholder.com/15/c5f015/000000?text=+) `#c5f015`
- ![#1589F0](https://via.placeholder.com/15/1520F0/000000?text=+) `#1589F0`
  
- [x] #739
- [ ] https://github.com/octo-org/octo-repo/issues/740
- [ ] Add delight to the experience when all tasks are complete :tada:
  
```diff
- text in red
+ text in green![Uploading 2020110214465175.png… 
! text in orange
# text in gray
```

-->