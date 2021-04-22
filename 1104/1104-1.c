#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int isFull(int *top){ // ���|�O�_�w��
    if(*top == 9){
        printf("Stack is full�I\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

int isEmpty(int *top){ //���|�O�_����
    if(*top == -1){
         printf("Stack is empty�I\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

void push(int num[MAX], int tmp, int *top){ //�Nitem��bstack���� �Y���|�w���h��ܰ��|�w���A�B���W�[
    int full;
    full = isFull(top);
    if(full == 0){
        *top += 1;
        num[*top] = tmp;
    }
}

void pop(int *top, int num[MAX]){ //�����æ^�ǰ��|���ݪ����� �Y���|���ūh��ܰ��|�w�šA�B������
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
        printf("\n[1]insert [2]delete [3]show [0]exit�G ");
        scanf(" %d",&menu);
        switch(menu)
        {
            case 1:  //�s�W
                printf("insert a number�G");
                scanf("%d", &tmp_num);
                push(num, tmp_num, &top);
                break;
            case 2:  //�R��
                pop(&top, num);
                break;
            case 3:  //���
                if(top == -1){
                    printf("Stack is empty�I\n");
                }
                for(i = top; i >= 0; i--){
                    printf("%d ", num[i]);
                }
                break;
            case 0:  //�����{������
                printf("Exit!\n");
                exit(1);
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
}
