#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char change(char input[20]){
    for(int i = 0;i < strlen(input);i++){
        if(input[i] < 123 && input[i] > 96){
            input[i] = input[i] - 32;
        }
    }
}
int main(){
    char input[100][20],tmp[20];
    int i,now = 0,j,sum = 0;
    FILE* fp_r = fopen("input_1.txt","r");
    FILE* fp_w = fopen("output.txt","w");
    if(fp_r == NULL || fp_w == NULL){
        printf("開檔錯誤!");
    }
    while(fscanf(fp_r , "%s" ,tmp) != EOF){
        change(tmp);
        strcpy(input[now],tmp);
        now++;
    }
    for(i = 0;i < now;i++){
        for(j = 0;j < now - i;j++){
            if(strcmp(input[j+1],input[j]) < 0){
                strcpy(tmp,input[j+1]);
                strcpy(input[j+1],input[j]);
                strcpy(input[j],tmp);
            }
        }
    }
    for(i = 0;i < now;i++){
        fprintf(fp_w, "%s\n", input[i]);
    }
    printf("單字                     出現次數\n------------------------------------\n");
    for(i = 0;i < now;i++){
        sum = 1;
        if(strcmp(input[i],input[i+1]) == 0){
            sum++;
            printf("%-27s%d\n",input[i],sum);
            i++;
        }
        else{
            printf("%-27s%d\n",input[i],sum);
        }
    }
    fclose(fp_r);
    fclose(fp_w);

}
