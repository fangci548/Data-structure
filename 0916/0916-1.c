#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(int n,char a,char b,char c){
    if(n == 1){
        printf("���ʮM�� %c --> %c\n",a,c);
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
        printf("�п�J��L�ƶq n (n=0 ����):");
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        fun(n,'A','B','C');
        sum = pow(2,n) - 1;
        printf("\n���ʦ��� %d\n\n",sum);
        printf("-----------------------------------\n");
    }
}
