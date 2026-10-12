#include <stdio.h>                 //标准输入输出头文件
#define MAXNUM 100                 //顺序表最大容量，和课本一致
typedef int DataType;              //DataType改成int，存放整数

//课本P32原版顺序表结构
struct SeqList{
    int n;                         //当前有效元素个数
    DataType element[MAXNUM];      //存储元素的数组
};

//课本算法2.1：初始化空顺序表
void InitList(struct SeqList *L)
{
    L->n = 0;                      //空表元素个数n=0
}

//尾插函数Append：在表的尾部添加新元素
int Append(struct SeqList *L, DataType x)
{
    if(L->n >= MAXNUM)             //判满：n到达最大容量，不能插入
        return 0;                  //返回0代表插入失败
    L->element[L->n] = x;         //空位下标就是n，放入新元素
    L->n = L->n + 1;              //有效元素个数加1
    return 1;                      //返回1代表插入成功
}

//遍历、打印顺序表全部有效元素
void PrintList(struct SeqList *L)
{
    int i;                         //循环变量
    printf("顺序表元素：");
    for(i = 0; i < L->n; i++)      //只打印0 ~ n?1的有效元素，不要遍历MAXNUM
    {
        printf("%d ", L->element[i]);
    }
    printf("\n");
}

int main()
{
    struct SeqList L;              //定义顺序表L
    InitList(&L);                   //初始化空顺序表
    Append(&L,12);                  //尾插12
    Append(&L,35);                  //尾插35
    Append(&L,8);                   //尾插8
    Append(&L,41);                  //尾插41
    Append(&L,22);                  //尾插22
    PrintList(&L);                  //输出整个顺序表
    return 0;
}
