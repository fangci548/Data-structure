#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int main(){
    FILE *fp = fopen("input_2.txt","r");
    if(fp != NULL){
        printf("File read success\n\n");
        printf("----------------------------\n");
    }
    char input[20];
    while(fscanf(fp, "%s", input) != EOF){
        int error = -1;
        int bracket = 0;
        int bracketfirst = 0;
        int ope = 0;
        int num = 0;
        int i;
        for(i = 0; i < strlen(input); i++){
            if(input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || (input[i] - 48 <= 9 && input[i] - 48 >= 0)){
                if(input[i] - 48 <= 9 && input[i] - 48 >= 0){
                    num++;
                }
                else{
                    ope++;
                }
            }
            else if(input[i] == '^'){
                if(input[i - 1] - 48 <= 9 && input[i - 1] - 48 >= 0){
                    if(input[i + 1] - 48 <= 9 && input[i + 1] - 48 >=0){
                        num--;
                    }
                    else{
                        if(error >= 2 || error == -1){
                            error = 2;
                        }
                    }
                }
                else{
                    if(error >= 2 || error == -1){
                        error = 2;
                    }
                }
            }
            else if(input[i] == '('){
                bracketfirst = 1;
                bracket++;
            }
            else if(input[i] == ')'){
                if(bracketfirst == 0 && (error >= 3 || error == -1)){ //先出現後括號
                    error = 3;
                }
                else{
                    bracketfirst = 0;
                    bracket--;
                }
            }
            else{ //非法字元
                if(error == -1 || error > 1){
                    error = 1;
                    break;
                }
            }
        }
        if(num - ope != 1 && (error >= 2 || error == -1)){
            error = 2;
        }
        if(bracket != 0 && (error >= 3 || error == -1)){
            error = 3;
        }
        printf("%-10s", input);
        switch(error){
            case -1:
                printf("Pass\n");
                break;
            case 1:
                printf("Fail：Symbol of operation errors\n");
                break;
            case 2:
                printf("Fail：The number of symbol errors\n");
                break;
            case 3:
                printf("Fail：Parentheses errors\n");
                break;
        }
    }
    printf("\n----------------------------\n");
    printf("finish\n");
}

