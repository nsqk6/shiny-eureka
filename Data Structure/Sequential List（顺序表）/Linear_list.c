// maxnum代表最多的元素个数，也就是线性表最多可以有多少个元素
#define maxnum 100
// 将int类型取别名为datatype，便于代码维护
typedef int datatype;
// 声明线性表这个结构体，取别名为list,num代表元素个数
typedef struct {
    datatype data[maxnum];
    int num;
}list;
// 初始化
void initlist(list * l){
    l->num=0;
}
// 在尾部添加元素,e为要添加的元素
int append (list *l,datatype e){
    if (l->num=maxnum)
    {
        printf("线性表已满，无法继续添加元素");
        return 0;
    }
    l->data[l->num]=e;
    l->num++;
    return 1;
}
// 遍历
void traverse(list * l){
    if(l->num=0)
    {
        printf("线性表为空，无法遍历");
    }
    for (int i=0;i<l->num;i++)
    {
        printf("%d",l->data[i]);
    }
        printf("\n");
}
// 插入元素 pos代表插入元素下标，e为要插入的元素
int  insert(list *l,int pos,datatype e)
{   
    // 线性表满了
    if(l->num=maxnum)
    {
        return 0;
    }
    // 下标非法
    if (pos<0||pos>l->num)
    {
        return 0;
    }
    if (pos<=l->num-1)
    {
        for (int i=l->num-1;i>=pos-1;i--)
        {
            l->data[i+1]=l->data[i];
        }
        l->data[pos]=e;
        l->num++;
        return 1;
    }
}
// 删除元素，pos为要删除元素的下标
int del (list *l,int pos)
{
// 下标非法
    if(pos<0||pos>=l->num)
    {
        return 0;
    }
    if (pos<=l->num-1)
    {
        for(int i=pos;i<=l->num-1;i++)
        {
            l->data[i]=l->data[i+1];
        }
        l->num--;
        return 1;
    }
}
// 查找，e为被查找的元素,找到后返回元素下标
int check(list *l,datatype e)
{   if(l->num==0)
    {
        return 0;
    }
    for (int i=0;i<l->num;i++)
    {
        if(l->data[i]==e)
        {
            return i;
        }
    }
    return -1;
}
