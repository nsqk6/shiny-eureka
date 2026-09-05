// 链表当中的数据元素称为节点，节点包含两个域，一个是数据域（存储数据信息），另一个是指针域（存储直接后继位置）
// 链表声明
typedef int datatype;
typedef struct {
    datatype data;//数据域
    struct node *next;//指针域，下一个节点的内存地址
}node;
// 初始化
#include <stdlib.h>
node* initlist()
{
    node *head=(node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
} 
// 单链表，头插法；e为插入的元素,l为头节点地址;
void inserthead(node*l,datatype e)
{   node *p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=l->next;
    l->next=p;
}
// 遍历，l为头节点地址
void listnode(node *l)
{   node *p=l->next;
    while(p !=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
// 尾插法，l为头节点地址，先找到尾部再插入
node* inserttail(node *l,datatype e)
{   node *p=l;
    while(p->next != NULL)
    {
        p=p->next;
    }
    // 组后循环跳出，p必然为尾节点地址
        node *q=(node*)malloc(sizeof(node));
        q->data=e;
        p->next=q;
        q->next=NULL;
        return q;
}
// 在指定位置插入数据,l为头节点地址，e为插入的数据，pos为插入的位置
int insertpos (node *l ,datatype e ,int pos)
{   node *p = l;
    int i = 0;
    if (pos<1)
    {
        return 0;
    }
    while (i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
        node *q=(node*)malloc(sizeof(node));
        q->data=e;
        q->next=p->next;
        p->next=q;
        return 1;
}
//删除指定位置的节点,l为头节点地址，pos为要删除的节点的位置
int deletenode (node *l ,int pos)
{   node *p=l;
    int i=0;
    if (pos<1)
    {
        return 0;
    }
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
    if(p->next=NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    node *q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}
// 获取链表长度，len为链表长度，l为头节点地址;
int getlen (node *l)
{
    node *p=l;
    int len=0;
    while(p->next != NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
// 释放链表，头节点不释放,l为头节点地址；
int freenode (node *l)
{   node *p=l->next;
    node *q;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    l->next=NULL;
}