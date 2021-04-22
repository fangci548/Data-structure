#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree {
    int data;
    struct tree *Left;
    struct tree *Right;
}treeNode;

treeNode *newNode(int key){
    treeNode * node;
    node = malloc(sizeof(treeNode));
    node->data = key;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

treeNode *insert(treeNode *root, int tmp){
    treeNode *now;
    if(root == NULL){
        root = malloc(sizeof(treeNode));
        root->data = tmp;
        root->Left = NULL;
        root->Right = NULL;
    }
    else{
        now = root;
        while(1){
            if(tmp > now->data){
                if(now->Right == NULL){
                    now->Right = newNode(tmp);
                    break;
                }
                else{
                    now = now->Right;
                }
            }
            else{
                if(now->Left == NULL){
                    now->Left = newNode(tmp);
                    break;
                }
                else{
                    now = now->Left;
                }
            }
        }
    }
    return root;
}

void Preorder(treeNode *ptr){
    if(ptr != NULL){
        printf("%d ",ptr->data);
        Preorder(ptr->Left);
        Preorder(ptr->Right);
    }
}

int leaf(treeNode *ptr, int level){
    if(ptr != NULL){
        level++;
        level = leaf(ptr->Left, level);
        level = leaf(ptr->Right, level);
        if(ptr->Left == NULL && ptr->Right == NULL){
            return level;
        }
    }
}

void which(treeNode *root, int now_num){
    treeNode *now = root;
    int tmp = 0;
    int kind = 1;
    int level = sqrt(now_num) + 1;
    //printf("%d", level);
//    while(1){
//
//    }
}

int main(){
    FILE *fp = fopen("input_2.txt","r");
    if(fp == NULL){
        printf("NO~~~~~\n");
    }
    int tmp;
    int now_num = 0;
    char space;
    int num[20];
    int i;
    int flag = 0;
    treeNode *root = NULL, *now;
    //treeNode *root = NULL, *now;
    while(fscanf(fp, "%d%c", &tmp, &space) != EOF){
        //printf("%d\n",tmp);
        num[now_num++] = tmp;
        if(space == '\n'){
            for(i = 0; i < now_num; i++){
                root = insert(root, num[i]);
            }
            //which(root, now_num);
            Preorder(root);
            printf("\n\n");
            root = NULL;
            now_num = 0;
            now = root;
            flag = 0;
            if(root->Left != NULL && root->Right == NULL){

                while(1){
                    if(now->Left == NULL){
                        break;
                    }
                    if(now->Right != NULL){
                        printf("Simple tree\n");
                        flag = 1;
                        break;
                    }
                    else{
                        now = now->Left;
                    }
                }
            }
            else{
                while(1){
                    if(now->Right == NULL){
                        now = now->Left;
                    }
                    if(now->Left != NULL){
                        printf("Simple tree\n");
                        flag = 1;
                        break;
                    }
                    else{
                        now = now->Right;
                    }
                }
            }
            if(flag == 0){
                printf("Skewed Binary Tree\n");
            }
        }
    }
}
