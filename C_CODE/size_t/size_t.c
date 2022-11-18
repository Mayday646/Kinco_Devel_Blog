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
    int gender;
    int age;

}Student;

void GetList(Student aStu[], int number)
{
    char format[LEN];
    sprintf(format, "%%%ds", LEN - 1);
    //"%19s"

    for(int i = 0; i < number; i++)
    {
        printf("%dth student\n\t姓名: ", i + 1);
        scanf(format, &aStu[i].name);
        printf("\t性别: ");
        scanf(format, &aStu[i].gender);
        printf("\t年龄: ");
        scanf(format, &aStu[i].age);
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

int Fseek(void)
{
    FILE *fp = fopen("student.date", "r");
    if(fp)
    {
        fseek(fp, 0L, SEEK_END);
        int number = ftell(fp)/sizeof(Student);
        printf("There has %d Dates ,which one do you want to seek?\n", number);
        int index;
        scanf("%d", &index);
        Fread(fp, index - 1);
        fclose(fp);
    }
}

void Fread(FILE *fp, int index)
{
    fseek(fp, index*sizeof(Student), SEEK_SET);
    Student *stu;
    if(fread(&stu, sizeof(Student), 1 , fp) == 1)
    {
        
    } 
}

int main(void)
{
    int number;
    printf("input student number:\n");
    scanf("%d", &number);
    Student aStu[number];
    GetList(aStu, number);

    if(save(aStu, number))
        printf("Save successful");
    else
        printf("Save failed");
    return 0;
}