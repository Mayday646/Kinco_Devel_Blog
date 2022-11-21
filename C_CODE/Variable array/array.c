#include "array.h"
// typedef struct {

//     int *array;
//     int size;

// } Array; //为什么不是指针 *Array ?

#define ARRAY_SIZE 32
Array array_create(int init_size)   //创建数组
{
    Array a;
    a.array = (int*)malloc(sizeof(int) * init_size);
    a.size = init_size;
    return a;
}

void array_free(Array *array) //释放内存
{
    free(array->array);
    array->array = NULL;    //保险起见，防止二次调用次函数
    array->size = 0;
}

void array_inflate(Array *array, int more_size)
{
    int *new_array = (int*)malloc(sizeof(int) * (array->size + more_size));
    // for(int i = 0; i < array->size; i++)
    // {
    //     new_array [i] = array->array[i];
    // }
    memcpy(new_array, array->array, array->size);
    free(array->array);
    array->array = NULL;
    array->array = new_array; 
    array->size += more_size;
}

int array_size(const Array *array) //数组大小
{
    return array->size; //封装
}

int *array_at(Array *array, int index) //查看某个数组元素
{
    if(index >= array->size)
    {
        array_inflate(array, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - array->size);
    }
    return &(array->array[index]);  //为啥返回指针？ 方便赋值
}

int main(void)
{
    Array a = array_create(ARRAY_SIZE);
    printf("%d\n", array_size(&a));
    //printf("%d", a.size);         //两者的区别?
   
    //*array_at(&a, 0) = 10;          //可如此法赋值
       //查看数组元素
    int cnt = 0;
    while(scanf("%d", array_at(&a, cnt++)) != EOF)
        ;
    for(int i = 0; i < cnt - 1; i++)
    {
        printf("array[%d]=%d\n", i, *array_at(&a, i));
    }
    array_free(&a);
    return 0; 
}