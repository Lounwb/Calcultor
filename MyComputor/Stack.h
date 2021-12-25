#ifndef STACK_H
#define STACK_H
#include"LinkedList.h"

typedef struct Stack{
    //栈底指针
    LinkedListNode *pBase;
    //栈顶指针
    LinkedListNode *pTop;
    //头结点
    LinkedList *pList;
    //栈的大小
    int size;
}Stack;

/**
 * @brief 栈的构造方法，创建一个栈
 * 
 * @return Stack* 返回该栈 
 */
Stack* Stack_Construct(void);

/**
 * @brief 析构栈，释放内存
 * 
 * @param pStack 操作栈
 * @param freeData 内存释放函数
 */
void Stack_DeConstruct(Stack*pStack,void(*freeData)());

/**
 * @brief 压栈
 * 
 * @param pStack 操作栈 
 * @param pData 压入的数据
 */
void Stack_Push(Stack* pStack, void* pData);

/**
 * @brief 判断是否栈空
 * 
 * @param pStack 操作栈
 * @return YesNo 如果为空返回YES，否则返回NO
 */
YesNo Stack_IsEmpty(Stack* pStack);

/**
 * @brief 弹栈
 * 
 * @param pStack 操作栈 
 * @param freeData 内存释放函数
 * @return void* 
 */
void* Stack_Pop(Stack* pStack, void(*freeData)());

/**
 * @brief 获取栈顶数据
 * 
 * @param pStack 操作栈
 * @return void* 返回栈顶数据
 */
void* Stack_Peek(Stack* pStack);

#endif