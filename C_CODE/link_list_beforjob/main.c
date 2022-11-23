#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
// 静态链表

struct static_Link {

    int num;
    int score;
    char *name;
    struct static_Link *next;

}a,b,c;

void display(struct static_Link *p)
{
    while(p) // 只要p 指向地址不为空这说明指向了一个有效的结构体变量，即某个结点
    {
        printf("学号:%d 名字:%s 分数:%d\n", p->num, p->name, p->score);
        p= p->next;
        //将循环指针p 更新为下一结点的地址
    }
}

int main (void)
{
    a.num=1; a.score=65; a.name= "张三";
    b.num=2; b.score=67; b.name= "李四";
    c.num=3; c.score=78; c.name= "王五";
   // 建立链表节点的关系
    struct static_Link *head; // head 头结点，p是遍历链表的循环指针；

    head= &a;
    a.next= &b;
    b.next= &c;
    c.next= NULL; // next 指针指向下一节点 ，最后指向NULL链表结束;
    display(head);
}

//动态链表 : 增删查改
#if 0
 struct Link
{
    int num;
    int score;
    struct Link *next ;
};
  struct Link* createList(int n)
{
    // 创建动态链表；
    struct Link *head=(struct Link*)malloc(sizeof(struct Link));

   /*
    头结点，无需循环创建，必须存在；
    动态分配内存
    当前头结点并没有具体名称/
  */

   struct Link *p =head;
   // p表的当前指针 ，即当前指针指向的结点是谁
    for( int i=0; i<n; i++) //  根据n 大小创建若干结点并连接
  {
      struct Link * Node=(struct Link*)malloc(sizeof(struct Link));
        printf("输入学号和成绩:\n");
        scanf("%d%d",&Node->num,&Node->score);
        p->next=Node;
        /*
        令当前结构体指针中保存next指针，指向新创建的结点
        即令head的next 指向新创建的结点
        */

        p=p->next;//将循环指针 指向下一个结点；
    }
    p->next=NULL;

    return head->next; // 返回头结点：通过头结点才找到下一个结点 不返回头指针
}

void freeLink(struct Link*head)
{
    struct Link* p= head;
    while(p)
    {
        struct Link * nextNode= p->next;    /**< 先记录当前结点p的下一个结点的地址 */
        free(p);                                                 /**< 释放当前结点 */
        p= nextNode;                                       /**< 将指针移动到下一个地址处 */
    }
}

void displayNode(struct Link* head)
// 从头结点开始遍历并输出整个链表；
{
    struct Link*p=head;// 令p指向第一个结点，遍历整个链表
    while(p) // 只要p 指向地址不为空这说明指向了一个有效的结构体变量，即某个结点
    {
        printf("*---------------------*");
        printf("\n*  学号:%2d  成绩:%2d   \n",p->num,p->score);
        p=p->next;
        //将循环指针p 更新为下一结点的地址
    }
     printf("*---------------------*");
}

