#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
程序要求：
*/
#define LEN 8

typedef struct {

    char name[LEN];
    unsigned int gender;
    unsigned int age;

}Student;

void GetList(Student aStu[], int number)
{
    // char format[LEN];
    // sprintf(format, "%%%ds", LEN - 1);
    //"%19s"
    // 这种写法 写入会多一个 "\0"
    for(int i = 0; i < number; i++)
    {
        printf("%dth student\n\tName: ", i + 1);
        scanf("%7s", aStu[i].name); //%7s: 限定输入长度 LEN - 1 ?
        printf("\tGender: ");
        scanf("%d", &aStu[i].gender);
        printf("\tAge: ");
        scanf("%d", &aStu[i].age);
        getchar();
    }
}
int Fsave(Student aStu[], int number)
{
    int ret = -1;
    FILE *fp = fopen("student.date", "w");
    if(fp)
    {
        ret = fwrite(aStu, sizeof(Student), number, fp);
        fclose(fp);
    }
    return ret == number;
}

void Fread(FILE *fp, int index)
{
    fseek(fp, index * sizeof(Student), SEEK_SET); // (*fp)走到 结构首地址 也是首成员地址 x index
    Student Stu;
    //? Student *Stu; //定义指针变量
    if(fread(&Stu, sizeof(Student), 1, fp) == 1)
    {
        printf("%dth student\n\tName: %s\n", index + 1, Stu.name);
        printf("\tGender: ");
        switch (Stu.gender)
        {
            case 1: 
                printf("Male\n");
                break;
            case 2: 
                printf("Female\n");
                break;
            case 3:
                printf("Other\n");
                break;
            default:
                printf("Unknown %d\n", Stu.gender);
                break;
        }
        printf("\tAge: %d\n",Stu.age);
    } 
}

void Fseek(void)
{
    FILE *fp = fopen("student.date", "r");
    if(fp)
    {
        fseek(fp, 0L, SEEK_END); // (*fp) 指向文件数据末尾
        long file_size = ftell(fp);   // 得到文件总大小
        int number = file_size / sizeof(Student); // 文件总大小 / 每个结构体大小 得到 结构体数量
        printf("There has %d Dates ,which one do you want to seek?\n", number);
        int index;
        scanf("%d", &index);
        Fread(fp, index - 1);
        fclose(fp);
    }
}

int main(void)
{
    // int number;
    // printf("input student number:\n");
    // scanf("%d", &number);
    // Student aStu[number];
    // GetList(aStu, number);

    // if(Fsave(aStu, number))
    //     printf("Write successful\n");
    // else
    //     printf("Write failed\n");
    Fseek();
    return 0;
}