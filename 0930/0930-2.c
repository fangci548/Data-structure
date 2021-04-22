#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[20];
    int score;
    struct Node *next;
}node;

node *new_infor(node **head,int *infor){
    node *current;
    current = *head;
    if(*head == NULL){
        *head = malloc(sizeof(node));
        current = *head;
        current->next = NULL;
        *infor+=1;
    }
    else{
        current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = malloc(sizeof(node));
        current = current->next;
        current->next = NULL;
        *infor+=1;
    }
    return current;
}

void delete_name(node **head,int infor){
    node *current;
    node *previous;
    node *tmp;
    int i, index;
    char del[20];
    current = *head;
    previous = *head;
    printf("Delete a name : ");
    scanf("%s",del);
    for(i = 0; i < infor; i++){
        if(strcmp(current->name, del) == 0){
            index = i;
            break;
        }
        current = current->next;
    }
    if(index == 0){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else{
        current = *head;
        for(i = 0; i < index - 1 ;i++){
            previous = previous->next;
        }
        for(i = 0; i < index + 1; i++){
            current = current->next;
        }
        tmp = previous->next;
        previous->next = current;
        free(tmp);
    }
}

node *change_name(node *head,int infor){
    node *current;
    current = head;
    int i;
    char change[20];
    printf("Change score's name : ");
    scanf("%s", change);
    printf("New score : ");
    for(i = 0; i < infor; i++){
        if( strcmp(current->name, change) == 0){
            scanf("%d", &current->score);
            break;
        }
        current = current->next;
    }
    return current;
}


int main(){
    node* headptr = NULL, *current, *previous;
    int tmp, flag = 0, i, j, change_score;
    int menu, infor = 0, index;
    while(1)
    {
        printf("\n[1]Insert [2]Delete [3]Change_Score [4]Print [0]End :");
        scanf(" %d", &menu);
        switch(menu)
        {
            case 1:  //資料產生
                current = new_infor(&headptr,&infor);
                printf("Insert a name : ");
                scanf("%s", current->name);
                printf("Insert score : ");
                scanf("%d", &current->score);
                break;
            case 2:  //刪除資料
                delete_name(&headptr,infor);
                break;
            case 3:  //更改成績
                current = change_name(headptr,infor);
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

