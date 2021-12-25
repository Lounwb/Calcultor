#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int *assist;
void merge(int arr[],int n,int lo,int mid,int hi){
    int i=lo;
    int p1=lo;
    int p2=mid+1;
    while(p1<=mid && p2<=hi){
        if(greater(arr[p1],arr[p2])){
            assist[i++] = arr[p2++];
        }else{
            assist[i++] = arr[p1++];
        }
    }
    while(p1<=mid){
        assist[i++] = arr[p1++];
    }
    while(p2<=hi){
        assist[i++] = arr[p2++];
    }
    for(int index=lo;index<=hi;index++){
        arr[index] = assist[index];
    }
}
void mergeSortAssist(int arr[],int n,int lo,int hi){
    if(hi<=lo){
        return;
    }
    int mid =(lo+hi)/2;

    mergeSortAssist(arr,n,lo,mid);
    mergeSortAssist(arr,n,mid+1,hi);

    merge(arr,n,lo,mid,hi);
}
void mergeSort(int arr[],int n){
    assist = malloc(n*sizeof(int));
    int lo=0;
    int hi = n-1;
    mergeSortAssist(arr,n,lo,hi);
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    mergeSort(arr,len);
    printArr(arr,len);
    int index = binarySearch(arr,len,30);
    printf("%d",index);
    return 0;
}