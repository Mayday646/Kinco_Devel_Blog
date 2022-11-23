#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include"node.h"
/*
程序要求：
*/
typedef struct _list{
    Node *head;
}List;

void add(List *pHead, int number)
{
    Node *p =(Node*)malloc(sizeof(Node));
    p->data= number;
    p->next= NULL;//尾结点
    Node *end= pHead->head;
    //find the end of the list
    if(end)
    {
        while(end->next)
        {
            end= end->next;
        }
        end->next= p;
    }
    else
    {
        pHead->head= p;
    }
   
}

void displayDate(List *plist)
{
    Node *p= plist->head;
    while(p)
    {
        printf("%d ", p->data);
        p= p->next;
    }
    printf("\n");
}

void FindDate(List *plist)
{
    int number;
    printf("intput find number\n");
    scanf("%d", &number);
    Node *p= plist->head;
    int find_date= 0;
    while(p)
    {
        if(p->data == number)
        {
            printf("There!\n");
            find_date= 1;
            break;
        }
        p= p->next;
    }
 if(!find_date)
    printf("Not find this date\n");   
}

void deleteDate(List *plist)
{
    int number;
    printf("intput delete date\n");
    scanf("%d", &number);
    Node *q= NULL;
    Node *p= plist->head;
    for(; p; q= p, p= p->next)// ','表达式;
    {
        if(p->data == number)
        {
            if(q)
                q->next= p->next;
            else
                plist->head= p->next;
            free(p);
            break;
        }
    }
    displayDate(plist);
}

int main(void)
{
    //Node *head = NULL;//头结点
    List list;
    list.head = NULL;
    int num= 0;
    
    //while(scanf("%d", &num)!= EOF)
    while (num++ < 4)
    {
        // add node to linked list
        add(&list, num);
    }

    // Node *p = list.head;
    // while(p)
    // {
    //     printf("%d ", p->data);
    //     p= p->next;
    // }

    displayDate(&list);
    
    FindDate(&list);

    deleteDate(&list);
    
    return 0;

}
//Date:2022/11/23/11:21