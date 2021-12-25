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
int binarySearch(int arr[],int n,int target){
    int begin =0;
    int end =n-1;
    int mid =0;
    while(begin<=end){
        mid = (begin+end)/2;
        if(arr[mid] < target){
            begin =mid+1;
        }else if(arr[mid] > target){
            end = mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    return 0;
}