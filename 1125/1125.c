#include <stdio.h>
#include <string.h>

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

void Preorder(treeNode *ptr){ //«e§Ç VLR
    if(ptr != NULL){
        printf("%d ",ptr->data);
        Preorder(ptr->Left);
        Preorder(ptr->Right);
    }
}

void Inorder(treeNode *ptr){ //¤¤§Ç LVR
    if(ptr != NULL){
        Inorder(ptr->Left);
        printf("%d ",ptr->data);
        Inorder(ptr->Right);
    }
}

void Postorder(treeNode *ptr){ //«á§Ç LRV
    if(ptr != NULL){
        Postorder(ptr->Left);
        Postorder(ptr->Right);
        printf("%d ",ptr->data);
    }
}

void MAX(treeNode *root){
    treeNode *now = root;
    while(1){
        if(now->Right == NULL){
            printf("MAX : %d\n",now->data);
            break;
        }
        else{
            now = now->Right;
        }
    }
}

void MIN(treeNode *root){
    treeNode *now = root;
    while(1){
        if(now->Left == NULL){
            printf("MIN : %d\n",now->data);
            break;
        }
        else{
            now = now->Left;
        }
    }
}

void leaf(treeNode *ptr){
    if(ptr != NULL){
        leaf(ptr->Left);
        leaf(ptr->Right);
        if(ptr->Left == NULL && ptr->Right == NULL){
            printf("%d ",ptr->data);
        }
    }
}
int main(){
    FILE *fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("NO~~~~~\n");
    }
    int tmp;
    treeNode *root = NULL, *now;
    while(fscanf(fp, "%d", &tmp) != EOF){
        //printf("%d\n",tmp);
        printf("Insert a number : %d\n", tmp);
        if(tmp == 0){
            break;
        }
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
                else if(tmp == now->data){
                    printf("%d  already exist.\n");
                    break;
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
    }
    printf("---------------------------------------------\n");
    printf("Preorder: ");
    Preorder(root);
    printf("\n");

    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    printf("Postorder: ");
    Postorder(root);
    printf("\n");
    MAX(root);
    MIN(root);
    printf("LeafNodes : ");
    leaf(root);
}
