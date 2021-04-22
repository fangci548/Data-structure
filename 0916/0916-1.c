#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(int n,char a,char b,char c){
    if(n == 1){
        printf("移動套環 %c --> %c\n",a,c);
    }
    else{
        fun(n-1,a,c,b);
        fun(1,a,b,c);
        fun(n-1,b,a,c);
    }
}

int main(){
    int n,sum;
    while(1){
        printf("請輸入圓盤數量 n (n=0 結束):");
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        fun(n,'A','B','C');
        sum = pow(2,n) - 1;
        printf("\n移動次數 %d\n\n",sum);
        printf("-----------------------------------\n");
    }
}
