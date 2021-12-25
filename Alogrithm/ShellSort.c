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
void shellSort(int arr[],int n){
    int h=1;
    while(h<=n/2){
        h=h*2+1;
    }
    while(h>=1){
        for(int i=0;i<n;i++){
            for(int j=i;j>=h;j-=h){
                if(greater(arr[j-h],arr[j])){
                    swap(&arr[j-h],&arr[j]);
                }else break;
            }
        }
        h/=2;
    }   
}
int main(){
    int arr[10];
    int len = sizeof(arr)/sizeof(arr[0]);
    getArray(arr,len);
    printArr(arr,len);
    shellSort(arr,len);
    printArr(arr,len);
    return 0;
}