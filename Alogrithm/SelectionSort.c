#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void getArray(int arr[],int n){
    unsigned sr = time(NULL);
    srand(sr);
    for (int i = 0; i < n; i++){
        arr[i] = 24+rand()%10;
    }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void swap(int* v,int *w){
    int temp = *v;
    *v = *w;
    *w = temp;
    return;
}
int greater(int v,int w){
    if(v>=w){
        return 1;
    }
    return 0;
}
int getMinValueIndex(int arr[],int n,int index){
    int target = -1;
    int min = arr[index];
    for(int i=index;i<n;i++){
        if(min>=arr[i]){
            min = arr[i];
            target = i;
        }
    }
    return target;
}
void selectionSort(int arr[],int n){
    int minValueIndex =0;
    for(int i=0;i<n;i++){
        minValueIndex = getMinValueIndex(arr,n,i);
        swap(&arr[i],&arr[minValueIndex]);
    }
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    selectionSort(arr,len);
    printArr(arr,len);
    return 0;
}