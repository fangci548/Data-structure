#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char num1[10],num2[10];
    int i,carry = 0,sum = 0;
    FILE* fp_r = fopen("input_2.txt","r");
    if(fp_r == NULL){
        printf("開檔錯誤!");
    }
    while(fscanf(fp_r ,"%s %s",num1,num2) != EOF){
        sum = 0;
        carry = 0;
        for(i = strlen(num1);i >= 0;i--){
            if(carry + (num1[i] - 48) +  (num2[i] - 48) > 9){
                sum++;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        printf("%-27d共%d次進位\n",atoi(num1) + atoi(num2),sum);
    }
    fclose(fp_r);
}
