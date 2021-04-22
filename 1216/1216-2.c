#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *newNode(int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void bfs(Node array[], int vertex){
    int i, j;
    Node *temp;
    int ans[20] = {0};
    for(i = 0; i < vertex; i++){
        temp = &array[i];
        while(temp != NULL){
            if(ans[temp->data] == 0){
                printf("%d ",temp->data);
                ans[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    int temp1, temp2, vertex;
    int i, j,now = 0;
    Node *temp;

    while(fscanf(fp, "%d", &vertex) != EOF){
        now = 0;
        int flag = 0;
        printf("Number of vertex: %d\n",vertex);
        Node array[vertex];
        for(i = 0; i < vertex ; i++){
            array[i].next = NULL;
            array[i].data = i;
        }
        while(1){
            fscanf(fp, "%d->%d", &temp1, &temp2);
            printf("edge %d: %d -> %d\n", now + 1,temp1, temp2);
            if(temp1 == 0 && temp2 == 0){
                break;
            }
            if(temp1 == temp2){
                printf("It failed to add!\n");
            }
            else{
                flag = 0;
                temp = &array[temp1];
                while(temp->next != NULL && flag != 1){
                    if(temp->next->data == temp2){
                        printf("It failed to add!\n");
                        flag = 1;
                    }
                    temp = temp->next;
                }
                if(flag == 0){
                    temp->next = newNode(temp2);
                    now++;
                }
            }
        }
        printf("\nAdjacency List:\n");
        for(i = 0; i < vertex; i++){
            temp = &array[i];
            while(temp != NULL){
                printf("%d ", temp->data);
                if(temp->next != NULL){
                    printf("->");
                }
                temp = temp->next;
            }
            printf("\n");
        }
        printf("\nBFS: ");
        int ans[20] = {0};
        bfs(array, vertex);
        printf("\n\n--------------------------------------------\n\n");

    }
}
