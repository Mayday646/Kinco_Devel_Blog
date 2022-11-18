#### c标准输入输出
+ `printf`
    + `%[flags][width][.prec][hlL]type`
  
---

|[flags]|含义|[width][prec]|含义|[hlL]|含义|
|:--:|:--:|:--:|:--:|:--:|:--:|  
|' - '|左对齐|number|最小字符|hh|byte|
|' + '|右对齐|' * '|下一参数是字符|h|short|
|(space)|正数留空|.number|小数点后的位数|l|long|
|0|填充不兼容' - '|" .* "|下一参数小数点后的位数|L|long double|

```c    
    printf ("%9d\n", 123); //   %[flags][width]
    printf ("%-9d\n", 123); //  %[+/-]  [9]
    printf ("%9.2f\n", 123.0)   //“9”:整个输出占9位“.2”小数点后两位
```

<div align =left>
    <img src="https://cdn.jsdelivr.net/gh/Mayday646/Kinco_Devel_Blog/Default_Picture_Dir/type.png" width="600"/>
</div>



+ `scanf`
  + `%[flag]type`










 <!-- 
- ![#f03c15](https://via.placeholder.com/15/f03c15/000000?text=+) `#f03c15`
- ![#c5f015](https://via.placeholder.com/15/c5f015/000000?text=+) `#c5f015`
- ![#1589F0](https://via.placeholder.com/15/1520F0/000000?text=+) `#1589F0`
```diff
- [x] #739
- [ ] https://github.com/octo-org/octo-repo/issues/740
- [ ] Add delight to the experience when all tasks are complete :tada:
- text in red
+ text in green![Uploading 2020110214465175.png… 
! text in orange
# text in gray

```
-->