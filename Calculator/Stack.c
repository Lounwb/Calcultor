#include"Stack.h"

Stack* Stack_Construct(void){
    Stack *pStack = malloc(sizeof(Stack));
    LinkedList *pList = LinkedList_Construct();
    pStack->pList = pList;
    pStack->pBase = pList->pFirstNode;
    pStack->pTop = NULL;
    pStack->size = 0;
    return pStack;
}
YesNo Stack_IsEmpty(Stack* pStack){
    if(pStack->pBase == pStack->pTop){
        return YES;
    }else{
        return NO;
    }
}
void Stack_Push(Stack* pStack, void* pData){
    LinkedList_AppendToEnd(pStack->pList,pData);
    pStack->pTop = LinkedList_GetLastNode(pStack->pList);
    pStack->size++;
    return;
}
void* Stack_Pop(Stack* pStack, void(*freeData)()){
    void *pData;
    if(pStack->size == 0) {
        return NULL;
    }
    pData = pStack->pTop->pData;
    LinkedListNode *p, *q;
    q = pStack->pList->pFirstNode;
    while(q->pNextNode!=NULL) {
        p = q;
        q = q->pNextNode;
    }
    LinkedList_DeleteLastNode(pStack->pList, freeData);
    pStack->size --;
    pStack->pTop = p;
    return pData;
}
void* Stack_Peek(Stack* pStack){
    if(pStack->size == 0){
        return NULL;
    }
    void* pData;
    pData = pStack->pTop->pData;
    return pData;
}