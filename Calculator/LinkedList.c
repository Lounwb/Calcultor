#include"LinkedList.h"

void freeData(void* pData) {
        pData = NULL;
}
LinkedListNode *LinkedList_MakeNode(void *pData){
    LinkedListNode *pNode;
    pNode = malloc(sizeof(LinkedListNode));
    if (pNode == NULL){
        return NULL;
    }else{
        pNode->pData = pData;
        pNode->pNextNode = NULL;
        return pNode;
    }
}
void LinkedList_FreeNode(LinkedListNode *pNode, void (*freeData)()){
    if (pNode != NULL){
        freeData(pNode->pData);
    }
    free(pNode);
    return;
}

void *LinkedList_GetData(LinkedListNode *pNode){
    return pNode->pData;
}
LinkedList *LinkedList_Construct(void){
    LinkedList *pList = malloc(sizeof(LinkedList));
    if (pList == NULL){
        return NULL;
    }
    pList->pFirstNode = NULL;
    pList->length = 0;
    return pList;
}
void LinkedList_Clear(LinkedList *pList,void (*freeData)()){
    LinkedListNode *pCurrentNode, *pNextNode;
    pCurrentNode = pList->pFirstNode;
    while (pCurrentNode != NULL){
        pNextNode = pCurrentNode->pNextNode;
        LinkedList_FreeNode(pCurrentNode, freeData);
        pCurrentNode = pNextNode;
    }
    pList->pFirstNode = NULL;
    pList->length = 0;
    return;
}
int LinkedList_Length(LinkedList *pList){
    return pList->length;
}
YesNo LinkedList_IsEmpty(LinkedList *pList){
    if (pList->length == 0){
        return YES;
    }else{
        return NO;
    }
}
Status LinkedList_InsertAtFront(LinkedList *pList,void *pData){
    LinkedListNode *pNewNode;
    pNewNode = LinkedList_MakeNode(pData);
    if (pNewNode == NULL){
        return ERROR;
    }
    pNewNode->pNextNode = pList->pFirstNode;
    pList->pFirstNode = pNewNode;
    pList->length++;
    return OK;
}
Status LinkedList_AppendToEnd(LinkedList *pList,void *pData){
    LinkedListNode *pNewNode, *pTail;
    pNewNode = LinkedList_MakeNode(pData);
    if (pNewNode == NULL){
        return ERROR;
    }
    if (pList->pFirstNode == NULL){
        pList->pFirstNode = pNewNode;
    }else{
        pTail = pList->pFirstNode;
        while (pTail->pNextNode != NULL){
            pTail = pTail->pNextNode;
        }
        pTail->pNextNode = pNewNode;
    }
    pList->length++;
    return OK;
}
Status LinkedList_DeleteFirstNode(LinkedList *pList,void (*freeData)()){
    LinkedListNode *pTempNode;
    if (pList->length == 0){
        return ERROR;
    }
    pTempNode = pList->pFirstNode;
    pList->pFirstNode = pTempNode->pNextNode;
    LinkedList_FreeNode(pTempNode, freeData);
    pTempNode = NULL;
    pList->length--;
    return OK;
}
Status LinkedList_DeleteLastNode(LinkedList *pList,void (*freeData)()){
    LinkedListNode *p, *q;
    if (pList->length == 0){
        return ERROR;
    }
    q = pList->pFirstNode;
    if (q->pNextNode == NULL){
        return LinkedList_DeleteFirstNode(pList,
                                          freeData);
    }
    while (q->pNextNode != NULL){
        p = q;
        q = q->pNextNode;
    }
    p->pNextNode = NULL;
    LinkedList_FreeNode(q, freeData);
    q = NULL;
    pList->length--;
    return OK;
}
Status LinkedList_Traverse(LinkedList *pList,Status (*visit)()){
    LinkedListNode *pTempNode;
    pTempNode = pList->pFirstNode;
    while (pTempNode != NULL){
        if (visit(pTempNode->pData) == ERROR){
            return ERROR;
        }
        pTempNode = pTempNode->pNextNode;
    }
    return OK;
}
LinkedListNode* LinkedList_GetLastNode(LinkedList *pList){
    if(pList->length == 0){
        return NULL;
    }
    LinkedListNode *pNode = pList->pFirstNode;
    while(pNode->pNextNode != NULL){
        pNode = pNode->pNextNode;
    }
    return pNode;
}