#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int cost;
    int data;
}Node;

//Node *newNode(int cost, int data){
//    Node *node = malloc(sizeof(Node));
//    node->cost = cost; //min
//    node->data = data;
//    node->next = NULL;
//    return node;
//}

int main(){
    FILE *fp = fopen("input_1.txt", "r");
    if(fp == NULL){
        printf("NO~~~~");
    }
    int node, acti;
    int temp1, temp2, ignore, cost;
    int i, cost_tmp;

    Node *temp;
    while(fscanf(fp, "%d %d", &node, &acti) != EOF){
        Node array[node];
        int activity[acti][3]; //0->self 1->max 2->min

        for(i = 0; i < node ; i++){
            array[i].next = NULL;
            array[i].cost = 0;
            array[i].data = i;
        }
        for(i = 0; i < acti; i++){
            fscanf(fp, "%d->%d a%d %d", &temp1, &temp2, &ignore, &cost);
            activity[i][0] = cost; //a0 = ? a1 = ?....
            cost_tmp = 0;
            temp = &array[temp1];
            while(temp->next != NULL){
                cost_tmp += temp->cost;
                temp = temp->next;
            }
            temp->next = newNode(cost_tmp, temp2);
        }
        for(i = 0; i < node; i++){
            temp = &array[i];
            while(temp != NULL){
                printf("%d", temp->data);
                if(temp->next != NULL){
                    printf("->");
                }
                printf("!!=%d ", temp->cost);
                temp = temp->next;

            }
            printf("\n");
        }

    }
}
