#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node{
    int num;
    struct Node *next;
}node;


int main(){
    srand(time(NULL));
    node* headptr = NULL, *tmpptr, *nowptr;
    int randnum[10], tmp, flag = 0, i, j;
    int a;

    tmpptr = malloc(sizeof(node));
    for(i = 0; i < 10; i++){
        flag = 0;
        tmp = (rand() % 20) + 1;
        for(j = 0; j < i; j++){
            if(tmp == randnum[j]){
                i--;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            randnum[i] = tmp;
        }
    }
    for(i = 0; i < 10; i++){
        if(i == 0){
            headptr = malloc(sizeof(node));
            tmpptr = headptr;
        }
        else{
            tmpptr->next = malloc(sizeof(node));
            tmpptr = tmpptr->next;
        }
        tmpptr->num = randnum[i];
        tmpptr->next = NULL;
    }

    tmpptr = headptr;
    printf("List: ");
    for(i = 0; i < 10; i++){
		printf("%d ", tmpptr->num);
		tmpptr = tmpptr->next;
    }
    printf("\n------------------------------------\n");



    while(1){
        printf("Search the number: ");
        scanf("%d",&a);
        flag = 0;
        if(a == 0){
            printf("Exit!\n");
            break;
        }
        nowptr = headptr;
        for(i = 0; i < 10; i++){
            if(nowptr->num == a){
                flag = 1;
                printf("In the List!\n");
                printf("Index: %d\n",i+1);
                break;
            }
            else{
                nowptr = nowptr->next;
            }
        }
        if(flag == 0){
            printf("Not in the List!\n");
        }
    }
}
