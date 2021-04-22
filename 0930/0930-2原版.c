#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node{
    char name[20];
    int score;
    struct Node *next;
}node;

node *new_infor(node *head,int *infor){
    node *current;
    current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    current = current->next;
    current->next = NULL;
    infor++;
    return current;
}

void case2(){

}

void case3(){

}

void case4(){

}

int main(){
    srand(time(NULL));
    node* headptr = NULL, *current, *previous;
    int tmp, flag = 0, i, j, change_score;
    int menu, infor = 0, index;
    char del_name[20], change_name[20];
    while(1)
    {
        printf("\n[1]Insert [2]Delete [3]Change_Score [4]Print [0]End :");
        scanf(" %d", &menu);
        switch(menu)
        {
            case 1:  //資料產生
                if(headptr == NULL){
                    headptr = malloc(sizeof(node));
                    current = headptr;
                    current->next = NULL;
                    infor++;
                }
                else{
                    current = new_infor(headptr,&infor);
//                    current = headptr;
//                    while(current->next != NULL){
//                        current = current->next;
//                    }
//                    current->next = malloc(sizeof(node));
//                    current = current->next;
//                    current->next = NULL;
//                    infor++;
                }
                printf("Insert a name : ");
                scanf("%s", current->name);
                printf("Insert score : ");
                scanf("%d", &current->score);
                break;
            case 2:  //刪除資料
                current = headptr;
                previous = headptr;
                printf("Delete a name : ");
                scanf("%s",del_name);
                for(i = 0; i < infor; i++){
                    if(strcmp(current->name, del_name) == 0){
                        index = i;
                        break;
                    }
                    current = current->next;
                }
                if(index == 0){
                    headptr = headptr->next;
                }
                else{
                    current = headptr;
                    for(i = 0; i < index - 1 ;i++){
                        previous = previous->next;
                    }
                    for(i = 0; i < index + 1; i++){
                        current = current->next;
                    }
                    previous->next = current;
                }
                break;
            case 3:  //更改成績
                current = headptr;
                printf("Change score's name : ");
                scanf("%s", change_name);
                printf("New score : ");
                for(i = 0; i < infor; i++){
                    if( strcmp(current->name, change_name) == 0){
                        scanf("%d", &current->score);
                        break;
                    }
                    current = current->next;
                }
                printf("Name: %s,  Grade: %d\n", current->name, current->score);
                break;
            case 4:  //印出
                current = headptr;
                while(current != NULL){
                    printf("%s(%d) ", current->name, current->score);
                    current = current->next;
                }
                printf("\n");
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

