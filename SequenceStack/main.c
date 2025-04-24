/********************************************
 * File Name : SequenceStack
 *
 * Function  : None
 * Argument  : None
 * Retval    : None
 *
 * Author    : Hrolf
 * Data      : 4/8/2025
 * Note      : None
 *
 * CopyRight (c)      Hrolf     All Right Reseverd
 * @param c
 * @return
 *
 * *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//元素表数据类型用户可以根据实际修改
typedef int DataType_t;

//结构体定义各项参数(顺序栈头地址Top 容量Size 栈底Bottom)
typedef struct SequenceStack
{
    DataType_t * Bottom;//栈底地址
    unsigned int Size;  //栈容量
    int          Top;   //栈顶地址
}SeqStack_t;


//创建顺序栈
SeqStack_t * SeqStack_Create(unsigned int size )
{
    //malloc申请内存放顺序栈
    SeqStack_t *Manager =
            (SeqStack_t * ) calloc(1, sizeof(SeqStack_t));
    if(NULL == Manager){
        perror("calloc SeqQueue Manager failed");
        exit(-2);
    }

    //2申请堆内存完成初始化
    Manager->Bottom =
            (DataType_t *)calloc(size, sizeof(DataType_t));
    if (NULL == Manager->Bottom){
        perror("calloc element memory failed");
        free(Manager);
        exit(-2);   //程序异常终止
    }

    //3管理顺序栈的结构体初始化
    Manager->Size = size;   //顺序表容量
    Manager->Top = -1;     //初始时元素为空,再加入到第一个元素

    return Manager;
}



//首先判断顺序表是否已满
bool SeqStack_IsFull(SeqStack_t * Manager)
{
    return (Manager->Size == Manager->Top + 1) ? true : false;
}


//设计插入元素，从数组尾部，也就是顺序栈顶部Top插入 入栈Push
bool SeqStack_Push(SeqStack_t * Manager , DataType_t Data)
{
    //1首先判断顺序表是否已满
    if (SeqStack_IsFull(Manager)){
        printf("SequenceStack is full\n");
        return false;
    }

    //有空闲空间,插入顺序栈的栈顶
    //*(Manager->Top + Manager->Bottom) = Data;
    //Manager->Bottom += 1;
    Manager->Bottom[++Manager->Top] = Data;
    return true;
}


//判断顺序栈是否为空
bool SeqStack_IsEmpty(SeqStack_t * Manager)
{
    return (-1 == Manager->Top) ? true : false;
}



//从栈顶删除  顺序栈 出栈Pop
DataType_t SeqStack_Pop(SeqStack_t * Manager)
{
    //1temp存储出栈的值
    DataType_t temp = -1;
    //2判断是否为空
    if (SeqStack_IsEmpty(Manager)){
        printf("SequenceStack is Empty\n");
        return temp;
    }

    //3非空,先赋值，再Top-1
    temp = Manager->Bottom[Manager->Top--];
    return temp;
}



//遍历顺序栈中的元素
void SeqStack_Print(SeqStack_t * Manager)
{
    //判断顺序栈只能是否为空
    if (Manager == NULL) {
        printf("Manager pointer is NULL\n");
        return;
    }
    if (SeqStack_IsEmpty(Manager)) {
        printf("The Sequence Stack Is Empty\n");
        return;
    }
    for (int i = Manager->Top; i >=0 ;--i) {
        printf("  %d",Manager->Bottom[i]);
    }
    printf("\n");
}


int main(void)
{
    printf("/*********************************************************/\n");

    //1创建时顺序栈
    printf("*****Make a Sequence Stack and allocate memory(10)\n");
    SeqStack_t * Manager = SeqStack_Create(10);


    //2入栈
    printf("******Push Stack\n");
    SeqStack_Push(Manager, 2);
    SeqStack_Push(Manager, 5);
    SeqStack_Push(Manager, 12);
    SeqStack_Push(Manager, 1);
    SeqStack_Push(Manager, 0);
    SeqStack_Push(Manager, 20);
    SeqStack_Push(Manager, 8);
    SeqStack_Push(Manager, 3);
    printf("******Expecting Order: 3 8 20 0 1 12 5 2\n");
    SeqStack_Print(Manager);

    SeqStack_Push(Manager, 1212);
    SeqStack_Push(Manager, 7);
    printf("******Expecting Order: 7 1212 3 8 20 0 1 12 5 2\n");
    SeqStack_Print(Manager);

    printf("******Expecting Output:The Sequence Stack IS Already Full\n");
    SeqStack_Push(Manager, 996);
    printf("******Expecting Order: 7 1212 3 8 20 0 1 12 5 2\n");
    SeqStack_Print(Manager);
    printf("\n");


    //出栈
    printf("******Pop Stack\n");

    SeqStack_Pop(Manager);
    SeqStack_Pop(Manager);
    SeqStack_Pop(Manager);
    printf("******Expecting Order: 8 20 0 1 12 5 2\n");
    SeqStack_Print(Manager);

    SeqStack_Pop(Manager);
    printf("******Expecting Order:  20 0 1 12 5 2\n");
    SeqStack_Print(Manager);

    SeqStack_Pop(Manager);
    printf("******Expecting Order:  0 1 12 5 2\n");
    SeqStack_Print(Manager);

    SeqStack_Pop(Manager);
    printf("******Expecting Order:  1 12 5 2\n");
    SeqStack_Print(Manager);

    SeqStack_Pop(Manager);
    SeqStack_Pop(Manager);
    SeqStack_Pop(Manager);
    SeqStack_Pop(Manager);
    printf("******Excepting Output: Sequence Stack Is Empty\n");
    SeqStack_Pop(Manager);
    printf("******Excepting Output: Sequence Stack Is Empty\n");
    SeqStack_Print(Manager);

    printf("\n");
    SeqStack_Push(Manager, -4);
    SeqStack_Print(Manager);
    printf("\n");
    printf("Hello, World!\n");
    return 0;
}