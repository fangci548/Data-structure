#include <stdio.h>
#include <string.h>

int calculator(char ope, int a, int b){
    switch(ope){
        case '*':
            return a * b;
            break;
        case '%':
            return a % b;
            break;
        case '/':
            return a / b;
            break;
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
    }
}

int main(){
    FILE *fp = fopen("input_1.txt","r");
    if(fp == NULL){
        printf("NO!!!!!\n");
    }
    char input[20], ope[20];
    int i, ope_now = 0;
    while(fscanf(fp, "%s", input) != EOF){
        int add[20];
        int now = 0, tmp_ans;
        ope_now = 0;
        int flag = 0;
        int count = 0;
        char tmp;
        char ans[30];
        int ans_now = 0;
        for(i = 0; i < strlen(input); i++){
            //printf("%c  ",input[i]);
            if(input[i] == '+' || input[i] == '-'){
                ope[ope_now] = input[i];
                if(flag == 1){
                    count--;
                }
                if(ope[ope_now - 1] == '*' || ope[ope_now - 1] == '/' || ope[ope_now - 1] == '%'){
                    ans[ans_now] = '(';
                    flag = 1;
                    count = 0;
                    ans_now++;
                }
                if((input[i + 1] - 48 <= 9 && input[i + 1] - 48 >= 0) && (input[i + 2] - 48 <= 9 && input[i + 2] - 48 >= 0) && flag == 0){
                    ans[ans_now++] = '(';
                    flag = 1;
                    count = 0;
                }
                ope_now++;
            }
            else if(input[i] == '*' || input[i] == '/' || input[i] == '%'){
                ope[ope_now] = input[i];
                ope_now++;
                if(flag == 0 && (input[i + 1] - 48 <= 9 && input[i + 1] - 48 >= 0) && (input[i + 2] - 48 <= 9 && input[i + 2] - 48 >= 0)){
                    ans[ans_now++] = '(';
                    flag = 1;
                    //printf("i = %d 123 ", i);
                    count = 1;
                }
                if(flag == 1){
                    count--;
                }
            }
            else{
                ans[ans_now] = input[i];
//                if((input[i + 1] - 48 <= 9 || input[i + 1] - 48 >= 0) && (input[i + 2] - 48 <= 9 || input[i + 2] - 48 >= 0)){
//                    ans[ans_now++] = '(';
//                    flag = 1;
//                    count = 0;
//                }
                if(flag == 1){
                    count++;
                }
                if(count == 2){
                    ans[++ans_now] = ')';
                    flag = 0;
                    count = -1;
                }
                ans[++ans_now] = ope[--ope_now];
                ans_now++;
                if(input[i + 1] == '*' || input[i + 1] == '/' || input[i + 1] == '%' || input[i + 1] == '+' || input[i + 1] == '-'){
                    //printf("qwer");
                    tmp = ope[ope_now];
                    if((input[i + 1] == '+' || input[i + 1] == '-') && (tmp == '*' || tmp == '%' || tmp == '/')){
                        ans[ans_now] = '(';
                        flag = 1;
                        count = 1;
                        ans_now++;
                    }
                }
            }
        }
        printf("輸入前置式: %s\n",input);
        printf("輸出中置式: ");
        for(i = 0; i < ans_now; i++){
            printf("%c",ans[i]);
        }
        printf("\n");



        for(i = strlen(input) - 1; i >= 0; i--){
            if((input[i] - 48) >= 0 && (input[i] - 48) <= 9){
                add[now++] = input[i] - 48;
            }
            else{
                tmp_ans = calculator(input[i], add[now - 1], add[now - 2]);
                add[now - 2] = tmp_ans;
                now--;
            }
        }
        printf("值: %d\n\n",add[0]);
        printf("------------------------------------------\n");

    }
}
