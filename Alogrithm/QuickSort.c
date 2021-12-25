#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int *assist;
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
int greater(int v,int w){
    if(v>=w){
        return 1;
    }
    return 0;
}
void swap(int arr[],int v,int w){
    int temp = arr[v];
    arr[v] = arr[w];
    arr[w] = temp;
}
int partition(int arr[],int n,int lo,int hi){
    int key = arr[lo];
    int left = lo;
    int right = hi+1;
    while(1){
        //先从右往左
        while(greater(arr[--right],key)){
            if(right==lo){
                break;
            }
        }
        while(greater(key,arr[++left])){
            if(left==hi){
                break;
            }
        }
        if(left>=right){
            break;
        }else{
            swap(arr,left,right);
        }
    }
    swap(arr,lo,right);

    return right;
}
void quickSortAssist(int arr[],int n,int lo,int hi){
    if(hi<=lo){
        return;
    }
    int part = partition(arr,n,lo,hi);

    quickSortAssist(arr,n,lo,part-1);
    quickSortAssist(arr,n,part+1,hi);

}
void quickSort(int arr[],int n){
    int lo=0;
    int hi=n-1;
    
    quickSortAssist(arr,n,lo,hi);
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    quickSort(arr,len);
    printArr(arr,len);
    return 0;
}