void deleteNode(struct Link* head)
 {
    printf("输入要删除数据的学生学号:\n");
    int num;
    scanf("%d",&num );
    struct Link*p=head;
    if(p->next == NULL)//  如果下一个结点为NULL，即当前结点为 尾节点
    {
        printf("目标学号没有找到\n");
        return;
    }
    while(p)// 遍历所有结点
        {                                                                         /**< 要找到删除的结点的上一个结点 */
            if(p->next->num==num)                             /**<如果当前遍历的结点p的下一个结点 :p->next为指定学号   */
            {                                                                     /**< 则当前结点即为要删的结点的上一个结点 */
                                                                                  /**< 当前结点p的下一个结点:p->next 即为要删除的结点*/
                struct Link* deleteNode=p->next;         // 这是要删除的结点
                                                                                   /* 首先需要将删除的结点的地址保存，防止后面无法访问*/
                p->next=p->next->next ;
            // 令当前的结点的下一个结点为要删除的下一个节点，即跳过原来那个要删除的结点
              /*  首先需要找到删除的结点的地址
              如果上面建立了链接 则无法访问要删除的结点
              */
              free(deleteNode);
              printf("成功删除目标学生数据\n");
              return;
            }
        p=p->next;
        p->next=NULL;
        }
 }

 void appendNode(struct Link*head) //末尾追加节点
{
    // 追加新增的学生结点
        struct Link * newNode=(struct Link*)malloc(sizeof(struct Link));
        printf("\n追加学号和成绩:\n");
        scanf("%d%d",&newNode->num,&newNode->score);
        // 追加到链表最后面（尾结点）；

        struct Link *p=head; //先将循环的指针定位到头结点处；
        while(p->next)
        {
            p=p->next;
            // 找到尾结点，只要当前的next不为NULL，持续循环
            // 循环结束，p指向尾结点，p->next=NULL;
        }
        p->next=newNode;
        newNode->next=NULL; //令新的结点作为最新的尾结点；
//       return head;
}

 void insertNode(struct Link *head) // 插入结点
{
        printf("\n输入学号并数据插入该学号后一位:\n");
        int num;
        scanf("%d",&num);
        // 创建插一个新增的学生结点
        struct Link * newNode=(struct Link*)malloc(sizeof(struct Link));
        printf("\n插入学号和成绩:\n");
        scanf("%d%d",&newNode->num,&newNode->score);
        // 插入 到链表中 重点是要找到实际插入的链表位置；
        struct Link * p =head;
        while(p->next)// 只要还没遍历到尾结，就继续向后移动 指针
        {
            if(p->num == num ) // 如果找到了目标结点，新结点就插入此节点之后；
            {
               // p->next=newNode  //只这么写是不行的
               struct Link * nextNode = p->next;//  当前结点的下一个结点的地址；
               p->next=newNode;
               newNode->next = nextNode; // 令新的结点指向指针指向之前保存的的下一结点
                printf("成功将新的数据插入到目标学号后\n");
                return ;
            }
            p=p->next;    //没有找到  就继续移动指针
        }
        p->next=newNode;
        newNode->next=NULL;
        printf("尾结点之前没有找到目标学号，默认将数据追加\n");
}

void modifyNode(struct Link*head)
{
    printf("输入需要更新数据的学生学号:\n");
    int num;
    scanf("%d",&num ); /**< 首先找到需要修改的结点 */
    struct Link*p=head;
    while(p) // 当前结点不为空就继续判断
    {
        if(p->num==num)/**< 如果找到了要修改的学生的学号 */
        {
            printf("请输入修改的成绩:\n");
            scanf("%d",&p->score);
            printf("修改成功:\n");
            return;
        }
        p=p->next;
    }
    /**< 如果没有找到指定学号 */
    printf("目标学号没有找到\n");
}

int main (void)
{
    printf("输入学生数量;\n");
    int n;
    scanf("%d",&n);
    struct Link* head=createList(n);
    // 创建n个检点的链表，并返回头结点的指针；
    int choice;
    while(choice)
    {
        printf("\n输操作编号:\n");
        printf("\t1:打印\t2:删除\t3:插入\t4:追加\t5:更新\t0:退出\n");

        scanf("%d",&choice);
            switch(choice)
        {
            case 0: freeLink(head) ; return 0;

            case 1: printf("\n数据总览:\n"); displayNode(head);   break;

            case 2: deleteNode(head);   printf("\n数据总览:\n"); displayNode(head);     break;

            case 3: insertNode(head);   printf("\n数据总览:\n"); displayNode(head);     break;

            case 4: appendNode(head);  printf("\n数据总览:\n"); displayNode(head);    break;

            case 5: modifyNode(head);  printf("\n数据总览:\n"); displayNode(head);     break;
        }
    }
    putchar('\n');
}
#endif // 0







