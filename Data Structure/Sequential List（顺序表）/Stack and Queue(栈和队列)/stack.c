#define maxsize 100
// 栈顺序实现
typedef int datatype;
typedef struct {
    datatype data[maxsize];
    int top;
}stack;
// 初始化
void initstack (stack *s){
    s->top=-1;
}
// 判断栈是否为空
int isempty (stack *s){
    if (s->top ==-1)
    {
        printf("栈为空");
        return 1;
    }
    else
    {
        return 0;
    }
}
// 压栈，e为入栈元素
int push (stack *s ,datatype e){
    if (s->top>=maxsize-1)
    {
        printf("栈满");
        return 0;
    }
    else 
    {
        s->top++;
        s->data[s->top]=e;
        return 1;
    
    }
}
// 出栈
int pop (stack *s,datatype *e){
    if (s->top==-1)
    {
        printf("空栈");
        return 0;
    }
    else
    {   
        *e=s->data[s->top];
        s->top--;
        return 1;
    }
}
// 获取栈顶元素
int gettop (stack *s, datatype *e){
    if (s->top==-1)
    {
        printf("栈空");
        return 0;
    }
    else
    {
        *e=s->data[s->top];
        return 1;
    }
}


