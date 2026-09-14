typedef int datatype;
typedef struct{
    datatype data;
    struct stack *next;
}stack;
// 初始化
stack* initstack(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->data=0;
    s->next=NULL;
    return s;
}
// 判断栈是否为空
int isempty(stack *s){
    if(s->next==NULL)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
// 进栈，s为头节点地址，e为插入元素
int push(stack *s, datatype e){
    stack *p =(stack *)malloc(sizeof(stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
// 出栈,s为头节点地址
int pop (stack *s,datatype *e){
    if (s->next==NULL)
    {
        printf("栈空\n");
        return 0;
    }
    *e= s->next->data;
    stack *q=s->next;
    s->next=q->next;
    free(q);
    return 1;
}
// 获取栈顶元素
int gettop (stack *s,datatype *e){
     if (s->next==NULL)
    {
        printf("栈空\n");
        return 0;
    }
    *e =s->next->data;
    return 1;
}



























