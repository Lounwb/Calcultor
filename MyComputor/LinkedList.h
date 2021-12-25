#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
typedef struct LinkedListNode{
    void *pData;
    struct LinkedListNode *pNextNode;
} LinkedListNode;

typedef struct LinkedList{
    LinkedListNode *pFirstNode;
    int length;
} LinkedList;


/**
 * @brief 释放内存
 * 
 * @param pData 传入需要释放的内存地址
 */
void freeData(void* pData);

/**
 * @brief 创建节点
 * 
 * @param pData 节点中存储的数据
 * @return LinkedListNode* 返回节点
 */
LinkedListNode *LinkedList_MakeNode(void *pData);

/**
 * @brief 释放节点
 * 
 * @param pNode 传入需要释放的节点
 * @param freeData 释放内存函数
 */
void LinkedList_FreeNode(LinkedListNode *pNode, void (*freeData)());

/**
 * @brief 获取节点上的数据
 * 
 * @param pNode 传入节点
 * @return void* 返回数据
 */
void *LinkedList_GetData(LinkedListNode *pNode);

/**
 * @brief 链表构造方法，创建链表
 * 
 * @return LinkedList* 返回一个链表
 */
LinkedList *LinkedList_Construct(void);

/**
 * @brief 清空链表
 * 
 * @param pList 操作的链表
 * @param freeData 释放内存函数
 */
void LinkedList_Clear(LinkedList *pList, void (*freeData)());

/**
 * @brief 析构链表，释放内存
 * 
 * @param pList 操作链表
 * @param freeData 内存释放函数
 */
void LinkedList_Destruct(LinkedList* pList,void (*freeData)());

/**
 * @brief 在头结点处插入数据
 * 
 * @param pList 操作的链表
 * @param pData 插入的节点的数据
 * @return Status 如果插入成功返回OK，否则返回ERROR
 */
Status LinkedList_InsertAtFront(LinkedList *pList, void *pData);

/**
 * @brief 向链表尾部插入数据
 * 
 * @param pList 操作的链表
 * @param pData 需要插入的数据
 * @return Status 如果插入成功返回OK，否则返回ERROR
 */
Status LinkedList_AppendToEnd(LinkedList *pList, void *pData);

/**
 * @brief 删除头结点
 * 
 * @param pList 操作的链表
 * @param freeData 内存释放函数
 * @return Status 如果插入成功返回OK，否则返回ERROR
 */
Status LinkedList_DeleteFirstNode(LinkedList *pList, void (*freeData)());

/**
 * @brief 删除尾结点
 * 
 * @param pList 操作的链表
 * @param freeData 内存释放函数
 * @return Status 如果插入成功返回OK，否则返回ERROR
 */
Status LinkedList_DeleteLastNode(LinkedList *pList, void (*freeData)());

/**
 * @brief 遍历链表
 * 
 * @param pList 操作的链表
 * @param visit 
 * @return Status 如果插入成功返回OK，否则返回ERROR
 */
Status LinkedList_Traverse(LinkedList *pList, Status (*visit)());
/**
 * @brief 获取链表尾结点
 * 
 * @param pList 操作的链表
 * @return LinkedListNode* 如果链表空返回NULL，反之返回尾结点 
 */
LinkedListNode* LinkedList_GetLastNode(LinkedList *pList);

#endif