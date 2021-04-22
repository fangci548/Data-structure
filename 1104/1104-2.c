#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int isFull(int *rear, int *front){ // ��C�O�_�w��
    if(*rear + 1 == *front || (*rear == MAX - 1 && *front == 0)){
        printf("Queue is full�I\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

int isEmpty(int *rear, int *front){ //��C�O�_����
    if(*rear == *front){
         printf("Queue is empty�I\n\n");
        return -1;
    }
    else{
        return 0;
    }
}

void add(int num[MAX], int tmp, int *front, int *rear, int *now){
    int full;
    full = isFull(rear, front);
    if(full == 0){
        *rear += 1;
        *rear = *rear % 10;
        num[*rear] = tmp;
        *now += 1;
    }
}

void del(int *front, int *rear, int num[MAX], int *now){
    int empty,del;
    empty = isEmpty(rear, front);
    if(empty == 0){
        *front += 1;
        *front = *front % 10;
        *now -= 1;
        printf("%d is deleted\n", num[*front]);
    }
}

int main(){
    int menu, i, tmp_num;
    int num[MAX], front = 0, rear = 0, now = 0;
    while(1)
    {
        printf("\n[1]insert [2]delete [3]show [0]exit�G ");
        scanf(" %d",&menu);
        switch(menu)
        {
            case 1:  //�s�W
                printf("insert a number�G");
                scanf("%d", &tmp_num);
                add(num, tmp_num, &front, &rear, &now);
                break;
            case 2:  //�R��
                del(&front, &rear, num, &now);
                break;
            case 3:  //���
                if(now == 0){
                    printf("Queue is empty�I\n");
                }
                else{
                    for(i = 1; i <= now; i++){
                        printf("%d ", num[(front + i) % 10]);
                    }
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
