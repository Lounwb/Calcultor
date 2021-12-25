#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void getArray(int arr[],int n){
    unsigned sr = time(NULL);
    srand(sr);
    for (int i = 0; i < n; i++){
        arr[i] = rand()%10;
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


void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(greater(arr[j],arr[i])){
                swap(&arr[j],&arr[i]);
            }
        }
    }
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    bubbleSort(arr,len);
    printArr(arr,len);
    return 0;
}