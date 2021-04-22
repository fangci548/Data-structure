#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int isFull(int *top){ // 堆疊是否已滿
    if(*top == 9){
        printf("Stack is full！\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

int isEmpty(int *top){ //堆疊是否為空
    if(*top == -1){
         printf("Stack is empty！\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

void push(int num[MAX], int tmp, int *top){ //將item放在stack頂端 若堆疊已滿則顯示堆疊已滿，且不增加
    int full;
    full = isFull(top);
    if(full == 0){
        *top += 1;
        num[*top] = tmp;
    }
}

void pop(int *top, int num[MAX]){ //移除並回傳堆疊頂端的元素 若堆疊為空則顯示堆疊已空，且不移除
    int empty,del;
    empty = isEmpty(top);
    if(empty == 0){
        del =  num[*top];
        *top -= 1;
        printf("%d is deleted\n", del);
    }
}

int main(){
    int menu, i;
    int num[MAX], tmp_num, top;
    top = -1;
    while(1)
    {
        printf("\n[1]insert [2]delete [3]show [0]exit： ");
        scanf(" %d",&menu);
        switch(menu)
        {
            case 1:  //新增
                printf("insert a number：");
                scanf("%d", &tmp_num);
                push(num, tmp_num, &top);
                break;
            case 2:  //刪除
                pop(&top, num);
                break;
            case 3:  //顯示
                if(top == -1){
                    printf("Stack is empty！\n");
                }
                for(i = top; i >= 0; i--){
                    printf("%d ", num[i]);
                }
                break;
            case 0:  //結束程式執行
                printf("Exit!\n");
                exit(1);
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
}
