#include<stdio.h>
#include<math.h>
int factor(int num){
    if(num ==1){
        return 1;
    }

    return num*factor(num-1);
}
double sinTaylorRemainder(double num,int i){
    return pow(-1,i+1)*pow(num,2*i-1)/factor(2*i-1);
}
double sin(double num){
    double result =0,remainder=0;
    int i=1;
    //精度为10^-5
    while(fabs(remainder=sinTaylorRemainder(num,i++)) > 10e-5){
        result+=remainder;
    }
    return result;
    
}
int main(){
    double result = sin(1.570796);
    printf("%lf",result);
}