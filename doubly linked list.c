
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *prev,*next;
}node;
// 头插法,l为头节点地址，e为要插入的元素
int inserthead (node *l,datatype e){
    node *p=(node *)malloc(sizeof(node));
    p->data=e;
    p->prev=l;
    p->next=l->next;
    if(l->next != NULL)
    {
        l->next->prev=p;
    }
        l->next=p;
        return 1;
}
// 遍历，l为头节点地址
void listnode(node *l){
    node *p=l;
    while(p->next!= NULL)
    {
        p=p->next;
    }
    printf('\n');

}
// 尾插法，先找到尾节点,再插入，l为头节点地址，e为插入元素
int inserttail(node *l, datatype e){
    node *p=l;
    while(p->next !=NULL)
    {
        p=p->next;
    }
        // 循环结束，p必然为尾节点；
        node *q = (node*)malloc(sizeof(node));
        q->data=e;
        q->prev=p;
        p->next=q;
        q->next=NULL;
}
// 指定位置插入，l为头节点地址，pos为要插入的位置，e为要插入的数据
int insertpos (node *l,int pos,datatype e){
    // 先找插入位置的前一个位置
    node *p=l;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
     node *q = (node*)malloc(sizeof(node));
     q->data=e;
     q->prev=p;
     q->next=p->next;
     p->next=q;
     p->next->prev=q;
     return 1;
}
// 删除节点，l为头节点地址，pos为要删除的节点的位置
int deletenode (node *l,int pos){
    if(pos<=0)
    {
        return 0;
    }
    node *p=l;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
    node *q=p->next;
    if(q==NULL)
    {
        return 0;
    }
    p->next=q->next;
    if(q->next != NULL){ // 不是尾节点才修改后继的prev
        q->next->prev = p;
    }
    free(q);
    return 1;
}
